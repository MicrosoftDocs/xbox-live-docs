---
title: Sending invites
description: Example code for sending multiplayer invites.
kindex: Sending invites
kindex: invites
ms.topic: how-to
ms.localizationpriority: high
author: jeffshi
ms.author: jeffshi
ms.date: 10/01/2019
---

# Sending invites

One of the key multiplayer scenarios is to allow a player to invite another player to a game session.
Your game sends invites to other players to join your game session.

<!-- chm-only content here -->






<!-- ## Using the Title-Callable UI (TCUI) (System UI overlay)

chm-only content here
 -->


## Using a title-implemented custom UI

<!-- destination not in this repo: Your title can implement a custom UI for viewing online friends and inviting game. You can use the [XblMultiplayerSendInvitesAsync](xblmultiplayersendinvitesasync.md) API to send invites to a set of players defined by their Xbox Live User IDs.  -->
Your title can implement a custom UI for viewing online friends and inviting game. You can use the `XblMultiplayerSendInvitesAsync` API to send invites to a set of players defined by their Xbox Live User IDs. <!--chm: This is useful if you prefer to use your own in-game UI instead of the stock System UI.--> <!--main docs:  -->This uses your own in-game UI.

**C API**
<!-- XblMultiplayerSendInvitesAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t handlesCount = 1; // must be equal to invites requested
    XblMultiplayerInviteHandle handles[1] = {};
    HRESULT hr = XblMultiplayerSendInvitesResult(asyncBlock, handlesCount, handles);
};

uint64_t xuids[1] = {};
xuids[0] = targetXuid;
size_t xuidsCount = 1;

HRESULT hr = XblMultiplayerSendInvitesAsync(
    xblContextHandle,
    &sessionReference,
    xuids,
    xuidsCount,
    titleId,
    contextStringId,
    customActivationContext,
    asyncBlock.get());
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!-- destination not in this repo: **Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblMultiplayerInviteHandle](xblmultiplayerinvitehandle.md)
* [XblMultiplayerSendInvitesAsync](xblmultiplayersendinvitesasync.md)
* [XblMultiplayerSendInvitesResult](xblmultiplayersendinvitesresult.md) -->


## See also

<!-- * chm-only api ref here -->
* To use Multiplayer Manager to handle game invites, see [Handling protocol activation to start a game, using Multiplayer Manager](../../mpm/how-to/live-handle-protocol-activation.md).
* [Sending game invites using Multiplayer Manager](../../mpm/how-to/live-send-game-invites.md)
