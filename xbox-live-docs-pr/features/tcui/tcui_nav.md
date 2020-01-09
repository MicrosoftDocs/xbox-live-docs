---
title: Title-callable UI (TCUI)
description: Title-callable UI (TCUI) enables your game code to call pre-defined user interface displays.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, windows 10, xbox one
ms.localizationpriority: medium
---

# Title-callable UI (TCUI)

> [!NOTE]
> This is preliminary documentation. 

Title-callable UI (TCUI) enables your game code to call pre-defined user interface displays.

The Xbox Live TCUI supports the following:
* Style consistent with RS5 Gamebar
* Tailored to direct input (keyboard/mouse/touch)
* Universal profile card across Gamebar, TCUI, Official Clubs
* Inline messaging
* Limited Game theming (TCUI uses TitleID to fetch existing art)
* Advanced Game theming (Game preconfigures more extensive styling)


TCUI provides the following functions.

| Function | Description |
|---------|-------------|
| `ShowProfileCardForUserAsync` | Show me-view or you-view profile card for a specific profile. |
| `ShowComposeInvitationForUserAsync` | Show list of user’s friends to select as invite recipients, then send the invite. Could potentially show other lists to choose from. |
| `ShowPeoplePickerForUserAsync` | Get the user to choose a set of people from a list—either their friends list or a list provided by the game.  The selected list is returned to the game. |
| `ShowChangeFriendRelationshipForUserAsync` | Allow the user to add/favorite/remove another profile as a friend.  Can also be invoked from Profile Card. |
| `ShowTitleAchievementsForUserAsync` | Show the Achievement list for a specific title.  Can pivot to show Stats. |
| `ShowFindFriendsForUserAsync` | Shows the Facebook friend finder list of suggested friends, where user can add as friends. |
| `ShowCheckPrivilegeUIAsync` | Checks to see if the user has a specific privilege, and provides UI feedback to the user if they do not. |
| `ShowGameInfoForUserAsync` | Navigates to game detail page. |
| `ShowCustomizeUserProfileForUserAsync` | Navigates to an area where the user can customize their profile (full screen profile). |
| `ShowUserSettingsForUserAsync` | Navigates to an area where the user can change their settings. |
| `ShowStorageUIAsync` | Shows storage progress / prompts for syncing disambiguation. |


### See also

* [Xbox Live Samples](../../api-ref/live-samples.md)
