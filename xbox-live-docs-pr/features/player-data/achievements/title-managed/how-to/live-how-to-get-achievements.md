---
title: Getting Achievements
description: Example code for getting title-managed Achievements.
kindex: Getting Achievements
author: XBL
ms.author: v-jasch
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
ms.date: 09/23/2019
ms.localizationpriority: medium
---

# Getting Achievements

A how-to guide for using Achievements API to get achievements.

**Contents:**
* Getting the Achievements List
* Getting the next page of Achievements results
* Getting a single Achievement


## Getting the Achievements List

To get the achievements for the running title, call **XblAchievementsGetAchievementsForTitleIdAsync**, as follows.


### Calling XblAchievementsGetAchievementsForTitleIdAsync

[!INCLUDE [Achievements_GetAchievementsForTitle](../../../../../code/snippets/Achievements_GetAchievementsForTitle.md)]


### Callback for XblAchievementsGetAchievementsForTitleIdAsync

[!INCLUDE [Achievements_GetAchievementsForTitle_Callback](../../../../../code/snippets/Achievements_GetAchievementsForTitle_Callback.md)]


## Getting the next page of Achievements results

To get the next page of Achievements, call **XblAchievementsResultGetNextAsync**, as follows.

### Calling XblAchievementsResultGetNextAsync

[!INCLUDE [Achievements_GetNextResultsPage](../../../../../code/snippets/Achievements_GetNextResultsPage.md)]


### Callback for XblAchievementsResultGetNextAsync

[!INCLUDE [Achievements_GetNextResultsPage_Callback](../../../../../code/snippets/Achievements_GetNextResultsPage_Callback.md)]



## Getting a single Achievement

To get a single Achievement, call **XblAchievementsGetAchievementAsync**, as follows.


### Calling XblAchievementsGetAchievementAsync

[!INCLUDE [Achievements_GetAchievement](../../../../../code/snippets/Achievements_GetAchievement.md)]


### Callback for XblAchievementsGetAchievementAsync

[!INCLUDE [Achievements_GetAchievement_Callback](../../../../../code/snippets/Achievements_GetAchievement_Callback.md)]
