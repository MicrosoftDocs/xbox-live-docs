---
title: Player Data Reset tool (PlayerReset.exe)
description: Resets a player's data in test sandboxes.
kindex: Player Data Reset tool (PlayerReset.exe)
kindex: reset tool
author: mikehoffms
ms.author: v-mihof
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.localizationpriority: medium
ms.date: 03/12/2018
edited: 00/00/0000
---

# Player Data Reset tool (PlayerReset.exe)


The Player Data Reset tool can be used to reset a player's data in test sandboxes.
You can reset data such as; achievements, leaderboards, stats and title history.

This command-line tool is part of `XboxLiveTools.zip`; see [Development tools for Xbox Live](live-tools.md).

Custom tools can be created with the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools).

PlayerReset is used to reset a player's data in test sandboxes.
Data includes achievements, leaderboards, stats and title history.
XblDevAccount.exe signin is required to be called at least once before first use.


## Usage:

```
PlayerReset.exe –scid xxx --sandbox xxx --xuid xxxx
```


***Success output example:***

```
Player {email} data reset has completed successfully.
```


***Error output example:***

```
Player {email} data reset has completed with errors:
    Leaderboard reset contains error: {errorMessage}
```
