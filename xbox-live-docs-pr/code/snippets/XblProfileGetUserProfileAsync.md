```cpp
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = GlobalState()->queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](XAsyncBlock* asyncBlock)
    {
        XblUserProfile profile = { 0 };
        HRESULT hr = XblProfileGetUserProfileResult(asyncBlock, &profile);
        delete asyncBlock;
    };

    HRESULT hr = XblProfileGetUserProfileAsync(GlobalState()->xboxLiveContext, GlobalState()->xboxUserId, asyncBlock);
```
