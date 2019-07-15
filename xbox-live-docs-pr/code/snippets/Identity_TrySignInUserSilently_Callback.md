```cpp
void CALLBACK Identity_TrySignInUserSilently_Callback(_In_ XAsyncBlock* asyncBlock)
{
    // NOTE: XalTryAddDefaultUserSilentlyResult will add a Ref to the passed in XalUserHandle
    XalUserHandle newUser = nullptr;
    HRESULT hr = XalTryAddDefaultUserSilentlyResult(asyncBlock, &newUser);

    if (SUCCEEDED(hr))
    {
        // TODO: Create XBL Context
    }
    else
    {
        // LOG: Failed to sign-in user silently
    }

    // Close the Reference if one was created during XalTryAddDefaultUserSilentlyResult
    if (newUser) { XalUserCloseHandle(newUser); }

    delete asyncBlock;
}
```
