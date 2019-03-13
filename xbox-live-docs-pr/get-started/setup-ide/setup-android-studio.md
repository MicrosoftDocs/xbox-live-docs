---
title: Setting up Android Studio for Xbox Live
description: Setting up Android Studio to use the Xbox Live SDK, to target Android.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one
ms.localizationpriority: medium
---
# Setting up Android Studio for Xbox Live

   > [!WARNING]
   > The following article is for ID@Xbox partners only.

   > [!IMPORTANT]
   > Prerequisite steps: 
   > *  Set up a game at Partner Center. See [Getting started](../index.md).
   > *  Have an existing game that you have created in [Android Studio](https://developer.android.com/studio/). 


<!--===================================================-->
## Get the Xbox Live SDK

<!-- Ask Jason, ask where the SDK will be, for users.  James used one from module from internal, packages, maven, manager.  James didn't incorp into Android Studio.

The XGD page below currently mentions 1703, and has no link yet to get zip file for SDK for a particular target (UWP, Xbox, Android, iOS). This will be for ID partners. Creators will get a public SDK at a public location.
 -->

<!-- Right-click the following link and then click **Open in new window**: -->
<!-- ["SDK Downloads" page at Xbox Game Dev portal](https://developer.microsoft.com/en-us/games/xbox/partner/live-downloads) -->
<a href="https://developer.microsoft.com/en-us/games/xbox/partner/live-downloads" target="_blank">"SDK Downloads" page</a> at Xbox Game Dev portal.


### Creators


### ID@Xbox Partners

<!-- 
Greg/Jason Sandlin: 
What will the planned URL be to get the public ID@Xbox XSAPI SDK?    eg at the secure site, per link below.
Hopefully the zip file is the 1902 build, which includes the .a lib files for Android.

The following page first bullet item has no links, but has old, 2017 info:
Xbox Live SDK
  Xbox Live SDK has moved!
    Starting with the 1703 release, the Xbox Live SDK is on GitHub, open source, and available to the public. To reference the Xbox Live Services API (XSAPI) in your project, use NuGet packages from NuGet.org.
 -->
1. Right-click the following link and then click **Open in new window**: [Xbox Live SDK](https://developer.microsoft.com/en-us/games/xbox/partner/live-downloads).


<!-- GREG question, review:  if extra account creation is needed to get SDK, beyond what's already set up before PC, where put this? above PC steps?
   > [!IMPORTANT]
   > Prerequisite steps for ID@Xbox partners:
   > For the above SDK link to work, you must have a __ account and must be registerd __.

 https://review.docs.microsoft.com/en-us/gaming/xbox-live/get-started-with-partner/create-a-new-title?branch=master

Create a Microsoft account
If you don't have a Microsoft Account (also known as an MSA), you will need to first create one at https://go.microsoft.com/fwlink/p/?LinkID=254486. If you have an Office 365 account, use Outlook.com, or have an Xbox Live account - you probably already have an MSA.

Register as an App Developer
You will need to register as an App Developer before you are allowed to create a new title in Partner Center.
To register go to https://developer.microsoft.com/en-us/store/register and follow the sign-up process. -->


2. In that page, click **Download SDK**.


<!--===================================================-->
## Configure Android Studio to use CMake and the NDK

Native Development Kit (NDK)


<!--===================================================-->
## Configure Android Studio to use the Xbox Live SDK

* Open the make or CMake file that builds your existing game project.

<!-- optional capture: Android Studio IDE capture showing minimum requirements 
if you make a Java project, IDE might create a make file.-->


### For ID@Xbox Partners, add libs and includes to project

In the IDE's make file or in a Cmake file:

1.  Add the following libraries, in the order shown:
    
    - libMicrosoft_Xbox_Services_Android.a
    - Xal.Android-RelAI32.a
    - CompactCoreCLL.Android-RelAI32.a
    - liblibHttpClient_141_Android_C.a
    - libssl.141.Android.a
    - libcrypto.141.Android.a

<!-- below is the non-Maven approach -->

2.  Add the following include directories from your XSAPI folder (your Android Maven `ndk` folder):

    - include/
    - include/cpprestinclude


<!--
### CMAKE option
If you want to use CMAKE, __.

CMakeLists.txt, contains cocos content:
# Add Additional Include Directories
-->


<!--===================================================
remove section for 1902
## Set up the Services.config file

* Add the following to your services config file `xboxservices.config`.
  Use the title id, service config id, and sandbox from your Partner Center account.

```xml
XBL.Sample.Android/app/main/res/raw/xboxservices.config
{
    "TitleId" : 12345678,
    "PrimaryServiceConfiId" : "abc123-abc123-abc123-abc123-abc123",
    "ClientId" : "000000123456A",
    "Sandbox" : "ABCDE.1"
}
```
-->


<!--====================================================-->
## Targeting Android


### Add preprocessor definitions

In your project's CMake file, add the following preprocessor definitions.

<!-- replace by actual cmake call: -->
```config
XSAPI_CPP=1
XSAPI_C=1
XSAPI_A=1
XSAPI_U=1
_NO_ASYNCRTIMP
_NO_PPLXIMP
_NO_XSAPIIMP
XBL_API_EXPORT
__STDC_WANT_LIB_EXT1__=1
ASIO_STANDALONE
```


<!-- section probably goes away for 1902 -->
### Add native modules and Java files

<!-- 
question: aar modules are internal, not public, needed by xsapi lib for android device usage. 
Will ms wrap .aar's, (and java files for notif & webview) into xsapi 1902 libs?

Maven should handle this for us?
 -->

1. Add the following native files:

    * The module file `com.microsoft.xboxlive.aar`

    * The module file `libHttpClient.aar`

    * The module file `XalAndroidJava.aar`

    * The file `NotificationListenerService.java`, for notification listener services (required by async).
      This file needs to be in or under the source directory: `com.microsoft.xboxlive`

    * The file `XblWebView.java`, for Xbox Live web view (required by XAL).
      This file needs to be in or under the source directory: `com.microsoft.xboxlive`
      <!-- move those java files into native setup integration with xsapi? -->


### Set up native integration with XSAPI

* Basic understanding of JNI, to link your code between Java and C++.
  In the `MainActivity.java` file...  
  This is how you implement a function call to a native C++, and how to retrieve that function in the native CPP.

* Set up the functions to initialize your native environment.
  This is needed to store the JavaVM and enact the Java environment, which are utilized later by the XSAPI integration files.

* Set up the web view call from native.

* Set up the file storage path.

* Initialize XSAPI.  `Game_Integration.h`


### Set up the emulator

<!-- todo: screen captures -->

1. In Android Studio, click the **Tools** menu, and then click **AVD Manager**.

   The "Android Virtual Device Manager" window appears.

2. Click the **Create Virtual Device** button.

   The "Virtual Device Configuration" window appears, showing the "Select Hardware" page.

3. Select your category of device.  

4. Select your device name.  

5. Click the **Next** button.

   The "System Image" page appears.  

6. Click a row to select your device's system image to download.

7. Click the **Next** button.

   The "Verify Configuration" page appears.  

8. Click the **Finish** button.

   The config runs, and sets up your virtual device to be used by Android Studio.


### Using the emulator

1. In Android Studio, click the **Tools** menu, and then click **AVD Manager**.

   The "Android Virtual Device Manager" window appears, showing the "Your Virtual Devices" page.

2. Double-click the virtual device you want to open; or, under the **Actions** heading, click the **Run** icon, which is a triangle pointing right.

   The AVD Manager starts your virtual device, and the emulator window appears.


<!--===================================================-->
## Next step

Now that your IDE is set up to use Xbox Live, continue with step 3: Writing code for your game to sign-in to Xbox Live.
See [Getting started](../index.md).
