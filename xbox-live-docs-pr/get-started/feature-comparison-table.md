---
title: Features supported for each developer program
description: Table of Xbox Live features supported for the Creators Program vs. the ID@Xbox Partners Program.
ms.date: 04/11/2019
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, developer program
ms.localizationpriority: medium
---

# Features supported for each developer program

The following Xbox Live features are supported for the Creators Program vs. the ID@Xbox Partners Program.


## Feature comparison table

<table>
<tr>
<th>Feature Area</th>
<th>Feature</th>
<th>Description</th>
<th>Creators Program</th>
<th>ID@Xbox Program</th>
</tr>


<tr class="dev-program-feature-start">
<td rowspan="2" class="dev-program-feature-name">Identity features</td>
<td>Sign-in / Sign-up</td>
<td>Allow players to sign-in to Xbox Live within your title, or create a new Xbox Live account if necessary.</td>
<td class="xbl-features-required">Required</td>
<td class="xbl-features-required">Required</td>
</tr>
<tr>
<td>User Identity</td>
<td>Use Xbox Live Identity by displaying information such as Gamertag and Gamerpic.</td>
<td class="xbl-features-required">Required</td>
<td class="xbl-features-required">Required</td>
</tr>


<tr class="dev-program-feature-start">
<td rowspan="13" class="dev-program-feature-name">Social features</td>
<td>Social Manager</td>
<td>Efficiently retrieve information about a player's social graph.</td>
<td class="xbl-features-limited">Optional / Limited (only friends who have played your title are exposed)</td>
<td class="xbl-features-optional">Optional</td>
</tr>
<tr>
<td>Friends</td>
<td>Retrieve the sign-in user's friends list to enable social gameplay scenarios in your title.</td>
<td class="xbl-features-limited">Optional / Limited (only friends who have played your title are exposed)</td>
<td class="xbl-features-required">Required</td>
</tr>
<tr>
<td>Rich Presence</td>
<td>Shows more detailed information about players in your title.  Whereas Basic Presence might show "User is in Car Racing Game", Rich Presence lets you specify a more detailed string like "User is driving SuperCar in RainyForest"</td>
<td class="xbl-features-notavailable">Not Supported</td>
<td class="xbl-features-required">Required</td>
</tr>
<tr>
<td>Reputation</td>
<td>Players gain or lose reputation through their behavior. Behavior is used in Matchmaking and can be used by your title in custom ways.</td>
<td class="xbl-features-notavailable">Not Supported</td>
<td class="xbl-features-optional">Optional</td>
</tr>
<tr>
<td>Basic Presence</td>
<td>Display basic presence strings showing user activity within a title, such as "Steve is playing Minecraft."</td>
<td class="xbl-features-automatic">Automatic</td>
<td class="xbl-features-automatic">Automatic</td>
</tr>
<tr>
<td>Recently Played</td>
<td>Appear in recently played titles in the Xbox App or Xbox One.</td>
<td class="xbl-features-automatic">Automatic</td>
<td class="xbl-features-automatic">Automatic</td>
</tr>
<tr>
<td>Activity Feed</td>
<td>Appear in the activity feed in the Xbox App or Xbox One.</td>
<td class="xbl-features-automatic">Automatic</td>
<td class="xbl-features-automatic">Automatic</td>
</tr>
<tr>
<td>Games Hub</td>
<td>Have a Game Hub associated with your title displaying stats, videos, and other content in a feed specific to your title.</td>
<td class="xbl-features-automatic">Automatic</td>
<td class="xbl-features-automatic">Automatic</td>
</tr>
<tr>
<td>Clubs</td>
<td>Players can use the Xbox App or Xbox One to create clubs that can be optionally associated with your title.</td>
<td class="xbl-features-automatic">Automatic</td>
<td class="xbl-features-automatic">Automatic</td>
</tr>
<tr>
<td>Looking For Group (LFG)</td>
<td>LFG allows players to find others out-of-game to schedule a multiplayer game.</td>
<td class="xbl-features-automatic">Automatic</td>
<td class="xbl-features-automatic">Automatic</td>
</tr>
<tr>
<td>GameDVR</td>
<td>Players can capture video of their gameplay sessions and share these on the activity feed.</td>
<td class="xbl-features-automatic">Automatic</td>
<td class="xbl-features-automatic">Automatic</td>
</tr>
<tr>
<td>Broadcast</td>
<td>Players can live broadcast their gameplay via streaming services like Mixer and Twitch.</td>
<td class="xbl-features-automatic">Automatic</td>
<td class="xbl-features-automatic">Automatic</td>
</tr>
<tr>
<td>Privacy</td>
<td>Allow players to mute or block or other players.</td>
<td class="xbl-features-optional">Optional</td>
<td class="xbl-features-optional">Optional</td>
</tr>


