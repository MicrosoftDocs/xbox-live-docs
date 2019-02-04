// <DoWork_snippet>
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
            LogRun("XblSocialManagerDoWork: UsersAddedToSocialGraph event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_UserAddedToSocialGraphEvent", S_OK); // CODE SNIP SKIP
            break;
        case XblSocialManagerEventType_UsersRemovedFromSocialGraph:
            // TODO: Handle UsersRemovedFromSocialGraph Event
            LogRun("XblSocialManagerDoWork: UsersRemovedFromSocialGraph event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_UsersRemovedFromSocialGraphEvent", S_OK); // CODE SNIP SKIP
            break;
        case XblSocialManagerEventType_PresenceChanged:
            // TODO: Handle PresenceChanged Event
            LogRun("XblSocialManagerDoWork: PresenceChanged event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_PresenceChangedEvent", S_OK); // CODE SNIP SKIP
            break;
        case XblSocialManagerEventType_ProfilesChanged:
            // TODO: Handle ProfilesChanged Event
            LogRun("XblSocialManagerDoWork: ProfilesChanged event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_ProfilesChangedEvent", S_OK); // CODE SNIP SKIP
            break;
        case XblSocialManagerEventType_SocialRelationshipsChanged:
            // TODO: Handle SocialRelationshipsChanged Event
            LogRun("XblSocialManagerDoWork: SocialRelationshipsChanged event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_SocialRelationshipsChangedEvent", S_OK); // CODE SNIP SKIP
            break;
        case XblSocialManagerEventType_LocalUserAdded:
            // TODO: Handle LocalUserAdded Event
            LogRun("XblSocialManagerDoWork: LocalUserAdded event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_LocalUserAddedEvent", S_OK); // CODE SNIP SKIP
            break;
        case XblSocialManagerEventType_LocalUserRemoved:
            // TODO: Handle LocalUserRemoved Event
            LogRun("XblSocialManagerDoWork: LocalUserRemoved event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_LocalUserRemovedEvent", S_OK); // CODE SNIP SKIP
            break;
        case XblSocialManagerEventType_SocialUserGroupLoaded:
            // TODO: Handle SocialUserGroupLoaded Event
            LogRun("XblSocialManagerDoWork: SocialUserGroupLoaded event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_SocialUserGroupLoadedEvent", S_OK); // CODE SNIP SKIP
            break;
        case XblSocialManagerEventType_SocialUserGroupUpdated:
            // TODO: Handle SocialUserGroupUpdated Event
            LogRun("XblSocialManagerDoWork: SocialUserGroupUpdated event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_SocialUserGroupUpdatedEvent", S_OK); // CODE SNIP SKIP
            break;
        default:
            // TODO: Handle Unknown Event
            LogRun("XblSocialManagerDoWork: Unknown event\n"); // CODE SNIP SKIP
            DoCommandsInEvent("OnXblSocialManagerDoWork_UnknownEvent", S_OK); // CODE SNIP SKIP
            break;
        }
    }
// </DoWork_snippet>

CallOtherMethod();