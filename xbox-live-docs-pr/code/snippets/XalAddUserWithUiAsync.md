```cpp
    AsyncBlock* asyncBlock = new AsyncBlock();
    asyncBlock->queue = GlobalState()->queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](AsyncBlock* asyncBlock)
    {
        xal_user_handle_t newUser = nullptr;
        HRESULT hr = XalAddUserWithUiResult(asyncBlock, &newUser);
        // TODO: Store and use newUser
        delete asyncBlock;
    };

    HRESULT hr = XalAddUserWithUiAsync(nullptr, asyncBlock);
```
