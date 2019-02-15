---
title: Signing-in to Xbox Live
description: Signing-in to Xbox Live through your game.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Signing-in to Xbox Live

Prerequisite: [Set up code for targeted devices](setup-targets.md).


## Add core XSAPI integration (Async, XAL, XSAPI)



## Add basic sign-in integration





<!-- 
Notes while James recorded video:

Have your game sign-in to Xbox Live, as follows.

This page is for ID@Xbox partners.

need modules (.ar's): com.microsoft.xboxlive.aar/
....
...java.aar

Those are native calls that have to be called from the XSAPI client.  In 1902, not 1810, they are automatically included in the library within the lirbaray native calls.  Include those modules if not done auto'ly.

Incorp your XSAPI integrration files for your specific target devices.

set up your envir; initialize the java envir for this device.

Game_Integration_ini.cpp -- ...InitializeNativeEnv()

core integration: 
4 fooIntegrration .cpp  files add into your proejct, or at least a way of calling eg XAL integration for XAL iniit. Requires a specific order. 
Set up plat args for a specific java machine.  X

In init, set all this up for native XSAPI calls.

Integrate best practices shown here (XAL_Integration.cpp) into your code.  

Once you have all of that in, the only signin code you might have to include is links to any gameplay you wnat to do after signin or before signout.  in XAL_Gameplay.cpp.  That file also has ShowWebView(), to get from C++ to native java, to enact signin.

Sample shows how to welcome the user that has signed-in. 
-->

## Testing sign-in



## Next steps

Add Xbox Live features.
Feature areas include player identity, social features, player data, cloud storage, multiplayer features, and external services.
