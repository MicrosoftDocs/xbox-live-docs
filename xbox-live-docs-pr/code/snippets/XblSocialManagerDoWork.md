```cpp
    XblSocialManagerEvent* events;
    uint32_t eventCount;
    HRESULT hr = XblSocialManagerDoWork(&events, &eventCount);

    for (uint32_t i = 0; i < eventCount; i++)
    {
        auto socialEvent = events[i];

        switch (socialEvent.eventType)
        {
        case XblSocialManagerEventType_UsersAddedToSocialGraph:
            // TODO: Handle UserAddedToSocialGraph Event
            break;
        case XblSocialManagerEventType_UsersRemovedFromSocialGraph:
            // TODO: Handle UsersRemovedFromSocialGraph Event
            break;
        case XblSocialManagerEventType_PresenceChanged:
            // TODO: Handle PresenceChanged Event
            break;
        case XblSocialManagerEventType_ProfilesChanged:
            // TODO: Handle ProfilesChanged Event
            break;
        case XblSocialManagerEventType_SocialRelationshipsChanged:
            // TODO: Handle SocialRelationshipsChanged Event
            break;
        case XblSocialManagerEventType_LocalUserAdded:
            // TODO: Handle LocalUserAdded Event
            break;
        case XblSocialManagerEventType_LocalUserRemoved:
            // TODO: Handle LocalUserRemoved Event
            break;
        case XblSocialManagerEventType_SocialUserGroupLoaded:
            // TODO: Handle SocialUserGroupLoaded Event
            break;
        case XblSocialManagerEventType_SocialUserGroupUpdated:
            // TODO: Handle SocialUserGroupUpdated Event
            break;
        default:
            // TODO: Handle Unknown Event
            break;
        }
    }
```
