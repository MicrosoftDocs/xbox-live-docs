---
title: Scenarios for creating event-based Achievements
description: Scenarios for creating event-based Achievements.
kindex: Scenarios for creating event-based Achievements
kindex: Xbox Live
author: KevinAsgari
ms.author: kevinasg
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
ms.assetid: f777aca3-0116-46d8-abdd-63a360649d86
ms.date: 04-04-2017
permalink: "en-us/games/xbox/docs/gxdk/live-achievements-eb-scenarios.html"
---

# Scenarios for creating event-based Achievements

>![](note.gif) **NOTE:** If you are currently using event-based Achievements (Achievements 2013) and want to continue using cross-progresssion, read this article; otherwise, we recommend using title-managed Achievements.

This article covers some common scenarios for creating achievements.

1. [AND/OR logic for multiple conditions](#scenario-1)
2. [Repeated actions](#scenario-2)
3. [Collection of actions](#scenario-3)
4. [Personal Best](#scenario-4)
5. [Binary value indicating conditions met](#scenario-5)


<div id='scenario-1'></div>

## AND/OR logic for multiple conditions ##

### Trap: AND logic for achievements ###
There are two common AND scenarios for achievements: synchronous AND, and asynchronous AND.

#### Asynchronous AND ####
This is an achievement that unlocks based on multiple criteria, where the user can fulfill each criterion independently of the other. For example: "Kill 10 zombies and 20 ghosts."

To define an achievement like this, configure multiple achievement rules on the achievement. An achievement unlocks only when ALL achievement rules have been met, and each can be met at separate points in time.

The achievement configuration for this is:

Field |  Value
--- | ---
**Rule #1 Name** | Kill 10 zombies
Stat(s) | Kills.EnemyType.Zombie
Action | SUM
Threshold | 10
**Rule #2 Name** | Kill 20 ghosts
Stat(s) | Kills.EnemyType.Ghost
Action | SUM
Threshold | 20

#### Synchronous AND ####
This is an achievement that unlocks based on multiple criteria, where the user must fulfill each criterion simultaneously. For example: "Kill 10 zombies with a bat while playing as Johnny."

**TRAP**: You might try using multiple achievement rules to capture each criterion. This will not work as you expect it to because each achievement rule can be met independently of one another. So, in the example below, the achievement would unlock if a user did the following:
* Monday: Play as Johnny and get 0 kills
* Tuesday: Play as Sam and get 10 zombie kills
* Friday: Play as Tim and get 5 skeleton kills using a bat

**BEST PRACTICE:** To define an achievement like this, you must define a stat rule that encompasses each criterion. Only events contain the full context of a user's activity - because you're communicating exactly what occurred within the game at that moment. Stats inherit from events and achievements inherit from stats, so the only way to persist any pertinent context such that the achievement is aware of it is to put it into a stat. The achievement unlocks only when the threshold is met via the specific stat instance containing the exact values you require. The configuration for this achievement is:

Field | Value
--- | ---
**Rule #1 Name** | Kill 10 zombies with a bat while playing as Johnny
Stat(s) | Kills.EnemyType.Zombie.WeaponType.Bat.PlayerCharacter.Johnny
Action | SUM
Threshold | 10

### Trap: OR logic for achievements ###
The most common OR scenario for achievements is to accomplish a particular goal in one of a few different, explicitly-enumerated possible means.

#### Reach this goal in this way OR that way ####
This is an achievement that unlocks based hitting a single goal in one way or another.

**BEST PRACTICE**
To define an achievement like this, configure a single achievement rule to be based on multiple stat instances, where each stat instance tracks an acceptable means.

**Using a MIN or MAX rule**
An example of this case is "Finish a race in under 3 minutes on Racetrack A, Racetrack B, or Racetrack F.". The achievement configuration for this is:

Field | Value
--- | ---
**Rule #1 Name** | Finish race in < 3 min on track A, B, or F
Stat(s) | <ul><li>FinishTimeInSeconds.TrackId.A</li><li>FinishTimeInSeconds.TrackId.B</li><li>FinishTimeInSeconds.TrackId.F</li></ul>
Action | MIN
Threshold | 180

Since this achievement rule uses a MIN rule action, the achievement will unlock when any of the listed stat instances fulfills the threshold. For example, if FinishTimeInSeconds.TrackId.A == 220, FinishTimeInSeconds.TrackId.B == 163, and FinishTimeInSeconds.TrackId.F == 199, then the achievement would unlock because the user had a finish time on racetrack B that outperformed the threshold.

#### Using a SUM rule ####
An example of this case is "Drive 1000 cumulative miles on Racetrack A, Racetrack B, or Racetrack F". The achievement configuration is:

Field | Value
--- | ---
**Rule #1 Name** | Drive 1000+ miles on racetracks A, B, or F
Stat(s) | <ul><li>MilesDriven.TrackId.A</li><li>MilesDriven.TrackId.B</li><li>MilesDriven.TrackId.F</li></ul>
Action | SUM
Threshold | 1000

Since this achievement rule uses a SUM rule action, the achievement will unlock when the aggregated combination of the listed stat instances fulfills the threshold. For example, if MilesDriven.TrackId.A == 900, MilesDriven.TrackId.B == 115, and MilesDriven.TrackId.F == 0, then the achievement would unlock because the user's aggregated total across all three stats outperformed the threshold.

#### Reach this goal OR that goal ####
A somewhat less common OR achievement scenario is to require the user to accomplish one of a few different goals. For example: "Finish a race in under 3 minutes on Racetrack A OR drive 1000 miles on Racetrack B".

**TRAP: This achievement scenario is not currently supported in the Achievements logic.** You might think you can accomplish this by defining multiple achievement rules, one for each goal, but remember that multiple rules on an achievement act as a logical AND -- each rule must be met in order for the achievement to unlock. Using one achievement rule for "finish a race in under 3 minutes on Racetrack A" and a second achievement rule for "drive 1000 miles on Racetrack B" will result in an achievement that only unlocks when the user fulfills both of those goals.


<div id='scenario-2'></div>

## Repeated actions ##

### Goal: Do this X times.  ###
Use this pattern to define an achievement that requires a user to repeat an action multiple times.

### Example 1: Win 50 multiplayer matches ###

Field | Value
--- | ---
**Rule Name** | Win 50 multiplayer matches
Stat(s) | MatchesCompleted.Result.1.Mode.Multiplayer
 Action | SUM
Threshold | 50

#### Example 2: Upload 10 videos and rate 100 videos ####

Field | Value
--- | ---
**Rule #1 Name** | Upload 10 videos
Stat(s) | VideosUploaded
 Action | SUM
Threshold | 10
**Rule #2 Name** | Rate 100 videos
Stat(s) | VideosRated
Action | SUM
Threshold | 100

To design the associated user statistic, see Using counters for cumulative values.


<div id='scenario-3'></div>

## Collection of actions ##

### Goal: Find X of Y items. ###
Use this pattern to define an achievement that requires a user to act on all (or a subset of) members in a specific set.

### Example 1: Complete all levels on Hardcore difficulty ###

Field | Value
--- | ---
**Rule #1 Name** | Complete level 1 on Hardcore
Stat(s) | LevelCompleted.Mode.3.LevelId.1
Action | SUM
Threshold | 1
**Rule #2 Name** | Complete level 2 on Hardcore
Stat(s) | LevelCompleted.Mode.3.LevelId.2
Action | SUM
Threshold | 1
**Rule #3 Name** | Complete level 3 on Hardcore
Stat(s) | LevelCompleted.Mode.3.LevelId.3
Action | SUM
Threshold | 1
**Rule #4 Name** | Complete level 4 on Hardcore
Stat(s) | LevelCompleted.Mode.3.LevelId.4
Action | SUM
Threshold | 1
**Rule #5 Name** | Complete level 5 on Hardcore
Stat(s) | LevelCompleted.Mode.3.LevelId.5
Action | SUM
Threshold | 1
**Rule #6 Name** | Complete level 6 on Hardcore
Stat(s) | LevelCompleted.Mode.3.LevelId.6
Action | SUM
Threshold | 1

### Example 2: Finish any of the Europe tracks in under 3 minutes ###
This can be done on one of two ways. Use either method 1 or method 2, but not both.

#### Method 1 ####

Field | Value
--- | ---
**Rule Name** | Finish any Europe track in less than 3 minutes
Stat(s) | <ul><li>LastFinishTimeInSeconds.TrackId.21</li><li>LastFinishTimeInSeconds.TrackId.22</li><li>LastFinishTimeInSeconds.TrackId.23</li><li>LastFinishTimeInSeconds.TrackId.24</li><li>LastFinishTimeInSeconds.TrackId.25</li><li>LastFinishTimeInSeconds.TrackId.26</li></ul>
Action | MIN
Threshold | 180

#### Method 2 ####

Field | Value
--- | ---
**Rule Name** | Finish any Europe track in less than 3 minutes
Stat(s) | BestFinishTimeInSeconds.TrackSet.Europe
Action | MIN
Threshold | 180

To design the associated user statistic, see Tracking the Most Recent and Tracking a Personal Best.


<div id='scenario-4'></div>

## Personal Best ##

#### Goal: Outperform the target in a single session or playthrough. ####
Use this pattern to define an achievement that requires a user to outperform the target in a single session or playthrough (i.e. not via aggregated effort).

#### Example 1: Complete the game with 5 or fewer deaths ####

Field | Value
--- | ---
**Rule Name** | Complete game with <= 5 deaths
Stat(s) | PlaythroughDeaths.GameResultId.1
Action | MIN
Threshold | 5

#### Example 2: Win a match having scored at least 50 points as Lebron James ####

Field | Value
--- | ---
**Rule Name** | Win match AND play as Lebron AND score 50+ pts
Stat(s) | BestScore.PlayerId.3056.MatchResultId.1
Action | SUM
Threshold | 10


<div id='scenario-5'></div>

## Binary value indicating conditions met ##

### Goal: Define an achievement that requires a user to do a complex activity that cannot be tracked easily via Xbox Live Stats or that is not otherwise supported by Xbox Live Achievements configuration options. ###
Use this pattern to define an achievement that requires a user to do a complex activity that cannot be tracked easily via Xbox Live Stats or that is not otherwise supported by Xbox Live Achievements configuration options.

### Example 1: Get 90 kills with shotgun or 10 kills with sniper ###

Field | Value
--- | ---
**Rule Name** | 90 shotgun kills OR 10 sniper kills
Stat(s) | AchievementUnlocked.UnlockId.9010
Action | SUM
Threshold | 1

>>**Important**
Note that this achievement configuration does NOT track either shotgun kills or sniper kills; it merely records the fact that one of those two conditions was met, and must be set by the title, as this scenario is NOT supported by the data platform.
