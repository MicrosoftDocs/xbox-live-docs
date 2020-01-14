---
title: Xbox Live service configuration IDs for Managed Partners
description: Setting up Xbox Live service configuration for your game, for Managed Partners.
ms.assetid: 631c415b-5366-4a84-ba4f-4f513b229c32
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, service configuration
ms.localizationpriority: medium
---

# Xbox Live service configuration IDs for Managed Partners


## What is Service Configuration?

Xbox Live features to configure include [Achievements](features/player-data/achievements/live-achievements-nav.md), [Stats & Leaderboards](features/player-data/stats-leaderboards/live-stats-leaderboards-nav.md) and [Matchmaking](features/multiplayer/concepts/live-multiplayer-concepts.md#smartmatch-matchmaking).

For example, Leaderboards allow players to see a value representing an accomplishment, in comparison to other players.
Such values include high scores in an arcade game, lap times in a racing game, and headshots in a first-person shooter.
But unlike an arcade machine, which only shows the top scores from the players who have played on that physical machine, with Xbox Live it is possible to display high scores from around the world.

For this to happen, you need to perform some one-time configuration so that Xbox Live knows about your leaderboard.
For example, whether the values should be sorted in ascending or descending value, and what piece of data it should be sorting.

This configuration happens on [Partner Center](https://partner.microsoft.com/dashboard).

If you are a developing your title as part of the Xbox Live Creators Program, you use [Partner Center](https://partner.microsoft.com/dashboard), and you can read [Getting Started With Xbox Live](get-started/setup-partner-center/legacy/get-started-with-xbox-live-creators.md) to learn how to get set up.

If you are in the Managed Partners Program, read on.


## Choose your development portal

Partner Center is used to configure Xbox Live Services.
*  Partner Center at [https://partner.microsoft.com/dashboard](https://partner.microsoft.com/dashboard)

You can find information about specific service configuration pages:
* [Partner Center configuration](configure-xbl/windows-dev-center_nav.md)

If you already have a title configured, you can scroll down to [Get your IDs](#get_ids) to learn how to get the various identifiers required to set up your title.


### PC/Mobile UWP game only

Partner Center is used for configuring and managing UWP games, including games that run on Windows 10 PCs and/or Windows 10 mobile devices.


#### Using Partner Center to configure UWP titles

You use Partner Center to configure UWP titles for all kinds of requirements, including:
1. You are using Arena.
2. You have existing users, groups, and permissions set up on Partner Center.
3. You are using tools on Partner Center such as the Tournaments Tool or Multiplayer Session Directory session history viewer.
4. You are developing a title that will have cross-platform play between an Xbox One XDK based game and UWP PC/mobile version of the same game.

See below for how to use Partner Center to configure a UWP title.


### Cross-play between Xbox One and PC/Mobile games ###

Cross-device gaming between the Xbox One and the PC, known as cross-play, is a showcase Windows 10 experience.
In this scenario, both the Xbox One and PC versions of a game share the same Xbox Live configuration.

This scenario also covers the case where you have an existing Xbox One XDK game, and want to add cross-play support for a UWP version of your game.

In order to implement cross-play, do the following:

* **Use Partner Center to configure and publish your XDK game.** Partner Center supports Xbox One XDK games.

* **Use a single Xbox Live service configuration that you created in Partner Center for both the XDK and the UWP versions of a game.** Partner Center allows a game to share a single Xbox Live service configuration between the XDK version and the UWP version of a game.

* **Use Partner Center to ingest and publish your UWP game.** Use Partner Center to configure Xbox Live services. Your game will use the service configuration that you created in Partner Center.

For more detail on this process, including items which are *not* self-service, see [Getting started with cross-play games](get-started-with-partner/get-started-with-cross-play-games.md).


### Separate versions of Xbox One and PC/Mobile games that are not cross-play

You may decide to keep your Xbox One version of a game separate from the PC/Mobile version of the same game.
In this case, you create two separate products, and follow the guidance for Xbox One XDK only and PC/Mobile UWP game only respectively.

You cannot use the same service configuration for both versions in this case, and you must manually create the service configuration for each separate version of your game, in Partner Center.


<a name="get_ids"></a>

## Get your IDs

To enable Xbox Live services, you will need to obtain several IDs to configure your development kit and your title.
These can be obtained by doing Xbox Live service configuration.

If you do not currently have a title at Partner Center, see the above section [Xbox Live Service Configuration portals](#xbox_live_portals) for guidance.


### Critical IDs

There are three IDs which are critical for development of titles and applications for Xbox One: the sandbox ID, the Title ID, and the SCID.

It is necessary to have a sandbox ID to use a development kit.
However, the Title ID and SCID are not required for initial development, but are required for any use of Xbox Live services.
We therefore recommend that you obtain all three IDs at once.


#### Sandbox IDs

The sandbox provides content isolation for your development kit during development, ensuring that you have a clean environment for developing and testing your title.
The Sandbox ID identifies your sandbox.
A console may only access one sandbox at any one time, though one sandbox may be accessed by multiple consoles.

Sandbox IDs are case-sensitive.

When configuring your title in Partner Center, you get your Sandbox ID on the "Xbox Live" root configuration page as shown below:

![Xbox Live title information on Partner Center screenshot. Includes Sandbox ID](images/getting_started/devcenter_sandbox_id.png)


#### Service Configuration ID (SCID)

As a part of development, you will create events, achievements, and a host of other online features.
These are all part of your service configuration, and require the SCID for access.

SCIDs are case sensitive.

To retrieve your SCID, in Partner Center, navigate to the Xbox Live Services section and go to *Xbox Live Setup*.

Your SCID is displayed in the table shown below:

![SCID displayed in Xbox Live Configuration on Partner Center screenshot](images/getting_started/devcenter_scid.png)


#### Title ID

The Title ID uniquely identifies your title to Xbox Live services.
It is used throughout the services to enable your users to access your title's Live content, their user statistics, achievements, and so forth, and to enable Live multiplayer functionality.

Title IDs can be case-sensitive, depending on how and where they are used.

Your Title ID is found in Partner Center in the same table as the SCID in the *Xbox Live Setup* page.

<a name="xbox_live_portals"></a>
