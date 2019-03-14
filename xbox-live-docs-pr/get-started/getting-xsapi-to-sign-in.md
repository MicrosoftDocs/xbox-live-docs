---
title: Using Xbox Live SDK to Sign-In for Mobile
description: Writing code for your game to sign-in to Xbox Live on Mobile.
ms.date: 03/14/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Using Xbox Live SDK to Sign-In for Mobile

   > [!IMPORTANT]
   > Prerequisite step: Set up an IDE with the Xbox Live SDK, for your target platforms. See [Getting started](index.md).

Now that you've imported the Xbox Live SDK into your IDE, it is time to setup your project to call Xbox Live's Sign-In API.

## Initialize XSAPI

The following is the order in which you will need to initialize XSAPI:

```cpp
bool XsapiInit()
{
    HRESULT hr = E_FAIL;

    // 1) Initialize Async

    // 2) Initialize Xbl

    // 3) Initialize XAL
    
    return true;
}
```

### Initialize Async

The Xbox Live SDK uses an XAsync queue to handle asynchronous tasks passed to it by it's underlying API.

The following showcases how to initialize your XAsync queue.

Targeting Android:
```cpp
bool XsapiInit()
{
    HRESULT hr = E_FAIL;

    // 1) Initialize XAsync
    
    hr = XAsync_Init(
        XTaskQueueDispatchMode::Manual,
        XTaskQueueDispatchMode::Manual,
        &m_asyncQueue,
        getJavaVM(),
        getJniEnv());
    ASSERT_MESSAGE(SUCCEEDED(hr), "Failed to Init XAsync!");
    
    // 2) Initialize Xbl

    // 3) Initialize XAL
    
    return true;
}
```

Targeting iOS:
```cpp
bool XsapiInit()
{
    HRESULT hr = E_FAIL;

    // 1) Initialize XAsync
    
    hr = XAsync_Init(
        XTaskQueueDispatchMode::Manual,
        XTaskQueueDispatchMode::Manual,
        &m_asyncQueue);
    ASSERT_MESSAGE(SUCCEEDED(hr), "Failed to Init XAsync!");
    
    // 2) Initialize Xbl

    // 3) Initialize XAL
    
    return true;
}
```

Inside of XAsync_Init, there are a few things that must be done:
1) Create an XTaskQueue
2) If using a Manual queue
    a) Setup variables
    b) Register Monitor for your XTaskQueue
    c) Spawn a background thread to handle XTaskQueue work

Targeting Android:
```cpp
HRESULT XAsync_Init(
    _In_ XTaskQueueDispatchMode workDispatchMode,
    _In_ XTaskQueueDispatchMode completionDispatchMode,
    _Inout_ XTaskQueueHandle* asyncQueuePtr,
    _In_ JavaVM* javaVM,
    _In_ JNIEnv* jniEnv)
{
    // Store DispatchModes to note if using Manual Queue for Cleanup
    g_workDispatchMode = workDispatchMode;
    g_completionDispatchMode = completionDispatchMode;

    HRESULT hr = XTaskQueueCreate(
        workDispatchMode,
        completionDispatchMode,
        asyncQueuePtr);

    ASSERT_MESSAGE(SUCCEEDED(hr), "XTaskQueueCreate Failed!");

    // If creating a Manual Queue, then create a background thread to handle work
    if (workDispatchMode == XTaskQueueDispatchMode::Manual)
    {
        {
            std::lock_guard<std::mutex> lock(g_workReadyMutex);
            g_workReady = false;
        }

        {
            std::lock_guard<std::mutex> lock(g_stopBackgroundWorkMutex);
            g_stopBackgroundWork = false;
        }

        XTaskQueueHandle asyncQueue = *asyncQueuePtr;
        XTaskQueueRegistrationToken callbackToken = {0};

        hr = XTaskQueueRegisterMonitor(asyncQueue, nullptr, HandleAsyncQueueCallback, &callbackToken);

        ASSERT_MESSAGE(SUCCEEDED(hr), "XTaskQueueRegisterMonitor Failed!");

        g_backgroundThread = std::thread(BackgroundWorkThreadProc, asyncQueue, callbackToken, javaVM, jniEnv);

        ASSERT_MESSAGE(g_backgroundThread.get_id() != std::thread::id(), "BackgroundWorkThread Failed Thread Creation!");
    }

    return hr;
}
```

