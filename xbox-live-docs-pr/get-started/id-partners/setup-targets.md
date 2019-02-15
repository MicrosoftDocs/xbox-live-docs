---
title: Set up code for targeted devices
description: Set up code for the targeted devices, such as adding preprocessor definitions.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Set up code for targeted devices

Prerequisite: [Setting up an IDE for Xbox Live](set-up-ide/index.md)


<!--====================================================-->
## UWP

There is no setup required when targeting UWP.


<!--====================================================-->
## Xbox


<!--====================================================-->
## iOS


<!--====================================================-->
## Android


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


### Add in native core integration files

<!-- question: aar modules are internal, not public, needed by xsapi lib for android device usage. Will ms wrap .aar's, (and java files for notif & webview) into xsapi 1902 libs? -->

Add the native core integration files:
* The .aar module: com.microsoft.xboxlive.aar
* The .aar module: libHttpClient
* The .aar module: XalAndroidJava
* The Java file NotificationListenerService, for notification listener services (required by async). This needs to be in or under the source directory: com.microsoft.xboxlive
* The Java file XblWebView, for Xbox Live web view (required by XAL). This needs to be in or under the source directory: com.microsoft.xboxlive

<!-- Add these two native Java files, if 1810. -->


### Set up native integration with XSAPI for Android

* Set up to initialize your native environment.

* Set up for the web view call from native.

* Set up the file storage path.

That incorporates the integration files that are needed to store the Java vm and enact the Java environment, which are utilized by the native core integration files.


## Next step

[Signing-in to Xbox Live](sign-in.md)
