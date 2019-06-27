```cpp
void CALLBACK Identity_TrySignOutUser_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    // TODO: Handle sign-out gameplay
    Identity_Gameplay_TrySignOutUser(hr);

    delete asyncBlock;
}
```
