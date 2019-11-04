---
title: Event-based Leaderboards overview
description: Leaderboards compare players by showing selected stats for a game.
kindex: Event-based Leaderboards overview
kindex: Leaderboards, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.date: 06/07/2019
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
ms.localizationpriority: medium
permalink: en-us/games/xbox/docs/gxdk/live-leaderboards-eb-overview.html
---

# Event-based Leaderboards overview

<!-- 
This article is for Data Platform 2013.

From "Xbox One XDK" TOC: "Leaderboards 2013"||"Leaderboards"
https://developer.microsoft.com/games/xbox/docs/xdk/leaderboards-2013
=
"Xbox Live developer guide||Xbox Live partner content" TOC, TOC title: "Leaderboards 2013"; top-of-page title: "Leaderboards"
https://developer.microsoft.com/games/xbox/docs/xboxlive/xbox-live-partners/event-driven-data-platform/leaderboards-2013
-->

Leaderboards are a fun way to engage users and drive competition amongst your players. Xbox Live provides functionality that is suited for your hardcore gamers (Global ranking against the whole Xbox Live population) and for your casual gamers (Social ranking against a user’s friends).

There are two types of Leaderboards available to you: global and social leaderboards.
These are both very similar concepts, but they have fundamental differences in terms of configuration and intent.


## Global vs. social leaderboards


### Global leaderboards

* A global leaderboard ranks the whole Xbox Live user base, and must be configured.

* A global leaderboard is a predefined view configured by the developer in the service at ingestion time (either before or at any time after the title is released).


### Social leaderboards

* A social leaderboard is generated dynamically, and ranks user’s friends.

* A social leaderboard only includes people who are in the user’s social graph.

* A social leaderboard doesn't need to be pre-defined at ingestion time, because the service generates the leaderboard dynamically at run time, based off existing user stats.


## Understanding Leaderboards

Leaderboards have two main components:

* A value to be ranked against (in Xbox Live, this is always a Player Stat)

* Sort order (Higher or lower values are better)


### Stats as ranking values

Leaderboards are derived from Player Stats so having the right Stat Rules defined for what you need is crucial. As your are designing your game, keep in mind what Leaderboards you’d like users to be ranked against.


## Global Leaderboards

Global leaderboards keep track of the best scores recorded by players across the Xbox LIVE community. The main differentiation for Global leaderboards is that they are predefined at ingestion time by specifying a leaderboard identification name, ranked stat, and sort order (ascending or descending). 

Titles can define an unlimited number of global leaderboards and add more leaderboards at any time via service configuration. The maximum number of records per global leaderboard is currently limited to 10,000 entries. This means that players whose “best” score is not ranked in the top 10,000 will not appear in the leaderboard.



<!--
Could move sections into the Partner Center article, instead of keeping in orig article section per old secure docs portal
-->

It is possible to read a “page” of up to 100 leaderboard entries (player XUID, gamertag, global rank, and score) at a time and specify the starting rank of the page, or retrieve leaderboard entries centered around a specified gamertag. The results are always scoped to all-time; day, week, and month views are not supported yet.

Global leaderboards can be accessed via XSAPI or our REST API using `GET (/scids/{scid}/leaderboards/{leaderboardname})`.

Below is a screenshot of how a sample Leaderboard could be configured for a racing game:

![Leaderboard details](live-leaderboards-eb-overview-images/leaderboard-details.png)


## Social Leaderboards

Social leaderboards are great incentives for casual gamers to compare and rank themselves against their friends so even if they are not in the highest ranks of the community, they can still be motivated to beat people they know. They are dynamically created based on any existing user stat, and therefore don’t need to be pre-defined at ingestion time and only people in one specific player’s social graph.

The main advantage to Social Leaderboards is that these are not predefined so you could create a Social Leaderboard for any stat for your game. The caller can specify two things when requesting a social leaderboard: 1) the stat instance and 2) sort order (default is descending by rating). The results are always scoped to all-time; day, week, month views are not supported.

As with global leaderboards, a caller can read a “page” of up to 100 leaderboard entries (player XUID, Gamertag, global rank, and score) at a time and specify the starting rank of the page.

Social leaderboards are accessed via XSAPI or our REST API using `GET (/users/xuid({xuid})/scids/{scid}/stats/{statname)/people/{all|favorite})`.


## Global Leaderboards with a Social View

Since social leaderboards are created dynamically, it takes longer to retrieve a social leaderboard than it does for a global leaderboard. For scenarios where your title frequently retrieves a social leaderboard based on a common set of criteria, you can create a global leaderboard, and retrieve only the entries in the leaderboard that pertain to the user’s social graph.

This results in a faster retrieval time than social leaderboards, since the leaderboard already exists on the Xbox Live servers, and results in a smaller payload, since the results are scoped to the user’s social graph. This type of leaderboard is a global leaderboard, and therefore must be defined in the title’s service configuration.

Global leaderboards with a social view are accessed using the normal global leaderboard request, `GET (/scids/{scid}/leaderboards/{leaderboardname})`, and appending the following query to the URL: `&viewTarget=people&view=people`.

