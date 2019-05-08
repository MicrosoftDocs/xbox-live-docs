---
title: Setting up Android Studio targeting Android
description: Setting up Android Studio targeting Android to use the Xbox Live SDK, for Managed Partners.
ms.date: 04/19/2019
ms.topic: article
keywords: xbox live, games
ms.localizationpriority: medium
---

# Setting up Android Studio targeting Android

Setting up Android Studio targeting Android to use the Xbox Live SDK, for Managed Partners.


## Prerequisite steps

* Ensure you have a Native C++ project created in Android Studio.
* Ensure that your Android SDK includes NDK and CMake.


## Download the Xbox Live SDK

<a href="https://github.com/Microsoft/xbox-live-api" target="_blank">Download</a> the packages and extract them to your project folder.


## Add extensions to the project

Add Maven support to your project, as follows.

1. In Android Studio, in the **Project** directory, open **your_project > build.gradle(Project)**.

2. Add the following code:

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
            url 'file:///C:/{Path to XboxLiveSDK}/XboxLiveSDK/Android/Maven'
        }
    }
}
```

3. Make sure to update the project's Maven url to your project's local Maven folder.


## Add dependencies to the project

Set up your Project's Gradle to include dependencies, as follows.

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

2. In **your_project > gradle.properties(Project)**, make sure that the following variable is defined:

```json
PROP_APP_ABI=armeabi-v7a:x86
```

> [!NOTE]
> The above property will be used later to ensure your project builds only for ARM and x86.

3. In **your_project > app > gradle.build(App)**, inside of `defaultConfig`, update the `externalNativeBuild` to include the required `cmake` arguments and `ndk` filters:

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

The `ndk` filter uses the PROP_APP_ABI variable defined in the project's `gradle.properties` that was set earlier.

4. At the bottom of your `gradle.build(App)` file, add the following dependencies:

```json
dependencies {
    ...
    
    implementation 'XsapiAndroid:com.microsoft.xboxlive:0.0.0'
    implementation 'androidxal:XalAndroidJava:0.0.0'
    implementation 'libHttpClientAndroid:libHttpClient:0.0.0'
}
```

5. Apply the Google plugins that are referenced above:

```json
dependencies {
  ...
}

apply plugin: 'com.google.gms.google-services'
```

   Gradle is now set up for your project.


## Add Xbox Live libraries to the project

Next, update the file `Cmakefile.txt` to include the XboxLiveSDK libraries, as follows.

1. Open the file **your_app > src > main > cpp > CMakeLists.txt**.

2. Just after the `cmake_minimum_required` element, add the following:

```cmake
#TODO: Replace path to direct to your local XboxLiveSDK Maven folder
set(ANDROID_MAVEN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../Maven)
```

> [!NOTE]
> The path to Maven must be from your project's CMake folder to the Maven folder inside of your local Xbox Live SDK.

3. Define the following compiler flags for the Xbox Live SDK:

```cmake
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

4. Run a gradle sync.

5. Do a project build.

   The last two steps ensure that the project links properly with your Xbox Live SDK libraries.


## Modify the build settings

Update the Android Manifest to include the permissions which Xbox Live requires to run, as follows.

1. Open the file **your_app > src > main > AndroidManifest.xml**.

2. Just after the header, add the following two lines:

```xml
<uses-permission android:name="android.permission.INTERNET"/>
<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
```

3. In the `application settings` section, set the following: `android:allowBackup="false"`

4. Just after the main `launcher` element, add a new activity, as follows:

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


## Prepare native files to initialize and cleanup Xbox Live

Next, update your `MainActivity` Java class to utilize native C++ binding, as follows.

1. Open the file **your_app > src > main > java > your_package > MainActivity.Java**.

2. Inside `MainActivity`, add the `InitializeGame` and `CleanupGame` function signatures and function calls:

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


## Bind C++ to the native environment

Next, update your Native C++ code to include XSAPI and XAL, as follows.

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

3. In the same file (`native-lib.cpp`), update the `extern "C"` method as follows:

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

This section will map your native code to your Java code, via the JNI library.

Your project is now set up to use the XboxLive API.

The Android Studio IDE is now set up to use the Xbox Live SDK, targeting Android.


## See also

[Getting Started](../../../index.md)
