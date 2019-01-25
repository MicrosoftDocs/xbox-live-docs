```cpp
    AsyncBlock* asyncBlock = new AsyncBlock();
    asyncBlock->queue = GlobalState()->queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](AsyncBlock* asyncBlock)
    {
        size_t bufferSize;
        HRESULT hr = XalUserGetTokenAndSignatureSilentlyResultSize(asyncBlock, &bufferSize);
        XalUserGetTokenAndSignatureData* result = (XalUserGetTokenAndSignatureData*)new byte[bufferSize];
        hr = XalUserGetTokenAndSignatureSilentlyResult(asyncBlock, bufferSize, result);
        delete[] result;
        delete asyncBlock;
    };

    XalUserGetTokenAndSignatureArgs args = {}; // TODO: fill out
    HRESULT hr = XalUserGetTokenAndSignatureSilentlyAsync(GlobalState()->xalUser, &args, asyncBlock);
```
