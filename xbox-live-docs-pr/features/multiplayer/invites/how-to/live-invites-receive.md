---
title: Receiving invites
description: Example code to receive multiplayer invites.
kindex: Receiving invites
kindex: invites
author: jeffshi
ms.author: jeffshi
ms.topic: how-to
ms.prod: gaming
ms.technology: xboxlive
ms.localizationpriority: medium
ms.date: 10/01/2019
edited: 12/18/2019
---

# Receiving invites

In order for your game to receive game invites, your game registers for the multiplayer protocol and the game invite callbacks.
Your game receives invites for the local user, and then joins that user to the multiplayer session.


## Registering for multiplayer protocol

Registering for multiplayer protocol tells the system how to launch your game when the user accepts a multiplayer game invite.
To register the multiplayer protocol, you need to add a `MultiplayerProtocol` element to your `MicrosoftGame.config` file:
<!-- destination not in this repo: To register the multiplayer protocol, you need to add a `MultiplayerProtocol` element to your [MicrosoftGame.config](MicrosoftGameConfig-toc.md) file: -->

```xml
    <MultiplayerProtocol>true</MultiplayerProtocol>
```

If you have multiple executables in the package, you can specify which executable should handle the multiplayer protocol with the `Executable` attribute:

```xml
    <MultiplayerProtocol Executable="MyExecutableForMultiplayer.exe">true</MultiplayerProtocol>
```


<!-- chm-only content here (h2) -->


<!-- chm-only content here (h2) -->


### For accepting a game invite

When the user accepts a game invite, the game would receive game invite callback with an `inviteUri` like this:

```cpp
    "ms-xbl-multiplayer://inviteHandleAccept?handle=%s&invitedXuid=%s&senderXuid=%s&context=%s"
    
    // for example:
    // "ms-xbl-multiplayer://inviteHandleAccept?handle=00000000-0000-1234-5678-1234567890ab&invitedXuid=1234567890123456&senderXuid=6543210987654321&context="
```

The URI will always start with "ms-xbl-multiplayer//", and following that:
1. `inviteHandleAccept` indicates that the callback was initiated because the user accepted a game invite.
1. `handle` is the invite handle you will use to join the multiplayer session.
1. `invitedXuid` is the ID of the Xbox Live user who is invited to the multiplayer session.
1. `senderXuid` is the ID of the Xbox Live user who sent the game invite.
1. `context` is the additional (optional) context the sender might have included.


### For joining a game session in progress

When the user attempts to join a multiplayer session, the game would receive a game invite callback with an `inviteUri`, like this:
```cpp
    "ms-xbl-multiplayer://activityHandleJoin?&handle=%s&joinerXuid=%s&joineeXuid=%s"
```
The URI will always start with "ms-xbl-multiplayer//", and following that:
1. `activityHandleJoin` indicates that the callback was initiated because the user accepted a game invite.
1. `handle` is the activity handle you will use to join the multiplayer session.
1. `joinerXuid` is the ID of the Xbox Live user who is attempting to join the multiplayer session.
1. `joineeXuid` is the ID of the Xbox Live user who is currently in the multiplayer session.


## Joining a multiplayer game session with handleId


### Using Multiplayer Manager

<!-- destination not in this repo: If you are using Multiplayer Manager, you can join the user to the multiplayer session with the [XblMultiplayerManagerJoinLobby](xblmultiplayermanagerjoinlobby.md) API by passing in the `handleId` extracted from the `inviteUrl`, as well as the `xblUserHandle` for the `invitedXuid`: -->
If you are using Multiplayer Manager, you can join the user to the multiplayer session with the `XblMultiplayerManagerJoinLobby` API by passing in the `handleId` extracted from the `inviteUrl`, as well as the `xblUserHandle` for the `invitedXuid`:

**C API**
<!-- XblMultiplayerManagerJoinLobby_C.md -->
```cpp
HRESULT hr = XblMultiplayerManagerJoinLobby(handleId, xblUserHandle);
```


### Using Multiplayer API directly

If you are using Multiplayer API directly, you can do the following steps:
<!-- destination not in this repo: 
1. Fetch the multiplayer session document using the [XblMultiplayerGetSessionByHandleAsync](xblmultiplayergetsessionbyhandleasync.md) API and pass in the `handleIdExtractedFromInviteUrl`.
1. Join the local user to the multiplayer session document using the [XblMultiplayerSessionJoin](xblmultiplayersessionjoin.md) API.
1. Write the multiplayer session document to the service to commit this change using the [XblMultiplayerWriteSessionByHandleAsync](xblmultiplayerwritesessionbyhandleasync.md) API. -->
1. Fetch the multiplayer session document using the `XblMultiplayerGetSessionByHandleAsync` API and pass in the `handleIdExtractedFromInviteUrl`.
1. Join the local user to the multiplayer session document using the `XblMultiplayerSessionJoin` API.
1. Write the multiplayer session document to the service to commit this change using the `XblMultiplayerWriteSessionByHandleAsync` API.


## See also

<!-- * chm-only api ref here -->
* To use Multiplayer Manager to handle game invites, see [Handling protocol activation to start a game, using Multiplayer Manager](../../mpm/how-to/live-handle-protocol-activation.md).
