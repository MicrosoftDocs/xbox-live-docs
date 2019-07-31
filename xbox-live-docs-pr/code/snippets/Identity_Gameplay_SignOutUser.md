```cpp
    // TODO: Get the current XblContext as xblContext

    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(xblContext, &user);

    if (SUCCEEDED(hr))
    {
        // TODO: Handle sign-out gameplay

        XalUserCloseHandle(user);
    }
    else
    {
        // LOG: Failed to get user handle
    }

    if (xblContext)
    {
        XblContextCloseHandle(xblContext);
    }
```
