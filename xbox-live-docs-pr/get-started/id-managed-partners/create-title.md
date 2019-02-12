---
title: Create a new title
description: Create a new game or other title, as a member of the ID@Xbox program or as a Managed Partner.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Create a new title

To add Xbox Live functionality to a game or other title, start by creating a new game or other title at Xbox Live Partner Center.

This page is for members of the ID@Xbox or Managed Partners program.

<!--
## Visio: Create Title (= "Create a new app", below)
## Visio: Choose platforms (not discussed Monday? where/when do this?)
## Visio: Get title approved (Submission)
## Visio: Choose sandbox
## Visio: Enable title (?= option button **Use full Xbox Live feature set (requires concept approval)**)
## Visio: Publish title
## Visio: Create Test Account (not discussed Monday?)
## Visio: Get Sample (not discussed Monday?)
## Visio: Sign in (not discussed Monday?)
-->

<!--===========================================================-->
## Set up a Partner Center account

As a prerequisite step, you must have a Partner Center account, so that you can login to Partner Center.

If you don't have a Partner Center account, at the Partner Center documentation site, see [Create a Partner Center account](https://docs.microsoft.com/en-us/partner-center/mpn-create-a-partner-center-account).
Then continue with the present page.

After you have a Partner Center account, do the steps below.


<!--===========================================================-->
## Create a new app

Next, at Partner Center, you create a new app, which is a game or other title, as follows.

1. Go to [Partner Center dashboard](https://partner.microsoft.com/dashboard/) (https://partner.microsoft.com/dashboard/).

   The Partner Center dashboard appears, showing the "Overview" page, within the "WINDOWS" section.

2. Click the **Create a new app** button.

   The page "Create your app by reserving a name" appears.

3. In the text box, enter the name of your game or title.
   You can use a test name such as "GetStartManaged01" or "GetStartManaged01JSmith". <!--GetStartManaged01mihof-->

4. Click the **Check availability** link.

   A checkmark appears in the right side of the text box.

5. Click the check box **Create this product in a sandbox**.

   **Important**: For Managed Partners and ID@Xbox developers, to enable Xbox Live functionality, you **MUST** select the option button **Create this product in a sandbox**, the first time through this process.
   You won't be able to select this radio button later.
   (Do not select the check box "Do not create this product in a sandbox".)

6. Click the **Reserve product name** button.

   The "Game setup" page appears.

   (In the user interface prior to GDC 2019, the "App overview" page appears.)


### Old UI
<!--delete? old ui?-->
7. (If using the old UI): In the App overview page, click the **Start your submission** button.

   The "Start your submission" dialog box appears.

8. (If using the old UI): In the combo field, click the down-arrow on the right, then click a sandbox, such as "NKDXTT.0 (shared)".

9. (If using the old UI): Click the **Create submission** button.
 
   <!-- correct? or black-box wait? -->
   After some 12 seconds, the submission page appears, such as "NKDXTT.0 (Submission 1)".

   <!-- NOW WHAT DO YOU CLICK IN THE UI? -->

### New UI
   <!-- how to now get to the "Game Setup" page after approved? -->


## Get title approved

1. Wait for your game or other title to pass the Concept Approval process.

   When your game or other title passes "concept approval", you receive the email saying "your game concept has been accepted".
   In the "Game setup" page, the "Use full Xbox Live feature set" radio button then becomes un-dimmed and is available to select.

   While the game has not been concept-approved, you must keep the "Disable" radio button selected instead.
   <!-- where is the Disable option button visible? -->


## Enable title

<!-- later, what do you click in the UI to make the "Game setup" page appear?-->
1. In Partner Center dashboard, click __.

   The "Game setup" page appears. 

2. Select the option button **Use full Xbox Live feature set (requires concept approval)**.

   This option becomes visible after your game concept is approved.


<!--===========================================================-->
## Choose a sandbox

1. In the "Primary Xbox Live development sandbox" section, select a starting sandbox.

2. Click the **Save** button.

   Xbox Live functionality is now enabled for your game or other title.

   After the first call to Xbox Live APIs, after some 30-45 seconds, the page redirects to the "Gameplay Setting" page, which is your Xbox Live configuration page.

3. On the "Xbox Live" page (the "Create a product in Partner Center" page), click the **Publish** button.

   A <!--"Foo"--> dialog box appears.

4. Click the **Confirm** button.

   Your game or other title now has Xbox Live configuration in a sandbox, but doesn't have a binary running with the Xbox Live SDK or XDK.

   Your identity configuration information, including the Xbox Live "product identities", is copied into your sandbox for Xbox Live services.
   This only occurs the first time you click Publish (and Confirm) for the game.

   Your game, or the Android Sign-in sample (discussed in a later step), runs in the runtime of the sandbox, after you click the **Publish** button.

   It is now possible for your game to sign-in to Xbox Live services (discussed in a later step).


## Publish title


## Create Test Account


## Get Sample


## Sign in


<!--===========================================================-->
## Background information about configuring a game

There are two areas, which are configured through different means:
*  Configuration of services, including server ingestion of information about your game.
*  Your executable ("the client"), including packages.

Enhanced Resource Access (ERA) is a type of package.
For example, for game code such as the Sign-in sample for Android (discussed in a later step), you package the game code to run on Android hardware; compiling it for that hardware.
An ERA package runs on the Xbox One console.
In contrast, a UWP package has less performance optimization, but can run on both Xbox and Windows without writing as much code.

Currently, Windows supports Win32 and UWP.
Store listing = markets.  
The marketing page for your game is generated based on this metadata in these categories.


<!--===========================================================-->
## Next steps

[Choose platforms](choose-platforms.md)
