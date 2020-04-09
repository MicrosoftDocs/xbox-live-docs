---
title: "XR-048: Profile Settings Usage"
description: Games must not store user information sourced from Xbox Live, such as profile data, preferences, or display names.
ms.topic: article
keywords: windows 10, uwp, games, xbox, xbox live, policies
ms.localizationpriority: medium
ms.date: 03/18/2019
---

# XR-048: Profile Settings Usage

The Xbox Live service is the source for Xbox Live user profile information.
Games must not store user information sourced from Xbox Live, such as profile data, preferences, or display names, beyond a locally stored cache used to support loss of network connectivity.
Any such caches must be updated on the next available connection to the service.


## More Information


### Exemptions

This requirement does not apply to scenarios in which a gamertag is displayed or used in a recorded experience such as a video or screenshot.


## Recommended Test Cases


### 048-01 Profile Settings Usage


#### Test Steps

1. Select a profile and create a save.

2. Change user profile data, including updating a gamertag or account name.

3. Boot the title and load the save made in Step [2].

4. Verify that the user-profile data visible during gameplay have changed and are not stored in the save game. 

5. Verify that any reference to the gamertag (created automatically by the title) has been updated. This includes any reference on server-hosted functionality as well as any reference within the title.  


#### Expected Result

User-profile data must not be stored. For example, if the title uses the gamertag in-game (such as in a welcome message) or on a non-Xbox Live server (such as naming data that is uploaded), it should not persist if the user changes his or her gamertag. This does not apply if the user has entered the gamertag manually.  


#### Pass Examples

1. User-profile data and preference settings are updated in all displays after they have been changed.  


#### Fail Examples

1. The title does not display the user’s updated gamertag or Microsoft account name within the title for locally stored save data such as replays, saves, options, maps, and teams. 

2. The title does not update a user’s gamertag for persistent posts, such as game clips, replays, leaderboards, or other custom posts, such as messages, bulletin posts, user challenges, costumes, themes, livery, tournaments, and league.
Note: This applies to both new and previously created posts.

3. The title stores the user’s gamertag for the user’s saved data, such as replays, saves, options, maps, and teams, resulting in the save data becoming unusable if the user changes his or her gamertag or account name.  
