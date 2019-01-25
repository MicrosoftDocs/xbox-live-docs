```cpp
    char gamertag[XAL_USER_GAMERTAG_MAX_SIZE];
    HRESULT hr = XalUserGetGamertag(GlobalState()->xalUser, XAL_USER_GAMERTAG_MAX_SIZE, gamertag, nullptr);
```
