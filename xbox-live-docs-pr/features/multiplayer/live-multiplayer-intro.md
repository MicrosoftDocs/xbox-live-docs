---
title: Xbox Live multiplayer overview
description: Multiplayer features in Xbox Live include Multiplayer Session Directory, matchmaking, networking, voice chat, and text chat.
kindex: Xbox Live multiplayer overview
author: joanlee
ms.author: joanlee
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.localizationpriority: medium
ms.date: 01/17/2021
edited: 01/17/2021
---

# Xbox Live multiplayer overview

Xbox Live multiplayer helps you create real-time multiplayer gameplay experiences in your title. 

These multiplayer features can be used to create interactions such as chatting and playing together over the Internet **for Xbox Live users**. These interactions can help to dramatically extend the life and usage of your title beyond typical solo play.

They can also be used in combination with your custom solutions and PlayFab Multiplayer features. To learn how you can mix and match these features when developing titles using the GDK, see [Multiplayer overview (secure site)](https://aka.ms/gdkdocs), [Xbox and PC multiplayer design guidance (secure site)](https://aka.ms/gdkdocs), and [Cross-platform multiplayer design guidance (secure site)](https://aka.ms/gdkdocs). If your titles need server hosting, see [Azure PlayFab Multiplayer Servers (MPS)](https://docs.microsoft.com/gaming/playfab/features/multiplayer/servers/). 

By building a great multiplayer experience, your title would be able to leverage the large social network of Xbox Live gamers to help increase the user base for your game and promote a sustained community of dedicated fans playing together.

## Xbox Live multiplayer features

Xbox Live multiplayer APIs can be used to enable features like sending and accepting invites, matchmaking, voice chat, and text chat for Xbox Live users. 

They can be categorized into the following major sub-systems.

* [Multiplayer session process life-cycle management](#multiplayer-session-process-life-cycle-management)
* [Simple and advanced matchmaking](#simple-and-advanced-matchmaking)
* [Xbox Live social experiences for titles with custom session and matchmaking components](#xbox-live-social-experiences-for-titles-with-custom-session-and-matchmaking-components)
* [Secure real-time voice and text chat communication](#secure-real-time-voice-and-text-chat-communication)
* [Real-time networking and communication solution for client-host titles](#real-time-networking-and-communication-solution-for-client-host-titles)

### Multiplayer session process life-cycle management

Multiplayer session process life-cycle management shares and coordinates information needed to connect a group of users together. It can facilitate interactions between server-client, matchmaking logic and session creations, UI and multiplayer game experiences, and more.

There are two types of services available. To learn more about the differences between these services, see [Multiplayer overview (secure site)](https://aka.ms/gdkdocs).

**1. Xbox Multiplayer Session Directory (MPSD)**

Multiplayer Session Directory enables you to manage extensively customized multiplayer experiences. It can be used for both server-client and client-host designs. MPSD also integrates the UI (also known as shell) experiences and the console operation system to find and invite Xbox Live users for play. For more details, see [Multiplayer Session Directory overview](mpsd/live-mpsd-overview.md).

**2. Xbox Multiplayer Manager (MPM)**

For **client-host** (peer-to-peer with relay) titles that require only simple multiplayer capabilities, you can choose to use Xbox Multiplayer Manager (MPM) instead. MPM is a client side API that enables common multiplayer scenarios that follow best practices. It is best suited for game sessions that have eight or less users. For more details, see [Multiplayer Manager overview](mpm/live-multiplayer-manager-overview.md).

### Simple and advanced matchmaking

Xbox SmartMatch is a matchmaking service that provides both traditional quickmatch capabilities, as well as, session browse and support for highly customized matchmaking scenarios.

Additionally, you can integrate Xbox Looking for Group (LFG) service in your title to allow players to find other Xbox Live users who share the same interest and goals as them. 

For more details, see [Matchmaking overview](matchmaking/live-matchmaking-overview.md).

### Xbox Live social experiences for titles with custom session and matchmaking components

Xbox Live social experiences around invites and joins is a requirement for Xbox and PC for Windows titles. 

Xbox Multiplayer Activity (MPA) is designed to help titles using custom/studio developed components, like matchmaking and lobby management functionalities, to light up these social experiences. For more details, see [Multiplayer Activity overview](mpa/live-mpa-overview.md).

### Secure real-time voice and text chat communication

Xbox Game Chat 2 facilitates secure in-game communication by leveraging Xbox Live social graph, media services, and specialized encoding hardware on Xbox One (or later) devices. For more details, see [Game Chat 2](chat/live-game-chat-2-overview.md).

### Real-time networking and communication solution for client-host titles

For those who are looking for an integrated real-time networking and communication solution, consider PlayFab Party. Party is a cross-platform solution designed to quickly add multiplayer experiences in client-host (peer-to-peer with relay) titles. For more information, see [Party overview](https://docs.microsoft.com/gaming/playfab/features/multiplayer/networking/).

Xbox Integrated Multiplayer (XIM), a similar solution provided by Xbox Live, has been deprecated. It does not work for GDK titles and no new XDK titles can adopt this technology. However, we will continue to support this for existing XDK titles so that published titles would continue to work.

> [!NOTE]
> For titles using server-client architecture, you can still use Party as a real-time voice and chat communication solution.

## Next steps

* [Multiplayer overview (secure site)](https://aka.ms/gdkdocs)
* [Common multiplayer scenarios](live-common-multiplayer-scenarios.md)