Targeting iOS:
```cpp
HRESULT XAsync_Init(
    _In_ XTaskQueueDispatchMode workDispatchMode,
    _In_ XTaskQueueDispatchMode completionDispatchMode,
    _Inout_ XTaskQueueHandle* asyncQueuePtr)
{
    // Store DispatchModes to note if using Manual Queue for Cleanup
    g_workDispatchMode = workDispatchMode;
    g_completionDispatchMode = completionDispatchMode;

    HRESULT hr = XTaskQueueCreate(
        workDispatchMode,
        completionDispatchMode,
        asyncQueuePtr);

    ASSERT_MESSAGE(SUCCEEDED(hr), "XTaskQueueCreate Failed!");

    // If creating a Manual Queue, then create a background thread to handle work
    if (workDispatchMode == XTaskQueueDispatchMode::Manual)
    {
        {
            std::lock_guard<std::mutex> lock(g_workReadyMutex);
            g_workReady = false;
        }

        {
            std::lock_guard<std::mutex> lock(g_stopBackgroundWorkMutex);
            g_stopBackgroundWork = false;
        }

        XTaskQueueHandle asyncQueue = *asyncQueuePtr;
        XTaskQueueRegistrationToken callbackToken = {0};

        hr = XTaskQueueRegisterMonitor(asyncQueue, nullptr, HandleAsyncQueueCallback, &callbackToken);

        ASSERT_MESSAGE(SUCCEEDED(hr), "XTaskQueueRegisterMonitor Failed!");

        g_backgroundThread = std::thread(BackgroundWorkThreadProc, asyncQueue, callbackToken);

        ASSERT_MESSAGE(g_backgroundThread.get_id() != std::thread::id(), "BackgroundWorkThread Failed Thread Creation!");
    }

    return hr;
}
```

XTaskQueueRegisterMonitor requires a callback function to be called when a new task is added to the queue.

This callback will tell our background thread when to act on XTaskQueuePort::Work type tasks.

```cpp
void CALLBACK HandleAsyncQueueCallback(_In_ void* context, _In_ XTaskQueueHandle queue, _In_ XTaskQueuePort type)
{
    UNREFERENCED_PARAMETER(context);
    UNREFERENCED_PARAMETER(queue);

    if (type == XTaskQueuePort::Work)
    {
        if (!g_workReady)
        {
            std::unique_lock<std::mutex> lock(g_workReadyMutex);
            g_workReady = true;
        }
    }
}
```

Before spawning our background thread, we must first define what it will do.

In our background thread, we will have to do the following:
1) Create a new XTaskQueueHandle based off of the one passed in
2) Bind the thread to your environment
3) Create an update loop:
    a) Exit the loop when the background thread should stop
    b) If there is work in the queue, then dispatch the work
4) Upon leaving the thread:
    a) Unregister your monitor
    b) Close your XTaskQueueHandle
    c) Detach your thread from your environment

Targeting Android:
```cpp
void BackgroundWorkThreadProc(_In_ XTaskQueueHandle queue,_In_ XTaskQueueRegistrationToken token, _In_ JavaVM* javaVM, _In_ JNIEnv* jniEnv)
{
    XTaskQueueHandle bgQueue = nullptr;

    XTaskQueueDuplicateHandle(queue, &bgQueue);

    javaVM->AttachCurrentThread(&jniEnv, nullptr);
    
    while (true)
    {
        if (g_stopBackgroundWork) { break; }

        if (g_workReady)
        {
            {
                std::unique_lock<std::mutex> cvLock(g_workReadyMutex);
                g_workReady = false;
            }

            bool found = false;

            do
            {
                if (g_stopBackgroundWork) { break; }

                found = XTaskQueueDispatch(bgQueue, XTaskQueuePort::Work, 0);
            }while(found);
        }
    }

    XTaskQueueUnregisterMonitor(bgQueue, token);
    XTaskQueueCloseHandle(bgQueue);

    javaVM->DetachCurrentThread();
}
```

