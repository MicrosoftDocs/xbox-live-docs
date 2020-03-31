---
title: Configuring cross-play for Xbox and Windows 10 in Partner Center
description: Sharing a single Xbox Live services configuration across an XDK-based Xbox version and a UWP-based Windows 10 version of the game.
kindex: Configuring cross-play for Xbox and Windows 10 in Partner Center
kindex: cross-play
ms.topic: article
ms.assetid: 6c8e9d08-a3d2-4bfc-90ee-03c8fde3e66d
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Configuring cross-play for Xbox and Windows 10 in Partner Center

A _cross-play game_ is a game that is released as an XDK-based Xbox One (or later) version and a UWP-based Windows 10 version, where both versions of the game share a single Title ID and a single Xbox Live services configuration such as multiplayer, game saves, achievements, and leaderboards.

<!-- todo: replace Xbox Developer Portal (XDP) captures by Partner Center captures -->

With the launch of Windows 10, game developers will be able to release single products both on Xbox One (as an XDK game) and Windows 10 (as a UWP game).

In some cases, developers will want to enable cross-play for these games, where the Xbox One (or later) and Windows 10 versions of their game are unified across Xbox Live services like Multiplayer, Game Save, Achievements, and more.
To enable cross-play, these games will share a single Title ID and Xbox Live service configuration across both the XDK and UWP versions of the game.

Ingesting an XDK+UWP game requires 4 major steps:

1. Create your UWP product in Partner Center.

2. Create your XDK game in Partner Center, selecting the platforms you want to share XBL configuration across.

3. Bind your UWP product information to your XDK product in Partner Center.

4. Configure and publish Xbox Live through Partner Center.

This article details these four steps, to make it as easy as possible to ingest XDK+UWP cross-platform games.


## Terminology

<!--
terms to add:
ingesting
-->

_Cross-Play_: A game that is releasing on more than one platform, but shares a single Xbox title ID and service configuration. The end result is that both versions of the game share the same Xbox Live configuration - achievements, leaderboards, game saves, multiplayer, and more.

