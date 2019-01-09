---
title: Add an XSAPI binary package to a UWP project
description: Using NuGet to add the Xbox Live APIs binary package to your UWP project.
ms.assetid: 1e77ce9f-8a0e-402c-9f46-e37f9cda90ed
ms.date: 11/28/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, nuget
ms.localizationpriority: medium
---

# Add an XSAPI binary package to a UWP project


## Requirements

1. **[Windows 10](https://microsoft.com/windows)**.
2. **[Visual Studio](https://www.visualstudio.com/)**. UWP apps can be built with Visual Studio 2015 Update 3 or later. We recommend that you use the latest release of Visual Studio for developer and security updates.
3. **[Windows 10 SDK](https://developer.microsoft.com/windows/downloads/windows-10-sdk) v10.0.10586.0** or later.


## Add the binary package via NuGet

To use the Xbox Live API from your project, you can either add references to the binaries by using NuGet packages or by adding the API source.
Adding NuGet packages makes compiling faster; adding the source makes debugging easier.

This article will walk through using NuGet packages.
If you instead want to use source, see [Compiling the Xbox Live APIs Source In Your UWP Project](add-xbox-live-apis-source-to-a-uwp-project.md).

The Xbox Services API comes in flavors for both UWP and XDK, and for C++ and WinRT and have their namespace structured as **Microsoft.Xbox.Live.SDK.*.UWP** and **Microsoft.Xbox.Live.SDK.*.XboxOneXDK**.

* **UWP** is for developers who are building a UWP game, which can run on either PC, the Xbox One, or Windows Phone.
* **XboxOneXDK** is for ID@Xbox and managed developers who are using the Xbox One XDK.
* The C++ SDK can be used for C++ game engines, where as the  WinRT SDK is for game engines written with C++, C#, or JavaScript.
* When using WinRT with a C++ engine, you should use C++/CX, which uses carets, or hats (^). C++ is the recommended API to use for C++ game engines.

> [!TIP]
> You can read more about running UWP on Xbox One at [Getting started with UWP app development on Xbox One](https://docs.microsoft.com/windows/uwp/xbox-apps/getting-started).

You can add the Xbox Live SDK NuGet package, as follows:
1. In Visual Studio, go to **Tools** > **NuGet Package Manager** > **Manage NuGet Packages for Solution...**.
2. In the NuGet package manager, click on **Browse** and enter **Xbox.Live.SDK** in the search box.
3. From the list on the left, select the version of the Xbox Live SDK that you want to use.
3. On the right side of the window, check the box next to your project and click **Install**.

> [!NOTE]
> Xbox Live Creators Program developers must use one of the UWP versions of the Xbox Live SDK, as XDK is not supported.

![add XBL via NuGet](../images/getting_started/vs-add-nuget-xbl.gif)

> [!IMPORTANT]
> For `Microsoft.Xbox.Live.SDK.Cpp.*` based projects, make sure to include the header `#include <xsapi\services.h>` in your project's source.
