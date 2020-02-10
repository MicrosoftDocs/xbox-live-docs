---
title: Xbox Live Integration Test Cases For PC and Mobile Devices
description: Test cases for adding Xbox Live to a PC or mobile game.
kindex: Xbox Live Integration Test Cases For PC and Mobile Devices
ms.topic: article
keywords: windows 10, uwp, games, xbox, xbox live, policies
ms.localizationpriority: medium
ms.date: 10/01/2019
---
# Xbox Live Integration Test Cases for PC and Mobile Devices

Version 2.0


## Introduction

The following test cases are the recommended steps to validate a title when Xbox Live is integrated into a mobile, PC or console device other than Xbox One.  

See also [Xbox Live Integration Policies For PC and Mobile Devices](live-policies-pc.md).


### Official Naming Standards (XR-022)

Titles must use the naming standards defined in the latest release of the [Xbox Live required terminology list](live-certification-terminology-pc.md) for Xbox Live features. On Xbox One, titles must not refer to components of the console system or components of peripherals using terms that are not specifically included in the terminology list.


### Test Cases

**022-01 Official Naming Standards**   

**Test Steps**  
>1. Launch the title.
>2. Visit all areas of the title.
>3. Navigate all menus and sub-menus.
>4. Change all available settings and options.
>5. If the title supports saves, save and load all possible game types.
>6. Watch all cinematics.
>7. Note all text shown.  

**Expected Result**  
>All text adheres to the most recent terminology list.  

**Pass Examples**  
 None  

**Fail Examples**
>1. The title uses a proprietary term from a competitive platform.
>2. Title refers to a component of the device or component of a peripheral using any term that is not included in the terminology list.

<br />

### Display Name and Gamerpic (XR-046)
On Xbox One, titles must use the Gamertag function to display the user's gamertag as their primary display name. 

On non console platforms, while not required, we recommend you use the Xbox Live player’s gamertag in the appropriate locations within the game title’s experience. 

If titles show the user's gamerpic, the corresponding GameDisplayPic function must be used. These items are returned by the get_user_profile or GetUserProfileAsync Xbox Live APIs. When the gamertag is displayed, all 15 characters of any gamertag must be displayed correctly. Gamertags can include only ASCII characters a--z, A--Z, 0--9, comma (,), and space (ASCII character 0x20).

### Test Cases

**046-01 Display Name and Gamerpic**

**Test Steps**  
>1. Discover if gamertags are displayed within the title.
>2. Check to see how the user’s gamertag is displayed in all areas where the gamertag is used.
>3. If the title displays users’ pictures, verify that the correct Microsoft account picture or gamerpic appears for each account.

**Expected Result**  
>The user’s gamertag must be displayed correctly.

**Pass Examples**  
>1. If used, the gamertag is displayed correctly.  
>2. Gamertags are not used.
 
**Fail Examples**  
>1. The title does not display the exact gamertag. 
>2. The gamertag is missing required ASCII characters.

<br />

### [Profile Settings Usage (XR-048)](xr/live-pc-xr048.md)
The Xbox Live service is the source for Xbox Live user profile information. Games must not store user information sourced from Xbox Live, such as profile data, preferences, or display names, beyond a locally stored cache used to support loss of network connectivity. Any such caches must be updated on the next available connection to the service. 

### Test Cases

**048-01 Profile Settings Usage**

**Test Steps**  
>1. Select a profile and create a save.
>2. Change user profile data, including updating a gamertag or account name.
>3. Boot the title and load the save made in Step [2].
>4. Verify that the user-profile data visible during gameplay have changed and are not stored in the save game. 
>5. Verify that any reference to the gamertag (created automatically by the title) has been updated. This includes any reference on server-hosted functionality as well as any reference within the title.  

**Expected Result**  
User-profile data must not be stored. For example, if the title uses the gamertag in-game (such as in a welcome message) or on a non-Xbox Live server (such as naming data that is uploaded), it should not persist if the user changes his or her gamertag. This does not apply if the user has entered the gamertag manually.  

