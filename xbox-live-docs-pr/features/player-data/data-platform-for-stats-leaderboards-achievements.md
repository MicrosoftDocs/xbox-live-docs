---
title: "Player Data: Stats, Leaderboards, and Achievements"
description: Player Data includes achievements, player stats, and leaderboards.
author: KevinAsgari
ms.assetid: a8bb7c4f-09fe-4dba-b3ce-1fab60453831
ms.author: kevinasg
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, stats, achievements, leaderboards, player data
ms.localizationpriority: medium
---

# Player Data: Stats, Leaderboards, and Achievements

Writing game data to Xbox Live Player Data enables your title to run as a service.
Additionally, Player Data drives user engagement with your title using stats, leaderboards, and achievements, and surfaces featured stats in the console shell and Xbox App.


## Stats and Leaderboards

One example of a stat for a racing game might be "Total races run in drag strip mode".
This stat can be used to create a leaderboard to compare your score against the community, and can be reflected in your Rich Presence string in real time (for example, "GoTeamEmily is playing Drag Strip Mode: 523 races completed").
The stat "Total races in drag strip mode" could also be used as a criterion for Matchmaking, so players with similar experience are more likely to be matched together.

Your title can display leaderboards based on player stats.
For example, the leaderboard could be a global ranking of races completed.
You call these services using the Xbox Live APIs directly, or wrappers in a game engine such as Unity.

See [Stats & Leaderboards](stats-leaderboards/live-stats-leaderboards-nav.md).


## Featured stats

You can designate certain stats as featured stats.
Featured stats are shown in your title's GameHub, to compare players against their friends.


## Achievements

Achievements are not powered by stats, and your title decides when an achievement is unlocked.
For example, your title might have an achievement for completing a race in under a minute.
Your title keeps track of the parameters needed to unlock the achievement.

In this example, it would be up to your title to measure how long the race took, and then award the achievement.
Typically, Gamerscore is awarded along with the completion of achievements.
It is up to you to decide the amount of Gamerscore for each achievement.

See [Achievements](achievements/live-achievements-nav.md).
