---
title: Writing an event to power an event-based Achievement
description: Example code for writing an event to power an event-based Achievement.
kindex: Writing an event to power an event-based Achievement
kindex: Xbox Live, Achievements
author: XBL
ms.author: player-data
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.date: 11/22/2019
edited: 00/00/0000
---

# Writing an event to power an event-based achievement

This example code shows how to write an event.
On the service, this will update event based-stats based on the stat rules you've defined in Partner Center.
Those stats, in turn, will power event-based achievements.


**C API**
<!-- XblEventsWriteInGameEvent.md -->
```cpp
HRESULT hr = XblEventsWriteInGameEvent(
    xboxLiveContext,
    "PuzzleSolved",
    R"({"DifficultyLevelId":100, "GameplayModeId":"Adventure"})",
    R"({"LocationX":1,"LocationY":1})"
);
```

<!-- **Reference**
* [XblEventsWriteInGameEvent](xbleventswriteingameevent.md) -->
