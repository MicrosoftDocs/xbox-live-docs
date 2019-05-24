---
title: Configuring an Xbox development console
description: Configuring your Xbox development console to support Xbox Live development.
ms.assetid: f8fd1caa-b1e9-4882-a01f-8f17820dfb55
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one
ms.localizationpriority: medium
---

# Configuring an Xbox development console

To configure your development console:
1. Get your Partner Center IDs.
2. Activate the console as a dev kit.
3. Set your sandbox on your development kit.
4. Sign in with a development account.
 
These steps are detailed below.


## Get your Partner Center IDs

To enable sandboxes and Xbox Live services, you will need to obtain several IDs to configure your development kit and your title.
See the section "Get your IDs" in [Xbox Live service configuration](../../../../xbox-live-service-configuration.md#get_ids).


## Activate the console as a dev kit

Activate Dev Mode on the retail Xbox One console.
To do this, download the Dev Mode Activation app from the Xbox One store.
See <a href="https://docs.microsoft.com/en-us/windows/uwp/xbox-apps/devkit-activation" target="_blank">Xbox One Developer Mode activation &#11008;</a>.


## Set your sandbox on your development kit

To boot your development kit, you must set your Sandbox ID.
To do this, you can use the "Xbox One Manager" that's installed on your PC by the XDK, or you can open an XDK command window and use the Configuration (xbconfig.exe) command, as follows:

1. Check your current sandbox.
   To do this, type `xbconfig sandboxid` at the command prompt.

2. If the ID is not what you expect, change your sandbox ID.
   To do this, type the following at the command prompt:

   `xbconfig sandboxid=<your sandbox id>`

3. Reboot your console using Reboot (xbreboot.exe) at the command prompt.

4. Verify that your sandbox has been correctly reset.
   To do this, type `xbconfig sandboxid` at the command prompt.


## Sign in with a development account

You can create development accounts used to sign-in on [Partner Center](https://partner.microsoft.com/dashboard).
