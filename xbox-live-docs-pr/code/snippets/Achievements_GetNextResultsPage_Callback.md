```cpp
void CALLBACK Achievements_GetNextResultsPage_Callback(_In_ XAsyncBlock* asyncBlock)
{
    XblAchievementsResultHandle resultHandle = nullptr;
    HRESULT hr = XblAchievementsResultGetNextResult(asyncBlock, &resultHandle);

    XblAchievement* achievements = nullptr;
    uint32_t achievementsCount = 0;
    bool hasNextPage = false;

    if (SUCCEEDED(hr))
    {
        hr = XblAchievementsResultGetAchievements(resultHandle, &achievements, &achievementsCount);

        if (SUCCEEDED(hr))
        {
            // Check if achievements has a next page
            XblAchievementsResultHasNext(resultHandle, &hasNextPage);
        }
    }
    else
    {
        // TODO: Handle failure to get achievements result handle
    }

    // TODO: Handle achievements next page gameplay
    Achievements_Gameplay_GetNextResultsPage(hr, resultHandle, achievements, achievementsCount, hasNextPage);

    delete asyncBlock;
}
```
