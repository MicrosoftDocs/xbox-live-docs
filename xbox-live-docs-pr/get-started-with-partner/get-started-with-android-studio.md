structure--
title: Adding Xbox Live to your Android Studio Project
author: KevinAsgari
description: Learn how to add XBL to your android Studio project
ms.author: kevinasg
ms.date: 03/13/2019
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, android, android studio
ms.localizationpriority: medium
---

# Adding Xbox Live to your Android Studio Project

To incorporate Xbox Live functionality in your android studio project you will need to complete the steps below

## Prerequisite: Have Android Studio setup with permission to use the Xbox Live SDK

Prerequisite steps for ID@Xbox partners:

* Ensure you have an Android Studio project already created that targets Android API 26 that is a native C++ project.
* Ensure that your Android SDK is setup with Android 8.0 (API 26) and includes NDK and CMake
* Ensure you have a virtual device that is capable of running Android API 26

## Download XSAPI & XAL

1. <a href="https://github.com/Microsoft/xbox-live-api" target="_blank"> Download  the various packages </a>  and extract them to your project folder

## Setup your Project to compile for x86 and include dependencies for XSAPI and XAL
1. In your project, open **your_project > gradle.properties (Project)** and ensure the following two variables are defined

   ```json
   PROP_APP_ABI=x86
   ```
    This property will be used later to ensure we are only building for x86

2. In **your_app > build.gradle(project)** you will need to add the following dependency:

  ```json
    classpath 'com.google.gms:google-services:4.1.0'
    ```

3. You must set your complier to target api 26. To do this navigate to ** file > Project Structure > your_app > Properties tab ** change the "Compile SDK Version" to "API:26: Android 8.0 (OREO)"" then click okay

Image

4. In **your_project > app > gradle.build (app)** update the externalNativeBuild to include the required cmake arguments and ndk filters
```json
externalNativeBuild {
           cmake {
               arguments "-DANDROID_STL=c++_static", "-DANDROID_TOOLCHAIN=clang"
               cppFlags "-frtti -fexceptions -fsigned-char"
           }
       }
       ndk {
           abiFilters = []
           abiFilters.addAll(PROP_APP_ABI.split(':').collect{it as String})
       }
   }
   ```
The ExternalNativeBuild flags will tell your compiler to be static as well as use clang for a toolchain. The ndk filters ensures you are only targeting x86 builds


5. In addition to the ndk and nativeBuild flags above you will also need to include the following dependencies at the bottom of your gradle.build (app) file


  ```json
implementation 'com.google.firebase:firebase-messaging:17.3.4'
implementation 'com.google.firebase:firebase-core:16.0.7'
implementation 'com.madgag.spongycastle:core:1.58.0.0'
implementation 'com.madgag.spongycastle:prov:1.58.0.0'
implementation 'com.squareup.okhttp3:okhttp:3.10.0'
implementation 'com.android.support:customtabs:26.1.0'
implementation 'com.google.code.gson:gson:2.8.5'
implementation('org.simpleframework:simple-xml:2.7.+') {
    exclude module: 'stax'
    exclude module: 'stax-api'
    exclude module: 'xpp3'
}
```
6. After entering the dependencies you will want to apply the google plugins referenceed above.
```json
//This should be after dependencies
apply plugin: 'com.google.gms.google-services'
  ```

## Including XSAPI and XAL to your project build

1. In Android Studio click **File > Project Structure** which presents the Project Structure modal. Within this modal click the + button which presents you with the New Module dialog select "Import .JAR/.AAR Package" Navigate to your C:XboxLIVESDK and select XSAPIAndroid's .aar file

Insert Image<br>
**Repeat this step with the androidXAL .aar and libHttpClientAndroid**

2. You now need to add these included modules as dependencies you can do this by again navigating to **File > Project Structure** then the dependencies tab. Within this tab you will want to click the "+" on the right side of the screen and select
"Module dependency" option. This should present you with a small screen list all the modules we added above. select all the modlues and add click ok

Image or better yet a gif <br>

3. Now that the libraries are included in the project we are going to update our Cmakefile.txt so that we can reference them in our native code. Open **your_app > src > main > cpp > CMakeLists.txt** and add the following just after the cmake_minimum_required element:
[!NOTE] the path to the NDK must be from your app root folder to the source of the maven ndk downloaded as part the XboxLiveSDK

   ```json
   set(ANDROID_MAVEN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../Maven/ndk)
   set(ANDROID_MAVEN_LIBS_PATH ${ANDROID_MAVEN_PATH}/libs/x86)
   ```
