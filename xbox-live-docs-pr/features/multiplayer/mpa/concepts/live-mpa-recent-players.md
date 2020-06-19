---
title: Recent Players
description: Record interactions with other players to build player relationships or report feedback.
kindex: Recent Players
kindex: MPA
ms.topic: conceptual
ms.localizationpriority: high
security: public
author: jeffng
ms.author: jeffng
ms.date: 05/12/2020
edited: 00/00/0000
---

# Recent Players

When players interact with each other in a multiplayer activity, titles should
record their interaction using Multiplayer Activity (MPA). This allows players
to easily send friend invites, game invites, and messages if the interaction was
positive, or report feedback if the interaction was negative.

Titles should be careful to only post meaningful interactions with players to
prevent flooding the recent players list with extraneous users. For instance, a
"battle royale" style game may have 100 users in it, but the title should only
record players that have actually interacted with each other, as opposed to
submitting that all 100 players have played with each other.


<a name="upvbg"></a>

## Unidirectional players vs. Bidirectional groups

MPA accepts two concepts of player interaction. In the unidirectional case, the
title reports that Player A has played with one or more players. This should
occur for every player that has affected player A, and as a result, each of
these players will appear on Player A's recent players list. All players should
report their own interactions individually.

Servers are also allowed to report batches of recent players in this manner.

In the bidirectional groups case, all players are known to have interacted with
each other. For example, in a "4 vs. 4" shooter or an 8-player race, the game
knows beforehand that all players should show up in each others' player lists.
They may call an API with a list of users, and MPA will ensure every player has
every other player added to their recent players list. Only servers are allowed
to submit bidirectional groups.

## Encounter types

MPA supports recording what type of encounter has occurred. Titles may specify
an `encounterType` field, which has the allowed values of `Default`, `Teammate`,
and `Opponent`. If unspecified, it defaults to `Default`. Specifying this gives
the opportunity for players to more easily differentiate between various types
of encounters.
