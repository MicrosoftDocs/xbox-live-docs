---
title: Handling a social relationship change
description: Example code for handling a social relationship change.
kindex: Handling a social relationship change
kindex: relationships
author: mikehoffms
ms.author: v-mihof
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
edited: 01/09/2020
---

# Handling a social relationship change

<!-- intro sentence here -->


## Subscribing to a Relationship change

<!-- intro sentence here -->

**C API**
<!--  XblSocialSubscribeToSocialRelationshipChange_C.md -->
```cpp
HRESULT hr = XblSocialSubscribeToSocialRelationshipChange(
    xboxLiveContext, 
    xboxUserId,
    &state.socialSubscriptionHandle
);
```

**Reference**
* [XblSocialSubscribeToSocialRelationshipChange](xblsocialsubscribetosocialrelationshipchange.md)


## Un-subscribing from a Relationship change

<!-- intro sentence here -->

**C API**
<!--  XblSocialUnsubscribeFromSocialRelationshipChange_C.md -->
```cpp
HRESULT hr = XblSocialUnsubscribeFromSocialRelationshipChange(
    xboxLiveContext, 
    state.socialSubscriptionHandle
);

state.socialSubscriptionHandle = nullptr;
```

**Reference**
* [XblSocialUnsubscribeFromSocialRelationshipChange](xblsocialunsubscribefromsocialrelationshipchange.md)


## Adding a Relationship-changed handler

<!-- intro sentence here -->

**C API**
<!--  XblSocialAddSocialRelationshipChangedHandler_C.md -->
```cpp
state.socialRelationshipChangedHandlerToken = XblSocialAddSocialRelationshipChangedHandler(
    xboxLiveContext,
    [](const XblSocialRelationshipChangeEventArgs* args, void* context)
    {
        UNREFERENCED_PARAMETER(context);
        LogToFile("Social relationship changed:");
        std::stringstream ss;
        for (size_t i = 0; i < args->xboxUserIdsCount; ++i)
        {
            if (i > 0) 
            {
                ss << ", ";
            }
            ss << args->xboxUserIds[i];
        }
        LogToFile("socialNotification = %u, affectedXuids = %s", args->socialNotification, ss.str().data());
    },
    nullptr
);
```

**Reference**
* [XblSocialAddSocialRelationshipChangedHandler](xblsocialaddsocialrelationshipchangedhandler.md)


## Removing a Relationship-changed handler

<!-- intro sentence here -->

**C API**
<!--  XblSocialRemoveSocialRelationshipChangedHandler_C.md -->
```cpp
HRESULT hr = XblSocialRemoveSocialRelationshipChangedHandler(xboxLiveContext, state.socialRelationshipChangedHandlerToken);
state.socialRelationshipChangedHandlerToken = 0;
```

**Reference**
* [XblSocialRemoveSocialRelationshipChangedHandler](xblsocialremovesocialrelationshipchangedhandler.md)
