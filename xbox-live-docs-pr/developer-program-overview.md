---
title: Joining a developer program
description: Choosing and joining either the Creators Program or the ID@Xbox Managed Partners Program.
ms.assetid: 1166308a-4079-41b4-8550-ce04b82b4f72
ms.date: 05/30/2018
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, developer program, creators
ms.localizationpriority: medium
---

# Joining a developer program

To enable a game with Xbox Live, you join the Creators program, or join the Managed Partners program as an ID@Xbox Partner.


## Summary of the programs

Each program offers different levels of time investment, features available, and support options.


### Creators Program

Join the Xbox Live *Creators Program* if both of the following are true:

*  You're interested in using only a subset of Xbox Live features, such as Identity, Presence, Clubs, or Leaderboards 2017.

*  You only plan to ship via Microsoft storefronts on Microsoft devices, such as Xbox, Windows 10 PC, and Hololens.

            

### ID@Xbox Managed Partners Program

Join the *ID@Xbox Managed Partners Program* if at least one of the following are true:

* You’re interested in using the full suite of Xbox Live services, including multiplayer features and Achievements and Gamerscore on Microsoft devices, such as Xbox, Windows 10 PC, or Hololens.

* You plan to use Xbox Live components in a game which is shipping via a non-Microsoft store or on a non-Microsoft device (such as mobile).

* You must agree to abide by the regulations around Xbox Live.


## Applying to a developer program


### Creators Program

To join the Xbox Live Creators Program:

* Create a Partner Center account; see <a href="https://docs.microsoft.com/partner-center/mpn-create-a-partner-center-account" target="_blank">Create a Partner Center account &#11008;</a>.

Then you can set up a game app at Partner Center; see [Getting Started](get-started/index.md).


### ID@Xbox Managed Partners Program

To apply to become an ID@Xbox partner:

1. Go to <a href="https://www.xbox.com/developers/id" target="_blank">Welcome to ID@Xbox &#11008;</a>.

2. Click the **APPLY TO THE PROGRAM NOW** button.

   The "Apply to ID@Xbox now" form appears.

3. Fill-in the form and then click the **Submit Application** button.

   Microsoft emails you additional forms and helps you create a Microsoft Partner Center account.

Then you can set up a game app at Partner Center; see [Getting Started](get-started/index.md).


## Xbox Live Creators Program

The Xbox Live Creators Program is a good starting point for Xbox Live if you are looking to familiarize yourself with Xbox Live development.
No approval process from Microsoft is required to join this program, and there are minimal certification and publishing requirements.

The Xbox Live Creators Program only supports the creation of titles (games) for the <a href="https://msdn.microsoft.com/windows/uwp/get-started/universal-application-platform-guide" target="_blank">Universal Windows Platform (UWP) &#11008;</a>.
These titles created as UWP games run on Windows 10 PCs and on Xbox One consoles.
For more details about running UWP games on Xbox One, see <a href="https://docs.microsoft.com/windows/uwp/xbox-apps/index" target="_blank">UWP on Xbox One &#11008;</a>.

On Xbox One, which offers gamers a curated store experience, games published through the Xbox Live Creators Program will be sold in the new Creators Collection section of the Microsoft Store on Xbox.
This offers a balance between ensuring an open platform where anyone can develop and ship a game, and a curated store experience console gamers have come to know and expect.
On Windows 10, your title will be published among all of the other Xbox Live games in the Microsoft Store.


### Publishing and certification, for Creators

To *release* a game as part of the Xbox Live Creators Program, you must be enrolled in the <a href="https://developer.microsoft.com/store/register" target="_blank">Partner Center developer program  &#11008;</a>.

There are two sets of requirements that your game must follow:

1. Integrate Xbox Live Sign-In and display the user identity (Gamertag, Gamerpic, etc.). All other Xbox Live services are optional.

2. Follow the standard <a href="https://msdn.microsoft.com/library/windows/apps/dn764944.aspx" target="_blank">Microsoft Store Policies &#11008;</a>.


### Supported Xbox Live services, for Creators

Titles enabled under the Xbox Live Creators Program can use Leaderboards, Featured Stats, Title Storage, Connected Storage, and a restricted set of social features.
Achievements, online multiplayer, and many social features are **not** supported for titles in the Xbox Live Creators Program.

