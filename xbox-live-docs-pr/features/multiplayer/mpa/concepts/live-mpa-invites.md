---
title: Invites
description: Send an request for another player to join a multiplayer experience.
kindex: Invites
kindex: MPA
ms.topic: conceptual
ms.prod: xbox
ms.technology: xboxgc
ms.localizationpriority: high
security: public
author: jeffng
ms.author: jeffng
ms.date: 05/12/2020
edited: 00/00/0000
---

# Invites

A title may use Multiplayer Activity (MPA) to invite another player to join a multiplayer experience.

Invites may be sent directly by the title or by an external server. Titles
send an invite with the following information:

Field | Purpose | Notes
------|---------|--------------
`xuids` | The XboxUserIds of one or more users to invite. |
`allowCrossPlatformJoin` | Indicates whether players on other platforms will receive the invite. | See "Supporting crossplay Invites" below.
`connectionString` | Title-defined string which is opaque to MPA. Contains information a title can use to connect to another player. | Must be less than 256 characters.

## Supporting crossplay invites

When creating an activity or sending an invite in the GDK, titles may specify an 
`allowCrossPlatformJoin` flag.  If `false`, the GDK automatically fills the platform field with the
current platform and the invite will only be received by players on that platform. If `true`, 
it leaves the platform field `null`, indicating that the invite is cross platform.

## Sending invites from a server

External servers may also send an invite on behalf of a user. Its contents are
identical to the client fields above, with the addition of one:

Server-only Field | Purpose | Notes
------|---------|--------------
`sender` | Indicates on behalf of which user the server is sending an invite. | Must be a valid user.