---
title: What's new for the Xbox Live SDK - February 2016
description: What's new for the Xbox Live SDK - February 2016
kindex: What's new for the Xbox Live SDK - February 2016
ms.topic: article
ms.assetid: 7ff34ea4-f07d-4584-98e4-13977994ccca
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# What's new for the Xbox Live SDK - February 2016


## OS and tool support

The Xbox Live SDK supports Windows 10 RTM [Version 10.0.10240] and Visual Studio 2015 RTM [Version 14.0.23107.0].


## Throttling

- Fine-grained throttling will soon be rolled out to most Xbox Live Services.  Xbox Service API (XSAPI) will automatically handle retries and inform you of calls that are throttled during development.  See [Best practices for calling Xbox Live](../../../test-release/services-tools/best-practices/live-best-practices-calling-xbl.md).


## Leaderboards

- Multicolumn leaderboards can now be accessed by the GetLeaderboard API. If you provide a vector of the names of the additional columns, the vector of columns on the result will be filled out if those columns exist.


## Documentation

- [Application Insights](https://developer.microsoft.com/games/xbox/docs/xboxlive/xbox-live-partners/event-driven-data-platform/application-insights) documentation is here.  You can use Application Insights with a free Azure account to view Player Data events in near-realtime.  This functionality is currently only available for UWP applications running on Windows 10 on the desktop.
- Updated documentation on the Xbox Common Events Tool for UWP developers discussing how to generate wrappers for sending Player Data events.  Please note that this is optional and you can continue to use the WriteInGameEvent API if you prefer.
- Using Fiddler to debug Player Data events and make sure they are properly being sent.  This is only for UWP events.
- Information on how to collect logs for the Live Trace Analyzer tool is available.  See [Trace Analyzer for reviewing service calls](../../../test-release/services-tools/live-trace-analyzer.md).
