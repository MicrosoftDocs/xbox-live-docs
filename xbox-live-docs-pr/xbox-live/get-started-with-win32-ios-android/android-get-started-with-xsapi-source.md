---
title: Get started with Xbox Live APIs on Android
author: KevinAsgari
description: Learn how to add and compile the Xbox Live APIs source in your Android project.
ms.author: kevinasg
ms.date: 09/21/2018
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, android
ms.localizationpriority: medium
---

# Get started with Xbox Live APIs on Android

To use the Xbox Live APIs with an Android game, you can use the pre-compiled binaries, or include the Xbox Live API source in your project and build it.


## Requirements

You must use Visual Studio 2017 or later in order to build the Xbox Live APIs.
Your Visual Studio instance requires the following components in order to build and deploy Android projects:

* Workloads
  * Mobile development with C++
* Individual Components
  * Visual Studio Emulator for Android
  * Android SDK setup (API Level 27)
* Extensions
  * [Java Language Service for Android and Eclipse Android Project Import](https://marketplace.visualstudio.com/items?itemName=VisualCPPTeam.JavaLanguageServiceforAndroidandEclipseAndroidProj )


## Add the Xbox Live API projects to your Visual Studio solution

> [!NOTE]
> Only use this option if you need to debug through the Xbox Live SDK source code or make customized changes.

Since Android apps are typically written in Java, your Visual Studio solution will need two projects that work in conjunction with each other.

Your first project consists of all of the Java code that interactions with the Android application environment, including the entry point to your application that is called from the Android OS when your app starts.
This project is typically created by using the **Visual C++ > Cross Platform > Android > Basic Application (Android, Gradle)** project template.

The second project contains the Java Native Interface (JNI) layer that the Java application references to call the native code for the Xbox Authorization Library (XAL) and Xbox Live APIs.

You can see examples of these projects in the SocialAndroidJNI sample, which you can find under `{Xbox Live API root}\InProgressSamples\ID@XboxSDK\Social`.


### To link your own project with the Xbox Live APIs for Android:

1. If you don’t already have one, you’ll need to add a C++ project that serves as the JNI layer to be able to call the Xbox Live API functions in C++ from Java.
In Visual Studio, add a new project to your solution, and use the **Visual C++ > Cross Platform > Android > Dynamic Shared Library (Android)** project template.

    > [!NOTE]
    > The following instructions assume that your JNI project is called **YourJniProject**, so make sure to use the name of your project instead.

1. Add the following projects to your solution:

   * `Build\Microsoft.Xbox.Services.141.Android\Microsoft.Xbox.Services.141.Android.vcxproj`
   * `Build\sdk.mobile\Android\com.microsoft.xboxlive\com.microsoft.xboxlive.androidproj`
   * `External\xal\Source\Xal\Xal.Android.vcxproj`
   * `External\xal\Source\Xal\Xal.Core.vcxitems`
   * `External\xal\Source\Xal\Xal.Platform.Common.vcxitems`
   * `External\xal\Source\XalAndroidJava\XalAndroidJava.androidproj`
   * `External\xal\External\CompatCoreCLL\CompatCoreCLL.Android.vcxproj`
   * `External\xal\External\libHttpClient\Build\libCrypto.141.Android\libcrypto.141.Android.vcxproj`
   * `External\xal\External\libHttpClient\Build\libHttpClient.141.Android.C\libHttpClient.141.Android.C.vcxproj`
   * `External\xal\External\libHttpClient\Build\libHttpClient.141.Android.Java\libHttpClient.141.Android.Java.androidproj`
   * `External\xal\External\libHttpClient\Build\libssl.141.Android\libssl.141.Android.vcxproj`

     ![Image of the projects in your Android solution](images/android-solution-projects.png)

1. Next you'll need to add references in your Android Java project:

    1. In the **Solution Explorer**, expand your Android Java project and right click on **References**.  
    1. Select **Add Reference...**, and in the dialog that appears, select the following projects:

        * `com.microsoft.xboxlive`
        * `libHttpClient.141.Android.Java`
        * `XalAndroidJava`
        * `YourJNIProject`

    1. Click the **Ok** button.

1. Right click **YourJNIProject** and select **Properties**. Set **Configurations** to **All Configurations** and **Platforms** to **All Platforms**, then set **Use of STL** to **LLVM libc++ shared library (c++_shared)**.

    > [!NOTE]
    > You should verify that the **Use of STL** setting is correct for all build configurations that you care about.

1. Add the Xbox Live API props files to your solution by clicking **View->Other Windows->Property manager**.

1. Right click **YourJniProject** and select **Add existing property sheet** and select `xsapi.staticlib.props` in the Xbox Live API source root.

1. Right click **YourJniProject** and select **Add existing property sheet** and select `xsapi.paths.props` in the Xbox Live API source root.

    This automatically updates your include path and adds references to the Xbox Live APIs and all of the dependencies.

1. To verify that YourJniProject is properly referencing the include paths set by the props file, right click on **YourJNIProject**, select **Properties**, then navigate to **Configuration Properties > C/C++**. In the **Additional Include Directories** field, select **<Edit...>** to view the **Additional Include Directories** dialog, and verify that the **Inherited values** section contains the following include paths:

   ```xml
   $(XsapiInclude)
   $(Sysroot)\usr\include
   $(StlIncludeDirectories)
   $(CppRestSdkInclude)
   $(libHttpClientInclude)
   $(opensslSourceRoot)include
   $(opensslGeneratedHeaders)
   $(XalInclude)
   $(CoreCLLInclude)
   ```

1. Next, you'll need to add a few preprocessor definitions to your JNI project. In Visual Studio, in the Solution Explorer, right-click **YourJniProject**, and select **Properties**. In the property pages dialog, navigate to **C/C++ > Preprocessor**. Edit the **Preprocessor Definitions** field to add the following definitions:

   * `XSAPI_XAL_AUTH`
   * `ANDROID_API=1`

    ![Image of adding preprocessor definitions in Visual Studio](images/android-add-preprocessor-definitions.png)

1. Include the appropriate header files in YourJniProject app source:

   Add the follow includes to your source:

   ```cpp
   #include <Xal/xal.h>
   #include <xsapi/types.h>
   ```

   If you are using C++ APIs, add:

   ```cpp
   #include "xsapi\services.h"
   ```

   If you are using flat C APIs, add:

   ```cpp
   #include "xsapi-c\services_c.h"
   ```

1. Next, you'll need to add some dependencies to the Gradle build of your Java application. In the Solution Explorer, under your Java project, navigate to your app folder, and edit the **build.gradle.template** file to add the following lines in the dependencies section:

   ```Java
       compile 'com.madgag.spongycastle:core:1.58.0.0'
       compile 'com.madgag.spongycastle:prov:1.58.0.0'
       compile 'com.squareup.okhttp3:okhttp:3.10.0'
   ```

    The section should look similar to the following:

   ```Java
   dependencies {
       compile fileTree(dir: 'libs', include: ['*.jar'])
       compile 'com.madgag.spongycastle:core:1.58.0.0'
       compile 'com.madgag.spongycastle:prov:1.58.0.0'
       compile 'com.squareup.okhttp3:okhttp:3.10.0'
       $(AarDependencies)
   }
   ```

1. Add these android permissions to your Java app's **AndroidManifest.xml.template**:

   ```xml
   <uses-permission android:name="android.permission.INTERNET" />
   <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
   ```

    The top of the manifest should look like the following when you are done:

   ```xml
   <?xml version="1.0" encoding="utf-8"?>
   <manifest xmlns:android="http://schemas.android.com/apk/res/android"
             package="com.YourJavaProject"
             android:versionCode="1"
             android:versionName="1.0">
       <uses-permission android:name="android.permission.INTERNET" />
       <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
     <application
   ```


## Samples

Included in the SDK download are Android samples for achievements and social, under `{Xbox Live API root}\InProgressSamples\ID@XboxSDK`.


## Remarks about using the Xbox Live APIs on Android


### Sign-in and authorization

Android games that use the Xbox Live APIs use the Xbox Authentication Library (XAL) in order to associate players with their Xbox Live identity.

After signing a player in with XAL, your game should then create an `xbox_live_context` and pass the XAL user handle as a parameter.
After that, the `xbox_live_context` should look and function the same as it does on any other platform.

For more information about signing in a player by using XAL in an Android game, see [Xbox Live Authentication Layer (Xal) with Android](../using-xbox-live/auth/android-xal.md).


### xboxservices.config

The Xbox Live APIs rely on [xboxservices.config](../xboxservices-config.md). On Android, you can just add the config file to your project.


### Async library

The async library for Android only supports `AsyncQueueDispatchMode::AsyncQueueDispatchMode_Manual`. This means your title has to create an async queue and pump the work and completion threads.

You can find a cross-platform solution at `{Xbox Live API Root}\InProgressSamples\Kits\XboxLiveToolkit\mobile\AsyncIntegration`.  
`AsyncIntegration` handles pumping the background thread and allows the title to control the completion thread by calling `DrainAsyncCompletionQueueUntilEmpty` when ready.
