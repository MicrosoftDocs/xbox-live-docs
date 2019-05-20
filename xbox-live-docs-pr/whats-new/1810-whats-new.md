---
title: What's new in Xbox Live APIs - October 2018
author: KevinAsgari
description: What's new in Xbox Live APIs - October 2018
ms.assetid: 
ms.author: kevinasg
ms.date: 11/08/2018
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, what's new, october 2018
ms.localizationpriority: medium
---

# What's new for the Xbox Live APIs - October 2018


## New Features

- SDK is now available as precompiled binaries (libs), and integrated with a package manager for Android.
  See [Get started with Xbox Live APIs on Android](../get-started/setup-ide/managed-partners/as-android/other/android-get-started-with-xsapi.md).


## Fixes

### XAL Fixes
- Xal's numerical parsing code has a chance to fail unnecessarily if errno has been set to a failure from any other unrelated cause.
- On iOS, Xal built with assertions enabled even in retail builds.
- On iOS, depending on how the calling app set up their work loop, it was possible for Xal to become unresponsive, particularly due to network inconsistency.
- Fixed an issue where roughly 0.8% of app installs on Android would crash on launch.
- Fixed an issue where SISU customizations do not get loaded for welcome back flows.
- Fixed a bug where UI could be shown when a silent call is made.

### XSAPI Fixes
- Fixed an issue where deadlock could happen in the telemetry module.

## Breaking Changes

### XAL Breaking Changes

#### All platforms
Xal has taken on the following API layer breaking changes based on API review feedback:
- DuplicateAsyncQueueHandle() has changed its signature. Instead of taking in a single queue handle and having that handle's reference count incremented by 1, DuplicateAsyncQueueHandle() now takes two arguments.:
    - The first argument is the async_queue_handle_t you want to duplicate.
    - The second argument is of type async_queue_handle_t* which is used as an out param and returns a new handle which you can then reference. The new handle still needs to be closed by calling CloseAsyncQueue().
    - The return value for DuplicateAsyncQueueHandle() has changed from being the duplicated handle to an HRESULT.
- XalUserDuplicateHandle() has had the same type of change done to it that DuplicateAsyncQueueHandle() has. Instead of taking in a single user handle and having that handle's reference count incremented by 1, XalUserDuplicateHandle() now takes two arguments:
    - The first argument is the xal_user_handle_t you want to duplicate.
    - The second argument is of type xal_user_handle_t* which is used as an out param and returns a new handle which you can then reference. The new handle still needs to be closed by calling XalUserCloseHandle().
    - The return value for XalUserDuplicateHandle() has changed from being the duplicated handle to an HRESULT.
- XalTryAddFirstUserSilentlyAsync() has been renamed to XalTryAddDefaultUserSilentlyAsync(). Its functionality has stayed the same
- The values of the enum XalGamerPictureSize have been changed.
- The values of the enum XalUserChangeType have been changed.
- The non-implemented XalUserGetAccentColor() stub has been removed.
- The non-implemented XalUserCheckPrivilegesWithUiAsync() stub has been removed and replaced with a non-implemented XalUserResolveUserPrivilegeWithUiAsync() stub.
- XalUserUnregisterChangeEventHandler() now returns void.
- The queue handles passed into Xal's event handlers and initialize method are no longer optional.
