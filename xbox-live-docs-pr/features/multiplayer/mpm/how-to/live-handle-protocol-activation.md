---
title: Handling protocol activation to start a game, using Multiplayer Manager
description: Using Multiplayer Manager to handle protocol activation, so that the game automatically starts in response to another action, such as when a player accepts a game invite from another player.
ms.assetid: e514bcb8-4302-4eeb-8c5b-176e23f3929f
ms.date: 04/04/2017
ms.topic: how-to
ms.prod: gaming
ms.technology: xboxlive
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, multiplayer manager, protocol activation
ms.localizationpriority: medium
---





# Handling protocol activation to start a game, using Multiplayer Manager

*Protocol activation* is when the system automatically starts a game in response to another action, typically when a player accepts a game invite from another player.

Your title can get protocol activated through the following ways:
* When a user accepts a game invite.
* When a user selects "Join Game" from a player's gamercard.

This scenario covers how to handle the protocol activation when your title is launched and join the lobby and game (if one exists).

You can see a flowchart of the process here: [Handling protocol activation (flowchart)](../concepts/flowcharts/live-mpm-on-protocol-activation.md).


**C++ API**
| Method | Event triggered |
| -----|----------------|
| `multiplayer_manager::join_lobby(IProtocolActivatedEventArgs^ args, User^)` | `join_lobby_completed_event` |
| `multiplayer_lobby_session::set_local_member_connection_address()` | `local_member_connection_address_write_completed ` |
| `multiplayer_lobby_session::set_local_member_properties()` | `member_property_changed` |



When a player accepts a game invite or joins a friend's game through the player's gamercard, the game is launched on their device by using protocol activation.
Once the game starts, Multiplayer Manager can use the protocol activated event arguments to join the lobby.

Optionally, if you haven't added the local users through `lobby_session()::add_local_user()`, you can pass in the list of users via the `join_lobby()` API.
If the invited user is not added, or if the invite was for another user than the user that was added, `join_lobby()` will fail and provide the `invited_xbox_user_id()` that the invite was sent for as part of the `join_lobby_completed_event_args`.

After joining the lobby, Microsoft recommends setting the local member's connection address, as well as any custom properties for the member.
You can also set the host via `set_synchronized_host` if one doesn't exist.

Finally, the Multiplayer Manager will auto join the user into the game session if a game is already in progress and has room for the invitee.
The title will be notified through the `join_game_completed` event providing an appropriate error code and message.

Error/success is handled via the `join_lobby_completed` event.


**C API**
```cpp
#include <XTaskQueue.h>
#include <XGameInvite.h>  
  
XTaskQueueHandle g_taskQueue;  
XTaskQueueRegistrationToken g_gameInviteEventToken;  
  
void OnGameInvite(void* context, const char* inviteUri)  
{  
    if (inviteUri != nullptr)
    {
        std::string inviteString(inviteUri);
        auto pos = inviteString.find("handle=");
        auto inviteHandeId = inviteString.substr(pos + 7, 36);
        // Now call XblMultiplayerManagerJoinLobby
    }
}  
  
void InitializeGame()  
{  
    XGameInviteRegisterForEvent(g_taskQueue, nullptr, OnGameInvite, &g_gameInviteEventToken);  
}  
  
void ShutdownGame()  
{  
    XGameInviteUnregisterForEvent(g_gameInviteEventToken);  
}  
```

<!-- XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress_C.md -->
```cpp
HRESULT hr = XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress(
    xblUserHandle, connectionAddress, context);
```

<!--**Reference**
* [XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress](xblmultiplayermanagerlobbysessionsetlocalmemberconnectionaddress.md)-->


**C++ API**
```cpp
auto result = mpInstance().join_lobby(IProtocolActivatedEventArgs^ args, users);
if (result.err())
{
  // handle error
}

string_t connectionAddress = L"1.1.1.1";
mpInstance->lobby_session()->set_local_member_connection_address(
    xboxLiveContext->user(),
    connectionAddress);
```


**Functions performed by Multiplayer Manager**
* Register RTA & Multiplayer Subscriptions
* Join Lobby session
* Existing Lobby state cleanup
* Join all local players as active
* Upload SDA
* Set member properties
* Register for Session Change Events
* Set Lobby Session as Active Session
* Join Game Session (if exists)
* Uses transfer handle
