---
title: Example code for event-based Stats
description: Example code for a game sending events about Stats, to the Xbox Live service.
kindex: Xbox Live stats
kindex: stats, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-stats-eb-code.html
---

# Example code for event-based Stats

As of July 2019, the following is the most important code for sending events:

```
    HRESULT hr = XblEventsWriteInGameEvent(
        Data()->xboxLiveContext,
        eventName.c_str(),
        dimensionsJson.c_str(),
        measurementsJson.c_str()
    );
```

```
    XAsyncBlock* asyncBlock = new XAsyncBlock{};
    asyncBlock->queue = Data()->queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](XAsyncBlock* asyncBlock)
    {
        size_t resultSize;
        HRESULT hr = XblUserStatisticsGetSingleUserStatisticResultSize(asyncBlock, &resultSize);

        if (SUCCEEDED(hr))
        {
            std::vector<char> buffer(resultSize, 0);
            XblUserStatisticsResult* result{};

            hr = XblUserStatisticsGetSingleUserStatisticResult(asyncBlock, resultSize, buffer.data(), &result, nullptr);
        }

        CallLuaFunctionWithHr(hr, "OnXblUserStatisticsGetSingleUserStatisticAsync"); // CODE SNIP SKIP
        delete asyncBlock;
    };
    
    HRESULT hr = XblUserStatisticsGetSingleUserStatisticAsync(
        Data()->xboxLiveContext,
        Data()->xboxUserId,
        Data()->scid.value,
        statisticName.c_str(),
        asyncBlock
    );
```


## Stats Reference

See [user_statistics_c header](user_statistics_c_members.md).

See the [Xbox Live Services RESTful Reference](https://docs.microsoft.com/gaming/xbox-live/xbox-live-rest/atoc-xboxlivews-reference).
