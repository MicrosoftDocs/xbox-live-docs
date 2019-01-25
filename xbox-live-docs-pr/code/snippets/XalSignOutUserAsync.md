```cpp
    AsyncBlock* asyncBlock = new AsyncBlock();
    asyncBlock->queue = GlobalState()->queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](AsyncBlock* asyncBlock)
    {
        HRESULT hr = GetAsyncStatus(asyncBlock, false);
        // TODO: Store and use newUser
        delete asyncBlock;
    };

    HRESULT hr = XalSignOutUserAsync(GlobalState()->xalUser, asyncBlock);
```
