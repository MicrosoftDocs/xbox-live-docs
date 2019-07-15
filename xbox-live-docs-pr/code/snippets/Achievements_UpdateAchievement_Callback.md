```cpp
void CALLBACK Achievements_UpdateAchievement_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    if (SUCCEEDED(hr))
    {
        // LOG: Achievement updated successfully
    }
    else if (hr == HTTP_E_STATUS_NOT_MODIFIED)
    {
        // LOG: Achievement not modifiable
    }
    else
    {
        // LOG: Failed to update achievement
    }

    delete asyncBlock;
}
```
