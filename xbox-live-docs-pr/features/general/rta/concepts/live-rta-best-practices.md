---
title: Best Practices for the RTA service
description: Best practices for using the Real Time Activity (RTA) service.
kindex: Best Practices for the RTA service
kindex: RTA
ms.topic: article
ms.assetid: 543b78e3-d06b-4969-95db-2cb996a8bbd3
ms.localizationpriority: medium
author: mlamaute
ms.author: migreen
ms.date: 04/04/2017
---

# Best Practices for the RTA service

These best practices will help you make the most out of your title's use of the Real Time Activity (RTA) service.


## The Basics

RTA uses WebSocket sessions to create a persistent connection with the client.
That's how the service will deliver statistics to you.
A client needs to send an authenticated connection request, and RTA will use the token provided on the request to verify the connection can be made and then establish it.

Once the connection has been established, your app can make requests to subscribe to particular statistics.
On a successful subscription, RTA will return the current value and some additional metadata, like type of statistic, as part of the response payload.
Then, RTA will forward any updates that happen to the statistic while the client is subscribed.

When your title doesn't require real-time updates on a statistic, it should stop tracking that statistic.


## Disconnects

A title should be aware that when the authentication token for the user expires, the session will be terminated by the service.

RTA connections are closed after two hours by design, which will force the client to reconnect.
This is done because the auth token for the connection is cached to save on message bandwidth.
Eventually that token will expire.
By closing the connection and forcing the client to reconnect, the client is forced to refresh the auth token.
XSAPI will handle this for the title by proactively reconnecting to RTA and resubmitting subscriptions after 90 minutes.
A client could also get disconnected due to a user's ISP having issues or when the process for the title is suspended.

In each of these cases, if the title has registered for RTA connection state changed events, a disconnected event will be raised. Note that in general, no action from the title is required upon disconnection, but the title may want to update UI to reflect that RTA connectivity has been lost. XSAPI will automatically try to reestablish the WebSocket connection and will automatically maintain any existing Real-Time activity service subscriptions.

> [!WARNING]
> If a client uses RTA for multiplayer sessions, and is disconnected for thirty seconds, the Multiplayer Session Directory (MPSD) detects that the RTA session is closed, and kicks the user out of the session. XSAPI will automatically reestablish the RTA connection, but it is the responsibility of the title to rewrite their MPSD sessions once the RTA subscription has been reestablished. See also [Multiplayer Session Directory overview](../../../multiplayer/mpsd/live-mpsd-overview.md).

## Unsubscribing

Its not recommended to track statistics for which real-time updates aren't needed. 
Each tracked statistic corresponds to an RTA subscription, and the service limits the number of subscriptions a user can have per title at a given time.
If you are subscribing to everything and anything, you may hit that limit, and this may prevent subscription to some important statistics.
(For more information about subscription limits, see **Throttles**, below.)

For example, your title might only need updates for a statistic within a certain scene.
When the user enters that scene, your title should track that statistic.
When the user leaves that scene, your title should stop tracking the statistic.
Similarly, if statistics change notifications are no longer needed at all, removing all statistic change handlers will automatically cause XSAPI to tear down the related RTA subscriptions.

## Awareness of Latent Items in the Queue

When unsubscribing from a statistic, it's possible that there is an update for the statistic still in the process of reaching your client.
So, even if your title has just unsubscribed from a statistic, be aware that it may still get an update or two related to that statistic.

The recommendation is to ignore the updates for statistics when the subscription identifier is not recognized.


## Ignore Messages You do not Understand

It's possible that the message protocol will get updated.
To keep your app agnostic of any new messages, we recommend that your title simply discard unknown message types.


## Throttles

RTA enforces certain throttles on the service:
- UserStats: 1000
- Presence: 2500

If a client hits the throttling limit it will either receive an error as part of a subscribe/unsubscribe call, or it will be disconnected.
In either case, more information about the throttling limitation that was hit will be available to the client along with the error message or disconnect message.

When developing your title, keep these concepts in mind.
If you are doing something extreme, you may have a degraded app experience because the service could be throttling your calls.

In the current release, the service allows 1000 subscriptions to statistics per instance of an application.
Additionally, an instance of an application can also subscribe to a user's entire people list length for presence updates.
This number is being tuned, so it may change in future releases.