Targeting iOS:
```cpp
void BackgroundWorkThreadProc(_In_ XTaskQueueHandle queue,_In_ XTaskQueueRegistrationToken token)
{
    XTaskQueueHandle bgQueue = nullptr;

    XTaskQueueDuplicateHandle(queue, &bgQueue);
    
    while (true)
    {
        if (g_stopBackgroundWork) { break; }

        if (g_workReady)
        {
            {
                std::unique_lock<std::mutex> cvLock(g_workReadyMutex);
                g_workReady = false;
            }

            bool found = false;

            do
            {
                if (g_stopBackgroundWork) { break; }

                found = XTaskQueueDispatch(bgQueue, XTaskQueuePort::Work, 0);
            }while(found);
        }
    }

    XTaskQueueUnregisterMonitor(bgQueue, token);
    XTaskQueueCloseHandle(bgQueue);
}
```

### Initialize Xbl

After initializing XAsync, we must then initialize Xbox Live.

Initializing Xbox Live requires a set of arguments to be passed in.

You can find your scid from your Partner Center account that you had set up for your game.

Targeting Android:
```cpp
bool XsapiInit()
{
    HRESULT hr = E_FAIL;

    // 1) Initialize Async

    // 2) Initialize Xbl
    
    std::string scid = "00000000-0000-0000-0000-000000000000";

    XblInitArgs args = { };
    args.queue = m_asyncQueue;
    args.scid = scid.c_str();
    args.javaVM = getJavaVM();
    args.applicationContext = getAppContext();

    hr = XblInitialize(&args);
    ASSERT_MESSAGE(SUCCEEDED(hr), "Failed to Init XboxLive!");

    // 3) Initialize XAL
    
    return true;
}
```

Targeting iOS:
```cpp
bool XsapiInit()
{
    HRESULT hr = E_FAIL;

    // 1) Initialize Async

    // 2) Initialize Xbl
    
    std::string scid = "00000000-0000-0000-0000-000000000000";

    XblInitArgs args = {};
    args.queue = m_asyncQueue;
    args.scid = scid.c_str();

    hr = XblInitialize(&args);
    ASSERT_MESSAGE(SUCCEEDED(hr), "Failed to Init XboxLive!");

    // 3) Initialize XAL
    
    return true;
}
```

### Initialize XAL

After initializing Xbox Live, we must then initialize XAL.

XAL has two sets of arguments to pass in.

First is XalPlatformArgs and second is XalInitArgs.

XalPlatormArgs defines arguments needed in order to display the Sign-In window to your app.

XalInitArgs defines arguments needed in order to link XAL to your specified game from Partner Center.

Your client ID, title ID, sandbox, and redirect Uri can be found at your Partner Center game account.

Lastly, we need to pass in the path to your device's data storage to store our XAL user data.

Targeting Android:
```cpp
bool XsapiInit()
{
    HRESULT hr = E_FAIL;

    // 1) Initialize Async

    // 2) Initialize Xbl

    // 3) Initialize XAL
    
    std::string clientId = "0000000000000000";
    uint32_t titleId = 0;
    std::string sandbox = "XXXX.X";
    
    std::string redirUri = "xal-";
    redirUri += clientId;
    redirUri += "://auth";
    
    XalPlatformArgs xalPlatformArgs = {};
    xalPlatformArgs.redirectUri = redirUri.c_str();
    xalPlatformArgs.javaVM      = getJavaVM();
    xalPlatformArgs.appContext  = getAppContext();

    XalInitArgs xalInitArgs = {};
    xalInitArgs.clientId     = clientId.c_str();
    xalInitArgs.titleId      = titleId;
    xalInitArgs.sandbox      = sandbox.c_str();
    xalInitArgs.platformArgs = &xalPlatformArgs;

    // Call XAL_Init after XblInitialize
    hr = XAL_Init(XblGetAsyncQueue(), &xalInitArgs, nullptr, g_storagePath);
    ASSERT_MESSAGE(SUCCEEDED(hr), "Failed to Init XAL!");
    
    return true;
}
```

