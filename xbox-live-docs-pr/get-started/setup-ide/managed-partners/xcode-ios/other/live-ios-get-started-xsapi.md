---
title: Getting started with Xbox Live SDK for iOS
description: Adding the Xbox Live SDK to an iOS project (older article).
kindex: Getting started with Xbox Live SDK for iOS
kindex: iOS, Xbox Live
author: JeffreyShi
ms.author: jeffshi
ms.topic: article
ms.localizationpriority: medium
ms.date: 03/10/2019
---

# Getting started with the Xbox Live SDK for iOS

This is an older and less comprehensive setup article.
Instead, start with the newer article [Setting up Xcode targeting iOS](../live-xcode-ios-mp.md), and if needed, check the present article for additional tips.

Use Xbox Live to connect all games across devices to play together.


## Add the Xbox Live SDK for iOS to your project

Xbox Live SDK for iOS contains 3 components as "frameworks" that you can reference in your game:
- HttpClient.framework
- Xal.framework
- Xsapi-c.framework


**To use Xbox Live SDK for iOS in your game:**

1. Download the Xbox Live SDK for iOS to your development machine.
1. Add all 3 frameworks to your Xcode workspace.
    1. Create a **Frameworks** group inside your project if one does not exist.
    1. Right-click the **Frameworks** group, and then click **Add Files to "{Your Project}"**.
    1. Navigate to the directory containing the Xbox Live SDK for iOS, and select all 3 frameworks (HttpClient.framework, Xal.framework, and Xsapi-c.framework).
        - Check **Copy items if needed**.
        - Select **Create folder references**.
1. Select your project, navigate to the **General** tab.
    1. Under the **Embedded Binaries** section, add all 3 frameworks.
1. Select your project, navigate to the **Capabilities** tab.
    1. Enable **Keychain Sharing**.
    1. Under **Keychain Sharing**, add the following keychain group to the list: **com.microsoft.xal**
1. Select your project, navigate to the **Info** tab.
    1. Expand **URL Types**, and click the **+** button.
    1. For the **Identifier** field, enter: &lt;Your app's bundle name&gt;`.xalAuth`
    1. For the **URL Schemes** field, enter the scheme portion of your custom redirect URI (for example, **ms-xal-00000000abcdef12**).
    1. For the **Role** field, select **Viewer**.
1. Select your project, navigate to the **Build Settings**, and add **XSAPI_C** to **Preprocessor Macros**.
1. Add the following setting to the **Info.plist** file of your project:
    ```xml
    <key>NSAppTransportSecurity</key>
    <dict>
        <key>NSExceptionDomains</key>
        <dict>
            <key>xboxlive.com</key>
            <dict>
                <key>NSExceptionAllowsInsecureHTTPLoads</key>
                <true/>
                <key>NSExceptionRequiresForwardSecrecy</key>
                <false/>
                <key>NSIncludesSubdomains</key>
                <true/>
            </dict>
        </dict>
    </dict>
    ```
