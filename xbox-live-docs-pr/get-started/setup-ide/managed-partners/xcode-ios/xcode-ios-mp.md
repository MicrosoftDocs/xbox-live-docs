---
title: Setting up Xcode targeting iOS
description: Setting up Xcode targeting iOS to use the Xbox Live SDK, for Managed Partners.
ms.date: 04/19/2019
ms.topic: article
keywords: xbox live, games
ms.localizationpriority: medium
---

# Setting up Xcode targeting iOS

Setting up Xcode targeting iOS to use the Xbox Live SDK, for Managed Partners.


## Prerequisite steps

* Ensure you have a iOS project created in Xcode, set up to handle Objective-C.
  If your project is written in pure Swift, you will need to set up Objective-C interoperability.


## Download the Xbox Live SDK

Download the Xbox Live SDK for iOS to your local computer.

<!-- todo: need URL for iOS SDK -->

The iOS Xbox Live SDK consists of 3 libraries (known in Xcode as frameworks):
- HttpClient.framework
- Xal.framework
- Xsapi-c.framework
These come in two flavors: Debug and Release.


<!-- ## Add extensions to the project -->


<!-- ## Add dependencies to the project -->


## Add Xbox Live libraries to the project

Add the 3 XBL iOS frameworks to your project, as follows.

1. Under **Project Settings**, select the "General" tab, and scroll down to "Embedded Binaries".
   Click the "+" button, and in the dialog that appears, click the "Add Other..." button.
   Navigate to the Xbox Live SDK directory, select the three frameworks (either the Debug or Release versions), and then click **Open**.

2. On the next dialog, select "Copy items if needed" and "Create folder references".
   Click "Finish".

   A copy of the frameworks will be added to your project, and embedded in the project build setup.


## Modify the build settings

1. Under project settings, select the **Capabilities** tab.
	a. Enable **Keychain Sharing**.
	b. Under **Keychain Sharing**, add "com.microsoft.xal" to **Keychain Groups**.

2. Under project settings, select the **Info** tab.
	a. Under **URL Types**, click the **+** button to add an entry.
	b. In **Identifier**, add the bundle identifier of your app.
		- (found at the top of the **General** tab... your app's bundle ID)
	c. In "URL Schemes", add "ms-xal-" and your Microsoft Partner Client ID.
		- for example, for the sample app, this is "ms-xal-000000004824156C".

3. Under project settings, select the **Build Settings** tab.
	a. Search for "Preprocessor Macros", and add "XSAPI_C=1" and "XSAPI_I=1" to each build configuration. If you are using cross-platform code, you can check for the "XSAPI_I" macro to wall-off iOS-specific code.

4. Find the `Info.plist` file for your project, and open it in a text editor.
	a. Add the following settings in the root dictionary:

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

	b. If you open `Info.plist` from Xcode, the section should look like the following:

   ![App transport security settings](xblsdk-info-ats.png)



<!-- ## Prepare native files to initialize and cleanup Xbox Live -->


## Bind C++ to the native environment

The Xbox Live SDK uses Microsoft's SAL annotation language in their code, but Xcode doesn't understand these annotations.
Go to <a href="https://github.com/nemequ/salieri" target="_blank">https://github.com/nemequ/salieri</a> and download a copy of `salieri.h`.

	a. Add this header to your Xcode project.
	b. Find your Prefix Header file:
		- Under project settings, select the **Build Settings** tab.
		- Search for "Prefix Header".
		- If empty, create a new C header file in your project, called `pch.h`, and point the build setting to it.
		- If not empty, open the listed file.
	c. Add the following to the Prefix Header file:

```cpp
#ifdef __cplusplus
// Defines the Microsoft Visual Studio SAL annotations used in the C++ code.
// This workaround for non-VS cross-platform support for SAL comes from here: https://github.com/nemequ/salieri
#import "salieri.h"
#define _Post_invalid_  // This annotation was added for SAL 2... not handled by the salieri.h workaround.

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

Notes about using the Xbox Live SDK in Xcode iOS projects:
	a. All access to the Xbox Live SDK needs to be through C++. You cannot directly call the SDK from Objective-C or Swift.
	b. You will need to make use of Xcode's Objective-C++ files (*.mm). These allow you to mix Objective-C and C++ code:
	   	- You can import header files for both languages.
	   	- You can run C++ code in Obj-C functions.
	   	- You can run Obj-C code in C++ methods.


## See also

[Getting Started](../../../index.md)
