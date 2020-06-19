---
title: Xbox Live overview
description: Xbox Live provides the greatest player community for your game on the most advanced cross-platform multiplayer network.
kindex: Xbox Live overview
ms.topic: conceptual
ms.assetid: 5a402113-b485-46f3-a30e-73f4b71492b6
ms.localizationpriority: medium
author: mlamaute
ms.author: migreen
ms.date: 04/04/2017
---



# Xbox Live overview

Xbox Live is a premier gaming network that connects millions of gamers across the world.
You can add Xbox Live to your game on mobile platforms, Windows 10 PC, and Xbox One (or later) console to take advantage of the Xbox Live features and services.

Here are some reasons to add Xbox Live to your game:

- Xbox Live unites gamers across Xbox One (or later) consoles and Windows 10, so gamers can play with their friends and connect with a massive community of players.

- Xbox Live lets players build a gaming legacy by unlocking achievements, sharing epic game clips, amassing Gamerscore, and perfecting their avatar.

- Xbox Live lets gamers play and pick up where they left off on another Xbox One (or later) console or PC, bringing all their saves from another device.

- With over 1 billion multiplayer matches played each month, Xbox Live is built for performance, speed and reliability.

- With cross-device multiplayer, gamers can play with your friends regardless of whether they play on the Xbox One (or later) console or a Windows 10 PC.


## Joining a developers program

With the Xbox Live Creators Program, anyone with a [Partner Center](https://partner.microsoft.com/dashboard) account can build an Xbox Live enabled Universal Windows Platform (UWP) game that can run on both Windows 10 PCs and Xbox One (or later) consoles.

For game developers that want to take advantage of the full Xbox Live experience, including multiplayer, achievements, and native Xbox console development, see [Choosing an Xbox Live developer program](join-dev-program/live-dev-program-overview.md).

For consumer Xbox Live information, see <a href="https://www.xbox.com/live/" target="_blank">Xbox Live &#11008;</a>.


## How Xbox Live works

Xbox Live is a collection of micro-services that expose Xbox Live features such as profile, friends and presence, stats, leaderboards, achievements, multiplayer, and matchmaking.
Xbox Live data is stored in the cloud, and can be accessed by using REST endpoints and secure websockets that are accessible from a set of client-side APIs designed for game developers.

In addition to the REST APIs, there are client-side APIs that wrap the REST functionality.
See [Introduction to Xbox Live APIs](../api-ref/xsapi/live-introduction-to-xbox-live-apis.md).


<!-- ====================================================================== -->
## Feature areas


### Player Data

Xbox Live Player Data drives the usage of player stats, achievements, and leaderboards.

|  |  |
|---------|-------------|
| [Player Data](../features/player-data/live-playerdata-nav.md) | A brief overview of the Player Data system, as well as guidance on how to best incorporate stats, leaderboards, and achievements into your title.
| [Stats & Leaderboards](../features/player-data/stats-leaderboards/live-stats-leaderboards-nav.md) | Stats are the foundation of leaderboards.  Leaderboards bring out your users' competitive sides by intelligently incorporating leaderboards.
| [Achievements](../features/player-data/achievements/live-achievements-nav.md) | Achievements are one of the most well known features in Xbox Live, and a great driver of player engagement. Learn how to use them in your title.


### Social features

Xbox Live social features can organically grow your audience, spreading awareness to over 55 million active users.

|  |  |
|---------|-------------|
| [Social](../features/social/live-social-nav.md) | If you can sign-in a user, then you can start using Xbox Live's social features, such as a user's social graph, Rich Presence, Friends list (People system), activity feed (presence strings), and reputation. |
| [Social Manager](../features/social/social-manager/live-social-manager-nav.md) | The Xbox Live Social Manager API simplifies keeping track of online friends and their gaming activity. |
| [People System (Friends List)](../features/social/people-system/live-people-system-nav.md) | Manages relationships between gamers, such as only showing a user's real name to close friends. |
| [Rich Presence](../features/social/presence/live-presence-nav.md) | Shows what activity a user is currently doing, in which area of the game. |
| [Localized strings](../features/social/localized-strings/live-localized-strings-nav.md) | Configuring UI strings in various languages for an Xbox Live game at Partner Center. |
| [Reputation](../features/social/reputation/live-reputation-nav.md) | The Reputation service encourages positive gameplay. |


### Multiplayer features

Multiplayer is a great way to extend the lifetime of your title and keep gameplay experiences fresh.
Xbox Live provides extensive multiplayer and matchmaking features.
You also have several options of API that provide varying levels of simplicity vs flexibility.

|  |  |
|---------|-------------|
| [Multiplayer overview](../features/multiplayer/live-multiplayer-intro.md) | If you are new to Xbox Live multiplayer development, or are unfamiliar with new APIs such as Multiplayer Manager and Xbox Integrated Multiplayer (XIM), start here. |
| [Common multiplayer scenarios](../features/multiplayer/live-common-multiplayer-scenarios.md) | Suggestions and guidance on how you might incorporate multiplayer into your title. |
| [Multiplayer Activity (MPA)](../features/multiplayer/mpa/live-mpa-nav.md) | Simplifies platform integration for player activities (joins), invites, and recent players, and allows players to launch into your game from their social graph. |
| [Xbox Integrated Multiplayer (XIM)](../features/multiplayer/xim/live-xim-nav.md) | Xbox Integrated Multiplayer (XIM) is an easy self-contained interface for adding multiplayer, real-time networking, and chat to your title. |
| [Multiplayer Manager (MPM)](../features/multiplayer/mpm/live-multiplayer-manager-nav.md) | Multiplayer Manager provides a high-level API focused on common multiplayer scenarios, including adding multiplayer functionality by managing sessions, matchmaking, and game invites. Provides a state- and event-based programming model. |
| [Multiplayer Session Directory (MPSD)](../features/multiplayer/mpsd/live-mpsd-nav.md) | Shares information to connect a group of users. Coordinates with the shell and console operating system in sending/accepting invites and in being joined via the gamer card. |
| [Invites](../features/multiplayer/invites/live-invites-nav.md) | A player can invite other players to their game sessions. Invited players receive a game invite, and the title uses this information to join the existing session and multiplayer experience. |
| [SmartMatch Matchmaking](../features/multiplayer/matchmaking/live-matchmaking-nav.md) | The SmartMatch matchmaking service selects compatible players in a multiplayer game. |

### Cloud Storage

Xbox Live Cloud Storage provides both Title Storage and Connected Storage.
These are two different but complementary services.
*  *Connected Storage* allows you to implement game saves in the cloud, that will roam across devices regardless of where a user is signed-in.
*  *Title Storage* lets you store blobs of data that can be per user or per title and shared across different users.

|  |  |
|---------|-------------|
| [Connected Storage vs. Title Storage](../features/cloud-storage/live-connected-storage-vs-title-storage.md) | Xbox Live Cloud Storage includes Connected Storage to store game state, and Title Storage to store player statistics and assets. |
| [Connected Storage](../features/cloud-storage/connected-storage/live-connected-storage-nav.md) | Connected Storage saves and loads gameplay data and other state data across devices. Title data is stored locally and also synced to the cloud. |
| [Title Storage](../features/cloud-storage/title-storage/live-title-storage-nav.md) | Title Storage is cloud storage for large amounts of per-user or per-game data, such as player statistics and assets. |
