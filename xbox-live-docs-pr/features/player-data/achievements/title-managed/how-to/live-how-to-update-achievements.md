---
title: Updating title-managed Achievements
description: Example code for updating title-managed Achievements.
kindex: Updating title-managed Achievements
author: XBL
ms.author: v-jasch
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
ms.date: 09/23/2019
ms.localizationpriority: medium
---

# Updating title-managed Achievements

**Contents:**
* [Unlocking an Achievement](#unlocking-an-achievement)
* [Updating completion progress for an Achievement](#updating-an-achievement)


<!-- ===================================================== -->
<a id="unlocking-an-achievement"></a>

## Unlocking an Achievement

Once your achievements are configured via Partner Center and published to your development sandbox, your title can unlock them by calling the `XblAchievementsUpdateAchievementAsync` API.
See the code in the next section.

To unlock an achievement, set the *percentComplete* to 100.
If the user is online, the request will be immediately sent to the Xbox Live Achievements service and will trigger the following user experiences:
-   The user will receive an Achievement Unlocked notification;
-   The specified achievement will appear as Unlocked in the user’s achievement list for the title;
-   The unlocked achievement will be added to the user’s activity feed.
    > [!NOTE]
    > There will be no visible difference in user experiences for achievements that use event-based or title-managed Achievements.

If the user is offline, the unlock request will be queued locally on the user’s device.
When the user’s device has reestablished network connectivity, the request will automatically be sent to the Achievements service (no action is required from the game to trigger this), and the above user experiences will occur as described.


<!-- ===================================================== -->
<a id="updating-an-achievement"></a>

## Updating completion progress for an Achievement

To update a user’s progress toward unlocking an achievement, call `XblAchievementsUpdateAchievementAsync`, setting the *percentComplete* argument to a whole number between 1-100.
See the code below.

An achievement’s progress can only increase.
If *percentComplete* is set to a number less than the achievement’s last *percentComplete* value, the update will be ignored. 
For example, if the achievement’s *percentComplete* had previously been set to 75, sending an update with a value of 25 will be ignored and the achievement will still be displayed as 75% complete.

If *percentComplete* is set to 100, the achievement will unlock.

If *percentComplete* is set to a number greater than 100, the API will behave as if you set it to exactly 100.


### Updating achievements for the present title

You can update achievements for the current title by calling `XblAchievementsUpdateAchievementAsync`, as follows.

**C API**
<!-- XblAchievementsUpdateAchievementAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    auto result = XAsyncGetStatus(asyncBlock, false);
    if (SUCCEEDED(result))
    {
        // Achievement updated
    }
    else if (result == HTTP_E_STATUS_NOT_MODIFIED)
    {
        // Achievement not modified
    }
    else
    {
        // Achievement failed to update
    }
};

HRESULT hr = XblAchievementsUpdateAchievementAsync(
    xboxLiveContext,
    xboxUserId,
    achievementId.c_str(),
    percentComplete,
    asyncBlock.get()
);
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!-- not present in public 
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblAchievementsUpdateAchievementAsync](xblachievementsupdateachievementasync.md)
-->


### Updating achievements for a different title

You can update achievements for another `titleId`, by using `XblAchievementsUpdateAchievementForTitleIdAsync`, as follows.

**C API**
<!-- XblAchievementsUpdateAchievementForTitleIdAsync.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    auto result = XAsyncGetStatus(asyncBlock, false);
    if (SUCCEEDED(result))
    {
        // Achievement updated
    }
    else if (result == HTTP_E_STATUS_NOT_MODIFIED)
    {
        // Achievement not modified
    }
    else
    {
        // Achievement failed to update
    }
};

HRESULT hr = XblAchievementsUpdateAchievementForTitleIdAsync(
    xboxLiveContext,
    xboxUserId,
    titleId,
    scid,
    achievementId.c_str(),
    percentComplete,
    asyncBlock.get()
);
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!-- not present in public 
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblAchievementsUpdateAchievementForTitleIdAsync](xblachievementsupdateachievementfortitleidasync.md)
-->
