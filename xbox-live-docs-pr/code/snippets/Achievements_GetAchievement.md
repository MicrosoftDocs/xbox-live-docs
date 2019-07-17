```cpp
HRESULT Achievements_GetAchievement(
    _In_ XTaskQueueHandle asyncQueue,
    _In_ XblContextHandle xblContext,
    _In_z_ const std::string& achievementId)
{
    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(xblContext, &user);

    if (SUCCEEDED(hr))
    {
        uint64_t xuid = 0;
        hr = XalUserGetId(user, &xuid);

        if (SUCCEEDED(hr))
        {
            XblGuid scid = {0};
            hr = XblGetScid(&scid);

            if (SUCCEEDED(hr))
            {
                XAsyncBlock* asyncBlock = new XAsyncBlock();
                asyncBlock->queue = asyncQueue;
                asyncBlock->callback = Achievements_GetAchievement_Callback;

                // Request to get achievement
                hr =  XblAchievementsGetAchievementAsync(
                        xblContext,
                        xuid,
                        scid.value,
                        achievementId.c_str(),
                        asyncBlock);

                if (FAILED(hr))
                {
                    // LOG: Failed to request achievement
                    delete asyncBlock;
                }
            }
            else
            {
                // LOG: Failed to get scid
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
