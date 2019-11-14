---
title: Event-based Stat rules overview
description: Each stat rule is triggered by a specific event name logged by the title.
kindex: Event-based Stat rules overview
kindex: stats, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-user-stat-rules.html
---

# Event-based Stat rules overview

<!-- from old portal "User Stat Rules" article; https://developer.microsoft.com/games/xbox/docs/xdk/user-stats-rules -->

<!-- todo: what does a rule accomplish? -->

Stat rules are used for event-based Stats, not for title-managed Stats.

Each stat rule consists of four parts: the producer event, the name, an operator, and a parameter.


## Event

Each stat rule will be triggered by a specific event name logged by the title. Note that multiple stat rules may be triggered by a single event.


## Naming requirements

* A rule name is composed of a “root” name; optionally followed by one or more “fields”.

* The “root” is an alphanumeric string (of up to 32 characters).

* The total length of the stat instance name must not exceed 128 characters.

* The name must start with a letter character and must only contain letters, numbers and the hyphen character. No spaces, commas, periods, underscore or any other special character is allowed. Example names are: “EnemiesDefeated”, “BestScoreUnder2Minutes”, “Total-Collectibles-Jewels”.

* Fields are separated by the dot character.

* Field names must exactly match the field names that are part of the producer EVENT.

> ![](live-user-stat-rules-images/note.gif)**Important** When one or more fields are included as part of the statistic rule name, this rule becomes a stat template. At run-time, the actual value of fields from the producer event will be inserted into the stat instance name.

* Some sample valid template names are “EnemiesDefeated.WeaponID”, “BestScoreUnder2Minutes.TrackId.DifficultyID”, and “Total-Collectibles-Jewels.Found”.

* Some sample valid instance names are “EnemiesDefeated.WeaponID.17”, “BestScoreUnder2Minutes.TrackId.40.DifficultyID.Insane”, and “Total-Collectibles-Jewels.Found.1”.


## Data type recommendations

* It is recommended to use integer data type for event fields that are part of a stat template name.

* If the event field data type is Boolean, the value inserted will be “1” for true, and “0” for false.

* If the event field data type is Unicode string, the developer must ensure that the potential values for that field contain only valid characters (see above).


## Operator

The value of the stat instance is calculated at run-time when processing the producer event. The stat rule executes an OPERATION with the specified PARAMETER. The list of supported operation options is:
* SUM
* MAX
* MIN
* REPLACE


## Parameter

The parameter can be either a constant value or a field name from the producing event.

| Operator | Parameter |
| --- | --- |
| SUM | Constant or field |
| MIN | Field |
| MAX | Field |
| REPLACE | Constant or field |

The data type of the resulting stat instance is determined by the parameter’s data type.

**Integer**, **Float**, and **Boolean** data types supported by all operators.

The **Unicode string** data type is supported only by the REPLACE operator.

| Stat Data Type | Parameter Data Type | Notes |
| --- | --- |
| Integer | Int32, Int64, UInt32, UInt64, Boolean | The largest integer value supported is 56-bit. Boolean is converted from TRUE to 1, and FALSE to 0. |
| Float | Float, Double | 64-bit float |
| String | UnicodeString, GUID | The maximum string length is 50 characters. |