_Partner Center_: The [portal](https://partner.microsoft.com/dashboard) where you can do the following:
    * Reserve app identities for use in UWP development.
    * Set up Xbox Live configuration for UWP.
    * Ingest, configure, and publish Xbox One XDK and SRA games.
    * Ingest, configure, and publish XDK+UWP Cross-Play games.

_Title ID_: This is the Xbox Title ID, used to identify each game to Xbox Live.
A Title ID maps to a single product, which may span multiple platforms.

_Service Configuration ID (SCID)_: Each Xbox title (identified by a Title ID) has a corresponding Service Configuration ID (aka SCID).
This ID allows Xbox Live to uniquely identify the rules / configuration to use when interacting with your title.

_Package Family Name (PFN)_: This is an identity assigned to each product created in Partner Center.
Once you bind your UWP to the identity of this Partner Center product, it will take on this PFN.
PFNs are unique product identifiers, which may span multiple platforms.
PFNs are 1:1 with Xbox Title IDs.

_MSA App ID_: Also known as MSA Client ID, this is another app identity assigned by MSA at product creation time in Partner Center.
This identity helps Microsoft services identify your app.
MSA App IDs are 1:1 with PFNs (and accordingly with Xbox Title IDs).


## Scenario Overview


### What is Cross-Play?

A showcase Windows 10 experience; cross-play is cross-device gaming between the Xbox One (or later) and PC, with games sharing a single Xbox Live configuration across device versions to light up scenarios like cross-device multiplayer, achievements & leaderboards, and game saves.


### What are the pros and cons of Cross-Play?

Cross-Play is likely the right approach for you if you want the XDK and UWP versions of your game to:

-   Engage in cross-device multiplayer (Xbox vs. PC) in at least one multiplayer game mode

-   Share a single game save that the user can use on both devices

-   Have a single set of achievements & Gamerscore / challenges / leaderboards that they can additively progress against on both devices

Cross-Play is likely not the right approach for you if:

-   You want to prevent the PC and Xbox players of your game from engaging in multiplayer across devices in any and all multiplayer game modes

-   You want to keep Xbox and PC game save separate (perhaps for security or trust reasons)

-   You want the Xbox and PC versions of your game to have separate Gamerscore (aka users who buy both Xbox and PC can receive 1000 Gamerscore for each platform instead of a shared 1000)

In general, Cross-Play adds the most value to:

-   Free-to-Play / Xbox Play Anywhere games, that emphasize continuity between the Xbox and PC versions of the game

-   Games featuring cross-device multiplayer between Xbox and PC

**NOTE**: Cross-Play is available both to new games that are releasing the XDK and UWP versions of their game simultaneously, as well as games that have already shipped an XDK, but are adding a UWP version.


### Two versions of the game are required

A Cross-Play game requires two versions of the game:
*  A XDK version of the game, for the Xbox One (or later) console
*  A UWP version of the game, for Windows 10 PC

**XDK titles must be ingested in Partner Center**. Both for service configuration and mainline publishing, Partner Center supports XDK-based titles.

**A single service configuration created in Partner Center can be used both by the XDK and UWP version of a game**. Features in Partner Center allow a game to share a single service configuration between its XDK and UWP versions. The UWP version is published in Partner Center for packages / catalog, and all service configuration publishing is done in Partner Center.


## Create your UWP product in Partner Center

Create a UWP product in Partner Center; follow the steps in [Getting started using Visual Studio for UWP games](../../get-started/setup-ide/managed-partners/vstudio-win10/live-get-started-vstudio-uwp.md).


## Set up your XDK product at Partner Center

Now that your UWP is created, you are ready to set up your XDK product at Partner Center.

If you do not already have an XDK title, you must create one, as follows.


### Create a new product at Partner Center

Work with your account manager to create a new product under your publisher at Partner Center.

When creating the product at Partner Center, make sure that you scroll to the bottom of the left section of the UI to select your platforms.
Check every platform that you **intend to someday** release the game on with Xbox Live cross-play integration.

Once you have selected your platforms, specify the type of resource access for your game (most likely a XDK title) and the intended release mechanisms for this product.

![Platform selection for new product](../../images/ingesting_crossplay_games_xdp/image4.png)


### Update your Product Platforms at Partner Center

If you have an existing XDK product at Partner Center, it needs to be updated to support the PC platform.
To do this, once on the product, navigate to Product Setup &gt; Platform Type.

![Update platforms dialog box](../../images/ingesting_crossplay_games_xdp/image10.png)

On this page, select the platforms you want to support (options are Xbox One, Threshold PC, and Windows Mobile).
Then select the **Submit Platforms** button.

This change will immediately be made live (no need for a service configuration, catalog, or binary publish for this to take affect).
This configuration spans sandboxes – you cannot have different platform types per sandbox for your game.


### Enter your MSA App ID

Once the product is created at Partner Center, go to the Product Setup page for the product to enter the MSA App ID created earlier.

![Product setup location](../../images/ingesting_crossplay_games_xdp/image11.png)

Once you make it to the Product Setup page, select the "Application ID Setup" section.
In this area, you can enter the MSA App ID you retrieved and place it in the "Application ID" field, as shown below.

![Application ID setup](../../images/ingesting_crossplay_games_xdp/image12.png)

**You** **do not need to enter Name and Publisher attribution**, **and specifically should not use the "Get Application ID" link on the page**, as you already have an MSA App ID you need to enter in this field and do not want a new one generated for your application.

Once you've entered your MSA App ID in the "Application ID" field, click the "Submit Application ID Setup" button.
This will save your MSA App ID information with Xbox Live security – whenever you make a request to retrieve an XToken from your UWP, the title claim contained within will now map to this Partner Center product, as long as the UWP is properly using the AppX Manifest Identity you created in Partner Center.

The above steps get your UWP game authenticated and using Xbox Live with the Service Configuration you create and publish in Partner Center.


### Enter the Package Family Name (PFN)

Certain Xbox Live features (like multiplayer invites) need to be aware of your UWP game's PFN, in order to work correctly.

To do this, navigate to Product Setup &gt; Partner Center Binding

![Dev Center Binding](../../images/ingesting_crossplay_games_xdp/image13.png)

On this page, enter the PFN for your UWP app (as retrieved in section 4.1.1), then select the "save" button.

This configuration is not immediately made live.
This configuration is brought live through future Service Configuration publishes to a sandbox.
As such, this information is sandboxed, and needs to be published to each sandbox to be available.


### Flag your App for Xbox Cert in Partner Center

Today, getting your game recognized as Xbox Live enabled for Xbox Cert requires some manual intervention.
Work with your release manager to flag your app is Xbox Live enabled in Partner Center for SmartCert detection.


### Update your UWP Game in the Xbox App

Normally, the Xbox App uses an auto-generated Title ID for all UWP games to power the Xbox Live experiences within the Xbox App.
In order to have your UWP game properly use the Partner Center-generated Title ID in the Xbox App, a data update needs to be made within Partner Center, **before you submit your UWP game for release.**

To do this, please contact your DAM and tell them you want to update your Xbox App Title ID for your title name.
Be sure to include:
* The Title ID created in Partner Center (visible in Partner Center under **Product Setup** &gt; **Product Details**).
* The URL for Windows 10 for your UWP (visible in Partner Center under App management &gt; App identity).


## Configure Xbox Live in Partner Center


### Service Configuration

With your Partner Center products properly configured and bound, you are free to setup your shared Xbox Live configuration within Partner Center as you would normally for an XDK title.

**REMINDER** – Bound XDK+UWP games should, under no circumstances, enable, configure, or publish Xbox Live service configuration through the Partner Center.
Failure to follow this guidance can permanently harm the Xbox Live configuration for your game.


### Catalog Configuration

For an XDK+UWP game, catalog configuration needs to be set up in Partner Center.

For this Partner Center configuration, see the detailed steps in the UWP documentation, in <a href="https://dev.windows.com/publish" target="_blank">Publish Windows apps and games &#11008;</a>.

<table>
  <tr>
    <td>
      For UWP-only games, only a limited set of catalog configuration needs to be set up.
      In particular, Marketing Info should be filled out for UWP-only games, as service configuration consumes the strings entered here for any Partner Center-configured Xbox Live game.
      Additionally, availabilities should be setup with "not available" to ensure that the game will never appear in the Xbox One catalog if/when the catalog info for the game gets published.
    </td>
  </tr>
</table>


### Binary Configuration

For an XDK+UWP game, binary configuration needs to be set up in Partner Center.

For this Partner Center configuration, see the detailed steps in the UWP documentation, in <a href="https://dev.windows.com/publish" target="_blank">Publish Windows apps and games &#11008;</a>.

<table>
  <tr>
    <td>
      For UWP-only games, there is no need for binary configuration in Partner Center. You can skip this step entirely.
    </td>
  </tr>
</table>


## Publish in Partner Center

The below focuses on unique process or considerations to make for cross-play games.


## Dev Sandbox Publishing


### No Dev Sandbox Catalog Equivalent for Microsoft Store

While Partner Center allows you to publish your catalog & binary to the dev sandbox version of the Xbox One catalog, the Microsoft Store catalog has no sandbox support.
As such, testing your UWP in a dev sandbox requires you to sideload that UWP and play it directly.
This doesn't impact Xbox Live testing, but may alter your standard testing processes.

<table>
  <tr>
    <td>
      For a UWP-only game, it is still required to publish the XDK title catalog information to unblock service configuration publish, even though the UWP-only game has no Xbox One catalog presence.
    </td>
  </tr>
</table>


## CERT Sandbox Publishing

In Partner Center, the submission process automatically moves your game through certification and on to retail.
There is an order of operations to respect.

When you're ready to go to certification, you should follow the following steps in order:

1.  Publish your XDK product in Partner Center to CERT (including catalog, binary, and service config).

2.  Start your Partner Center submission for your UWP product.

    1.  **Be sure to select "Publish this app manually" or "No sooner than \[date\]" in the Publish date field!** If you don't do this, your UWP game could be released to retail automatically without your intervention.

<table>
  <tr>
    <td>
      For a UWP-only game, it is still required to publish your catalog and service config to CERT in Partner Center before starting your submission, even though you don't have an XDK title binary that you're publishing.
    </td>
  </tr>
</table>


## RETAIL Sandbox Publishing

Once certification of your XDK title has completed, and your UWP has left certification and is ready to publish, you are ready to publish your app to RETAIL.
Again, it's important to follow this process in a specific order to ensure that your XDK title and UWP stay aligned.

1.  Once you're ready, publish your XDK product in Partner Center to RETAIL (including catalog, binary, and service config)

2.  In Partner Center, on the certification page of your product, select "Publish now" if you had previously selected "Publish this app manually", or wait for the publish to occur if you selected "No sooner than \[date\]".

Once these steps have completed, you should have your XDK title and UWP game published to the world, with a shared service configuration in RETAIL.
Congratulations!

<table>
  <tr>
    <td>
      For a UWP-only game, it is still required to publish your catalog and service config to RETAIL in Partner Center before publishing completes, otherwise the released UWP will not be able to access Xbox Live.
    </td>
  </tr>
</table>
