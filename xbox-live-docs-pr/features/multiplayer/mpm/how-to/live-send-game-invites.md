---
title: Sending game invites using Multiplayer Manager
description: Using Multiplayer Manager to enable a player to send game invites to other players to join the game.
kindex: Sending game invites using Multiplayer Manager
kindex: multiplayer
kindex: multiplayer manager
kindex: flowchart
kindex: game invite
ms.topic: how-to
ms.assetid: 8b9a98af-fb78-431b-9a2a-876168e2fd76
ms.localizationpriority: medium
ms.date: 04/04/2017
---







# Sending game invites using Multiplayer Manager

One of the simpler multiplayer scenarios is to allow a gamer to play your game online with friends.
This scenario covers the steps you need to send invites to another player to join your game.

Once you've initialized the Multiplayer Manager, and have created a Lobby session by adding local users (see [Enable playing a multiplayer game with friends using Multiplayer Manager](live-play-multiplayer-with-friends.md)), you must wait until you receive the `XblMultiplayerEventType::UserAdded` event (C) or `user_added` event (C++)) before you can start sending invites.

There are two ways to send an invite:
1. [Xbox Platform Invite TCUI](#xbox-platform-invite-tcui)
2. [Title implemented custom UI](#title-implemented-custom-ui)

You can see a flowchart of the process here: [Sending invites to another player (flowchart)](../concepts/flowcharts/live-mpm-send-invites.md).


### 1) Xbox Platform Invite TCUI <a name="xbox-platform-invite-tcui">

| Method | Event triggered |
| -----|----------------|
| `multiplayer_lobby_session::invite_friends()` | `invite_sent` |

Calling `XblMultiplayerManagerLobbySessionInviteFriends` (C) or `invite_friends()` (C++) will bring up the standard Xbox UI for inviting friends.
This displays a UI that allows the player to select friends or recent players to invite to the game.
Once the player hits **Confirm**, Multiplayer Manager sends the invites to the selected players.

**C API:**
```cpp
std::string customActivationContext = "{ \"customGameData\": 1 }"; // This string can be anything your game wants to send across to the invited player's game.

HRESULT hr = XblMultiplayerManagerLobbySessionInviteFriends(xuserHandle, nullptr, customActivationContext.c_str());
```

**C++ API:**
```cpp
auto result = mpInstance->lobby_session()->invite_friends(xboxLiveContext);
if (result.err())
{
  // handle error
}
```

**Functions performed by Multiplayer Manager for Xbox Platform Invite TCUI**

* Brings up the Xbox stock title callable UI (TCUI)
* Sends invite directly to the selected players


### 2) Title-implemented custom UI<a name="title-implemented-custom-ui">

| Method | Event triggered |
|-----|----------------|
| `multiplayer_lobby_session::invite_users()` | `invite_sent` |

Your title can implement a custom TCUI for viewing online friends and inviting them.
Games can use the `XblMultiplayerManagerLobbySessionInviteUsers` C method or the `invite_users()` C++ method to send invites to a set of people defined by their Xbox Live User IDs.
This is useful if you prefer to use your own in-game UI instead of the stock Xbox UI.

**C API**
<!-- XblMultiplayerManagerLobbySessionInviteUsers_C.md -->
```cpp
size_t xuidsCount = 1;
uint64_t xuids[1] = {};
xuids[0] = 1234567891234567;
HRESULT hr = XblMultiplayerManagerLobbySessionInviteUsers(
    xblUserHandle, 
    xuids, 
    xuidsCount, 
    nullptr,    // ContextStringId 
    nullptr     // CustomActivationContext
);
```

<!-- **Reference**
* [XblMultiplayerManagerLobbySessionInviteUsers](xblmultiplayermanagerlobbysessioninviteusers.md) -->

**C++ API**
```cpp
std::vector<string_t>& xboxUserIds;
xboxUserIds.push_back();  // Add xbox_user_ids from your in-game roster list

auto result = mpInstance->lobby_session()->invite_users(xboxUserIds);
if (result.err())
{
  // handle error
}
```

**Functions performed by Multiplayer Manager for title-implemented custom UI**

* Sends invite directly to the selected players.
