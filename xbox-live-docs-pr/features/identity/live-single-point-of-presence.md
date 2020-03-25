---
title: Single Point of Presence (SPOP)
description: Ensures that a title is played on only a single device at a time.
kindex: Single Point of Presence (SPOP)
kindex: SPOP
ms.topic: article
ms.assetid: 40f19319-9ccc-4d35-85eb-4749c2cf5ef8
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Single Point of Presence (SPOP)

Single Point of Presence (SPOP) is an Xbox Live-enforced condition where a title can only be played on one device at a time.
This is enforced for Xbox One XDK and UWP titles on any device.

An Xbox Live title, regardless of the device it is on, can sign-out a user who is signed into a title on another Xbox One or Windows 10 device.


## How to handle SPOP

Single Point of Presence (SPOP) should be handled by the title the same way as any other type of sign-out event.
The user will always be notified via UI when they do an action that would initiate an SPOP sign-out event, to verify that the user wants the title to be disconnected on the other device.

* For XDK titles, the `User::SignOutCompleted` event will trigger when this occurs.

* For UWP titles, they will be notified of the sign out through the `sign_out_complete` handler from the `xbox_live_user` class.
  See [Authentication for UWP projects](auth/auth-uwp/live-auth-for-uwp-projects.md).
