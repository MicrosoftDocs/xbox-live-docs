---
title: Privacy and Permissions overview
description: The Xbox Live Privacy service protects users by respecting their preferences and providing the social experiences they want.
kindex: Privacy and Permissions overview
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xbox
ms.technology: xboxgc
ms.localizationpriority: medium
edited: 00/00/0000
security: linked
---

# Privacy and Permissions overview

The Xbox Live Privacy service protects users by respecting their preferences and providing the social experiences they want.
The Privacy service supports permission checking, Mute lists, and Avoid lists through both an XSAPI API and a REST API.

The Privacy service does not let you get or set a user's Privacy setting.


## Permission checking

Permission checks are the primary capability provided by the Privacy service.
These checks function by determining whether a given user can perform an action with another user (or users).

For example, if you ask "Can the user can communicate with the target?", the Privacy service bases its answer on the range of relevant criteria, such as:
* Do both users' settings permit this scenario?
* What is the relationship between the users?
* Is the actor on the target's Avoid list?


## Mute list

The Privacy service also enables a game to retrieve a user's Mute list.
A Mute list specifies up to 250 users that the list owner doesn't want to hear from via voice communication.
The Mute list controls voice communication, and doesn't affect text communication.

All relevant permission checks incorporate Mute lists, so you don't need to check Mute lists in addition to checking other permissions.
For example, if Permissions is asked "Can the user voice-chat with another user?", the Privacy service will check the user's Mute list as part of the permission check, so your code doesn't need to also check the Mute list.
However, you might find some scenarios where it's helpful to retrieve a Mute list.

Games are not allowed to add people to a given user's Mute list.


## Avoid list

The Privacy service also gives you the ability to get a user's Avoid list, which holds up to 1,000 Xbox Live users that the owner has blocked to prevent communication in any form, such as voice, text, game invites, or club invites.
There may be some scenarios where retrieving the Avoid list is valuable, but checking the Avoid list is also part of all relevant permission checks, so checking the Avoid list in addition is not required.

For example, in a scenario where Permissions is asked, "Can the user send a text message to this other user?", the Privacy service consults the Avoid lists as part of the permission check, so there's no need to check the Avoid list in addition.

Games are not allowed to add people to a user's Avoid list.
