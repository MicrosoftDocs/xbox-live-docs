---
title: Getting title-managed Achievements
description: Example code for getting title-managed Achievements.
kindex: Getting title-managed Achievements
author: XBL
ms.author: v-jasch
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
ms.date: 09/23/2019
ms.localizationpriority: medium
---

# Getting title-managed Achievements

**Contents:**
* [Getting the Achievements List](#getting-the-achievements-list)
* [Getting the next page of Achievements results](#getting-the-next-page-of-achievements-results)
* [Getting a single Achievement](#getting-a-single-achievement)


<!-- ===================================================== -->
<a id="getting-the-achievements-list"></a>

## Getting the Achievements List

To get the achievements for the running title, call **XblAchievementsGetAchievementsForTitleIdAsync**, as follows.


### Calling XblAchievementsGetAchievementsForTitleIdAsync

[!INCLUDE [Achievements_GetAchievementsForTitle](../../../../../code/snippets/Achievements_GetAchievementsForTitle.md)]


**Callback for XblAchievementsGetAchievementsForTitleIdAsync**

[!INCLUDE [Achievements_GetAchievementsForTitle_Callback](../../../../../code/snippets/Achievements_GetAchievementsForTitle_Callback.md)]


<!-- ===================================================== -->
## Getting the next page of Achievements results

To get the next page of Achievements, call **XblAchievementsResultGetNextAsync**, as follows.


### Calling XblAchievementsResultGetNextAsync

[!INCLUDE [Achievements_GetNextResultsPage](../../../../../code/snippets/Achievements_GetNextResultsPage.md)]


**Callback for XblAchievementsResultGetNextAsync**

[!INCLUDE [Achievements_GetNextResultsPage_Callback](../../../../../code/snippets/Achievements_GetNextResultsPage_Callback.md)]


<!-- ===================================================== -->
## Getting a single Achievement

To get a single Achievement, call **XblAchievementsGetAchievementAsync**, as follows.


### Calling XblAchievementsGetAchievementAsync

[!INCLUDE [Achievements_GetAchievement](../../../../../code/snippets/Achievements_GetAchievement.md)]


**Callback for XblAchievementsGetAchievementAsync**

[!INCLUDE [Achievements_GetAchievement_Callback](../../../../../code/snippets/Achievements_GetAchievement_Callback.md)]
