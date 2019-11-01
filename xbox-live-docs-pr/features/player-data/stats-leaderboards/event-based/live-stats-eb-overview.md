---
title: Event-based Stats overview
description: The game sends events to your Xbox Live service configuration at the developer portal. These events are handled by stat rules to update stats on the server. The game can then retrieve the updated stats from the server.
kindex: Event-based Stats overview
kindex: stats, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-stats-eb-overview.html
---

# Event-based Stats overview

<!-- these 4 sentences are from public docs, were the file player-stats-2013.md, and were linked at bottom to old secure docs portal: -->

Player stats are key pieces of information to track about a player, such as *Head Shots* or *Fastest Lap Time*.

Stats are used to generate leaderboards in scenarios that allow players to compare their effort and skills with their friends and every other player in a title's community.

Event-based Stats was formerly named _Stats 2013_.
With event-based Stats, the Xbox Live Service owns and maintains the stats; stats are updated based on your game sending user-action events to the Xbox Live Service.

Event-based Stats is for Managed Partners only, not Creators.

<!-- See [User Stats for Data Platform 2013](https://developer.microsoft.com/games/xbox/docs/xdk/user-stats).
This is an external link, to the "Xbox One XDK" documentation. -->

<!-- the remainder of this article is from old secure portal article "User Stats for Data Platform 2013" (the old link above): -->

User Stats are developer-defined data points that are calculated by the Xbox Live service and stored as name-value pairs on a per-user basis.

Some examples of User Stats include:
* Total number of zombies killed with a shotgun in Hard difficulty
* Fastest time for completing level 3
* Highest score achieved in a multiplayer match
* Name of the car driven most recently.

<!-- probably old: "the XDP Service Configuration Tool" -->

With event-based Stats, stats are calculated in the Xbox Live service based on events logged by the title and statistics rules defined by the developer via the XDP Service Configuration Tool.

The game sends events to your Xbox Live service configuration at the developer portal. These events are handled by stat rules to update stats on the server. The game can then retrieve the updated stats from the server.
<!-- added new sentence above -->

The figures below show the relationship between events, stat rules, and user stats.

Figure 1. Events, stat rules, and user stats:

![Events and user statistics](../../../../../../../../resources/gamecore/secure/images/en-us/live/stats/events-and-user-stats2.png)

Figure 2. Events and stat templates:

![Events and stat templates](../../../../../../../../resources/gamecore/secure/images/en-us/live/stats/stat-templates.png)

Figure 3. Events, stat rules, and user stats, showing locations of processing:

![Rules, events, and stats, showing locations](../../../../../../../../resources/gamecore/secure/images/en-us/live/stats/stats2013diagram.jpg)

Every event has an event name and a set of fields.
Stat rules are triggered when an event of a particular name is received by the Xbox Live service.
Statistics rules produce stat instances.


## Defining stat instances

A _stat instance_ uses a single name-value pair.
This is the basic way to use stats.

You configure stat rules to control how the Xbox Live Service should produce stat instances based on events sent by the game.
See [User Stat Rules](live-user-stat-rules.md).


## Defining stat templates

A more advanced type of stats is a _stat template_.
A stat template includes some number of event fields in its name, in order to produce several stat instances.

A _stat template_ uses a statistics rule with event fields in its name, to produce multiple stat instances.

A statistics rule can be configured to produce either:
* A single stat instance
* Multiple stat instances based on a stat template.

A stat instance name refers to a particular name-value pair, for example:
* EnemiesDefeated
* HighScoreMP
* CurrentCarName

A stat template is produced by a statistics rule that includes one or more event fields as part of its name, so it can produce multiple stat instances.
For example:
* Stat template: BestTime.LevelId
* Stat Instance: BestTime.LevelId.3
* Stat Instance: BestTime.LevelId.55
* Stat template: EnemiesDefeated.EnemyTypeId.WeaponId.DifficultyLevelId
* Stat Instance: EnemiesDefeated.EnemyTypeId.6.WeaponId.17.DifficultyLevelId.4
* Stat Instance: EnemiesDefeated.EnemyTypeId.9.WeaponId.33.DifficultyLevelId.1
