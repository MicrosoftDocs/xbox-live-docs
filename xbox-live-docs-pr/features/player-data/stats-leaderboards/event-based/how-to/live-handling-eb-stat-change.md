---
title: Handling an event-based stat change
description: Example code for handling an event-based stat change.
kindex: Handling an event-based stat change
kindex: stats, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.date: 11/22/2019
edited: 00/00/0000
ms.localizationpriority: medium
---

# Handling an event-based stat change

To get notifications about event-based stat changes, do the following:
1. [Add a Stat-changed handler](#ID4EM1)
2. [Subscribe to a specific stat change](#ID4EM2)

To clean up, do the following:
1. [Remove a Stat-changed handler](#ID4EM3)
2. [Unsubscribe from a specific stat change](#ID4EM4)


<a id="ID4EM1"></a>

## Adding a Stat-changed handler

Register an event handler for statistic change notifications.
The event handler will receive a `XblStatisticChangeEventArgs` object.

**C API**
<!-- XblUserStatisticsAddStatisticChangedHandler.md -->
```cpp
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

<!-- **Reference** -->
<!-- * [XblFunctionContext](xblfunctioncontext.md) -->
<!-- * [XblStatisticChangeEventArgs](xblstatisticchangeeventargs.md)
* [XblUserStatisticsAddStatisticChangedHandler](xbluserstatisticsaddstatisticchangedhandler.md) -->


<a id="ID4EM2"></a>

## Subscribing to a specific stat change

Subscribes to statistic update notifications via the `StatisticChanged` event.

**C API**
<!-- XblUserStatisticsSubscribeToStatisticChange.md -->
```cpp
XblRealTimeActivitySubscriptionHandle subscriptionHandle{ nullptr };

HRESULT hr = XblUserStatisticsSubscribeToStatisticChange(
    xboxLiveContext,
    xboxUserId,
    scid,
    statisticName.c_str(),
    &subscriptionHandle
);
```

<!-- **Reference** -->
<!-- * [XblRealTimeActivitySubscriptionHandle](xblrealtimeactivitysubscriptionhandle.md) -->
<!-- * [XblUserStatisticsSubscribeToStatisticChange](xbluserstatisticssubscribetostatisticchange.md) -->


<a id="ID4EM3"></a>

## Removing a Stat-changed handler

Removes an event handler for statistic change notifications.

**C API**
<!-- XblUserStatisticsRemoveStatisticChangedHandler.md -->
```cpp
XblUserStatisticsRemoveStatisticChangedHandler(
        xboxLiveContext,
        statisticChangedFunctionContext
);
```

<!-- **Reference**
* [XblUserStatisticsRemoveStatisticChangedHandler](xbluserstatisticsremovestatisticchangedhandler.md) -->


<a id="ID4EM4"></a>

## Unsubscribing from a specific stat change

Unsubscribes a previously created statistic change subscription.

**C API**
<!--  XblUserStatisticsUnsubscribeFromStatisticChange.md -->
```cpp
hr = XblUserStatisticsUnsubscribeFromStatisticChange(
    xboxLiveContext,
    statisticChangeSubscriptionHandle
);
```

<!-- **Reference**
* [XblUserStatisticsUnsubscribeFromStatisticChange](xbluserstatisticsunsubscribefromstatisticchange.md) -->
