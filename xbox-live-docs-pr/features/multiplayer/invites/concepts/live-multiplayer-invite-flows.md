---
title: Flows for multiplayer game invites
description: Updated flow diagrams for implementing multiplayer game invites, to invite another player to a multiplayer game.
ms.assetid: 1569588e-3bbc-47d3-8b7d-cc9774071adc
ms.date: 04/04/2017
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, multiplayer 2015
ms.localizationpriority: medium
---





# Flows for multiplayer game invites

Starting with Xbox One Recovery Update 24 (November 6, 2013), the user experience flow for multiplayer game invites has been changed.
This is a change to the **user-experience (UX) only** and will not affect any behavior or functionality from the perspective of a game title.
Title developers will not need to make any code changes.


## Summary of changes

- The initial invitation toast has changed from "join my party" to "&lt;_game title_&gt; Let's Play" and now has a button that allows users to launch the game and jump right into gameplay.

- The Party app is not snapped by default when the user chooses the new "&lt;_game title_&gt; Let's Play" option. This change is also made so that the user can jump right into gameplay.

- A new toast has been added on the sender's side that says "Adding \[*number*\] friends to the game". This makes it clear that invites were sent out when a game session is associated with a user's party.

The detailed user experience flows are described in the following examples.
Each table shows an example flow for two users, David and Laura.
These flows are shown in each column and occur in parallel.

The <b style="background-color: #FFFF00">highlighted text</b> shows the adjustments that have been made from the prior UX flows.


## Inviting users from within a game

<table>
  <tr>
    <th>Step</th>
    <th>David's Device</th>
    <th>Laura's Device</th>
  </tr>

  <tr>
    <td>1.</td>
    <td>
      <p>David is in the multiplayer lobby for a game he is playing.</p>
      <p>David chooses "Invite a Friend".</p>
      <p>David selects Laura.</p>
      <p>Toast pops up indicating that an invite was sent.</p>
    </td>
    <td>
      Laura is playing a different game.
    </td>
  </tr>

  <tr>
    <td>2.</td>
    <td>
      &nbsp;
    </td>
    <td>
      <p>Toast pops up indicating an invitation from David, and <b style="background-color: #FFFF00">displays the game name and icon</b>. (The Party app does not auto-snap.)</p>
      <p>In the Notification Center, <b style="background-color: #FFFF00">Laura can choose "Launch and accept invite"</b>, "Accept invite", or <b style="background-color: #FFFF00">"Decline Invite"</b>.</p>
    </td>
  </tr>

  <tr>
    <td>&nbsp;</td>
    <td>
      &nbsp;
    </td>
    <td>
      <b style="background-color: #FFFF00">Case 1: Laura selects "Launch and accept invite"</b> (this is a new option):
    </td>
  </tr>

  <tr>
    <td>3.</td>
    <td>
      <p>Toast pops up indicating that Laura has joined David's party.</p>
      <p>David starts the game from multiplayer lobby.</p>
      <p><b style="background-color: #FFFF00">Toast pops up indicating that a game invite was sent to Laura.</b></p>
    </td>
    <td>
      The game launches and the Party app does not snap.
    </td>
  </tr>

  <tr>
    <td>&nbsp;</td>
    <td>
      &nbsp;
    </td>
    <td>
      <b>Case 2: Laura selects "Accept invite":</b>
    </td>
  </tr>

  <tr>
    <td>3.</td>
    <td>
      &nbsp;
    </td>
    <td>
      Laura joins the party.
    </td>
  </tr>

  <tr>
    <td>4.</td>
    <td>
      <b style="background-color: #FFFF00">Toast pops up indicating that a game invite was sent to Laura.</b>
    </td>
    <td>
      &nbsp;
    </td>
  </tr>

  <tr>
    <td>5.</td>
    <td>
      &nbsp;
    </td>
    <td>
      <p>Toast pops up indicating that a game was found for the party.</p>
      <p>In the Notification Center, Laura can choose:
        <ul>
          <li>"Accept game invite":</b> Game launches.</li>
          <li>"Decline game invite":</b> No game launches. Laura is still in the party and will receive subsequent game invites.</li>
          <li><b style="background-color: #FFFF00">"Leave party": No game launches. Laura is removed from the party.</b></li>
        </ul>
      </p>
    </td>
  </tr>

