---
title: Signing-in using XAL
author: aablackm
description: Sign-in scenarios for XAL are soft single-user authentication, hard single-user authentication, and multi-user authentication.
ms.author: aablackm
ms.date: 08/30/2018
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, authentication, sign-in
ms.localizationpriority: medium
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


## Hooking up storage

To give an example of how to set up event handlers, here is how a client might (optionally) set up storage handlers.

You will need to use a function hook provided by XAL to tell XAL what to call to perform storage related tasks.
You will then write code for your specific platform to implement the storage operations.

To do this, set an event handler to be called whenever storage is required, using `XalPlatformStorageSetEventHandlers()`:

```cpp
HRESULT XalPlatformStorageSetEventHandlers(
    _In_opt_ XTaskQueueHandle queue,
    _In_ XalPlatformStorageEventHandlers* handlers
) noexcept;
```

|Parameter  |Description |
|---------|---------|
|queue    | The async queue the callback should be invoked on.         |
|handlers | The event handlers for the function you want called when storage needs to be done.        |

**Call Sample**  
[!INCLUDE [XalPlatformStorageSetEventHandlers](../../code/snippets/XalPlatformStorageSetEventHandlers.md)]

> [!IMPORTANT]
> This function must be called before `XalIntialize()`

The function set as the event handler must take some context, a handle representing the XAL operation being executed, a key describing the data being accessed, and (in the case of a write) an array of data to be written.

```cpp
void Xal_PlatformOnWriteHandler(
    _In_opt_ void* context,
    _In_opt_ void* userContext,
    _In_ XalPlatformOperation operation,
    _In_z_ char const* key,
    _In_ size_t dataSize,
    _In_reads_bytes_(dataSize) void const* data
)

void Xal_PlatformOnReadHandler(
    _In_opt_ void* userContext,
    _In_ XalPlatformOperation operation,
    _In_z_ char const* key
)

void Xal_PlatformOnClearHandler(
    _In_opt_ void* context,
    _In_opt_ void* userContext,
    _In_ XalPlatformOperation operation,
    _In_z_ char const* key
)
```

|Parameter  |Description  |
|---------|---------|
|context     | The context pointer that was passed in inside the handlers struct when XalPlatformStorageEventHandlers() was called.         |
|userContext     | The context pointer that was passed to XAL that is associated with the user being operated on.         |
|operation     | The handle for this operation.         |
|key     | The key associated with the data to be accessed.        |
|dataSize     | The number of bytes to be written. |
|data     | The data to be written. |

> [!IMPORTANT]
> The `XalPlatformStorageWriteEventHandler` method must save data in a way that does not get migrated to new devices.

When the resulting work is done, your code will need to call into `XalPlatformStorageWriteComplete()`, `XalPlatformStorageReadComplete()`, or `XalPlatformStorageClearComplete()` which will return the XAL information which was needed:

```cpp
HRESULT XalPlatformStorageWriteComplete(
    _In_ XalPlatformOperation operation,
    _In_ XalPlatformOperationResult result
) noexcept;

HRESULT XalPlatformStorageReadComplete(
    _In_ XalPlatformOperation operation,
    _In_ XalPlatformOperationResult result,
    _In_ size_t dataSize,
    _In_reads_bytes_opt_(dataSize) void const* data
) noexcept;

HRESULT XalPlatformStorageClearComplete(
    _In_ XalPlatformOperation operation,
    _In_ XalPlatformOperationResult result
) noexcept;
```

|Parameter  |Description  |
|---------|---------|
|operation     | The handle for this operation         |
|result     | The result of the operation        |
|dataSize     | The number of bytes being returned to XAL. |
|data     | The data that was read. |

**Call Sample**  
[!INCLUDE [XalPlatformStorageReadComplete](../../code/snippets/XalPlatformStorageReadComplete.md)]  

After all desired event handlers are set, initialize XAL so that it can be used for authentication.


## Initialize

In each scenario you will need to initialize XAL before signing in a user:

[!INCLUDE [XalInitialize](../../code/snippets/XalInitialize.md)]


## Sign-in

XAL has two sign-in functions:
* `XalTryAddDefaultUserSilentlyAsync()` - Attempts to add a user without showing any UI.
* `XalAddUserWithUiAsync()` - Attempts to add a user and will always show UI.

Both of these functions follow the [Flat-C api calling pattern](../../flatc-async-patterns.md), which you should familiarize yourself with.

You will need to set up an `XAsyncBlock` which calls the appropriate result function, `XalTryAddDefaultUserSilentlyResult()` or `XalAddUserWithUiResult()`, in its return function before calling the sign-in function.
You will also need to have set up an `XTaskQueueHandle` to handle the asynchronous work, or pass null if you do not wish to control the threading model.


### Sign-in silent example

[!INCLUDE [XalTryAddDefaultUserSilentlyAsync](../../code/snippets/XalTryAddDefaultUserSilentlyAsync.md)]

### Sign-in with UI example

[!INCLUDE [XalAddUserWithUIAsync](../../code/snippets/XalAddUserWithUiAsync.md)]


## Soft SUA and MUA

In a **hard** single-user authentication (SUA) scenario, you are not allowed to sign-out a user so the sign-out user function is not available.
However, user switching and sign-out are allowed in **soft** SUA and MUA scenarios.

So if you are developing on a platform that uses these scenarios, you will want to know how to sign-out as well.


### Sign-out

The XAL sign-out function is `XalSignOutUserAsync()` and follows the same flat C async calling pattern as the sign-in functions previously covered.
Before using the sign-out function make sure that you verify its presence with `XalSignOutUserAsyncIsPresent()`.


#### Sign-out example

[!INCLUDE [XalSignOutUserAsync](../../code/snippets/XalSignOutUserAsync.md)]

> [!IMPORTANT]
> Calling sign out will remove users from the device and removes them as a default user for sign-in. This means that a user that is signed out will no longer be eligible for silent sign-in.


## See also

* [XAL sign-in for iOS](iOS-xal.md)
* [XAL sign-in for android](android-xal.md)
