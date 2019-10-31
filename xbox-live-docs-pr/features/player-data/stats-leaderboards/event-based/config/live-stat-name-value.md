---
title: Adding a field value to a stat rule
description: Usually you should add a field name, rather than a field value, to a stat rule.
kindex: Xbox Live stat rules
kindex: stat rules, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-stat-name-value.html
---

# Adding a field value to a stat rule

<!-- this article is based on email 2019-07-19 -->
Usually you should add a field name, rather than a field value, to a stat rule.


## The event value is added to the stat name

Stat templates are powerful and flexible, but can sometimes produce unintended results if not properly configured.

Not only are event _names_ added to the stat name, but the event _values_ are as well, and that can often produce confusion and unintended outcomes.

Stat templates create variable stat paths, or stat instances.

Stat templates result in stat names based on variables that are derived from the name _and value_ of selected fields in the source event.
This is how you might capture something like _how much_ gold a player earned in each map.


## Example

Suppose your game sends an event named `GameEnd`, which has an `int` field named `Map` and an `int` field named `Gold`.

To capture the high score by map using a single stat rule, you’d give the stat a name, such as `GoldByMap`, and add a `Map` field to the stat rule. In this example, the `Map` value is a numeric ID.
<!-- Is Map a field on a stat rule, or is Map a stat rule? -->

Your parameter (the field that contains the value you want to increment the stat by) would be the `Gold` field on the `GameEnd` event.
<!-- 
How do you add or set or equate the Gold field, or field value, to the stat path? 
GoldByMap.Map.1 = ${GameEnd.Gold}  ?
-->

Suppose your game sends a `GameEnd` event to the Xbox Live service, and the event's `Map` field value is 1, and the `Gold` field value is 100.
The result is that the stat is written to the stat path `GoldByMap.Map.1`, and the new value for that stat path is 100.

Here's what we have so far:

| Item | Type | Notes |
| --- | --- | --- |
| `GameEnd` | An event | Sent by your game to the Xbox Live service. |
| `Map` | A field on the event | An `int`. |
| 1 | `int` | The value of the `Map` field. |
| `Gold` | A field on the event | An `int`. |
| 100 | `int` | The value of the `Gold` field. |

The stat path has the following parts:

| Item | Type | Notes |
| --- | --- | --- |
| `GoldByMap.Map.1` | A stat path | The value of this stat path is 100. |
| `GoldByMap` | A stat name |  |
| `Map` | A stat rule | A numeric ID. |

If the next event comes in with `Map` value of 2, the `Gold` field from that event is added to that new stat path, which is: `GoldByMap.Map.2`

Suppose that `Gold` field on the event has the value 200.
We would now also have:

| Item | Type | Notes |
| --- | --- | --- |
| `GoldByMap.Map.2` | A stat path | The value of this stat path is 200. |

This way, you can keep stats values separate, without needing to define a stat for every `Map`.


## Example of mistakenly adding a field name rather than a field value to the stat rule

Starting with the example above, let's see what bad result happens when you also add the `Gold` field name to the `Map` stat rule, instead of adding just the `Gold` parameter value.

This would result in the following stat name: `GoldByMap.Map.1.Gold.100`

Notice that the value of the gold earned by the user (100) is also in the name of the stat.
This means that a user earning 100 gold on Map 1 will get a value of 100 for this stat: `GoldByMap.Map.1.Gold.100`

If a user earned 101 gold on that map, this configuration results in the following, which is a different stat name: `GoldByMap.Map.1.Gold.101`

The result is that these stats would only increment whenever the player earns the specific amount of gold defined in the stat name, which is probably not what was intended.
