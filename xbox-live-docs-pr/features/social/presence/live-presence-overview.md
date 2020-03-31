---
title: Rich Presence overview
description: Rich Presence shows what activity a user is currently doing, in which area of the game.
kindex: Rich Presence overview
ms.topic: article
ms.localizationpriority: medium
ms.assetid: 00042359-f877-4b26-9067-58834590b1dd
ms.date: 04/04/2017
---






# Rich Presence overview

By default, you get *Basic Presence*, indicating to other users which game a user is currently playing.
If you write code to use *Rich Presence*, the Rich Presence string also indicates what activity a user is doing, in which area of the game.

By using Rich Presence, your game can advertise what specific activity a player is doing right now, in which area of the game.
For example, your game can use Rich Presence strings to show all gamers the status of your game's players, such as *Away*.

Rich Presence information is visible to gamers connected to Xbox Live.
Ideally, a Rich Presence string tells other Xbox Live gamers what a player is doing, and where in your game the player is doing it.

The concept of Rich Presence strings is now the same as it was on Xbox 360, but the newer implementation follows the "Entertainment as a Service" initiative.

The articles in this section describe how to configure your Rich Presence strings and then how to set the string for a user playing your title.


## Definitions

*Enumeration*  
An enumeration is a list of some in-game dimension.
Examples of these in-game dimensions are weapons, character classes, maps, and so on.
You can show a list of the possible weapons in your game, a list of all the possible character classes or maps, and so on.

*Locale-string pair*  
Every possible Rich Presence string must have a locale associated with it to specify in what locales the string can/should be used.
Each enumeration will also have a set of locale-string pairs as well.

*String-set*  
A string set is made up of a group of locale-string pairs.
This set defines the possible values of a Rich Presence string for all possible locales or the possible values for an enumeration for all possible locales.

*Friendly name*  
There are two types of friendly names:
* *Rich Presence string* - The friendly name for a string-set is a unique identifier in the form of a string used to reference a string-set.
* *Enumeration* - These friendly names are used to uniquely identify a particular enumeration like the weapons enumeration or the character class enumeration.
