```cpp
HRESULT Identity_TrySignInUserWithUI(_In_ XTaskQueueHandle asyncQueue)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Identity_TrySignInUserWithUI_Callback;

    // Request to sign-in user with UI
    return XalAddUserWithUiAsync(nullptr, asyncBlock);
}
```