**Pass Examples**  
>1. User-profile data and preference settings are updated in all displays after they have been changed.  

**Fail Examples**  
>1. The title does not display the user’s updated gamertag or Microsoft account name within the title for locally stored save data such as replays, saves, options, maps, and teams. 
>2. The title does not update a user’s gamertag for persistent posts, such as game clips, replays, leaderboards, or other custom posts, such as messages, bulletin posts, user challenges, costumes, themes, livery, tournaments, and league.
Note: This applies to both new and previously created posts.
>3. The title stores the user’s gamertag for the user’s saved data, such as replays, saves, options, maps, and teams, resulting in the save data becoming unusable if the user changes his or her gamertag or account name.  

<br />

## Service Connectivity

### [Loss of Connectivity to Xbox and Partner Services (XR-074)](xr/live-pc-xr074.md)
Titles must resolve errors with Xbox Live and partner services connectivity. Titles must honor the retry policies set by Xbox Live when attempting to retry a request to the Xbox service after a failure has occurred.  Titles must appropriately manage messaging the user when services are unavailable. For example, if a partner service other than Xbox Live is not available, the game should not indicate that there is an issue with Xbox Live.

### Test Cases

**074-01 WAN Disconnection to Xbox Services**

**Test Steps**  
>1. Sign into an Xbox profile.
>2. While performing the following actions, disconnect the WAN network (if using an Ethernet switch/hub disconnect the uplink cable from the network device. If the device is connected via Wifi, disconnect the uplink cable from the wireless access point) connection:
>* Creating a new save point.
>* Loading a save point.
>* Reaching an auto-save point.
>* Enumerating a list of saved games.
>* Searching for and joining an online session.
>* Attempting to create an online session.
>* Viewing a leaderboard (if applicable).
>* Playing offline.

**Expected Result**  
In the event that the device is unable to reach Xbox services, the title should respond with a user-friendly error message.

**Pass Examples**  
>1.	Title displays error message indicating loss of network connection to Xbox services.
>2.	Title does not display an error message while playing a local game mode that does not require Xbox services.

**Fail Examples**  
>1. User is unable to complete a non-online Xbox game session.
>2.	Title goes into an unresponsive or unstable state.

**074-02 Direct Disconnection**

**Test Steps**  
>1. Sign into an Xbox profile.
>2. While performing the following actions in the title, pull the network cable from the device or power off the WAP or wireless router:
>* Creating a new save point.
>* Loading a save point.
>* Reaching an auto-save point.
>* Enumerating a list of saved games.
>* Searching for and joining an online session.
>* Attempting to create an online session.
>* Viewing a leaderboard (if applicable).
>* Playing offline.

**Expected Result**  
In the event the device loses connection to Xbox services, the title should respond with a user-friendly error message.

**Pass Examples**  
>1.	The title displays a user-friendly message while in online game mode.
>2. The title does not interrupt game-play during offline game mode.

**Fail Examples**  
>1. An error message is displayed during offline game mode.
>2.	The user is able to view online menus or view buffered media after the network goes offline.

**074-07 Dynamic Connectivity Loss**

**Tools Needed**
>1. Fiddler

**Test Steps**
>1. Sign into an Xbox profile and launch the title.
>2. Access non-Microsoft online feature.
>3. Use Fiddler to emulate downtime.

**Expected Results**
Title should gracefully handle disconnections to non-Microsoft service.

**Pass Examples**
>1. Title does not hang or crash upon loss of connectivity to the partner-hosted service.

**Fail Examples**
>1. Error displayed implies issues with Microsoft service.
>2.	Non-descriptive error message is displayed.
>3.	Title crashes or becomes unstable.

**074-08 Pre-launch Downtime**

**Tools Needed**
1. Fiddler

**Test Steps**
>1. Use Fiddler to emulate downtime. 
>2. Sign into an Xbox profile and launch the title.
>3. Access non-Microsoft online feature.

**Expected Results**
Titles should provide a user-friendly error message indicating that there is a problem reaching the non-Microsoft service and should allow an opportunity to retry connection.

