```cpp
size_t eventCount{ 0 };
const XblMultiplayerEvent* events{ nullptr };
HRESULT hr = XblMultiplayerManagerDoWork(&events, &eventCount);
if (FAILED(hr))
{
    // Handle failure
}

for (auto i = 0u; i < eventCount; ++i)
{
    switch (events[i].EventType)
    {
        case XblMultiplayerEventType::MemberJoined:
        {
            // Handle MemberJoined
            size_t memberCount = 0;
            hr = XblMultiplayerEventArgsMembersCount(events[i].EventArgsHandle, &memberCount);
            assert(SUCCEEDED(hr));

            std::vector<XblMultiplayerManagerMember> members(memberCount);
            hr = XblMultiplayerEventArgsMembers(events[i].EventArgsHandle, memberCount, members.data());
            assert(SUCCEEDED(hr));
            ...

            for (auto& member : members)
            {
                LogToScreen("    member %ull", member.Xuid);
            }
            break;
        }
        case XblMultiplayerEventType::SessionPropertyChanged:
        {
            // Handle SessionPropertyChanged
            const char* changedProperty{ nullptr };
            hr = XblMultiplayerEventArgsPropertiesJson(events[i].EventArgsHandle, &changedProperty);
            assert(SUCCEEDED(hr));
            ...

            break;
        }
        ...
    }
}
```
