```cpp
    AsyncBlock* asyncBlock = new AsyncBlock();
    asyncBlock->queue = GlobalState()->queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](AsyncBlock* asyncBlock)
    {
        HRESULT hr = GetAsyncStatus(asyncBlock, false);
        delete asyncBlock;
    };

    HRESULT hr = XalUserResolveIssueWithUiAsync(GlobalState()->xalUser, "https://www.xboxlive.com", asyncBlock);
```
