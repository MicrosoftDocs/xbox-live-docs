---
title: Invites overview
description: A player can invite other players to their game sessions. Invited players receive a game invite, and the title uses this information to join the existing session and multiplayer experience.
kindex: Invites overview
author: mikehoffms
ms.author: v-mihof
ms.topic: overview
ms.prod: gaming
ms.technology: xboxlive
edited: 00/00/0000
---

# Invites overview

<!-- goal of article:
o  Describe invites in general.
o  Describe the invite context/string.
o  Describe behavior on the platform vs. in-game invites.
 -->

<!-- these paragraphs were copied from  live-multiplayer-concepts.md#invites -->
Xbox Live provides an invite system that is supported by the Multiplayer service.
The Multiplayer service enables players to invite other players to their game sessions.
Invited players receive a game invite, and a title uses this information to join an existing session and multiplayer experience.

The title controls the invite flow and when invites can be sent. Invites can be sent through the shell by the user, or can be sent directly from the title.

The notification text for an invite can be dynamically set by a title to provide more information to the invited player.
Invites can also include additional data for the title that is not visible to the player and can be used to carry additional information.

<!-- 
keep and modify, or delete?
## Invites glossary

| Term | Definition |
| --- | --- |
| activation context | TBD |
| context string ID | TBD |
| invite context | TBD |
| invite string ID | TBD |
| Broadcast | TBD |
| sandboxed | TBD |
-->


## See also

* The [Invites](../concepts/live-multiplayer-concepts.md#invites) section in the article "Multiplayer concepts overview"
* [Flows for multiplayer game invites](concepts/live-multiplayer-invite-flows.md)
* [Sending invites to another player (flowchart)](../mpm/concepts/flowcharts/live-mpm-send-invites.md)
* [Sending game invites using Multiplayer Manager](../mpm/how-to/live-send-game-invites.md)
<!-- destination not in this repo * [Game Invite API](game_invite_c_members.md)
* [XGameInvite](xgameinvite_members.md) -->
