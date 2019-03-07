```cpp
    XalPlatformStorageEventHandlers storageHandlers{};
    storageHandlers.context = context;
    storageHandlers.write = &Xal_PlatformOnWriteHandler;
    storageHandlers.read = &Xal_PlatformOnReadHandler;
    storageHandlers.clear = &Xal_PlatformOnClearHandler;
	
	HRESULT res = XalPlatformStorageSetEventHandlers(GlobalState()->queue, &storageHandlers);
```
