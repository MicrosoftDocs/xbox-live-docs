---
title: Deleting a blob from Title Storage
description: Example code for deleting a blob from Title Storage.
kindex: Deleting a blob from Title Storage
author: heba
ms.author: heba
ms.topic: conceptual
ms.prod: xbox
ms.technology: xboxgc
ms.date: 11/15/2019
ms.localizationpriority: medium
edited: 11/15/2019
---

# Deleting a blob from Title Storage

The following code example demonstrates how to delete a blob in Xbox Live Title Storage.

**C API**
<!-- XblTitleStorageDeleteBlobAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
};

HRESULT hr = XblTitleStorageDeleteBlobAsync(
    xboxLiveContext,
    blobMetadata,
    deleteOnlyIfEtagMatches,
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
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblTitleStorageDeleteBlobAsync](xbltitlestoragedeleteblobasync.md)
-->