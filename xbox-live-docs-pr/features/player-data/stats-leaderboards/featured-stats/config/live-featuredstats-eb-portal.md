---
title: Portal configuration of event-based Featured Stats
description: Configuring featured stats.
kindex: Portal configuration of event-based Featured Stats
kindex: event-based Featured Stats
kindex: Xbox Live, event-based Featured Stats
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-featuredstats-eb-portal.html
---

# Portal configuration of event-based Featured Stats

<!-- this article was copied from old secure portal docs "Configure featured stats in Windows Dev Center" -->

**Note:** This topic describes the features available only with proper permissions. For details, talk to your account manager or another contact at Microsoft.

This topic describes the procedures for adding and changing the featured stats in the Partner Center service configuration for a title. For an intro to the Xbox Live service configuration, see [Xbox Live service configuration](https://docs.microsoft.com/gaming/xbox-live/xbox-live-service-configuration).

Sections in this topic:

- [What is a featured stat?](#what-is-a-featured-stat)
- [Configure featured stats](#configure-featured-stats)
- [Create a featured stat](#create-a-featured-stat)
- [Reorder featured stats](#reorder-featured-stats)
- [Change a featured stat](#change-a-featured-stat)
- [Delete a featured stat](#delete-a-featured-stat)


<a id="what-is-a-featured-stat"></a>

## What is a featured stat?

A featured stat is a player stat displayed in various kinds of Xbox UI, most notably in a player's activity hub and in a player-to-player comparison of progress in the game.

For each title, you can select up to 20 of the title's most representative user stats. These custom-defined metrics are used to highlight a player's progress, compare it with the progress of other players, and drive players back into the game.

Each featured stat includes a localizable display name, a sort order, and a sequence number for prioritizing a set of featured stats.


<a id="configure-featured-stats"></a>

## Configure featured stats

1. Sign in with your account on [Partner Center](https://partner.microsoft.com/dashboard/windows/overview).

2. Select your title, and go to **Services** > **Xbox Live**.

3. Click the link to **Featured stats**.

4. Designate new featured stats, or reorder existing featured stats.


<a id="create-a-featured-stat"></a>

## Create a featured stat

You must create a stat rule before you can create a featured stat. For details, see [Portal configuration of event-based Stats](../../event-based/config/live-stats-eb-portal.md).

1. On the **Featured stats** page, click **New featured stat**.

2. In the box under **Display name**, provide a new, localizable display name for the featured stat. The maximum length of the string is 40 characters.

3. In the drop-down box under **Select a player stat to rank players with**, select the player stat instance to be featured. The stats should be easy to sort.

4. In the drop-down box under **Format**, select the format for the presented stat data: integer, decimal, percentage, short time-span, or long time-span.

    If you selected a short or long time-span, select the unit of time to be displayed: milliseconds, seconds, minutes, hours, or days.

5. Under **How should we aggregate this stat when comparing to other players?**, select from these three options:
   * Tier  
    A tiered level of achievement for a player's progress in the game

    * Best  
    The current best score a player has posted

    * Cumulative  
    An indication that this value can be added to other players' values in the calculation of the total cumulative value

6. Under **How should we sort this stat when comparing to other players?**, select from these two options:
    * Higher values are better
    * Lower values are better

7. Click **Save** to save the featured stat, or click **Cancel** to cancel it.


<a id="reorder-featured-stats"></a>

## Reorder featured stats

All titles automatically display three (3) built-in featured stats before any title-specific featured stats. The built-in stats are GamerScore, achievements earned, and time played.

By default, title-specific featured stats are ordered according to the sequence in which you create them. Each featured stat has an associated number that represents the stat's display order in the UI. Make sure that the most important and representative stats have lower order numbers, with 1 being the first featured stat displayed.

To change the order of the featured stats:

1. On the **Featured stats** page, click **Reorder featured stats**.

2. Change the value in the **Order** column. You can't assign the same number to more than one featured stat.

3. Click **Confirm**.


<a id="change-a-featured-stat"></a>

## Change a featured stat

1. On the **Featured stats** page, click the **Display name** of the featured stat you want to change.

2. Make the changes on the page that shows the details of the featured stat.

3. Click **Save**.


<a id="delete-a-featured-stat"></a>

## Delete a featured stat

> [!IMPORTANT]
> Deletion of a featured stat is permanent and irreversible.

1. On the **Featured stats** page, click **Delete** in the row of the featured stat you want to delete.

2. In the **Confirmation** dialog box, click **Delete**.
