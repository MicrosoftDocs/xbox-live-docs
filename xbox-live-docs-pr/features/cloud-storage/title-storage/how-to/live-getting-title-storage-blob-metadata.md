---
title: Getting Title Storage blob metadata
description: Example code for getting Title Storage blob metadata.
kindex: Getting Title Storage blob metadata
ms.topic: conceptual
ms.localizationpriority: high
author: heba
ms.author: heba
ms.date: 11/15/2019
---




# Getting Title Storage blob metadata

The following code example demonstrates how to retrieve blob metadata from Xbox Live Title Storage.

**C API**
<!-- XblTitleStorageGetBlobMetadataAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock };
    XblTitleStorageBlobMetadataResultHandle handle;
    HRESULT hr = XblTitleStorageGetBlobMetadataResult(asyncBlock, &handle);

    if (SUCCEEDED(hr))
    {
        if (blobMetadataResultHandle != nullptr)
        {
            XblTitleStorageBlobMetadataResultCloseHandle(blobMetadataResultHandle);
        }

        blobMetadataResultHandle = handle;
    }

};

HRESULT hr = XblTitleStorageGetBlobMetadataAsync(
    xboxLiveContext,
    scid,
    storageType,
    blobPath.c_str(),
    xboxUserId,
    skipItems,
    maxItems,
    asyncBlock.get()
);
if (SUCCEEDED(hr))
{
    asyncBlock.release();
}
```

<!-- 
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblTitleStorageBlobMetadataResultCloseHandle](xbltitlestorageblobmetadataresultclosehandle.md)
-->
<!-- * [XblTitleStorageBlobMetadataResultHandle](xbltitlestorageblobmetadataresulthandle.md) -->
<!-- 
* [XblTitleStorageGetBlobMetadataAsync](xbltitlestoragegetblobmetadataasync.md)
* [XblTitleStorageGetBlobMetadataResult](xbltitlestoragegetblobmetadataresult.md)
-->


Once you have an `XblTitleStorageBlobMetadataResultHandle`, the code below demonstrates how to retrieve the list of `XblTitleStorageBlobMetadata` objects.

**C API**
<!-- XblTitleStorageBlobMetadataResultGetItems_C.md -->
```cpp
XblTitleStorageBlobMetadataResultHandle handle = blobMetadataResultHandle;

const XblTitleStorageBlobMetadata* items;
size_t itemsSize;

HRESULT hr = XblTitleStorageBlobMetadataResultGetItems(handle, &items, &itemsSize);
```

<!-- 
**Reference**
* [XblTitleStorageBlobMetadata](xbltitlestorageblobmetadata.md)
* [XblTitleStorageBlobMetadataResultGetItems](xbltitlestorageblobmetadataresultgetitems.md)
-->

<!-- * [XblTitleStorageBlobMetadataResultHandle](xbltitlestorageblobmetadataresulthandle.md) -->


## Retrieving the Next Page of XblTitleStorageBlobMetadata Objects

Depending on the number of blobs the title has in Title Storage, there might be several pages of `XblTitleStorageBlobMetadata` in existence. The above example will only retrieve the first page of entries.

The following code example demonstrates how to check if they are more pages of `XblTitleStorageBlobMetadata` to retrieve from Title Storage.

**C API**
<!-- XblTitleStorageBlobMetadataResultHasNext_C.md -->
```cpp
XblTitleStorageBlobMetadataResultHandle handle = blobMetadataResultHandle;

bool hasNext;
HRESULT hr = XblTitleStorageBlobMetadataResultHasNext(handle, &hasNext);
```
<!-- 
**Reference**
-->
<!-- * [XblTitleStorageBlobMetadataResultHandle](xbltitlestorageblobmetadataresulthandle.md) -->
<!-- 
* [XblTitleStorageBlobMetadataResultHasNext](xbltitlestorageblobmetadataresulthasnext.md)
-->

In the case where they are more pages of `XblTitleStorageBlobMetadata`, the code example below demonstrates how to retrieve the next page of `XblTitleStorageBlobMetadata` objects.

**C API**
<!-- XblTitleStorageBlobMetadataResultGetNextAsync_C.md -->
```cpp
XblTitleStorageBlobMetadataResultHandle handle = blobMetadataResultHandle;

auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock };
    XblTitleStorageBlobMetadataResultHandle handle{ nullptr };
    
    HRESULT hr = XblTitleStorageBlobMetadataResultGetNextResult(asyncBlock, &handle);

};

HRESULT hr = XblTitleStorageBlobMetadataResultGetNextAsync(handle, maxItems, asyncBlock.get());
if (SUCCEEDED(hr))
{
    asyncBlock.release();
}
```

<!-- 
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblTitleStorageBlobMetadataResultGetNextAsync](xbltitlestorageblobmetadataresultgetnextasync.md)
* [XblTitleStorageBlobMetadataResultGetNextResult](xbltitlestorageblobmetadataresultgetnextresult.md)
-->
<!-- * [XblTitleStorageBlobMetadataResultHandle](xbltitlestorageblobmetadataresulthandle.md) -->


## Duplicating XblTitleStorageBlobMetadataResultHandle

The code below demonstrates how to create a duplicate of the `XblTitleStorageBlobMetadataResultHandle`.

**C API**
<!-- XblTitleStorageBlobMetadataResultDuplicateHandle_C.md -->
```cpp
XblTitleStorageBlobMetadataResultHandle handle = blobMetadataResultHandle;
XblTitleStorageBlobMetadataResultHandle duplicatedHandle;

HRESULT hr = XblTitleStorageBlobMetadataResultDuplicateHandle(handle, &duplicatedHandle);
```

<!-- 
**Reference**
* [XblTitleStorageBlobMetadataResultDuplicateHandle](xbltitlestorageblobmetadataresultduplicatehandle.md)
-->
<!-- * [XblTitleStorageBlobMetadataResultHandle](xbltitlestorageblobmetadataresulthandle.md) -->


## Closing XblTitleStorageBlobMetadataResultHandle

When done with the `XblTitleStorageBlobMetadataResultHandle`, the code below demonstrates how to close the `XblTitleStorageBlobMetadataResultHandle`.

**C API**
<!-- XblTitleStorageBlobMetadataResultCloseHandle_C.md -->
```cpp
XblTitleStorageBlobMetadataResultHandle handle = blobMetadataResultHandle;
XblTitleStorageBlobMetadataResultCloseHandle(handle);
blobMetadataResultHandle = nullptr;
```

<!-- 
**Reference**
* [XblTitleStorageBlobMetadataResultCloseHandle](xbltitlestorageblobmetadataresultclosehandle.md)
-->
<!-- * [XblTitleStorageBlobMetadataResultHandle](xbltitlestorageblobmetadataresulthandle.md) -->
