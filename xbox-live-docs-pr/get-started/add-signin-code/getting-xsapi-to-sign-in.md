---
title: Adding basic sign-in code for mobile, for Managed Partners
description: Adding code to a mobile game to enable basic sign-in to Xbox Live.
ms.date: 03/14/2019
ms.topic: article
keywords: xbox live, xbox, games, mobile, sign-in
ms.localizationpriority: medium
---
# Adding basic sign-in code for mobile, for Managed Partners

> [!IMPORTANT]
> Prerequisite step: Set up an IDE with the Xbox Live SDK, for your target platforms. See [Getting started](index.md).

Now that you've imported the Xbox Live SDK into your IDE, set up your project to call Xbox Live's Sign-In API.
Adding this code to your game enables the user to do basic sign-in to Xbox Live on the user's mobile device.


## Find the game's IDs at Partner Center, for Managed Partners

At Partner Center, find the Title ID, SCID, Sandbox ID, and Client ID of your game, as follows.
These IDs are needed, to insert into the sign-in code.

1. Go to <a href="https://partner.microsoft.com/en-us/dashboard/" target="_blank">Partner Center</a>.

2. On the left, click **Products**, then click your game app.

   The "App overview" page appears.

3. In the **Submissions** section of the page, click **&lt;sandbox&gt; (Submission <#>)**.

   The "&lt;sandbox&gt; Submission <#>" page appears.

4. Copy and save the sandbox name for the sandbox which you want to use, such as "ABCDEF.1".

5. Click the **Xbox Live Config** section of the page.

   The "Gameplay Setting" page appears.

6. In the middle navigation column, click **Services**, and then click **Xbox Live Setup**.

   The "Xbox Live configuration" page appears.

7. In the **Xbox Live product identities** section of the page, copy and save the **Title ID (decimal)**, **MsaAppId** (this is the Client ID),  and **SCID**.

   <!-- todo: confirm this is the Client ID -->


<!-- ### Find the game's IDs at Partner Center, for Creators

1. Go to <a href="https://partner.microsoft.com/en-us/dashboard/" target="_blank">Partner Center</a>.

2. On the left, click **Products**, then click your game app.

   The "App overview" page appears.

3. In the **Submissions** section of the page, click **Submission <#>**.

   The "Submission <#>" page appears.

4. Click the **Xbox Live Creators Program** section of the page.

   The "Xbox Live Creators Program" page appears.

5. In the top of the page, copy and save the **Title ID**, **SCID**, and the **Sandbox ID** such as "ABCDEF.12" -->

   <!-- todo: where to get the Client ID -->


## Initialize XSAPI

Initializing Xbox Live requires a set of arguments to be passed in.

1. Add the following `XsapiInit` function.

```cpp
HRESULT XsapiInit()
{
    XblInitArgs args = {};
    args.scid = ; // TODO: Add your SCID here.
#if ANDROID
    args.javaVM = getJavaVM();
    args.applicationContext = getAppContext();
#end

    return XblInitialize(&args);
}
```


## Initialize XAL

XAL has two sets of arguments to pass in:
* `XalPlatformArgs` defines arguments that are needed in order to display the Sign-In window to your game.
* `XalInitArgs` defines arguments that are needed in order to link XAL to your specified game from Partner Center.

1. Add the following `XalInit` function.

```cpp
HRESULT XalInit()
{
    // Trace Debugger must be set before any XAL calls
    HCSettingsSetTraceLevel(HCTraceLevel::Verbose);
    HCTraceSetTraceToDebugger(true);
    
    std::string clientId = ; // TODO: Add your Client ID here. Make sure Client ID is all lowercase!
    std::string redirUri = "ms-xal-" + clientId + "://auth";
    
    XalPlatformArgs xalPlatformArgs = {};
    xalPlatformArgs.redirectUri = redirUri.c_str();
#if ANDROID
    xalPlatformArgs.javaVM      = getJavaVM();
    xalPlatformArgs.appContext  = getAppContext();
#endif

    XalInitArgs xalInitArgs = {};
    xalInitArgs.clientId     = clientId.c_str();
    xalInitArgs.titleId      = ; // TODO: Add your Title ID here.
    xalInitArgs.sandbox      = ; // TODO: Add your Sandbox here.
    xalInitArgs.platformArgs = &xalPlatformArgs;

    return XalInitialize(xalInitArgs, nullptr);
}
```

## Basic Sign-In/Sign-Out

Now that Xbox Live is initialized, set up the Sign-In and Sign-Out functionality, as follows.


### Sign-In Silently

To begin, let's start with adding in functionality for signing-in silently.

1. Add the following `XAL_TrySignInUserSilently` function, which should be called when your game starts up, to auto sign-in the previously logged-in user.
   This function wraps the async call `XalTryAddDefaultUserSilentlyAsync`.

```cpp
HRESULT XAL_TrySignInUserSilently()
{
    XAsyncBlock* asyncBlock = new XAsyncBlock() {};
    asyncBlock->callback = XAL_TrySignInUserSilently_Callback;

    return XalTryAddDefaultUserSilentlyAsync(nullptr, asyncBlock);
}
```
When the `XAsyncBlock` returns from calling the server, it will run the callback function.

2. Add the following `XAL_TrySignInUserSilently_Callback` callback function, which grabs the result from the server.
After grabbing the result, pass the result to gameplay.

```cpp
void CALLBACK XAL_TrySignInUserSilently_Callback(_In_ XAsyncBlock* asyncBlock)
{
    XblUserHandle newUser = nullptr;
    HRESULT hr = XalTryAddDefaultUserSilentlyResult(asyncBlock, &newUser);

    if (SUCCEEDED(hr)) { Gameplay_SignInUser(newUser, false); }

    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```

3. Add the following `Gameplay_SignInUser` function.
   In gameplay, handle whether an `XblContext` should be created from the `XalUser`.
   If an `XblContext` is created, the user has properly signed in.

```cpp
void Gameplay_SignInUser(_In_ XalUserHandle newUser, _In_ bool resolveIssuesWithUI)
{
    // Call XalUserGetId here to ensure all vetos (gametag banned, etc) have passed
    uint64_t xuid = 0;
    HRESULT hr = XalUserGetId(newUser, &xuid);

    if (SUCCEEDED(hr))
    {
        XblContextHandle newXblContext = nullptr;
        hr = XblContextCreateHandle(newUser, &newXblContext);

        if (SUCCEEDED(hr))
        {
            // TODO: Close the previous XblContextHandle, if one existed

            // TODO: Store the new XblContextHandle
        }
    }
    else
    {
        if (resolveIssuesWithUI)
        {
            // Duplicate the handle to prolong the user to be handled later by resolve
            XblUserHandle dupUser = nullptr;
            XalUserDuplicateHandle(newUser, &dupUser);
            // Note: Creates a Ref for XblUserHandle, will be closed inside Gameplay_ResolveUserIssue

            HRESULT asyncResult = XAL_TryResolveUserIssue(dupUser);

            if (FAILED(asyncResult))
            {
                if (dupUser) { XalUserCloseHandle(dupUser); }
            }
        }
    }
}
```


### Sign-In with UI

If sign-in silently fails, then the user will need to sign-in using XAL's web view UI.

1. Just like with "Sign-In Silently", create a `XAL_TrySignInUserWithUI` wrapper function that calls the async function `XalAddUserWithUiAsync`:

```cpp
HRESULT XAL_TrySignInUserWithUI()
{
    XAsyncBlock* asyncBlock = new XAsyncBlock() {};
    asyncBlock->callback = XAL_TrySignInUserWithUI_Callback;

    return XalAddUserWithUiAsync(nullptr, asyncBlock);
}
```

2. Add the following `XAL_TrySignInUserWithUI_Callback` callback function, to grab the result from the server to pass on to gameplay:

```cpp
void CALLBACK XAL_TrySignInUserWithUI_Callback(_In_ XAsyncBlock* asyncBlock)
{
    XblUserHandle newUser = nullptr;
    HRESULT hr = XalAddUserWithUiResult(asyncBlock, &newUser);

    if (SUCCEEDED(hr)) { Gameplay_SignInUser(newUser, true); }

    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```

3. Create the following `XAL_TryResolveUserIssue` function.
   This function will be called if there are issues with the user signing in to your game.
   Use `asyncBlock-context` to store the handle to the new user to be used later in the callback:

```cpp
HRESULT XAL_TryResolveUserIssue(_In_ XalUserHandle user)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock() {};
    asyncBlock->context = user;
    asyncBlock->callback = XAL_TryResolveUserIssue_Callback;

    return XalUserResolveIssueWithUiAsync(user, "https://www.xboxlive.com", asyncBlock);
}
```

4. Add the following `XAL_TryResolveUserIssue_Callback` function, which will grab the `XAsyncGetStatus` result to be used by gameplay.
   This callback also grabs the `XalUserHandle`, from `asyncBlock->context`.

```cpp
void CALLBACK XAL_TryResolveUserIssue_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
    XalUserHandle user = reinterpret_cast<XblUserHandle>(asyncBlock->context);

    // TODO: If XAsyncGetStatus fails, tell user to sign in again

    // Close the Reference if one was created during XalUserDuplicateHandle
    if (user) { XalUserCloseHandle(user); }

    delete asyncBlock;
}
```


### Sign-Out

Now that sign-in is taken care of, implement sign-out.

1. Add the following `XAL_TrySignOutUser` function, which wraps the async function `XalSignOutUserAsync`:

```cpp
HRESULT XAL_TrySignOutUser(_In_ XalUserHandle user)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock() {};
    asyncBlock->callback = XAL_TrySignOutUser_Callback;

    return XalSignOutUserAsync(user, asyncBlock);
}
```

2. Add the following `XAL_TrySignOutUser_Callback` callback function, which grabs the `XAsyncGetStatus` result:

```cpp
void CALLBACK XAL_TrySignOutUser_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    if (SUCCEEDED(hr))
    {
        // TODO: Close the previous XalUserHandle

        // TODO: Close the previous XblContextHandle
    }

    delete asyncBlock;
}
```


## Cleanup

Now that everything is implemented, clean it up when your game closes, as follows.

1. XAL doesn't require any cleanup, however, you will need to close your `XalUserHandle` and `XblContextHandle`; add the following:

```cpp
if (m_xblContext)
{
    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(m_xblContext, &user);

    if (SUCCEEDED(hr)) { XalUserCloseHandle(user); }

    XblContextCloseHandle(m_xblContext);
}
```

2. When your game closes, cleanup Xbox Live, by adding the following:

```cpp
XblCleanup();
```

You have finished adding the basic sign-in code.


## Testing basic sign-in

Test that the basic sign-in code works properly, as follows.

1. When your game starts for the first time, make sure that you're calling your "Sign-In Silently" code.

   This code fails with the result "E_XAL_UIREQUIRED", since there hasn't been a user signed-in before.

2. Call "Sign-In with UI".

   A webview window appears, displaying the Xbox Live Sign-In portal.

   ![Xbox Live Sign-In portal](images/xboxlive-signin-window.png)

3. Sign-in by using the Xbox Live Sign-In portal.

   `XalAddUserWithUiResult` returns "S_OK".
   Thus your sign-in code will create an `XblContext`, which confirms that your user has properly signed in to your game on Xbox Live.

4. Close your game without signing-out, and then re-open your game.

   This time, your "Sign-In Silently" code succeeds, and automatically signs-in the user.

5. Call your Sign-Out code.
   Make sure you're closing your `XalUserHandle` and `XblContextHandle`.

   If cleared properly, you should be able to run your game and get the "E_XAL_UIREQUIRED" result from your "Sign-In Silently" code.

Repeat the above steps as needed.

Your game now enables the user to do basic sign-in to Xbox Live.

        
## Next step

Now that your game enables the user to do basic sign-in to Xbox Live on the device, you are ready to implement any of the Xbox Live features, which are provided through the Xbox Services API (XSAPI).
See [Features](../features/index.md).
