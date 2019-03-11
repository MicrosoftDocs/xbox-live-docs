---
title: Using Xbox Live tokens for custom web service authentication
author: aablackm
description: An introduction to XAL and how to integrate it into your Xbox Live project
ms.author: aablackm
ms.date: 08/30/2018
ms.topic: article
ms.prod: windows
ms.technology: xbox live=
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, authentication, sign-in
ms.localizationpriority: medium
---

# Using Xbox Live tokens for custom web service authentication

Xbox Live tokens can be used by custom, title-specific web services for authentication and authorization.

Custom web services allow you to use user, title, and device claims that are contained in the Xbox Live token.


## Retrieve an Xbox Live partner token for your own service

To retrieve the Xbox Live partner token for your own service, an endpoint configuration that uses an Xbox Live token is required.

The game then requests the Xbox Live partner token for this endpoint by calling `XalUserGetTokenAndSignatureSilentlyAsync()` using the following flow:

1. Create a `XalUserGetTokenAndSignatureArgs` object:

```c
XalUserGetTokenAndSignatureArgs tokenAndSigArgs = {};
    tokenAndSigArgs.method = "GET";
    tokenAndSigArgs.url = "https://service.yourcompany.com/yourpath"
    tokenAndSigArgs.headerCount = static_cast<uint32_t>(headers.size());
    tokenAndSigArgs.headers = headers.data();
    tokenAndSigArgs.bodySize = static_cast<uint32_t>(data->Body.size());
    tokenAndSigArgs.body = data->Body.data();
    tokenAndSigArgs.forceRefresh = forceRefresh;
    tokenAndSigArgs.allUsers = false;
```

> [!IMPORTANT]
> Only set forceRefresh to true if you previously requested a token and it was rejected from your service.

2. Call `XalUserGetTokenAndSignatureSilentlyAsync` to get the partner token:

```c
HRESULT XalUserGetTokenAndSignatureSilentlyAsync(
    _In_ XalUserHandle user,
    _In_ XalUserGetTokenAndSignatureArgs const* args,
    _In_ XAsyncBlock* async
)
```

Read the following articles to learn how to work with XAL in the general case and for any of its supported platforms.

[XAL Sign-In](xal-sign-in.md)  
[Get Started with XAL on iOS](iOS-xal.md)  
[Get Started with XAL on Android](android-xal.md)
