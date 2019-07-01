```cpp
void CALLBACK Achievements_UpdateAchievement_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    // TODO: Handle update achievement gameplay
    Achievements_Gameplay_UpdateAchievement(hr);

    delete asyncBlock;
}
```
