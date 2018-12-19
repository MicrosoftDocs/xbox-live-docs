```cpp
    AsyncBlock* asyncBlock = new AsyncBlock();
    asyncBlock->queue = g_queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](AsyncBlock* asyncBlock)
    {
        XblUserProfile profile = { 0 };
        HRESULT hr = XblProfileGetUserProfileResult(asyncBlock, &profile);
	// TODO: use profile
        delete asyncBlock;
    };

    HRESULT hr = XblProfileGetUserProfileAsync(g_xboxLiveContext, g_xboxUserId, asyncBlock);
```