To support multi-column leaderboard views stats metadata can be used. A title can define metadata fields for a leaderboard stat which can be returned when querying leaderboard ranks. A title should not use the batch User Stats URI to achieve the same behavior as privacy settings may prevent stats access.


## Multi-column Leaderboards

There will be cases where you need more columns in a Leaderboard to decorate the stat with more information, for example, for a Leaderboard for most enemies defeated, you might want to add the weapon the player used, the map where it happened, the most type of enemies defeated, and the K/D ratio.

Xbox Live Leaderboards have multi-column support built in so you can very easily get these type of rankings. The only pre-requisite is that the stat utilized for the Leaderboard has Stat Context defined, which is what’ll be used as additional metadata. For example, for a FastestLap stat we might want to configure these additional properties as Stat Context:

![Stat context](live-leaderboards-eb-overview-images/stat-context.png)

Now that the stat will be getting persisted with context, if we retrieve the multi-column leaderboard, it would look something like this:

| Operator | Value (FastestLap) | CarModel | WeatherCondition | TrackId |
| --- | --- | --- | --- | --- |
| SUM | Constant or field | Model A | Rainy | 9 |
| MIN | Field | Model A | Sunny | 9 |
| MAX | Field | Model B | Sunny | 2 |
| REPLACE | Constant or field | Model C | Cloudy | 1 |

Multi-column leaderboards are currently supported in Global Leaderboards and Global Leaderboards with a Social View. However if you’d like to create a Multi-column _Social_ Leaderboard, you can use the batch User Stats call to get all the stats with their context and manually create the leaderboard.

Multi-column leaderboards are only accessed via our REST API using the normal global leaderboard request, `GET (/scids/{scid}/leaderboards/{leaderboardname})`, and appending the following query to the URL: `&include=valuemetadata`.


## Where leaderboards with Featured Stats appear

<!-- 
from "Xbox Live" TOC; "Overview of leaderboards"||"Leaderboards"
https://review.docs.microsoft.com/gaming/xbox-live/leaderboards-and-stats-2017/leaderboards?branch=master
copied top half only.
-->

Leaderboards compare players by showing selected stats for a game.

<!-- XBL docs delta: 
# Leaderboards
## Introduction 
As described in [Player Data Overview](../data-platform/data-platform-for-stats-leaderboards-achievements.md),  
-->

Leaderboards are a great way to encourage competition between your players, and keep players engaged in trying to beat their previous best score as well as that of their friends.

<!-- XBL docs delta: 
[Featured Stats](stats2017.md#configured-stats-and-featured-leaderboards)  
-->

<!-- broke up into list, reworded, added subheading: -->

* Leaderboards for Featured Stats are always displayed in a title's Official Club.

* Leaderboards for Featured Stats are sometimes displayed in other Xbox Live experiences, such as a player’s achievement view in their profile.

* You can also use your configured Featured Stats to create Leaderboards inside of your title.


## Choosing good Leaderboards

<!-- XBL docs delta: 
As discussed in [Player Stats](player-stats_nav.md),  
-->
A leaderboard corresponds to a stat that you have defined.
You should choose leaderboards that correspond to an accomplishment that a player can work towards improving.

For example, Best Lap Time in a racing game is a good leaderboard, because players will want to work towards improving their Best Lap Time.
Other examples are Kill/Death ratio for shooters, or Max Combo Size in a fighting game.


## When to display Leaderboards

You have the ability to display leaderboards at any time in your title.
You should choose a time when a leaderboard will not interfere with the gameplay or the flow of your title.
In between rounds and after matches are both good times.


## How to display Leaderboards

There are numerous options for displaying leaderboards provided in the Xbox Live SDK.
<!-- XBL docs delta: 
If you are using Unity with the Xbox Live Creators Program, you can get started by using a Leaderboard Prefab to display your leaderboard data.
For specifics, see [Configure Xbox Live in Unity](../get-started/setup-ide/creators/unity-win10/configure-xbox-live-in-unity.md). 
-->

If you are coding against the Xbox Live SDK directly, then read on to learn about the APIs you can use.


## Programming guide

There are several Leaderboard APIs you can use to get the current state of a leaderboard.
All of the APIs are asynchronous and do not block.

You would make a request to get leaderboard data and continue your usual game processing.
When the leaderboard results are returned from the service, you can display the results at the appropriate time.

You should request the leaderboard data from the service, slightly ahead of when you want to display it, so that players are not blocked waiting for the leaderboard to display.

See:
* [Example code for event-based Leaderboards](how-to/live-eb-leaderboards-apis.md)
* [Xbox Live RESTful reference: Leaderboards URIs](https://docs.microsoft.com/gaming/xbox-live/xbox-live-rest/uri/leaderboard/atoc-reference-leaderboard) (external link to public docs)

<!-- 
Moved remainder of top half of article, starting w/ section "Leaderboards 2013 APIs", to APIs article
XBL docs delta: 2017 coverage, bottom 50% of article
-->
