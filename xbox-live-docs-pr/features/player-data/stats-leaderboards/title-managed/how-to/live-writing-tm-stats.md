---
title: Writing title-managed stats
description: Example code for writing title-managed stats.
kindex: Writing title-managed stats
kindex: Leaderboards
ms.topic: conceptual
ms.localizationpriority: high
author: mlamaute
ms.author: migreen
ms.date: 05/13/2020
---






# Writing title-managed stats


## Updating only the specified title-managed Stats

You can send specified stats that you want to update, by calling `XblTitleManagedStatsUpdateStatsAsync`, which selectively updates the calling user's stats.
A specified stat will only be overwritten if it already exists; any stats that are not specified in the call to `XblTitleManagedStatsUpdateStatsAsync` will remain unchanged.

<!-- **C API** -->
<!-- XblTitleManagedStatsUpdateStatsAsync.md -->
```cpp
std::vector<XblTitleManagedStatistic> stats{ s_svd->Stats() };
auto stat1 = std::find_if(stats.begin(), stats.end(), [](const XblTitleManagedStatistic& s)
{
    return std::string{ "AddedStat" } == s.statisticName;
});

auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = Data()->queue;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
};

HRESULT hr = XblTitleManagedStatsUpdateStatsAsync(
    Data()->xboxLiveContext,
    &(*stat1),
    1,
    asyncBlock.get()
);

if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!-- **Reference**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblTitleManagedStatistic](xbltitlemanagedstatistic.md)
* [XblTitleManagedStatsUpdateStatsAsync](xbltitlemanagedstatsupdatestatsasync.md) -->


## Writing all the stats you want to keep, and deleting the rest

To write only the title-managed stats that you want to keep, and delete the rest, call `XblTitleManagedStatsWriteAsync` with all the stats you want to write.
Any stats that are not included in the call will be removed; this call replaces the last stats document on the service with a new stats document that contains only the values you sent.


**C API**
<!-- XblTitleManagedStatsWriteAsync.md -->
```cpp
std::vector<XblTitleManagedStatistic> statList;
statList.push_back(XblTitleManagedStatistic{ "MyStatName1", XblTitleManagedStatType::Number, 200 });
statList.push_back(XblTitleManagedStatistic{ "MyStatName2", XblTitleManagedStatType::String, 0, "SomeValue" });

auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
};

HRESULT hr = XblTitleManagedStatsWriteAsync(
    xboxLiveContext, 
    xboxUserId, 
    statList.data(), statList.size(), 
    asyncBlock.get());
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!-- **Reference**
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblTitleManagedStatistic](xbltitlemanagedstatistic.md)
* [XblTitleManagedStatsWriteAsync](xbltitlemanagedstatswriteasync.md)
* [XblTitleManagedStatType](xbltitlemanagedstattype.md) -->


### See also

* [Updating title-managed Stats](live-stats-tm-updating.md) - Coding concepts for the C++ API and WinRT C# API
