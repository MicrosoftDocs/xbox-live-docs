---
title: What's new for the Xbox Live SDK - October 2015
description: What's new for the Xbox Live SDK - October 2015
kindex: What's new for the Xbox Live SDK - October 2015
ms.topic: article
ms.assetid: 052be4aa-5f18-4eb7-ba5f-80c5f5cab6f2
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# What's new for the Xbox Live SDK - October 2015


## OS and tool support

The Xbox Live SDK supports Windows 10 RTM [Version 10.0.10240] and Visual Studio 2015 RTM [Version 14.0.23107.0].


## Social Manager

* The Social Manager is intended to ease the use of the Xbox Live social APIs.  It will intelligently cache a user's social graph, provide a simpler API and more.  Please see the documentation for more information.


## Samples

* We have a new Social Manager sample demonstrating the API.


## Tools

* The Xbox Live Trace Analyzer is now included in the Xbox Live SDK.  Collect traces as described in [Xbox Live Trace Analyzer (XBLTraceAnalyzer.exe)](../../../test-release/tools/live-trace-analyzer.md), and then run the Live Trace Analyzer to ensure your title is using Xbox Live in an optimal way by viewing statistics about repeated calls, call frequency, and more.


## Bug Fixes

* Changed default timeout for HTTP socket operations to 30 seconds from 5 minutes.  For long running HTTP socket operations such as Title Storage upload and download calls, those remain using a 5 minute timeout.


## Documentation

* Introduction to the Social Manager added
* Introduction to the Multiplayer Manager updated
