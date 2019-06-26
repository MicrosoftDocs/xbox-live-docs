---
title: Achievements 2017
description: Achievements 2017 is simpler than cloud-powered achievements, using direct calling, simple configuration, and local troubleshooting.
ms.assetid: d424db04-328d-470c-81d3-5d4b82cb792f
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one
ms.localizationpriority: medium
---

# Achievements 2017

Achievements 2017 is simpler than cloud-powered achievements, using direct calling, simple configuration, and local troubleshooting.
The Achievements 2017 system enables game developers to use a direct-calling model to unlock achievements for new Xbox Live games on Xbox One, Windows 10, Windows 10 Phone, Android, and iOS.


## Introduction

Xbox One originally used a Cloud-Powered Achievements system that empowers game developers to drive the data for their Xbox Live capabilities, such as user stats, achievements, rich presence, and multiplayer, by simply sending in-game telemetry events. This opened up a multitude of benefits – a single event can update data for multiple Xbox Live features; Xbox Live configuration lives on the server instead of in the client; and much more.

In the years following the Xbox One launch, we have listened closely to game developer feedback, and developers have consistently shared the following:

1.  **Desire to unlock achievements via a direct calling pattern.**
    Many developers build games for various platforms, including previous versions of Xbox, and the achievement-like systems on those platforms use a direct calling method.
    Supporting direct unlock calls on Xbox One and other current-gen Xbox platforms would ease their cross-platform game development needs and development time costs.

2.  **Minimize configuration complexity.**
    With the Cloud-Powered Achievements system, an achievement’s unlock logic must be configured in Xbox Live so that the services know how to interpret the title’s stats data and when to unlock the achievement for a user. 
    This was done via a new, "Achievement Rules" section of an achievement’s configuration that did not previously exist.
    While having unlock logic in the cloud can be quite powerful, this additional configuration requirement adds complexity into the design & creation of a title’s achievements.

3.  **Difficult to troubleshoot.**
    While the Cloud-Powered Achievements system introduces a variety of helpful capabilities, it can also be more difficult for game developers to validate and troubleshoot issues with their achievements since achievement unlocks are triggered indirectly by rules that live on the service rather than directly controlled by the game itself.

Game developers have also repeatedly shared feedback that they appreciate and value certain features that were introduced along with the Cloud-Powered Achievements system:

1.  User experience features such as achievement progression, real-time updates, concept art rewards, and posting unlocks into activity feed.

2.  Configuration improvements such as a service config instead of a local config that must be included in the game package (such as gameconfig, XLAST, and SPA) and the ability to easily edit achievement strings and images after the game has shipped.

Achievements 2017 is a replacement of the existing Cloud-Powered Achievements system for future titles to use that makes it even easier for Xbox game developers to configure achievements, integrate achievement unlocks and updates into the game code, and validate that the achievements are working as expected.


## What’s different with Achievements 2017

| Feature | Achievements 2017 system | Cloud-powered Achievements system |
|--------------------------|---------------------------------------|----------------------------------------|
| Unlock Trigger           | Directly via API call                 | Indirectly via telemetry events        |
| Unlock Owner             | Title                                 | Xbox Live                              |
| Configuration            | Strings, images, rewards              | Strings, images, rewards, unlock rules  \[+ stats, +events\]                    |
| Progression              | Supported <br>*directly via API call*                | Supported <br> *indirectly via telemetry events*       |
| Real-Time Activity (RTA) | Supported                             | Supported                              |
| Challenges               | Not Supported   | Supported                      |


## Title requirements

The following are the requirements of any title that will use the Achievements 2017 system.

