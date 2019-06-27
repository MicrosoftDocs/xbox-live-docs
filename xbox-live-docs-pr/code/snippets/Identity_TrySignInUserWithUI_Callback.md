```cpp
void CALLBACK Identity_TrySignInUserWithUI_Callback(_In_ XAsyncBlock* asyncBlock)
{
    // Note: XalAddUserWithUiResult will add a Ref to the passed in XalUserHandle
    XalUserHandle newUser = nullptr;
    HRESULT hr = XalAddUserWithUiResult(asyncBlock, &newUser);

    // TODO: Handle sign-in with UI gameplay
    Identity_Gameplay_TrySignInUserWithUI(newUser, hr);

    // Close the Reference if one was created during XalTryAddDefaultUserSilentlyResult
    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```
