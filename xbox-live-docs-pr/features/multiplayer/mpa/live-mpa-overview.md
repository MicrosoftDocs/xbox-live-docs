---
title: Multiplayer Activity feature overview
description: Simplifies platform integration for player activities (joins), invites, and recent players, and allows players to launch into your game from their social graph.
kindex: Multiplayer Activity feature overview
kindex: MPA
kindex: activity
kindex: invites
kindex: recent players
ms.topic: conceptual
ms.localizationpriority: high
security: public
author: thboard
ms.author: thboard
ms.date: 05/8/2020
edited: 00/00/0000
---

# Multiplayer Activity feature overview

The Multiplayer Activity (MPA) feature simplifies Xbox Live integration for
player activities (joins), invites, and recent players. MPA will also allow
players to launch into your game from their social graph, even if the title
itself isn't running.  

## Terminology

There are four terms that are used frequently in the context of MPA.

* **Connection String** - A string created and understood only by the title,
 which contains information required for one player to connect to another.
 Often this contains a server IP, but is left freeform to allow titles
 flexibility. This string is opaque to MPA--it simply passes it from one player
 to another to enable players to join each other.

* **Activity** - Represents an advertisement that the player is in a multiplayer
 experience. This contains a connection string as well as a small set of
 properties to restrict who may join the experience. Activities enable the
 shell to display this information including its joinability. An activity
 should always be present when a player is in a multiplayer experience.

* **Invite** - Represents a request for a player to join a multiplayer
 experience. This also contains a connection string. In general a player
 should have created an activity before sending invites to other players.

* **Recent Player** - Someone who has had a meaningful interaction with a
 player. Recent players are stored by MPA in a list, and a player may use them
 to form friend relationships, send messages and invites, or report feedback
 after a game is played.

## Using Multiplayer Activity

### Client flow
A title should have the following flow for handling multiplayer experiences:

1. When Player A starts or joins a multiplayer experience, the title should [set an
   activity](how-to/live-mpa-client-how-to.md#setting-an-activity) to represent
   this.
   * Both Xbox Live and other players in the title may [retrieve this
     activity](how-to/live-mpa-client-how-to.md#getting-activities). Depending
     on their relationship to Player A, the activity they receive may also
     include a connection string, which they may use it to join the game in
     progress.
2. Player A may [send invites](how-to/live-mpa-client-how-to.md#sending-invites)
   to other players, actively requesting them to join the game.
3. As players join and leave, the title should update the number of players in
   the activity by [setting it
   again](how-to/live-mpa-client-how-to.md#setting-an-activity), with updated
   information.
4. The title should [update the player's recent players
   list](how-to/live-mpa-client-how-to.md#updating-recent-players) with any
   players with whom they have had meaningful interactions.
5. When Player A ends or leaves the multiplayer experience, the title should [delete the
   activity](how-to/live-mpa-client-how-to.md#deleting-an-activity).

### External Server flow

A server may act on behalf of clients for any of these items.  In addition, a
server can:

* Record [bidirectional lists](concepts/live-mpa-recent-players.md#upvbg) of recent players.
* Send an invite on behalf of a user.
* Retrieve activities for multiple users at once, as opposed to one at a time.

See the forthcoming <a href="https://docs.microsoft.com/gaming/xbox-live/api-ref/xbox-live-rest/atoc-xboxlivews-reference" target="_blank">Xbox Live Services RESTful Reference &#11008;</a>.


## More details

For more information on the specifics of activities, invites, and recent players, see their respective concepts pages:
* [Activities](concepts/live-mpa-activities.md)
* [Invites](concepts/live-mpa-invites.md)
* [Recent Players](concepts/live-mpa-recent-players.md)
