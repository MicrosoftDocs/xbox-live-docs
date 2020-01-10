---
title: Handling a title Presence change
description: Example code for handling a title Presence change.
kindex: Handling a title Presence change
kindex: Presence
author: mikehoffms
ms.author: v-mihof
ms.date: 01/09/2020
ms.topic: conceptual
ms.localizationpriority: medium
---

# Handling a title Presence change


## Subscribing to a title presence change

**C API**
<!--  XblPresenceSubscribeToTitlePresenceChange_C.md -->
```cpp
uint64_t xuid{ 2814639011617876 };

HRESULT hr = XblPresenceSubscribeToTitlePresenceChange(
    xboxLiveContext,
    xuid,
    titleId,
    &state.titlePresenceChangeSubscription
);
```

<!-- in gdk only:
**Reference**
* [XblPresenceSubscribeToTitlePresenceChange](xblpresencesubscribetotitlepresencechange.md)
-->


## Unsubscribing from a title presence change

**C API**
<!--  XblPresenceUnsubscribeFromTitlePresenceChange_C.md -->
```cpp
HRESULT hr = XblPresenceUnsubscribeFromTitlePresenceChange(
    xboxLiveContext,
    state.titlePresenceChangeSubscription
);

state.titlePresenceChangeSubscription = nullptr;
```

<!-- in gdk only:
**Reference**
* [XblPresenceUnsubscribeFromTitlePresenceChange](xblpresenceunsubscribefromtitlepresencechange.md)
-->


## Adding a title presence change handler

**C API**
<!--  XblPresenceAddTitlePresenceChangedHandler_C.md -->
```cpp
state.titlePresenceChangedHandlerToken =  XblPresenceAddTitlePresenceChangedHandler(
    xboxLiveContext,
    [](void* context, uint64_t xuid, uint32_t titleId, XblPresenceTitleState titleState)
    {
        UNREFERENCED_PARAMETER(context);
        LogToFile("Title presence change notification received:");
        LogToFile("Xuid = %u, titleId = %u, titleState = %u", xuid, titleId, titleState);
    },
    nullptr
);
```

<!-- in gdk only:
**Reference**
* [XblPresenceAddTitlePresenceChangedHandler](xblpresenceaddtitlepresencechangedhandler.md)
* [XblPresenceTitleState](xblpresencetitlestate.md)
-->


## Removing a title presence change handler

**C API**
<!--  XblPresenceRemoveTitlePresenceChangedHandler_C.md -->
```cpp
HRESULT hr = XblPresenceRemoveTitlePresenceChangedHandler(
    xboxLiveContext,
    state.titlePresenceChangedHandlerToken
);

state.titlePresenceChangedHandlerToken = 0;
```

<!-- in gdk only:
**Reference**
* [XblPresenceRemoveTitlePresenceChangedHandler](xblpresenceremovetitlepresencechangedhandler.md)
-->