<tr class="dev-program-feature-start">
<td rowspan="4" class="dev-program-feature-name">Player Data</td>
<td>Achievements</td>
<td>Gamerscore and other rewards such as digital artwork, new maps, characters, and stat boosts.</td>
<td class="xbl-features-notavailable">Not Supported</td>
<td class="xbl-features-required">Required</td>
</tr>
<tr>
<td>Player Stats</td>
<td>Upload statistics about players which can be used in Leaderboards.</td>
<td class="xbl-features-optional">Optional (Player Data 2017 only)</td>
<td class="xbl-features-optional">Optional</td>
</tr>
<tr>
<td>Leaderboards</td>
<td>Retrieve and display player stats in a sorted way to encourage competition.</td>
<td class="xbl-features-optional">Optional (Player Data 2017 only)</td>
<td class="xbl-features-optional">Optional</td>
</tr>
<tr>
<td>Featured Stats</td>
<td>Designate certain stats as "Featured Stats" that will show up in the Game Hub.</td>
<td class="xbl-features-optional">Optional (Player Data 2017 only)</td>
<td class="xbl-features-required">Required</td>
</tr>


<tr class="dev-program-feature-start">
<td rowspan="2" class="dev-program-feature-name">Cloud Storage</td>
<td>Connected Storage</td>
<td>Roaming game saves across Xbox One Consoles and PCs.</td>
<td class="xbl-features-optional">Optional</td>
<td class="xbl-features-required">Required</td>
</tr>
<tr>
<td>Title Storage</td>
<td>Cloud storage for large amounts of per-user or per-title data.</td>
<td class="xbl-features-optional">Optional</td>
<td class="xbl-features-optional">Optional</td>
</tr>


<tr class="dev-program-feature-start">
<td rowspan="5" class="dev-program-feature-name">Multiplayer features</td>
<td>Multiplayer Session Directory (MPSD)</td>
<td>Stores information about a multiplayer session, such as list of players and their state.</td>
<td class="xbl-features-notavailable">Not Supported</td>
<td class="xbl-features-optional">Required</td>
</tr>
<tr>
<td>SmartMatch matchmaking</td>
<td>Xbox Live can match different players together for a multiplayer session.</td>
<td class="xbl-features-notavailable">Not Supported</td>
<td class="xbl-features-optional">Optional</td>
</tr>
<tr>
<td>Game Chat</td>
<td>Voice chat for players in a multiplayer game.</td>
<td class="xbl-features-notavailable">Not Supported</td>
<td class="xbl-features-optional">Optional</td>
</tr>
<tr>
<td>Arena</td>
<td>Players can compete against each other tournament style.</td>
<td class="xbl-features-notavailable">Not Supported</td>
<td class="xbl-features-optional">Optional</td>
</tr>
<tr>
<td>Xbox Live Compute</td>
<td>Deploy executables and assets which your title can communicate with, to offload computation from the client.</td>
<td class="xbl-features-notavailable">Not Supported</td>
<td class="xbl-features-optional">Optional</td>
</tr>
</table>


## Support levels

The following terms are used in the right-hand columns of the feature comparison table.

| Support level | Description |
|---------|-------------|
| _Required_ | You must implement this feature. |
| _Optional_ | You can optionally implement this feature. |
| _Limited_ | You can implement certain aspects of this feature. |
| _Not Supported_ | You cannot implement this feature. |
| _Automatic_ | This feature is automatically implemented for you. |


## See also

[Features](../features/index.md)
