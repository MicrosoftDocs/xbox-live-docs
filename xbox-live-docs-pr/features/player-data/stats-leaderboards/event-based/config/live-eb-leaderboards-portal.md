---
title: Portal configuration of event-based Leaderboards
description: Configuring event-based Leaderboards at Partner Center.
kindex: Xbox Live Leaderboards
kindex: Leaderboards, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-eb-leaderboards-portal.html
---

# Portal configuration of event-based Leaderboards

<!-- 
from "Xbox One XDK" TOC: "Configure leaderboards in Windows Dev Center"
https://developer.microsoft.com/en-us/games/xbox/docs/xdk/windows-configure-leaderboards-2013
 -->

*Note:* This topic describes the features available only with proper permissions. For details, talk to your account manager or another contact at Microsoft.

This topic describes the procedures for configuring leaderboards in the Dev Center service configuration for a title that’s using event-based Stats.

<!-- 
= lb overview article:
For info on leaderboards that use data platform 2013, see Leaderboards. https://developer.microsoft.com/en-us/games/xbox/docs/xdk/leaderboards-2013 
-->

<!-- 
For an intro to the Xbox Live service configuration, see Xbox Live service configuration. https://docs.microsoft.com/en-us/windows/uwp/xbox-live/xbox-live-service-configuration 
-->


### What is a global leaderboard?

The Xbox Live Leaderboard service provides the capability for storing and retrieving global leaderboards for Xbox Live titles. Each leaderboard score is automatically updated by the Xbox data platform to reflect the appropriate values of the score’s underlying stat instances. Multiple leaderboards can be maintained for each title.


### Configure leaderboards, in general

1. Sign in with your account on Dev Center.

2. Select your title, and go to **Services** > **Xbox Live**.

3. Click the link to **Leaderboards**.

4. On the "Leaderboards" page, create and manage global leaderboards for your title.


### Create a leaderboard

1. On the "Leaderboards" page, click the **New leaderboard** button. This will take you to the "New leaderboard" page.

2. In the **Leaderboard name** field, provide your leaderboard’s name, which must not exceed 100 characters. The name won’t be visible to your players but can be used in your code to reference the leaderboard.

3. In the drop-down list **Player Stat to rank with**, select the stat on which the leaderboard is ranked. To create a new player stat, start by clicking **Create a new player stat**, which will open the "Events and stat rules" page in a new tab.

4. If you select a stat whose name contains fields, you must specify the values for the fields.

5. Under **Sort order**, select the applicable option in the dialog. Higher values are better is a good choice for stats like kill count and coins collected. Lower values are better is a good choice for stats like race times and least attempts at a level.

6. Click **Save** to save your changes.

Your new leaderboard is now listed on the "Leaderboards" page.


### Change a leaderboard

*Important:* There’s no support for changing or deleting a leaderboard that’s been published. This means you’ll have to create a new leaderboard with a different leaderboard ID. Changing the sort order or the underlying instance of a leaderboard’s stat might cause loss of data. Avoid reusing leaderboard IDs that have already been configured and published.

1. On the "Leaderboards" page, click the name of the leaderboard that you want to change.

2. Make your changes to the leaderboard’s details.

3. Click **Save** to save your changes.


### Delete a leaderboard

*Important:* There’s no support for changing or deleting a leaderboard that’s been published. This means you’ll have to create a new leaderboard with a different leaderboard ID. Changing the sort order or the underlying instance of a leaderboard’s stat might cause loss of data. Avoid reusing leaderboard IDs that have already been configured and published.

1. On the "Leaderboards" page, click **Delete** next to the leaderboard that you want to delete.

2. In the "Confirmation" dialog, click **Delete** to confirm the deletion.
