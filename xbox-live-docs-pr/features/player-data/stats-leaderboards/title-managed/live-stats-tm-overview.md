---
title: Title-managed Stats overview
description: Stats track a player's progress and prowess in a game. With title-managed Stats, the game code maintains the stats, and sends the stat values to the server for display upon request.
ms.date: 07/02/2018
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, player stats, leaderboards, title-managed stats
ms.localizationpriority: medium
---

# Title-managed Stats overview

Title-managed Stats was formerly known as _Stats 2017_.

With title-managed Stats, the title keeps track of the stat values, and sends the values to the service.

User Stats allows developers to configure stats for individual players signifying progress and prowess in game.
These stats are a social tool that will allow players to be more competitive with their friends and the larger title's community, as well as showcasing some of the capabilities and challenges your title has to offer.

For example, if you have a racing game with featured statistics like longest drift and best hang time, you can communicate the type of racing game your players can expect.

Seeing how players stack against their friends and the community at large will give them more incentive to buy and play your title.
Players will see featured statistics on the title's GameHub.
Featured Stats may also periodically appear in pinned content blocks that users may add to their Home view.

Title-managed Stats operates by accepting stat values as key/value pairs from your title for a player and storing that stat value so that it can be displayed at a later time.
Title-managed Stats supports Xbox Live leaderboard scenarios by saving stats about individual players so they can be compared and ranked on a leaderboard later.

Title-managed Stats accepts values sent to it with little to no validation, so it is up to your title to handle all of the logic which determines the correct value for a stat.


## Configured stats and featured leaderboards

Stats are configured on the [Partner Center dashboard](https://partner.microsoft.com/dashboard/windows/overview).
In order to configure stats, you must already have a title configured.

If you do not have a title configured, you can learn how to do so by reading [Create and test a new Creator's title](../../../../get-started/setup-partner-center/legacy/create-and-test-a-new-creators-title.md).
The Stats you configure in Partner Center will appear in your title's GameHub as pictured:

The *Featured Stats* are highlighted in yellow in the image below.
![Official Club Page Social Leaderboard](live-stats-tm-overview-images/gamehub_featuredstats.png)

On Xbox One, users are able to pin games directly to their Home screen to quickly find relevant information, community driven content, and developer posts.
The stats you configure may also appear as a part of pinned Home content.

Stats will show the player along with a slightly higher ranked friend, encouraging them to play their way up the leaderboard.
Leaderboards in pinned content would appear as highlighted in the following image.

![Halo 5 Pinned Leaderboard](live-stats-tm-overview-images/Halo_5_Pinned_Leaderboard.png)

Featured Stats compare in-game progress based on configured statistics with other friends who also play the title.
This encourages more play time for your title when friends compete for high scores or simply bond over a shared experience.

Featured Stat leaderboards are monthly leaderboards which are reset on the first day of the month.

Developers are limited to having no more than 20 featured stats for their title, but there is no requirement for developers to include Featured Stats in their title.


## See also

* [Title-managed Featured Stats & Leaderboards portal config](config/live-featured-stats-and-leaderboards.md)
* [Updating title-managed Stats](how-to/live-stats-tm-updating.md)
