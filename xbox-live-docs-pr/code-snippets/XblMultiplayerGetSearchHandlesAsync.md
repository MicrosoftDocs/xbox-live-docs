```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t resultCount{ 0 };
    auto hr = XblMultiplayerGetSearchHandlesResultCount(asyncBlock, &resultCount);
    if (SUCCEEDED(hr) && resultCount > 0)
    {
        auto handles = new XblMultiplayerSearchHandle[resultCount];

        hr = XblMultiplayerGetSearchHandlesResult(asyncBlock, handles, resultCount);
        LogToFile("XblMultiplayerGetSearchHandlesResult: hr=%s", ConvertHR(hr).data());

        if (SUCCEEDED(hr))
        {
            LogToFile("Got %u search handles:", resultCount);

            for (auto i = 0u; i < resultCount; ++i)
            {
                const char* handleId{ nullptr };
                XblMultiplayerSearchHandleGetId(handles[i], &handleId);
                LogToFile("\t%s", handleId);

                XblMultiplayerSearchHandleCloseHandle(handles[i]);
            }
        }
    }

};

HRESULT hr = XblMultiplayerGetSearchHandlesAsync(
    xboxLiveContext,
    scid,
    "MinGameSession",
    nullptr,
    false,
    nullptr,
    nullptr,
    asyncBlock.get()
);
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```
