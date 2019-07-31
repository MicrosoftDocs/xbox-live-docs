```cpp
void CALLBACK Identity_TrySignInUserWithUI_Callback(_In_ XAsyncBlock* asyncBlock)
{
    // NOTE: XalAddUserWithUiResult will add a Ref to the passed in XalUserHandle
    XalUserHandle newUser = nullptr;
    HRESULT hr = XalAddUserWithUiResult(asyncBlock, &newUser);

    if (SUCCEEDED(hr))
    {
        // TODO: Create XBL Context
    }
    else
    {
        // LOG: Failed to sign-in user with UI
        // TODO: Resolve issues with UI
    }

    // Close the Reference if one was created during XalTryAddDefaultUserSilentlyResult
    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```
