```cpp
    HRESULT hr = XalPlatformStorageReadComplete(
        args->operation,
        result,
        data.size(),
		data.data()
        );
    LogRun("XalPlatformStorageReadComplete: hr=0x%08X", hr);
```
