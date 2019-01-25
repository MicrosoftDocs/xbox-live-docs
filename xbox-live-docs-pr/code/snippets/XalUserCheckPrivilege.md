```cpp
    XalPrivilege privilege = XalPrivilege_Multiplayer;
    bool hasPrivilege = false;
    XalPrivilegeCheckDenyReasons reasons = { };
    HRESULT hr = XalUserCheckPrivilege(GlobalState()->xalUser, privilege, &hasPrivilege, &reasons);
```
