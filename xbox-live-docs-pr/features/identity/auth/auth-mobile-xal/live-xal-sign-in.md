---
title: Signing-in using XAL
description: Sign-in scenarios for XAL are soft single-user authentication, hard single-user authentication, and multi-user authentication.
kindex: Signing-in using XAL
kindex: authentication
kindex: sign-in
author: aablackm
ms.author: aablackm
ms.topic: article
ms.localizationpriority: medium
ms.date: 08/30/2018
---

# Signing-in using XAL

Sign-in scenarios for the Xbox Live Authentication Library (XAL) can be divided into two broad categories depending on the platform XAL is used to authenticate on.
There are **single-user application (SUA)** devices and **multi-user application (MUA)** devices.

* On a single-user application (SUA) device, you can have at most one user signed-in to Xbox Live at a time. Single-user devices can also be split into two categories, **soft SUA**, and **hard SUA**.
    * On a soft SUA device, you may operate in a state where zero or one users are signed in.
    * Hard SUA devices require that one user and only one user be signed-in at all times.

* Multi-user application (MUA) devices allow more than one user to be signed-in to Xbox Live at once.

The three common scenarios:

|Scenario  |Authentication Limits|
|---------|---------|
|Soft SUA | You may operate the application with zero or one users signed-in. You may not sign-in additional users but switching users is allowed.|
|Hard SUA | One user and one user only must be signed-in to Xbox Live for the duration of the app. This means a user will be signed in on application start and remain signed in until the application ends. Signing out or attempting to change users will end the application.|
|MUA      | You may operate the application with zero or more users signed-in. This scenario is the only scenario which allows more than one simultaneous sign-in.|

Each of the three scenarios require you to vary your approach to sign-in.

If you're not sure what scenario you are using, you can use the `XalGetMaxUsers()` function to check whether it is a single-user application (SUA) or MUA scenario.
If the "max users" parameter returns 1, it is a single-user authentication scenario.


## Checking whether soft or hard SUA is used

To distinguish between soft and hard SUA, you can check for the presence of `XalSignOutUserAsync()`, as follows:

```cpp
// Hard SUA example:
HRESULT res = S_OK;
uint32_t maxUsers = 0;
res = XalGetMaxUsers(&maxUsers); // check max number of users
assert(maxUsers == 1);
assert(!XalSignOutUserAsyncIsPresent()); // check for the presence of XalSignOutUserAsync
```


## Common sign-in scenarios


## Setting hooks

Before Initializing or running any sign-in sign-up code, you must first set all of the event handlers you wish to set to customize XAL's behavior. On Android and iOS these methods are all optional.

There are several "SetEventHandle" functions that XAL provides to complete this task:
- `XalPlatformWebSetEventHandler()`
- `XalPlatformStorageSetEventHandlers()`
- `XalUserRegisterChangeEventHandler()`

All of these functions are used to set functions to be called by XAL when it needs to give control over to gain some information.


## Initialize

In each scenario you will need to initialize XAL before signing in a user:

[!INCLUDE [XalInitialize](../../../../code/snippets/XalInitialize.md)]


## Sign-in

XAL has two sign-in functions:
* `XalTryAddDefaultUserSilentlyAsync()` - Attempts to add a user without showing any UI.
* `XalAddUserWithUiAsync()` - Attempts to add a user and will always show UI.

Both of these functions follow the C API calling pattern, which you should familiarize yourself with; see [Making async calls in the XSAPI C API](../../../../api-ref/xasync/live-flatc-async-patterns.md).

You will need to set up an `XAsyncBlock` which calls the appropriate result function, `XalTryAddDefaultUserSilentlyResult()` or `XalAddUserWithUiResult()`, in its return function before calling the sign-in function.
You will also need to have set up an `XTaskQueueHandle` to handle the asynchronous work, or pass null if you do not wish to control the threading model.


### Sign-in silent example

[!INCLUDE [XalTryAddDefaultUserSilentlyAsync](../../../../code/snippets/XalTryAddDefaultUserSilentlyAsync.md)]

### Sign-in with UI example

[!INCLUDE [XalAddUserWithUIAsync](../../../../code/snippets/XalAddUserWithUiAsync.md)]


### Resolving issues with sign-in

1. Create the following `XAL_TryResolveUserIssue` function.
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

2. Add the following `XAL_TryResolveUserIssue_Callback` function, which will grab the `XAsyncGetStatus` result to be used by gameplay.
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


## Soft SUA and MUA

In a **hard** single-user authentication (SUA) scenario, you are not allowed to sign-out a user so the sign-out user function is not available.
However, user switching and sign-out are allowed in **soft** SUA and MUA scenarios.

So if you are developing on a platform that uses these scenarios, you will want to know how to sign-out as well.


### Sign-out

The XAL sign-out function is `XalSignOutUserAsync()` and follows the same C async calling pattern as the sign-in functions previously covered.
Before using the sign-out function make sure that you verify its presence with `XalSignOutUserAsyncIsPresent()`.


#### Sign-out example

[!INCLUDE [XalSignOutUserAsync](../../../../code/snippets/XalSignOutUserAsync.md)]

> [!IMPORTANT]
> Calling sign out will remove users from the device and removes them as a default user for sign-in. This means that a user that is signed out will no longer be eligible for silent sign-in.


## See also

* [Getting started with Xbox Live SDK for iOS](../../../../get-started/setup-ide/managed-partners/xcode-ios/other/live-ios-get-started-xsapi.md)  
* [Getting started with the Xbox Live APIs on Android](../../../../get-started/setup-ide/managed-partners/astudio-android/other/live-android-get-started-xsapi.md)
