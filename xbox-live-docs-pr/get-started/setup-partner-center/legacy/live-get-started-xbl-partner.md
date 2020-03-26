---
title: Getting started with Xbox Live, for Managed Partners
description: All the high-level steps for Xbox Live-enabling your game, from joining the Managed Partners Program, through releasing your game.
kindex: Getting started with Xbox Live, for Managed Partners
ms.topic: article
ms.assetid: 69ab75d1-c0e7-4bad-bf8f-5df5cfce13d5
ms.localizationpriority: medium
ms.date: 06/07/2017
---

# Getting started with Xbox Live, for Managed Partners

This section covers getting started with Xbox Live development, for Managed Partners.

Managed Partners can access the full range of Xbox Live features, including achievements, multiplayer, and more.

Managed Partners can develop Xbox Live titles for both the Universal Windows Platform (UWP) or the Xbox Developer Kit (XDK) platform.

In addition to the content available here, there is also additional documentation that is available to partners with an authorized Partner Center account: <a href="https://developer.microsoft.com/games/xbox/docs/xboxlive/xbox-live-partners/partner-content" target="_blank">Xbox Live partner content &#11008;</a>.


## Why should you use Xbox Live?

Xbox Live offers an array of features designed to help promote your game and keep gamers engaged:

- Xbox Live Social features let gamers connect with friends and talk about your game.
- Xbox Live achievements helps your game get popular by giving your game free promotion to the Xbox Live social graph when gamers unlock achievements.
- Xbox Live leaderboards helps drive engagement of your game by letting gamers compete to beat their friends and move up the ranks.
- Xbox Live multiplayer lets gamers play with their friends or a get matched with other players to compete or cooperate in your game.
- Xbox Live connected storage offers free save game roaming between devices so gamers can easily continue game progress between Xbox One (or later) consoles and Windows PCs.


## 1. Choose a platform

Decide between making an Xbox Development Kit (XDK), Universal Windows Platform (UWP), or cross-play game:

- XDK based games only run on the Xbox One (or later) console.
- UWP games can target any Windows platform such as Windows PC, Windows Phone, or Xbox One (or later) consoles.
  - For Xbox One (or later), see <a href="https://docs.microsoft.com/windows/uwp/xbox-apps/" target="_blank">UWP on Xbox One &#11008;</a> and specifically <a href="https://docs.microsoft.com/windows/uwp/xbox-apps/system-resource-allocation" target="_blank">System resources for UWP apps and games on Xbox One &#11008;</a>.
- Cross-play games are typically games that target Xbox One (or later) consoles and Windows PCs, using both the XDK and UWP paths.


## 2. Ensure that you have a title created in Partner Center

Every Xbox Live title must be defined in Partner Center before you will be able to sign-in and make Xbox Live Service calls.
See [Setting up a game at Partner Center, for Managed Partners](../live-setup-partner-center-partners.md).


## 3. Follow the appropriate guide to setup your IDE or game engine

You can follow the appropriate Getting Started guide for your platform and engine and learn the basics of Xbox Live as you go along.

* [Setting up an IDE](../../setup-ide/live-setup-ide-nav.md)
* [Configuring cross-play for Xbox and Windows 10 in Partner Center](../../../test-release/portal-config/live-config-cross-play-xbox-win10.md) shows how to make a product that is an XDK-based game for Xbox One (or later) and a UWP-based game for Windows 10 PC.


## 4. Xbox Live Concepts

Once you have a title created, you should learn about the Xbox Live concepts that will affect your experience developing titles:

- [Xbox Live Sandboxes overview](../../../test-release/sandboxes/live-setup-sandbox.md)
- [Xbox Live test accounts](../../../test-release/test-accounts/live-test-accounts.md)
- [Introduction to Xbox Live APIs](../../../api-ref/xsapi/live-introduction-to-xbox-live-apis.md)


## 5. Add Xbox Live Features

Add Xbox Live features to your game:

- [Player Data](../../../features/player-data/live-playerdata-nav.md) - Achievements, player stats, leaderboards, and featured stats.
- [Social](../../../features/social/live-social-nav.md) - Friends list (People system), official and in-game clubs, activity feed (presence strings), and reputation.
- [Multiplayer](../../../features/multiplayer/live-multiplayer-intro.md) - Matchmaking, invites, voice and text chat, and networking.
- [Cloud Storage](../../../features/cloud-storage/live-cloud-storage-nav.md) - Connected Storage and Title Storage.


## 6. Release Your Title

Managed Partners must go through a certification process before releasing their titles.
This is because the titles have access to additional features such as online multiplayer, achievements, and rich presence.
Once you are ready to release your title, contact your Microsoft representative for more details on the submission and release process.
