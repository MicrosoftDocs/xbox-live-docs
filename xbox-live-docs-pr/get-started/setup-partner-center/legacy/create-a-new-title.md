---
title: Create an app and publish it for testing, for Managed Partners
description: Creating a new Managed Partners app in Partner Center, and publishing it to the test environment.
ms.assetid: b8bd69e6-887a-4b1f-a42d-8affdbec0234
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one
ms.localizationpriority: medium
---

# Create an app and publish it for testing, for Managed Partners


## Introduction

Before writing any code, you must set up a new title on your service configuration portal.
You can learn more about service configuration in [Xbox Live service configuration IDs, for Managed Partners](../../../test-release/portal-config/live-service-config-ids-mp.md).

This article through this process with the following assumptions:
* You are developing a Universal Windows Platform (UWP) title.  UWP titles run on Xbox One, Windows 10 desktop PCs, and mobile.
* You are configuring your title in Partner Center.
* You are using either Visual Studio with a custom game engine, or Unity.
* Your development machine is running Windows 10.

Provided that the above are true, the remainder of this article will walk through everything required to get a title configured in Partner Center, a new project created, and Xbox Live sign-in code written and tested.

> [!NOTE]
> If you are part of the Xbox Live Creators Program, the above assumptions apply to you and you should follow along with this article.


## Partner Center Setup

You need an Xbox Live enabled title created in Partner Center as a pre-requisite to any Xbox Live functionality working.


### Create a Microsoft account

If you don't have a Microsoft Account (also known as an MSA), you will need to first create one at [https://go.microsoft.com/fwlink/p/?LinkID=254486](https://go.microsoft.com/fwlink/p/?LinkID=254486).
If you have an Office 365 account, use Outlook.com, or have an Xbox Live account - you probably already have an MSA.


### Register as an App Developer

Before you can create a new title in Partner Center, you will need to register as an App Developer.

To register, go to [https://developer.microsoft.com/store/register](https://developer.microsoft.com/store/register) and follow the sign-up process.


### Create a new UWP title

Next, you need a UWP title defined in Partner Center.
You do that by first going to the Partner Center Dashboard:

![Partner Center screenshot highlighting Dashboard location](create-a-new-title_images/first_xbltitle_dashboard.png)

Then, create a new title.
You'll need to reserve a name.

![Partner Center name reservation dialogue box screenshot](create-a-new-title_images/first_xbltitle_newapp.png)

You'll then be taken to the *App Overview* page for your app.
The primary page where you'll be configuring Xbox Live is under the **Services -> Xbox Live** menu shown below.

![Xbox Live services configuration location in Partner Center menu left nav screenshot](create-a-new-title_images/first_xbltitle_leftnav.png)

<div id="createxblaccount"></div>


## Create an Xbox Live Account

You will need an Xbox Live Account to sign-in to Xbox Live.
If you already have one that you use to sign-in on your Xbox One console, or in the Xbox App on Windows 10, then you can use that one.

Otherwise you should open the Xbox App on your PC and sign-in with your Microsoft Account.
It will then be enabled for use with Xbox Live.

You can find the Xbox App by going into the *Start Menu* and typing in "Xbox" as shown below.

![Xbox App in Start Menu screenshot](create-a-new-title_images/first_xbltitle_xboxapp.png)


## Next Steps

Now that you have a new title created, you can set up an Xbox Live enabled title in your Game Engine, Visual Studio or build environment of choice.

See [Get started with Xbox Live, as a Managed Partner](get-started-with-xbox-live-partner.md).
