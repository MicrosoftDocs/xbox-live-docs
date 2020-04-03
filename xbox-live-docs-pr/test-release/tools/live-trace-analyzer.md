---
title: Xbox Live Trace Analyzer (XBLTraceAnalyzer.exe)
description: Reviews the service calls made by a title.
kindex: Xbox Live Trace Analyzer (XBLTraceAnalyzer.exe)
kindex: trace analyzer
kindex: XBLTraceAnalyzer.exe
kindex: service calls, testing
ms.topic: conceptual
ms.localizationpriority: high
ms.assetid: b4490fae-d554-403d-bbbc-601af38af0ef
ms.date: 04/04/2017
---






# Trace Analyzer for reviewing service calls

The Xbox Live Trace Analyzer reviews the service calls made by a title.

The Xbox Live Services API allows you to capture all service calls, so that the Trace Analyzer can analyze the service calls offline.
The *Xbox Live Trace Analyzer* is an offline analysis tool, to find any violations in calling patterns.

Service call tracing can be activated by using functionality available in the **xbtrace** command line tool, or through protocol activation for more advanced scenarios.
Activating service call tracking directly from title code is also supported.

The Trace Analyzer (**XBLTraceAnalyzer.exe**) can be found as part of the Xbox Live Tools package (`XboxLiveTools.zip`) from [https://aka.ms/xboxliveuwptools](https://aka.ms/xboxliveuwptools).

This is a command-line tool.  There is a readme file about this tool in the .zip file.


## Gather logs and analyze the service calls

The following steps are required to gather the logs that contain the record of your service calls and analyze them using Xbox Live Trace Analyzer.

1.  Build your title using the version of the Xbox Live Services API that is included in the July 2015 or newer version of the Xbox Developer Kit (XDK).
2.  Modify your title to enable tracing as described below.
3.  Deploy your title.
4.  Launch the title and make at least one call to Xbox Live Services in order to initialize the Xbox Live Services API.
5.  Start tracing at the point in your title you'd like to analyze.
6.  Stop tracing.
7.  Run the Xbox Live Trace Analyzer tool on your development PC and view the output.


## Starting and stopping tracing



It is possible to use Fiddler to capture the trace file of the target device, then save the Fiddler results as a Fiddler Session file (.saz) which the Xbox Live Trace Analyzer tool can read.
See [Using Fiddler to inspect web service calls](live-fiddler-inspect-web-calls.md).

There are three ways to start and stop tracing:
* Call a set of Xbox Live Services APIs directly from your title.
* Use the **xbtrace** command line tool.
* Use protocol activation through the *Application Management (xbapp.exe)* command line tool.

These approaches are described below.


### Starting and stopping tracing directly from your title

To start tracing directly from your title, you must do the following:

1.  Set the `EnableServiceCallTracking` property of the `ServiceCallTrackerSettings` class to true.
2.  Call `StartServiceCallTracking()` to start tracing service calls.
3.  Call `StopServiceCallTracking()` to stop tracing service calls.
4.  After tracing is stopped, copy the resulting trace file from the developer scratch drive on the console back to your PC by using either *File Copy (xbcp.exe)* or the *Xbox One Neighborhood* in order to analyze it by using Xbox Live Trace Analyzer.


### Starting and stopping tracing by using the xbtrace command line tool

The most convenient and straightforward way to start tracing is to use the **xbtrace** command line tool with the xboxliveservices trace type.
When you use **xbtrace**, the resulting trace file is copied back to your PC for you.

Starting and stopping traces using **xbtrace** relies on protocol activation.
Before using **xbtrace** to start and stop tracing, you must initialize protocol activation by calling the `RegisterForProtcolActivation` method on the `ServiceCallTrackerSettings` class.

The following example shows how to start and stop an Xbox Live Services trace by using **xbtrace**:


```cmd
xbtrace start xboxliveservices
xbtrace stop
```

Before you can start and stop tracing with **xbtrace**, your title must be running, and protocol activation must be initialized.

After tracing is stopped, **xbtrace** copies the trace file to your development PC and places it in a directory whose name includes "xbtrace" and a timestamp.
The name of this directory can be overridden using the \[etlfile\] option to **xbtrace**.


### Starting and stopping tracing by using protocol activation

Tracing can also be controlled by using the protocol activation features of "xbApp launch".

You must know your title's titleid to start and stop tracing via protocol activation.
You can find your title id in your title's manifest file.

Tracing is controlled through URIs that contain "serviceCallTracking" parameter.

The following examples show how to start and stop tracing for a title whose title id is 12345678:

```cmd
xbapp launch "ms-xbl-12345678://serviceCallTracking?state=start"
xbapp launch "ms-xbl-12345678://serviceCallTracking?state=stop"
```


#### Location of trace file

When you use protocol activation, the resulting trace file is stored on the developer scratch drive on the console.

You'll need to copy the file back to your PC using either **xbcp** or the Xbox One Neighborhood.
The file is not automatically copied back to the PC, as it is when using **xbtrace**.


#### Setting verbosity

Protocol activation allows you to set additional trace parameters, such as verbosity.
Four levels of verbosity are supported: quiet, diagnostic, detailed, and minimal.

The following example sets the verbosity level to "diagnostic":

```cmd
xbapp launch "ms-xbl-12345678://serviceCallTracking?verbosity=diagnostic"
```


## Analyze the trace file

To analyze your title's use of Xbox Live Services, after the trace file has been copied back to your PC, you can use the Xbox Live Trace Analyzer tool on GDN.

For a description of how to invoke the tool and interpret its output, see the documentation included with the Xbox Live Trace Analyzer tool on Game Developer Network.

To view command line help, you can also run **XBLTraceAnalyzer.exe** with the command line option of -? or -h.