Targeting iOS:
```cpp
bool XsapiInit()
{
    HRESULT hr = E_FAIL;

    // 1) Initialize Async

    // 2) Initialize Xbl

    // 3) Initialize XAL
    
    std::string clientId = "0000000000000000";
    uint32_t titleId = 0;
    std::string sandbox = "XXXX.X";
    
    std::string redirUri = "xal-";
    redirUri += clientId;
    redirUri += "://auth";
    
    XalPlatformArgs xalPlatformArgs = {};
    xalPlatformArgs.redirectUri = redirUri.c_str();

    XalInitArgs xalInitArgs = {};
    xalInitArgs.clientId     = clientId.c_str();
    xalInitArgs.titleId      = titleId;
    xalInitArgs.sandbox      = sandbox.c_str();
    xalInitArgs.platformArgs = &xalPlatformArgs;

    // Call XAL_Init after XblInitialize
    hr = XAL_Init(XblGetAsyncQueue(), &xalInitArgs, nullptr, g_storagePath);
    ASSERT_MESSAGE(SUCCEEDED(hr), "Failed to Init XAL!");
    
    return true;
}
```

Inside of XAL_Init, we must setup debugging and memory management:

1) If you want debugging info, then set that up
2) Setup Xal memory functions
3) Store the path passed in for the Xal memory functions
4) Setup XalPlatformStorageEventHandlers
5) Pass XalPlatformStorageEventHandlers into XAL
6) Initialize XAL

```cpp
HRESULT XAL_Init(
    _In_ XTaskQueueHandle asyncQueue,
    _In_ XalInitArgs* xalInitArgs,
    _In_opt_ void* context,
    _In_opt_z_ char const* pathPrefix)
{
    // Must be set before any XAL calls
    HCSettingsSetTraceLevel(HCTraceLevel::Verbose);
    HCTraceSetTraceToDebugger(true);

    // Optional if you want to hook up memory management for XAL
    HRESULT hr = XalMemSetFunctions(&XalMemAlloc, &XalMemFree);
    ASSERT_MESSAGE(SUCCEEDED(hr), "XalMemSetFunctions Failed!");

    // Store PathPrefix to be used later by read/write/clear functions
    g_pathPrefix = pathPrefix;

    XalPlatformStorageEventHandlers storage = {};
    storage.write   = &OnWrite;
    storage.read    = &OnRead;
    storage.clear   = &OnClear;
    storage.context = context;

    hr = XalPlatformStorageSetEventHandlers(asyncQueue, &storage);
    ASSERT_MESSAGE(SUCCEEDED(hr), "XalPlatformStorageSetEventHandlers Failed!");
    
    return XalInitialize(xalInitArgs, asyncQueue);
}
```

The following are the functions utilized by XalMemSetFunctions and XalPlatformStorageEventHandlers:

