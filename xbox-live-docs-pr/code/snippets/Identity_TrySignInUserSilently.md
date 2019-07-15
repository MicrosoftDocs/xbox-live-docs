```cpp
HRESULT Identity_TrySignInUserSilently(_In_ XTaskQueueHandle asyncQueue)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Identity_TrySignInUserSilently_Callback;

    // Request to silently sign-in default user
    HRESULT hr = XalTryAddDefaultUserSilentlyAsync(nullptr, asyncBlock);

    if (FAILED(hr))
    {
        // LOG: Failed to request sign-in silently
        delete asyncBlock;
    }

    return hr;
}
```
