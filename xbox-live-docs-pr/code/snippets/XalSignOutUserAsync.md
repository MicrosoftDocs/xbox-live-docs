```cpp
    assert(XalSignOutUserAsyncIsPresent()); // check to make sure sign-out function is present
    assert(GlobalState()->xalUser)

    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = GlobalState()->queue;
    asyncBlock->context = myContext;
    asyncBlock->callback = [](XAsyncBlock* asyncBlock)
    {
        HRESULT hr = XalSignOutUserResult(asyncBlock);
        if (FAILED(hr))
        {
            // Failed to sign out, this should only happen due to network errors
            // Display error message
        }
        else
        {
            // Move to a signed out state
        }

        delete asyncBlock;
    };

    HRESULT hr = XalSignOutUserAsync(GlobalState()->xalUser, asyncBlock);
    if (FAILED(hr))
    {
        delete asyncBlock;
    }
```
