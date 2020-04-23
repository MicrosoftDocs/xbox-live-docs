---
title: XR-067 Maintaining Multiplayer Session State
author: mwester
ms.topic: article   
description: TBD
---

Version 1.1, 5/1/2020


# XR-067: Maintaining Multiplayer Session State &diams;

On Xbox consoles, titles with online multiplayer functionality must maintain session-state information in the Xbox Multiplayer Session Directory (MPSD). 

On devices other than Xbox consoles, titles which offer cross platform multiplayer with Xbox consoles must maintain session-state information in the Xbox Multiplayer Session Directory (MPSD).

## More Information
When multiple users are playing together in a networked experience, that grouping of players must have at least one session in the MPSD containing all the players. When a session is in interactive multiplayer gameplay, the gameplay capability in the multiplayer session must be set to True.  As players join and leave the experience, they must be added to and removed from the MPSD session, respectively. 
Intent: Ensure that the Xbox system is aware of the users who are playing together online. This information is used to support the recent players list, player feedback, usage reporting, and other platform features.


## Implementation Guidance and Best Practices

## Additional Resources


“Multiplayer in Xbox One,” a topic in the XDK documentation
Net Rumble Cross Play, a code sample available from Samples on GDN

## Certification Test Cases

**067-01 Maintaining Session State**   
  
  
>
>**Test Steps**  
>1. Sign into an Xbox Live profile and launch the title on multiple devices.
>2. Complete an Xbox Live game session with all players.
>3. Return Home and view the Recent Players list to verify that all players from the game session are included.
>4. Repeat steps [1] – [3] several more times but this time using new accounts each time.
>5. Repeat steps [1] – [4] but this time have one or more player(s) leave during gameplay and ensure their profile(s) still appear in the Recent Players list during step [2].  
>
>**Expected Result**  
>Users must be able to review all players from each and every recently played game session.  
>
>**Pass Examples**  
> 1. All profiles are included in the device's Recent Players list.  
>
>**Fail Examples**  
> 1. Not all the profiles are included in the device's Recent Players list.
>2. Users who quit during multiplayer gameplay do not appear in the Recent Players list.  



# Change history 

Date | Document version | Change description
-----|------------------|-------------------
May 1, 2020  | 7.1 | Updated to require integration on non console devices when cross play is enabled with Xbox Consoles  <br/> <br/> 