4. In the same CMakeLists.txt we also need to define some compilar flags for XSAPI and XAL copy the following and insert it just after the add_library element

```json
# Add pre-processor definitions to the project
target_compile_definitions(native-lib PUBLIC
        XSAPI_CPP=1
        XSAPI_C=1
        _NO_ASYNCRTIMP
        _NO_PPLXIMP
        _NO_XSAPIIMP
        XBL_API_EXPORT
        XSAPI_A=1
        XSAPI_U=1
        __STDC_WANT_LIB_EXT1__=1
        ASIO_STANDALONE
        )
# Link Additional Dependencies. Note: Order matters here!
target_link_libraries(native-lib
        ${ANDROID_MAVEN_LIBS_PATH}/libMicrosoft_Xbox_Services_Android.a
        ${ANDROID_MAVEN_LIBS_PATH}/Xal.Android-RelAI32.a
        ${ANDROID_MAVEN_LIBS_PATH}/CompactCoreCLL.Android-RelAI32.a
        ${ANDROID_MAVEN_LIBS_PATH}/liblibHttpClient_141_Android_C.a
        ${ANDROID_MAVEN_LIBS_PATH}/libssl.141.Android.a
        ${ANDROID_MAVEN_LIBS_PATH}/libcrypto.141.Android.a
        )
# Add Additional Include Directories
 target_include_directories(native-lib
         PUBLIC ${ANDROID_MAVEN_PATH}/include
         PUBLIC ${ANDROID_MAVEN_PATH}/include/cpprestinclude
          )

```
Upon completion of this step you should run a gradle sync followed by project build which will complete with the new included XSAPI and XAL libraries


## Preparing your Java files for XSAPI and XAL
1. First we are going to update the Android Manifest to include the permission XAL and XSAPI require to run. Open **your_app > src > main > AndroidManifest.xml ** and add the following two lines just after the header:
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
        <data android:scheme="ms-xal-000000004824156c" android:host="auth" />
        <category android:name="android.intent.category.DEFAULT" />
        <category android:name="android.intent.category.BROWSABLE"/>
    </intent-filter>
</activity>
<service
    android:name="com.microsoft.xboxlive.NotificationListenerService"
    android:exported="false" >
    <intent-filter>
        <action android:name="com.google.firebase.MESSAGING_EVENT" />
    </intent-filter>
</service>
```
We will be creating the NotificationListenerService java class in just a bit.

4. We are now going to update our MainActivity java class to utalize native C++ binding. To do this begin by Opening up ** your_app > src > main > java > your_package > MainActivity.Java**

```java
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.content.Context;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

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
        //now adding in new clean up the thread spawned above
        super.onDestroy();
    }

}
```

5. With MainActivity updated with our new methods we will now create the NotificationListenerService class we had mentiond above. Click **your_app > src > main ** and create a new class entitled com.microsoft.xboxlive.NotificationListenerService. Once created populate the file with the following:

```java
import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;
import android.util.Log;
import com.microsoft.xbox.service.notification.*;


public class NotificationListenerService extends FirebaseMessagingService
{
    private static final String TAG = "AchievementSample";

    @Override
    public void onMessageReceived(RemoteMessage remoteMessage)
    {
        Log.d(TAG, "FCM message From: " + remoteMessage.getFrom());

        if (remoteMessage.getData().size() > 0)
        {
            Log.d(TAG, "FCM Message data payload: " + remoteMessage.getData());
        }

        if (remoteMessage.getNotification() != null)
        {
            Log.d(TAG, "FCM Message Notification Body: " + remoteMessage.getNotification().getBody());
        }

        //TODO(developer): Add notification handler based on result.notificationType
    }
}
```

## Binding your Java files to your Native C files

 1. We are going to update the our native C code to make use of XSAPI, XAL, and ASYNC. To do this we open up **your_app > src > main > cpp > native-lib.cpp file and add the following includes and global definitions:

```c++
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
#include <XAsync.h>

typedef std::string string_t;
typedef std::stringstream stringstream_t;


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
5. In the same file we also will update our EXTERN "C" method which via JNI maps our native code to our java code to make use of XSAPI, XAL, and ASYNC.

```c++
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


Congratulations at this point you should have your project up and running with Xbox Live now you just need to get sign in working!

link to Getting Started Sign In article