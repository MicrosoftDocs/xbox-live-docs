---
title: XAL sign-in
author: aablackm
description: Sign-in scenarios common to XAL
ms.author: aablackm
ms.date: 08/30/2018
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, authentication, sign-in
ms.localizationpriority: medium
---
# Sign-in with XAL

Sign-in scenarios for XAL can be divided into two broad categories depending on the platform XAL is used to authenticate on. There are **single user authentication(SUA)** devices and **multi user authentication(MUA)** devices. On a single user authentication device you may have at most one user signed-in to Xbox Live at a time. SUA devices can also be split into two categories, **soft SUA**, and **hard SUA**. On a soft SUA device you may operate in a state where zero or one users are signed in, hard SUA devices require that one user and only one user be signed-in at all times. MUA devices allow more than one user to be signed-in to Xbox Live at once. You can quickly reference the three common scenarios in the table below

|Scenario  |Authentication Limits|
|---------|---------|
|Hard SUA | One user and one user only must be signed-in to Xbox live for the duration of the app. This means a user will be signed in on application start and remain signed in until the application ends. Signing out or attempting to change users will end the application.|
|Soft SUA | You may operate the application with zero or one users signed-in. You may not sign-in additional users but switching users is allowed.|
|MUA      | You may operate the application with zero or more users signed-in. This scenario is the only scenario which allows more than one simultaneous sign-in.|

Each of the three scenarios will require you to vary your approach to sign-in.

If you're not sure what scenario you are using you can use the `XalGetMaxUsers` function to check whether it is a SUA or MUA scenario. If the max users parameter returns as 1 it is a single user authentication scenario. To distinguish between soft and hard SUA you can check for the presence of `XalSignOutUserAsync`.

```cpp
HRESULT res = S_OK;
uint32_t maxUsers = 0;
res = XalGetMaxUsers(&maxUsers); //check max number of users
assert(maxUsers == 1);
assert(!XalSignOutUserAsyncIsPresent()); // check for the presence of XalSignOusUserAsync
```

## Common sign-in scenarios

### Setting hooks

Before Initializing or running any sign-in sign-up code you must first set all of the event handlers XAL may need to use in order to complete its functions. There are several "SetEventHandle" functions that XAL provides to complete this task. To give a few examples:

- `XalPlatformWebSetEventHandler()`
- `XalPlatformStorageSetEventHandlers()`
- `XalUserRegisterChangeEventHandler()`

All of these functions are used to set functions to be called by XAL when it needs to give control over to gain some information. The `XalPlatfromWebSetEventHandler()` will be most commonly used as it allows for UI to be displayed on behalf of XAL.

### Hooking up UI

In order to get your very first sign-in on a device you will have to implement some UI. You will need to use a function hook provided by XAL to bring XAL any information that requires UI. You will then write code for you specific platform to implement the necessary UI.

To do this, you will set an event handler to be called whenever UI is required. This is done using the `XalPlatformWebSetEventHandler()` function:

```cpp
HRESULT XalPlatformWebSetEventHandler(
    _In_opt_ async_queue_handle_t queue,
    _In_opt_ void* context,
    _In_ XalPlatformWebShowUrlEventHandler* handler
) XAL_NOEXCEPT;
```

|Parameter  |Description |
|---------|---------|
|queue    | The async queue the callback should be invoked on.         |
|context     | Optional pointer to the client provided user specific content.         |
|handler     | the event handler for the function you want called when UI needs to be shown        |

**Call Sample**  
[!INCLUDE [XalPlatformWebSetEventHandler](../../code/snippets/XalPlatformWebSetEventHandler.md)]

> [!IMPORTANT]
> This function must be called before `XalIntialize()`

The function set as the event handler must take some context, the XAL operation being executed, a start url and a final url for the webflow being used. In the **AndroidTestApp** project the function `OnShow()` is used as the event handler to show a web view:

```cpp
void OnShow(
    _In_opt_ void* context,
    _In_opt_ void* /*userContext*/,
    _In_ xal_platform_operation_t operation,
    _In_z_ char const* startUrl,
    _In_z_ char const* finalUrl,
    bool suppressUi
)
```