```cpp
static _Ret_maybenull_ _Post_writable_byte_size_(size) void* __cdecl XalMemAlloc(_In_ size_t size, _In_ uint32_t tag)
{
    UNREFERENCED_PARAMETER(tag);
    return new (std::nothrow) int8_t[size];
}

static void __cdecl XalMemFree(_In_ _Post_invalid_ void* pointer, _In_ uint32_t tag)
{
    UNREFERENCED_PARAMETER(tag);
    delete[] pointer;
}

std::string MakeName(char const* key)
{
    if (!g_pathPrefix.empty())
    {
        return g_pathPrefix + "/" + std::string{ key } + ".json";
    }

    return std::string{ key } + ".json";
}

void OnWrite(
    _In_opt_ void* context,
    _In_opt_ void* userContext,
    _In_ XalPlatformOperation operation,
    _In_z_ char const* key,
    _In_ size_t dataSize,
    _In_reads_bytes_(dataSize) void const* data)
{
    UNREFERENCED_PARAMETER(context);
    UNREFERENCED_PARAMETER(userContext);

    if (dataSize == 0 || data == nullptr)
    {
        return;
    }

    std::string path;

    {
        std::lock_guard<std::mutex> lock(g_mutex);

        path = MakeName(key);

        if (path.empty())
        {
            XalPlatformStorageWriteComplete(operation, XalPlatformOperationResult_Failure);
            return;
        }

        std::ofstream file{ path, std::ios::binary | std::ios::trunc };

        if (!file.is_open())
        {
            XalPlatformStorageWriteComplete(operation, XalPlatformOperationResult_Failure);
            return;
        }

        file.write(static_cast<char const*>(data), dataSize);

        if (file.fail())
        {
            file.close();
            XalPlatformStorageWriteComplete(operation, XalPlatformOperationResult_Failure);
            return;
        }

        file.close();
    }

    XalPlatformStorageWriteComplete(operation, XalPlatformOperationResult_Success);
}

void OnRead(
    _In_opt_ void* context,
    _In_opt_ void* userContext,
    _In_ XalPlatformOperation operation,
    _In_z_ char const* key)
{
    UNREFERENCED_PARAMETER(context);
    UNREFERENCED_PARAMETER(userContext);

    std::string path;
    std::vector<char> data;

    {
        std::lock_guard<std::mutex> lock(g_mutex);

        path = MakeName(key);

        if (path.empty())
        {
            XalPlatformStorageReadComplete(operation, XalPlatformOperationResult_Failure, 0, nullptr);
            return;
        }

        std::ifstream file{ path, std::ios::binary | std::ios::ate };

        if (!file.is_open())
        {
            // couldn't open the file, let's assume it does not exist
            XalPlatformStorageReadComplete(operation, XalPlatformOperationResult_Success, 0, nullptr);
            return;
        }

        size_t size = file.tellg();
        file.seekg(0, file.beg);

        data.resize(size);

        file.read(data.data(), data.size());

        if (file.fail())
        {
            file.close();
            XalPlatformStorageReadComplete(operation, XalPlatformOperationResult_Failure, 0, nullptr);
            return;
        }

        file.close();
    }

    XalPlatformStorageReadComplete(operation, XalPlatformOperationResult_Success, data.size(), data.data());
}

void OnClear(
    _In_opt_ void* context,
    _In_opt_ void* userContext,
    _In_ XalPlatformOperation operation,
    _In_z_ char const* key)
{
    UNREFERENCED_PARAMETER(context);
    UNREFERENCED_PARAMETER(userContext);

    std::string path;

    {
        std::lock_guard<std::mutex> lock(g_mutex);

        path = MakeName(key);

        if (path.empty())
        {
            XalPlatformStorageClearComplete(operation, XalPlatformOperationResult_Failure);
            return;
        }

        int res = std::remove(path.c_str());

        if (res != 0)
        {
            XalPlatformStorageClearComplete(operation, XalPlatformOperationResult_Failure);
            return;
        }
    }

    XalPlatformStorageClearComplete(operation, XalPlatformOperationResult_Success);
}
```

## Basic Sign-In/Sign-Out

Now that Xbox Live is initialized, it's time for us to setup our Sign-In and Sign-Out functionality.

XAL functionality is split between 3 function types:

    1) Calling the Async function, thus adding the task to the XTaskQueue to send to the server
    2) Running a callback function, when the server responds back to the API
    3) Implementing a gameplay function, to be used by the developer to handle the server response
    
Many of the gameplay functions will reference the function bellow:

```cpp
void XAL_Gameplay_CloseUserContext(_In_ XblContextHandle xblContext)
{
    if (xblContext)
    {
        XalUserHandle user = nullptr;
        HRESULT hr = XblContextGetUser(xblContext, &user);

        if (SUCCEEDED(hr))
        {
            XalUserCloseHandle(user);
        }

        XblContextCloseHandle(xblContext);
    }
}
```

### Sign-In Silently

To start off with, we will add in Sign-In Silently.

This function should be called when your app/game starts up to sign-in the previously logged in user.

The function below wraps the async call XalTryAddDefaultUserSilentlyAsync.

