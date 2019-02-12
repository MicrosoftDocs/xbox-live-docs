---
title: Getting started, for ID@Xbox or Managed Partners
description: Get started adding Xbox Live functionality to your game, as a member of the ID@Xbox program or as a Managed Partner.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Getting started, for ID\@Xbox or Managed Partners

<!-- todo: add screen captures -->

To add Xbox Live functionality to a game or other title, start by creating a new app at Microsoft Partner Center.

This page is for members of the ID@Xbox or Managed Partners program.
If you are in the Creators program, see [Create a new title, for ID@Xbox or Managed Partners](../creators/create-title.md).


## 1. Set up a Partner Center account

   > [!PREREQUISITE]
   > As a prerequisite step, you must have a Partner Center account.
   > To create a Partner Center account, right-click the following link and click **Open in new tab**:
[Partner Center documentation site: Create a Partner Center account](https://docs.microsoft.com/en-us/partner-center/mpn-create-a-partner-center-account).
   >Then continue with the steps below.
   <!--todo: open link in new tab>


<!--===========================================================-->
## 2. Create a new app

Next, at Partner Center, create a new app, as follows.

1. Go to [Partner Center dashboard](https://partner.microsoft.com/dashboard/) (https://partner.microsoft.com/dashboard/).

   The Partner Center dashboard appears, showing the "Overview" page, within the "WINDOWS" section.

2. Click the **Create a new app** button.

   The page "Create your app by reserving a name" appears.

3. In the text box, enter the name of your product.
   You can change the name later.
   <!--
   used:
   GetStartManaged01mihof
   GettingStartedManaged02Greg (confirm).  Pre-approved, to access the post-approval UI.
   -->

4. Click the check box **Create this product in a sandbox**.

   > [!IMPORTANT]
   > For Managed Partners and ID@Xbox developers, to enable Xbox Live functionality, you **MUST** select the option button **Create this product in a sandbox**, the first time through this process. You won't be able to select this option button later.
   > (Do not select the check box "Do not create this product in a sandbox".)

5. Click the **Reserve product name** button.

   The "App overview" page appears.

6. In the App overview page, click the **Start your submission** button.

   The "Start your submission" dialog box appears.

7. In the combo field, click the down-arrow on the right, then click a sandbox. 
   For example, on the Xbox account, we have "NKDXTT.0 (shared)".

8. Click the **Create submission** button.
 
   After a delay, the submission page appears, showing the name of the sandbox and the submission number; for example, "NKDXTT.0 (Submission 1)".


<!--===========================================================-->
## 3. Request Concept Approval for your game

<!-- what if you are a Managed Partner? -->
1. If you are in the ID@Xbox program, send email to the ID@xbox team, requesting Concept Approval of your game.
   Send the email to __.
 
   The ID@Xbox team emails you the following:
   * A Non-Disclosure Agreement (NDA).
   * A Game Information Form (GIF).

2. Sign the Non-Disclosure Agreement and email it to the ID@Xbox team.

3. Fill-in the Game Information Form and email it to the ID@Xbox team.

   The ID@Xbox team reviews the Game Information Form.

   If your game concept is approved, the ID@Xbox team emails you, indicating that your game concept is approved.
   The ID@Xbox team also enables the Xbox Live user interface at Partner Center for your game.


<!--===========================================================-->
## 4. Enable Xbox Live for the title

When you receive the "concept approved" email, continue with the following steps.

1. Close the browser, to clear the session cache.
 
2. Open the browser.

3. Go to the Partner Center.

4. In Partner Center dashboard, click **Products**, then click your game.

   The Game Setup page appears.

5. Click the option button **Use full Xbox Live feature set (requires concept approval)**.

   The "App overview" page appears.

   Under "Services", "Xbox Live" now appears.

   The "Enable Xbox Live" page appears.
   The "Enable Xbox Live" page appears only the first time you click __ above.

6. Put in the name of the product, using the same name as before.

7. Click the "Enable" button.

   The "Gameplay Setting" page appears.

8. In the top right, click the **Publish** button.

   The "Publish gameplay settings" dialog box appears.

9. Click **Confirm**.

   At the bottom of the dialog box, the message appears: "Publishing configuration finished successfully."

   The game is actually published after a delay of possibly 20 minutes.

10. Click the **Close** button.

   The "Publish gameplay settings" dialog box closes.

The SDK can now be used in an application to sign-in.


<!--===========================================================-->
<!-- future UI:
## Choose a sandbox

1. In the "Primary Xbox Live development sandbox" section, select a starting sandbox.

2. Click the **Save** button.

   Xbox Live functionality is now enabled for your game or other title.

   After the first call to Xbox Live APIs, after some 30-45 seconds, the page redirects to the "Gameplay Setting" page, which is your Xbox Live configuration page.

3. On the "Xbox Live" page (the "Create a product in Partner Center" page), click the **Publish** button.

   A <!--"Foo" dialog box appears.-->

<!--
4. Click the **Confirm** button.

   Your game or other title now has Xbox Live configuration in a sandbox, but doesn't have a binary running with the Xbox Live SDK or XDK.

   Your identity configuration information, including the Xbox Live "product identities", is copied into your sandbox for Xbox Live services.
   This only occurs the first time you click Publish (and Confirm) for the game.

   Your game, or the Android Sign-in sample (discussed in a later step), runs in the runtime of the sandbox, after you click the **Publish** button.

   It is now possible for your game to sign-in to Xbox Live services (discussed in a later step).
-->


<!--===========================================================-->
## 5. Publish title

TBD


<!--===========================================================-->
## 6. Create Test Account

TBD


<!--===========================================================-->
## 7. Get Sample

TBD


<!--===========================================================-->
## 8. Sign in

TBD


<!--===========================================================-->
## Background information about configuring a game

There are two areas, which are configured through different means:
*  Configuration of services, including server ingestion of information about your game.
*  Your executable ("the client"), including packages.

Enhanced Resource Access (ERA) is a type of package.
For example, for game code such as the Sign-in sample for Android (discussed in a later step), you package the game code to run on Android hardware; compiling it for that hardware.
An ERA package runs on the Xbox One console.

In contrast, a UWP package has less performance optimization, but can run on both Xbox and Windows without writing as much code.

The marketing page for your game is generated based on the metadata in the categories listed under "Product":
* Name/Type
* Store Rating
* Store Listing (markets)
* Store Metadata
* Packages
* Xbox Live


<!--===========================================================-->
## Platforms

Supported package types for each platform:
* Xbox One supports and ERA, UWP packages.
* The PC supports Win32, UWP, and eventually MSIXVC packages.
* Android
* iOS


<!--===========================================================-->
## Next steps

TBD


<!--===========================================================-->
## See also

[Partner Center Xbox Live configuration Summary page](../../configure-xbl/dev-center/summary.md)
