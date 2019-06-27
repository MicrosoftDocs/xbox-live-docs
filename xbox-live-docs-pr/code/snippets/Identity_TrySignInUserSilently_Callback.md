```cpp
void CALLBACK Identity_TrySignInUserSilently_Callback(_In_ XAsyncBlock* asyncBlock)
{
    // Note: XalTryAddDefaultUserSilentlyResult will add a Ref to the passed in XalUserHandle
    XalUserHandle newUser = nullptr;
    HRESULT hr = XalTryAddDefaultUserSilentlyResult(asyncBlock, &newUser);

    // TODO: Handle sign-in silently gameplay
    Identity_Gameplay_TrySignInUserSilently(newUser, hr);

    // Close the Reference if one was created during XalTryAddDefaultUserSilentlyResult
    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```
