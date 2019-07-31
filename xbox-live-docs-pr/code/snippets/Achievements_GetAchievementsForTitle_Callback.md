```cpp
void CALLBACK Achievements_GetAchievementsForTitle_Callback(_In_ XAsyncBlock* asyncBlock)
{
    XblAchievementsResultHandle resultHandle = nullptr;
    HRESULT hr = XblAchievementsGetAchievementsForTitleIdResult(asyncBlock, &resultHandle);

    if (SUCCEEDED(hr))
    {
        XblAchievement* achievements = nullptr;
        uint32_t achievementsCount = 0;
        hr = XblAchievementsResultGetAchievements(resultHandle, &achievements, &achievementsCount);

        if (SUCCEEDED(hr))
        {
            // Check if achievements has a next page
            bool hasNextPage = false;
            XblAchievementsResultHasNext(resultHandle, &hasNextPage);

            // TODO: Iterate over achievements
            // TODO: If hasNextPage, store resultHandle
        }
        else
        {
            // LOG: Failed to get achievements
        }
    }
    else
    {
        // LOG: Failed to get achievements result handle
    }

    delete asyncBlock;
}
```
