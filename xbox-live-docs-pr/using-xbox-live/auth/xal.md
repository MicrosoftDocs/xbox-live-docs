---
title: Authentication for Mobile Projects
description: The Xbox Live Authentication Library (XAL) is a cross-platform authentication platform for Win32, Android, and iOS.
ms.date: 08/30/2018
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, authentication, sign-in
ms.localizationpriority: medium
---

# Authentication for Mobile Projects
The Xbox Live Authentication Library, or XAL, is a cross platform authentication platform for Xbox Live. XAL provides developers with a consistent api and user model across all platforms. XAL will allow you to write code once and deploy it across multiple platforms. The platforms supported today are Win32, Android, and iOS. In addition to being great for developers who want to release on multiple platforms it is also the authentication solution for previously unsupported Xbox Live platforms such as Android and iOS.
The Xbox Live Authentication Library (XAL) is a cross-platform authentication platform for Xbox Live.
The XAL library has been designed to facilitate easy and controlled game integration. The library is written in flat C, making it easy to bind to other languages. XAL does not spawn threads, access any hard disk, or show UI. It instead allows developers complete control in these areas when XAL requires it. This is done by providing functions that allow you to set event handlers to carry out this task in the manner best suited for your game's performance.  It also allows developers to write their games such that they override memory allocation functions and http requests. The library was designed to give developers as much control of their game as possible so they can fine tune all aspects of performance.

XAL works on both Single User Authentication (SUA) and Multi User Application (MUA) platforms, and contains functions to allow you to differentiate between the two so that your code works across both.

## In this section
You can use Visual Studio to build both Win32 and Android applications, the following are general use instructions for setting up XAL in the Visual Studio environment. These instructions are sufficient for using XAL in a Win32 environment, Android projects however, will require additional setup.

| Article | Description |
|---------|-------------|
| [Xbox Live Authentication Library (XAL) overview](xal-overview.md) | The Xbox Live Authentication Library (XAL) is a cross-platform authentication platform for Win32, Android, and iOS. |
You can include multiple variations of the XAL and libHttpClient projects into your solution to target multiple platforms. We suggest that you use Visual Studio 2017 or later for your win32 and android projects.
| [Setting up Visual Studio for XAL login on Win32](win32-xal.md) | Signing in to Xbox Live with an Win32 project. |
| [Setting up Visual Studio for XAL login on Android](android-xal.md) | Signing in to Xbox Live with an Android project. |
| [Setting up Xcode for sign-in with iOS](iOS-xal.md) | Signing in to Xbox Live with an iOS project. |
