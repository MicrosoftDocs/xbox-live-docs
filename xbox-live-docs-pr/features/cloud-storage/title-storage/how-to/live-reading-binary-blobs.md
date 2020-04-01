---
title: Reading a binary blob from Title Storage
description: Reading a binary blob in Title Storage, using GET.
kindex: Reading a binary blob from Title Storage
kindex: title storage
ms.topic: article
ms.assetid: 9b8e0c35-0cea-4491-bf30-22fad224f11b
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Reading a binary blob from Title Storage

1.  Send a request using the *GET* method to read the data from Xbox Live Title Storage. This example uses global title storage.

```http
GET https://titlestorage.xboxlive.com/global/scids/{scid}/data/userinfo.bin,binary
Content-Type: application/octet-stream
x-xbl-contract-version: 1
Authorization: XBL3.0 x=<userHash>;<STSTokenString>
Connection: Keep-Alive
```


- The user must be in the session to update it.

- `<STSTokenString>` is a placeholder for brevity, and should be replaced with the token returned by the authentication request.


### Reference

**/global/scids/{scid}/data/{pathAndFileName},{type}**
