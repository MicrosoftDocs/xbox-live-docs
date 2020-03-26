---
title: Using Xbox Live APIs built into the XDK
description: Using the built-in Xbox Live APIs in your Xbox Developer Kit (XDK) project.
kindex: Using Xbox Live APIs built into the XDK
ms.assetid: 539caca3-58bc-49d9-8432-ca8e57755be2
ms.topic: article
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Using Xbox Live APIs built into the XDK

1. Right-click on your project in Visual Studio, and click **References**.
2. Click **Add New Reference**.
3. Click on **Durango.<build number>** and **Extensions** on the left panel.
4. In the middle, do either:
   - To use the WinRT XSAPI API, click **Xbox Services API**.
   - To use the C++ XSAPI API, click **Xbox Services API Cpp**.
5. Click **OK**.

Note: If your build system doesn't support props files, you must manually add the preprocessor definitions and libraries, as seen in:
`%XboxOneExtensionSDKLatest%\ExtensionSDKs\Xbox.Services.API.Cpp\8.0\DesignTime\CommonConfiguration\Neutral\Xbox.Services.API.Cpp.props`
