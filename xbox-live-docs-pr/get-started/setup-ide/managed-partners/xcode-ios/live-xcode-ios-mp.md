---
title: Setting up Xcode targeting iOS
description: Setting up Xcode targeting iOS to use the Xbox Live SDK, for Managed Partners.
kindex: Setting up Xcode targeting iOS
kindex: Xcode
kindex: iOS
ms.topic: article
ms.localizationpriority: high
ms.date: 04/19/2019
---

# Setting up Xcode targeting iOS

Follow the steps in this article, in the order shown, to set up Xcode targeting iOS to use the Xbox Live SDK, for Managed Partners.
Afterwards, you'll be ready to follow the article about adding basic sign-in code for Xbox Live services.
Then you'll be able to call other Xbox Services API (XSAPI) functions.


## Prerequisite steps

* Set up a game in Partner Center; see [Getting Started](../../../live-getstarted-nav.md).

* Ensure you have a iOS project created in Xcode, set up to handle Objective-C.
  If your project is written in pure Swift, you will need to set up Objective-C interoperability.


## Download the Xbox Live SDK

Download the Xbox Live SDK for iOS to your local computer.

<!-- todo: need URL for iOS SDK -->


<!-- ## Add extensions to the project -->


<!-- ## Add dependencies to the project -->


## Add Xbox Live libraries to the project

Add the Xbox Live iOS frameworks (that is, libraries) to your project, as follows.

1. Under **Project Settings**, select the **General** tab, scroll down to **Embedded Binaries**, and then click the **+** button.

   The "Choose items to add" dialog box appears.

2. Click the **Add Other...** button.

   A file chooser dialog box appears.

3. Navigate to the **Xbox Live SDK** directory, select the Debug (or Release) version of the following libraries, which comprise the iOS Xbox Live SDK:
    - HttpClient.framework
    - Xal.framework
    - Xsapi-c.framework

4. Click the **Open** button.

   The "Choose options for adding these files" dialog box appears.

5. Select the **Copy items if needed** check box and the **Create folder references** check box, and then click the **Finish** button.

   A copy of the frameworks is added to the project, and the frameworks are embedded in the project build setup.


## Modify the build settings


### Capabilities tab

1. In Xcode, under **Project Settings**, at the top of the window, click the **Capabilities** tab.

   The "Capabilities" screen appears.

2. Scroll down to **Keychain Sharing** section and click it, so that it's set to **ON**.

3. In the **Keychain Groups** text boxes, add `com.microsoft.xal`.


### Info tab

1. Under **Project Settings**, at the top of the window, click the **General** tab, and then in the **Bundle Identifier** field, select and copy your app's bundle ID.

2. Under **Project Settings**, at the top of the window, click the **Info** tab.

   The "Info" screen appears.
 
<!-- 
Not bundlename+.xalAuth?
From get-started-with-ios-android/ios-get-started-with-xsapi.md : 
   For the **Identifier** field, enter: &lt;Your app's bundle name&gt;`.xalAuth`
-->

3. Scroll down to the **URL Types** section, click **+**, and then in the **Identifier** field, paste the bundle ID of your app.

4. In the **URL Schemes** text box, add `ms-xal-` followed by Microsoft Partner Client ID.
   For example, for the iOS Xbox Live sample app, the Microsoft Partner Client ID is "ms-xal-000000004824156C".


### Build Settings tab

1. Under **Project Settings**, click the **Build Settings** tab.

   The "Build Settings" screen appears.

2. In the **Search** field in the upper right, search for "Preprocessor Macros".

    For each build configuration under Preprocessor Macros, add both "XSAPI_C=1" and "XSAPI_I=1".

    If you are using cross-platform code, you can check for the "XSAPI_I" macro, to wall-off iOS-specific code.

3. In the Xcode project explorer pane, find the `Info.plist` file for your project, and open it in a text editor.

4. In the root dictionary, add the following settings:

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

5. In Xcode, open the `Info.plist` file.

    The file is displayed as nested rows.
    The **App Transport Security Settings** section should look like the following:

    ![App transport security settings](live-xcode-ios-mp-images/xblsdk-info-ats.png)


<!-- ## Prepare native files to initialize and cleanup Xbox Live -->


## Bind C++ to the native environment

The code in the Xbox Live SDK uses Microsoft's SAL annotation language.
Tell Xcode how to understand these SAL annotations, as follows.

1. Go to <a href="https://github.com/nemequ/salieri" target="_blank">https://github.com/nemequ/salieri</a> and download a copy of `salieri.h`, then continue here.

2. Add a prefix header to your Xcode project, as follows.
   First, find your Prefix Header file: Under **Project Settings**, click the **Build Settings** tab.

3. In the **Search** field in the upper right, search for "Prefix Header".

4. If the **Prefix Header** row found by the search is empty, create a new C header file in your project, called `pch.h`, and point the build setting to it.

   If the **Prefix Header** row found by the search is not empty, open the listed file, and then add the following code into the Prefix Header file:

```cpp
#ifdef __cplusplus
// Defines the Microsoft Visual Studio SAL annotations used in the C++ code.
// This workaround for non-VS cross-platform support for SAL comes from: https://github.com/nemequ/salieri
#import "salieri.h"
#define _Post_invalid_  // This annotation was added for SAL version 2, thus is not handled by the salieri.h workaround.

// C++ standard libraries.
#include <cstdlib>
#include <cerrno>
#include <memory>
#include <cassert>
#include <ctime>
#include <unistd.h>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <fstream>

#define UNREFERENCED_PARAMETER(P) (P)
#define ASSERT_MESSAGE(check_bool, failed_message) assert(check_bool && failed_message)

// Xbox Live SDK headers.
#include <xsapi-c/services_c.h>
#include <Xal/xal.h>
#include <Xal/xal_platform.h>
#endif
```

You have finished setting up Xcode targeting iOS to use the Xbox Live SDK.
You are now ready to follow the article about adding basic sign-in code for Xbox Live services, as C++ code in Objective-C++ files.
Then you'll be able to call other Xbox Services API (XSAPI) functions.


## Using C++ to call the Xbox Live SDK

All access to the Xbox Live SDK needs to be through C++.
In Xcode, this C++ is usually within Objective-C++ files.
You cannot directly call the Xbox Live SDK from Objective-C or Swift.

To call the Xbox Live SDK, you need to use Xcode's Objective-C++ files, which have an `*.mm` extension.

Objective-C++ files enable you to mix Objective-C and C++ code:

* You can import header files for both languages.

* You can run C++ code in Obj-C functions.

* You can run Obj-C code in C++ methods.


## Next step

Add basic sign-in code; see [Getting Started](../../../live-getstarted-nav.md).
