---
title: Xbox Live Authentication Library (XAL) overview
author: aablackm
description: The Xbox Live Authentication Library (XAL) is a cross-platform authentication platform for Win32, Android, and iOS.
ms.assetid: e54c98ce-e049-4189-a50d-bb1cb319697c
ms.author: aablackm
ms.date: 08/30/2018
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, authentication, sign-in
ms.localizationpriority: medium
---
# Xbox Live Authentication Library (XAL) overview

The Xbox Live Authentication Library (XAL) is a cross-platform authentication platform for Xbox Live. XAL provides developers with a consistent API and user model across all platforms. XAL enables you to write code once and deploy it across multiple platforms. The platforms supported today are Win32, Android, and iOS.

In addition to being great for developers who want to release on multiple platforms, XAL is also the authentication solution for previously unsupported Xbox Live platforms such as Android and iOS.

The XAL library has been designed to facilitate easy and controlled game integration. The library is written in flat C, making it easy to bind to other languages. XAL does not spawn threads, access any hard disk, or show UI. It instead allows developers complete control in these areas when XAL requires it. This is done by providing functions that allow you to set event handlers to carry out this task in the manner best suited for your game's performance.  

XAL also allows developers to write their games such that they override memory allocation functions and http requests. The library was designed to give developers as much control of their game as possible so they can fine-tune all aspects of performance.

XAL works on both Single User Authentication (SUA) and Multi User Application (MUA) platforms, and contains functions to allow you to differentiate between the two so that your code works across both.

## Integrate XAL into Visual Studio

You can use Visual Studio to build both Win32 and Android applications. The following are general-use instructions for setting up XAL in the Visual Studio environment. These instructions are sufficient for using XAL in a Win32 environment, Android projects however, will require additional setup.

1. Add the following projects from the code source repo to your solution:

```
    - Source\Xal\Xal.{your platform}.vcxproj
    - Source\Xal\Xal.Core.vcxitems
    - Source\Xal\Xal.Platform.Common.vcxitems
    - External\CompactCoreCll\CompactCoreCll.{your platform}.vcxproj
    - External\CompactCoreCll\CompactCoreCll.Common.vcxproj
    - External\LibHttpClient\Build\libHttpClient.{vs toolset}.{your platform}.C\libHttpClient.{vs toolset}.{your platform}.C.vcxproj
    - External\LibHttpClient\Build\libcrypto.{vs toolset}.{your platform}\libcrypto.{vs toolset}.{your platform}.vcxproj
    - External\LibHttpClient\Build\libssl.{vs toolset}.{your platform}\libssl.{vs toolset}.{your platform}.vcxproj
```

1. Add the XAL project as a dependency to your project
1. Add Source\Xal\Include to your project include path
1. In your project file set $(HCLibPlatformType) to {your platform}
1. Import External\LibHttpClient\libHttpClient.props in your project

You can include multiple variations of the XAL and libHttpClient projects into your solution to target multiple platforms. We suggest that you use Visual Studio 2017 or later for your win32 and android projects.

Once you have both acquired and integrated the source, open the Xal.2017.sln to see the sample app projects that can be run on each platform, provided that you have the appropriate device or emulator. The sample apps are meant to provide sample code and practices for integrating XAL into you projects.

## Working with XAL

Read the following articles to learn how to work with XAL in the general case and for any of its supported platforms.

[XAL Sign-In](xal-sign-in.md)  
[Get Started with XAL on Win32](win32-xal.md)  
[Get Started with XAL on iOS](iOS-xal.md)  
[Get Started with XAL on Android](android-xal.md)