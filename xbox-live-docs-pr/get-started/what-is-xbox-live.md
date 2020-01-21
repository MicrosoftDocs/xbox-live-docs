---
title: What is Xbox Live?
description: Xbox Live provides the greatest player community for your game on the most advanced cross-platform multiplayer network.
ms.assetid: 5a402113-b485-46f3-a30e-73f4b71492b6
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one
ms.localizationpriority: medium
---

# What is Xbox Live?

Xbox Live is a premier gaming network that connects millions of gamers across the world.
You can add Xbox Live to your game on mobile platforms, Windows 10 PC, and Xbox One console to take advantage of the Xbox Live features and services.

Here are some reasons to add Xbox Live to your game:

- Xbox Live unites gamers across Xbox One and Windows 10, so gamers can play with their friends and connect with a massive community of players.

- Xbox Live lets players build a gaming legacy by unlocking achievements, sharing epic game clips, amassing Gamerscore, and perfecting their avatar.

- Xbox Live lets gamers play and pick up where they left off on another Xbox One or PC, bringing all their saves from another device.

- With over 1 billion multiplayer matches played each month, Xbox Live is built for performance, speed and reliability.

- With cross-device multiplayer, gamers can play with your friends regardless of whether they play on Xbox One or Windows 10 PC.

With the Xbox Live Creators Program, anyone with a [Partner Center](https://partner.microsoft.com/dashboard) account can build an Xbox Live enabled Universal Windows Platform (UWP) game that can run on both Windows 10 PCs and Xbox One consoles.

For game developers that want to take advantage of the full Xbox Live experience, including multiplayer, achievements, and native Xbox console development, there are additional developer programs which are detailed in the [Developer Program Overview](join-dev-program/developer-program-overview.md).

For consumer Xbox Live information, see [Xbox Live](https://www.xbox.com/live/).


## How Xbox Live works

Xbox Live is a collection of micro-services that expose Xbox Live features such as profile, friends and presence, stats, leaderboards, achievements, multiplayer, and matchmaking.

Xbox Live data is stored in the cloud, and can be accessed by using REST endpoints and secure websockets that are accessible from a set of client-side APIs designed for game developers.

In addition to the REST APIs, there are client side APIs that wrap the REST functionality. See [Introduction to Xbox Live APIs](../api-ref/xsapi/live-introduction-to-xbox-live-apis.md).


## Join the Creators or ID program

The following guides can help you get started with Xbox Live development, regardless of whether you are a UWP or Xbox console developer.
There are also guides for getting setup with game engines.

| Article | Description |
|---------|-------------|
| [Developer Program Overview](join-dev-program/developer-program-overview.md) | The various developer programs that enable Xbox Live development. |
| [Get started with Xbox Live Creators Program](setup-partner-center/legacy/get-started-with-xbox-live-creators.md) | How to get started with Xbox Live in the Xbox Live Creators Program. |
| [Get started with Xbox Live as a Managed Partner](setup-partner-center/legacy/get-started-with-xbox-live-partner.md) | How to get started with Xbox Live as a developer in the Managed Partners Program. |


## Using Xbox Live

Once you have a title created and the fundamentals working, this section provides necessary background before you jump in and start coding.

| Article | Description |
|---------|-------------|
| [Using Xbox Live](../using-xbox-live/using-xbox-live.md) | Once you've setup your title and integrated the Xbox Live SDK, you are ready to implement sign-in and learn more about Xbox Live programming.
| [Best practices for calling Xbox Live](../using-xbox-live/best-practices/best-practices-for-calling-xbox-live.md) | Familiarize yourself with the basics on Xbox Live calling patterns and best-practices to ensure your title performs well and doesn't get rate limited.
| [Troubleshooting the Xbox Live Services API](../using-xbox-live/troubleshooting/troubleshooting-the-xbox-live-services-api.md) | Common issues you may encounter and suggestions on how to fix them.


## Social features

Xbox Live social features can organically grow your audience, spreading awareness to over 55 million active users.
This section describes how to get started with the Xbox Live social features.

| Article | Description |
|---------|-------------|
| [Social](../features/social/live-social-nav.md) | If you can sign-in a user, then you can start using Xbox Live's Social features, such as Friends list (People system), official and in-game clubs, activity feed (presence strings), and reputation. |


## Player Data

Xbox Live Player Data drives the usage of player stats, achievements, and leaderboards.
Read this series of articles to learn more about how to use these in your title.

| Article | Description |
|---------|-------------|
| [Xbox Live Player Data](../features/player-data/live-playerdata-nav.md) | A brief overview of the Player Data system, as well as guidance on how to best incorporate stats, leaderboards, and achievements into your title.
| [Achievements](../features/player-data/achievements/live-achievements-nav.md) | Achievements are one of the most well known features in Xbox Live, and a great driver of player engagement. Learn how to use them in your title.
| [Stats & Leaderboards](../features/player-data/stats-leaderboards/live-stats-leaderboards-nav.md) | Stats are the foundation of leaderboards.  Leaderboards bring out your users' competitive sides by intelligently incorporating leaderboards.


## Cloud Storage

Xbox Live Cloud Storage provides both Title Storage and Connected Storage.
These are two different but complementary services:  

*  *Connected Storage* allows you to implement game saves in the cloud, that will roam across devices regardless of where a user is signed-in.
*  *Title Storage* lets you store blobs of data that can be per user or per title and shared across different users.

| Article | Description |
|---------|-------------|
| [Xbox Live Cloud Storage](../features/cloud-storage/live-cloud-storage-nav.md) | Use the Xbox Live storage services for storing game saves, instant replays, user preferences, and other data in the cloud. |
| [Connected Storage](../features/cloud-storage/connected-storage/live-connected-storage-technical-overview.md) | An overview and programming guide on Connected Storage. |
| [Title Storage](../features/cloud-storage/title-storage/live-title-storage-overview.md) | An overview and programming guide on Title Storage. |


## Multiplayer features

Multiplayer is a great way to extend the lifetime of your title and keep gameplay experiences fresh.
Xbox Live provides extensive multiplayer and matchmaking features.
You also have several options of API that provide varying levels of simplicity vs flexibility.

| Article | Description |
|---------|-------------|
| [Multiplayer overview](../features/multiplayer/live-multiplayer-intro.md) | If you are new to Xbox Live multiplayer development, or are unfamiliar with new APIs such as Multiplayer Manager and Xbox Integrated Multiplayer (XIM), then start here. |
| [Common multiplayer scenarios](../features/multiplayer/concepts/live-common-multiplayer-scenarios.md) | Suggestions and guidance on how you might incorporate multiplayer into your title. |
| [Xbox Integrated Multiplayer (XIM)](../features/multiplayer/xim/live-xim-nav.md) | Xbox Integrated Multiplayer (XIM) is an easy self-contained interface for adding multiplayer, real-time networking, and chat to your title. |
| [Multiplayer Manager (MPM)](../features/multiplayer/mpm/live-multiplayer-manager-nav.md) | High-level API for adding multiplayer functionality by managing sessions, matchmaking, and game invites. Provides a state- and event-based programming model. |