</table>


## In-game invite flow: In a party, and switching titles

<table>
  <tr>
    <th>Step</th>
    <th>David's Device</th>
    <th>Laura's Device</th>
  </tr>

  <tr>
    <td>1.</td>
    <td>
      <p>Playing a game together.</p>
      <p>David switches to a different game and goes to the multiplayer menu.</p>
      <p>The Xbox System UI asks David if he would like to switch his Party to the new game, to which he can answer "Yes" or "No".</p>
    </td>
    <td style="text-align:top">
      Playing a game together.
    </td>
  </tr>

  <tr>
    <td>&nbsp;</td>
    <td>
      <b>Case 1: David selects "Yes":</b>
    </td>
    <td>
      &nbsp;
    </td>
  </tr>

  <tr>
    <td>2.</td>
    <td>
      <p>Party comes to the new title.</p>
      <p>From the multiplayer lobby, David starts the game.</p>
      <p><b style="background-color: #FFFF00">Toast pops up indicating that a game invite has been sent to Laura.</b></p>
    </td>
    <td>
      &nbsp;
    </td>
  </tr>

  <tr>
    <td>3.</td>
    <td>
      &nbsp;
    </td>
    <td>
      <p>Toast pops up indicating that a game was found for the party.</p>
      <p>From the Notification Center, Laura can choose:
        <ul>
          <li>"Accept game invite": New game launches</li>
          <li>"Decline game invite": No game launches, but Laura is still in the party and will receive subsequent game invites.</li>
          <li><b style="background-color: #FFFF00">"Leave party": No game launches and Laura is removed from the party.</b></li>
        </ul>
      </p>
    </td>
  </tr>

  <tr>
    <td>&nbsp;</td>
    <td>
      <b>Case 2: David selects "No":</b>
    </td>
    <td>
      &nbsp;
    </td>
  </tr>

  <tr>
    <td>2.</td>
    <td>
      Party does not come to the new title.
      David plays on multiplayer mode without his party members.
      David is still in the party.
    </td>
    <td>
      &nbsp;
    </td>
  </tr>

</table>


## Invite flow from Home

<table>
  <tr>
    <th>Step</th>
    <th>David's Device</th>
    <th>Laura's Device</th>
  </tr>

  <tr>
    <td>1.</td>
    <td>
      <p>David is browsing "Home", and in his "Friends" list, he sees that Laura is online.</p>
      <p>David chooses to invite Laura to his party. Toast pops up indicating that the invite is sent. The Party app is snapped for David.</p>
    </td>
    <td>
      Laura is playing a game.
    </td>
  </tr>

  <tr>
    <td>2.</td>
    <td>
      &nbsp;
    </td>
    <td>
      <p>Toast pops up indicating that David has invited Laura to his party.</p>
      <p>In the Notification Center, Laura has the option to "Accept the invite".</p>
      <p>When Laura accepts, the Party app snaps.</p>
    </td>
  </tr>

  <tr>
    <td>3.</td>
    <td>
      <p>Toast pops up indicating that Laura has joined the party.</p>
      <p>David and Laura discuss what game they want to play. David launches the game and enters the multiplayer game mode.</p>
      <p>Game will either give an option to invite friends, or auto-pull the party members.</p>
      <p><b style="background-color: #FFFF00">Toast pops up indicating that a game invite has been sent.</b></p>
    </td>
    <td>
      <p>Toast pops up indicating that a game has been found for the party.</p>
      <p>In the Notification Center, Laura can:
        <ul>
          <li>"Accept game invite": Game launches</li>
          <li>"Decline game invite": No game launches, Laura is still in the party and will receive subsequent invites.</li>
          <li><b style="background-color: #FFFF00">"Leave party": No game launches, Laura is removed from the party.</b></li>
        </ul>  
      </p>
    </td>
  </tr>

</table>


## More about the Game Invite Sent toast

The **Game Invite Sent** toast will only appear the first time a game session is established with remote party members.
Subsequent requests sent to remote party members will not generate this toast.
This prevents the user from being spammed with repeated **Game Invite Sent** toasts if the title makes multiple calls to **PullReservedPlayersAsync**.

**Note** The best practice is to add all desired friends as Reserved, and then call **PullReservedPlayersAsync** only once.
