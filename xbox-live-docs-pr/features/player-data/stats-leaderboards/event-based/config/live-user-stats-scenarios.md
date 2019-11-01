---
title: User Stats scenarios
description: Configuring event rules for several common User Stat scenarios.
kindex: Xbox Live stats scenarios
kindex: stats scenarios, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-user-stats-scenarios.html
---

# User Stats scenarios

<!-- from old portal "User Stats Scenarios" article; https://developer.microsoft.com/games/xbox/docs/xdk/user-stats-scenarios -->

The following are some common scenarios for creating user statistics, when using event-based Stats.

* [Using boolean values for conditions](#ubvfc)

* [Using counters for cumulative values](#ucfcv)

* [Tracking a Personal Best](#tapb)

* [Tracking the Most Recent](#ttmr)


<!-- ====================================================================== -->
<a id="ubvfc"></a>

## Using boolean values for conditions


### Goal: Track whether a particular condition has been met.

Use this pattern when you want to flag whether the user has met a specific condition in the game logic or not.


### Use cases:

* Flag if the user has died on a particular level

* Flag whether the user has unlocked each specific collectible

* Flag if the user is currently playing on hardcore difficulty

* Flag if the user has meet all five conditions to unlock a complex achievement


### Example: Flag if user got 90 kills with the shotgun or 10 kills with the sniper.

| Field | Value |
| --- | --- |
| Event Name | AchievementUnlocked |
| Event Fields | UnlockId (Data type: INT32) |
| Stat Template Name | AchievementUnlocked.UnlockId |
| Operator | REPLACE |
| Parameter | 1 |
| Access | Open |


### Rule

Apply the REPLACE operator with a literal value of “1” if the flag must be read as TRUE.

Apply the SUM operator with a literal value of “1” if the flag must be equal or greater than 1 to trigger the game logic.


### Traps

If necessary, remember to initialize or reset the value for REPLACE boolean stats; otherwise the most recently set value will be persisted.

In some cases it is convenient to define an event that allows resetting a Boolean stat to FALSE. in those cases, use a REPLACE operation with a literal value of “0”.


<!-- ====================================================================== -->
<a id="ucfcv"></a>

## Using counters for cumulative values


### Goal: Increment (or decrement) an all-time cumulative value for the user on a particular metric.

Use this pattern when you want to increment the stat value by a fixed or variable amount each time the event is processed.


### Use cases:

* Player level

* Total kills

* Number of videos uploaded

* Number of times user has played on each map

* Cumulative distance driving each vehicle type

* Current number of items in inventory


### Example: Counter of multiplayer matches won

| Field | Value |
| --- | --- |
| Event Name | MatchCompleted |
| Event Field 1 | Result (Data type: INT32) |
| Event Field 2 | Mode (Data type: UNICODE STRING) |
| Stat Template Name | MatchesCompleted.Result.Mode |
| Operator | SUM |
| Parameter | 1 |
| Access | Open |


### Rule

Apply the SUM operator to the corresponding event field, or specify a fixed constant value as the parameter.

In order to decrement the value of the stat use a negative value as the parameter, either as a fixed constant or as a run-time value in the event field.


### Traps

Do not use string datatype ‘literal’ values as parameters with the SUM operator.

Do not apply the SUM operator to a string datatype event field.

If you have multiple events updating the same stat, make sure that all the stat rules updating that stat use the same operator.


<!-- ====================================================================== -->
<a id="tapb"></a>

### Tracking a Personal Best


### Goal: Track the all-time “best” score for the user on a particular metric.

Use this pattern when you want to persist the largest (MAX) or smallest (MIN) record for the user and discard any values that don’t improve the user’s record.


### Use cases:

* Longest kill streak

* Fewest deaths on a multiplayer round

* Fastest time completing each race track

* Longest distance drive on every hole on any golf course.


### Example: Fastest time completing any track in the Europe set.

| Field | Value |
| --- | --- |
| Event Name | TrackCompleted |
| Event Field 1 | TrackSet (Data type: UNICODE STRING) |
| Event Field 2 | TimeInSeconds (Data type: INT32) |
| Stat Template Name | BestFinishTimeInSeconds.TrackSet |
| Operator | MIN |
| Parameter | TimeInSeconds |
| Access | Open |


### Rule

Apply the MAX or MIN operator to the corresponding event field.


### Traps

Do not use ‘literal’ values as parameters with the MAX or MIN operator.

Do not apply the MAX or MIN operator to a string datatype event field.

If you have multiple events updating the same stat, make sure that all the stat rules updating that stat use the same operator.


<!-- ====================================================================== -->
<a id="ttmr"></a>

## Tracking the Most Recent


### Goal: Track the most recent score posted by the user on a particular metric.

Use this pattern when you want to persist the latest record for the user regardless of whether the value improves the user’s best record or not.


### Use cases:

* Current difficulty

* Number of deaths on the current multiplayer round

* Top speed on the most recent race for each track

* Boolean flag for premium golf club currently equipped


### Example: Most recent completed time on any track

| Field | Value |
| --- | --- |
| Event Name | TrackCompleted |
| Event Field 1 | TrackId (Data type: INT32) |
| Event Field 2 | TimeInSeconds (Data type: INT32) |
| Stat Template Name | BestFinishTimeInSeconds.TrackId |
| Operator | REPLACE |
| Parameter | TimeInSeconds |
| Access | Open |


### Rule

Apply the REPLACE operator to the corresponding event field or literal value.


### Traps

If necessary, remember to initialize or reset the value for REPLACE stats; otherwise the most recently set value will be persisted.