```cpp
HRESULT XAL_TrySignInUserSilently(_In_ XTaskQueueHandle asyncQueue)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
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
    // Note: XalTryAddDefaultUserSilentlyResult will add a Ref to the passed in XalUserHandle

    if (FAILED(hr))
    {
        SampleLog(LL_ERROR, "XalTryAddDefaultUserSilentlyResult Failed!");
        SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(hr).c_str());
    }

    XAL_Gameplay_TrySignInUserSilently(newUser, hr);

    // Close the Reference if one was created during XalTryAddDefaultUserSilentlyResult
    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```

In gameplay, we will handle if an XblContext should be created from our XalUser.

If an XblContext is created, then the user has properly signed in.

```cpp
void XAL_Gameplay_TrySignInUserSilently(_In_ XalUserHandle newUser, _In_ HRESULT result)
{
    // TODO(GameDev): Implement gameplay logic below

    if (SUCCEEDED(result))
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
                // Close the previous Xbl Context, if one existed
                XAL_Gameplay_CloseUserContext(getXblContext());

                // Store the new XblContext
                setXblContext(newXblContext);

                SampleLog(LL_INFO, "Auto sign-in successful!");

                // Welcome the user to your app/game
            }
            else
            {
                SampleLog(LL_ERROR, "XblContextCreateHandle Failed!");
                SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(hr).c_str());
            }
        }
        else
        {
            SampleLog(LL_ERROR, "XalUserGetId Failed!");
            SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(hr).c_str());
        }
    }
    else
    {
        SampleLog(LL_INFO, "Auto sign-in failed! Please sign-in with the UI!");
    }
}
```

### Sign-In with UI

If sign-in silently fails, then the user will need to sign-in using XAL's web view UI.

Just like with sign-in silently, we will create a wrapper to call our async function XalAddUserWithUiAsync.

```cpp
HRESULT XAL_TrySignInUserWithUI(_In_ XTaskQueueHandle asyncQueue)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = XAL_TrySignInUserWithUI_Callback;

    return XalAddUserWithUiAsync(nullptr, asyncBlock);
}
```

The callback function will grab the result from the server and then we will pass it to gameplay.

```cpp
void CALLBACK XAL_TrySignInUserWithUI_Callback(_In_ XAsyncBlock* asyncBlock)
{
    if (asyncBlock == nullptr) { return; }

    XblUserHandle newUser = nullptr;
    HRESULT hr = XalAddUserWithUiResult(asyncBlock, &newUser);
    // Note: XalAddUserWithUiResult will add a Ref to the passed in XalUserHandle

    if (FAILED(hr))
    {
        SampleLog(LL_ERROR, "XalAddUserWithUiResult Failed!");
        SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(hr).c_str());
    }

    XAL_Gameplay_TrySignInUserWithUI(newUser, hr);

    // Close the Reference if one was created during XalTryAddDefaultUserSilentlyResult
    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```

Just like with sign-in silently, in gameplay we will check if the user is valid for your title.

If valid, then we will create an XblContext based off their XalUser.

However, if XalUserGetId fails, we will need to try and resolve any issues.

To do this, we will need to duplicate the XalUserHandle so that we can pass it through XAL_TryResolveUserIssue.

```cpp
void XAL_Gameplay_TrySignInUserWithUI(_In_ XalUserHandle newUser, _In_ HRESULT result)
{
    // TODO(GameDev): Implement gameplay logic below

    if (SUCCEEDED(result))
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
                // Close the previous Xbl Context, if one existed
                XAL_Gameplay_CloseUserContext(getXblContext());

                // Store the new XblContext
                setXblContext(newXblContext);

                SampleLog(LL_INFO, "Sign-in with UI successful!");
                
                // Welcome the user to your app/game
            }
            else
            {
                SampleLog(LL_ERROR, "XblContextCreateHandle Failed!");
                SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(hr).c_str());
            }
        }
        else
        {
            SampleLog(LL_ERROR, "XalUserGetId Failed!");
            SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(hr).c_str());

            SampleLog(LL_INFO, "Trying to resolve user issue with UI");

            // Duplicate the handle to prolong the user to be handled later by resolve
            XblUserHandle dupUser = nullptr;
            XalUserDuplicateHandle(newUser, &dupUser);
            // Note: Creates a Ref for XblUserHandle, will be closed inside XAL_Gameplay_TryResolveUserIssue

            HRESULT asyncResult = XAL_TryResolveUserIssue(XblGetAsyncQueue(), dupUser);

            if (FAILED(asyncResult))
            {
                SampleLog(LL_ERROR, "XalUserResolveIssueWithUiAsync Failed!");
                SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(asyncResult).c_str());
                if (dupUser) { XalUserCloseHandle(dupUser); }
            }
        }
    }
    else
    {
        SampleLog(LL_INFO, ""); // New line
        SampleLog(LL_INFO, "Sign-in with UI failed!");
    }
}
```

