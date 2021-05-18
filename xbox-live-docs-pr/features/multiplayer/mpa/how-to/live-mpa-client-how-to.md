---
title: Example code for Multiplayer Activity
description: Example code for setting, getting, and deleting an Activity, as well as sending Invites and adding player interactions to Recent Players.
kindex: Example code for Multiplayer Activity
ms.topic: conceptual
ms.localizationpriority: high
author: thboard
ms.author: thboard
ms.date: 05/12/2020
edited: 00/00/0000
security: public
---
# Example code for Multiplayer Activity

This document is intended as a quickstart guide for basic use of the Multiplayer
Activity Client APIs. Topics discussed are managing activities, sending invites,
and adding players to the recent players list.

## Activities

### Setting an activity

Whenever a title starts or joins a multiplayer experience, it should create an
activity. Doing this allows both the shell and other players in your title to
see the player's activity, and allows other players to potentially join the game
in progress. If a player wants to join an activity for your title and it is not
running, it will be activated and the connection string passed to it.

Titles should update the activity as players join or leave to provide a more
rich view of the activity to other players, and to inform them whether the
activity is full or not.

For more information on the meaning of the fields, see the [Activity contents](../concepts/live-mpa-activities.md#activity-contents) section in the "Activities" article.

A code example for setting an activity is below. This applies for both creating
an activity as well as updating an existing one.

<!-- XblMultiplayerActivitySetActivityAsync_C.md -->
```cpp
auto async = std::make_unique<XAsyncBlock>();
async->queue = queue;
async->callback = [](XAsyncBlock* async)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ async }; // take ownership of XAsyncBlock
    HRESULT hr = XAsyncGetStatus(async, false);
};

XblMultiplayerActivityInfo info{};
info.connectionString = "dummyConnectionString";
info.joinRestriction = XblMultiplayerActivityJoinRestriction::Followed;
info.maxPlayers = 10;
info.currentPlayers = 1;
info.groupId = "dummyGroupId";

HRESULT hr = XblMultiplayerActivitySetActivityAsync(
    xblContext,
    &info,
    false,
    async.get()
);

if (SUCCEEDED(hr))
{
    async.release();
}
```

<!-- **Reference:**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblMultiplayerActivityInfo](xblmultiplayeractivityinfo.md)
* [XblMultiplayerActivityJoinRestriction](xblmultiplayeractivityjoinrestriction.md)
* [XblMultiplayerActivitySetActivityAsync](xblmultiplayeractivitysetactivityasync.md) -->


### Getting Activities

Titles may wish to know the activities of other users. For instance, a title may
wish to display an in-game UI of a players' friends in the title alongside their
activities.

A code example for retrieving an activity is below.

<!-- XblMultiplayerActivityGetActivityAsync_C.md -->
```cpp
auto async = std::make_unique<XAsyncBlock>();
async->queue = queue;
async->callback = [](XAsyncBlock* async)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ async }; // take ownership of XAsyncBlock

    size_t resultSize{};
    HRESULT hr = XblMultiplayerActivityGetActivityResultSize(async, &resultSize);
    if (SUCCEEDED(hr))
    {
        std::vector<uint8_t> buffer(resultSize);
        XblMultiplayerActivityInfo* activityInfo{};
        size_t resultCount{};
        hr = XblMultiplayerActivityGetActivityResult(async, buffer.size(), buffer.data(), &activityInfo, &resultCount, nullptr);
        if (SUCCEEDED(hr))
        {
            // ...
        }
    }
};

HRESULT hr = XblMultiplayerActivityGetActivityAsync(
    xblContext,
    &xuid,
    1,
    async.get()
);

if (SUCCEEDED(hr))
{
    async.release();
}
```

<!-- **Reference:**
* [XAsyncBlock](xasyncblock.md)
* [XblMultiplayerActivityGetActivityResultSize](xblmultiplayeractivitygetactivityresultsize.md)
* [XblMultiplayerActivityInfo](xblmultiplayeractivityinfo.md)
* [XblMultiplayerActivityGetActivityResult](xblmultiplayeractivitygetactivityresult.md)
* [XblMultiplayerActivityGetActivityAsync](xblmultiplayeractivitygetactivityasync.md) -->

### Deleting an Activity

When a player ends or leaves a multiplayer activity, the title should delete
the activity using the code below.

<!-- XblMultiplayerActivityDeleteActivityAsync_C.md -->
```cpp
auto async = std::make_unique<XAsyncBlock>();
async->queue = queue;
async->callback = [](XAsyncBlock* async)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ async }; // take ownership of XAsyncBlock
    HRESULT hr = XAsyncGetStatus(async, false);
};

HRESULT hr = XblMultiplayerActivityDeleteActivityAsync(xblContext, async.get());

if (SUCCEEDED(hr))
{
    async.release();
}
```

<!-- **Reference:**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblMultiplayerActivityDeleteActivityAsync](xblmultiplayeractivitydeleteactivityasync.md) -->

## Invites

### Sending Invites

Players may wish to send invites directly to one or more other players. Before
sending an invite, the title should ensure an activity is set. This ensures
continuity between the shell and your title, as the shell sends invites based on
the current activity.

Once an activity is set, the title should call the Invite API, passing along an
array of users to invite, and the same connection string used in your current
activity.

