---
title: Reading a configuration blob from Title Storage
description: Reading a JSON configuration blob in Title Storage, using GET.
kindex: Reading a configuration blob from Title Storage
ms.topic: article
ms.assetid: ee62d221-69b9-4f52-9b5d-5a44d04de548
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Reading a configuration blob from Title Storage

*Configuration blobs* are files in Xbox Live Title Storage that hold game data.
The data are JSON objects that include virtual nodes that can be filtered before being delivered to the game.

For more information about configuration blobs, see **Title Storage URIs**.


### To read a configuration blob

1.  Send a request using the below method to read the data from title storage.

```http
GET https://titlestorage.xboxlive.com/global/scids/{scid}/data/config.json,config              
Content-Type: application/octet-stream
x-xbl-contract-version: 1
Authorization: XBL3.0 x=<userHash>;<STSTokenString>
Connection: Keep-Alive
```

-   The user must be in the session to update it.
-   STSTokenString is a placeholder for brevity and should be replaced with the token returned by the authentication request.


### Reference

**/global/scids/{scid}/data/{pathAndFileName},{type}**

**GET (/global/scids/{scid}/data/{pathAndFileName},{type})**
