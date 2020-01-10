---
title: Updating a user's Presence via XSAPI C
description: Example code for setting a user's online Presence status.
kindex: Updating a user's Presence via XSAPI C
kindex: Presence
author: jeffshi
ms.author: v-mihof
ms.topic: conceptual
ms.localizationpriority: medium
ms.date: 01/09/2020
edited: 01/09/2020
---

# Updating a user's Presence via XSAPI C

Xbox Live Rich Presence provides features for advertising a player's current activity to other players.

For more information, see [Rich Presence overview](../live-presence-overview.md).


## Updating a user's online Presence status

This code example sets a user's online presence status.

**C API**
<!--  XblPresenceSetPresenceAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
};

HRESULT hr = XblPresenceSetPresenceAsync(xboxLiveContext, true, nullptr, asyncBlock.get());
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!-- in gdk only:
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblPresenceSetPresenceAsync](xblpresencesetpresenceasync.md)
-->


<!-- ### Updating basic Presence status -->

<!-- **C API** -->
<!--  _C.md -->
<!-- ```cpp -->
<!-- This is the example above -->
<!-- ``` -->

<!-- **Reference** -->


## Updating Rich Presence status

**C API**
<!--  _C.md -->
```cpp
XblPresenceRichPresenceIds ids{};
pal::strcpy(ids.scid, sizeof(ids.scid), scid);
ids.presenceId = "playingMap";
std::vector<const char*> tokenIds{ "CurrentMap" };
ids.presenceTokenIds = tokenIds.data();
ids.presenceTokenIdsCount = tokenIds.size();

HRESULT hr = XblPresenceSetPresenceAsync(xboxLiveContext, true, &ids, asyncBlock.get());
```

<!-- in gdk only:
**Reference**
* [XblPresenceRichPresenceIds](xblpresencerichpresenceids.md)
* [XblPresenceSetPresenceAsync](xblpresencesetpresenceasync.md)
-->
