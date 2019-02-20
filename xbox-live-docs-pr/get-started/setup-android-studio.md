---
title: Setting up Android Studio for Xbox Live
description: Setting up Android Studio to use the Xbox Live SDK, to target Android.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one
ms.localizationpriority: medium
---
# Setting up Android Studio for Xbox Live

This article is for ID@Xbox partners; Creators set up Visual Studio instead.

   > [!IMPORTANT]
   > Prerequisite steps: 
   > *  Set up a game at Partner Center. See [Getting started](index.md).
   > *  Have an existing game that you have created in Android Studio.


<!--===================================================-->
## Get the Xbox Live SDK

<!-- Ask Jason, ask where the SDK will be, for users.  James used one from module from internal, packages, maven, manager.  James didn't incorp into Android Studio. -->

### Creators

TBD


### ID@Xbox Partners

1. Right-click the following link and then click **Open in new window**: [Xbox Live SDK](https://developer.microsoft.com/en-us/games/xbox/partner/live-downloads).

2. In that page, click **Download SDK**.


<!--===================================================-->
## Configure Android Studio to use the Xbox Live SDK

* Open the make or CMake file that builds your project.


### For ID@Xbox Partners, add libs and includes to project

Add the following libs and includes in either the IDE's make file or in a Cmake file.

1.  Add the following libraries, in the order shown:
    
    ```
    libMicrosoft_Xbox_Services_Android.a
    Xal.Android-RelAI32.a
    CompactCoreCLL.Android-RelAI32.a
    liblibHttpClient_141_Android_C.a
    libssl.141.Android.a
    libcrypto.141.Android.a
    ```

2.  Add the following include directories from your XSAPI folder (your Android Maven ndk folder):

    ```
    include/
    include/cpprestinclude
    ```

#### IDE (Make) file


#### Cmake file versions



<!--
### CMAKE option
If you want to use CMAKE, __.

CMakeLists.txt, contains cocos contnetN:
# Add Additional Include Directories
-->


<!--===================================================
remove section for 1902
-->
## Set up the Services.config file

* Add the following to your services config file `xboxservices.config`.
  Use the title id, service config id, and sandbox from your Partner Center account.

```
XBL.Sample.Android/app/main/res/raw/xboxservices.config
{
    "TitleId" : 12345678,
    "PrimaryServiceConfiId" : "abc123-abc123-abc123-abc123-abc123",
    "ClientId" : "000000123456A",
    "Sandbox" : "ABCDE.1"
}
```


<!--====================================================-->
## Targeting Android


### Add preprocessor definitions

Add the following preprocessor definitions.
For example, you could add them in the CMake file.

```
XSAPI_CPP=1
XSAPI_C=1
XSAPI_A=1
XSAPI_U=1
_NO_ASYNCRTIMP
_NO_PPLXIMP
_NO_XSAPIIMP
XBL_API_EXPORT
__STDC_WANT_LIB_EXT1__=1
ASIO_STANDALONE
```

<!-- section goes away for 1902 -->
### Add native modules and Java files

<!-- question: aar modules are internal, not public, needed by xsapi lib for android device usage. Will ms wrap .aar's, (and java files for notif & webview) into xsapi 1902 libs? -->

1. Add the following native core integration files:
    * The .aar module: com.microsoft.xboxlive.aar
    * The .aar module: libHttpClient
    * The .aar module: XalAndroidJava
    * The Java file NotificationListenerService, for notification listener services (required by async). This needs to be in or under the source directory: com.microsoft.xboxlive
    * The Java file XblWebView, for Xbox Live web view (required by XAL). This needs to be in or under the source directory: com.microsoft.xboxlive
    
<!-- Add these two native Java files, if 1810. -->


### Set up native integration with XSAPI

* Set up to initialize your native environment.

* Set up for the web view call from native.

* Set up the file storage path.

That incorporates the integration files that are needed to store the Java vm and enact the Java environment, which are utilized by the native core integration files.


### Setup emulator


<!--===================================================-->
## Next step

Now that your IDE is set up to use Xbox Live, continue with step 3: Writing code for your game to sign-in to Xbox Live.
See [Getting started](index.md).
