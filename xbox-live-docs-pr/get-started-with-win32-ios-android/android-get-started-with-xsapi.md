---
title: Get started with Xbox Live APIs on Android with SDK
author: KevinAsgari
description: Learn how to add and compile the Xbox Live APIs source in your Android project.
ms.author: kevinasg
ms.date: 09/21/2018
ms.topic: article
keywords: xbox live, xbox, games, android
ms.localizationpriority: medium
---

# Get started with Xbox Live APIs on Android

To use the Xbox Live APIs with an Android game, you can use the pre-compiled binaries, or include the Xbox Live API source in your project and build it.


## Requirements

You must use Visual Studio 2017 or later in order to build the Xbox Live APIs. Your Visual Studio instance requires the following components in order to build and deploy Android projects:

* Workloads
  * Mobile development with C++
* Individual Components
  * Visual Studio Emulator for Android
  * Android SDK setup (API Level 27)
* Extensions
  * [Java Language Service for Android and Eclipse Android Project Import](https://marketplace.visualstudio.com/items?itemName=VisualCPPTeam.JavaLanguageServiceforAndroidandEclipseAndroidProj )


## Add the Xbox Live SDK to your Android project (using precompiled binaries and Maven)

> [!NOTE]
> The instruction below only applies to Android projects that use Gradle as the build system.

1. Download the SDK package and extract the Android SDK binaries to a local folder (for example, C:\XboxLiveSDK)

1. In your project, open **your_app > Gradle Scripts > build.gradle.template (Project)** and make sure the following maven url is listed under **allprojects { repositories {} }**

   ```json
   maven {
       url "https://maven.google.com/"
   }
   maven {
       url "file:///C:/XboxLiveSDK/Maven/"
   }
   ```

    The second url is the path to your local Maven repository that contains the Xbxo Live SDK for Android binaries.

1. In your project, open **your_app** > **Gradle Scripts** > **build.gradle (Module: app)** and add the following dependencies to the dependencies{} section to depend on the latest version of the Xbox Live SDK:

   ```json
   compile(group: 'XsapiAndroid', name: 'com.microsoft.xboxlive', version: '0.0.0') 
   compile(group: 'androidxal', name: 'XalAndroidJava', version: '0.0.0') 
   compile(group: 'libHttpClientAndroid', name: 'libHttpClient', version: '0.0.0')
   compile fileTree(dir: 'libs', include: ['*.jar'])
   compile ('com.squareup.okhttp3:okhttp:3.10.0')
   compile ('com.google.code.gson:gson:2.5') { force = true; }
   compile ('com.google.android.gms:play-services-gcm:8.4.0') { force = true; }
   compile ('org.simpleframework:simple-xml:2.7.1') {  force = true;  exclude group: 'xpp3', module: 'xpp3'; exclude group: 'stax', module: 'stax-api'; exclude group: 'stax', module: 'stax'}
   ```

1. For your native JNI project, add the props file to your project by clicking **View** > **Other Windows** > **Property Manager**, right clicking on your project, selecting **Add Existing Property Sheet**, and then finally selecting the **Maven\ndk\xsapi.android.props**. This should add lib dependencies and include the paths.

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

After signing a player in with XAL, your game should then create an `xbox_live_context` and pass the XAL user handle as a parameter. After that, the `xbox_live_context` should look and function the same as it does on any other platform.

For more information about signing in a player by using XAL in an Android game, see [Xbox Live Authentication Layer (Xal) with Android](../using-xbox-live/auth/android-xal.md).


### xboxservices.config

The Xbox Live APIs rely on [xboxservices.config](../xboxservices-config.md). On Android, you can just add the config file to your project.


### Async library

The async library for Android only supports `AsyncQueueDispatchMode::AsyncQueueDispatchMode_Manual`. This means your title has to create an async queue and pump the work and completion threads.

You can find a cross-platform solution at `{Xbox Live API Root}\InProgressSamples\Kits\XboxLiveToolkit\mobile\AsyncIntegration`.  
`AsyncIntegration` handles pumping the background thread and allows the title to control the completion thread by calling `DrainAsyncCompletionQueueUntilEmpty` when ready.
