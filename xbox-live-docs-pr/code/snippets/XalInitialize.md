```cpp
    XalPlatformArgs xalPlatformArgs = {};
    xalPlatformArgs.redirectUri = redirectUri;

    XalInitArgs xalInitArgs = {};
    xalInitArgs.ClientId = clientId;
    xalInitArgs.TitleId = ConvertStringToUInt64(titleId);
    xalInitArgs.Sandbox = sandbox;
    xalInitArgs.PlatformArgs = &xalPlatformArgs;

    HRESULT hr = XalInitialize(&xalInitArgs, GlobalState()->queue);
```
