```cpp
void CALLBACK Identity_TrySignOutUser_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);

    if (SUCCEEDED(hr))
    {
        // TODO: Close XBL Context
    }
    else
    {
        // LOG: Failed to sign-out user
    }

    delete asyncBlock;
}
```
