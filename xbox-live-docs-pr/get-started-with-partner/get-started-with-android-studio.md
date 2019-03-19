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
> * Ensure you have a Native C++ project created in Android Studio
> * Ensure you are targeting Android API 26+
> * Ensure that your Android SDK includes NDK and CMake
> * Ensure you have a virtual device that is capable of running Android API 26+

## Download Xbox Live SDK

1. <a href="https://github.com/Microsoft/xbox-live-api" target="_blank"> Download </a> the various packages and extract them to your project folder.

## Setup your Project to include dependencies
1. In your project, open **your_project > gradle.properties(Project)** and ensure the following variable is defined

```json
PROP_APP_ABI=armeabi-v7a:x86
```
This property will be used later to ensure your project builds only for arm and x86.

2. In **your_project > build.gradle(Project)** you will need to add the following dependency:

```json
classpath 'com.google.gms:google-services:4.1.0'
```

3. You must set your complier SDK version to API 26+. To do this navigate to ** file > Project Structure > your_app > Properties tab ** change the "Compile SDK Version" to "API:26: Android 8.0 (OREO)"" then click okay

Image

4. In **your_project > app > gradle.build(App)** update the externalNativeBuild, inside of 'defaultConfig', to include the required cmake arguments and filters:

```json
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
```
The ndk filters uses your gradle.properties variable that you had set earlier.

5. In addition to the externalNativeBuild above, you will also need to include the following dependencies at the bottom of your gradle.build(App) file

```json
implementation 'com.madgag.spongycastle:core:1.58.0.0'
implementation 'com.madgag.spongycastle:prov:1.58.0.0'
implementation 'com.squareup.okhttp3:okhttp:3.10.0'
implementation 'com.android.support:customtabs:26.1.0'
```

6. After entering the dependencies you will want to apply the google plugins referenceed above.

```json
dependencies {
  ...
}
// Add after dependencies
apply plugin: 'com.google.gms.google-services'
```

## Including Xbox Live SDK to your project build

1. In Android Studio click **File > Project Structure** which presents the Project Structure model. Within this model click the "+" button (top left) which presents you with the New Module dialog and select "Import .JAR/.AAR Package". Navigate to where you installed your Xbox Live SDK and add the following .aar's:

* Android\Maven\XsapiAndroid\com.microsoft.xboxlive\0.0.0\com.microsoft.xboxlive-0.0.0.aar
* Android\Maven\androidxal\XalAndroidJava\0.0.0\XalAndroidJava-0.0.0.aar
* Android\Maven\libHttpClientAndroid\libHttpClient\0.0.0\libHttpClient-0.0.0.aar

2. Next, you will need to make sure that you add these .aar modules to your project as dependencies. You can do this by navigating to **File > Project Structure** then the dependencies tab. Within this tab you will want to click the "+" button (top right) and select "Module dependency" option. This should present you with a small screen list of all the modules we added above. Select the modlues and click ok.

3. Now that the libraries are included in the project, we are going to update our Cmakefile.txt so that we can reference them in our native code. Open **your_app > src > main > cpp > CMakeLists.txt** and add the following just after the cmake_minimum_required element:

[!NOTE] The path to the NDK must be from your app root folder to the source of the maven ndk downloaded as part the XboxLiveSDK

```json
set(ANDROID_MAVEN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../Maven) //TODO: Replace path to direct to your local XboxLiveSDK Maven folder
```

4. In the same CMakeLists.txt we also need to define some compilar flags for XSAPI and XAL copy the following and insert it just after the add_library element

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
Upon completion of this step you should run a gradle sync followed by project build to ensure that the project links properly with your XboxLiveSDK.

## Adjusting your Android Manifest to handle XboxLiveSDK

1. First we are going to update the Android Manifest to include the permissions XboxLive requires to run. Open **your_app > src > main > AndroidManifest.xml ** and add the following two lines just after the header:

```xml
<uses-permission android:name="android.permission.INTERNET"/>
<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
```

2. In your application settings of the AndoroidMainfest you will need to set the **android:allowBackup="false"**

3. In the same file AndroidManifest file you will also need to add a new activity just after the main launcher element.

```xml
<activity android:name="com.microsoft.xal.browser.WebView" android:launchMode="singleTask">
    <intent-filter>
        <action android:name="android.intent.action.VIEW" />
        <data android:scheme="ms-xal-0000000012345678" android:host="auth" /> // TODO: Replace the last part of scheme (after ms-xal-) with your client ID
        <category android:name="android.intent.category.DEFAULT" />
        <category android:name="android.intent.category.BROWSABLE"/>
    </intent-filter>
</activity>
```
This will make sure that the application can grab the WebView to display the log-in screen when needed.

## Preparing your Java files to handle XboxLiveSDK

We are now going to update our MainActivity java class to utalize native C++ binding. To do this begin by Opening up ** your_app > src > main > java > your_package > MainActivity.Java**

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

1. We are going to update the our Native C++ code to make use of XSAPI, XAL, and ASYNC. To do this we open up **your_app > src > main > cpp > native-lib.cpp file and add the following includes and global definitions:

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

2. In the same file we also will update our 'extern "C"' method which, via JNI, maps our native code to our java code to make use of our XboxLiveSDK.

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

Congratulations at this point you should have your project up and running with our XboxLiveSDK!

<!--===================================================-->
## Next step

Now that your IDE is set up to use Xbox Live, continue with step 3: Using Xbox Live SDK to Sign-In for Mobile.
See [Getting started](../index.md).