For more details on an invite's contents, refer to the [Invite
concepts](../concepts/live-mpa-invites.md#invites) page

A code example for sending invites is below.

<!-- XblMultiplayerActivitySendInvitesAsync_C.md -->
```cpp
auto async = std::make_unique<XAsyncBlock>();
async->queue = queue;
async->callback = [](XAsyncBlock* async)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ async }; // take ownership of XAsyncBlock
    HRESULT hr = XAsyncGetStatus(async, false);
};

HRESULT hr = XblMultiplayerActivitySendInvitesAsync(
    xblContext,
    &xuid,
    1,
    true, // Setting false will send the invite to only users on the sender's platform
    "dummyConnectionString",
    async.get()
);

if (SUCCEEDED(hr))
{
    async.release();
}
```

<!-- **Reference:**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblMultiplayerActivitySendInvitesAsync](xblmultiplayeractivitysendinvitesasync.md) -->

### Receiving Invites
To be notified when a player has accepted an invitation, titles can register for
invite notifications with `XGameInviteRegisterForEvent`. Each time an invite is accepted, a formatted URI
will be passed to the title through the registered callback. That URI can be parsed to determine
the invite sender, receiver, and connection string. The connection string is title specific
and is set when the multiplayer activity is created. For titles using the Multiplayer Activity
service, the full format of the URI is as follows:
Platform | Format
------|--------------
GDK or XDK on console | `ms-xbl-<titleId>://inviteAccept?invitedUser=<xuid>&sender=<xuid>&connectionString=<conntectionString>`
GDK or UWP on PC | `ms-xbl-multiplayer://inviteAccept?invitedUser=<xuid>&sender=<xuid>&connectionString=<conntectionString>`
When invite notifications are no longer needed, the callback can be unregistered with `XGameInviteUnregisterForEvent`.
A code sample for registering and handling accepted invites is below.
<!-- XblMultiplayerActivitySendInvitesAsync_C.md -->
```cpp
void CALLBACK MyXGameInviteEventCallback(
    _In_opt_ void* context,
    _In_ const char* inviteUri)
{
    if (inviteUri != nullptr)
    {
        std::string uri{ inviteUri };
        size_t invitedUserBegin = uri.find("invitedUser=");
        size_t senderBegin = uri.find("sender=");
        std::string invitedUser = uri.substr(invitedUserBegin, uri.find('&', invitedUserBegin) - invitedUserBegin);
        std::string sender = uri.substr(senderBegin, uri.find('&', senderBegin) - senderBegin);
        std::string connectionString = uri.substr(uri.find("connectionString="));
        // ...
    }
}
XTaskQueueRegistrationToken token = { 0 };
HRESULT hr = XGameInviteRegisterForEvent(
    queue,
    nullptr,
    MyXGameInviteEventCallback,
    &token
    );
// ...
bool result = XGameInviteUnregisterForEvent(token, true);
```
<!-- **Reference:**
* [XGameInviteRegisterForEvent](xgameinviteregisterforevent.md)
* [XGameInviteUnregisterForEvent](xgameinviteunregisterforevent.md)-->

## Recent Players

The title should submit lists of other players that have had a meaningful
interaction with the current user, in order to update the user's recent player
list. The list is unidirectional, meaning that each player's client is
responsible for updating their own user's list, and players' lists do not affect
each others. 

As an example, if a group of users are together in a pre-game lobby and are
matched together, each player would update their list with all other xuids in
the lobby at the time the match begins. If a new user were to join, that user
could be written individually. It is also important to note that the title
developer decides what defines a meaningful interaction. For one title this
could be being present in a lobby, whereas in another it may be shooting another
player, and in a third it could be merely having another player visible
on-screen.

In scenarios where you may not want teams of players to be seen until a match
session starts, you could delay writing the list of players until the time at
which you'd like them visible to one another. To flush the client side recent
players list, you can call `XblMultiplayerActivityFlushRecentPlayersAsync` if you
require an immediate force flush. Otherwise, the recent players list will be
flushed automatically every five seconds. 

Code examples for both updating the recent players list and flushing updates are
below.

### Updating Recent Players

<!-- XblMultiplayerActivityUpdateRecentPlayers_C.md -->
```cpp
XblMultiplayerActivityRecentPlayerUpdate update{ xuid };
HRESULT hr = XblMultiplayerActivityUpdateRecentPlayers(xblContext, &update, 1);
```

<!-- **Reference:**
* [XblMultiplayerActivityRecentPlayerUpdate](xblmultiplayeractivityrecentplayerupdate.md)
* [XblMultiplayerActivityUpdateRecentPlayers](xblmultiplayeractivityupdaterecentplayers.md) -->


### Flushing Recent Players

<!-- XblMultiplayerActivityFlushRecentPlayersAsync_C.md -->
```cpp
auto async = std::make_unique<XAsyncBlock>();
async->queue = queue;
async->callback = [](XAsyncBlock* async)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ async }; // take ownership of XAsyncBlock
    HRESULT hr = XAsyncGetStatus(async, false);
};

HRESULT hr = XblMultiplayerActivityFlushRecentPlayersAsync(xblContext, async.get());
if (SUCCEEDED(hr))
{
    async.release();
}
```

<!-- **Reference:**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblMultiplayerActivityFlushRecentPlayersAsync](xblmultiplayeractivityflushrecentplayersasync.md) -->
