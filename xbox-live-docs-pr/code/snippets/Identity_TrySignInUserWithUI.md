```cpp
HRESULT Identity_TrySignInUserWithUI(_In_ XTaskQueueHandle asyncQueue)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Identity_TrySignInUserWithUI_Callback;

    // Request to sign-in user with UI
    HRESULT hr = XalAddUserWithUiAsync(nullptr, asyncBlock);

    if (FAILED(hr))
    {
        // LOG: Failed to request sign-in with UI
        delete asyncBlock;
    }

    return hr;
}
```
