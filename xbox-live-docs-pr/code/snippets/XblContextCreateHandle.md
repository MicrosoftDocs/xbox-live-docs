```cpp
#if !UWP_API
    HRESULT hr = XblContextCreateHandle(GlobalState()->xalUser, &GlobalState()->xboxLiveContext);
#else 
    HRESULT hr = S_OK;
#endif
```
