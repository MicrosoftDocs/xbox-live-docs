---
title: Development tools
author: mikehoffms
description: Tools to help develop and test your Xbox Live-enabled title.
ms.author: v-mihof
ms.date: 06/13/2018
ms.topic: article
ms.prod: windows
ms.technology: uwp
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, tools, player reset, live trace analyzer, LTA, xbox live account tool
ms.localizationpriority: medium
---
# Development tools for Xbox Live

This section covers various tools that you can use to help you develop for Xbox Live. Many of the tools are available on the [Xbox Live Developer Tools GitHub](https://github.com/Microsoft/xbox-live-developer-tools) repo. You can also use the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools) to create your own custom tooling. All standalone developer tools can be downloaded at [https://aka.ms/xboxliveuwptools](https://aka.ms/xboxliveuwptools).

> [!NOTE]
> The MatchSim and XboxLiveCompute tools included in the download can only be used by managed partners, or partners enrolled in the [ID@Xbox](https://www.xbox.com/Developers/id) program. To learn more about the available developer programs, please refer to the [developer program overview](https://docs.microsoft.com/windows/uwp/xbox-live/developer-program-overview). 

## Global Storage
Global title storage is used to store data that everyone can read, such as rosters, maps, challenges, or art resources. It is a type of [Title Storage](../storage-platform/xbox-live-title-storage/xbox-live-title-storage.md). The Global Storage tool is used to manage global title storage in test sandboxes. Data must still be published to RETAIL via Partner Center or Xbox Developer Portal (XDP). The tool is available via command-line as part of the [Development Tools](https://aka.ms/xboxliveuwptools) zip. Custom tools can be created with the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools).

## Multiplayer Session History Viewer
Multiplayer Session History Viewer gives you the ability to view a historical timeline of all changes over a multiplayer session document's history (including deleted documents). Using this tool will give you a deeper understanding of what is happening with your MPSD session documents as it changes over time. It is available as a standalone tool in the [Development Tools](https://aka.ms/xboxliveuwptools) zip.

# Development tools

Tools to help develop and test your Xbox Live-enabled title.


## In this section

| Article | Description |
|---------|-------------|
| [Development tools for Xbox Live](development-tools-for-xbox-live.md) | Tools to help develop and test your Xbox Live-enabled title. |
| [XBL Trace Analyzer](analyze-service-calls.md) | Using the Xbox Live Trace Analyzer to review the service calls made by your title. |
| [XBL Account Tool](xbox-live-account-tool.md) | The Xbox Live Developer Account Tool creates test accounts for testing your Xbox Live-enabled title. |
