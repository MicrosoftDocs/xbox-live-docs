---
title: Multiplayer 2015 appendix
author: KevinAsgari
description: The Multiplayer 2015 service is a more complex way than the Multiplayer Manager API, to enable game play and assembling game players into groups.
ms.assetid: 412ae5f4-6975-4a8b-9cc2-9747e093ec4d
ms.author: kevinasg
ms.date: 04/04/2017
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, uwp, windows 10, xbox one
ms.localizationpriority: medium
---

# Multiplayer 2015 appendix

> **Note**  
The Multiplayer 2015 service, described in this article, is for advanced API usage.  As a starting point, instead use the [Multiplayer Manager API](../multiplayer-manager.md) which significantly simplifies development. If you find an unsupported scenario in the Multiplayer Manager API, please let your DAM know.

> **Note**  
The previous version of the multiplayer system is Multiplayer 2014. This version is based on the concept of the *game party* and participation in games through *parties*. This version is now deprecated, although source code for it is still provided with the XDK. The Multiplayer 2014 documentation is no longer included with the XDK. If you need this documentation, use a 2014 release of the XDK.


The Multiplayer 2015 system in Xbox One enables game play and the assembly of game players into groups. The system is secure and flexible, allowing you not only to build simple features quickly, but also to build more complex features and plug in your own services.

The Multiplayer 2015 service abstracts-away the Multiplayer 2014 "game party" concept and instead uses the multiplayer session directory (MPSD) to control game sessions.

## In this section

| Topic                                                                                                                                             | Description                                                                                                   |
|:--------------------------------------------------------------------------------------------------------------------------------------------------|:--------------------------------------------------------------------------------------------------------------|
| [Introduction](introduction-to-the-multiplayer-system.md) | The Multiplayer 2015 service is a more complex way than the Multiplayer Manager API, to enable game play and assembling game players into groups. |
| [Multiplayer Session Directory (mpsd)](multiplayer-session-directory.md) | Multiplayer Session Directory centralizes a game's multiplayer API metadata across all the titles and manages game sessions. |
| [MPSD Session Details](mpsd-session-details.md) | Details about multiplayer sessions. |
| [Common Issues When Adapting Your Titles for Multiplayer 2015](common-issues-when-adapting-multiplayer.md) | Changing a title from Multiplayer 2014 to Multiplayer 2015. |
| [SmartMatch Matchmaking](smartmatch-matchmaking.md) | The SmartMatch matchmaking service selects compatible players in a multiplayer game. |
| [Migrating an Arbiter](migrating-an-arbiter.md) | Selecting a new arbiter for Multiplayer 2015 by using either graceful or failover migration. |
| [Using SmartMatch Matchmaking](using-smartmatch-matchmaking.md) | Using SmartMatch to match players in a multiplayer game. |
| [Multiplayer how-to's](multiplayer-how-tos.md) | Implementing common tasks in Multiplayer 2015. |
| [Multiplayer session status codes](multiplayer-session-status-codes.md) | Status codes returned from the Xbox Live service when requesting a multiplayer session. |
| [Multiplayer 2015 FAQs and Troubleshooting](multiplayer-2015-faq.md) | FAQs and troubleshooting for Multiplayer 2015. |
| [Xbox One multiplayer session directory](xbox-one-multiplayer-session-directory.md) | Multiplayer Session Directory (MPSD) enables a title to share the information needed to connect a group of users, to create a multiplayer session. |
| [Flows for multiplayer game invites](flows-for-multiplayer-game-invites.md) | Updated flow diagrams for implementing multiplayer game invites, to invite another player to a multiplayer game. |
| [Game session and game party visibility and joinability](game-session-and-game-party-visibility-and-joinability.md) | Visibility and joinability of multiplayer game sessions and game parties. |
