---
title: Signing-in to Xbox Live
description: Writing code for your game to sign-in to Xbox Live.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Signing-in to Xbox Live

   > [!IMPORTANT]
   > Prerequisite step: Set up an IDE with the Xbox Live SDK, for your target platforms. See [Getting started](index.md).

Now that you've set up an app in Partner Center and have set up an IDE, write code for your game to sign-in to Xbox Live, as follows.


## Add core XSAPI integration (Async, XAL, XSAPI)


## Add basic sign-in integration


<!-- 
Notes while James recorded video:

Have your game sign-in to Xbox Live, as follows.

This page is for ID@Xbox partners.

need modules (.ar's): com.microsoft.xboxlive.aar/
....
...java.aar

Those are native calls that have to be called from the XSAPI client.  In 1902, not 1810, they are automatically included in the library within the lirbaray native calls.  Include those modules if not done auto'ly.

Incorp your XSAPI integrration files for your specific target devices.

set up your envir; initialize the java envir for this device.

Game_Integration_ini.cpp -- ...InitializeNativeEnv()

core integration: 
4 fooIntegration .cpp  files add into your project, or at least a way of calling eg XAL integration for XAL init. Requires a specific order.
Set up plat args for a specific java machine.  X

In init, set all this up for native XSAPI calls.

Integrate best practices shown here (XAL_Integration.cpp) into your code.  

Once you have all of that in, the only signin code you might have to include is links to any gameplay you want to do after signin or before signout.  in XAL_Gameplay.cpp.  That file also has ShowWebView(), to get from C++ to native java, to enact signin.

Sample shows how to welcome the user that has signed-in.
-->


<!-- start of "Getting started with Xbox Live in Project Antibes" -->


## Add Xbox Live APIs (XAL and XSAPI) to Your Project

In order to use the Xbox Live APIs in a Project Antibes desktop game on Windows 10 PC, you must include the Xbox Live extension SDK headers and libraries in your project:

1. Make sure that you have installed the Gaming Runtime SDK (GRDK) on your development PC.

1. Open the vcxproj file for your game, and add the following element:

```xml
  <ImportGroup>
    <Import Project="$(ProgramFiles)\Microsoft SDKs\Gaming.Desktop.x64.190200\v10.0\ExtensionSDKs\Xbox.Services.API.C\10.0\DesignTime\CommonConfiguration\Neutral\Xbox.Services.API.C.props" />
  </ImportGroup>
```


## Initialize Gaming Runtime

Because Xbox Live APIs depend on the Gaming Runtime service, before calling any XAL or XSAPI APIs, you need to initialize the Gaming Runtime service:

```c
    #include <XGameRuntimeInit.h>
    ...
    HRESULT hr = XGameRuntimeInitialize();
```


## Optionally Create XTaskQueue

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

If you don't create a task queue, you can pass in nullptr below for the queue.  When nullptr is used, the task system will use ThreadPool by default and but can be overridden by calling `XTaskQueueSetCurrentProcessTaskQueue`.


## Initialize XAL (Xbox Authentication Library)

You will need to Initialize XAL before adding a user:
```c
    XalInitArgs xalArgs = {};
    xalArgs.titleId = 12345678; // Replace with the title id of your game
    xalArgs.sandbox = "RETAIL"; // This isn't used to control the sandbox on PC or console so you can just set this to RETAIL
    XalInitialize(&xalArgs, g_queue);
```

## Add user to Xbox Live

XAL has two add user functions, `XalTryAddDefaultUserSilentlyResult` which attempts to add a user without showing any UI, and `XalAddUserWithUiAsync`, which attempts to add a user with UI.

You will need to setup an `XAsyncBlock` which calls the appropriate result function, `XalTryAddDefaultUserSilentlyResult` or  `XalAddUserWithUiResult`, in its return function before calling the add function. You will also need to have setup an `XAsyncQueue`to handle the asynchronous work.


### Add a user without showing any UI

You should first attempt to add the user automatically without any UI.
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


### Add user with UI

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


## Initialize XSAPI (Xbox Services API)

You will need to initialize XSAPI before calling other Xbox Service APIs:
```c
    XblInitArgs xblArgs = {};
    xblArgs.queue = g_queue;
    xblArgs.scid = "00000000-0000-0000-0000-000000000000"; // Replace with the service configuration id of your game
    XblInitialize(&xblArgs);
```


## Create an Xbox Live Context handle in XSAPI 

You will need to create an Xbox Live context handle for each user after the sig

```c
XblContextHandle g_xboxLiveContext = nullptr;
void HandleAddUserSuccess(XalUserHandle xalUser)
{
    HRESULT hr = XblContextCreateHandle(xalUser, &g_xboxLiveContext);
}
```

## Use XSAPI APIs

Here is an example of how to call XSAPI to get a user profile.  
Other XSAPI C async APIs can be called with a similar calling pattern.

```c
    XAsyncBlock* asyncBlock = new XAsyncBlock{};
    ZeroMemory(asyncBlock, sizeof(asyncBlock));

    asyncBlock->queue = g_queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](XAsyncBlock* asyncBlockInner)
    {
        XblUserProfile profile;
        HRESULT hr = XblProfileGetUserProfileResult(asyncBlockInner, &profile);

        if( SUCCEEDED(hr) )
        {
            LogCharArray(std::to_string(profile.xboxUserId).c_str());
            LogCharArray(profile.gamertag);
            LogCharArray(profile.gamerscore);
        }

        delete asyncBlockInner;
    };

    uint64_t xuid = 0;
    XblContextGetXboxUserId(g_xboxLiveContext, &xuid);
    XblProfileGetUserProfileAsync(g_xboxLiveContext, xuid, asyncBlock);
```

<!-- end of "Getting started with Xbox Live in Project Antibes" -->


## Testing sign-in

TBD


## Next steps

After your game is able to sign-in to Xbox Live, add Xbox Live features.
See [Getting started](index.md).
