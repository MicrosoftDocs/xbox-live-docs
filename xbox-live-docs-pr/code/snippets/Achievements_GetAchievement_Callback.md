```cpp
void CALLBACK Achievements_GetAchievement_Callback(_In_ XAsyncBlock* asyncBlock)
{
    XblAchievementsResultHandle resultHandle = nullptr;
    HRESULT hr = XblAchievementsGetAchievementResult(asyncBlock, &resultHandle);

    if (SUCCEEDED(hr))
    {
        XblAchievement* achievements = nullptr;
        uint32_t achievementsCount = 0;
        hr = XblAchievementsResultGetAchievements(resultHandle, &achievements, &achievementsCount);

        if (SUCCEEDED(hr))
        {
            // TODO: Iterate over achievement
        }
        else
        {
            // LOG: Failed to get achievement
        }
    }
    else
    {
        // LOG: Failed to get achievement result handle
    }

    delete asyncBlock;
}
```
