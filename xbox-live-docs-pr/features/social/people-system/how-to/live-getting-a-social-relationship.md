---
title: Getting a social relationship
description: Code example showing how to use the Social Manager API to retrieve a user's social relationships and their public properties.
kindex: Getting a social relationship
kindex: Social Manager
author: jeffshi
ms.author: jeffshi
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.assetid: 101d059a-e03f-472c-8300-800aa5730ee2
ms.localizationpriority: medium
ms.date: 04/04/2017
edited: 04/04/2017
---

# Getting a social relationship

> [!NOTE]
> This article demonstrates advanced API usage.  Please let your DAM know if you find an unsupported scenario in the Social Manager.

<!-- 
Commenting out the following that was in the above note, because the article is not in the docs. The article has been moved to the boneyard directory. To add the article to the docs, move it from the boneyard directory to an appropriate location in the  _content directory and then add the article to toc.md:

As a starting point, please take a look at the [Introduction to the Social Manager API](intro-to-social-manager.md) which significantly simplifies development.
-->


## Getting the first user's social relationships

The following code example demonstrates how to retrieve a social relationship with Xbox Live.

The example does the following:
1. Generates a list of all users on the system and retrieves the first one.
2. Retrieves all of that user's social relationships.
3. Displays the public properties of each of those relationships.

**C API**
<!--  XblSocialGetSocialRelationshipsAsync_C.md -->
```cpp
auto asyncBlock = std::make_unique<XAsyncBlock>(); 
asyncBlock->queue = queue;
asyncBlock->context = nullptr;
asyncBlock->callback = [](XAsyncBlock* asyncBlock)
{
    std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
    HRESULT hr = XblSocialGetSocialRelationshipsResult(asyncBlock, &state.socialResultHandle);

    // Be sure to call XblSocialRelationshipResultCloseHandle when the result object is no longer needed
};

HRESULT hr = XblSocialGetSocialRelationshipsAsync(
    xboxLiveContext,
    xboxUserId,
    socialRelationshipFilter,
    0,
    0,
    asyncBlock.get()
);

if (SUCCEEDED(hr))
{
    // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
    // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
    asyncBlock.release();
}
```

<!-- in GDK, not in public:
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblSocialGetSocialRelationshipsAsync](xblsocialgetsocialrelationshipsasync.md)
* [XblSocialGetSocialRelationshipsResult](xblsocialgetsocialrelationshipsresult.md)
* [XblSocialRelationshipResultCloseHandle](xblsocialrelationshipresultclosehandle.md)
-->


## Getting a single relationship

<!-- intro sentence here -->

**C API**
<!--  XblSocialRelationshipResultGetRelationships_C.md -->
```cpp
const XblSocialRelationship* relationships = nullptr;
size_t relationshipsCount = 0;
HRESULT hr = XblSocialRelationshipResultGetRelationships(state.socialResultHandle, &relationships, &relationshipsCount);

LogToFile("Got %u SocialRelationships:", relationshipsCount);
for (size_t i = 0; i < relationshipsCount; ++i)
{
    LogToFile("Xuid = %u, isFollowingCaller = %u", relationships[i].xboxUserId, relationships[i].isFollowingCaller);
}
```

<!-- in GDK, not in public:
**Reference**
* [XblSocialRelationship](xblsocialrelationship.md)
* [XblSocialRelationshipResultGetRelationships](xblsocialrelationshipresultgetrelationships.md)
-->


<!-- ## Getting multiple relationships -->

<!-- intro sentence here -->

<!-- **C API** -->
<!--  _C.md -->
<!--
```cpp
See above. There is no way to retreive just a single relationship.
```
-->

<!-- **Reference** -->


## Getting next page of relationships

<!-- intro sentence here -->

**C API**
<!--  XblSocialRelationshipResultHasNext_C.md -->
<!--  XblSocialRelationshipResultGetNextAsync_C.md -->
```cpp
bool hasNext{ false };
HRESULT hr = XblSocialRelationshipResultHasNext(state.socialResultHandle, &hasNext);

if (hasNext)
{
    auto asyncBlock = std::make_unique<XAsyncBlock>(); 
    asyncBlock->queue = queue;
    asyncBlock->context = nullptr;
    asyncBlock->callback = [](XAsyncBlock* asyncBlock)
    {
        std::unique_ptr<XAsyncBlock> asyncBlockPtr{ asyncBlock }; // Take over ownership of the XAsyncBlock*
        // Close handle to previous page of results
        if (state.socialResultHandle)
        {
            XblSocialRelationshipResultCloseHandle(state.socialResultHandle);
        }
        HRESULT hr = XblSocialRelationshipResultGetNextResult(asyncBlock, &state.socialResultHandle);
    };

    uint32_t maxItems = 100;
    HRESULT hr = XblSocialRelationshipResultGetNextAsync(xboxLiveContext, state.socialResultHandle, maxItems, asyncBlock.get());
    if (SUCCEEDED(hr))
    {
        // The call succeeded, so release the std::unique_ptr ownership of XAsyncBlock* since the callback will take over ownership.
        // If the call fails, the std::unique_ptr will keep ownership and delete the XAsyncBlock*
        asyncBlock.release();
    }
}
```

<!-- in GDK, not in public:
**Reference**
* [XAsyncBlock](xasyncblock.md)
* [XblSocialRelationshipResultCloseHandle](xblsocialrelationshipresultclosehandle.md)
* [XblSocialRelationshipResultGetNextAsync](xblsocialrelationshipresultgetnextasync.md)
* [XblSocialRelationshipResultGetNextResult](xblsocialrelationshipresultgetnextresult.md)
* [XblSocialRelationshipResultHasNext](xblsocialrelationshipresulthasnext.md)
-->