For a full list of supported services, see the Feature Table below.


### Supported third party game development engines

Xbox Live Creators Program titles are UWP games which can be built with a number of popular game engines.
Microsoft provides documentation for integrating Xbox Live services into UWP games built with the <a href="https://unity.com" target="_blank">Unity game engine &#11008;</a>.
 
For details on Xbox Live integration with Unity games, see [Get started developing a Creators Program title with Unity](get-started-with-creators/develop-creators-title-with-unity.md).
Download and learn about the Microsoft-built <a href="https://github.com/Microsoft/xbox-live-unity-plugin" target="_blank">Xbox Live Unity plugin &#11008;</a>.

Xbox Live Creators Program games can also be built with the game engines
<a href="https://www.scirra.com/construct2" target="_blank">Construct (2 & 3) &#11008;</a>, and
<a href="https://www.yoyogames.com/gamemaker" target="_blank">GameMaker Studio 2 &#11008;</a>.
Both game engines have added Xbox Live support, however, that support is handled by the game engines creators and not Microsoft.
For details and support for adding Xbox Live to your Construct or GameMaker Studio 2 project, you will have to consult each game engine's documentation respectively.

<a href="https://www.scirra.com/tutorials/9540/using-xbox-live-in-uwp-apps" target="_blank">Learn to integrate Xbox Live into your Construct project &#11008;</a>

<a href="https://www.yoyogames.com/gamemaker/xblc" target="_blank">Learn to integrate Xbox Live into your GameMaker Studio 2 project &#11008;</a>

For other game development engines, like <a href="http://www.monogame.net/" target="_blank">MonoGame &#11008;</a> or <a href="https://xenko.com/" target="_blank">Xenko &#11008;</a>, that do not have baked in Xbox Live functionality or a plug-in, you can still use the Xbox Live APIs to add Xbox Live to your title.
To use the Xbox Live API from your project, you can either add references to the binaries with NuGet packages or add the API source.
Adding NuGet packages makes compilation quicker while adding the source makes debugging easier.


## Support and feedback

Your questions can be answered on the <a href="https://social.msdn.microsoft.com/Forums/home?forum=xboxlivedev" target="_blank">MSDN Forums &#11008;</a>.

You can also ask programming-related questions at <a href="https://stackoverflow.com/questions/tagged/xbox-live" target="_blank">Stack Overflow &#11008;</a>, using the "xbox-live" tag.

The Xbox Live team will be engaged with the community and be continually improving our APIs, tools, and documentation based on the feedback received at these forums.


### Support for Creators

For developers in the Xbox Live Creators Program, you can <a href="https://xbox.uservoice.com/forums/363186--new-ideas?category_id=196261" target="_blank">submit a new idea &#11008;</a> or <a href="https://xbox.uservoice.com/forums/251649?category_id=210838" target="_blank">vote on an existing idea &#11008;</a> at <a href="https://xbox.uservoice.com/forums/363186--new-ideas" target="_blank">Xbox User Voice &#11008;</a>.

The Xbox Live Creators Program is great for many games and developers.


### Support for ID@Xbox Managed Partners

If you’d like to access the full Xbox Live stack, including online multiplayer, achievements and Gamerscore, or you want to access the full power of the Xbox One family of devices using hardware dev kits, the ID@Xbox program is for you.

Games in the ID@Xbox program must be concept-approved and go through full certification on Xbox One and Windows 10, which is a greater time commitment on your part.
ID@Xbox titles get placement in the primary section of the Store (versus the Creators Collection), which may provide greater exposure to customers.

Developers in the ID@Xbox program also gain access to developer support and promotional assistance from Microsoft, as well as the full complement of private whitepapers and developer technical forums.
You can continue to use <a href="https://social.msdn.microsoft.com/Forums/home?forum=xboxlivedev" target="_blank">MSDN Forums &#11008;</a> or ask programming-related questions on <a href="https://stackoverflow.com/questions/tagged/xbox-live" target="_blank">Stack Overflow &#11008;</a> using the "xbox-live" tag.

Developers working with a game publisher that is a Managed Partner (such as the ID@Xbox program) have access to the full set of Xbox Live features and dedicated Microsoft representatives to assist in the development, certification, and release process.


## Features available to Creators and ID@Xbox Partners

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
