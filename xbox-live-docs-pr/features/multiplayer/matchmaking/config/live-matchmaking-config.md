---
title: Matchmaking portal configuration
description: Configuring Partner Center to select compatible players.
ms.topic: portal
ms.prod: gaming
ms.technology: xboxlive
ms.assetid: ba0c1ecb-e928-4e86-9162-8cb456b697ff
ms.date: 04/04/2017
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, multiplayer, matchmaking, smartmatch
ms.localizationpriority: medium
---

# Matchmaking portal configuration


## Configuration of SmartMatch Matchmaking Runtime Operations

All configuration of SmartMatch matchmaking occurs through the [Partner Center](https://partner.microsoft.com/dashboard).


#### Matchmaking Session Template Configuration

There are two types of session related to matchmaking:
* The match ticket session, which is the input to the matchmaking service.
* The match target session, which is the output.

When configuring session templates, you should create a template for each session type.

For a ticket session, you might use a dedicated template.
Alternatively, you can reuse a template for a lobby session or other session not intended to be used for game play.

| Important                                                                                      |
|-------------------------------------------------------------------------------------------------------------|
| The ticket session must not have QoS checks enabled, and must not be marked with the "gameplay" capability. |

For a target session, you must use a template that is intended for matchmade game play.
It should have settings that enable QoS checks between peers prior to the start of game play, and must be marked with the "gameplay" capability.

With the config UI for Partner Center, you can map each session to one or more hoppers, each containing rules that determine how sessions are matched together in that hopper.
For more information, see Basic Hopper Configuration for Matchmaking.


<a id="hop"></a>

#### Basic Hopper Configuration for Matchmaking

This section defines the fields used to configure basic hopper fields.
After this configuration, you must configure the hopper rules, as described in Configuration of Hopper Rules.

![Hopper Editor](live-matchmaking-config-images/session_template_hopper_edit.png)


###### Name

The name of the hopper that is used when submitting a session to matchmaking.
This name must match the value passed as a parameter to the **CreateMatchTicketAsync** method during creation of the match ticket.


###### Min/Max Group Size

The minimum and maximum sizes for the player group that is to be created from sessions in the hopper.
The matchmaking service attempts to create a matched group that is as large as possible, up to the maximum group size.
However, it does create a matched group if it can assemble enough players to meet the minimum group size.


###### Should Rule Expansion Cycles

For a SHOULD rule, the matchmaking service attempts to increase the search space and relax the provided matchmaking rules over time if no successful match is found.
This process is performed over multiple cycles, as specified using the Should Rule Expansion Cycles field.

Upon the last expansion cycle, the SHOULD rules are dropped so that they no longer prevent tickets from matching.
However, they are still used to determine the best match if multiple tickets are available.
Only number and QoS types are expanded before they are dropped.

See also "Configuration of Hopper Rules" in this article.

Increasing the value of the "SHOULD Rule Expansion Cycles" setting provides more cycles for SHOULD rule expansion, but also increases matchmaking duration.
The default value is 3, which is generally sufficient for most configurations.

| Important                                                                                                                                                                        |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Expansion cycles occur at fixed time intervals of 5 seconds. Upon the last expansion cycle, all "Should" rules are no longer taken into account for the remainder of the matchmaking attempt. |


##### Ranked Hopper
Ordinarily SmartMatch will prevent blocked players from being matched.
If Ranked Hopper is checked, this logic is bypassed to prevent players from using this system to avoid players of greater skill.

#### Configuration of Hopper Rules
This section defines the fields used to configure rules for a hopper.

###### Common Rule Fields
The fields defined in this section are common to all hopper rules.

**Rule Name**
The friendly name displayed for the rule for configuration purposes.

**Rule Type**
The rule type.
Options are MUST and SHOULD.
- MUST rules have to be satisfied for successful matchmaking.
- SHOULD rules can be relaxed and/or removed to find a successful match.

See "Configuration of SHOULD Rule Expansion" for more details on this process.

**Data Type**
The data type of the attribute of the matchmaking rule.
Possible values are:
- Number. Specify a simple 32-bit numerical value.
- String. Specify a Unicode string of up to 128 characters.
- Collection. Specify an array of strings. Use this value to identify downloadable content (DLC), squad membership, or role preference for players.
- Quality of Service. Specify a custom data type for including latency QoS data in matchmaking. Only one such rule should be used per matchmaking hopper.

| Note |
|----------|
| Please contact your Developer Account Manager if this limit is problematic for your title. |

- Total Value. Specify a custom data type that sums up submitted matchmaking values. You can use this value to ensure that the resulting sum is within a specific range or is an exact value.
- Team. Specify a custom data type for the teams of players included in matchmaking requests. You can use this value to avoid splitting players within a single match ticket among multiple teams.


###### Data Type-specific Rule Fields
This section defines fields used to define rules that apply to some data types, but not to others. The UI should be able to clarify which data types apply to particular rules.

**Allow Wildcards**
A value that indicates if the attribute can be omitted in the match ticket.
If it is omitted, the ticket becomes compatible with any other ticket, regardless of the value for this attribute.

**Attribute Source**
The source of the data type value. Possible sources are:
- Title provided. The data value is submitted in the match ticket.
- User stat instance. The data value is automatically retrieved from the UserStatistics service.

**Attribute Name**
The name of the attribute value source.
It is either the property name in the match ticket or the name of a user statistic.

**Default Value**
The default value for the data type, if no value is specified or available for the matchmaking request.
The default value is not applied when the Allow Wildcards field is selected and no value is specified.

**Weight**
The importance of the rule.
The weight can be used to indicate which rules are prioritized during matchmaking and rule expansion.
The weight value must be positive, and defaults to 1.

**Flatten Method**
Number data types only.
A value that indicates how multiple values are combined to satisfy a match.
It applies to multiple values for different players in a single match ticket and across multiple tickets.

The possible values are:
- Min/Max. Use the minimum or maximum value of multiple values from different match tickets.
- Average. Use average value of multiple values from different match tickets.

**Max Diff**
Number data types only.
The maximum acceptable numerical difference between two compared values to satisfy a rule.
For a SHOULD rule, this value is the starting point for rule expansion.

**Set Operation**
Collection data types only.
The operation to perform on matching the group of set values.

The possible options are:
- Intersection. Match two collections based on the amount of intersection between them. This setting results in similar or identical collection values.
- Difference. Match two collections based on the amount of difference between them.
- Role Preference. Match collections based on the preferences for the role of a player in role-based game modes.

**Target Intersection**
Part of Set Operation configuration.
The minimal intersection or maximum difference for two collections before they are matched.

**Network Topology**
Quality of service data type only.
The network topology that is used for QoS.
Possible values are Peer to Peer, Peer to Host, and Client/Server.

**Maximum Latency/Scaling Maximum**  
Quality of service data type only.
The maximum latency for successful matchmaking within the specified network topology.

This value is treated as a scaling value (as opposed to a required latency) when using a Client-Server Quality of service should rule.

| Note                                                                                                                                                           |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| In addition, default reputation rules are also applied to a hopper. These rules cannot be removed and are used to ensure correct handling of reputation during matchmaking. |

**Allow Waiting for Roles**
Collection Role Preferences data type only.
Specifies if the match service holds the matchmaking ticket in order to fill all available roles.

###### Expansion Delta
Value indicating how much to relax the submitted rule for each expansion generation.
The expansion delta is applied in addition to the Max Diff value.
See Example 1 (Rule Expansion) for details.

You can also use the expansion delta to expand multiple number values at different speeds.
This is not possible through the expansion cycle configuration setting because it applies to all rules.
Instead, the approach is to use decimal expansion values, for example, 0.4.

An expansion only occurs when a new integer is reached, which allows for different expansion speeds, even for the same number of expansion cycles.


###### QoS Expansion (Peer-to-Peer, Peer-to-Host)
For quality of service type expansion for peer games, the expansion delta cannot be configured.
Instead, you should use one of the following expansion strategies.

<table>

<tr>

<tr>
<td>
<b>1. MaxLatency < 256.</b><p/><p/>

Expansion is performed at MaxLatency * Expansion Cycle.<p/>
For example, if the initial value is 200, then 200 is used in the first cycle, 400 in the second cycle, and so on.
</td>
</tr>

<tr>
<td>
<b>2. MaxLatency > or equal to 256</b><p/><p/>

Expansion linearly scales from 50 to MaxLatency - 256.<p/>
For example, if the initial value is 556, the value scales linearly from 50 to 300 over the number of cycles.
That is, if six cycles were chosen, then the values would be 50, 100, 150, 200, 250, and 300.
If five cycles were chosen, the values would be 50, 112.5, 175, 237.5, and 300.
</td>
</tr>

</tr>
</table>


##### QoS Expansion (Client-Server)
When using dedicated servers, the expansion is based on relative preference.
Only most preferred servers will be considered in early expansion cycles.
Over time, other, less preferred servers will be used.

To ensure appropriate expansion, we require a value similar to MaxLatency, called Scaling Maximum.
This Scaling Maximum should still be set to the largest acceptable ping time — however, this value gives a relative scale for the different server ping times provided by a player, as opposed to providing an absolute requirement for ping times.

You can exclude servers with unacceptable ping times by removing them from the list in the request.

#### Example 1 (Rule Expansion)
Player level is used for matchmaking, and players are matched loosely, based on the closeness of their levels.
Players with the least amount of difference between their levels are preferred.

-   Player Level Rule
-   Rule Type: SHOULD
-   Data Type: Number
-   Max Diff: 1
-   Expansion Delta: 2
-   Flatten Method: Average

By default, the required difference between player levels is 1 or less.
- If a match is found within this difference, players are matched.
- If no initial match is found, the player level value is expanded by 2 for each iteration (three iterations by default).

This scenario results in a matchmaking behavior for a player at level 20, as shown in the table below.

| Step                    | Level Value for Potential Match Candidates | Effective Level Distance for Successful Match |
|-----|
| Initial Submitted Value | 19-21                                      | 1                                             |
| Expansion Cycle 1       | 17-23                                      | 3                                             |
| Expansion Cycle 2       | 15-25                                      | 5                                             |
| Expansion Cycle 3       | 13-27                                      | 7                                             |

As the expansion cycles continue, the effective level distance for a successful match increases without altering the Max Diff value.
Only the player level value is relaxed.


#### Example 2 (Collection Rule)
The game releases three types of DLC that are available for players.
This matchmaking rule is applied to "DLC only" game play matchmaking, and a player should own at least one DLC to be matchmade with other players.

-   Player DLC Rule
-   Rule Type: MUST
-   Data Type: Collection
-   Set Operation: Intersection
-   Target Intersection: 1

Players evaluate their DLCs and submit the values shown in the next table in their match tickets.

| Note                                                                                                                                   |
|-----------------------------------------------------------------------------------------------------------------------------------------------------|
| In the table below, the collection value indicates the ownership of the DLC. It is set to 1 if the DLC is available for the player and to 0 if not. |

| Player   | Collection Value | Matched with Players | Note           |
|----------|------------------|----------------------|----------------|
| Player 1 | { "1", "1", "1"} | 3                    | Owns all DLCs  |
| Player 2 | { "0", "0", "0"} | None                 | Owns no DLC    |
| Player 3 | { "1", "0", "0"} | 1                    | Owns first DLC |

If the target intersection in the example is set to 2, players 1 and 3 will not be matched, since the intersection between them is only 1.

#### Example 3 (Avoid previous players)
The title prefers avoiding a game with the player most recently played.
* Rule Type: MUST
* Data Type: Collection
* Set Operation: Difference
* Target Intersection: 0


## Defining team rules during SmartMatch configuration

### Configuring Team Rules
To set up the Team Rule, begin by creating one in Partner Center.
Fill out the team sizes your game expects to create from the tickets matched in this hopper.

For instance, if your game expects 4v4, you should create two entries, expecting a maximum size of 4 each, and a different name.

There is a minimum team size as well--use this if a game can be played with fewer players on a team.
Otherwise, the minimum and maximum should be the same value.


#### Using Team Rules
Once the Team Rule is configured, tickets within the hopper will be prevented from matching if there is no way to fit their groups into teams without causing a split.
The rule will write the resulting team allocation to the target session, under members/constants/custom/matchmakingresult/initialTeam.
Note that this is simply a suggested allocation--the title may find that by rearranging the players it may create a better game, while still preventing tickets from splitting into different teams.

If a ticket is created for a game that is in progress, the Team Rule will require additional information.
Suppose, for instance, that 8 players are in a 4v4 game, when two players drop or are disconnected.
The title would like to fill in those empty spots, but it cannot reshuffle the teams while the game is being played.

Attempts to fill games in progress are represented by tickets with the PreserveSession field set to "always".
In cases like this, because teams have already been allocated to players, the title must specify the current team allocation, so Match will know how many spaces are open on each team.

To supply the names of the teams each player is on, each player writes their team name into the game session, under members/me/properties/system/groups.
This field is a JArray.

Once the above properties are written to the game session, one player creates a ticket for the session, in an attempt to find more players.
When the ticket is fulfilled, Match will again write the suggested team of any players who join into members/constants/custom/matchmakingresult/initialTeam


###### Preferring even teams
Additionally, matches will be made with the largest teams first.
This means that in a hypothetical 4v4 hopper, tickets of 4 players will be matched together first, until no tickets of 4 remain.
Tickets of 3 then continue, pulling singletons as they need to, and so forth.

In this manner, tickets of similar size will generally play against each other, if they are present and not prevented by other rules.

Note that this gives the Team Rule fairly strong precedence over other rules.
For example, suppose you have a limited population, consisting of one ticket of size 4 with high skill(A), one ticket of size 4 with low skill(B), and four tickets of size 1 with high skill(C-F).
The Team Rule will cause Match to prefer A and B matching, as opposed to A, C, D, E, and F.


###### Should Variant
The Must rule prevents ticket splitting in all generations, and provides the prefer-even-teams sorting.
The Should rule is identical until the last generation--once there, tickets may be split, although the prefer-even-teams sorting will still be active.


## See also

* [Multiplayer session templates](../../mpsd/concepts/live-session-templates.md)
* [Multiplayer Session Directory overview](../../mpsd/live-mpsd-overview.md)
