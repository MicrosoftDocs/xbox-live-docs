---
title: Submitting Reputation feedback
description: Example code for submitting Reputation feedback.
kindex: Submitting Reputation feedback
kindex: Reputation
author: mikehoffms
ms.author: v-mihof
ms.date: 01/09/2020
ms.topic: conceptual
ms.localizationpriority: medium
---

# Submitting Reputation feedback


## Submitting a single Reputation feedback

**C API**
<!--  XblSocialSubmitReputationFeedbackAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
};

uint64_t xuid{ 2814639011617876 };
HRESULT hr = XblSocialSubmitReputationFeedbackAsync(
    xboxLiveContext,
    xuid,
    XblReputationFeedbackType::PositiveHelpfulPlayer,
    nullptr,
    "Helpful player",
    nullptr,
    asyncBlock.get()
);
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblReputationFeedbackType](xblreputationfeedbacktype.md)
* [XblSocialSubmitReputationFeedbackAsync](xblsocialsubmitreputationfeedbackasync.md)


## Submitting multiple Reputation feedback items

**C API**
<!--  _C.md -->
```cpp
std::vector<XblReputationFeedbackItem> feedbackItems;
feedbackItems.push_back(XblReputationFeedbackItem
    {
        2814639011617876,
        XblReputationFeedbackType::PositiveHelpfulPlayer,
        nullptr,
        "Helpful player",
        nullptr
    });
// Add any additional feedback items here

auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
};

HRESULT hr = XblSocialSubmitBatchReputationFeedbackAsync(
    xboxLiveContext,
    feedbackItems.data(),
    feedbackItems.size(),
    asyncBlock.get()
);
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XAsyncGetStatus](xasyncgetstatus.md)
* [XblReputationFeedbackItem](xblreputationfeedbackitem.md)
* [XblReputationFeedbackType](xblreputationfeedbacktype.md)
* [XblSocialSubmitBatchReputationFeedbackAsync](xblsocialsubmitbatchreputationfeedbackasync.md)
