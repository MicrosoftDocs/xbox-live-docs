---
title: Create an app and publish it for testing, for Creators
description: Creating a new Creators app in Partner Center, and publishing it to the test environment.
ms.assetid: ced4d708-e8c0-4b69-aad0-e953bfdacbbf
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, creators, test
ms.localizationpriority: medium
---

# Create an app and publish it for testing, for Creators


## Introduction

Before writing any Xbox Live code, you must set up a new title on your service configuration portal.
See also [Xbox Live Service Configuration](../xbox-live-service-configuration.md).

This article will walk through everything required to configure a title in Partner Center, create a new project, and prepare Xbox Live for testing.

This article assumes the following:
1. You are using the Xbox Live Creators Program.
2. You are developing a Universal Windows Platform (UWP) title.  UWP titles can run on Xbox One, Windows 10 desktop PCs, and mobile.
3. You are configuring your title in Partner Center.
4. Your development machine is running Windows 10.

> [!NOTE]
> If you are part of the Xbox Live Creators Program, the above assumptions apply to you and you should follow along with this article


## Partner Center setup

You need an Xbox Live-enabled title created in Partner Center as a prerequisite to using any Xbox Live functionality.


### Create a Microsoft account

If you don't have a Microsoft Account (also known as an *MSA*), you will need to first create one at [Microsoft Account - Sign In](https://go.microsoft.com/fwlink/p/?LinkID=254486).
If you have an Office 365 account, use Outlook.com, or have an Xbox Live account - you probably already have an MSA.


### Register as an App Developer

Before you can create a new title in Partner Center, you must register as an App Developer.

See [Register as an app developer](https://developer.microsoft.com/store/register) and follow the sign-up process.


### Create a new UWP title

You will need a UWP title defined in Partner Center. You do that by first going to [Partner Center](https://partner.microsoft.com/dashboard).

Next, create a new title. You'll need to reserve a name.

![name reservation dialogue box screenshot](../images/getting_started/first_xbltitle_newapp.png)

The screenshot shows the primary page where you'll be configuring Xbox Live, located under the **Services** > **Xbox Live** menu.

![Xbox Live configuration in Partner Center menu screenshot](../images/creators_udc/creators_udc_xboxlive_page.png)


## Enable Xbox Live services

When you click the **Xbox Live** link under **Services** for the first time for a product, you will be taken to the Enable Xbox Live Creators Program page.  
Next, click the **Enable** button to bring up the Xbox Live setup dialog.

![Partner Center screenshot with enable button location](../images/creators_udc/creators_udc_xboxlive_enable.png)

On the setup dialog, select the platforms that you would like to enable the Xbox Live Services for (both Xbox One and Windows 10 PC are selected by default).
Click the **Confirm** button to enable Xbox Live Creators Program for your game.

> [!IMPORTANT]
> Xbox Live is only supported for games. In order to successfully publish your game with Xbox Live, you must set your product type to "Game" in the properties section of the submission.

![Enabled game name selection dialogue box screenshot](../images/creators_udc/creators_udc_xboxlive_enable_dialog.png)


## Test Xbox Live service configuration in your game

When you make changes to the Xbox Live configuration for your game, you need to publish the changes to a specific environment before they are picked up by the rest of Xbox Live and can be seen by your game.

When you are still working on your game, you publish to your own development sandbox.
The development sandbox allows you to work on changes to your game in an isolated environment.

When your game is released to the public, the Xbox Live configuration will automatically be published to the RETAIL sandbox.

By default, Xbox One Consoles and Windows 10 PCs are in the RETAIL sandbox.


### Publish Xbox Live Configuration to the test environment

Whenever you enable Xbox Live services and make changes to Xbox Live service configuration, to make the changes effective, you need to publish these changes to your development sandbox.

On the Xbox Live configuration page, click the **Test** button to publish the current Xbox Live configuration to your development sandbox.

![Partner center screenshot with test publish button](../images/creators_udc/creators_udc_xboxlive_config_test.png)


### Authorize devices and users for the development sandbox

Only authorized devices and users can access the Xbox Live configuration for the game in your development sandbox.

By default, all the Xbox One development consoles you have added to your Partner Center account have access to your development sandbox.
To add an Xbox One console, go to [Manage Xbox One consoles](https://partner.microsoft.com/xboxconfig/devices).
If you’re already in your Partner Center account, you can go to **Account Settings** > **Account Settings** > **Dev devices** > **Xbox One development consoles**.


## Next steps

After you have a new title created, you can set up an Xbox Live-enabled title in your game engine, Visual Studio, or build environment of choice.
See [Get started with the Xbox Live Creators Program](get-started-with-xbox-live-creators.md).
