---
title: Getting event-based stats
description: Example code for getting event-based stats.
kindex: Getting event-based stats
kindex: stats, Xbox Live
author: mikehoffms
ms.author: v-mihof
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.localizationpriority: medium
ms.date: 11/22/2019
edited: 00/00/0000
---

# Getting event-based stats

APIs expose various levels of batching to get event-based stats.
It is best practice to make as few calls as possible using the batch API that fits your needs.

<!-- **Contents**
- [Getting a single stat for a single user and single SCID](#ID4EM1)
- [Getting multiple stats for a single user and single SCID](#ID4EM2)
- [Getting multiple stats for multiple users and single SCID](#ID4EM3)
- [Getting multiple stats for multiple users across multiple SCIDs](#ID4EM4) -->

You can also [subscribe to stats changes](live-handling-eb-stat-change.md).


<a id="ID4EM1"></a>

## Getting a single stat for a single user and single SCID

This example code shows how to read a single user stat.

**C API**
<!-- XblUserStatisticsGetSingleUserStatisticAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t resultSize;
    HRESULT hr = XblUserStatisticsGetSingleUserStatisticResultSize(asyncBlock, &resultSize);

    if (SUCCEEDED(hr))
    {
        std::vector<char> buffer(resultSize, 0);
        XblUserStatisticsResult* result{};

        hr = XblUserStatisticsGetSingleUserStatisticResult(asyncBlock, resultSize, buffer.data(), &result, nullptr);

        if (SUCCEEDED(hr) && result->serviceConfigStatisticsCount > 0 && result->serviceConfigStatistics->statisticsCount > 0)
        {
            int64_t userStatValue = atoll(result->serviceConfigStatistics[0].statistics[0].value);
            // Now you can show or store userStatValue
        }
    }
};

HRESULT hr = XblUserStatisticsGetSingleUserStatisticAsync(
    xboxLiveContext,
    xboxUserId,
    scid,
    statisticName.c_str(),
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
* [XblUserStatisticsGetSingleUserStatisticAsync](xbluserstatisticsgetsingleuserstatisticasync.md)
* [XblUserStatisticsGetSingleUserStatisticResult](xbluserstatisticsgetsingleuserstatisticresult.md)
* [XblUserStatisticsGetSingleUserStatisticResultSize](xbluserstatisticsgetsingleuserstatisticresultsize.md)
* [XblUserStatisticsResult](xbluserstatisticsresult.md) -->


<a id="ID4EM2"></a>

## Getting multiple stats for a single user and single SCID

This example code shows how to read multiple stats for a single user in one HTTP call.

**C API**
<!-- XblUserStatisticsGetSingleUserStatisticsAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t resultSize;
    HRESULT hr = XblUserStatisticsGetSingleUserStatisticsResultSize(asyncBlock, &resultSize);

    if (SUCCEEDED(hr))
    {
        std::vector<char> buffer(resultSize, 0);
        XblUserStatisticsResult* results{};

        hr = XblUserStatisticsGetSingleUserStatisticsResult(asyncBlock, resultSize, buffer.data(), &results, nullptr);
        if (SUCCEEDED(hr))
        {
            // Now you can use the XblUserStatisticsResult array in results
        }
    }

};

const char* statisticNames[2] = {};
statisticNames[0] = statisticName1.c_str();
statisticNames[1] = statisticName2.c_str();

HRESULT hr = XblUserStatisticsGetSingleUserStatisticsAsync(
    xboxLiveContext,
    xboxUserId,
    scid,
    statisticNames, 2, 
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
* [XblUserStatisticsGetSingleUserStatisticAsync](xbluserstatisticsgetsingleuserstatisticasync.md)
* [XblUserStatisticsGetSingleUserStatisticResult](xbluserstatisticsgetsingleuserstatisticresult.md)
* [XblUserStatisticsGetSingleUserStatisticResultSize](xbluserstatisticsgetsingleuserstatisticresultsize.md)
* [XblUserStatisticsResult](xbluserstatisticsresult.md) -->


<a id="ID4EM3"></a>

## Getting multiple stats for multiple users and single SCID

This example code shows how to read multiple stats for a multiple user in one HTTP call.

**C API**
<!-- XblUserStatisticsGetMultipleUserStatisticsAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t resultSize;
    HRESULT hr = XblUserStatisticsGetMultipleUserStatisticsResultSize(asyncBlock, &resultSize);

    if (SUCCEEDED(hr))
    {
        std::vector<char> buffer(resultSize, 0);
        XblUserStatisticsResult* results{};
        size_t resultsCount = 0;

        hr = XblUserStatisticsGetMultipleUserStatisticsResult(asyncBlock, resultSize, buffer.data(), &results, &resultsCount, nullptr);

        // Process results array to read the user stats data
        for (size_t iResult = 0; iResult < resultsCount; iResult++)
        {
            LogToFile("%d", results[iResult].xboxUserId);
            for (size_t iScid = 0; iScid < results[iResult].serviceConfigStatisticsCount; iScid++)
            {
                LogToFile("SCID: %s", results[iResult].serviceConfigStatistics[iScid].serviceConfigurationId);
                for (size_t iStat = 0; iStat < results[iResult].serviceConfigStatistics[iScid].statisticsCount; iStat++)
                {
                    LogToFile("Stat %d: name:%s value:%s type:%s", iResult,
                        results[iResult].serviceConfigStatistics[iScid].statistics[iStat].statisticName,
                        results[iResult].serviceConfigStatistics[iScid].statistics[iStat].value,
                        results[iResult].serviceConfigStatistics[iScid].statistics[iStat].statisticType );
                }
            }
        }
    }

};

const char* statisticNames[2] = {};
statisticNames[0] = statisticName1.c_str();
statisticNames[1] = statisticName2.c_str();

uint64_t xuids[2] = {};
xuids[0] = xuid1;
xuids[1] = xuid2;

HRESULT hr = XblUserStatisticsGetMultipleUserStatisticsAsync(
    xboxLiveContext,
    xuids, 2,
    scid,
    statisticNames, 2,
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
* [XblUserStatisticsGetMultipleUserStatisticsAsync](xbluserstatisticsgetmultipleuserstatisticsasync.md)
* [XblUserStatisticsGetMultipleUserStatisticsResult](xbluserstatisticsgetmultipleuserstatisticsresult.md)
* [XblUserStatisticsGetMultipleUserStatisticsResultSize](xbluserstatisticsgetmultipleuserstatisticsresultsize.md)
* [XblUserStatisticsResult](xbluserstatisticsresult.md) -->


<a id="ID4EM4"></a>

## Getting multiple stats for multiple users across multiple SCIDs

**C API**
<!-- XblUserStatisticsGetMultipleUserStatisticsForMultipleServiceConfigurationsAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t resultSize;
    HRESULT hr = XblUserStatisticsGetMultipleUserStatisticsForMultipleServiceConfigurationsResultSize(asyncBlock, &resultSize);

    if (SUCCEEDED(hr))
    {
        std::vector<char> buffer(resultSize, 0);
        XblUserStatisticsResult* results{};
        size_t resultsCount = 0;

        hr = XblUserStatisticsGetMultipleUserStatisticsForMultipleServiceConfigurationsResult(asyncBlock, resultSize, buffer.data(), &results, &resultsCount, nullptr);

        if (SUCCEEDED(hr))
        {
            for (size_t i = 0; i < resultsCount; i++)
            {
                // Log results
                std::stringstream stream;
                stream << "XUID: " << results[i].xboxUserId << std::endl;;

                for (size_t j = 0; j < results[i].serviceConfigStatisticsCount; j++)
                {
                    stream << " " << results[i].serviceConfigStatistics[j].serviceConfigurationId << ": " << std::endl;
                    for (size_t k = 0; k < results[i].serviceConfigStatistics[j].statisticsCount; k++)
                    {
                        stream << " " << results[i].serviceConfigStatistics[j].statistics[k].statisticName << "=" << results[i].serviceConfigStatistics[j].statistics[k].value << std::endl;
                    }
                }
            }
        }
    }

};

const char* requestedStatsNames1[2] = {};
requestedStatsNames1[0] = statisticName1.c_str();
requestedStatsNames1[1] = statisticName2.c_str();

XblRequestedStatistics requestedStats[1] = {};
pal::strcpy(requestedStats[0].serviceConfigurationId, sizeof(XblRequestedStatistics::serviceConfigurationId), scid);
requestedStats[0].statistics = requestedStatsNames1;
requestedStats[0].statisticsCount = 2;

uint64_t xuids[2] = {};
xuids[0] = xuid1;
xuids[1] = xuid2;
    
HRESULT hr = XblUserStatisticsGetMultipleUserStatisticsForMultipleServiceConfigurationsAsync(
    xboxLiveContext,
    xuids, 2,
    requestedStats, 1,
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
* [XblRequestedStatistics](xblrequestedstatistics.md)
* [XblUserStatisticsGetMultipleUserStatisticsForMultipleServiceConfigurationsAsync](xbluserstatisticsgetmultipleuserstatisticsformultipleserviceconfigurationsasync.md)
* [XblUserStatisticsGetMultipleUserStatisticsForMultipleServiceConfigurationsResult](xbluserstatisticsgetmultipleuserstatisticsformultipleserviceconfigurationsresult.md)
* [XblUserStatisticsGetMultipleUserStatisticsForMultipleServiceConfigurationsResultSize](xbluserstatisticsgetmultipleuserstatisticsformultipleserviceconfigurationsresultsize.md)
* [XblUserStatisticsResult](xbluserstatisticsresult.md) -->


## See also

* [Sending an event](live-sending-an-event.md)
* [user_statistics_c header](user_statistics_c_members.md)
