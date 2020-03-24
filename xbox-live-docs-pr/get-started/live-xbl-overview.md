---
title: Xbox Live overview
description: Xbox Live provides the greatest player community for your game on the most advanced cross-platform multiplayer network.
kindex: Xbox Live overview
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.assetid: 5a402113-b485-46f3-a30e-73f4b71492b6
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Xbox Live overview

Xbox Live is a premier gaming network that connects millions of gamers across the world.
You can add Xbox Live to your game on mobile platforms, Windows 10 PC, and Xbox One console to take advantage of the Xbox Live features and services.

Here are some reasons to add Xbox Live to your game:

- Xbox Live unites gamers across Xbox One and Windows 10, so gamers can play with their friends and connect with a massive community of players.

- Xbox Live lets players build a gaming legacy by unlocking achievements, sharing epic game clips, amassing Gamerscore, and perfecting their avatar.

- Xbox Live lets gamers play and pick up where they left off on another Xbox One or PC, bringing all their saves from another device.

- With over 1 billion multiplayer matches played each month, Xbox Live is built for performance, speed and reliability.

- With cross-device multiplayer, gamers can play with your friends regardless of whether they play on Xbox One or Windows 10 PC.

With the Xbox Live Creators Program, anyone with a [Partner Center](https://partner.microsoft.com/dashboard) account can build an Xbox Live enabled Universal Windows Platform (UWP) game that can run on both Windows 10 PCs and Xbox One consoles.

For game developers that want to take advantage of the full Xbox Live experience, including multiplayer, achievements, and native Xbox console development, see [Choosing an Xbox Live developer program](join-dev-program/live-dev-program-overview.md).

For consumer Xbox Live information, see <a href="https://www.xbox.com/live/" target="_blank">Xbox Live &#11008;</a>.


## How Xbox Live works

Xbox Live is a collection of micro-services that expose Xbox Live features such as profile, friends and presence, stats, leaderboards, achievements, multiplayer, and matchmaking.
Xbox Live data is stored in the cloud, and can be accessed by using REST endpoints and secure websockets that are accessible from a set of client-side APIs designed for game developers.

In addition to the REST APIs, there are client-side APIs that wrap the REST functionality.
See [Introduction to Xbox Live APIs](../api-ref/xsapi/live-introduction-to-xbox-live-apis.md).


## Join the Creators or ID program

The following guides can help you get started with Xbox Live development, regardless of whether you are a UWP or Xbox console developer.
There are also guides for getting setup with game engines.

| Article | Description |
|---------|-------------|
| [Choosing an Xbox Live developer program](join-dev-program/live-dev-program-overview.md) | The various developer programs that enable Xbox Live development. |
| [Getting started with Xbox Live, for Creators](setup-partner-center/legacy/live-get-started-creators.md) | How to get started with Xbox Live in the Xbox Live Creators Program. |
| [Getting started with Xbox Live, for Managed Partners](setup-partner-center/legacy/live-get-started-xbl-partner.md) | How to get started with Xbox Live as a developer in the Managed Partners Program. |


## Using Xbox Live

Once you have a title created and the fundamentals working, this section provides necessary background before you jump in and start coding.

| Article | Description |
|---------|-------------|
| [Error handling](../test-release/services/error-handling/live-error-handling-nav.md) | Handling errors when calling an Xbox Live service through XSAPI. |
| [Authentication and sign-in](../features/identity/auth/live-authentication-nav.md) | Signing-in an Xbox Live user in your title. |
| [Best practices for calling Xbox Live](../test-release/services/best-practices/live-best-practices-calling-xbl.md) | Familiarize yourself with the basics on Xbox Live calling patterns and best-practices to ensure your title performs well and doesn't get rate limited.
| [Troubleshooting Xbox Live Services APIs](../test-release/troubleshooting/live-troubleshooting-apis.md) | Common issues you may encounter and suggestions on how to fix them.


## Player Data

Xbox Live Player Data drives the usage of player stats, achievements, and leaderboards.
Read this series of articles to learn more about how to use these in your title.

| Article | Description |
|---------|-------------|
| [Player Data](../features/player-data/live-playerdata-nav.md) | A brief overview of the Player Data system, as well as guidance on how to best incorporate stats, leaderboards, and achievements into your title.
| [Stats & Leaderboards](../features/player-data/stats-leaderboards/live-stats-leaderboards-nav.md) | Stats are the foundation of leaderboards.  Leaderboards bring out your users' competitive sides by intelligently incorporating leaderboards.
| [Achievements](../features/player-data/achievements/live-achievements-nav.md) | Achievements are one of the most well known features in Xbox Live, and a great driver of player engagement. Learn how to use them in your title.


## Social features

Xbox Live social features can organically grow your audience, spreading awareness to over 55 million active users.
This section describes how to get started with the Xbox Live social features.

| Article | Description |
|---------|-------------|
| [Social](../features/social/live-social-nav.md) | If you can sign-in a user, then you can start using Xbox Live's Social features, such as Friends list (People system), official and in-game clubs, activity feed (presence strings), and reputation. |


## Multiplayer features

Multiplayer is a great way to extend the lifetime of your title and keep gameplay experiences fresh.
Xbox Live provides extensive multiplayer and matchmaking features.
You also have several options of API that provide varying levels of simplicity vs flexibility.

| Article | Description |
|---------|-------------|
| [Multiplayer overview](../features/multiplayer/live-multiplayer-intro.md) | If you are new to Xbox Live multiplayer development, or are unfamiliar with new APIs such as Multiplayer Manager and Xbox Integrated Multiplayer (XIM), start here. |
| [Common multiplayer scenarios](../features/multiplayer/live-common-multiplayer-scenarios.md) | Suggestions and guidance on how you might incorporate multiplayer into your title. |
| [Xbox Integrated Multiplayer (XIM)](../features/multiplayer/xim/live-xim-nav.md) | Xbox Integrated Multiplayer (XIM) is an easy self-contained interface for adding multiplayer, real-time networking, and chat to your title. |
| [Multiplayer Manager (MPM)](../features/multiplayer/mpm/live-multiplayer-manager-nav.md) | Multiplayer Manager provides a high-level API focused on common multiplayer scenarios, including adding multiplayer functionality by managing sessions, matchmaking, and game invites. Provides a state- and event-based programming model. |



## Cloud Storage

Xbox Live Cloud Storage provides both Title Storage and Connected Storage.
These are two different but complementary services:  

*  *Connected Storage* allows you to implement game saves in the cloud, that will roam across devices regardless of where a user is signed-in.
*  *Title Storage* lets you store blobs of data that can be per user or per title and shared across different users.

| Article | Description |
|---------|-------------|
| [Connected Storage vs. Title Storage](../features/cloud-storage/live-connected-storage-vs-title-storage.md) | Xbox Live Cloud Storage includes Connected Storage to store game state, and Title Storage to store player statistics and assets. |
| [Connected Storage](../features/cloud-storage/connected-storage/live-connected-storage-nav.md) | Connected Storage saves and loads gameplay data and other state data across devices. Title data is stored locally and also synced to the cloud. |
| [Title Storage](../features/cloud-storage/title-storage/live-title-storage-nav.md) | Title Storage is cloud storage for large amounts of per-user or per-game data, such as player statistics and assets. |