Next, we must create the XAL_TryResolveUserIssue function.

We will use asyncBlock-context to store the handle to the new user to be used later in the callback.

```cpp
HRESULT XAL_TryResolveUserIssue(_In_ XTaskQueueHandle asyncQueue, _In_ XalUserHandle user)
{
    // Make sure a valid user was passed in
    if (user == nullptr)
    {
        SampleLog(LL_ERROR, "The XalUserHandle passed in was NULL!");
        return E_INVALIDARG;
    }

    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->context = user;
    asyncBlock->callback = XAL_TryResolveUserIssue_Callback;

    return XalUserResolveIssueWithUiAsync(user, "https://www.xboxlive.com", asyncBlock);
}
```

The callback function will then grab the XAsyncGetStatus result to be passed onto gameplay.

We will also make sure to grab the XalUserHandle, from asyncBlock->context, to be passed onto gameplay.        

```cpp
void CALLBACK XAL_TryResolveUserIssue_Callback(_In_ XAsyncBlock* asyncBlock)
{
    if (asyncBlock == nullptr) { return; }

    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    if (FAILED(hr))
    {
        SampleLog(LL_ERROR, "XAsyncGetStatus for XalUserResolveIssueWithUiAsync Failed!");
        SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(hr).c_str());
    }

    XalUserHandle user = reinterpret_cast<XblUserHandle>(asyncBlock->context);

    XAL_Gameplay_TryResolveUserIssue(user, hr);

    delete asyncBlock;
}
```

The gameplay function should prompt the user if the issues were resolved or not.

After gameplay logic is done, we will make sure to close the XalUserHandle that was duplicated from before.

```cpp
void XAL_Gameplay_TryResolveUserIssue(_In_ XalUserHandle user, _In_ HRESULT result)
{
    // TODO(GameDev): Implement gameplay logic below

    if (SUCCEEDED(result))
    {
        SampleLog(LL_INFO, "Issues with sign-in resolved!");
    }
    else
    {
        SampleLog(LL_ERROR, "Issues with sign-in failed to resolve!");
        SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(result).c_str());
    }

    SampleLog(LL_INFO, "Please try signing-in with UI again!");

    // Close the Reference if one was created during XalUserDuplicateHandle
    if (user) { XalUserCloseHandle(user); }
}
```

### Sign-Out

Now that sign-in is taken care of, it's time to implement sign-out.

```cpp
HRESULT XAL_TrySignOutUser(_In_ XTaskQueueHandle asyncQueue, _In_ XalUserHandle user)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = XAL_TrySignOutUser_Callback;

    return XalSignOutUserAsync(user, asyncBlock);
}
```

The callback function will then grab the XAsyncGetStatus result to be passed onto gameplay.

```cpp
void CALLBACK XAL_TrySignOutUser_Callback(_In_ XAsyncBlock* asyncBlock)
{
    if (asyncBlock == nullptr) { return; }

    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    if (FAILED(hr))
    {
        SampleLog(LL_ERROR, "XAsyncGetStatus for XalSignOutUserAsync Failed!");
        SampleLog(LL_ERROR, "Error code: %s", ConvertHRtoString(hr).c_str());
    }

    XAL_Gameplay_TrySignOutUser(hr);

    delete asyncBlock;
}
```

If the callback succeeded, then the gameplay function should grab the existing XblContext and close it.

