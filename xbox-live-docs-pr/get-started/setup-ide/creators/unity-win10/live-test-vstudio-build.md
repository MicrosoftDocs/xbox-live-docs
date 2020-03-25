---
title: Testing a Unity game build in Visual Studio
description: Checklist for testing Unity builds in Visual Studio.
kindex: Testing a Unity game build in Visual Studio
kindex: Unity
kindex: Visual Studio
ms.topic: article
ms.date: 03/12/2018
---

# Testing a Unity game build in Visual Studio

To test the Xbox Live functionality of your Unity game with real data, you must build the game as described in the section [Build and test the project](live-configure-xbl-in-unity.md#build-and-test-the-project) in the article "Configuring Xbox Live in Unity".

The following articles serve as a checklist of items to help ensure successful testing of your Unity game in Visual Studio.

1. **Double-check that you have a properly configured title associated with your Unity game.**

    If you enabled Xbox Live through the Xbox Live Association Wizard, you will want to familiarize yourself with [Partner Center](https://partner.microsoft.com/dashboard).
    Partner Center allows you to configure the Xbox Live settings for your title and must be set up properly in order for your title to communicate with Xbox Live.

    The article [Creating an app and publishing it for testing, for Creators](../../../setup-partner-center/legacy/live-create-and-test-creators-title.md) takes you through the Partner Center setup process.
    
    If you have already set up your game through the **Xbox Configuration Wizard** in Unity, you can skip to the section [Test Xbox Live service configuration in your game](../../../setup-partner-center/legacy/live-create-and-test-creators-title.md#test-xbox-live-service-configuration-in-your-game) in the article "Creating an app and publishing it for testing, for Creators".
    While in Partner Center, make sure to check to see that the information in your Xbox Live configuration for your Unity game matches the Partner Center configuration for your game.
    
2. **Ensure that your title has an authorized Microsoft Account(with gamertag) that can sign-in to your title.**

    Without an authorized account, you will not be able to complete sign-in in while testing your title, nor will you be able to use other Xbox Live features.

    To make sure you have an authorized Microsoft Account and gamertag, read [Authorizing test accounts, for Creators](../../../setup-partner-center/legacy/live-authorize-xbox-live-accounts.md).

3. **Ensure that your title has been published for testing.**

    When you make changes to your title, those changes must be published to your sand box before they can be used.
    Make sure you push the **Test** button to publish your changes to your configuration.

    ![Publish for test image](live-test-vstudio-build-images/creators_udc_xboxlive_config_test.png)

    The **Test** button is found in [Partner Center](https://partner.microsoft.com/dashboard) under your title's Xbox Live service settings.
    If you made any changes to your configuration such as adding a new authorized test account, you will want to push the **Test** button to publish the new configuration settings to the Xbox Live service.

4. **Check to make sure that your PC is in developer mode and you are using the appropriate Xbox Live Sandbox.**

    When your title is published for testing, it is published to a specific environment called a *sandbox*.
    If your development PC is not set to use that sandbox, you will not be able to test Xbox Live features.

    Learn to check and change your PC's sandbox with the [Using Xbox Live sandboxes, for Creators](../../../../test-release/sandboxes/live-sandboxes-creators.md).

5. **Make sure that you build your project as an x64 build targeting the local machine to build on your PC.**

    ![build settings](live-test-vstudio-build-images/vsBuildSettings.JPG)
