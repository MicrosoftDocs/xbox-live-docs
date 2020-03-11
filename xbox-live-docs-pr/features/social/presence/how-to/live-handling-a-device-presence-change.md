---
title: Handling a device Presence change
description: Example code for handling a device Presence change.
kindex: Handling a device Presence change
kindex: Presence
author: mikehoffms
ms.author: v-mihof
ms.topic: conceptual
ms.localizationpriority: medium
ms.date: 01/09/2020
---


# Handling a device Presence change

<!-- **Contents**
* [Subscribing to a device Presence change​](#stadpc)
* [Un-subscribing from a device Presence change​](#ufadpc)
* [Adding a device Presence change handler​](#aadpch)
* [Removing a device Presence change handler](#radpch) -->


<a id="stadpc"></a>

## Subscribing to a device Presence change​

**C API**
<!--  XblPresenceSubscribeToDevicePresenceChange_C.md -->
<!-- note guid "123" -->
```cpp
uint64_t xuid{ 123 };

HRESULT hr = XblPresenceSubscribeToDevicePresenceChange(
    xboxLiveContext,
    xuid,
    &state.devicePresenceChangeSubscription
);
```

<!--**Reference**
* [XblPresenceSubscribeToDevicePresenceChange](xblpresencesubscribetodevicepresencechange.md)-->


<a id="ufadpc"></a>

## Un-subscribing from a device Presence change​

**C API**
<!--  XblPresenceUnsubscribeFromDevicePresenceChange_C.md -->
```cpp
HRESULT hr = XblPresenceUnsubscribeFromDevicePresenceChange(
    xboxLiveContext,
    state.devicePresenceChangeSubscription
);

state.devicePresenceChangeSubscription = nullptr;
```

<!--**Reference**
* [XblPresenceUnsubscribeFromDevicePresenceChange](xblpresenceunsubscribefromdevicepresencechange.md)-->


<a id="aadpch"></a>

## Adding a device Presence change handler​

**C API**
<!--  XblPresenceAddDevicePresenceChangedHandler_C.md -->
```cpp
state.devicePresenceChangedHandlerToken = XblPresenceAddDevicePresenceChangedHandler(
    xboxLiveContext,
    [](void* context, uint64_t xuid, XblPresenceDeviceType deviceType, bool isUserLoggedOnDevice)
    {
        UNREFERENCED_PARAMETER(context);
        LogToFile("Device presence change notification received:");
        LogToFile("Xuid = %u, deviceType = %u, isUserLoggedOnDevice = %u", xuid, deviceType, isUserLoggedOnDevice);
    },
    nullptr
);
```

<!--**Reference**
* [XblPresenceAddDevicePresenceChangedHandler](xblpresenceadddevicepresencechangedhandler.md)
* [XblPresenceDeviceType](xblpresencedevicetype.md)-->


<a id="radpch"></a>

## Removing a device Presence change handler

**C API**
<!--  XblPresenceRemoveDevicePresenceChangedHandler_C.md -->
```cpp
HRESULT hr = XblPresenceRemoveDevicePresenceChangedHandler(
    xboxLiveContext,
    state.devicePresenceChangedHandlerToken
);

state.devicePresenceChangedHandlerToken = 0;
```

<!--**Reference**
* [XblPresenceRemoveDevicePresenceChangedHandler](xblpresenceremovedevicepresencechangedhandler.md)-->
