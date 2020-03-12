---
title: Xbox Live Account tool (XboxLiveAccountTool.exe)
description: Sets up existing test accounts for testing game scenarios.
kindex: Xbox Live Account tool (XboxLiveAccountTool.exe)
kindex: account tool
author: mikehoffms
ms.author: v-mihof
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.localizationpriority: medium
ms.date: 03/12/2018
edited: 00/00/0000
---

# Xbox Live Account tool (XboxLiveAccountTool.exe)

See also [Developer Account Tool to set up test accounts](../test-accounts/live-account-tool.md).

This command-line tool is part of `XboxLiveTools.zip`; see [Development tools for Xbox Live](live-tools.md).


<!-- There is a readme about this tool in the .zip file, containing the following. -->

## XboxLiveAccountTool (XBLAT) FAQ


### What is XBLAT?

The Xbox Live Account tool (XBLAT) is a tool designed to help title developers set up existing dev accounts for testing game scenarios.
For example, you can use XBLAT to change a dev account's gamertag, or quickly add 1000 followers to an account's friends list.
For more details, go to http://www.aka.ms/XboxLiveAccountTool.


### What can I do with XBLAT?

You can:
  1. View a user's profile settings, XUID, and active privileges
  2. Add a list of followers to a user's social graph, either from a text file or an XDP csv
  3. Manage a user's friends list: favorite, unfavorite, block, and unblock users you follow, and see if they follow you back
  4. Change your dev user's reputation (and see the raw reputation stat values immediately)
  5. Change a user's gamertag


### How do I log in?

You'll need the credentials of the user you want to manage and specify the correct sandbox.
Make sure that the dev account has access to the sandbox, otherwise the login might fail.
The tool was designed with dev accounts using a sandbox in mind.


### Can I use a retail account, or does it have to be a sandboxed account?

You can certainly use XBLAT to manage a retail account, but not all features are supported.
For example, you cannot change a retail user's reputation.


### How do I change a dev user's gamertag?

Navigate to the "Gamertag" tab and enter a gamertag.
Gamertags must only contain numbers, letters, and spaces and can be only 15 characters long.
Dev account gamertags must start with a 2.
Only one change is currently supported.


### How do I see my block list?

Navigate to the "People" tab and select the "Blocked" column header to sort by users who are currently blocked.


### How do I follow a large group of users?

If you have a list of XUIDs you want to follow, copy them into a text file.
Navigate to the "Follow" tab, select "Import list", and choose your file.
The XUIDs should populate in the list view.
Click "commit changes" to follow the users.


### How do I block someone?

Navigate to the "People" tab and select the user or users you want to block.
Press the "block" button and they'll get blocked in batches.
If you notice an error, simply retry later.


### How do I change my dev account's reputation?

Navigate to the "Reputation" tab.
Select the defaults you'd like, and press the "Commit changes" button to submit the request.
You'll see the reputation stat values change if the request is successful.


### What do the values in the Reputation tab mean?

Overall reputation is computed from three sub-reputations: Fairplay (multiplayer conduct), user-generated content (video clips and the like), and communications (messages and voice).
The raw values for each category can range from 0 to 75, where higher means the user's reputation is better.
The `OverallStatIsBad` tells you if the user has "Avoid Me" reputation.


### What's the black area at the bottom?

To keep you informed, we thought that it would be useful if debug output printed in the UI.
That area will tell you what the tool is up to and print any errors it runs into.


### Where's my gamerpic?

We're aware of a bug that some dev accounts do not get a gamerpic auto-generated at account creation time.


### Why are things happening so slowly?

For the batch operations (like adding followers), the tool automatically performs batches to prevent huge request sizes.


### How do I run XBLAT?

Extract Xbox Live SDK to a folder, and double-click the Tools\XboxLiveAccountTool.exe file to run it.


### I have a feature request! How do I get my feature incorporated?

Talk to your DAM with any feature requests and we'll see what we can do.
