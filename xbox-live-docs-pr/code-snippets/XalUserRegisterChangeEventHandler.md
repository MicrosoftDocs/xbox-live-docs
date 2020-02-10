```cpp
#if HC_PLATFORM == HC_PLATFORM_GSDK
HRESULT hr = XalUserRegisterChangeEventHandler(queue, context, OnXalUserChangeEventHandler_GSDK, &token);
#else
HRESULT hr = XalUserRegisterChangeEventHandler(queue, context, OnXalUserChangeEventHandler, &token);
#endif
```
