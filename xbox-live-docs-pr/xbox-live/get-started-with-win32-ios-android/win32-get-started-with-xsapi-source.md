---
title: Including XBL API sources in a Win32 project, for debugging
author: KevinAsgari
description: Add and compile Xbox Live APIs source in a Win32 project, for debugging into the XBL sources.
ms.author: kevinasg
ms.date: 09/21/2018
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, windows, win32
ms.localizationpriority: medium
---

# Including XBL API sources in a Win32 project, for debugging

To use the Xbox Live APIs with a Win32 game, when you need to debug into the Xbox Live source code, include the Xbox Live API source in your project and build it.


## Add the Xbox Live SDK projects to your Visual Studio solution (using source code)

> [!NOTE]
> Only use this option if you need to debug through the Xbox Live SDK source code or make customized changes.

1. Add the Xbox Live API props file to your solution by clicking **View->Other Windows->Property manager**.

1. Right click your project and select **Add existing property sheet** and select `xsapi.staticlib.props` in the Xbox Live API source root.

    This automatically updates your include path and adds references to the Xbox Live APIs and all of the dependencies.

1. Add the following dependency projects to your solution:  

    For Visual Studio 2017:

    * `Build\Microsoft.Xbox.Services.141.Win32.Cpp\Microsoft.Xbox.Services.141.Win32.Cpp.vcxproj`
    * `External\xal\Source\Xal\Xal.Core.vcxitems`
    * `External\xal\Source\Xal\Xal.Platform.Common.vcxitems`
    * `External\xal\Source\Xal\Xal.Win32.vcxproj`
    * `External\xal\External\libHttpClient\Build\libcrypto.141.Win32\libcrypto.141.Win32.vcxproj`
    * `External\xal\External\libHttpClient\Build\libssl.141.Win32\libssl.141.Win32.vcxproj`
    * `External\xal\External\libHttpClient\Build\libHttpClient.141.Win32.C\libHttpClient.141.Win32.C.vcxproj`

    For Visual Studio 2015:

    * Use the same set of files for 2017, but replace the 141 in the paths with 140.

1. Include the appropriate services.h file in your app source:

    If you are using C++ APIs, add `#include "xsapi\services.h"`.  
    If you are using flat C APIs, add `#include "xsapi-c\services_c.h"`.


## Samples

Included in the SDK download are Win32 samples for achievements and social, under `{Xbox Live API root}\InProgressSamples\ID@XboxSDK`.

> [!IMPORTANT]
> The Win32 samples use a C# sign-in app for demonstration purposes, but your actual game should render its own web page for sign-in.


## Usage differences for the Xbox Live APIs between UWP and Win32


### Sign-in and authorization

The main difference between the Xbox Live APIs for Win32 games as opposed to Universal Windows Platform (UWP) and Xbox Developer Kit (XDK) games lies in how Xbox Live members are signed in and authenticated. Win32 games require an additional component known as the Xbox Authentication Library (XAL) in order to associate players with their Xbox Live identity.

After signing a player in with XAL, your game should then create an xbox_live_context and pass the XAL user handle as a parameter. After that, the xbox_live_context should look and function the same as it does on UWP.

For more information about signing in a player by using XAL in a Win32 game, see [Xbox Live Authentication Library (Xal)](../using-xbox-live/auth/xal.md).


### xboxservices.config

The Xbox Live APIs for Win32 rely on xboxservices.config just like the UWP version does, but the expected location of the file is slightly different:
* On UWP, the APIs look for the file in the app installation directory.
* On Win32, the APIs look for the file in the same directory as the game .exe.


### Title-Callable UI (TCUI)

Win32 does not currently provide any Title-Callable UI (TCUI), so the `title_callable_ui` APIs are not available to Win32 games.
Instead, games must create their own UI if they want to display profile cards, friend lists, etc.
