---
title: Development tools for Xbox Live
description: Tools to help develop and test an Xbox Live-enabled title.
author: StaceyHaffner
ms.author: kevinasg
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, tools, player reset, live trace analyzer, LTA, xbox live account tool
ms.localizationpriority: medium
ms.assetid: 380a29bf-41a7-4817-9c57-f48f2b824b52
ms.date: 06/13/2018
---

# Development tools for Xbox Live

Various tools in `XboxLiveTools-#.zip` can help you develop for Xbox Live.

To get these Xbox Live development tools, you can download `XboxLiveTools-#.zip` using this [aka.ms link](https://aka.ms/xboxliveuwptools).

> [!NOTE]
> `XboxLiveTools-#.zip` includes the MatchSim and XboxLiveCompute tools, but those tools can only be used by Managed Partners, not by Creators Program developers.

Many of these tools are also available in the [Xbox Live Developer Tools GitHub](https://github.com/Microsoft/xbox-live-developer-tools) repo.

To create your own custom tooling, you can use the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools).


## Global Storage

Global title storage is used to store data that everyone can read, such as rosters, maps, challenges, or art resources.
Global title storage is a type of [Title Storage](../../features/cloud-storage/title-storage/live-title-storage-nav.md).

The Global Storage tool is used to manage global title storage in test sandboxes.
Data must still be published to RETAIL via Partner Center.

This command-line tool is part of `XboxLiveTools-#.zip`; see the top of this article.

Custom tools can be created with the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools).


<a id="xpssc"></a>

## Xbox Live PC Sandbox Switcher (XBLPCSandbox.exe)

Xbox Live PC Sandbox Switcher is a command-line tool that helps manage the Xbox Live sandbox on PC.
This Sandbox Switcher can do the following:

* Show the name of the current sandbox.
* Set a sandbox to use.
* Re-launch the Microsoft Store app, the Xbox app, and the Xbox Companion app in sandbox mode.

This command-line tool is part of `XboxLiveTools-#.zip`; see the top of this article.


### Requirements for running the command

For setting the sandbox, the Sandbox Switcher requires elevated privileges (such as a command prompt that has been started with "Run as administrator").

If the tool is run without elevated privileges, then the tool will attempt to re-run in an elevated state.


### Command options


#### Getting the current sandbox

<pre>
XBLPCSandbox
</pre>

Gets the current Xbox Live sandbox, if any.


#### Showing Help info

<pre>
XBLPCSandbox /?
</pre>

Shows the help information, similar to this section.


#### Setting the sandbox

<pre>
XBLPCSandbox <i>sandbox</i>
</pre>

Sets the Xbox Live sandbox for the device.
For example: `XBLPCSandbox XDKS.1`

When setting the sandbox, the Sandbox Switcher always restarts the Xbox Live Auth Manager.

If the Microsoft Store app, the Xbox app, and/or the Xbox Companion app is open, setting the sandbox re-launches the open apps in sandbox mode.
If one of these apps is not open, the Sandbox Switcher doesn't open that app.


##### Switching back to RETAIL

To reset the device to normal, set the sandbox to RETAIL.
For example: `XBLPCSandbox RETAIL`

Setting the sandbox to RETAIL resets the opened apps to normal, including Xbox Live Auth Manager, the Microsoft Store app, the Xbox app, and the Xbox Companion app.


## Multiplayer Session History Viewer

Multiplayer Session History Viewer gives you the ability to view a historical timeline of all changes over a multiplayer session document's history (including deleted documents).
Using this tool will give you a deeper understanding of what is happening with your MPSD session documents as it changes over time.

This standalone tool is part of `XboxLiveTools-#.zip`; see the top of this article.


## Player Data Reset

The Player Data Reset tool can be used to reset a player's data in test sandboxes.
You can reset data such as; achievements, leaderboards, stats and title history.

This command-line tool is part of `XboxLiveTools-#.zip`; see the top of this article.

Custom tools can be created with the [Dev Tools library](https://www.nuget.org/packages/Microsoft.Xbox.Services.DevTools).


## Xbox Live Developer Account

The Xbox Live Developer Account tool is used to manage authentication of a developer account.
This tool is needed to interact with other developer tools that require a developer credential, such as Player Reset and Global Storage.

This command-line tool is part of `XboxLiveTools-#.zip`; see the top of this article.

For more information, see [Developer Account Tool to set up test accounts](../test-accounts/live-account-tool.md).


## Xbox Live Trace Analyzer

Using the Xbox Live Trace Analyzer, you can capture all service calls and then analyze them offline for any violations in calling patterns.
Service call tracing can be activated by using the **xbtrace** command line tool, or through protocol activation for more advanced scenarios.
Activating service call tracking directly from title code is also supported.

This command-line tool is part of `XboxLiveTools-#.zip`; see the top of this article.

See [Trace Analyzer for reviewing service calls](live-trace-analyzer.md).


## Xbox Live Account Tool  

The [Developer Account Tool to set up test accounts](../test-accounts/live-account-tool.md) is designed to help you set up existing test accounts for testing game scenarios.
For example, you can use Xbox Live Account Tool to change an account's gamertag, or quickly add 1000 followers to an account's friends list.

This command-line tool is part of `XboxLiveTools-#.zip`; see the top of this article.


## Config as Source

[Config as Source](https://github.com/Microsoft/xbox-live-developer-tools/blob/master/CONFIGASSOURCE.md) is a suite of tools that Microsoft developed to accommodate advanced users, by providing officially supported tools and APIs for integrating into our configuration services.
These Xbox Live services are normally configured for your title in Partner Center, including services ranging from leaderboards to achievements, to web services and relying parties.

For many game developers, using Partner Center is sufficient.
For advanced users, however, there is a desire to integrate common configuration tasks into their own processes and tools.
Config as Source is intended to support these scenarios by providing command line tools and new APIs to support custom integration into your existing workflows and pipelines.

This command-line tool is part of `XboxLiveTools-#.zip`; see the top of this article.
