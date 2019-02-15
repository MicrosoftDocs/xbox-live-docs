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


### Add preprocessor definitions



<!--====================================================-->
## iOS


### Add preprocessor definitions



<!--====================================================-->
## Android


### Add preprocessor definitions



In CMake file, add lines:

XSAPI_CPP=1
XSAPI_C=1
...
XSAPI_A=1
XSAPI_U=1


### Add in native core integration files

Add the native core integration files:

<!-- question: aar modules are internal, not public, needed by xsapi lib for android device usage. Will ms wrap .aar's, (and java files for notif & webview) into xsapi 1902 libs? -->
* .aar modules.    
* The Java file for notification listener services (required by async).
* The Java file for Xbox Live web view (required by XAL).

Add these two native Java files, if 1810.


### Set up XSAPI integration for Android

That incorps the integratino files needed to store the java vm and enact the java envir., whihc are utilized by the native core integration files.


## Next step

[Signing-in to Xbox Live](sign-in.md)
