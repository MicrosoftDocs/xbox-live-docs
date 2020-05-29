---
title: Programming the RTA service
description: Example code for calling the Real-Time Activity Service.
kindex: Programming the RTA service
kindex: RTA
ms.topic: article
ms.localizationpriority: medium
ms.assetid: 98cdcb1f-41d8-43db-98fc-6647755d3b17
author: mlamaute
ms.author: migreen
ms.date: 04/04/2017
---

# Programming the RTA service

This article contains the following sections:
* [Connecting to the Real-Time Activity Service from Xbox Live](#connecting-to-the-real-time-activity-service-from-xbox-live)
* [Creating a statistic](#creating-a-statistic)
* [Disconnecting from the Real-Time Activity service](#disconnecting-from-the-real-time-activity-service)
* [Subscribing to a statistic from the Real-Time Activity service](#subscribing-to-a-statistic-from-the-real-time-activity-service)
* [Unsubscribing from a statistic from the Real-Time Activity service](#unsubscribing-from-a-statistic-from-the-real-time-activity-service)


## Connecting to the Real-Time Activity Service from Xbox Live

Applications must connect to the Real-Time Activity (RTA) service to get event information from Xbox Live.

> [!NOTE]
> The examples used in this article indicate method calls for one user. However, your title must make these calls for all users to connect to and disconnect from the Real-Time Activity (RTA) service.

**C API**
<!-- XblRealTimeActivityActivate.md --> 
```cpp
HRESULT hr = XblRealTimeActivityActivate(xboxLiveContext);
```

## Disconnecting from the Real-Time Activity service

**C API**
<!-- XblRealTimeActivityDeactivate.md --> 
```cpp
HRESULT hr = XblRealTimeActivityDeactivate(xboxLiveContext);
```

## Subscribing to a statistic from the Real-Time Activity service

You define your stats and configure them for RTA in [Partner Center](https://partner.microsoft.com/dashboard).
See [Configuring title-managed Featured Stats & Leaderboards in Partner Center](../../../player-data/stats-leaderboards/title-managed/config/live-tm-leaderboards-portal.md).
See [Registering for player Stat change notifications](../concepts/live-register-for-stat-notifications.md).

> [!NOTE]
> An event-based Stats developer will need to contact their DAM for information about portal configuration of event-based Stats in [Partner Center](https://partner.microsoft.com/dashboard). Secure docs portal: [Configure Xbox Live stats and stat rules in Partner Center](https://developer.microsoft.com/games/xbox/docs/xdk/windows-configure-stats-2013).

Applications subscribe to a Real-Time Activity (RTA) to get updates when the statistics configured in Partner Center change.

**C API**
<!-- DocsSubscribeToStatisticChange.md -->
```cpp
// Subscribe for statistic change events
std::string statisticName = "totalPuzzlesSolved";
XblRealTimeActivitySubscriptionHandle subscriptionHandle{ nullptr };
HRESULT hr = XblUserStatisticsSubscribeToStatisticChange(
    xblContextHandle,
    xboxUserId,
    scid,
    statisticName.c_str(),
    &subscriptionHandle
);

// Add a statistic changed handler
void* context{ nullptr };
XblFunctionContext statisticChangedFunctionContext = XblUserStatisticsAddStatisticChangedHandler(
    xboxLiveContext,
    [](XblStatisticChangeEventArgs eventArgs, void* context)
    {
        // Handle stat change 
        LogToScreen("Statistic changed callback: stat changed (%s = %s)",
            eventArgs.latestStatistic.statisticName,
            eventArgs.latestStatistic.value);
    },
    context
    );
```


## Unsubscribing from a statistic from the Real-Time Activity service

Applications subscribe to a statistic from the Real-Time Activity (RTA) service to get updates when the statistic changes.
When these updates are no longer needed, the subscription can be terminated, as follows.

**C API**
<!-- DocsUnsubscribeFromStatisticChange.md -->
```cpp
// Remove the statistic changed handler
XblUserStatisticsRemoveStatisticChangedHandler(
    xblContextHandle,
    statisticChangedFunctionContext
);

// Unsubscribe for statistic change events
HRESULT hr = XblUserStatisticsUnsubscribeFromStatisticChange(
    xboxLiveContext,
    statisticChangeSubscriptionHandle
);
```

> [!IMPORTANT]
> The Real-Time Activity service will disconnect after two hours of use, your code must be able to detect this and re-establish a connection to the Real-Time Activity service if it is still needed. This is done primarily to ensure that auth tokens are refreshed upon expiration. XSAPI will handle this for the title by proactively reconnecting to RTA and resubmitting subscriptions after 90 minutes.
> 
> If a client uses RTA for multiplayer sessions, and is disconnected for thirty seconds, the Multiplayer Session Directory (MPSD) detects that the RTA session is closed, and kicks the user out of the session. It's up to the RTA client to detect when the connection is closed and initiate a reconnect and resubscribe before MPSD ends the session.
