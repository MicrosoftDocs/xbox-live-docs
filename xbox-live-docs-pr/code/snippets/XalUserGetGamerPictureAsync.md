```cpp
    AsyncBlock* asyncBlock = new AsyncBlock();
    asyncBlock->queue = GlobalState()->queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](AsyncBlock* asyncBlock)
    {
        size_t bufferSize;
        HRESULT hr = XalUserGetGamerPictureResultSize(asyncBlock, &bufferSize);
        byte* buffer = new byte[bufferSize];
        hr = XalUserGetGamerPictureResult(asyncBlock, bufferSize, buffer);
        delete[] buffer;
        delete asyncBlock;
    };

    HRESULT hr = XalUserGetGamerPictureAsync(GlobalState()->xalUser, XalGamerPictureSize_Small, asyncBlock);
```
