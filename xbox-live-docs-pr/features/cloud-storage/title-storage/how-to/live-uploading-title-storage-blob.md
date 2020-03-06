---
title: Uploading a blob to Title Storage
description: Example code for uploading a blob to Title Storage.
kindex: Uploading a blob to Title Storage
author: heba
ms.author: heba
ms.topic: conceptual
ms.prod: xbox
ms.technology: xboxgc
ms.assetid: f424aca1-e671-4e31-84c6-098fda4a9558
ms.date: 11/15/2019
ms.localizationpriority: medium
edited: 00/00/0000
---

# Uploading a blob to Title Storage

The following code example demonstrates how to upload a blob to Xbox Live Title Storage.

Notes about `XblTitleStorageUploadBlobAsync` parameters:
- The buffer containing the blob data to upload must be available for the duration of the async operation. Clients should not modify the buffer while an upload is in progress.
- This method will use a default size if `preferredUploadBlockSize` is not provided or is not within the acceptable range. The current minimum size is 1024 bytes. The maximum size is 4194304 bytes.  The default size is 262144 bytes.
- Binary blobs will be uploaded in multiple chunks of `preferredUploadBlockSize` if they exceed it. Larger sizes are preferred by the service. If timeouts occur, the app should retry with a smaller size.

**C API**
<!--  XblTitleStorageUploadBlobAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = blobBuffer.get();
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    std::unique_ptr<std::vector<uint8_t>> blobBuffer{ static_cast<std::vector<uint8_t>*>(asyncBlock->context) };
    HRESULT hr = XblTitleStorageUploadBlobResult(asyncBlock, &blobMetadata);

};

XblTitleStorageBlobMetadata blobMetadata{};
pal::strcpy(blobMetadata.displayName, displayName.size() + 1, displayName.c_str());
pal::strcpy(blobMetadata.serviceConfigurationId, XBL_SCID_LENGTH, scid);
pal::strcpy(blobMetadata.blobPath, blobPath.size() + 1, blobPath.c_str());
blobMetadata.storageType = storageType;
blobMetadata.blobType = blobType;
time(&blobMetadata.clientTimestamp);

HRESULT hr = XblTitleStorageUploadBlobAsync(
    xboxLiveContext,
    blobMetadata,
    reinterpret_cast<const uint8_t*>(blobBuffer->data()),
    blobBufferSize,
    eTagMatchCondition,
    preferredUploadBlockSize, // optional
    asyncBlock.get()
);

if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
    blobBuffer.release();
}
```

<!--
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblTitleStorageBlobMetadata](xbltitlestorageblobmetadata.md)
* [XblTitleStorageUploadBlobAsync](xbltitlestorageuploadblobasync.md)
* [XblTitleStorageUploadBlobResult](xbltitlestorageuploadblobresult.md)
-->