```cpp
void XAL_Gameplay_TrySignOutUser(_In_ HRESULT result)
{
    // TODO(GameDev): Implement gameplay logic below

    if (SUCCEEDED(result))
    {
        XblContextHandle xblContext = getXblContext();

        XalUserHandle user = nullptr;
        HRESULT hr = XblContextGetUser(xblContext, &user);

        if (SUCCEEDED(hr))
        {
            // Say good-bye to user
        }

        XAL_Gameplay_CloseUserContext(xblContext);
        setXblContext(nullptr);

        SampleLog(LL_INFO, "User sign-out successful!");
    }
    else
    {
        SampleLog(LL_INFO, "User sign-out failed!");
    }
}
```

## Runtime

If you're using a Manual XTaskQueue, then you'll need to handle draining the completion queue during runtime.

### Async Draining the Completion Queue

Add one of the 3 methods to your game and call it during your game loop.

```cpp
void Async_DrainCompletionQueueUntilEmpty(_In_ XTaskQueueHandle queue)
{
    if (g_completionDispatchMode == XTaskQueueDispatchMode::Manual)
    {
        bool found = false;

        do
        {
            if (g_stopBackgroundWork) { break; }

            found = XTaskQueueDispatch(queue, XTaskQueuePort::Completion, 0);
        } while (found);
    }
}
```

```cpp
bool Async_DrainCompletionQueueWithTimeout(_In_ XTaskQueueHandle queue, _In_ double stopAfterMilliseconds)
{
    bool found = false;

    if (g_completionDispatchMode == XTaskQueueDispatchMode::Manual)
    {
        std::chrono::time_point<std::chrono::system_clock> startTime;
        std::chrono::time_point<std::chrono::system_clock> endTime;
        double elapsedTime;

        do
        {
            if (g_stopBackgroundWork) { break; }

            startTime = std::chrono::system_clock::now();

            found = XTaskQueueDispatch(queue, XTaskQueuePort::Completion, 0);

            if (!found) { break; }

            endTime = std::chrono::system_clock::now();

            elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

            stopAfterMilliseconds -= elapsedTime;

            if (stopAfterMilliseconds < 0.0) { break; }

        } while (found);
    }

    return found;
}
```

```cpp
bool Async_DrainCompletionQueue(_In_ XTaskQueueHandle queue, _In_ uint32_t maxItemsToDrain)
{
    bool found = false;

    if (g_completionDispatchMode == XTaskQueueDispatchMode::Manual)
    {
        for (uint32_t i = maxItemsToDrain; i > 0; --i)
        {
            if (g_stopBackgroundWork) { break; }

            found = XTaskQueueDispatch(queue, XTaskQueuePort::Completion, 0);

            if (!found) { break; }
        }
    }

    return found;
}
```

## Cleanup

Now that everything is implemented, we need to make sure that we clean it up when your game closes.

### XAL Cleanup

XAL doesn't require any cleanup, however, you will need to close your XblContextHandle and XalUserHandle.

```cpp
if (m_xblContext)
{
    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(m_xblContext, &user);

    if (SUCCEEDED(hr))
    {
        XalUserCloseHandle(user);
    }

    XblContextCloseHandle(m_xblContext);
}
```

### Xbl Cleanup

When your game closes, make sure to cleanup Xbox Live.

```cpp
XblCleanup();
```

### Async Cleanup

After you cleanup Xbox Live, make sure to cleanup your manual XTaskQueue.

```cpp
void XAsync_Cleanup(_In_ XTaskQueueHandle asyncQueue)
{
    if (g_workDispatchMode == XTaskQueueDispatchMode::Manual)
    {
        {
            std::lock_guard<std::mutex> lock(g_stopBackgroundWorkMutex);
            g_stopBackgroundWork = true;
        }

        if (g_backgroundThread.joinable())
        {
            g_backgroundThread.join();
        }
    }

    if (asyncQueue)
    {
        XTaskQueueCloseHandle(asyncQueue);
    }
}
```
        
<!--===========================================================-->
## Next step

After your game is set up with Sign-In, you are now ready to implement any of the features provided by XSAPI.
See [Features](../features/index.md).