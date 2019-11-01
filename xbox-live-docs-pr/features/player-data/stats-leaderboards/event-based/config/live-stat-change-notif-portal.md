---
title: Portal configuration of stat change notifications
description: Configuring stat change notifications.
kindex: Xbox Live stats
kindex: stats, Xbox Live
author: v-andrg
ms.author: v-andrg
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-stat-change-notif-portal.html
---

# Portal configuration of stat change notifications

<!-- article from old secure docs portal "Configure stat change notifications in Windows Dev Center" -->

**Note:** This article describes the features available only with proper permissions. For details, talk to your account manager or another contact at Microsoft.

This article describes the procedures for subscribing to stat change notifications in the Partner Center service configuration for a title that's using the event-based data platform.

Stat change notifications are issued by using the Real-Time Activity (RTA) feature. Because constantly polling the service for the value of a player stat is inefficient, RTA is used to notify a title when a subscribed stat value has changed.

For an introduction to service configuration, see [Xbox Live service configuration](https://docs.microsoft.com/gaming/xbox-live/xbox-live-service-configuration) (external link to public docs).

For info on RTA, see [Real-Time Activity Service](https://docs.microsoft.com/gaming/xbox-live/real-time-activity-service/real-time-activity-service_nav) (external link to public docs).
<!--
todo: 
link to local article instead
global search on: https://docs.microsoft.com/gaming/xbox-live/
-->

Sections in this article:
- [What is a stat change notification?](#what-is-a-stat-change-notification)
- [Configure stat change notifications](#configure-stat-change-notifications)
- [Enable stat change notifications](#enable-stat-change-notifications)
- [Modify stat change notifications](#modify-stat-change-notifications)
- [Delete a stat change notification](#delete-a-stat-change-notification)


<a id="what-is-a-stat-change-notification"></a>

## What is a stat change notification?

When a player stat is updated, it can be sent as a real-time update to any client subscribed to it. In this context, the user stat is considered an RTA. This reporting capability eliminates tracking and updating of your code and easily synchronizes this user statistic data across multiple screens.

Stat change notifications are especially useful in multiplayer games where a scoreboard tracks stats for each player and needs to be updated as quickly as possible.


<a id="configure-stat-change-notifications"></a>

## Configure stat change notifications

1. Sign in with your account on [Partner Center](https://developer.microsoft.com/dashboard/windows/overview).

1. Select your title, and go to **Services** > **Xbox Live**.

1. Click the link to **Stat change notifications**.

1. On the **Stat change notifications** page, enable stats for stat change notifications.

You must create player stats before you can enable them for stat change notifications.
For details, see [Portal configuration of event-based Stats](live-stats-eb-portal.md).


<a id="enable-stat-change-notifications"></a>

## Enable stat change notifications

1. Open the **Stat change notifications** page, which contains a list of any stats enabled for stat change notifications.

2. Click the drop-down box **Select a stat**, and select an existing stat to be registered for stat change notifications. You can also select **Create a new player stat**, which will open the **Events and stat rules** page in a new tab and will let you create a new player stat.

3. If you select a stat whose name contains fields, you must specify values for the fields.

4. When done adding the stat change notifications, click **Save** to save your changes, or click **Cancel** to discard them.

For your title to handle stat change notifications, you must add code to subscribe to the stat change notification by using the RTA service.
For more info, see [Programming the RTA service via C++ APIs](https://docs.microsoft.com/gaming/xbox-live/real-time-activity-service/programming-the-real-time-activity-service) (external link to public docs).


<a id="modify-stat-change-notifications"></a>

## Modify stat change notifications

> [!IMPORTANT]
> After a title passes Final Certification, existing real-time activities in that title can no longer be changed or deleted.

1. On the **Stat change notifications** page, click the stat instance that you want to change.

2. In the drop-down box, select the stat instance for which you want to change the notification. 

3. Click **Save** to save your changes, or click **Cancel** to discard them.


<a id="delete-a-stat-change-notification"></a>

## Delete a stat change notification

> [!IMPORTANT]
> After a title passes Final Certification, existing RTAs in that title can no longer be changed or deleted.

1. On the **Stat change notifications** page, click **Delete** next to the stat change notification that you want to remove.

2. Click **Save** to save your changes, or click **Cancel** to discard them.