1.  **Must be a new (unreleased) title.** Titles that have already been released and are using the Cloud-Powered Achievements system are ineligible. For more, see [Why can’t existing titles “migrate” onto the new Achievements 2017 system?](#_Why_cant_existing)

2.  **Must use August 2016 XDK or newer.**

3.  **Must be an XDK or UWP title.** The Achievements 2017 system is not available for legacy platforms, including Xbox 360, Windows 8.x or older, nor Windows Phone 8 or older.


## Frequently asked questions


### <span id="_Why_are_Challenges" class="anchor"></span>Can I ship my title using the Achievements 2017 system yet?

Absolutely! All new titles are welcomed and encouraged to make use of the Achievements 2017 system in lieu of the Cloud-Powered Achievements system.


### Why aren't Challenges supported in the Achievements 2017 system?

Usage data across Xbox games has shown that the current implementation and presentation of challenges does not fulfill a need for most game developers.
We will continue gathering developer input and feedback in this space and endeavor to deliver future features that are more on point with developer needs.
Xbox Arena is an example of a feature that introduces competitive capabilities for Xbox games in a new, but similar, direction.



### Can I still add new achievements every calendar quarter if my title is using the Achievements 2017 system?

Yes. The Achievements policy is unchanged.


### <span id="_Why_cant_existing" class="anchor"></span>Why can’t existing titles “migrate” onto the new Achievements 2017 system?

For the vast majority of existing titles, a ‘migration’ to the Achievements 2017 system would not be limited to simply updating their service configurations and swapping out event writes for achievement unlock calls – although these changes alone would be very costly and would carry significant risk of error and unintended behavior that could result in the achievements being irreparably broken.
Rather, most existing titles also have users with existing data.

Attempting to convert a live game that is already using the Cloud-Powered Achievements system would not only be a very costly effort, for both the developer and Xbox, but would significantly jeopardize existing users’ profiles and/or game experiences.


### If my title was released using the Cloud-Powered Achievements system, can any future DLC for the title switch to Achievements 2017?

All achievements for a title must use the same Achievements system.
Whichever Achievements system is used by the base game’s achievements is the system that must be used for all future achievements for the title.


### While testing achievements in my dev sandbox, can I mix-and-match between using the Achievements 2017 system and the Cloud-Powered Achievements system?

No. All achievements for a title must use the same Achievements system.


### Does Achievements 2017 also include offline unlocks?

If the title unlocks an achievement while the device is offline, the API will automatically queue the offline unlock requests, and will auto-sync to Xbox Live when the device has reestablished network connectivity,similar to the current Cloud-Powered Achievements system’s offline experience.
Achievements unlocks will not occur while the user is offline.


### I see a new "AchievementUpdate" event in Partner Center. If my title uses that event, does that mean it has Achievements 2017?

The *AchievementUpdate* base event is required by Xbox Live for backend purposes.
You can safely ignore this base event.

If your title configures an event using this base event type, those event writes will be ignored by Xbox Live.
Titles that are built on the Cloud-Powered Achievements system should continue to configure their events by using the other base event types.
Titles that are built on the Achievements 2017 system need not configure *any* events for achievement purposes.


## Getting the Achievements List

To get the achievements for the running title, call **XblAchievementsGetAchievementsForTitleIdAsync**, as follows.


### Calling XblAchievementsGetAchievementsForTitleIdAsync

[!INCLUDE [Achievements_GetAchievementsForTitle](../code/snippets/Achievements_GetAchievementsForTitle.md)]


### Callback for XblAchievementsGetAchievementsForTitleIdAsync

[!INCLUDE [Achievements_GetAchievementsForTitle_Callback](../code/snippets/Achievements_GetAchievementsForTitle_Callback.md)]


## Getting the next page of Achievements results

To get the next page of Achievements, call **XblAchievementsResultGetNextAsync**, as follows.

### Calling XblAchievementsResultGetNextAsync

[!INCLUDE [Achievements_GetNextResultsPage](../code/snippets/Achievements_GetNextResultsPage.md)]


### Callback for XblAchievementsResultGetNextAsync

[!INCLUDE [Achievements_GetNextResultsPage_Callback](../code/snippets/Achievements_GetNextResultsPage_Callback.md)]



## Getting a single Achievement

To get a single Achievement, call **XblAchievementsGetAchievementAsync**, as follows.


### Calling XblAchievementsGetAchievementAsync

[!INCLUDE [Achievements_GetAchievement](../code/snippets/Achievements_GetAchievement.md)]


### Callback for XblAchievementsGetAchievementAsync

[!INCLUDE [Achievements_GetAchievement_Callback](../code/snippets/Achievements_GetAchievement_Callback.md)]


## Unlocking an achievement

Once your achievements are configured via Partner Center and published to your dev sandbox, your title can unlock them by calling **XblAchievementsUpdateAchievementAsync**.

See also [Configuring Achievements 2017 in Partner Center](../configure-xbl/dev-center/achievements-in-udc.md).

To unlock an achievement, set the *percentComplete* argument of **XblAchievementsUpdateAchievementAsync**, shown below, to 100.

If the user is online, the request will be immediately sent to the Xbox Live Achievements service and will trigger the following user experiences:

-   The user will receive an Achievement Unlocked notification;

-   The specified achievement will appear as Unlocked in the user’s achievement list for the title;

-   The unlocked achievement will be added to the user’s activity feed.

> *Note: There will be no visible difference in user experiences for achievements that use the Achievements 2017 system and the Cloud-Powered Achievements.*

If the user is offline, the unlock request will be queued locally on the user’s device. When the user’s device has reestablished network connectivity, the request will automatically be sent to the Achievements service – note: no action is required from the game to trigger this – and the above user experiences will occur as described.


## Updating completion progress for an Achievement

To update a user’s progress toward unlocking an achievement, set the *percentComplete* argument of **XblAchievementsUpdateAchievementAsync**, shown below, to the appropriate whole number between 1-100.

An achievement’s progress can only increase. If *percentComplete* is set to a number less than the achievement’s last *percentComplete* value, the update will be ignored. For example, if the achievement’s *percentComplete* had previously been set to 75, sending an update with a value of 25 will be ignored and the achievement will still be displayed as 75% complete.

If *percentComplete* is set to 100, the achievement will unlock.

If *percentComplete* is set to a number greater than 100, the API will behave as if you set it to exactly 100.


### Calling XblAchievementsUpdateAchievementAsync

[!INCLUDE [Achievements_UpdateAchievement](../code/snippets/Achievements_UpdateAchievement.md)]


### Callback for XblAchievementsUpdateAchievementAsync

[!INCLUDE [Achievements_UpdateAchievement_Callback](../code/snippets/Achievements_UpdateAchievement_Callback.md)]
