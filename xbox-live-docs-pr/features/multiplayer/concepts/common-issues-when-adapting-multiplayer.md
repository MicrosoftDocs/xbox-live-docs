---
title: Changing a game from 2014 to 2015 Multiplayer
description: Changing a title from 2014 Multiplayer to 2015 Multiplayer.
ms.assetid: 206f8fe4-c7aa-44b8-923b-18f679d8439f
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one
ms.localizationpriority: medium
---

# Changing a game from 2014 to 2015 Multiplayer

This article describes issues that you must consider when adapting a 2014 Multiplayer title for 2015 Multiplayer.

<!-- from ~\multiplayer\multiplayer-appendix\multiplayer-appendix.md: -->
> **Note**  
The Multiplayer 2015 service, described in this article, is for advanced API usage.  As a starting point, instead use the [Multiplayer Manager API](../multiplayer-manager/multiplayer-manager.md) which significantly simplifies development. If you find an unsupported scenario in the Multiplayer Manager API, please let your DAM know.

> **Note**  
The previous version of the multiplayer system is Multiplayer 2014.
Multiplayer 2014 is based on the concept of the *game party* and participation in games through *parties*.
Multiplayer 2014 is now deprecated, although source code for it is still provided with the XDK.
The Multiplayer 2014 documentation is no longer included with the XDK; if you need that documentation, use a 2014 release of the XDK.

The Multiplayer 2015 system in Xbox One enables game play and the assembly of game players into groups.
The system is secure and flexible, allowing you not only to build simple features quickly, but also to build more complex features and plug in your own services.

The Multiplayer 2015 service abstracts-away the Multiplayer 2014 "game party" concept and instead uses the multiplayer session directory (MPSD) to control game sessions.
<!-- / multiplayer-appendix.md -->


## Configuration Changes to Make for 2015 Multiplayer

This section describes changes to be aware of when configuring your sessions and templates for 2015 Multiplayer.
For examples of the specific items discussed, see [MPSD Session Templates](../multiplayer-session/mpsd-overview.md).


### Add a Capability for Active Member Connection

The connectionRequiredForActiveMembers capability enables the disconnect detection and session change subscription features of 2015 Multiplayer.
Add this capability to the /constants/system/capabilities object for all session templates.


### Add a System Constant for Invite Protocol

The inviteProtocol system constant enables the recipient of an invite to receive a toast when the sender's title calls the **MultiplayerService.SendInvitesAsync Method** or the **SystemUI.ShowSendGameInvitesAsync Method (IUser, IMultiplayerSessionReference, String)**.
Add this constant, set to "game", to the /constants/system object for all templates for sessions to which the title invites players.


## Runtime Considerations for 2015 Multiplayer

Titles for 2015 Multiplayer must:
-   Always call the **MultiplayerService.EnableMultiplayerSubscriptions Method** prior to entering the multiplayer area of the title code. This call enables both subscriptions to session changes and disconnect detection.
-   Be sure to use the same **XboxLiveContext Class** object for all calls by the same user. The context contains state related to the management of the connection used for multiplayer subscriptions and disconnect detection.
-   If there are multiple local users, use a separate **XboxLiveContext** object for each user.


## Migrating a Session Template from Contract Version 104/105 to 107

The latest session template contract version is 107, with some changes to the schema used for MPSD.
Templates that you have written for session template contract version 104/105 must be updated if they are republished to use version 107.

This section summarizes the changes to make in migrating your templates to the latest version.
The templates themselves are described in [MPSD Session Templates](../multiplayer-session/mpsd-overview.md).

| Important                                                                                                                                                                                                                                                      |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Functionality that is set through a template cannot be changed through writes to MPSD. To change the values, you must create and submit a new template with the necessary changes. Any items that are not set through a template can be changed through writes to the MPSD. |


### Changes to the /constants/system/managedInitialization Object

The /constants/system/managedInitialization object has been renamed to /constants/system/memberInitialization.

Here are the changes to make to the name/value pairs for this object:
- autoEvaluate is renamed to externalEvaluation. Its polarity changes, except that false remains the default.
- The default value of membersNeededToStart changes from 2 to 1.
- The default value of joinTimeout changes from 5 seconds to 10 seconds.
- The default value of measurementTimeout changes from 5 seconds to 30 seconds.


### Changes to the /constants/system/timeouts Object

The /constants/system/timeouts object is removed, and the timeouts are renamed and relocated under /constants/system.

Here are the changes to make to the name/value pairs for this object:
- The reserved timeout becomes reservedRemovalTimeout.
- The inactive timeout becomes inactiveRemovalTimeout. Its new default is 0 (hours).
- The ready timeout becomes readyRemovalTimeout.
- The sessionEmpty timeout becomes sessionEmptyTimeout.

Details of the timeouts are presented in [Session Timeouts](../multiplayer-session/mpsd-details.md).


### Change to the Game Play Capability

The game play capability enables recent players and reputation reporting.
You must now specify the /constants/system/capabilities/gameplay field as true on sessions that represent actual game play, as opposed to helper sessions, for example, match and lobby sessions.


## See also

[MPSD Session Templates](../multiplayer-session/mpsd-details.md)
