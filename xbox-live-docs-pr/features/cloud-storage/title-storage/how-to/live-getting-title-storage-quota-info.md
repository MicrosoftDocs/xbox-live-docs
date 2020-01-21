---
title: Getting quota info for a Title Storage service configuration
description: Example code for getting quota info for a Title Storage service configuration.
kindex: Getting quota info for a Title Storage service configuration
author: heba
ms.author: heba
ms.topic: conceptual
ms.prod: xbox
ms.technology: xboxgc
ms.date: 11/15/2019
ms.localizationpriority: medium
edited: 11/15/2019
---

# Getting quota info for a Title Storage service configuration

The following code example demonstrates how to get quota info for a specified service configuration and storage type in Title Storage.

NOTE: For TrustedPlatform storage types, the request will be made for the calling user's Xbox user ID.

**C API**
<!-- XblTitleStorageGetQuotaAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t usedBytes;
    size_t quotaBytes;
    HRESULT hr = XblTitleStorageGetQuotaResult(asyncBlock, &usedBytes, &quotaBytes);
};

HRESULT hr = XblTitleStorageGetQuotaAsync(
    xboxLiveContext,
    scid,
    storageType,
    asyncBlock.get()
);

if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!-- In .Chm only:
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblTitleStorageGetQuotaAsync](xbltitlestoragegetquotaasync.md)
* [XblTitleStorageGetQuotaResult](xbltitlestoragegetquotaresult.md)
-->