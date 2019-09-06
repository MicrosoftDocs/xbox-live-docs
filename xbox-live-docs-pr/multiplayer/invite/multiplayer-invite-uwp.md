---
title: Multiplayer Invite for UWP Games
description: Multiplayer Invite for UWP Games
ms.assetid: 72f179e7-4705-4161-9b8a-4d6a1a05b8f7
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, protocol activation, multiplayer
ms.localizationpriority: medium
---

# Configuring an AppXManifest for Multiplayer

You need to make some updates to the `Package.appxmanifest` file in your Visual Studio project if the following conditions are true:
- You are developing a UWP
- You want to implement the ability for players to invite other users to your title

If you don't do this step, then your title will not get protocol activated when a recipient player accepts an invitation to play.


## Open your Package.appxmanifest

Your `Package.appxmanifest` file is typically located in the same directory as your Visual Studio project's solution file.
Or you can find the `Package.appxmanifest` file in the Solution Explorer.

![Package.appxmanifest in Solution Explorer and File Explorer screenshot](../../images/multiplayer/multiplayer_open_appxmanifest.png)


## Add new entry

You will need to add the following to the ```<Extensions>``` element under ```<Applications>``` in your Package.appxmanifest file:

```xml
<Extensions>
  <uap:Extension Category="windows.protocol">
    <uap:Protocol Name="ms-xbl-multiplayer" />
  </uap:Extension>
</Extensions>
```

For example:

![Highlighted changes to Package.appxmanifest mark up](../../images/multiplayer/multiplayer_appxmanifest_changes.png)

Save and rebuild your title.
To learn how to use the Multiplayer Manager to implement the ability to invite players to your title, see [Play Multiplayer With Friends](../multiplayer-manager/play-multiplayer-with-friends.md).
