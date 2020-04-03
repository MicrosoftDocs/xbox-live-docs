---
title: Downloading a blob from Title Storage
description: Example code for downloading a blob from Title Storage.
kindex: Downloading a blob from Title Storage
ms.topic: conceptual
ms.assetid: f424aca1-e671-4e31-84c6-098fda4a9558
ms.localizationpriority: high
author: heba
ms.author: heba
ms.date: 11/15/2019
---




# Downloading a blob from Title Storage

The following code example demonstrates how to download a blob from Xbox Live Title Storage.

Notes about `XblTitleStorageDownloadBlobAsync` parameters:
- The buffer provided to store the downloaded blob data needs to be large enough to store the blob being downloaded. If necessary, the length required for the buffer can be retrieved by getting the blob metadata.
- This API will return E_NOT_SUFFICIENT_BUFFER (0x8007007A) if the `blobBuffer` doesn't have enough capacity to hold the blob data.
- Pass 0 for the `preferredDownloadBlockSize` to use the default size.


**C API**
<!--  XblTitleStorageDownloadBlobAsync_C.md -->
```cpp
std::unique_ptr<std::vector<uint8_t>> downloadBlobBuffer = std::make_unique<std::vector<uint8_t>>(blobMetadata.length);

auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = downloadBlobBuffer.get();
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    std::unique_ptr<std::vector<uint8_t>> downloadBlobBuffer{ static_cast<std::vector<uint8_t>*>(asyncBlock->context) };
    HRESULT hr = XblTitleStorageDownloadBlobResult(asyncBlock, &blobMetadata);
};

HRESULT hr = XblTitleStorageDownloadBlobAsync(
    xboxLiveContext,
    blobMetadata,
    downloadBlobBuffer->data(),
    blobMetadata.length,
    XblTitleStorageETagMatchCondition::NotUsed,
    selectQuery.c_str(), // optional
    preferredDownloadBlockSize, // optional
    asyncBlock.get()
);

if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
    downloadBlobBuffer.release();
}
```

<!--
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblTitleStorageDownloadBlobAsync](xbltitlestoragedownloadblobasync.md)
* [XblTitleStorageDownloadBlobResult](xbltitlestoragedownloadblobresult.md)
* [XblTitleStorageETagMatchCondition](xbltitlestorageetagmatchcondition.md)
-->
