---
title: "Download the Events Manifest file from Partner Center"
description: "Procedures for downloading the Events Manifest file from Partner Center."
kindex: Downloading the Events Manifest file
kindex: Events Manifest, download
kindex: Events Manifest, publish
author: v-andrg
ms.author: v-andrg
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-downloading-events-manifest.html
---

# Download the Events Manifest file from Partner Center

<!-- 
article copied from secure docs portal "Download the Events Manifest file from Windows Dev Center"-->

**Note:** This article only applies if you are using event-based User Stats, not title-managed User Stats.

**Note:** This article describes the features available only with proper permissions. For details, talk to your account manager or another contact at Microsoft.

You download the Events Manifest file from Partner Center. 
The Events Manifest file contains information about your configuration for the selected sandbox.
The event manifest file is a binary file, such as `Events-NKDXTT.0.man`.

After defining or modifying your title's events, you must publish them to your Xbox Live sandbox or retail and use the following steps to download the Events Manifest file from Partner Center.
You then use the event manifest file, along with the **Xbox Common Events Tool**, to create header files that contain function definitions that your title can use to send events.


**To download and use the event manifest file:**

1. Sign in with your account in [Partner Center](https://developer.microsoft.com/dashboard/windows/overview).

2. Select your title, and go to **Services** > **Xbox Live**.

3. Click the link to **Stat rules**.

4. On the **Events & Stat Rules** page, click **Download published events manifest**.  

    The downloaded manifest contains only the configurations published to the sandbox most recently. Any unpublished changes you made are not included.

5. On the **Confirm** dialog, click **Download event manifest** to confirm your download; otherwise, click **Cancel**.

![Animated gif of the process of downloading the Events Manifest file](../../../../../../resources/gamecore/secure/images/en-us/live/events/download-manifest.gif)

   The browser starts downloading the event manifest file, which may have a name such as `Events-NKDXTT.0.man`.

6. Run the SDK's `XceTool.exe` command-line tool against that event manifest file to generate the events header file.

7. Include the generated events header file in your game project.


### See also

[Xbox Common Events Tool (xcetool.exe)](live-xbox-common-events-tool.md)

For an intro to the Xbox Live service configuration, see [Xbox Live service configuration](https://docs.microsoft.com/windows/uwp/xbox-live/xbox-live-service-configuration) (external link, to public docs).
