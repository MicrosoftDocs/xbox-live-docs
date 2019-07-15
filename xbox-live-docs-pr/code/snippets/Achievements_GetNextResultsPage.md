```cpp
HRESULT Achievements_GetNextResultsPage(
    _In_ XTaskQueueHandle asyncQueue,
    _In_ XblContextHandle xblContext,
    _In_ XblAchievementsResultHandle resultHandle,
    _In_ uint32_t maxItems)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Achievements_GetNextResultsPage_Callback;

    // Request to get next page of achievements
    HRESULT hr = XblAchievementsResultGetNextAsync(
                    xblContext,
                    resultHandle,
                    maxItems,
                    asyncBlock);

    if (FAILED(hr))
    {
        // LOG: Failed to request next page of achievements
        delete asyncBlock;
    }

    return hr;
}
```
