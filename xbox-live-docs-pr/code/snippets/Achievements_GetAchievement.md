```cpp
HRESULT Achievements_GetAchievement(
    _In_ XTaskQueueHandle asyncQueue,
    _In_ XblContextHandle xblContext,
    _In_z_ const std::string& achievementId)
{
    XAsyncBlock* asyncBlock = new XAsyncBlock();
    asyncBlock->queue = asyncQueue;
    asyncBlock->callback = Achievements_GetAchievement_Callback;

    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(xblContext, &user);

    // TODO: Handle HRESULT hr

    uint64_t xuid = 0;
    hr = XalUserGetId(user, &xuid);

    // TODO: Handle HRESULT hr

    XblGuid scid = {0};
    hr = XblGetScid(&scid);

    // TODO: Handle HRESULT hr

    // Request to get achievement
    return XblAchievementsGetAchievementAsync(
        xblContext,
        xuid,
        scid.value,
        achievementId.c_str(),
        asyncBlock);
}
```
