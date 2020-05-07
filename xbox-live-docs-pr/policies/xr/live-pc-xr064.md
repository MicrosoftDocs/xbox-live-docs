---
title: "XR-064: Joinable Game Sessions and Online Play"
description: On devices other than Xbox consoles, titles which offer cross platform multiplayer with Xbox consoles must enable joins through the Game Bar experience.
kindex: "XR-064: Joinable Game Sessions and Online Play"
kindex: policies
ms.topic: article
ms.localizationpriority: medium
author: mwester
ms.author: mwester
ms.date: 03/18/2019
---

# XR-064: Joinable Game Sessions and Online Play &diams;

On Xbox consoles, titles that offer joinable game sessions must enable joinability through the Xbox shell interface. 

On devices other than Xbox consoles, titles which offer cross platform multiplayer with Xbox consoles must enable joins through the Game Bar experience.


## More Information
If a user is in a joinable multiplayer or co-op experience, titles must enable platform joins. A joinable multiplayer experience is one where players can intentionally play together. Examples include, but are not limited to, directly joining another player, sending and receiving invites, private lobbies and password-protected experiences.  If a user is no longer in an experience that supports joining, the user must not appear as available for joining.

When a user joins a game session but the experience is no longer joinable by that user for any reason, the title can choose to either:
* Ask the user to wait until the next opportunity to jump in.
* Give the user a clear message explaining the reason for the join failure.


## Implementation Guidance and Best Practices

Titles are highly encouraged to use the 2015 Multiplayer API flows, and must utilize the activity handle for correctly advertising joinability in the Xbox shell interface. For information about properly setting and clearing the activity handle, see the XDK documentation.

See also the Xbox One Multiplayer 2015 Developer Flowchart, available for download for Xbox console developers on the Game Developer Network, or for Xbox on Windows 10 developers on the forums.

## Additional Resources

## Certification Test Cases

**064-01 Joining a Game Session from Outside the Game**

**Configuration: 2 Xbox Live Profiles**
>* Device 1 Profile A – Friends with Profile B
>* Device 2 Profile B – Friends with Profile A

**Test Steps**
>1. Using Profile A, create a joinable game session.
>2. Using Profile B not running the title, access the Friends List via Game Bar and verify that the Profile A is listed as joinable.
>* It is possible that some games may only support private multiplayer sessions and therefore not appear as joinable for Profile B, in which case please jump to step [5].
>3. Profile B join Profile A’s game.
>4. Confirm that both profiles are placed into the game experience together.
>5. Repeat steps [1] – [4] but this time, instead of Profile B joining through Game Bar, have Profile A send a game invite via Game Bar to Profile B and make sure Profile B can receive, accept, and join Profile A.

**Expected Result**  
>User B must be able to join user A’s game and progress into the game experience together. For games that only support private multiplayer sessions and therefore do not appear as joinable for Profile B, it is acceptable for invites to be the only mechanism to join Profile A. For multiplayer game sessions that only support joining the session via matchmaking (e.g. ranked matches), it is acceptable to not support joining via Game Bar.  Titles which offer cross platform multiplayer with Xbox consoles must enable joins through the Game Bar experience.

**Pass Examples**
>1. Both profiles are placed into the game experience together.
>2. User B is able to join user A’s game and progress into the game experience together.
>3. User A does not appear as joinable in the Friends List via Game Bar because the game only supports private multiplayer sessions, however user A can send user B a game invitation via Game Bar.
>4. User A does not appear as joinable and is unable to send game invites via Game Bar while participating in a session that only supports joining via matchmaking (e.g. ranked matches).

**Fail Examples**
>1. User B is not able to successfully join User A’s game and is not placed in the game experience.
>2. User A does not appear as joinable in Game Bar because the game only supports private multiplayer sessions, and user A cannot send user B a game invitation via Game Bar.

**064-02 Joining a Game Session from the Same Game**

**Configuration: 2 Xbox Live Profiles**
>* Device 1 Profile A – Friends with Profile B
>* Device 2 Profile B – Friends with Profile A

**Test Steps**
>1. Using Profile A, launch the title and create a joinable game session within the title.
>2. Using Profile B, launch the same title and enter some experience within the title.
>3. Using Profile B, join Profile A’s game via Game Bar.
>* It is possible that some games may only support private multiplayer sessions and therefore do not appear as joinable for Profile B, in which case please jump to step [5].
>4. Confirm that both profiles are placed into the game experience together.
>5. Repeat steps [1] – [4] but this time, instead of Profile B joining through Game Bar, have Profile A send a game invite via Game Bar to Profile B and make sure Profile B can receive, accept, and join Profile A.

**Expected Result**
>User B must be able to join user A’s game and progress into the game experience together. For games that only support private multiplayer sessions and therefore do not appear as joinable for Profile B, it is acceptable for invites to be the only mechanism to join Profile A. For multiplayer game sessions that only support joining the session via matchmaking (e.g. ranked matches), it is acceptable to not support joining via Game Bar. Titles which offer cross platform multiplayer with Xbox consoles must enable joins through the Game Bar experience.

**Pass Examples**
>1. Both profiles are placed into the game experience together.
>2. User B is able to join user A’s game and progress into the game experience together.
>3. User A does not appear as joinable in Game Bar because the game only supports private multiplayer sessions, however user A can send user B a game invitation via Game Bar.
>4. User A does not appear as joinable and is unable to send game invites via Game Bar while participating in a session that only supports joining via matchmaking (e.g. ranked matches).

**Fail Examples**
>1. User B is not able to successfully join User A’s game and is not placed in the game experience.
>2. User A does not appear as joinable in Game Bar because the game only supports private multiplayer sessions, and user A cannot send user B a game invitation via Game Bar.

**064-05 Non-Joinable Game**

**Configuration: 3 Xbox Live Profiles each signed into a different devices**
>* Device 1 Profile A - Friends with Profiles B & C
>* Device 2 Profile B - Friends with Profile A
>* Device 3 Profile C - Friends with Profile A

**Test Steps**
>1. Using Profile A, launch the title and create a joinable game session.
>2. Using Profile A, invite profiles B and C to the game.
>3. Using Profile A, enter a game session so there is only one remaining slot after A joins.
>4. Using Profile B, accept the invite.
>5. Confirm Profiles A & B are playing together.
>6. Using Profile C, accept the invite and attempt to join the game session.

**Expected Result**
>Profile C is asked to wait until the next opportunity to jump in or Profile C is messaged the reason for the failure to join the game session.

**Pass Examples**
>1. Profile C is asked to wait until the next opportunity to jump in.
>2. Profile C is messaged the reason for the failure to join the game session.

**Fail Examples**
>1. Profile C is not asked to wait until the next opportunity to jump in and Profile C is not messaged for the failure to join. 

<br />

## Change history 

Date | Document version | Change description
-----|------------------|-------------------
May 1, 2020  | 7.1 | Updated to require integration on non console devices when cross play is enabled with Xbox Consoles  <br/> <br/> 
