---
title: Event-based vs. title-managed Achievements
description: Title-managed Achievements is simpler than cloud-powered (event-based) Achievements, using direct calling, simple configuration, and local troubleshooting.
kindex: Event-based vs. title-managed Achievements
kindex: achievements
ms.topic: article
ms.assetid: d424db04-328d-470c-81d3-5d4b82cb792f
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Event-based vs. title-managed Achievements

Event-based Achievements was previously called "cloud-powered Achievements" or "Achievements 2013".

Title-managed Achievements was previously called "Achievements 2017".

Title-managed Achievements is simpler than event-based Achievements, using direct calling, simple configuration, and local troubleshooting.
The title-managed Achievements system enables game developers to use a direct-calling model to unlock achievements for new Xbox Live games on Xbox One (or later), Windows 10, Windows 10 Phone, Android, and iOS.


## Introduction

Xbox One originally used a Cloud-Powered (event-based) Achievements system that empowers game developers to drive the data for their Xbox Live capabilities, such as user stats, achievements, rich presence, and multiplayer, by simply sending in-game telemetry events. This opened up a multitude of benefits – a single event can update data for multiple Xbox Live features; Xbox Live configuration lives on the server instead of in the client; and much more.

In the years following the Xbox One launch, we have listened closely to game developer feedback, and developers have consistently shared the following:

1.  **Desire to unlock achievements via a direct calling pattern.**
    Many developers build games for various platforms, including previous versions of Xbox, and the achievement-like systems on those platforms use a direct calling method.
    Supporting direct unlock calls on Xbox One and other current-gen Xbox platforms would ease their cross-platform game development needs and development time costs.

2.  **Minimize configuration complexity.**
    With the Cloud-Powered (event-based) Achievements system, an achievement's unlock logic must be configured in Xbox Live so that the services know how to interpret the title's stats data and when to unlock the achievement for a user.
    This was done via a new, "Achievement Rules" section of an achievement's configuration that did not previously exist.
    While having unlock logic in the cloud can be quite powerful, this additional configuration requirement adds complexity into the design & creation of a title's achievements.

3.  **Difficult to troubleshoot.**
    While the Cloud-Powered (event-based) Achievements system introduces a variety of helpful capabilities, it can also be more difficult for game developers to validate and troubleshoot issues with their achievements since achievement unlocks are triggered indirectly by rules that live on the service rather than directly controlled by the game itself.

Game developers have also repeatedly shared feedback that they appreciate and value certain features that were introduced along with the Cloud-Powered (event-based) Achievements system:

1.  User experience features such as achievement progression, real-time updates, concept art rewards, and posting unlocks into activity feed.

2.  Configuration improvements such as a service config instead of a local config that must be included in the game package (such as gameconfig, XLAST, and SPA) and the ability to easily edit achievement strings and images after the game has shipped.

Title-managed Achievements is a replacement of the existing Cloud-Powered (event-based) Achievements system for future titles to use that makes it even easier for Xbox game developers to configure achievements, integrate achievement unlocks and updates into the game code, and validate that the achievements are working as expected.


## What's different with title-managed Achievements

| Feature | Title-managed Achievements | Event-based Achievements |
|--------------------------|---------------------------------------|----------------------------------------|
| Unlock Trigger           | Directly via API call                 | Indirectly via telemetry events        |
| Unlock Owner             | Title                                 | Xbox Live                              |
| Configuration            | Strings, images, rewards              | Strings, images, rewards, unlock rules  \[+ stats, +events\]                    |
| Progression              | Supported <br>*directly via API call*                | Supported <br> *indirectly via telemetry events*       |
| Real-Time Activity (RTA) | Supported                             | Supported                              |
| Challenges               | Not Supported   | Supported                      |


## Title requirements

The following are the requirements of any title that will use title-managed Achievements.

1.  **Must be a new (unreleased) title.** Titles that have already been released and are using the Cloud-Powered (event-based) Achievements system are ineligible. For more, see [Why can't existing titles "migrate" onto title-managed Achievements?](#_Why_cant_existing)

2.  **Must use August 2016 XDK or newer.**

3.  **Must be an XDK or UWP title.** Title-managed Achievements is not available for legacy platforms, including Xbox 360, Windows 8.x or older, nor Windows Phone 8 or older.


## Frequently asked questions


### <span id="_Why_are_Challenges" class="anchor"></span>Can I ship my title using title-managed Achievements yet?

Absolutely! All new titles are welcomed and encouraged to make use of title-managed Achievements in lieu of event-based Achievements.


### Why aren't Challenges supported in title-managed Achievements?

Usage data across Xbox games has shown that the current implementation and presentation of challenges does not fulfill a need for most game developers.
We will continue gathering developer input and feedback in this space and endeavor to deliver future features that are more on point with developer needs.



### Can I still add new achievements every calendar quarter if my title is using title-managed Achievements?

Yes. The Achievements policy is unchanged.


### <span id="_Why_cant_existing" class="anchor"></span>Why can't existing titles "migrate" onto title-managed Achievements?

For the vast majority of existing titles, a 'migration' to title-managed Achievements would not be limited to simply updating their service configurations and swapping out event writes for achievement unlock calls – although these changes alone would be very costly and would carry significant risk of error and unintended behavior that could result in the achievements being irreparably broken.
Rather, most existing titles also have users with existing data.

Attempting to convert a live game that is already using the Cloud-Powered (event-based) Achievements system would not only be a very costly effort, for both the developer and Xbox, but would significantly jeopardize existing users' profiles and/or game experiences.


### If my title was released using the Cloud-Powered (event-based) Achievements system, can any future DLC for the title switch to title-managed Achievements?

All achievements for a title must use the same Achievements system.
Whichever Achievements system is used by the base game's achievements is the system that must be used for all future achievements for the title.


### While testing achievements in my dev sandbox, can I mix-and-match between using title-managed Achievements and event-based Achievements?

No. All achievements for a title must use the same Achievements system.


### Does title-managed Achievements also include offline unlocks?

If the title unlocks an achievement while the device is offline, the API will automatically queue the offline unlock requests, and will auto-sync to Xbox Live when the device has reestablished network connectivity,similar to the current Cloud-Powered (event-based) Achievements system's offline experience.
Achievements unlocks will not occur while the user is offline.


### I see a new "AchievementUpdate" event in Partner Center. If my title uses that event, does that mean it has title-managed Achievements?

The *AchievementUpdate* base event is required by Xbox Live for backend purposes.
You can safely ignore this base event.

If your title configures an event using this base event type, those event writes will be ignored by Xbox Live.
Titles that are built on event-based Achievements should continue to configure their events by using the other base event types.
Titles that are built on title-managed Achievements need not configure *any* events for achievement purposes.
