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
    }
    else
    {
        // TODO: Handle failure to get achievements result handle
    }

    // TODO: Handle achievement gameplay
    Achievements_Gameplay_GetAchievement(hr, achievements, achievementsCount);

    delete asyncBlock;
}
```
