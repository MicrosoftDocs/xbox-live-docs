---
title: Writing an event to power an event-based Stat
description: Example code for writing an event to power an event-based Stat.
kindex: Writing an event to power an event-based Stat
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.localizationpriority: medium
ms.date: 11/22/2019
edited: 00/00/0000
---

# Writing an event to power an event-based Stat

This example code shows how to write an event.
On the service, this will update event-based stats based on the stat rules you've defined in Partner Center.


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
