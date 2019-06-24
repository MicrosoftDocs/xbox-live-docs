```cpp
void CALLBACK Identity_TrySignOutUser_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    // Pass info to be handled by gameplay
    Identity_Gameplay_TrySignOutUser(hr);

    delete asyncBlock;
}
```
