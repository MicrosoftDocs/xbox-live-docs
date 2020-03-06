---
title: Getting title-managed Achievements
description: Example code for getting title-managed Achievements.
kindex: Getting title-managed Achievements
author: XBL
ms.author: v-jasch
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
ms.date: 09/23/2019
ms.localizationpriority: medium
---


# Getting title-managed Achievements

**Contents:**
* [Getting the Achievements List](#getting-the-achievements-list)
* [Getting the next page of Achievements results](#getting-the-next-page-of-achievements-results)
* [Getting a single Achievement](#getting-a-single-achievement)


<!-- ===================================================== -->
<a id="getting-the-achievements-list"></a>

## Getting the Achievements List

To get the achievements for the running title, call `XblAchievementsGetAchievementsForTitleIdAsync`, as follows.


### Calling XblAchievementsGetAchievementsForTitleIdAsync

**C API**
<!-- XblAchievementsGetAchievementsForTitleIdAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*

    XblAchievementsResultHandle resultHandle;
    auto hr = XblAchievementsGetAchievementsForTitleIdResult(asyncBlock, &resultHandle);

    if (SUCCEEDED(hr))
    {
        const XblAchievement* achievements = nullptr;
        size_t achievementsCount = 0;
        hr = XblAchievementsResultGetAchievements(resultHandle, &achievements, &achievementsCount);

        for (size_t i = 0; i < achievementsCount; i++)
        {
            LogToScreen("Achievement %s: %s = %s", 
                achievements[i].id, 
                achievements[i].name,
                (achievements[i].progressState == XblAchievementProgressState::Achieved) ? "Achieved" : "Not achieved");
        }

        XblAchievementsResultCloseHandle(resultHandle); // when done with handle, close it
        achievements = nullptr; // Clear array after calling XblAchievementsResultCloseHandle to pointer to freed memory
        // Instead you could not close the handle and store it.  Then 
        // if you needed to copy the handle, call XblAchievementsResultDuplicateHandle()
    }
};

HRESULT hr = XblAchievementsGetAchievementsForTitleIdAsync(
    xboxLiveContext,
    xboxUserId,
    titleId,
    achievementType,
    unlockedOnly,
    orderBy,
    skipItems,
    maxItems,
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
* [XblAchievement](xblachievement.md)
* [XblAchievementProgressState](xblachievementprogressstate.md)
* [XblAchievementsGetAchievementsForTitleIdAsync](xblachievementsgetachievementsfortitleidasync.md)
* [XblAchievementsGetAchievementsForTitleIdResult](xblachievementsgetachievementsfortitleidresult.md)
* [XblAchievementsResultCloseHandle](xblachievementsresultclosehandle.md)
* [XblAchievementsResultDuplicateHandle](xblachievementsresultduplicatehandle.md)
* [XblAchievementsResultGetAchievements](xblachievementsresultgetachievements.md)-->
<!-- * [XblAchievementsResultHandle](xblachievementsresulthandle.md) -->


<!-- ===================================================== -->
<a id="getting-the-next-page-of-achievements-results"></a>

## Getting the next page of Achievements results

There might be more pages of Achievements.  To know if there are more pages, call `XblAchievementsResultHasNext` and then `XblAchievementsResultGetNextAsync`.


### Calling XblAchievementsResultHasNext

**C API**
<!-- XblAchievementsResultHasNext.md -->
```cpp
HRESULT hr = S_OK;
bool hasNext = false;
if (achievementsResult != nullptr)
{
    hr = XblAchievementsResultHasNext(achievementsResult, &hasNext);
}
```

<!-- **Reference**
* [XblAchievementsResultHasNext](xblachievementsresulthasnext.md)-->


### Calling XblAchievementsResultGetNextAsync

To get the next page of Achievements, call `XblAchievementsResultGetNextAsync`, as follows.

**C API**
<!-- XblAchievementsResultGetNextAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    XblAchievementsResultHandle resultHandle;
    auto hr = XblAchievementsResultGetNextResult(asyncBlock, &resultHandle);

    if (SUCCEEDED(hr))
    {
        const XblAchievement* achievements = nullptr;
        size_t achievementsCount = 0;
        hr = XblAchievementsResultGetAchievements(resultHandle, &achievements, &achievementsCount);

        for (size_t i = 0; i < achievementsCount; i++)
        {
            LogToScreen("Achievement %s: %s = %s",
                achievements[i].id,
                achievements[i].name,
                (achievements[i].progressState == XblAchievementProgressState::Achieved) ? "Achieved" : "Not achieved");
        }

        XblAchievementsResultCloseHandle(resultHandle); // when done with handle, close it
        achievements = nullptr; // Clear array after calling XblAchievementsResultCloseHandle to pointer to freed memory
    }
};

HRESULT hr = XblAchievementsResultGetNextAsync(
    achievementsResult,
    maxItems,
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
* [XblAchievement](xblachievement.md)
* [XblAchievementProgressState](xblachievementprogressstate.md)
* [XblAchievementsResultCloseHandle](xblachievementsresultclosehandle.md)
* [XblAchievementsResultGetAchievements](xblachievementsresultgetachievements.md)
* [XblAchievementsResultGetNextAsync](xblachievementsresultgetnextasync.md)
* [XblAchievementsResultGetNextResult](xblachievementsresultgetnextresult.md)-->
<!-- * [XblAchievementsResultHandle](xblachievementsresulthandle.md) -->


<!-- ===================================================== -->
<a id="getting-a-single-achievement"></a>

## Getting a single Achievement

To get a single Achievement, call `XblAchievementsGetAchievementAsync`, as follows.

**C API**
<!-- XblAchievementsGetAchievementAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    XblAchievementsResultHandle resultHandle;
    auto hr = XblAchievementsGetAchievementResult(asyncBlock, &resultHandle);

    if (SUCCEEDED(hr))
    {
        const XblAchievement* achievements = nullptr;
        size_t achievementsCount = 0;
        hr = XblAchievementsResultGetAchievements( resultHandle, &achievements, &achievementsCount );

        // Use achievements array to read the achievement data.

        XblAchievementsResultCloseHandle(resultHandle); // when done with handle, close it
        achievements = nullptr; // Clear array after calling XblAchievementsResultCloseHandle to avoid ptr to freed memory
    }
};

HRESULT hr = XblAchievementsGetAchievementAsync(
    xboxLiveContext,
    xboxUserId,
    scid,
    achievementId.c_str(),
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
* [XblAchievement](xblachievement.md)
* [XblAchievementsGetAchievementAsync](xblachievementsgetachievementasync.md)
* [XblAchievementsGetAchievementResult](xblachievementsgetachievementresult.md)
* [XblAchievementsResultCloseHandle](xblachievementsresultclosehandle.md)
* [XblAchievementsResultGetAchievements](xblachievementsresultgetachievements.md)-->
<!-- * [XblAchievementsResultHandle](xblachievementsresulthandle.md) -->
