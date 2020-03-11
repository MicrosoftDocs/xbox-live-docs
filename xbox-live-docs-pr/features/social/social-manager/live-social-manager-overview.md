---
title: Social Manager overview
description: The Xbox Live Social Manager API simplifies keeping track of online friends and their gaming activity.
ms.assetid: d4c6d5aa-e18c-4d59-91f8-63077116eda3
ms.date: 03/26/2018
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one
ms.localizationpriority: medium
---






# Social Manager overview

The Xbox Live Social Manager API simplifies keeping track of online friends and their gaming activity.

Xbox Live provides a rich social graph that titles can use for various scenarios.
Using the social APIs in the Xbox Live Services API (XSAPI) to obtain and maintain information about a social graph is complex, and keeping this information up to date can be complicated.
Not doing this correctly can result in performance issues, stale data, or being throttled due to calling the Xbox Live social services more frequently than necessary.

The Social Manager solves this problem by:

* Creating a simple API to call.
* Creating up to date information using the real time activity service behind the scenes.
* Developers can call the Social Manager API synchronously without any extra strain on the service.

The Social Manager masks the complexity of dealing with multiple RTA subscriptions, and refreshing data for users and allows developers to easily get the up to date graph they want to create interesting scenarios.

See [Social Manager memory and performance](concepts/live-socmgr-mem-perf.md).


## Features

The Social Manager provides the following features:

* Simplified Social API
* Up-to-date social graph
* Control over the verbosity of information displayed
* Reduce number of calls to Xbox Live services
  * This directly correlates to overall latency reduction in data acquisition
* Thread safe
* Efficiently keeping data up to date


## Core Concepts


**Social Graph**: A *social graph* is created for a local user on the device.
This creates a structure that keeps information about all of a users friends up to date.

> [!NOTE]
> On Windows there can only be one local user


**Xbox Social User**: An *Xbox social user* is a full set of social data associated with a user from a group


**Xbox Social User Group**: A group is a collection of users that is used for things like populating UI.
There are two types of groups:

* **Filter Groups**: A filter group takes a local (calling) user's *social graph* and returns a consistently fresh set of users based on specified filter parameters

* **User Groups**: A user group takes a list of users and returns a consistently fresh view of those users. These users can be outside of a user's friends list.

C API: To keep a *social user group* up to date, the function `XblSocialManagerDoWork()` must be called every frame.

C++ API: To keep a *social user group* up to date, the function `social_manager::do_work()` must be called every frame.


## API Overview

You will most frequently use the following key APIs.


### Adding local users to Social Manager

