```cpp
HRESULT Identity_TrySignInUserSilently(_In_ XTaskQueueHandle asyncQueue)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Identity_TrySignInUserSilently_Callback;

    // Request to silently sign-in default user
    return XalTryAddDefaultUserSilentlyAsync(nullptr, asyncBlock);
}
```
