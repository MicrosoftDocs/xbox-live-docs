```cpp
HRESULT Identity_TrySignOutUser(_In_ XTaskQueueHandle asyncQueue, _In_ XalUserHandle user)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Identity_TrySignOutUser_Callback;

    // Request to sign-out user
    HRESULT hr = XalSignOutUserAsync(user, asyncBlock);

    if (FAILED(hr))
    {
        // LOG: Failed to request sign-out user
        delete asyncBlock;
    }

    return hr;
}
```