* C API function: `XblSocialManagerAddLocalUser(...)`
* C++ API class: social_manager
* WinRT(C#) API class: <a href="https://docs.microsoft.com/dotnet/api/microsoft.xbox.services.social.manager.socialmanager?view=xboxlive-dotnet-2017.11.20171204.01" target="_blank">SocialManager &#11008;</a>

Adding a local user to Social Manager causes a *social graph* to be created for the user.
After a local user is added, *social user groups* can be created for that user.

For C++ and WinRT C#, this is a singleton class that can be used to get **Xbox social user groups** which are the views described above.

The Social Manager will keep xbox social user groups up to date, and can filter user groups by presence or relationship to the user.
For example, an xbox social user group containing all of the user's friends who are online and playing the current title could be created.
This would be kept up to date as friends start or stop playing the title.


### Xbox social user group

* C API function: `XblSocialManagerUserGroupHandle`
* C++ API class: xbox_social_user_group
* WinRT(C#) API class: <a href="https://docs.microsoft.com/dotnet/api/microsoft.xbox.services.social.manager.xboxsocialusergroup?view=xboxlive-dotnet-2017.11.20171204.01" target="_blank">XboxSocialUserGroup &#11008;</a>

A group of users that meet certain criteria, as described above.
Xbox social user groups expose what type of a group they are, which users are being tracked or what the filter set is on them, and the local user which the group belongs to.

You can find a complete description of the Social Manager APIs in the [Xbox Live API reference](https://aka.ms/xboxliveuwpdocs).
You can also find the WinRT APIs in the [Microsoft.Xbox.Services.Social.Manager.Namespace documentation](https://docs.microsoft.com/dotnet/api/microsoft.xbox.services.social.manager?view=xboxlive-dotnet-2017.11.20171204.01)


## Usage


### Creating a social user group from filters

In this scenario, you want a list of users from a filter, such as all the people this user is following or has tagged as favorite.


**C API**
```cpp
HRESULT hr = XblSocialManagerAddLocalUser(user, extraLevelDetail, nullptr);

XblPresenceFilter presenceFilter{ XblPresenceFilter::All };
XblRelationshipFilter relationshipFilter{ XblRelationshipFilter::Friends };

XblSocialManagerUserGroupHandle groupHandle{ nullptr };
HRESULT hr = XblSocialManagerCreateSocialUserGroupFromFilters(user, presenceFilter, relationshipFilter, &groupHandle);

if (SUCCEEDED(hr))
{
    state.groups.insert(groupHandle);
}

// some update loop in the game
while (true)
{
    const XblSocialManagerEvent* events{ nullptr };
    size_t eventCount{ 0 };
    HRESULT hr = XblSocialManagerDoWork(&events, &eventCount);
    if (SUCCEEDED(hr))
    {
        for (size_t i = 0; i < eventCount; i++)
        {
            // Act on the event
        }
    }
}
```

<!-- **Reference**
* [XblPresenceFilter](xblpresencefilter.md)
* [XblRelationshipFilter](xblrelationshipfilter.md)
* [XblSocialManagerAddLocalUser](xblsocialmanageraddlocaluser.md)
* [XblSocialManagerCreateSocialUserGroupFromFilters](xblsocialmanagercreatesocialusergroupfromfilters.md)
* [XblSocialManagerDoWork](xblsocialmanagerdowork.md)
* [XblSocialManagerEvent](xblsocialmanagerevent.md)-->
<!-- * [XblSocialManagerUserGroupHandle](xblsocialmanagerusergrouphandle.md) -->


**C++ API**
```cpp
//#include "Social.h"

auto socialManager = social_manager::get_singleton_instance();

socialManger->add_local_user(
    xboxLiveContext->user(),
    social_manager_extra_detail_level::preferred_color_level | social_manager_extra_detail_level::title_history_level
    );

auto socialUserGroup = socialManager->create_social_user_group_from_filters(
    xboxLiveContext->user(),
    presence_filter::all,
    relationship_filter::friends
    );

while(true)
{
    // some update loop in the game
    socialManager->do_work();
    // TODO: render the friends list using game UI, passing in socialUserGroup->users()
}
```


**C# WinRT API**
```csharp
// using Microsoft.Xbox.Services;
// using Microsoft.Xbox.Services.System;
// using Microsoft.Xbox.Services.Social.Manager;

socialManager = SocialManager.SingletonInstance;

socialManager.AddLocalUser(
     xboxLiveContext.User,
     SocialManagerExtraDetailLevel.PreferredColorLevel | SocialManagerExtraDetailLevel.TitleHistoryLevel
     );

socialUserGroup = socialManager.CreateSocialUserGroupFromFilters(
     xboxLiveContext.User,
     PresenceFilter.All,
     RelationshipFilter.Friends
     );

while(true)
{
     // some update loop in the game
     socialManager.DoWork();
     // // TODO: render the friends list using game UI, passing in socialUserGroup.Users
}

```


#### Events returned

**Local User Added**: Triggers when loading of users social graph is complete. Will indicate if any errors occurred during initialization.
* C API: `XblSocialManagerEventType::LocalUserAdded`
* C++ API: `local_user_added`
* C# API: `LocalUserAdded`

**Social User Group Loaded**: Triggers when social user group has been created.
* C API: `XblSocialManagerEventType::SocialUserGroupLoaded`
* C++ API: `social_user_group_loaded`
* C# API: `SocialUserGroupLoaded`

**Users Added to Social Graph**: Triggers when users are loaded in.
* C API: `XblSocialManagerEventType::UsersAddedToSocialGraph`
* C++ API: `users_added_to_social_graph`
* C# API: `UsersAddedToSocialGraph`

<!-- **Reference**:
* [XblSocialManagerEventType](xblsocialmanagereventtype.md) (C API) -->


#### Additional details


**C API**
The above example shows how to initialize the Social Manager for a user, create a social user group for that user, and keep it up to date.

The filtering options can be seen in the `XblPresenceFilter` and `XblRelationshipFilter` enums.

In the game loop, the `XblSocialManagerDoWork` function updates all created views with the latest snapshot of the users in that group.

The users in the view can be obtained by calling the `XblSocialManagerUserGroupGetUsers(...)` function which returns an `XblSocialManagerUserPtrArray`, an array of `XblSocialManagerUser` objects owned by XSAPI.
The `XblSocialManagerUser` contains the social information such as gamertag, gamerpic uri, etc.


**C++ API**
The above example shows how to initialize the Social Manager for a user, create a social user group for that user, and keep it up to date.

The filtering options can be seen in the `presence_filter` and `relationship_filter` enums.

In the game loop, the `do_work` function updates all created views with the latest snapshot of the users in that group.

The users in the view can be obtained by calling the `xbox_social_user_group::get_users()` function which returns a list of `xbox_social_user` objects.
The `xbox_social_user` contains the social information such as gamertag, gamerpic uri, etc.


### Create and update a social user group from list

In this scenario, you want the social information of a list of users such as users in a multiplayer session.


**C API**
```cpp
HRESULT hr = XblSocialManagerAddLocalUser(user, extraLevelDetail, nullptr);

// List of xuids to track
std::vector<uint64_t> xuids
{
    listXuids.begin() + static_cast<int>(offset),
    listXuids.begin() + static_cast<int>(offset + count) 
}; 

XblSocialManagerUserGroupHandle groupHandle{ nullptr };
HRESULT hr = XblSocialManagerCreateSocialUserGroupFromList(user, xuids.data(), xuids.size(), &groupHandle);

if (SUCCEEDED(hr))
{
    state.groups.insert(groupHandle);
}

// some update loop in the game
while (true)
{
    const XblSocialManagerEvent* events{ nullptr };
    size_t eventCount{ 0 };
    HRESULT hr = XblSocialManagerDoWork(&events, &eventCount);
    if (SUCCEEDED(hr))
    {
        for (size_t i = 0; i < eventCount; i++)
        {
            // Act on the event
        }
    }
}
```

<!-- **Reference**
* [XblSocialManagerAddLocalUser](xblsocialmanageraddlocaluser.md)
* [XblSocialManagerCreateSocialUserGroupFromList](xblsocialmanagercreatesocialusergroupfromlist.md)
* [XblSocialManagerDoWork](xblsocialmanagerdowork.md)
* [XblSocialManagerEvent](xblsocialmanagerevent.md)-->
 <!-- * [XblSocialManagerUserGroupHandle](xblsocialmanagerusergrouphandle.md) -->


**C++ API**
```cpp
//#include "Social.h"

auto socialManager = social_manager::get_singleton_instance();

socialManger->add_local_user(
    xboxLiveContext->user(),
    social_manager_extra_detail_level::preferred_color_level | social_manager_extra_detail_level::title_history_level
    );

auto socialUserGroup = socialManager->create_social_user_group_from_list(
    xboxLiveContext->user(),
    userList  // this is a std::vector<string_t> (list of xuids)
    );

while(true)
{
    // some update loop in the game
    socialManager->do_work();
    // TODO: render the friends list using game UI, passing in socialUserGroup->users()
}
```


**C# WinRT API**
```csharp
// using Microsoft.Xbox.Services;
// using Microsoft.Xbox.Services.System;
// using Microsoft.Xbox.Services.Social.Manager;

socialManager = SocialManager.SingletonInstance;

socialManager.AddLocalUser(
     xboxLiveContext.User,
     SocialManagerExtraDetailLevel.PreferredColorLevel | SocialManagerExtraDetailLevel.TitleHistoryLevel
     );

socialUserGroup = socialManager.CreateSocialUserGroupFromList(
     xboxLiveContext.User,
     userList //this is a IReadOnlyList<string> (list of xbox user ids a.k.a. xuids)
    );

while(true)
{
     // some update loop in the game
     socialManager.DoWork();
     // // TODO: render the friends list using game UI, passing in socialUserGroup.Users
}
```


#### Events returned

`local_user_added`(C++) | `LocalUserAdded`(C#) - Triggers when loading of users social graph is complete. Will indicate if any errors occurred during initialization.

`social_user_group_loaded`(C++) | `SocialUserGroupLoaded`(C#)- Triggers when social user group has been created.

`users_added_to_social_graph`(C++) | `UsersAddedToSocialGraph`(C#)- Triggers when users are loaded in.


### Updating Social User Group From List

You can also change the list of tracked users in the social user group by calling `update_social_user_group()`.


**C API**
```cpp
// New list of xuids to track
std::vector<uint64_t> xuids
{ 
    listXuids.begin() + static_cast<int>(offset),
    listXuids.begin() + static_cast<int>(offset + count)
};

HRESULT hr = XblSocialManagerUpdateSocialUserGroup(group, xuids.data(), xuids.size());

// some update loop in the game
while (true)
{
    const XblSocialManagerEvent* events{ nullptr };
    size_t eventCount{ 0 };
    HRESULT hr = XblSocialManagerDoWork(&events, &eventCount);
    if (SUCCEEDED(hr))
    {
        for (size_t i = 0; i < eventCount; i++)
        {
            // Act on the event
        }
    }
}
```

<!-- **Reference**
* [XblSocialManagerDoWork](xblsocialmanagerdowork.md)
* [XblSocialManagerEvent](xblsocialmanagerevent.md)
* [XblSocialManagerUpdateSocialUserGroup](xblsocialmanagerupdatesocialusergroup.md)-->


**C++ API**
```cpp
//#include "Social.h"

socialManager->update_social_user_group(
    xboxSocialUserGroup,
    newUserList    // std::vector<string_t> (list of xuids)
    );

    while(true)
    {
    // some update loop in the game
    socialManager->do_work();
    // TODO: render the friends list using game UI, passing in socialUserGroup->users()
    }
```


**C# WinRT API**
```csharp
// using Microsoft.Xbox.Services.Social.Manager;

socialManager.UpdateSocialUserGroup(
     xboxSocialUserGroup,
     newUserList //IReadOnlyList<string> (list of xbox user ids a.k.a. xuids)
     );

while(true)
{
     // some update loop in the game
     socialManager.DoWork();
     // // TODO: render the friends list using game UI, passing in socialUserGroup.Users
}
```


#### Events returned

**Social User Group Updated** - Triggers when social user group updating is complete.
* C++: `social_user_group_updated`
* C#: `SocialUserGroupUpdated`

**Users Added to Social Graph** - Triggers when users are loaded in. If users added via list are already in graph, this event will not trigger.
* C++: `users_added_to_social_graph`
* C#: `UsersAddedToSocialGraph`

**Users Removed from Social Graph** - Triggers when the previous users are removed from the social graph.
* C#: `XblSocialManagerEventType::UsersRemovedFromSocialGraph`


### Using Social Manager events

Social Manager tells you what happened, in the form of events.
You can use those events to update your UI or perform other logic.


**C API**
```cpp
// some update loop in the game
while (true)
{
    const XblSocialManagerEvent* events{ nullptr };
    size_t eventCount{ 0 };
    HRESULT hr = XblSocialManagerDoWork(&events, &eventCount);
    if (SUCCEEDED(hr))
    {
        for (size_t i = 0; i < eventCount; i++)
        {
            // Act on the event
            auto& socialEvent = events[i];
            std::stringstream ss;
            ss << "XblSocialManagerDoWork: Event of type " << eventTypesMap[socialEvent.eventType] << std::endl;
            for (uint32_t i = 0; i < XBL_SOCIAL_MANAGER_MAX_AFFECTED_USERS_PER_EVENT; i++)
            {
                if (socialEvent.usersAffected[i] != nullptr)
                {
                    if (i == 0)
                    {
                        ss << "Users affected: " << std::endl;
                    }
                    ss << "\t" << socialEvent.usersAffected[i]->gamertag << std::endl;
                }
            }
            LogToFile(ss.str().c_str());
        }
    }
}
```

<!-- **Reference**
* [XblSocialManagerDoWork](xblsocialmanagerdowork.md)
* [XblSocialManagerEvent](xblsocialmanagerevent.md)-->


**C++ API**
```cpp
//#include "Social.h"

auto socialManager = social_manager::get_singleton_instance();
socialManger->add_local_user(
    xboxLiveContext->user(),
    social_manager_extra_detail_level::no_extra_detail
    );

auto socialUserGroup = socialManager->create_social_user_group_from_filters(
    xboxLiveContext->user(),
    presence_filter::all,
    relationship_filter::friends
    );

socialManager->do_work();
// TODO: initialize the game UI containing the friends list using game UI, socialUserGroup->users()

while(true)
{
    // some update loop in the game
    auto events = socialManager->do_work();
    for(auto evt : events)
    {
        auto affectedUsersFromGraph = socialUserGroup->get_users_from_xbox_user_ids(evt.users_affected());
        // TODO: render the changes to the friends list using game UI, passing in affectedUsersFromGraph
    }
}
```


**C# WinRT API**
```csharp
// using Microsoft.Xbox.Services;
// using Microsoft.Xbox.Services.System;
// using Microsoft.Xbox.Services.Social.Manager;

socialManager = SocialManager.SingletonInstance;

socialManager.AddLocalUser(
     xboxLiveContext.User,
     SocialManagerExtraDetailLevel.PreferredColorLevel | SocialManagerExtraDetailLevel.TitleHistoryLevel
     );

socialUserGroup = socialManager.CreateSocialUserGroupFromFilters(
     xboxLiveContext.User,
     PresenceFilter.All,
     RelationshipFilter.Friends
     );

socialManager.DoWork();
// TODO: initialize the game UI containing the friends list using game UI, socialUserGroup->users()

while(true)
{
    // some update loop in the game
    IReadOnlyList<SocialEvent> Events = socialManager.DoWork();
    IReadOnlyList<XboxSocialUser> affectedUsersFromGraph;
    foreach(SocialEvent managerEvent in Events)
    {
        affectedUsersFromGraph = socialUserGroup.GetUsersFromXboxUserIds(managerEvent.UsersAffected);
    }
}

```


#### Events returned

`XblSocialManagerEventType::LocalUserAdded` - Triggers when loading of users social graph is complete. Will indicate if any errors occurred during initialization.
* C++: `local_user_added`

`XblSocialManagerEventType::SocialUserGroupLoaded` - Triggers when social user group has been created.
* C++: `social_user_group_loaded`

`XblSocialManagerEventType::UsersAddedToSocialGraph` - Triggers when users are loaded in.
* C++: `users_added_to_social_graph`

`XblSocialManagerEventType::UsersRemovedFromSocialGraph` - Triggers when a user is removed from the social graph.

`XblSocialManagerEventType::PresenceChanged` - Triggers when the presence of a user in the social graph changes.

`XblSocialManagerEventType::ProfilesChanged` - Triggers when the profile of a user in the social graph changes.

`XblSocialManagerEventType::SocialRelationshipsChanged` - Triggers when the relationship between the local user and another user in the social graph changes.

`XblSocialManagerEventType::SocialUserGroupUpdated` - Triggers when social user group updating is complete.


#### Additional details

This example shows some of the additional control offered.

Rather than relying on the social user group filters to provide a fresh user list during the game loop, the social graph is initialized outside the game loop.
Then the title relies upon the `events` returned by the `socialManager->do_work()` function.

`events` is a list of `social_event`, and each `social_event` contains a change to the social graph that occurred during the last frame.
For example, `profiles_changed`, `users_added`, etc.

More information can be found in the `social_event` API documentation.


### Cleanup


#### Cleaning Up Social User Groups

Cleans up the social user group that was created.
Caller should also remove any references they have to any created social user group, as it is now invalid.


**C API**
```cpp
HRESULT hr = XblSocialManagerDestroySocialUserGroup(groupHandle);
if (SUCCEEDED(hr))
{
    state.groups.erase(groupHandle);
}
```

<!-- **Reference**
*[XblSocialManagerDestroySocialUserGroup](xblsocialmanagerdestroysocialusergroup.md)-->


**C++ API**
```cpp
//#include "Social.h"

socialManger->destroy_social_user_group(
    socialUserGroup
    );
```


**C# WinRT API**
```csharp
// using Microsoft.Xbox.Services.Social.Manager;

socialManager.DestroySocialUserGroup(
     socialUserGroup
     );
```


#### Cleaning Up Local Users

Remove local user removes the loaded users social graph, as well as any social user groups that were created using that user.

With the C API, no further events should be received for the removed user.


**C API**
```cpp
HRESULT hr = XblSocialManagerRemoveLocalUser(user);
```

<!-- **Reference**
* [XblSocialManagerRemoveLocalUser](xblsocialmanagerremovelocaluser.md)-->


**C++ API**
```cpp
//#include "Social.h"

socialManger->remove_local_user(
    xboxLiveContext->user()
    );
```


**C# WinRT API**
```csharp
// using Microsoft.Xbox.Services.Social.Manager;

socialManager.RemoveLocalUser(
     xboxLiveContext.User
     );
```


#### Events returned

`local_user_removed`(C++) | `LocalUserRemoved`(C#) - Triggers when a local user has been removed successfully.
