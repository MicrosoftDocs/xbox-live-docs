```cpp
HRESULT Achievements_UpdateAchievement(
    _In_ XTaskQueueHandle asyncQueue,
    _In_ XblContextHandle xblContext,
    _In_z_ const std::string& achievementId,
    _In_ uint32_t percentComplete)
{
    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(xblContext, &user);

    if (SUCCEEDED(hr))
    {
        uint64_t xuid = 0;
        hr = XalUserGetId(user, &xuid);

        if (SUCCEEDED(hr))
        {
            XAsyncBlock* asyncBlock = new XAsyncBlock();
            asyncBlock->queue = asyncQueue;
            asyncBlock->callback = Achievements_UpdateAchievement_Callback;

            // Request to update achievement
            hr =  XblAchievementsUpdateAchievementAsync(
                    xblContext,
                    xuid,
                    achievementId.c_str(),
                    percentComplete,
                    asyncBlock);

            if (FAILED(hr))
            {
                // LOG: Failed to request achievement update
                delete asyncBlock;
            }
        }
        else
        {
            // LOG: Failed to get xuid
        }
    }
    else
    {
        // LOG: Failed to get user handle
    }

    return hr;
}
```
