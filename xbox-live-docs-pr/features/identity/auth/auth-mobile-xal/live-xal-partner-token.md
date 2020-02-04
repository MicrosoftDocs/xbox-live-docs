---
title: Using Xbox Live tokens for custom web service authentication
description: An introduction to XAL and how to integrate it into your Xbox Live project.
kindex: Using Xbox Live tokens for custom web service authentication
kindex: tokens, for custom web service authentication
kindex: sign-in, for custom web service authentication
author: aablackm
ms.author: aablackm
ms.topic: article
ms.localizationpriority: medium
ms.date: 08/30/2018
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
) noexcept;
```

3. In your callback passed via your `XAsyncBlock`, call `XalUserGetTokenAndSignatureSilentlyResultSize()`, and `XalUserGetTokenAndSignatureSilentlyResult()` to retrieve the result.

```cpp
[](XAsyncBlock* asyncBlock)
{
    size_t bufferSize = 0;
    HRESULT result = XalUserGetTokenAndSignatureSilentlyResultSize(asyncBlock, &bufferSize);
    if (result == E_XAL_NOTOKENREQUIRED)
    {
        // no token is required for this call
        return;
    }
    else if (result == E_XAL_UIREQUIRED)
    {
        // handle UI error
        return;
    }
    else if (FAILED(result))
    {
        // handle error
        return;
    }

    uint8_t* buffer = new uint8_t[bufferSize];
    XalUserGetTokenAndSignatureData* tokenAndSig = nullptr;

    result = XalUserGetTokenAndSignatureSilentlyResult(asyncBlock, bufferSize, buffer, &tokenAndSig, nullptr);
    if (FAILED(result))
    {
        // handle error
    }
    else
    {
        char const* token = tokenAndSig->token;
        char const* signature = nullptr;
        if (tokenAndSig->signatureSize > 0)
        {
            // a signature is needed for this call
            signature = tokenAndSig->signature;
        }

        // use the received token and signature
    }

    delete [] buffer;
};
```

## Handle failures when retrieving a token

The method `XalUserGetTokenAndSignatureSilentlyAsync()` promises to never show UI.
This means that if a requested token could not be retrieved because UI was needed, for example to resolve some state on the user's account, an HRESULT with a value of `E_XAL_UIREQUIRED` will be returned.
Usually if this error is returned, the issue can be resolved by allowing XAL to show UI.

If a token request fails indicating that UI is required, the issue can be resolved by calling `XalUserResolveIssueWithUiAsync()`.
Whatever URL was passed to `XalUserGetTokenAndSignatureSilentlyAsync()` when the call failed must be reused when calling `XalUserResolveIssueWithUiAsync()`.

```c
HRESULT XalUserResolveIssueWithUiAsync(
    _In_ XalUserHandle user,
    _In_opt_z_ char const* url,
    _In_ XAsyncBlock* async
) noexcept;
```

Once `XalUserResolveIssueWithUiAsync()` completes, you must retry your call to `XalUserResolveIssueWithUiAsync()` to retrieve your token.

To learn how to work with XAL in the general case and for any of its supported platforms, see the following articles:
* [Signing-in using XAL](live-xal-sign-in.md)  
* [Getting started with Xbox Live SDK for iOS](../../../../get-started/setup-ide/managed-partners/xcode-ios/other/ios-get-started-with-xsapi.md)  
* [Getting started with the Xbox Live APIs on Android](../../../../get-started/setup-ide/managed-partners/as-android/other/android-get-started-with-xsapi.md)
