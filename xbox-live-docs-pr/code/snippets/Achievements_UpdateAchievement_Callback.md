```cpp
void CALLBACK Achievements_UpdateAchievement_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    if (SUCCEEDED(hr))
    {
        // Achievement updated successfully
    }
    else if (hr == HTTP_E_STATUS_NOT_MODIFIED)
    {
        // Achievement not modifiable
    }
    else
    {
        // Failed to update achievement
    }

    // Pass info to be handled by gameplay
    Achievements_Gameplay_UpdateAchievement(hr);

    delete asyncBlock;
}
```
