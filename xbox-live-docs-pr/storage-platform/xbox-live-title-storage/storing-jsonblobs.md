---
title: Storing a JSON blob in Title Storage
description: Storing a JSON blob in Title Storage, using PUT.
ms.assetid: f424aca1-e671-4e31-84c6-098fda4a9558
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, title storage
ms.localizationpriority: medium
---

# Storing a JSON blob in Title Storage

1.  Send a request using the *PUT* method to send the data to Xbox Live Title Storage.


```http
PUT https://titlestorage.xboxlive.com/json/users/xuid(1245111)/scids/{scid}/data/{pathAndFileName},json
Content-Type: application/octet-stream
x-xbl-contract-version: 1
Authorization: XBL3.0 x=<userHash>;<STSTokenString>
Content-Length: 240
Connection: Keep-Alive
```

-   The user must be in the session to update it.

-   STSTokenString is a placeholder for brevity and should be replaced with the token returned by the authentication request.

2.  Send a JSON object.

```json
{
        "startlevel":"1",
        "expression":"smile"
}
```

#### Reference

**/json/users/xuid({xuid})/scids/{scid}/data/{pathAndFileName},json)**