**Pass Examples**
>1. Title does not hang or crash upon loss of connectivity to the partner-hosted service.

**Fail Examples**
>1. Error displayed implies issues with Microsoft service.
>2.	Non-descriptive error message is displayed.
>3.	Title crashes or becomes unstable.

<br />

### [Service Access Limitations (XR-132)](xr/live-pc-xr132.md)
Titles which exceed [title and user based limits ](https://docs.microsoft.com/windows/uwp/xbox-live/using-xbox-live/best-practices/fine-grained-rate-limiting)when calling Xbox Live services or do not adhere to Xbox Live service retry policies may be subjected to rate limiting, which may result in service interruption or deprecation. Failure to adhere to the specified limits may block a title from release, and in-production issues with released titles may result in Xbox Live services suspension up to and including title removal.

### Test Cases

**132-01 Service Access Limitations**

**Tools Needed**
>1. Fiddler
>2. [Xbox Live Trace Analyzer](https://aka.ms/xboxlivetoolspackage) to parse the output files from Fiddler

**Test Steps**  
>1. With the title running, start a fiddler trace and proceed to move through all areas of the title, including (if supported), but not limited to, the following: 
>* Create a game save, reboot the device and load the game save
>* Change rich presence states in quick succession (if possible)
>* Unlock and view achievements
>* Post to all leaderboards and view all leaderboards using all filters
>* View in-game Friends List (including a friend with presence blocked) and move between pages rapidly
>* Earn and view a Hero Stat
>* Match-make into all online modes, including being unable to find an available session (if possible) and generate voice traffic
>* Create, save and share a game clip
>* Access the in-game store (if applicable)
>2. Once test has concluded, stop the fiddler trace.
>3. In the XDK command prompt, run _xboxlivetraceanalyzer -data filepath -outputdir filepath_
>4. Open the output directory from step 4 and open the ‘index’ file (select ‘Allow blocked content’ if prompted).

**Expected Result**  
Games must not display any serious warnings in their Live Trace Analyzer output results. Titles must ensure they keep their service calls to Xbox Live endpoints below the specified burst and sustain limits.

**Pass Examples**  
>1. The title does not exceed the sustain limit when calling Xbox Live services.  

**Fail Examples**  
>1. The title exceeds the sustain limit (limit at which rate limiting takes effect) by 10x. For example, if the sustained limit at which Fine Grain Rate Limiting takes effect is set to 300 calls in 300 seconds, titles at or above 3000 calls in 300 seconds will fail.

<br />

## Online Safety and Privacy
 
### [Linking Microsoft Accounts with Publisher Accounts (XR-013)](xr/live-pc-xr013.md)
On Xbox One, titles that use partner-hosted services or accounts that require credentials must link that account with the user’s Microsoft account.  

Outside of Xbox One, titles can choose to allow account linking to support their game experience.  

If account linking is enabled within the title, the following rules apply: 
* Users must be notified of the account linking and given the choice to opt-out.
* If any account linking or access to partner hosted services is enabled, it must be made available to all users/account types. 
* Linked accounts must be authenticated prior to linking. 
* Users must be provided all applicable terms of use, privacy and other policies within the title (or a notice with a link to such information) both during the linking process and for as long as the accounts are linked.
* Users must have the ability to de-link accounts. 

### Test Cases

**013-01 Linking Microsoft Accounts with Publisher Accounts**

**Test Steps**  
>1. Verify that the title supports or requires non-Xbox accounts or login for services or functionality.
>2. Using a newly created Xbox profile, use the publisher provided service account or login to enter non-Xbox account credentials during initial setup.
>3. Verify the title allows the user to view the terms of use in the app, or informs the user how to view the terms of use, prior to completing the account linking process.
>4. Verify that the user is not prompted to reenter his or her non-Xbox account credentials in any location.
>5. Sign out and sign back in while the title is running.
>6. Repeat Step [4].
>7. Terminate and reactivate the title using the same profile.
>8. Repeat Step [4].
>9. Terminate the title.
>10. Verify that the title does not store non-Xbox account credentials locally by deleting any saved files that may have been created by the title.
>11. Reactivate the title and repeat Step [4].
>12. On a different console, launch the title using the same profile and repeat Step [4].
>13. Verify the title provides a method to view the terms of use while the accounts are linked.
>14. Verify the user is able to unlink their Xbox profile from the non-Xbox account.  

**Expected Result**  
The user should only have to provide his or her credentials once and allows the user to view the terms of use, or informs the user how to view the terms of use, prior to completing the account linking process. Users are provided with a mechanism to unlink their Xbox profile from their non-Xbox account.  

**Pass Examples**  
>1. The title never asks the user to reenter his or her non-Xbox account or login credentials at any point after he or she has initially entered them and the title provides a notification of the terms of use both during the linking process and for as long as the accounts are linked.  

**Fail Examples**  
>1. The title requires the user to enter his or her non-Xbox account or login credentials every time the title is launched.
>2. The title requires the user to enter his or her non-Xbox account or login credentials when running the title from another console.
>3. The title does not provide a method for viewing the terms of use during the account linking process.
>4. The title does not provide a method for viewing the terms of use after the accounts are linked.
>5. The title does not provide a method for unlinking their Xbox profile from their non-Xbox account.  

<br />

### [Xbox Live and Account Privileges (XR-045)](xr/live-pc-xr045.md)
Xbox Live promises users a certain level of privacy and online safety for themselves and their children. In order to deliver on that promise, titles must check whether the active user has certain privileges before completing certain actions on the Xbox Live service or in a title experience.


| **Activity**|**ID**|**Privilege Name**|**Notes**|
|-|--|--- |---|
|Playing in a multiplayer game session|254|XPRIVILEGE_MULTIPLAYER_SESSIONS|Allows a user to join multiplayer gameplay sessions with real-world users (not bots) in scenarios such as: Synchronous player-vs-player gameplay in the same session, asynchronous turn-based gameplay, Team-based gameplay, User-initiated matchmaking, Sending or accepting invitations, Join-in-progress sessions.|
|Playing in a cross network game play session|185|AuthPrivileges.CrossNetworkPlay|Allows a user to participate in a gameplay session with other real-world players who are not signed into Xbox Live in scenarios such as: Synchronous player-vs-player gameplay in the same session, asynchronous turn-based gameplay, Team-based gameplay, User-initiated matchmaking, Sending or accepting invitations, Join-in-progress sessions.|
|Communication with anyone |252|XPRIVILEGE_COMMUNICATIONS|Allows a user to communicate with any other Xbox Live users through voice or text. |
|Shared gaming sessions|189|XPRIVILEGE_SESSIONS|Allows a user to participate in connected single-player experiences in shared environments. These experiences must not have any features covered under privilege 252 or 254 (Communications and Multiplayer, respectively). Use of this privilege is a title capability that requires platform approval.|
|User-generated content (UGC)|247|XPRIVILEGE_USER_CREATED_CONTENT|Allows a user to see other users’ UGC online, download other users’ UGC, or share their own UGC online. This does not restrict usage of previously downloaded UGC. |
|Sharing to a social network|220|XPRIVILEGE_SOCIAL_NETWORK_SHARING|Xbox One Only: Allows a user to share information, including game progress, Kinect-generated content, game clips, and so on outside of Xbox Live.|

### Test Cases

**045-01 Respect User Privileges**   

**Test Steps**  
>1. Sign in to a profile and launch the title.
>2. For each of the privileges identified in the XR, identify if the title supports the associated activity.
>3. For each possible setting of each applicable privilege identified in step [2], perform the following:
>* Exit the title and change the user’s settings for the privilege.
>* Restart the device.
>* Sign into the same profile and launch the title.
>* Visit all relevant areas of the title, use all title features relevant to the privilege and verify that the title respects the user’s current privilege setting.  

**Expected Result**  
Titles must honor the user’s privilege settings.  

**Pass Examples**  
>1. The title respects the user’s privilege settings.
>2. The title treats a partial-allow privilege setting as if the privilege is disabled / disallowed (e.g. when the User-generated content (UGC) privilege is set to Friends Only, the title behaves as if the privilege is set to Blocked).
>3. For titles using the Xbox One XDK, the title invokes the system UI to alert the user of any privilege conflicts (titles must use the Store::Product::CheckPrivilegeAsync API).
>4. For titles using XSAPI, the title shows an informative message to let the user know they cannot participate. 

**Fail Examples**  
>1. The title persists a user’s privilege settings and does not reflect the user’s actual privileges after they have been changed.
>2. The title treats a partial-allow privilege setting as if the privilege is set to its least restrictive setting (e.g. when the User-generated content (UGC) privilege is set to Friends Only, the title behaves as if the privilege is set to Allowed).
>3. For titles using the Xbox One XDK, the title uses in-game messaging to alert the user of any privilege conflicts and does not display the System UI.
>4. For titles using XSAPI, the title does not show an informative message to let the user know they cannot participate.  

<br />

### [Privacy and Permissions (XR-015)](xr/live-pc-xr015.md)
Titles must not transmit user data or allow communication over Xbox Live when the user's privacy settings do not allow it.

Titles meet this XR by retrieving data from Xbox Live services. If the title uses its own services, it must check the user's privacy permissions at the beginning of a session or when a new user joins the session. For user-initiated scenarios outside of sessions, titles meet this requirement by checking privacy prior to displaying the user's data and before performing the action. The following list of privacy settings is available for titles to check:


| Permission name |Description |
|-------------------|-|---------------|
|CommunicateUsingText | Check whether or not the usercan send a message with text content to the target user. |
|CommunicateUsingVoice |Check whether or not the user can communicate using voice with the target user. | |

During the gameplay session, titles which offer communication between Xbox Live and non-Xbox Live network players must offer the ability to mute any non-Xbox Live players for the duration of the session.

### Test Cases

**015-01 User Communication**   
  
**Configuration:**   Create a set of profiles with a combination of different settings for the communication permissions outlined in the permissions table above.  

**Test Steps**  
>1. On Device 1, sign in to a profile that has been configured with a specific set of permissions per the Configuration.
>2. On Device 2, sign in to a profile that has no communication restrictions.
>3. On both devices, launch the title and attempt to communicate using text, voice, and video in every location supported.
>4. Repeat Steps [1] – [3] for all profiles from the Configuration step.  

**Expected Result**  
Titles must check the Xbox Live service for a user’s permissions regarding privacy and online safety-related actions before completing certain actions in the title when communicating over Xbox Live.  

**Pass Examples**  
>1. The title prevents the user from communicating over Xbox Live when that specific method of communication is configured to be blocked.  

**Fail Examples**  
>1. The user is able to communicate over Xbox Live when that specific method of communication is configured to be blocked.  

<br />

**015-02 Muting Support**   

**Test Steps**  
>1. As user A, mute user B.
>2. Have both users join an Xbox Live multiplayer session.
>3. Attempt to send voice communication from user B to user A.
>4. Ensure that user A is unable to receive any voice communication from user B.
>5. Attempt to send text communication from user B to user A.
>6. Ensure that user A is unable to receive any text communication from user B. 

**Expected Result**  
User A must not be able to hear or see text communication from user B.  

**Pass Examples**  
>1. Voice communication from the muted user cannot be heard by the user who initiated the mute.
>2. Text communication from the muted user cannot be seen by the user who initiated the mute.  

**Fail Examples**  
>1. Voice communication from the muted user can be heard by the user who initiated the mute.
>2. Text communication from the muted user can be seen by the user who initiated the mute.  
<br />

**015-03 Blocked Users**   

**Test Steps**  
>1. As user A, block user B.
>2. Have both users join an Xbox Live multiplayer session.
>3. Attempt to send voice and written communication from user B to user A.
>4. Locate any title-provided invitation mechanisms (any invitation mechanism that does not utilize the Xbox Shell).
>5. Using each of the mechanisms located in step [4], attempt to send a game invite from user B to user A.
>6. Ensure that user A is unable to receive any communication or invites from user B.

**Expected Result**  
User A must not be able to hear or see communication from user B. User A must not be able to receive game invitations from User B.  

**Pass Examples**  
> 1. Communication from the blocked user cannot be seen or heard by the user who initiated the block.  
> 2. Game invitations from the blocked user are not received by the user who initiated the block.

**Fail Examples**  
> 1. Communication from the blocked user can be seen or heard by the user who initiated the block.
> 2. Game invitations from the blocked user are received by the user who initiated the block. 
>
<br />

## Achievements and awards
The following requirements apply to titles that offer achievements, and awards on Xbox Live.  All games targeting Xbox One are required to have Achievements and meet the following requirements. Demos are not allowed to have achievements; however, they have the option of supporting Hero Stats.

### Achievements and Gamerscore (XR-055)
Titles that offer Xbox Live achievements must provide the required number of achievements and their associated gamerscore at launch. Titles are permitted to add achievements or gamerscore at any time after launch, with or without corresponding new content, but they cannot exceed title-based or calendar-based limits.

A single achievement cannot exceed 200 gamerscore and all achievements in the title must be achievable.

Item | Launch |Quarterly additions| Lifetime limit
-----|----|-----|-----
Minimum achievements | 10 | 0 | 10
Maximum achievements | 100 | 50 | 500
Gamerscore | 1000 | 500 | 5000

### Test Cases

**055-01 Achievements**

**Test Steps**
>1. Review the amount of Gamerscore and total number of Achievements supported by the title.
>2. Play through the title and attempt to gain as many achievements as possible.
>3. Repeat step [2] after resuming from connected-standby.

**Expected Result**  
All achievements unlock according to their criteria and the maximum possible Gamerscore for the base game’s launch is 1000G spread between 10-100 achievements.

**Pass Examples**
>1. All achievements can be gained.
>2. Achievements unlock as per their criteria.
>3. The launch version of the game has 1000 gamerscore spread across 10-100 achievements.

**Fail Examples**
>1. An achievement doesn’t unlock when the criteria has been met.
>2. An achievement unlocks before the criteria has been met.
>3. The launch version of the game does not have 1000G.
>4. The launch version of the game has more or fewer than 10-100 achievements.
>5. Achievements do not unlock after resuming from connected-standby.
>6. A single achievement exceeds 200 gamerscore.

<br />

### No Additional Purchases Required for Base Achievements (XR-057)
Titles must provide a way for a user to earn all achievements defined by the base title without being required to purchase additional in-title content.

Titles must not allow users to earn achievements by simply making purchases. For titles that have any achievement that unlocks based on a real-money purchase, that achievement must also be unlockable through in-title activity or in-title currency that was earned through in-title activity. 

### Test Cases

**057-01 No Additional Purchases Required for Base Achievements**   
  
**Test Steps**  
>1. Review the achievement descriptions on the base title.
>2. Verify that they do not require additional purchases or content.
>3. Gain all achievements.  

>**Expected Result**  
All achievements can be gained without being required to purchase additional in-title content.  

**Pass Examples**  
>1. All achievements can be gained without being required to purchase additional in-title content.
>2. No achievements require additional in-title content.  

**Fail Examples**  
> 1. The user is required to purchase additional in-title content to unlock an achievement defined by the base title.

<br />

### Achievements Across Multiple Titles or Platforms (XR-058)
Achievements must not be shared across titles. When a single title is supported across different platforms by using the same title ID, a title must share the same set of achievements and can, at their discretion, have platform-specific achievements.
  
### Modifying Active Achievements (XR-060)
After an achievement has been published to users, it cannot be removed, nor can its unlock rules or rewards be changed. Achievement text strings (name, description) or art (icons/background) can be modified.
 
 
### [Achievement Names and Descriptions (XR-062)](xr/live-pc-xr062.md)
Achievement names and descriptions may contain only content that would merit a rating of PEGI 12, ESRB EVERYONE 10+, or lower.

Achievement names and descriptions may not contain what is commonly considered profanity in a clear text or redacted form.
