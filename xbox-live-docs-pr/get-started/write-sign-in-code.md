---
title: Setting up basic sign-in for Xbox Live
description: Writing code for your game to sign-in to Xbox Live.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Setting up basic sign-in for Xbox Live

   > [!IMPORTANT]
   > Prerequisite step: Set up an IDE with the Xbox Live SDK, for your target platforms. See [Getting started](index.md).

Now that you've set up an app in Partner Center and have set up an IDE, write code for your game to sign-in to Xbox Live, as follows.


<!--========================================================================-->
## Initialize Async

### UWP

### Xbox

### Android

### iOS

### Platform-independent

You can optionally create an `XTaskQueue`.
Most of the Xbox Live APIs are asynchronous APIs, and require the use of a task queue. A task queue is an API for queuing work and completion task callbacks.

<!-- To learn more about XTaskQueue and different dispatch modes, please refer to [XTaskQueue Overview](../../system/overviews/xtaskqueue-overview.md) -->

For example, the following code creates a task queue using system thread pool:
```c
    HRESULT hr = XTaskQueueCreate(
      XTaskQueueDispatchMode::Threadpool,
      XTaskQueueDispatchMode::ThreadPool,
      &g_queue
    )
```

<!-- the above is the thread pool approach.  the other approach is manual. -->

If you don't create a task queue, you can pass in nullptr below for the queue.  When nullptr is used, the task system will use ThreadPool by default and but can be overridden by calling `XTaskQueueSetCurrentProcessTaskQueue`.


<!--========================================================================-->
## Initialize XAL

### UWP

### Xbox

### Android

### iOS

### Platform-independent

You will need to initialize Xbox Authentication Library (XAL) before adding a user:
```c
    XalInitArgs xalArgs = {};
    xalArgs.titleId = 12345678; // Replace with the title id of your game
    xalArgs.sandbox = "RETAIL"; // This isn't used to control the sandbox on PC or console so you can just set this to RETAIL
    XalInitialize(&xalArgs, g_queue);
```


<!--========================================================================-->
## Initialize XSAPI (Xbox Services API)

You will need to initialize XSAPI before calling other Xbox Service APIs:
```c
    XblInitArgs xblArgs = {};
    xblArgs.queue = g_queue;
    xblArgs.scid = "00000000-0000-0000-0000-000000000000"; // Replace with the service configuration id of your game
    XblInitialize(&xblArgs);
```


<!--========================================================================-->
## Integrate Sign-In Silently

