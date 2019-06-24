```cpp
void CALLBACK Achievements_GetNextResultsPage_Callback(_In_ XAsyncBlock* asyncBlock)
{
    XblAchievementsResultHandle achievementsResultHandle = nullptr;
    HRESULT hr = XblAchievementsResultGetNextResult(asyncBlock, &achievementsResultHandle);

    XblAchievement* achievements = nullptr;
    uint32_t achievementsCount = 0;
    bool hasNextPage = false;

    if (SUCCEEDED(hr))
    {
        hr = XblAchievementsResultGetAchievements(achievementsResultHandle, &achievements, &achievementsCount);

        if (SUCCEEDED(hr))
        {
            // Check if achievements has a next page
            XblAchievementsResultHasNext(achievementsResultHandle, &hasNextPage);
        }
        else
        {
            // Failed to get achievements
        }
    }
    else
    {
        // Failed to get next achievements restult handle
    }

    // Pass info to be handled by gameplay
    Achievements_Gameplay_GetNextResultsPage(hr, achievementsResultHandle, achievements, achievementsCount, hasNextPage);

    delete asyncBlock;
}
```
