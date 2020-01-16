---
title: Event-based vs. title-managed Stats
description: User Stats can be updated by sending events to the Xbox Live service or by directly calling the Stats API.
kindex: Xbox Live stats
kindex: stats, Xbox Live
author: aablackm
ms.author: aablackm
ms.date: 07/30/2018
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, player stats, leaderboards
ms.localizationpriority: medium
ms.assetid: 5ec7cec6-4296-483d-960d-2f025af6896e
---

# Event-based vs. title-managed Stats

<!-- renamed file from leaderboards-and-stats-2017/using-player-stats.md -->

As described in [Player Data Overview](../live-playerdata-overview.md), stats are key pieces of information you want to track about a player, such as *Head Shots* or *Fastest Lap Time*.
Stats are used to generate leaderboards in a number of scenarios that will allow players to compare their effort and skills with their friends and every other player in a title's community.

*Configured stats* show up in a title's GameHub leaderboard, where a player will see how they rank against their friends who have also played the title.
For more information about GameHub leaderboards, see [Designing Xbox Live Experiences](../live-designing-experiences.md).

<!-- pinned content blocks are no longer applicable:

The stats that show up in a title's Game Hub are called *Featured stats*, aka *Hero stats*.
In addition to showing up in the Game Hub, as of the Xbox One 1806 update, Featured Stats may also periodically appear in pinned content blocks that users may add to their Home view.
This allows quick access to social leaderboards for directly from the Home view.

Featured Stats are one of several possible items displayed in pinned Content Blocks, so users may not always see them if Microsoft’s content services determine another content item could be more compelling.
-->

There are two implementations of Stats for Xbox Live:
* Event-based Stats (formerly called _Stats 2013_)
* Title-managed Stats (formerly called _Stats 2017_)

* Managed Partners can use event-based Stats or title-managed Stats.

* Xbox Live Creators Program developers can only use title-managed Stats, and so can ignore event-based Stats.
  Creators Program developers can skip ahead to [Title-managed Stats overview](title-managed/live-stats2017.md).
Event-based Stats and title-managed Stats operate on fundamentally different principles, as follows.


### Event-based Stats

When using event-based Stats, you send **events** to the Xbox Live Service containing certain information about an action a user performed.

The information in these **events** is used to update stats accordingly.
In event-based Stats, the service keeps track of and updates all of your stats values, so that the service is the source of truth for statistic values for a player or group of players.


### Title-managed Stats

When using title-managed Stats, you send up the actual stat value itself for the server to use.

In title-managed Stats, the server does little to no validation on the value sent to it, and so it is up to your title to keep track of the correct stat values; your title is the source of truth for statistic values.
When using title-managed Stats, we recommend that you track and store your stats in the cloud with the [Xbox Live Cloud Storage](../../../features/cloud-storage/cloud-storage_nav.md).

Title-managed Stats is like a reporting service: you send the correct stat for your game to the server, your stat then sits on the server and waits to be displayed on request or updated.


## History

With the launch of Xbox One, Xbox Live introduced a new event-driven stats model: event-based Stats.
This offered a multitude of benefits – a single event from a game can update data for multiple Xbox Live features, such as leaderboards and achievements; Xbox Live configuration lives on the server instead of in the client; and much more.

In the years following the Xbox One launch, we listened closely to game developer feedback, and developers consistently requested a more streamlined stats service that would allow them to bypass the complexity that comes with an event-driven system, as well as allow them to use any stats tracking methods they were already practicing.

Based on Developer feedback, a new simplified version of stats was created that would put control of stats logic back into the hands of the developer.
That system is title-managed Stats, a service that simply takes the value passed to it by the title, giving developers control of the logic of how a stat value is determined.


## How Stats are handled in event-based Stats and title-managed Stats

Let's take a look at configuring and updating stats for event-based Stats versus title-managed Stats.
Let us say we're going to make stats from some generic RPG and want to keep track of monsters killed.


### Event-based Stats

In event-based Stats, your title would send an *event* that contains information about an action performed by a player.

In this event, the action will be slaying an orc while the player had a sword equipped.
Some of the information contained in this event might be that a slay action was taken, the thing slayed was an orc, the combat type was melee, and the weapon used was a sword.

Event-based Stats will run this information through a number of rules configured by you, the developer, at [Partner Center](https://partner.microsoft.com/dashboard), and update stats, also configured by you, based on the event.

In event-based Stats, the service will keep track of what the value for your slaying statistics should be.
The "slay orc with sword" event could update multiple statistics such as, number of kills, number of orcs slain, and number of sword kills.


### Title-managed Stats

In title-managed Stats, you will send up the actual values for your statistics.

For the "slay orc with sword" example, your title will keep track of the number of overall kills, sword kills, and orcs slain individually, and send the service the updated number for each statistic.
The service has minimal validation checks to make sure that you're sending a number that makes sense, so it is absolutely up to your title to send up the correct statistic.

Although you may use the title-managed Stats service to recall the values of stats at the beginning of a game session, you should not use the title-managed Stats service to confirm the value of a stat while the session is ongoing.

How the two flavors of Stats operate:
![Event-based vs. title-based Stats](live-stats-eb-vs-tm-images/Stats2013-7DiagramColored.jpg)


## Other differences between the two approaches

For Managed Partners, there are a few more differences you should be aware of when deciding between event-based Stats and title-managed Stats for your title.

Event-based Stats allows for more leaderboard views.
Event-based Stats allows you to more easily drill down on the meta data of your statistics.
In our "orc slay" example, the overall statistic was keeping track of the number of kills.
Event-based Stats allows you to drill down on your statistics to what was killed and with what weapon as well as any other kill defining information you may configure.

Event-based Stats has a native "minutes played" stat.
Event-based Stats allows you access to a player's play time in game without configuring the statistic.
Any playtime statistic would have to be tracked by your title in title-managed Stats.


### Update frequency

Event-based Stats has a near-real-time update frequency.
The event-based Stats event system updates your stats almost instantaneously.
In title-managed Stats, there is a 5-minute wait time before updated stats are flushed to the service.
The developer can flush statistics manually, but will still be throttled to a minimum of 30 seconds between flushes.

Event-based Stats can support other Xbox Live Services.
With event-based Stats, you can use stats to unlock achievements and make matchmaking decisions.
Title-managed Stats is only used to produce Featured Stats and leaderboards.


## Further reading

For a more in-depth explanation of event-based Stats, see [Event-based Stats overview](event-based/live-stats-eb-overview.md).

For a more in-depth explanation of title-managed Stats, see [Title-managed Stats overview](title-managed/live-stats2017.md).
