```cpp
    // TODO: Get the current XblContext as xblContext

    XalUserHandle user = nullptr;
    HRESULT hr = XblContextGetUser(xblContext, &user);

    if (SUCCEEDED(hr))
    {
        // TODO: Handle sign-out gameplay
    }

    if (xblContext)
    {
        if (user)
        {
            XalUserCloseHandle(user);
        }

        XblContextCloseHandle(xblContext);
    }
```
