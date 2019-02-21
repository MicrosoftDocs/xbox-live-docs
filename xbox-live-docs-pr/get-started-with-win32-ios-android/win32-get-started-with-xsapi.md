---
title: Get started with Xbox Live APIs on Win32 using binaries
author: KevinAsgari
description: Learn how to add and compile the Xbox Live APIs source in your Win32 project.
ms.author: kevinasg
ms.date: 09/21/2018
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, windows, win32
ms.localizationpriority: medium
---

# Get started with Xbox Live APIs on Win32


## Add the Xbox Live SDK to your Visual Studio project (using binaries, preferred option)

1. Download the Xbox Live SDK zip package to your local machine, and extract the contents to a local directory

2. Open Visual Studio, go to **Tools > Options > NuGet Package Manager => Package Sources**, and add the local directory to Available package sources.

3. Right click your project and select **Manage NuGet Packages...**

4. Set the **Package source** to the local folder containing the Xbox Live NuGet packages, and then browse packages.

5. Select the **Microsoft.Xbox.Live.SDK.Cpp.Win32** package and install it.

6. Include the appropriate services.h file in your app source:

    If you are using C++ APIs, add `#include "xsapi\services.h"`.  
    If you are using flat C APIs, add `#include "xsapi-c\services_c.h"`.


## Samples

The Win32 samples for achievements and social can be found in `Microsoft.Xbox.Services.VS2017.sln` under the `Win32\Tests` folder.
To build these samples, first build `Microsoft.Xbox.Services.Dependency.VS2017.sln`

> [!IMPORTANT]
> The Win32 samples use a trivial C# sign-in test app called `TestWebClient` for demonstration purposes only, but your actual game should render its own web page for sign-in.


## Usage differences for the Xbox Live APIs between UWP and Win32


### Sign-in and authorization

The main difference between the Xbox Live APIs for Win32 games, as opposed to Universal Windows Platform (UWP) and Xbox Developer Kit (XDK) games, lies in how Xbox Live members are signed in and authenticated.
Win32 games require an additional component known as the *Xbox Authentication Library (XAL)* in order to associate players with their Xbox Live identity.

After signing a player in with XAL, your game should then create an `xbox_live_context` and pass the XAL user handle as a parameter.
After that, the `xbox_live_context` should look and function the same as it does on UWP.

For more information about signing in a player by using XAL in a Win32 game, see [Xbox Live Authentication Library (Xal)](../using-xbox-live/auth/xal.md).


### xboxservices.config

The Xbox Live APIs for Win32 rely on `xboxservices.config` just like the UWP version does, but the expected location of the file is slightly different.
On UWP, the APIs look for the file in the app installation directory, but on Win32 they look for the file in the same directory as the game .exe.


### Title-Callable UI (TCUI)

Win32 does not currently provide any Title-Callable UI (TCUI), so the `title_callable_ui` APIs are not available to Win32 games.
Instead, games must create their own UI if they want to display profile cards, friend lists, etc.