Calling `XalPlatformWebSetEventHandler()` will allow you to write your own function that will be called when UI needs to be show for some XAL operation. When the resulting work is done, your code will need to call into `XalPlatformWebShowUrlComplete()` which will return the XAL information for which UI was needed.

```cpp
HRESULT XalPlatformWebShowUrlComplete(
    _In_ xal_platform_operation_t operation,
    _In_ XalPlatformOperationResult result,
    _In_opt_z_ char const* url
) XAL_NOEXCEPT;
```

|Parameter  |Description  |
|---------|---------|
|operation     | The handle for this operation         |
|result     | the result of the operation        |
|url     | the full url for the final redirection. This should contain the information needed for XAL functionality |

**Call Sample**  
[!INCLUDE [XalPlatformWebShowUrlComplete](../../code/snippets/XalPlatformWebShowUrlComplete.md)]  

After event handlers for web views and other necessary processes are set you will want to Initialize XAL so that it can be used for authentication.

### Initialize

In each scenario you will need to Initialize XAL before signing in a user:

[!INCLUDE [XalInitialize](../../code/snippets/XalInitialize.md)]

### Sign-in

XAL has two sign-in functions, `XalTryAddFirstUserSilentlyAsync` which attempts to add a user without showing any ui, and `XalAddUserWithUiAsync`, which attempts to add a user with UI. Both of these functions follow the [Flat-C api calling pattern](../../flatc-async-patterns.md), which you should familiarize yourself with if you have not already.

You will need to setup an `AsyncBlock` which calls the appropriate result function, `XalTryAddFirstUserSilentlyResult` or  `XalAddUserWithUiResult`, in its return function before calling the sign-in function. You will also need to have setup an `AsynceQueue`to handle the asynchronous work.

#### Sign-in silent example

[!INCLUDE [XalTryAddFirstUserSilentlyResult](../../code/snippets/XalTryAddFirstUserSilentlyAsync.md)]

#### Sign-in with UI example

[!INCLUDE [XalAddUserWithUIAsync](../../code/snippets/XalAddUserWithUiAsync.md)]

## Soft SUA and MUA

In a hard SUA scenario you are not allowed to sign-out a user so the sign-out user function is not available. However, user switching and sign-out are allowed in soft SUA and MUA scenarios. So if you are developing on a platform that uses these scenarios you will want to know how to sign-out as well.

### Sign-out

The XAL sign-out function is `XalSignOutUserAsync`and follows the same flat c async calling pattern as the sign-in functions previously covered. Before using the sign-out function make sure that you verify it's presence with `XalSignOutUserAsyncIsPresent`.

#### Sign-out example

```cpp
HRESULT res = S_OK;

assert(XalSignOutUserAsyncIsPresent()); // check to make sure sign-out function is present

xal_user_handle_t user = MyGameState->GetAUser(userIndex);
assert(user); // sign out user requires a valid user handle

// create the AsyncBlock for the sign-out function
auto op = std::make_unique<AsyncBlock>(AsyncBlock 
{
    XalAsyncQueue,
    nullptr, // context
    [](AsyncBlock* rawOp)
    {
        std::unique_ptr<AsyncBlock> op{ rawOp };

        HRESULT result = GetAsyncStatus(op.get(), false); //Check status of call in the callback function
        if (result == E_XAL_NETWORK || result == E_ABORT || result == E_XAL_CLIENTERROR)
        {
            // failed to sign out, this should only happen due to network errors
            // try again later
            return;
        }
        assert(SUCCEEDED(result));
    }
});

res = XalSignOutUserAsync(user, op.release()); // Sign-out function call
```

> [!IMPORTANT]
> Calling sign out will remove users from the device and removes them as a default user for sign-in. This means that a user that is signed out will no longer be eligible for silent sign-in.

### Cleanup

When you're finished with your game loop and are ready to shutdown, be sure to remove the user handle using the `XalUserCloseHandle()` function, in addition to making a call to the `XalCleanup()` function.

```cpp
    // shutdown
    XalUserCloseHandle(someUserHandle;
    res = XalCleanup();
    assert(SUCCEEDED(res));
```

## Further reading

To read about setup and sign-in for iOS and android projects read the following articles.

* [XAL sign-in for iOS](iOS-xal.md)
* [XAL sign-in for android](android-xal.md)