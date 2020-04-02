---
title: Xbox Live PC Sandbox Switcher (XBLPCSandbox.exe)
description: Command-line tool that helps manage the Xbox Live sandbox on PC.
kindex: Xbox Live PC Sandbox Switcher (XBLPCSandbox.exe)
kindex: sandbox switcher
ms.topic: conceptual
ms.localizationpriority: high
author: mikehoffms
ms.author: v-mihof
ms.date: 03/12/2020
---

# Xbox Live PC Sandbox Switcher (XBLPCSandbox.exe)

Xbox Live PC Sandbox Switcher is a command-line tool that helps manage the Xbox Live sandbox on PC.
This Sandbox Switcher can do the following:

* Show the name of the current sandbox.
* Set a sandbox to use.
* Re-launch the Microsoft Store app, the Xbox app, and the Xbox Companion app in sandbox mode.

This command-line tool is part of `XboxLiveTools.zip`; see [Development tools for Xbox Live](live-tools.md).


### Requirements for running the command

For setting the sandbox, the Sandbox Switcher requires elevated privileges (such as a command prompt that has been started with "Run as administrator").

If the tool is run without elevated privileges, then the tool will attempt to re-run in an elevated state.


### Getting the current sandbox

<pre>
XBLPCSandbox
</pre>

Gets the current Xbox Live sandbox, if any.


### Showing Help info

<pre>
XBLPCSandbox /?
</pre>

Shows the help information, similar to this section.


### Setting the sandbox

<pre>
XBLPCSandbox <i>sandbox</i>
</pre>

Sets the Xbox Live sandbox for the device.
For example: `XBLPCSandbox XDKS.1`

When setting the sandbox, the Sandbox Switcher always restarts the Xbox Live Auth Manager.

If the Microsoft Store app, the Xbox app, and/or the Xbox Companion app is open, setting the sandbox relaunches the open apps in sandbox mode.
If one of these apps is not open, the Sandbox Switcher doesn't open that app.


#### Switching back to RETAIL

To reset the device to normal, set the sandbox to RETAIL.
For example: `XBLPCSandbox RETAIL`

Resetting the sandbox to RETAIL will restart the Xbox Live Auth Manager and relaunch opened system apps (the Microsoft Store app, the Xbox app, and/or the Xbox Companion app) back to normal.
