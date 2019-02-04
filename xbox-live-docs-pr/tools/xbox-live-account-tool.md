---
title: Developer Account Tool to set up test accounts
description: The Xbox Live Developer Account Tool creates test accounts for testing your Xbox Live enabled title.
ms.assetid: ec5959f9-1c60-4aa4-94a6-5d8bdcf77a96
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, testing, test accounts
ms.localizationpriority: medium
---

# Developer Account Tool to set up test accounts

The Xbox Live Developer Account Tool is a tool to help title developers set up existing dev accounts for testing game scenarios.

For example, you can use Xbox Live Account Tool to change a dev account's gamertag, or quickly add 1000 followers to an account's friends list.


## What can I do with Xbox Live Account Tool?

You can:
* View a user's profile settings, XUID, and active privileges.
* Add a list of followers to a user's social graph, either from a text file or an Xbox Developer Platform csv.
* Manage a user's friends list: favorite, unfavorite, block, and unblock users you follow, and see if they follow you back.
* Change your dev user's reputation (and see the raw reputation stat values immediately).
* Change a user's gamertag.


## Where can I find Xbox Live Account Tool?

The Xbox Live Account Tool can be found as part of the Xbox Live Tools package from [https://aka.ms/xboxliveuwptools](https://aka.ms/xboxliveuwptools).


## How do I log in?

You'll need the credentials of the user you want to manage and specify the correct sandbox.
Make sure that the dev account has access to the sandbox, otherwise the login might fail.

The tool was designed with dev accounts using a sandbox in mind.


## Can I use a retail account, or does it have to be a sandboxed account?

You can certainly use Xbox Live Account Tool to manage a retail account, but not all features are supported.
For example, you cannot change a retail user's reputation.


## How do I change a dev user's gamertag?

Navigate to the **Gamertag** tab and enter a gamertag.
Gamertags must only contain numbers, letters, and spaces and can be only 15 characters long.

Dev account gamertags must start with a 2.

Only one change is currently supported.


## How do I see my block list?

Navigate to the **People** tab and select the **Blocked** column header to sort by users who are currently blocked.


## How do I follow a large group of users?

1. If you have a list of XUIDs you want to follow, copy them into a text file.

2. Navigate to the **Follow** tab, select **Import list**, and choose your file.

   The XUIDs populate in the list view.

3. Click **Commit Changes** to follow the users.


## How do I block someone?

1. Navigate to the **People** tab, then select the user or users you want to block.

2. Click the **block** button.

   The users will get blocked in batches.

If you notice an error, retry again later.


## How do I change my dev account's reputation?

Navigate to the **Reputation** tab.
Select the defaults you'd like, and press the **Commit changes** button to submit the request.

If the request is successful, you'll see the reputation stat values change.


## What do the values in the Reputation tab mean?

Overall reputation is computed from three sub-reputations: Fairplay (multiplayer conduct), user-generated content (video clips and the like), and communications (messages and voice).
The raw values for each category can range from 0 to 75, where higher means the user's reputation is better.

`OverallStatIsBad` tells you if the user has "Avoid Me" reputation.


## What's the black area at the bottom?

To keep you informed, we thought that it would be useful if debug output printed in the UI.
That area will tell you what the tool is up to and print any errors it runs into.


## Where's my gamerpic?

We're aware of a bug that some dev accounts do not get a gamerpic auto-generated at account creation time.


## Why are things happening so slowly?

For the batch operations (like adding followers), the tool automatically performs batches to prevent huge request sizes.


## How do I run Xbox Live Account Tool?

Extract Xbox Live SDK to a folder, and double-click the `Tools\XboxLiveAccountTool.exe` file to run it.


## I have a feature request! How do I get my feature incorporated?

Talk to your Microsoft representative with any feature requests and we'll see what we can do.
