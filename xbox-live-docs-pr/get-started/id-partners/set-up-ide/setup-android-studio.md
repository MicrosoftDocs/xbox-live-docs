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

<!-- tag as IMPORTANT -->
Prerequisite steps:
* [Setting up a game at Partner Center](../setup-partner-center.md).
* Have a demo of your game as an Android Studio project.


<!--===================================================-->
## Download Android Studio



<!--===================================================-->
## Get the Xbox Live SDK

<!-- Ask Jason, ask where the SDK will be, for users.  James used one from module from internal, packages, maven, manager.  James didn't incorp into Android Studio. -->

1. Right-click the following link and then click **Open in new window**: [Xbox Live SDK](https://developer.microsoft.com/en-us/games/xbox/partner/live-downloads).

2. In that page, click **Download SDK**.


<!--===================================================-->
## Set up Android Studio to use the Xbox Live SDK

* Open the make or CMake file that builds your project.


### Add additional SDK libraries (XSAPI)

* Add the following libraries, in the order shown:
    
    ```
    libMicrosoft_Xbox_Services_Android.a
    Xal.Android-RelAI32.a
    CompactCoreCLL.Android-RelAI32.a
    liblibHttpClient_141_Android_C.a
    libssl.141.Android.a
    libcrypto.141.Android.a
    ```
    
### Add Include directories

* Add the following include directories from your XSAPI folder (your Android Maven ndk folder):

    ```
    include/
    include/cpprestinclude
    ```
    
<!--
### CMAKE option
If you want to use CMAKE, __.

CMakeLists.txt, contains cocos contnetN:
# Add Additional Include Directories
-->


<!--===================================================-->
## Set up the Services.config file


* Add the following to your services config file `xboxservices.config`.
  Use the title id, service config id, and sandbox from your Partner Center account.

```
XBL.Sample.Android/app/main/res/raw/xboxservices.config
{
    "TitleId" : 12345678,
    "PrimaryServiceConfiId" : "abc123-abc123-abc123-abc123-abc123",
    ""ClientId" : "000000123456A",
    "Sandbox" : "ABCDE.1"
}
```

<!--===================================================-->
## Next step

[Set up code for targeted devices](../setup-targets.md)
