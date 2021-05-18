---
title: Activities
description: Advertise joinable multiplayer experiences to other users and allow them to join.
kindex: Activities
kindex: MPA
kindex: activity
ms.topic: conceptual
ms.localizationpriority: high
security: public
author: jeffng
ms.author: jeffng
ms.date: 05/12/2020
edited: 00/00/0000
---

# Activities

## Using activities

When a player starts or joins a multiplayer experience, a title should advertise
this in Multiplayer Activity (MPA) by creating an activity. Unlike a
session-based model, activities are per-player. Each player should create their
own activity, even if they are playing together.

A title should create this activity as soon as a player is in a multiplayer
experience. During the experience it should modify the activity if the player
count increases or decreases, and it should delete the activity if the player
ends or leaves the multiplayer experience. Should a title crash or otherwise
fail to remove an activity, MPA will attempt to remove the activity if it
detects the player has stopped playing the title. Activities are automatically
removed after 24 hours without an update.

## Activity contents
Activities contain the following information:

Field | Purpose | Notes
------|---------|--------------
`xuid` | The XboxUserId of the user who created the activity. | Used when querying activities only. Users can only set activity for themselves.
`connectionString` | Title-defined string which is opaque to MPA. Contains information a title can use to connect to another player. | Must be less than 256 characters.
`joinRestriction` | Represents who may see the connection string in this activity. See Privacy, below, for more details. | Must be `Public`, `Followed`, `InviteOnly`.
`maxPlayers` | Maximum allowed players in this activity. | Optional. If specified, must be > 1 and <= 100.
`currentPlayers` | Current number of players in this activity. | Optional. If specified, must be > 0 and <= 100.
`groupId` | A title-defined Id. Players with the same groupID are recognized in MPA to be playing together. | Must be < 128 characters.
`platform` | The platform on which the activity was created. | Used when querying activities only. The platform will be automatically inferred when setting an activity.

## Privacy
A title may wish to allow only a subset of the users on its social graph to join
the user. The `joinRestriction` field determines whether other players receive
the connection string when viewing this activity.

Value | Meaning
------|--------
`Public` | All players may join this activity.
`Followed` | If the activity creator follows another player, that player may join.
`InviteOnly` | No players may join this activity, unless responding to an invite.

## Supporting crossplay activities

When creating an activity in the GDK, titles may specify an `allowCrossplay` flag.
If `false`, the GDK automatically fills the platform field of an invite with the
current platform. If `true`, it leaves the platform field `null`, indicating that
the invite is cross platform. The list of platforms allowed via crossplay is defined by title 
configuration. Console generations are considered crossplay in this scenario.

## Retrieving activities
When retrieving activities for other players, sometimes the connection string is
hidden. This indicates that the user is not allowed to join this activity. For
example, the connection string may be hidden because of the activity's
`joinRestriction`, the activity is full.