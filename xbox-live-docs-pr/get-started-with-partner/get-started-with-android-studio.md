---
title: Adding Xbox Live to your Android Studio Project
description: Learn how to add XBL to your Android Studio project
ms.date: 03/14/2019
ms.topic: article
keywords: xbox live, xbox, games, android, android studio
ms.localizationpriority: medium
---
# Adding Xbox Live to your Android Studio Project

> [!IMPORTANT]
> Prerequisite steps:
> * Ensure you have a Native C++ project created in Android Studio.
> * Ensure you are targeting Android API 26+.
> * Ensure that your Android SDK includes NDK and CMake.
> * Ensure you have a virtual device that is capable of running Android API 26+.


## Download the Xbox Live SDK

<a href="https://github.com/Microsoft/xbox-live-api" target="_blank"> Download </a> the packages and extract them to your project folder.


## Add Maven to your Project

Add Maven support to project by going to **your_project > build.gradle(Project)** and adding the following:

```json
buildscript {
    repositories {
        jcenter()
        maven {
            url 'https://maven.google.com/'
            name 'Google'
        }
    }
}

allprojects {
    repositories {
        jcenter()
        maven {
            url 'https://maven.google.com/'
            name 'Google'
        }
        maven {
            url 'file:///C:/XboxLiveSDK/Android/Maven'
        }
    }
}
```

> [!NOTE]
> Make sure to update the url to your project's Maven folder inside of your local XboxLiveSDK.


## Set up your Project's Gradle to include dependencies

1. In **your_project > build.gradle(Project)**, add the following dependency:

```json
buildscript {
    ...
    
    dependencies {
        ...
        
        classpath 'com.google.gms:google-services:4.1.0'
    }
}
```

2. In **your_project > gradle.properties(Project)**, ensure the following variable is defined:

```json
PROP_APP_ABI=armeabi-v7a:x86
```
This property will be used later to ensure your project builds only for arm and x86.

3. You must set your complier SDK version to API 26+.
   To do this, navigate to **file > Project Structure > your_app > Properties tab**, change the "Compile SDK Version" to "API:26: Android 8.0 (OREO)", and then click **OK**.

4. In **your_project > app > gradle.build(App)**, inside of `defaultConfig`, update the `externalNativeBuild` to include the required cmake arguments and filters:

```json
android {
    ...
     
    defaultConfig {
        ...
        
        externalNativeBuild {
           cmake {
               arguments "-DANDROID_STL=c++_shared", "-DANDROID_TOOLCHAIN=clang"
               cppFlags "-frtti -fexceptions -fsigned-char"
           }
        }
        ndk {
           abiFilters = []
           abiFilters.addAll(PROP_APP_ABI.split(':').collect{it as String})
        }
    }
}
```
The ndk filters uses your `gradle.properties` variable that you had set earlier.

5. Include the following dependencies at the bottom of your `gradle.build(App)` file:

```json
dependencies {
    ...
    
    implementation 'com.madgag.spongycastle:core:1.58.0.0'
    implementation 'com.madgag.spongycastle:prov:1.58.0.0'
    implementation 'com.squareup.okhttp3:okhttp:3.10.0'
    implementation 'com.android.support:customtabs:26.1.0'
    implementation (group: 'XsapiAndroid', name: 'com.microsoft.xboxlive', version: '0.0.0')
    implementation (group: 'androidxal', name: 'XalAndroidJava', version: '0.0.0')
    implementation (group: 'libHttpClientAndroid', name: 'libHttpClient', version: '0.0.0')
}
```

6. Apply the Google plugins that are referenced above:

```json
dependencies {
  ...
}

apply plugin: 'com.google.gms.google-services'
```


## Including the Xbox Live SDK into your CMake file

1. Now that gradle is set up for your project, we are going to update `Cmakefile.txt` so that we can include the XboxLiveSDK libraries. Open **your_app > src > main > cpp > CMakeLists.txt** and add the following just after the cmake_minimum_required element:

```json
#TODO: Replace path to direct to your local XboxLiveSDK Maven folder
set(ANDROID_MAVEN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../Maven)
```
> [!NOTE]
> The path to Maven must be from your project's CMake folder to the Maven folder inside of your local Xbox Live SDK.

2. Next, define some compiler flags for the Xbox Live SDK, as follows:

