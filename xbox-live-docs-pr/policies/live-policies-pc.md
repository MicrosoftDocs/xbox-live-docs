---
title: Xbox Live Policies for PC and mobile
description: Policies for adding Xbox Live to a PC, mobile or Creators Program game.
kindex: Xbox Live Policies for PC and mobile
ms.topic: conceptual
ms.localizationpriority: high
ms.date: 7/1/2021
---

# Xbox Live Policies for PC, Mobile, and Creators Program

Version 2.4


## Introduction

The following policies apply when Xbox Live is integrated into a mobile, PC, or console device other than an Xbox console.

>If your game is targeting an Xbox console, see [Xbox Requirements](https://developer.microsoft.com/games/xbox/partner/certification-requirements) for the Xbox Live and Xbox Policies which apply on that platform. If you have trouble accessing that page, please contact your Microsoft representative. Interested in bringing your PC/Mobile game to an Xbox console? Visit the [ID@Xbox program](https://www.xbox.com/Developers/id) for more information on how to apply.
>
>For developers in the Xbox Live Creators Program, in addition to the Xbox Live Policies below (for supported features in the creators program) visit the[ Microsoft Store Policies](https://docs.microsoft.com/legal/windows/agreements/store-policies) for store policies relating to the submission of your game to the Store across all Microsoft Devices (PC, Xbox consoles, Hololens, etc). Note that there are additional requirements for apps that are primarily gaming experiences or target Xbox consoles, detailed in the section titled "Gaming and Xbox". Xbox Live on devices not supported by the Microsoft Store is not available to the Creators Program at this time. Visit the [Xbox Live Creators Program](https://www.xbox.com/developers/creators-program/) for information on getting started.
>
Adherence to these integration policies will ensure successful deployment of Xbox Live in your game and consistent implementation across the gaming ecosystem. Failure to adhere to these policies may result in revocation of access to the Xbox Live service by your title.


## Store policies

Games which use Xbox Live are still subject to the store polices for the application platforms which they  submit their game to. For Microsoft Store, the store policies are located [here](https://docs.microsoft.com/legal/windows/agreements/store-policies). 

For PC games submitted to the Microsoft Store which have Xbox Live, there will be pre release testing to ensure that the Xbox Live implementation functions correctly and that parental controls are respected prior to release.  This testing will occur in parallel to normal store testing, adding no additional delays to your publishing timeline on the Microsoft Store.  


## Policy enforcement process

You are free to release and update your Xbox Live integrated game on any store or platform, outside of the Xbox One console, without any additional certification testing, except for those required by the store or platform on which your game will be published and released. Microsoft will monitor released games via the following mechanisms:
1. Customer complaints regarding game functionality.
2. Spot-check review of select games, including the most popular titles.
3. Alerts and/or warnings we find in our back-end services.

If your game is found to not adhere to these policies, we will inform you and provide a reasonable timeline to fix based on severity, as determined by Microsoft. Other than in exceptional circumstances, if the issue is not resolved within the requested timeframe we may revoke the game's ability to sign into Xbox Live services until the issue is resolved.

For information on how to test your title's adherence to these policies, see [Xbox Live Integration Test Cases For PC and Mobile Devices](live-policy-tests-pc.md).


## Xbox Live Implementation Policies

In order to keep Xbox Live running as a high quality service that respects the privacy and protects the security of its users we enforce a number of Xbox Live implementation policies. These policies are referred to as Xbox Requirements or XRs. Failure to comply with XRs will result in your title being denied the ability to publish to the Microsoft store. Titles which are already published may find themselves removed if they do not maintain compliance with XRs. The rest of this article will outline the XRs required to keep a PC or mobile title in good standing.


### Player Data and Privacy

Xbox Live Services will provide you with limited user data in order for you to deliver your game to players.  This user data includes account identifiers like a userid (XUID) and gamertag, connections with other players, and data about a player's activities in your game, including usage data, statistics, scores, ratings rankings, and social activity.

You are an independent controller of such data and must have a privacy statement (or policy) in place with end users governing your use of personal data, as required by the [Application Developer Agreement](https://docs.microsoft.com/legal/windows/agreements/app-developer-agreement). We recommend you include a link to your privacy statement from within your game, on your website, and from the detail page of any store in which you make your game available for download.

Notwithstanding the foregoing, the following rules apply to personal data provide through the Xbox Live Services.  

* Such data may only be used to deliver your game to players.  

* You may not sell, license, or share the data with any third party.  Social graph data (e.g., friends' lists) may not be stored, except for the account identifiers of those friends who have linked their own Xbox Live accounts with your game. Delete all account identifiers, when you remove your game from our service, or when a user delinks their Xbox Live account from your game.  

* Do not share services or user data (even if anonymous, aggregate, or derived data) to any ad network, data broker or other advertising or monetization-related service.

* When Microsoft receives requests from end users to delete their personal data, we will communicate the requests to you by providing a list of end user identifiers. You must check the list at least every 30 days to ensure you receive all delete requests and must use the information provided on the list only to satisfy the delete requests of end users. You can find details about this process at[ Deleted Account List Tools](https://aka.ms/xbox-deleted).


### Official Naming Standards (XR-022)

Titles must use the naming standards defined in the latest release of the [Xbox Live required terminology list](live-certification-terminology-pc.md) for Xbox Live features. On Xbox One, titles must not refer to components of the console system or components of peripherals using terms that are not specifically included in the terminology list.


### Display Name and Gamerpic (XR-046)

On Xbox consoles, titles must use the Gamertag as their primary display name.
Based on development architecture and design choice titles can choose between the player’s modern gamertag (Game Core) or their classic gamertag (ERA or Game Core)

On non console platforms, while not required, we recommend you use the Xbox Live player’s gamertag in the appropriate locations within the game title’s experience.

The gamertag used must be displayed correctly in the title based on the gamertag type used:

* **Modern Gamertag:**  Display all 16 characters of the unique modern gamertag, which includes up to 12 characters of the modern gamertag, followed by # and the suffix number (if present). For example: Major Nelson (no suffix present) or Major Nelson#881. If modern gamertags are used, all Unicode character ranges available for modern gamertags must be supported. For more modern gamertag information and best practices visit the Game Core development documentation article 'Overview of modern gamertags'
* **Classic Gamertag:**  Correctly display all 15 characters of the classic gamertag. Classic gamertags include only ASCII characters a–z, A–Z, 0–9, comma (,), and space (ASCII character 0x20). For example: Major Nelson

In Game Core these items are returned using the **XUserGetGamertag** API.  In ERA the gamertag is obtained using the **GetUserProfileAsync** API.
 
### [Profile Settings Usage (XR-048)](xr/live-pc-xr048.md)

The Xbox Live service is the source for Xbox Live user profile information. Games must not store user information sourced from Xbox Live, such as profile data, preferences, or display names, beyond a locally stored cache used to support loss of network connectivity. Any such caches must be updated on the next available connection to the service. 


## Service Connectivity


### [Loss of Connectivity to Xbox and Partner Services (XR-074)](xr/live-pc-xr074.md)

Titles must resolve errors with Xbox Live and partner services connectivity. Titles must honor the retry policies set by Xbox Live when attempting to retry a request to the Xbox service after a failure has occurred.  Titles must appropriately manage messaging the user when services are unavailable. For example, if a partner service other than Xbox Live is not available, the game should not indicate that there is an issue with Xbox Live.
 

### [Service Access Limitations (XR-132)](xr/live-pc-xr132.md)

Titles which exceed [title and user based limits ](https://docs.microsoft.com/windows/uwp/xbox-live/using-xbox-live/best-practices/fine-grained-rate-limiting)when calling Xbox Live services or do not adhere to Xbox Live service retry policies may be subjected to rate limiting, which may result in service interruption or deprecation. Failure to adhere to the specified limits may block a title from release, and in-production issues with released titles may result in Xbox Live services suspension up to and including title removal.


## Online Safety and Privacy
 

### [Linking Microsoft Accounts with Publisher Accounts (XR-013)](xr/live-pc-xr013.md)

On Xbox One, titles that use partner-hosted services or accounts that require credentials must link that account with the user's Microsoft account.  

Outside of Xbox One, titles can choose to allow account linking to support their game experience.  

If account linking is enabled within the title, the following rules apply:
* Users must be notified of the account linking and given the choice to opt-out.
* If any account linking or access to partner hosted services is enabled, it must be made available to all users/account types.
* Linked accounts must be authenticated prior to linking.
* Users must be provided all applicable terms of use, privacy and other policies within the title (or a notice with a link to such information) both during the linking process and for as long as the accounts are linked.
* Users must have the ability to de-link accounts.


### [Xbox Live and Account Privileges (XR-045)](xr/live-pc-xr045.md)

Xbox Live promises users a certain level of privacy and online safety for themselves and their children. In order to deliver on that promise, titles must check whether the active user has certain privileges before completing certain actions on the Xbox Live service or in a title experience.


| **Activity**|**ID**|**Privilege Name**|**Notes**|
|-|--|--- |---|
|Playing in a multiplayer game session|254|XPRIVILEGE_MULTIPLAYER_SESSIONS|Allows a user to join multiplayer gameplay sessions with real-world users (not bots) in scenarios such as: Synchronous player-vs-player gameplay in the same session, asynchronous turn-based gameplay, Team-based gameplay, User-initiated matchmaking, Sending or accepting invitations, Join-in-progress sessions.|
|Playing in a cross network game play session|185|AuthPrivileges.CrossNetworkPlay|Allows a user to participate in a gameplay session with other real-world players who are not signed into Xbox Live in scenarios such as: Synchronous player-vs-player gameplay in the same session, asynchronous turn-based gameplay, Team-based gameplay, User-initiated matchmaking, Sending or accepting invitations, Join-in-progress sessions.|
|Communication with anyone |252|XPRIVILEGE_COMMUNICATIONS|Allows a user to communicate with any other Xbox Live users through voice or text. |
|Shared gaming sessions|189|XPRIVILEGE_SESSIONS|Allows a user to participate in connected single-player experiences in shared environments. These experiences must not have any features covered under privilege 252 or 254 (Communications and Multiplayer, respectively). Use of this privilege is a title capability that requires platform approval.|
|User-generated content (UGC)|247|XPRIVILEGE_USER_CREATED_CONTENT|Allows a user to see other users' UGC online, download other users' UGC, or share their own UGC online. This does not restrict usage of previously downloaded UGC. |
|Sharing to a social network|220|XPRIVILEGE_SOCIAL_NETWORK_SHARING|Xbox One Only: Allows a user to share information, including game progress, Kinect-generated content, game clips, and so on outside of Xbox Live.|


Free to play titles, demos, or betas can be configured to allow multiplayer gameplay (ID 254) for players who are not Xbox Live Gold subscribers.  This is done via a service side configuration and can be initiated by contacting your Microsoft representative.  These titles must continue to check for the multiplayer game privilege to ensure that parental controls and player choices are respected.


### [Managing Player Communication (XR-015)](xr/live-pc-xr015.md)

Titles must not transmit user data or allow communication over Xbox Live when the user's privacy & online safety settings do not allow it.

Titles meet this XR by retrieving data from Xbox Live services. If the title uses its own services, it must check the user's privacy permissions at the beginning of a session or when a new user joins the session. For user-initiated scenarios outside of sessions, titles meet this requirement by checking privacy prior to displaying the user's data and before performing the action. The following list of privacy settings is available for titles to check:

| Permission name |Description |
|-----------------|------------|
|CommunicateUsingText | Check whether or not the user can send a message with text content to the target user. |
|CommunicateUsingVoice |Check whether or not the user can communicate using voice with the target user. |

During the gameplay session, titles which offer communication between Xbox Live and non-Xbox Live network players must offer the ability to mute any non-Xbox Live players for the duration of the session.

### [User Generated Content (XR-018:)](xr/live-pc-XR018.md) \* 

User generated content is content that users contribute to an app or product and can be viewed or accessed by other users in an online state. If your product contains UGC, you must: 

* Publish and make available to users a product terms of service and/or content guidelines for User Generated Content either in game or on a title’s website 
* Provide a means for users to report inappropriate or harmful content within the product to the developer for review and removal/disablement if in violation of content guidelines and/or implement a method for proactive detection of inappropriate or harmful UGC (for example, text filtering) 
* Titles must remove/disable UGC when requested by Microsoft 
* Gracefully handle scenarios in which a user does not have access to UGC in game 
* Titles integrated with 3rd party mod platforms must integrate with the product’s report / complaint API if available and must moderate content if required by respective 3rd party contracts 
* Titles integrated with 3rd party mod platforms must present a disclaimer, dialog, or visual cue to users if the content is not sourced from the developer 

## Achievements and awards

The following requirements apply to titles that offer achievements, and awards on Xbox Live.  All games targeting Xbox One are required to have Achievements and meet the following requirements. Demos are not allowed to have achievements; however, they have the option of supporting Hero Stats.


### Achievements and Gamerscore (XR-055)

Titles that offer Xbox Live achievements must provide the required number of achievements and their associated gamerscore at launch. Titles are permitted to add achievements or gamerscore at any time after launch, with or without corresponding new content, but they cannot exceed title-based or calendar-based limits.

A single achievement cannot exceed 200 gamerscore and all achievements in the title must be achievable.

Item | Launch |Semi-annual additions| Lifetime limit
-----|----|-----|-----
Minimum achievements | 10 | 0 | 10
Maximum achievements | 100 | 100 | 500
Gamerscore | 1000 | 1000 | 5000

Note: “Semi-annual” means January–June, July–December. Base game achievements and Gamerscore do not count towards the semi-annual limits.


### Unlocking Achievements  (XR-057)

Titles must provide a way for a user to earn all achievements defined by the base title without being required to purchase additional in-title content.

Achievements must be unlocked through in-game actions, gameplay, and/or experiences.

Titles must not provide players alternative options that unlock achievements directly without corresponding gameplay activity. A non-exhaustive list of disallowed options:

* A real-money purchase

* In-game cheat codes, consoles, or menu options

These options may be used to reduce the difficulty of the gameplay required to unlock achievements.

### Achievements Across Multiple Titles or Platforms (XR-058)

Achievements must not be shared across titles. When a single title is supported across different platforms by using the same title ID, a title must share the same set of achievements and can, at their discretion, have platform-specific achievements.
  

### Modifying Active Achievements (XR-060)

After an achievement has been published to users, it cannot be removed, nor can its unlock rules or rewards be changed. Achievement text strings (name, description) or art (icons/background) can be modified.
 
 
### [Achievement Names and Descriptions (XR-062)](xr/live-pc-xr062.md)

Achievement names and descriptions may contain only content that would merit a rating of PEGI 12, ESRB EVERYONE 10+, or lower.

Achievement names and descriptions may not contain what is commonly considered profanity in a clear text or redacted form.

## **Multiplayer sessions**

The requirements in this category pertain to game titles that provide multiplayer sessions on Xbox Live. Xbox Live offers a consistent and simple way to find multiplayer sessions and to fine-tune the parameters used to find those sessions.

### [Joinable Game Sessions and Online Play (XR-064)](xr/live-pc-xr064.md)

On Xbox consoles, titles that offer joinable game sessions must enable joinability through the Xbox shell interface. 

Titles that offer cross platform multiplayer with Xbox consoles from PC devices using Xbox sign in must also enable joins through the Game Bar experience.


### [Maintaining Multiplayer Session State (XR-067)](xr/live-pc-xr067.md)

On Xbox consoles, titles with online multiplayer functionality must maintain session-state information on Xbox Live.  Titles do this through the Xbox Multiplayer Session Directory (MPSD) or if a title has their own multiplayer session state functionality, they may choose to instead record player interactions using the Multiplayer Activity Recent Player feature.

On devices other than Xbox consoles, titles which offer cross platform multiplayer with Xbox consoles must maintain session-state information in the Xbox Multiplayer Session Directory (MPSD).   If they have their own session state functionality,  they may choose to instead record player interactions using the Multiplayer Activity Recent Player feature.

