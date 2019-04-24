---
title: Using the Xbox Live SDK in Xcode projects targeting iOS
description: Using Xcode targeting iOS, through C++ in Objective-C++ files.
ms.date: 04/24/2019
ms.topic: article
keywords: xbox live, games, xcode, ios
ms.localizationpriority: medium
---

# Using the Xbox Live SDK in Xcode projects targeting iOS


## Use C++ to call the Xbox Live SDK

All access to the Xbox Live SDK needs to be through C++. <!-- or through Objective-C++?  through C++ that is usually within Objective-C++ files?-->
You cannot directly call the Xbox Live SDK from Objective-C or Swift.


## Objective-C++

To call the Xbox Live SDK, <!-- the Xbox Services API?--> you need to use Xcode's _Objective-C++_ files, which have an `*.mm` extension.
  Objective-C++ files enable you to mix Objective-C and C++ code:
    - You can import header files for both languages.
    - You can run C++ code in Obj-C functions.
    - You can run Obj-C code in C++ methods.
