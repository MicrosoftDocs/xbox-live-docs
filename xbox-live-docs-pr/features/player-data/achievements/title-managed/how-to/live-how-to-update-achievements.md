---
title: Updating Achievements
description: Example code for updating title-managed Achievements.
kindex: Updating Achievements
author: XBL
ms.author: v-jasch
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
ms.date: 09/23/2019
ms.localizationpriority: medium
---

# Updating Achievements

**Contents:**
* Unlocking an Achievement
* Updating an Achievement


## Unlocking an Achievement

Once your achievements are configured via Partner Center and published to your dev sandbox, your title can unlock them by calling **XblAchievementsUpdateAchievementAsync**.

See also [Title-managed Achievements portal config](../config/live-achievements-tm-config.md).

To unlock an achievement, set the *percentComplete* argument of **XblAchievementsUpdateAchievementAsync** to 100.

If the user is online, the request will be immediately sent to the Xbox Live Achievements service and will trigger the following user experiences:

-   The user will receive an Achievement Unlocked notification.

-   The specified achievement will appear as Unlocked in the user’s achievement list for the title.

-   The unlocked achievement will be added to the user’s activity feed.

> *Note: There will be no visible difference in user experiences for achievements that use title-managed Achievements and Cloud-Powered (event-based) Achievements.*

If the user is offline, the unlock request will be queued locally on the user’s device. When the user’s device has reestablished network connectivity, the request will automatically be sent to the Achievements service – note: no action is required from the game to trigger this – and the above user experiences will occur as described.

The code in the next section shows how to call **XblAchievementsUpdateAchievementAsync**.


## Updating completion progress for an Achievement

To update a user’s progress toward unlocking an achievement, set the *percentComplete* argument of **XblAchievementsUpdateAchievementAsync** to the appropriate whole number between 1-100.

An achievement’s progress can only increase.
If *percentComplete* is set to a number less than the achievement’s last *percentComplete* value, the update will be ignored.
For example, if the achievement’s *percentComplete* had previously been set to 75, sending an update with a value of 25 will be ignored and the achievement will still be displayed as 75% complete.

If *percentComplete* is set to 100, the achievement will unlock.

If *percentComplete* is set to a number greater than 100, the API will behave as if you set it to 100.

The following code shows how to call **XblAchievementsUpdateAchievementAsync**.


### Calling XblAchievementsUpdateAchievementAsync

[!INCLUDE [Achievements_UpdateAchievement](../../../../../code/snippets/Achievements_UpdateAchievement.md)]


### Callback for XblAchievementsUpdateAchievementAsync

[!INCLUDE [Achievements_UpdateAchievement_Callback](../../../../../code/snippets/Achievements_UpdateAchievement_Callback.md)]
