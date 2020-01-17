---
title: Development tools for Xbox Live
author: StaceyHaffner
description: Tools to help develop and test an Xbox Live-enabled title.
ms.assetid: 380a29bf-41a7-4817-9c57-f48f2b824b52
ms.author: kevinasg
ms.date: 06/13/2018
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, tools, player reset, live trace analyzer, LTA, xbox live account tool
ms.localizationpriority: medium
---

# Development tools for Xbox Live

This section covers various tools that you can use to help you develop for Xbox Live.

These tools can be downloaded as part of the [Development Tools](https://aka.ms/xboxliveuwptools) zip.
Many of the tools are available on the [Xbox Live Developer Tools GitHub](https://github.com/Microsoft/xbox-live-developer-tools) repo.

To create your own custom tooling, you can use the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools).

> [!NOTE]
> The MatchSim and XboxLiveCompute tools included in the download can only be used by Managed Partners, not by Creators Program developers.


## Global Storage

Global title storage is used to store data that everyone can read, such as rosters, maps, challenges, or art resources.
Global title storage is a type of [Title Storage](../features/cloud-storage/title-storage/live-title-storage-overview.md).

The Global Storage tool is used to manage global title storage in test sandboxes.
Data must still be published to RETAIL via Partner Center.

The tool is available via command-line as part of the [Development Tools](https://aka.ms/xboxliveuwptools) zip.

Custom tools can be created with the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools).


## Multiplayer Session History Viewer

Multiplayer Session History Viewer gives you the ability to view a historical timeline of all changes over a multiplayer session document's history (including deleted documents).
Using this tool will give you a deeper understanding of what is happening with your MPSD session documents as it changes over time.

The tool is available as a standalone tool in the [Development Tools](https://aka.ms/xboxliveuwptools) zip.


## Player Data Reset

The Player Data Reset tool can be used to reset a player's data in test sandboxes.
You can reset data such as; achievements, leaderboards, stats and title history.

The tool is available via command-line as part of the [Development Tools](https://aka.ms/xboxliveuwptools) zip.

Custom tools can be created with the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools).


## Xbox Live Developer Account

The Xbox Live Developer Account tool is used to manage authentication of a developer account.
The Xbox Live Developer Account tool is needed to interact with other developer tools that require a developer credential, such as Player Reset and Global Storage.

The tool is available via command-line as part of the [Development Tools](https://aka.ms/xboxliveuwptools) zip.

For more information, see [XBL Developer Account Tool](xbox-live-account-tool.md).


## Xbox Live Trace Analyzer

Using [Xbox Live Trace Analyzer](analyze-service-calls.md), you can capture all service calls and then analyze them offline for any violations in calling patterns.
Service call tracing can be activated by using the **xbtrace** command line tool, or through protocol activation for more advanced scenarios.
Activating service call tracking directly from title code is also supported.

The tool is available via command-line as part of the [Development Tools](https://aka.ms/xboxliveuwptools) zip.

For more information, see [Xbox Live Trace Analyzer](analyze-service-calls.md).


## Xbox Live Account Tool  

The [Xbox Live Account Tool](xbox-live-account-tool.md) is designed to help you set up existing test accounts for testing game scenarios.
For example, you can use Xbox Live Account Tool to change an account's gamertag, or quickly add 1000 followers to an account's friends list.

The tool is available via command-line as part of the [Development Tools](https://aka.ms/xboxliveuwptools) zip.


## Config as Source

[Config as Source](https://github.com/Microsoft/xbox-live-developer-tools/blob/master/CONFIGASSOURCE.md) is a suite of tools that Microsoft developed to accommodate advanced users, by providing officially supported tools and APIs for integrating into our configuration services.
These Xbox Live services are normally configured for your title in Partner Center, including services ranging from leaderboards to achievements, to web services and relying parties.

For many game developers, using Partner Center is sufficient.
For advanced users, however, there is a desire to integrate common configuration tasks into their own processes and tools.
Config as Source is intended to support these scenarios by providing command line tools and new APIs to support custom integration into your existing workflows and pipelines.

The tool is available via command-line as part of the [Development Tools](https://aka.ms/xboxliveuwptools) zip.