```json
# Add pre-processor definitions to the project
target_compile_definitions(${APP_NAME} PUBLIC
                           XSAPI_C=1
                           XSAPI_A=1
                           )

# Handle Android ABI flavors
if (${ANDROID_ABI} STREQUAL "x86")
    set(XBLSDK_ABI "x86")
    set(XALSUFFIX "AI32")
elseif (${ANDROID_ABI} STREQUAL "armeabi-v7a")
    set(XBLSDK_ABI "arm")
    set(XALSUFFIX "AA32")
endif()

# Link Additional Dependencies. Note: Order matters here!
target_link_libraries(${APP_NAME}
                      ${ANDROID_MAVEN_PATH}/ndk/libs/${XBLSDK_ABI}/libMicrosoft_Xbox_Services_Android.a
                      ${ANDROID_MAVEN_PATH}/ndk/libs/${XBLSDK_ABI}/Xal.Android-Rel${XALSUFFIX}.a
                      ${ANDROID_MAVEN_PATH}/ndk/libs/${XBLSDK_ABI}/CompactCoreCLL.Android-Rel${XALSUFFIX}.a
                      ${ANDROID_MAVEN_PATH}/ndk/libs/${XBLSDK_ABI}/liblibHttpClient_141_Android_C.a
                      ${ANDROID_MAVEN_PATH}/ndk/libs/${XBLSDK_ABI}/libssl.141.Android.a
                      ${ANDROID_MAVEN_PATH}/ndk/libs/${XBLSDK_ABI}/libcrypto.141.Android.a
                      )

# Add Additional Include Directories
target_include_directories(${APP_NAME}
                           PUBLIC ${ANDROID_MAVEN_PATH}/ndk/include/
                           )
```
Upon completion of this step you should run a gradle sync followed by project build to ensure that the project links properly with your Xbox Live SDK libraries.


## Adjusting your Android Manifest to handle XboxLiveSDK

1. First, update the Android Manifest to include the permissions which Xbox Live requires to run, as follows.
   Open the file **your_app > src > main > AndroidManifest.xml** and add the following two lines just after the header:

```xml
<uses-permission android:name="android.permission.INTERNET"/>
<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
```

2. In your application settings of the Android Manifest, you will need to set the following: **android:allowBackup="false"**

3. In the same Android Manifest file, add a new activity just after the main launcher element, as follows:

```xml
<activity android:name="com.microsoft.xal.browser.WebView" android:launchMode="singleTask">
    <intent-filter>
        <action android:name="android.intent.action.VIEW" />
        <!-- TODO: Replace the last part of scheme (after ms-xal-) with your client ID -->
        <data android:scheme="ms-xal-0000000012345678" android:host="auth" />
        <category android:name="android.intent.category.DEFAULT" />
        <category android:name="android.intent.category.BROWSABLE"/>
    </intent-filter>
</activity>
```
This will make sure that the application can grab the WebView to display the log-in screen when needed.


## Preparing your Java files to handle XboxLiveSDK

We are now going to update our MainActivity java class to utilize native C++ binding. To do this, begin by opening the file **your_app > src > main > java > your_package > MainActivity.Java**.
Inside your MainActivity, add in the `InitializeGame` and `CleanupGame` functions below:

```java
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.content.Context;

public class MainActivity extends AppCompatActivity {

    private native void InitializeGame(Context context);
    private native void CleanupGame();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        InitializeGame(getApplicationContext());
    }
    @Override
    protected void onDestroy(){
        CleanupGame();
        super.onDestroy();
    }
}
```


## Binding your Native C++ files to your Java Environment

Next, update the our Native C++ code to include XSAPI and XAL, as follows.

1. Open the file **your_app > src > main > cpp > native-lib.cpp**.

2. Add the following includes and global definitions:

```cpp
#include <jni.h>
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

#include <xsapi-c/services_c.h>
#include <Xal/xal.h>
#include <Xal/xal_platform.h>

JavaVM* g_javaVm = nullptr;
jobject g_appContext = nullptr;

JNIEnv* getJniEnv()
{
    ASSERT_MESSAGE(g_javaVm != nullptr, "JavaVM is NULL! Must init JavaVM before grabbing JniEnv!");

    JNIEnv* jniEnv = nullptr;
    jint j_result = g_javaVm->GetEnv(reinterpret_cast<void**>(&jniEnv), JNI_VERSION_1_6);
    ASSERT_MESSAGE(j_result == JNI_OK, "Failed to retrieve the JNIEnv from the JavaVM!");
    ASSERT_MESSAGE(jniEnv != nullptr, "JniEnv is NULL!");

    return jniEnv;
}
```

2. In the same file, update the `extern "C"` method, as follows.

```cpp
extern "C"
{
    JNIEXPORT void JNICALL Java_com_example_{your_app}_MainActivity_InitializeGame(
            JNIEnv* env,
            jobject instance,
            jobject appContext)
    {
        jint j_result = env->GetJavaVM(&g_javaVm);
        ASSERT_MESSAGE(j_result == JNI_OK, "Failed to retrieve the JavaVM from provided Environment!");
        ASSERT_MESSAGE(g_javaVm != nullptr, "JavaVM is NULL!");

        g_appContext = env->NewGlobalRef(appContext);
        
        //TODO: Put XSAPI initialize here
    }

    JNIEXPORT void JNICALL Java_com_example_{your_app}_MainActivity_CleanupGame(
            JNIEnv* env,
            jobject instance)
    {
        //TODO: Put XSAPI clean up here
    }
}
```

   The `extern "C"` method, via JNI, maps your native code to your Java code, to make use of the XboxLiveSDK.

Congratulations! At this point, your project is set up to start utilizing the XboxLive API.


<!--===================================================-->
## Next step

Now that your IDE is set up to use Xbox Live, continue with step 3: Using the Xbox Live SDK to Sign-In for Mobile.
See [Getting started](../get-started/index.md).
