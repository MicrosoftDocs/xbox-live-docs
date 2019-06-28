```cpp
HRESULT Achievements_UpdateAchievement(
    _In_ XTaskQueueHandle asyncQueue,
    _In_ XblContextHandle xblContext,
    _In_z_ const std::string& achievementId,
    _In_ uint32_t percentComplete)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Achievements_UpdateAchievement_Callback;

    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(xblContext, &user);

    // TODO: Handle HRESULT hr

    uint64_t xuid = 0;
    hr = XalUserGetId(user, &xuid);

    // TODO: Handle HRESULT hr

    // Request to update achievement
    return XblAchievementsUpdateAchievementAsync(
        xblContext,
        xuid,
        achievementId.c_str(),
        percentComplete,
        asyncBlock);
}
```
