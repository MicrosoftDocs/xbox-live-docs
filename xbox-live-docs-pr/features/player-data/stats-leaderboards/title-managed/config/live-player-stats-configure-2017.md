---
title: Title-managed Featured Stats & Leaderboards portal config
description: Configuring title-managed Featured Stats and Leaderboards in Partner Center.
kindex: Title-managed Featured Stats & Leaderboards portal config
ms.topic: article
ms.assetid: e0f307d2-ea02-48ea-bcdf-828272a894d4
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Title-managed Featured Stats & Leaderboards portal config

<!-- 
This file was at path
leaderboards-and-stats-2017/player-stats-configure-2017.md
and has been orphaned for over a year.  sme compare the two articles in this dir. delete one?
-->

With player data, you only need to configure a stat in two cases:
* The stat is used as a basis for a global leaderboard, or
* The stat is a featured player stat that will be displayed on the game hub page.

In either case, you must configure Stats and leaderboards together.
Every leaderboard is based on a stat, and you cannot configure a stat without also configuring an associated global leaderboard, even if you do not plan to use a leaderboard for a featured player stat.

You do not need to configure Stats that are not featured player Stats, and are not used by a global leaderboard.


## Configure a global leaderboard and an associated player stat

First, go to the Player Stats section for your title as shown below.

![Partner Center Featured Stats and Leaderboards configuration screenshot](live-player-stats-configure-2017-images/dev_center_player_stats_creators.png)

Then click the `Create your first featured stat/leaderboard` button, and then fill out this dialog and click Save.

![Partner Center new leaderboard dialogue](live-player-stats-configure-2017-images/dev_center_player_stats_creators_leaderboard.png)

The `Display name` field is what users will see in the GameHub.

This string can be localized in the `Localize strings` section.
To see details on how to localize these strings, in the `Localize strings` section, click `Show Options`.

The `ID` field is the stat name and will be how you will refer to your stat when updating it from your title code.
For more detail, see [Updating title-managed Stats](../how-to/live-stats-tm-updating.md).

The `Format` is the data format of the stat.

The `Display Logic` offers the choice between `Player progression`, `Personal best`, and `Counter`:
- Player progression: Represents an individual player level or progression in the game.  The last value set is what users will see.  For example, position in current round.
- Personal Best: Represents the current best score a player has posted. The max or min value set depending on sort order is what users will see.  For example, fastest lap.
- Counter: Can be added to other player's to calculate a cumulative number.  

The `Sort` field lets you change the sort order of the leaderboard.

You can also choose to make this stat a `Featured Stat`, but clicking on `Feature on players' profiles`.


## Configure Featured Stats

When you define a player stat, you have the option of checking `Featured Stat`.
Note the following requirements:

| Developer Type | Requirement |
|----------------|-------------|
| Creators Program | There is no requirement to designate any Stats as Featured Stats. You are limited to a maximum of 10 Featured Stats.|
| Managed Partners | You must designate between 3 and 10 Featured Stats. |


## Next Steps

Next, update the stat from title code; see [Updating title-managed Stats](../how-to/live-stats-tm-updating.md).
