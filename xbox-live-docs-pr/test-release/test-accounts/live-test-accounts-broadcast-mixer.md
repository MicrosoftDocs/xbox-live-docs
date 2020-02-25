---
title: Broadcasting Xbox Live test accounts to Mixer
description: Creating test accounts for use with Mixer on your Xbox Live sandbox.
kindex: Broadcasting Xbox Live test accounts to Mixer
ms.topic: article
ms.date: 02/25/2020
---

# Broadcasting Xbox Live test accounts to Mixer

To log into Mixer using your Xbox Live test accounts, you can broadcast your Xbox Live test accounts to Mixer, by appending the sandbox name to the Mixer URL.

To test with accounts from your sandbox, you can add the query parameter `sandbox=` to the Mixer URL.
For example: `https://mixer.com/?sandbox=XDKS.1`

> [!IMPORTANT]
> **Sandbox IDs are case-sensitive.** Note the uppercase sandbox name in the above URL: `XDKS.1`. The lowercase sandbox name `xdks.1` won't work in the URL.


**To log in:**
1. Click the Login button in the upper, right.
2. In the dialog, click the **Log in with your Microsoft account** button.
3. This will show a second dialog where you can enter your credentials for your Xbox Live test account.

If you encounter the error message "There was an error logging you in: Content isolation not authorized", make sure you are not logged into Mixer in another tab or browser with a non-sandbox account.
The easiest way to get around this conflict is to open an in-private browser session.


## Broadcasting from your DevKit

If you're broadcasting from your DevKit, you'll be automatically placed in Test Stream mode.
You want to make sure that your game has a Title ID and Service Configuration ID.
If the game doesn't have a Title ID and Service Configuration ID, broadcasting won't work.


## Test Streams

See <a href="https://dev.mixer.com/guides/test-streams/introduction" target="_blank">Test Streams &#11008;</a> at Mixer Dev site.


## TroubleShooting


**Can't broadcast from Xbox One**

If you can't broadcast from Xbox One:
1. Make sure you are signed in.
2. Make sure the game has a Title ID and Service Configuration that you have access to.


**Video is not showing the correct frames**

If you are broadcasting from Xbox and you see test frames (such as the image of astronauts in a living room), this is because your game is not released yet and Xbox Live is blocking the broadcast.
To see the frames, go to the developer portal and change the embargo settings to allow broadcasting.

An alternative is to use a capture card instead of the guide, to broadcast.

The most popular workflow is to work with the test frames.
The video isn't necessary for testing and development, since the interactive controls appear and the Xbox is usually close enough to see.
