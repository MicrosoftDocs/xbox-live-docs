```cpp
void CALLBACK Achievements_GetAchievement_Callback(_In_ XAsyncBlock* asyncBlock)
{
    XblAchievementsResultHandle resultHandle = nullptr;
    HRESULT hr = XblAchievementsGetAchievementResult(asyncBlock, &resultHandle);

    XblAchievement* achievements = nullptr;
    uint32_t achievementsCount = 0;

    if (SUCCEEDED(hr))
    {
        hr = XblAchievementsResultGetAchievements(resultHandle, &achievements, &achievementsCount);

        if (SUCCEEDED(hr))
        {
            // Check if achievements has a next page
        }
        else
        {
            // Failed to get achievement
        }
    }
    else
    {
        // Failed to get achievements result handle
    }

    // Pass info to be handled by gameplay
    Achievements_Gameplay_GetAchievement(hr, achievements, achievementsCount);

    delete asyncBlock;
}
```