See also the "Sign-in silent example" subsection within the article [Sign-in with XAL](../using-xbox-live/auth/xal-sign-in.md#sign-in).

You should first attempt to add the user automatically without showing any UI.
```c
    XAsyncBlock* asyncBlock = new XAsyncBlock;
    ZeroMemory(asyncBlock, sizeof(*asyncBlock));

    asyncBlock->queue = g_queue;
    asyncBlock->callback = [](XAsyncBlock* asyncBlockInner)
    {
        XalUserHandle xalUser = nullptr;
        HRESULT hr = XalTryAddDefaultUserSilentlyResult(asyncBlockInner, &xalUser);

        if( SUCCEEDED(hr) )
        {
            // Call XalUserGetId here to ensure all vetos (gametag banned, etc) have passed
            uint64_t xuid = 0;
            hr = XalUserGetId(xalUser, &xuid);
            
            if( FAILED(hr) )
            {
                XalUserCloseHandle(xalUser);
                xalUser = nullptr;

                // TODO: Tell user to click the "Add User" button to add the user with UI.  See below
            }
            else
            {
                HandleAddUserSuccess(xalUser);
            }
        }

        delete asyncBlockInner;
    };

    HRESULT hr = XalTryAddDefaultUserSilentlyAsync(nullptr, asyncBlock);
    assert(SUCCEEDED(hr));
```

<!--========================================================================-->
## Integrate Sign-In with UI

See also the "Sign-in with UI example" subsection within the article [Sign-in with XAL](../using-xbox-live/auth/xal-sign-in.md#sign-in).

If the user could not be added silently - for example if the user needs to give consent to the game for accessing Xbox Live profile, you should call the XalAddUserWithUiAsync API to add the user with UI.
```c
    XAsyncBlock* asyncBlock = new XAsyncBlock;
    ZeroMemory(asyncBlock, sizeof(*asyncBlock));

    asyncBlock->queue = g_queue;
    asyncBlock->callback = [](XAsyncBlock* asyncBlockInner)
    {
        HRESULT hr = XalAddUserWithUiResult(asyncBlockInner, &g_xalUser);

        if( SUCCEEDED(hr) )
        {
            // Call XalUserGetId here to ensure all vetos (gametag banned, etc) have passed
            uint64_t xuid = 0;
            hr = XalUserGetId(g_xalUser, &xuid);
            
            if( FAILED(hr) )
            {
                // If XalAddUserWithUiResult fails, then call XalUserResolveIssueWithUiAsync
                XAsyncBlock* resolveAsyncBlock = new XAsyncBlock();
                resolveAsyncBlock->queue = Data()->queue;
                resolveAsyncBlock->context = nullptr;
                resolveAsyncBlock->callback = [](XAsyncBlock* asyncBlock)
                {
                    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

                    if( FAILED(hr) )
                    {
                        XalUserCloseHandle(xalUser);
                        xalUser = nullptr;

                        // TODO: Resolve failed, so continue to tell user to click the "Add User" button
                    }
                    else
                    {
                        HandleAddUserSuccess(xalUser);
                    }

                    delete asyncBlock;
                };

                hr = XalUserResolveIssueWithUiAsync(Data()->xalUser, "https://www.xboxlive.com", asyncBlock);
            }
            else
            {
                HandleAddUserSuccess(xalUser);
            }
        }

        delete asyncBlockInner;
    };

    HRESULT hr = XalAddUserWithUiAsync(nullptr, asyncBlock);
    assert(SUCCEEDED(hr));
```


<!--========================================================================-->
## Integrate Sign-Out

See the "Sign-out" subsection within the article [Sign-in with XAL](../using-xbox-live/auth/xal-sign-in.md#sign-out).


<!--========================================================================-->
## Test Sign-In/Sign-Out

Next, find the ID of your game, as follows.

### Find your Xbox Live game information

In Partner Center, with your game selected as in the above procedures, do the following.

1. Click **Service**: **Xbox Live**: **Xbox Live Setup**.

   <!-- todo: left-nav says "Services", not "Service", and doesn't list "Xbox Live" -->

   The "Xbox Live configuration" page appears.

   <!-- status: todo: this is ID version, create Creators version of capture - if these steps are needed -->
   ![The "Xbox Live configuration" page](images/pc_xblconfign_pg.png)

2. Copy and save the two Title ID values, for use by the SDK.


<!--========================================================================-->
## Next step

After your game is able to sign-in to Xbox Live, add Xbox Live features.
See [Getting started](index.md).


<!-- 
Notes while JS recorded video:

Have your game sign-in to Xbox Live, as follows.

This page is for ID@Xbox partners.

need modules (.ar's): com.microsoft.xboxlive.aar/
....
...java.aar

Those are native calls that have to be called from the XSAPI client.  In 1902, not 1810, they are automatically included in the library within the lirbaray native calls.  Include those modules if not done auto'ly.

Incorporate your XSAPI integration files for your specific target devices.

set up your environment; initialize the Java environment for this device.

Game_Integration_ini.cpp -- ...InitializeNativeEnv()

core integration:
4 fooIntegration .cpp  files add into your project, or at least a way of calling eg XAL integration for XAL init. Requires a specific order.
Set up plat args for a specific java machine.  X

In init, set all this up for native XSAPI calls.

Integrate best practices shown here (XAL_Integration.cpp) into your code.  

Once you have all of that in, the only sign-in code you might have to include is links to any gameplay you want to do after signin or before signout.  in XAL_Gameplay.cpp.  That file also has ShowWebView(), to get from C++ to native java, to enact signin.

Sample shows how to welcome the user that has signed-in.
-->


<!-- from "Getting started with Xbox Live in Project Antibes": -->
<!-- ## Add user to Xbox Live

XAL has two add user functions:
*  `XalTryAddDefaultUserSilentlyResult`, which attempts to add a user without showing any UI.
*  `XalAddUserWithUiAsync`, which attempts to add a user with UI.

You will need to setup an `XAsyncBlock` which calls the appropriate result function, `XalTryAddDefaultUserSilentlyResult` or  `XalAddUserWithUiResult`, in its return function before calling the add function. You will also need to have setup an `XAsyncQueue`to handle the asynchronous work. -->
