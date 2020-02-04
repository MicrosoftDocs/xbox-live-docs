---
title: Xbox Authentication Library (XAL) overview
author: aablackm
description: The Xbox Authentication Library (XAL) is a cross-platform authentication platform for Android and iOS.
ms.assetid: e54c98ce-e049-4189-a50d-bb1cb319697c
ms.author: aablackm
ms.date: 08/30/2018
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, authentication, sign-in
ms.localizationpriority: medium
---

# Xbox Authentication Library (XAL) overview

The Xbox Authentication Library (XAL) is a cross-platform authentication platform for Xbox Live.
XAL enables you to write code once and deploy it across previously unsupported Xbox Live platforms Android, and iOS.
XAL provides a consistent API and user model across all platforms.

The XAL library provides easy and controlled game integration:

* The library is written in C, making it easy to bind to other languages.

* XAL allows clients to be in control of threads, hard disk access, and UI handling.
  It allows developers to optionally control these areas when XAL requires it.
  This is done by providing functions that allow you to set event handlers to carry out the task in the manner best suited for your game's performance.

The XAL library gives you as much control of your game as possible, so you can fine-tune all aspects of performance.
XAL also allows games to override memory allocation functions and http requests.

XAL works on both Single User Application (SUA) and Multi User Application (MUA) platforms, and contains functions to allow you to differentiate between the two so that your code works across both.


## Working with XAL

Read the following articles to learn how to work with XAL in the general case and for any of its supported platforms.
* [Signing-in using XAL](live-xal-sign-in.md)
* [Getting started with the Xbox Live SDK for iOS](../../../../get-started/setup-ide/managed-partners/xcode-ios/other/ios-get-started-with-xsapi.md)
* [Getting started with the Xbox Live APIs on Android](../../../../get-started/setup-ide/managed-partners/as-android/other/android-get-started-with-xsapi.md)