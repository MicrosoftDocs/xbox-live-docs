---
title: Setting up Android Studio for Xbox Live
description: Setting up Android Studio to use the Xbox Live SDK.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one
ms.localizationpriority: medium
---
# Setting up Android Studio for Xbox Live

This article is for ID@Xbox partners.

Prerequisite step: [Setting up a game at Partner Center](setup-partner-center.md).


<!--===================================================-->
## Download Android Studio



<!--===================================================-->
## Get the Xbox Live SDK

Ask Jason, ask where the SDK will be, for users.  James used one from module from internal, packages, maven, manager.  James didn't incorp into Android Studio.

1. Right-click the following link and then click **Open in new window**: [Xbox Live SDK](https://developer.microsoft.com/en-us/games/xbox/partner/live-downloads).

2. In that page, __.


<!--===================================================-->
## Set up Android Studio to use the Xbox Live SDK

Create New Project


### Add additional SDK libraries (XSAPI)


### Add Include directories

The NuGet files already include directories and libs.


<!--
### CMAKE option
If you want to use CMAKE, __.

CMakeLists.txt, contains cocos contnetN:
# Add Additional Include Directories
-->


<!--===================================================-->
## Set up the Services.config file

XBL.Sample.Android/app/main/res/raw/xboxservices.config
{
"TitleId"
"PrimaryServiceConfiId
""ClientId"
"Sandbox"
}

<!--===================================================-->
## Next step

[Set up code for targeted devices](../setup-targets.md)
