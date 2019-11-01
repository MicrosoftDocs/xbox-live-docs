---
title: Event-based Player Data overview
description: The game sends events to your Xbox Live service configuration, to update User Stats, Leaderboards, and Achievements.
kindex: Xbox Live, data platform
kindex: Event-based Player Data overview
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-how-data-platform-works.html
---

# Event-based Player Data overview

<!-- 
This article is copied from the old secure portal article "How the Xbox Live data platform 2013 works"  https://developer.microsoft.com/en-us/games/xbox/docs/xdk/how-data-platform-works
Original wording:
Note This article only applies if you are using Stats 2013 or Achievements 2013.
This topic discuss the basic concepts required to understand how to best use the Xbox Live data platform 2013 service.
-->
This article only applies if you are using event-based Stats or event-based Achievements.
This article discusses the basic concepts required to understand how to best use the event-based player data platform.

**Terminology**

_player data_ - This is also known as _user data_, to include the scenario of a non-game title. _data_ or _data platform_ means all associated functionality, including events, stats, stat rules, leaderboards, featured stats, achievements, rewards, and challenges.

_player stats_ - This is also known as _user stats_, to include the scenario of a non-game title. _stats_ means only some of the data platform functionality.


## Basic concepts

The Xbox Live event-based data platform is a RESTful service, which means that the service runs in the cloud (aka, a remote data center). Your game or app can send data, in the form of “events”, to the service, which then processes the data to create user statistics, achievements, leaderboards, challenges, and a variety of other data based information, according to rules that you have defined. These rules are known as a “service configuration”, and they let the Xbox Live data platform know how to process the event data from your title. We will discuss them more in the next section.

The flow of data starts when your title writes an event. An event consists of the name of the event, such as “PlayerScored”, and may optionally contain additional data that is relevant to the event. When your game writes an event, the system saves the event locally, to either the Event Tracer for Windows (ETW) (for Xbox One XDK titles), or the Universal Telemetry Client (UTC) (for Universal Windows Apps). A service running on your client then sends these events to the Xbox Live data platform when it can. This allows a system to not lose data in the event that internet connectivity is not available at the time that the event is written.

When the Xbox Live data platform service receives the event, it creates or updates user statistics, achievements, leaderboards, and challenges based on the rules that you defined in the service configuration.

You title can request the stats, achievements, leaderboards, etc., from the data platform service, however the only way for your title to update them is by writing events.


## Service configuration

Before your title can use the Xbox Live services, you must create a service configuration for your title. The service configuration lets the Xbox Live service know how your title will use the service. For the data platform, the service configuration defines the events that your title can send, along with any data that is associated with those events. The configuration also defines your title’s stats, achievements, leaderboards, challenges, and the rules that affect them.

<!-- If you are using Partner Center to create your service configuration, you can find more information at [Configure data platform 2013 in Dev Center](https://developer.microsoft.com/en-us/games/xbox/docs/xdk/dev-center-configure-data-platform-2013). -->
