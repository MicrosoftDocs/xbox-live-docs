---
title: Retrieving the Windows user in a UWP title
description: Retrieving the Windows System User in a Universal Windows Platform (UWP) game.
kindex: Retrieving the Windows user in a UWP title
kindex: system user
ms.topic: article
ms.localizationpriority: medium
ms.date: 06/07/2017
---

# Retrieving the Windows user in a UWP title

You can retrieve the Windows System User in a Universal Windows Platform (UWP) title, as follows.


## Windows.System.User

A [Windows.System.User](https://docs.microsoft.com/uwp/api/windows.system.user) object represents a local Windows user.

On Xbox console, this object allows multiple windows user to be logged in at the same time in a single interactive session.

If your app is a multi-user application, then a `Windows.System.User` object would be required to construct an `XboxLiveUser`, in order to access live services.

On other Windows platforms, such as PC or phone, where it only allow one Windows user on one device or in one interactive session, passing in a `Windows.System.User` to construct an `XboxLiveUser` is not required.


## Ways to retrieve a Windows System User


### Windows.System.User class static method FindAllAsync

To retrieve a Windows System User, one approach is to use static methods from the [Windows.System.User](https://docs.microsoft.com/uwp/api/windows.system.user) class.

That class provides static methods to retrieve `Windows.System.User` objects.
For example, you can call `FindAllAsync` to get all active windows users.


### Windows.System.UserPicker

The class [Windows.System.UserPicker](https://docs.microsoft.com/uwp/api/windows.system.userpicker) provides methods to launch the user picker UI and select a Windows system user in multi-user scenarios.


### Windows.Gaming.Input.IGameController

The interface [Windows.Gaming.Input.IGameController](https://docs.microsoft.com/uwp/api/windows.gaming.input.igamecontroller) is the core interface for all controller devices, such as gamepad, racing wheel, and flight stick.
You can get the `Windows.System.User` object that is associated with the game controller, by calling its `User` property.

Here are some game controllers implemented by Windows:
* [ArcadeStick](https://docs.microsoft.com/uwp/api/windows.gaming.input.arcadestick)
* [FlightStick](https://docs.microsoft.com/uwp/api/windows.gaming.input.flightstick)
* [Gamepad](https://docs.microsoft.com/uwp/api/windows.gaming.input.gamepad)
* [RacingWheel](https://docs.microsoft.com/uwp/api/windows.gaming.input.racingwheel)


### UserDeviceAssociation class static method FindUserFromDeviceId

To retrieve a Windows System User, first, obtain the device ID from Windows input events, such as:
* [Windows.​UI.​Xaml.​Input.KeyRoutedEventArgs](https://docs.microsoft.com/uwp/api/Windows.UI.Xaml.Input.KeyRoutedEventArgs)
* [Windows.​UI.​Core.KeyEventArgs](https://docs.microsoft.com/uwp/api/windows.ui.core.keyeventargs)

Then, to find the user associated with the device ID, you can call the static method
[FindUserFromDeviceId](https://docs.microsoft.com/uwp/api/windows.system.userdeviceassociation.finduserfromdeviceid)
in the class
[UserDeviceAssociation](https://docs.microsoft.com/uwp/api/windows.system.userdeviceassociation).
