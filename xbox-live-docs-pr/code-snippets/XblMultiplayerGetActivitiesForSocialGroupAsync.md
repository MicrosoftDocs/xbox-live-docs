```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>();
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    size_t activityCount = 0;
    HRESULT hr = XblMultiplayerGetActivitiesForSocialGroupResultCount(asyncBlock, &activityCount);
    if (SUCCEEDED(hr))
    {
        std::vector<XblMultiplayerActivityDetails> activities(activityCount);
        hr = XblMultiplayerGetActivitiesForSocialGroupResult(asyncBlock, activityCount, activities.data());
    }

};

HRESULT hr = XblMultiplayerGetActivitiesForSocialGroupAsync(
    xboxLiveContext,
    scid,
    socialGroupOwnerXuid,
    socialGroup.c_str(),
    asyncBlock.get());
if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```
