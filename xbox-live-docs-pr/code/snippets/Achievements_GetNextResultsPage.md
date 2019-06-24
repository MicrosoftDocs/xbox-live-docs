```cpp
HRESULT Achievements_GetNextResultsPage(
    _In_ XTaskQueueHandle asyncQueue,
    _In_ XblContextHandle xblContext,
    _In_ XblAchievementsResultHandle achievementsResultHandle,
    _In_ uint32_t maxItems)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Achievements_GetNextResultsPage_Callback;

    // Request to get next page of achievements
    return XblAchievementsResultGetNextAsync(
        xblContext,
        achievementsResultHandle,
        maxItems,
        asyncBlock);
}
```
