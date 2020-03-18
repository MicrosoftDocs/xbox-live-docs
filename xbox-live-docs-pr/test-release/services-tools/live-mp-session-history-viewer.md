---
title: Multiplayer Session History Viewer (MultiplayerSessionHistoryViewer.exe)
description: Shows a historical timeline of all changes over a multiplayer session document's history.
kindex: Multiplayer Session History Viewer (MultiplayerSessionHistoryViewer.exe)
kindex: session history
kindex: history viewer
author: mikehoffms
ms.author: v-mihof
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.localizationpriority: medium
ms.date: 03/18/2020
edited: 00/00/0000
---

# Multiplayer Session History Viewer (MultiplayerSessionHistoryViewer.exe)

Multiplayer Session History Viewer enables you to view a historical timeline of all changes over a multiplayer session document's history (including deleted documents).
Using this tool gives a deeper understanding of what is happening with an MPSD session document as it changes over time.

This standalone tool is part of `XboxLiveTools.zip`; see [Development tools for Xbox Live](live-tools.md).

<!-- .chm: -->
<!-- ![MPSD Session History Viewer](../../../../../resources/gdk/secure/images/en-us/live/test-release/services-tools/live-mp-session-history-viewer-images/live-session-history-viewer.png) -->
<!-- dmc: -->
![MPSD Session History Viewer](live-mp-session-history-viewer-images/live-session-history-viewer.png)


### Duration of results

The tool will only show sessions for a few days.


## Access Control

Someone on the developer team with Partner Center access needs to go to their Partner Center page for their company, and then select **Access Management*, and then select the appropriate group.
A real user must be added to this group that developer accounts can be created and added to.

Those developer accounts that are handed out to people who need access via the tool.
An Administrator can create their own developer account to test out tool access.


## Viewing changes to the session document

The tool won't ask for any access credentials until a valid query is made.
You must then specify a sandbox, SCID, template name, and "query key" (either a session name, gamertag, xuid, or request correlationId) along with a search date range. Then click the **Query** button.

1. If this is the first query for that sandbox, an access control flow dialog box appears, requesting your email and password (see "Access Control" above).  

2. If the credentials are valid, the query runs, and any MPSD sessions that match the query criteria are displayed in the top listview control, along with metadata.

3. If multiple sessions are found, selecting any one of them in that top section will pull down all changes ever made to that session, along with metadata for each change.

4. Selecting a single change will download and show the complete MPSD document state for that change.

If you multi-select 2 different changes, a colored diff view will appear highlighting differences between the 2 version of the session.
* Blue means "something changed".
* Yellow means "something was added".
* Red means "something was removed".

To keep the line numbers matched up on each side for easier comparison, enable lock-scrolling.
