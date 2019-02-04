```cpp
    AsyncBlock* asyncBlock = new AsyncBlock();
    asyncBlock->queue = GlobalState()->queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](AsyncBlock* asyncBlock)
    {
        XblUserProfile profile = { 0 };
        HRESULT hr = XblProfileGetUserProfileResult(asyncBlock, &profile);
        delete asyncBlock;
    };

    HRESULT hr = XblProfileGetUserProfileAsync(GlobalState()->xboxLiveContext, GlobalState()->xboxUserId, asyncBlock);
```
