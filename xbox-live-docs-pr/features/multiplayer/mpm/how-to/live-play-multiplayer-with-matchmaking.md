---
title: Finding a multiplayer game by using SmartMatch using Multiplayer Manager
description: Using Multiplayer Manager to enable a player to find a multiplayer game by using SmartMatch matchmaking.
kindex: Finding a multiplayer game by using SmartMatch using Multiplayer Manager
kindex: multiplayer manager
kindex: flowchart, SmartMatch
kindex: SmartMatch
ms.topic: how-to
ms.prod: gaming
ms.technology: xboxlive
ms.assetid: f9001364-214f-4ba0-a0a6-0f3be0b2f523
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Finding a multiplayer game by using SmartMatch using Multiplayer Manager

Sometimes, a gamer may not have enough friends online when they want to play a game, or they just want to play against random people online.
You can use the Xbox Live SmartMatch service to find other Xbox Live players.

This article covers the basic steps you need to implement SmartMatch matchmaking by using Multiplayer Manager.


## Find a match

There are four steps involved when using the Multiplayer Manager to send an invite to a user's friend, and then for that friend to join the game in progress:

1. [Initialize Multiplayer Manager](#initialize-multiplayer-manager)
2. [Create the lobby session by adding local users](#create-lobby)
3. [Send invites to friends](#send-invites)
4. [Accept invites](#accept-invites)
5. [Find a match](#find-match)

Steps 1, 2, 3, and 5 are done on the device performing the invite.
Step 4 would typically be initiated on the invitee's machine following app launch via protocol activation.

See [Playing a game by using SmartMatch matchmaking (flowchart)](../concepts/flowcharts/live-mpm-play-with-smartmatch-matchmaking.md).

<a id="initialize-multiplayer-manager"></a>

### 1) Initialize Multiplayer Manager

| Call | Event triggered |
|-----|----------------|
| `multiplayer_manager::initialize(lobbySessionTemplateName)` | N/A |

The lobby session object is automatically created upon initializing the Multiplayer Manager, assuming that a valid session template name (configured in the service configuration) is specified.
Note that this does not create the lobby session instance on the service.


```c
HRESULT hr = XblMultiplayerManagerInitialize(lobbySessionTemplateName, queueUsedByMultiplayerManager);
```

```cpp
auto mpInstance = multiplayer_manager::get_singleton_instance();

mpInstance->initialize(lobbySessionTemplateName);
```

<a id="create-lobby"></a>

### 2) Create the lobby session by adding local users

| Method | Event triggered |
|-----|----------------|
| `multiplayer_lobby_session::add_local_user()` | `user_added_event` |
| `multiplayer_lobby_session::set_local_member_connection_address()` | `local_member_connection_address_write_completed ` |
| `multiplayer_lobby_session::set_local_member_properties()` | `member_property_changed` |

Here, you add the locally signed in Xbox Live users to the lobby session.
This hosts a new lobby when the first user is added.
For all other users, they will be added to the existing lobby as secondary users.

This API will also advertise the lobby in the shell for friends to join.
You can send invites, set lobby properties, access lobby members via `lobby()` only once you've added the local user.

After joining the lobby, Microsoft recommends setting the local member's connection address, as well as any custom properties for the member.

You must repeat this process for all locally signed-in users.


### Adding a single local user

<!-- DocsMultiplayerManagerAddLocalUser_Single_C.md -->
```c
HRESULT hr = XblMultiplayerManagerLobbySessionAddLocalUser(xblUserHandle);

if (!SUCCEEDED(hr))
{
    // Handle failure
}

// Set member connection address
const char* connectionAddress = "1.1.1.1";
hr = XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress(
    xblUserHandle, connectionAddress, context);

if (!SUCCEEDED(hr))
{
    // Handle failure
}

// Set custom member properties
const char* propName = "Name";
const char* propValueJson = "{}";
hr = XblMultiplayerManagerLobbySessionSetProperties(propName, propValueJson, context);

if (!SUCCEEDED(hr))
{
    // Handle failure
}
...
```

<!-- **Reference**
* [XblMultiplayerManagerLobbySessionAddLocalUser](xblmultiplayermanagerlobbysessionaddlocaluser.md)
* [XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress](xblmultiplayermanagerlobbysessionsetlocalmemberconnectionaddress.md)
* [XblMultiplayerManagerLobbySessionSetProperties](xblmultiplayermanagerlobbysessionsetproperties.md) -->

```cpp
auto mpInstance = multiplayer_manager::get_singleton_instance();

auto result = mpInstance->lobby_session()->add_local_user(xboxLiveContext->user());
if (result.err())
{
  // handle error
}

// Set member connection address
string_t connectionAddress = L"1.1.1.1";
mpInstance->lobby_session()->set_local_member_connection_address(
    xboxLiveContext->user(), connectionAddress);

// Set custom member properties
mpInstance->lobby_session()->set_local_member_properties(xboxLivecontext->user(), ..., ...)
```

### Adding multiple local users


<!-- DocsMultiplayerManagerAddLocalUser_Multiple_C.md -->
```c
std::vector<XblUserHandle> xblUsers;
for (XblUserHandle xblUserHandle : xblUsers)
{
    HRESULT hr = XblMultiplayerManagerLobbySessionAddLocalUser(xblUserHandle);

    if (!SUCCEEDED(hr))
    {
        // Handle failure
    }

    // Set member connection address
    const char* connectionAddress = "1.1.1.1";
    hr = XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress(
        xblUserHandle, connectionAddress, context);

    if (!SUCCEEDED(hr))
    {
        // Handle failure
    }

    // Set custom member properties
    const char* propName = "Name";
    const char* propValueJson = "{}";
    hr = XblMultiplayerManagerLobbySessionSetProperties(propName, propValueJson, context);
    ...
}
```

<!-- **Reference**
* [XblMultiplayerManagerLobbySessionAddLocalUser](xblmultiplayermanagerlobbysessionaddlocaluser.md)
* [XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress](xblmultiplayermanagerlobbysessionsetlocalmemberconnectionaddress.md)
* [XblMultiplayerManagerLobbySessionSetProperties](xblmultiplayermanagerlobbysessionsetproperties.md) -->
<!-- * [XblUserHandle](xbluserhandle.md) -->

```cpp
auto mpInstance = multiplayer_manager::get_singleton_instance();
string_t connectionAddress = L"1.1.1.1";

for (User^ user : User::Users)
{
  if( user->IsSignedIn )
  {
    auto result = mpInstance.lobby_session()->add_local_user(user);
    if (result.err())
    {
      // handle error
    }

    // Set member connection address
    mpInstance->lobby_session()->set_local_member_connection_address(
        xboxLiveContext->user(), connectionAddress);

    // Set custom member properties
    mpInstance->lobby_session()->set_local_member_properties(xboxLivecontext->user(), ..., ...)
  }
}
```

The changes are batched on the next `do_work()` call.
Multiplayer manager fires a `user_added` event each time a user is added to the lobby session.

It is recommended that you inspect the error code of the event to see if that user was successfully added.
In case of a failure, an error message will be provided detailing the reasons of the failure.

**Functions performed by Multiplayer Manager to create the lobby session by adding local users**

* Register Real Time Activity & Multiplayer Subscriptions with the Xbox Live multiplayer service
* Create Lobby Session
* Join all local players as active
* Upload SDA
* Set member properties
* Register for Session Change Events
* Set Lobby Session as Active Session

<a id="send-invites"></a>

### 3) Send invites to friends (optional)

| Method | Event triggered |
| -----|----------------|
| `multiplayer_lobby_session::invite_friends()` | `invite_sent` |
| `multiplayer_lobby_session::invite_users()` | `invite_sent` |

Next, you'll want to bring up the standard Xbox UI for inviting friends.
This displays a UI that allows the player to select friends  or recent players to invite to the game.
Once the player hits confirm, Multiplayer Manager sends the invites to the selected players.

Games can also use the `invite_users()` method to send invites to a set of people defined by their Xbox Live User IDs.
This is useful if you prefer to use your own in-game UI instead of the stock Xbox UI.


<!-- XblMultiplayerManagerLobbySessionInviteUsers_C.md -->
```c
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


```cpp
auto result = mpInstance->lobby_session()->invite_friends(xboxLiveContext);
if (result.err())
{
  // handle error
}
```

**Functions performed by Multiplayer Manager to send invites to friends**

* Brings up the Xbox stock title callable UI (TCUI)
* Sends invite directly to the selected players

<a id="accept-invites"></a>

### 4) Accept invites (optional) 

| Method | Event triggered |
| -----|----------------|
| `multiplayer_manager::join_lobby(Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs^ args)` | `join_lobby_completed_event` |
| `multiplayer_lobby_session::set_local_member_connection_address()` | `local_member_connection_address_write_completed ` |
| `multiplayer_lobby_session::set_local_member_properties()` | `member_property_changed` |

When an invited player accepts a game invite or joined a friends game via a shell UI, the game is launched on their device by using protocol activation.
Once the game starts, Multiplayer Manager can use the protocol activated event arguments to join the lobby.

Optionally, if you haven't added the local users through `lobby_session()::add_local_user()`, you can pass in the list of users via the `join_lobby()` API.

If the invited user is not added either via `lobby_session()::add_local_user()` or through `join_lobby()`, then `join_lobby()` will fail and provide the `invited_xbox_user_id()` that the invite was sent for as part of the `join_lobby_completed_event_args()`.

After joining the lobby, we recommend setting the local member's connection address, as well as any custom properties for the member.
You can also set the host via `set_synchronized_host` if one doesn't exist.

Finally, the Multiplayer Manager will auto join the user into the game session if a game is already in progress and has room for the invitee.
The title will be notified through the `join_game_completed` event providing an appropriate error code and message.


<!-- DocsMultiplayerManagerJoinLobby_C.md -->
```c
HRESULT hr = XblMultiplayerManagerJoinLobby(inviteHandleId, xblUserHandle);
if (!SUCCEEDED(hr))
{
    // Handle failure
}

// Set member connection address
const char* connectionAddress = "1.1.1.1";
hr = XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress(
    xblUserHandle, connectionAddress, context);
```

<!-- **Reference**
* [XblMultiplayerManagerJoinLobby](xblmultiplayermanagerjoinlobby.md)
* [XblMultiplayerManagerLobbySessionSetLocalMemberConnectionAddress](xblmultiplayermanagerlobbysessionsetlocalmemberconnectionaddress.md) -->


```cpp
auto result = mpInstance().join_lobby(IProtocolActivatedEventArgs^ args);
if (result.err())
{
  // handle error
}

string_t connectionAddress = L"1.1.1.1";
mpInstance->lobby_session()->set_local_member_connection_address(
    xboxLiveContext->user(), connectionAddress);

```

Error/success is handled via the `join_lobby_completed` event.

**Functions performed by Multiplayer Manager to accept invites**
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

<a id="find-match"></a>

### 5) Find match

| Call | Event triggered |
|-----|----------------|
| `multiplayer_manager::find_match()` | Many events, as described in ```match_status``` (eg: ```searching```, ```found```, ```measuring```). |

After invites (if any) have been accepted, and the host is ready to start playing the game, you can use SmartMatch to either:
* Find an existing game that has enough open player slots for all of the members in the lobby session by calling `find_match()`.
* Create a new game session that includes all of the members from the lobby session and fill up open spots with other people looking for a match of the same game type, by calling `join_game_from_lobby()` followed with `set_auto_fill_members_during_matchmaking()`.

Before you can call `find_match()`, you must first configure hoppers in your service configuration.
A hopper defines the rules that SmartMatch uses to match players.


<!-- XblMultiplayerManagerFindMatch_C.md -->
```c
uint32_t timeoutInSeconds = 30;
HRESULT hr = XblMultiplayerManagerFindMatch(hopperName, attributesJson, timeoutInSeconds);
if (!SUCCEEDED(hr))
{
    // Handle failure
}
```

<!-- **Reference**
* [XblMultiplayerManagerFindMatch](xblmultiplayermanagerfindmatch.md) -->

```cpp
auto result = mpInstance.find_match(HOPPER_NAME);
if (result.err())
{
  // handle error
}
```


**Functions performed by Multiplayer Manager to find a match**
* Create a match ticket
* Handle all of the QoS stages
* Handle roster changes
* Resubmit (if needed)
* Joins target Game session
* Advertise Game via Lobby Session


## See also

* [Xbox Live samples](../../../general/samples/live-samples.md)
