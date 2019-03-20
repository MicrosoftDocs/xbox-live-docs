---
title: Using Xbox Live SDK to Sign-In for Mobile
description: Writing code for your game to sign-in to Xbox Live on Mobile.
ms.date: 03/14/2019
ms.topic: article
keywords: xbox live, xbox, games, mobile, sign-in
ms.localizationpriority: medium
---
# Using Xbox Live SDK to Sign-In for Mobile

> [!IMPORTANT]
> Prerequisite step: Set up an IDE with the Xbox Live SDK, for your target platforms. See [Getting started](index.md).

Now that you've imported the Xbox Live SDK into your IDE, it is time to setup your project to call Xbox Live's Sign-In API.

## Initialize XSAPI

Initializing Xbox Live requires a set of arguments to be passed in.

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
> [!NOTE]
> You can find your SCID at your Partner Center account.

## Initialize XAL

XAL has two sets of arguments to pass in. First is XalPlatformArgs and second is XalInitArgs.
XalPlatormArgs defines arguments needed in order to display the Sign-In window to your game.
XalInitArgs defines arguments needed in order to link XAL to your specified game from Partner Center.

```cpp
HRESULT XalInit()
{
    // Trace Debugger must be set before any XAL calls
    HCSettingsSetTraceLevel(HCTraceLevel::Verbose);
    HCTraceSetTraceToDebugger(true);
    
    std::string clientId = ; // TODO: Add your Client ID here.
    
    // TODO: Make sure Client ID is all lower case!
    std::string redirUri = "ms-xal-";
    redirUri += clientId;
    redirUri += "://auth";
    
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
> [!NOTE]
> You can find your Client ID, Title ID, and Sandbox at your Partner Center account.

## Basic Sign-In/Sign-Out

Now that Xbox Live is initialized, it's time for us to setup our Sign-In and Sign-Out functionality.

### Sign-In Silently

To start off with, we will add in Sign-In Silently.
This function should be called when your game starts up to auto sign-in the previously logged in user.
The function below wraps the async call XalTryAddDefaultUserSilentlyAsync.

```cpp
HRESULT XAL_TrySignInUserSilently()
{
    XAsyncBlock* asyncBlock = new XAsyncBlock() {};
    asyncBlock->callback = XAL_TrySignInUserSilently_Callback;

    return XalTryAddDefaultUserSilentlyAsync(nullptr, asyncBlock);
}
```

When our XAsyncBlock returns from calling the server, it will run our callback function.
The callback function will require that we grab the result from the server.
After grabbing the result, we will pass it to gameplay.

```cpp
void CALLBACK XAL_TrySignInUserSilently_Callback(_In_ XAsyncBlock* asyncBlock)
{
    if (asyncBlock == nullptr) { return; }

    XblUserHandle newUser = nullptr;
    HRESULT hr = XalTryAddDefaultUserSilentlyResult(asyncBlock, &newUser);

    if (SUCCEEDED(hr)) { Gameplay_SignInUser(newUser, false); }

    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```

In gameplay, we will handle if an XblContext should be created from our XalUser.
If an XblContext is created, then the user has properly signed in.

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
Just like with sign-in silently, we will create a wrapper to call our async function XalAddUserWithUiAsync.

```cpp
HRESULT XAL_TrySignInUserWithUI()
{
    XAsyncBlock* asyncBlock = new XAsyncBlock() {};
    asyncBlock->callback = XAL_TrySignInUserWithUI_Callback;

    return XalAddUserWithUiAsync(nullptr, asyncBlock);
}
```

The callback function will grab the result from the server to pass on to gameplay.

```cpp
void CALLBACK XAL_TrySignInUserWithUI_Callback(_In_ XAsyncBlock* asyncBlock)
{
    if (asyncBlock == nullptr) { return; }

    XblUserHandle newUser = nullptr;
    HRESULT hr = XalAddUserWithUiResult(asyncBlock, &newUser);

    if (SUCCEEDED(hr)) { Gameplay_SignInUser(newUser, true); }

    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```

Next, we must create the XAL_TryResolveUserIssue function.
This function will be called if there happens to be any issues with the user signing it to your game.
We will use asyncBlock-context to store the handle to the new user to be used later in the callback.

```cpp
HRESULT XAL_TryResolveUserIssue(_In_ XalUserHandle user)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock() {};
    asyncBlock->context = user;
    asyncBlock->callback = XAL_TryResolveUserIssue_Callback;

    return XalUserResolveIssueWithUiAsync(user, "https://www.xboxlive.com", asyncBlock);
}
```

The callback function will then grab the XAsyncGetStatus result to be used by gameplay.
We will also make sure to grab the XalUserHandle, from asyncBlock->context.        

```cpp
void CALLBACK XAL_TryResolveUserIssue_Callback(_In_ XAsyncBlock* asyncBlock)
{
    if (asyncBlock == nullptr) { return; }

    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
    XalUserHandle user = reinterpret_cast<XblUserHandle>(asyncBlock->context);

    // TODO: If XAsyncGetStatus fails, tell user to sign in again
    
    // Close the Reference if one was created during XalUserDuplicateHandle
    if (user) { XalUserCloseHandle(user); }   

    delete asyncBlock;
}
```

### Sign-Out

Now that sign-in is taken care of, it's time to implement sign-out.

```cpp
HRESULT XAL_TrySignOutUser(_In_ XalUserHandle user)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock() {};
    asyncBlock->callback = XAL_TrySignOutUser_Callback;

    return XalSignOutUserAsync(user, asyncBlock);
}
```

The callback function will then grab the XAsyncGetStatus result.

```cpp
void CALLBACK XAL_TrySignOutUser_Callback(_In_ XAsyncBlock* asyncBlock)
{
    if (asyncBlock == nullptr) { return; }

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

Now that everything is implemented, we need to make sure that we clean it up when your game closes.

### XAL Cleanup

XAL doesn't require any cleanup, however, you will need to close your XalUserHandle and XblContextHandle.

```cpp
if (m_xblContext)
{
    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(m_xblContext, &user);

    if (SUCCEEDED(hr)) { XalUserCloseHandle(user); }

    XblContextCloseHandle(m_xblContext);
}
```

### Xbl Cleanup

When your game closes, make sure to cleanup Xbox Live.

```cpp
XblCleanup();
```

## Testing

Now that basic sign-in/sign-out is added, it is time to test that it works properly.

1. When your game starts for the first time, you'll want to make sure that you're calling your Sign-In Silently code.
This should fail with the result "E_XAL_UIREQUIRED", since there hasn't been a user signed in before.

2. Next, make sure to call Sign-In with UI. This should bring up a webview window displaying the Xbox Live Sign-In portal.

   ![Xbox Live Sign-In portal](images/XboxLiveSignInWindow.png)

3. After finishing sign-in with the Xbox Live Sign-In portal, you should recieve an "S_OK" result from XalAddUserWithUiResult.
You should now be able to create an XblContext and run your game.

4. Next, close your game without signing-out, and then re-open your game.
This time, your Sign-In Silently code should pass and automatically sign-in the user.

5. Lastly, call your Sign-Out code. Make sure you're closing your XalUserHandle and XblContextHandle.
If cleared properly, you should be able to run your game and get the "E_XAL_UIREQUIRED" result from your Sign-In Silently code.

6. Repeat steps 2-5 as needed.
        
<!--===========================================================-->
## Next step

After your game is set up with Sign-In, you are now ready to implement any of the features provided by XSAPI.
See [Features](../features/index.md).