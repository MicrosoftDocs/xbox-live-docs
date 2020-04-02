---
title: Getting a user's Presence
description: Example code for getting a user's Presence.
kindex: Getting a user's Presence
kindex: Presence
ms.topic: how-to
ms.localizationpriority: high
author: mikehoffms
ms.author: v-mihof
ms.date: 01/09/2020
---


# Getting a user's Presence

 ​
## Getting a single user's presence


**C API**
<!--  XblPresenceGetPresenceAsync_C.md.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    HRESULT hr = XblPresenceGetPresenceResult(asyncBlock, &state.presenceRecord);

    // Be sure to call XblPresenceRecordCloseHandle when the presence record is no longer needed.
};

HRESULT hr = XblPresenceGetPresenceAsync(xboxLiveContext, xboxUserId, asyncBlock.get());
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!--**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblPresenceGetPresenceAsync](xblpresencegetpresenceasync.md)
* [XblPresenceGetPresenceResult](xblpresencegetpresenceresult.md)
* [XblPresenceRecordCloseHandle](xblpresencerecordclosehandle.md)-->


## Getting multiple users' presence strings


**C API**
<!--  XblPresenceGetPresenceForMultipleUsersAsync_C.md -->
<!-- note guids "123, 456" -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t resultCount{ 0 };
    HRESULT hr = XblPresenceGetPresenceForMultipleUsersResultCount(asyncBlock, &resultCount);

    if (SUCCEEDED(hr) && resultCount > 0)
    {
        std::vector<XblPresenceRecordHandle> handles(resultCount, nullptr);
        hr = XblPresenceGetPresenceForMultipleUsersResult(asyncBlock, handles.data(), resultCount);

        // Be sure to call XblPresenceRecordCloseHandle for each presence record when they are
        // no longer needed.
    }
};

std::vector<uint64_t> xuids{ 123, 456 };

// Filter results to only online users
XblPresenceQueryFilters filters{};
filters.onlineOnly = true;

HRESULT hr = XblPresenceGetPresenceForMultipleUsersAsync(xboxLiveContext, xuids.data(), xuids.size(), &filters, asyncBlock.get());
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!--**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblPresenceGetPresenceForMultipleUsersAsync](xblpresencegetpresenceformultipleusersasync.md)
* [XblPresenceGetPresenceForMultipleUsersResult](xblpresencegetpresenceformultipleusersresult.md)
* [XblPresenceGetPresenceForMultipleUsersResultCount](xblpresencegetpresenceformultipleusersresultcount.md)
* [XblPresenceQueryFilters](xblpresencequeryfilters.md)
* [XblPresenceRecordCloseHandle](xblpresencerecordclosehandle.md)-->
<!-- * [XblPresenceRecordHandle](xblpresencerecordhandle.md) -->


## Getting a user's presence from a social group


**C API**
<!--  XblPresenceGetPresenceForSocialGroupAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t resultCount{ 0 };
    HRESULT hr = XblPresenceGetPresenceForSocialGroupResultCount(asyncBlock, &resultCount);

    if (SUCCEEDED(hr) && resultCount > 0)
    {
        std::vector<XblPresenceRecordHandle> handles(resultCount, nullptr);
        hr = XblPresenceGetPresenceForSocialGroupResult(asyncBlock, handles.data(), resultCount);

        // Be sure to call XblPresenceRecordCloseHandle for each presence record when they are
        // no longer needed.
    }

};

HRESULT hr = XblPresenceGetPresenceForSocialGroupAsync(xboxLiveContext, "Favorites", nullptr, nullptr, asyncBlock.get());
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!--**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblPresenceGetPresenceForSocialGroupAsync](xblpresencegetpresenceforsocialgroupasync.md)
* [XblPresenceGetPresenceForSocialGroupResult](xblpresencegetpresenceforsocialgroupresult.md)
* [XblPresenceGetPresenceForSocialGroupResultCount](xblpresencegetpresenceforsocialgroupresultcount.md)
* [XblPresenceRecordCloseHandle](xblpresencerecordclosehandle.md)-->
<!-- * [XblPresenceRecordHandle](xblpresencerecordhandle.md) -->


## Displaying a user's presence


**C API**
<!--  _C.md -->
```cpp
const XblPresenceDeviceRecord* deviceRecords{ nullptr };
size_t deviceRecordsCount{ 0 };
HRESULT hr = XblPresenceRecordGetDeviceRecords(state.presenceRecord, &deviceRecords, &deviceRecordsCount);

for (auto i = 0u; i < deviceRecordsCount; ++i)
{
    auto& deviceRecord{ deviceRecords[i] };
    LogToFile("Got XblDeviceRecord with device type %u and %u title records", deviceRecord.deviceType, deviceRecord.titleRecordsCount);

    for (auto j = 0u; j < deviceRecord.titleRecordsCount; ++j)
    {
        auto& titleRecord{ deviceRecord.titleRecords[j] };
        // Display rich presence string
        LogToFile("Rich presence string for titleId %u: %s", titleRecord.titleId, titleRecord.richPresenceString);
    }
}
```

<!--**Reference**
* [XblPresenceDeviceRecord](xblpresencedevicerecord.md)
* [XblPresenceRecordGetDeviceRecords](xblpresencerecordgetdevicerecords.md)-->
