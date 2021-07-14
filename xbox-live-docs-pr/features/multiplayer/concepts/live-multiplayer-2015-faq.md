---
title: Multiplayer 2015 FAQ and troubleshooting
description: FAQs and troubleshooting for Multiplayer 2015.
kindex: Multiplayer 2015 FAQ and troubleshooting
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
ms.assetid: 75823f10-b342-4e20-b885-e5ad4392bc3d
ms.localizationpriority: medium
ms.date: 04/04/2017
---





# Multiplayer FAQ and troubleshooting


### How can I access the new multiplayer API from a service?

See the section [Calling MPSD](../mpsd/live-mpsd-overview.md#calling-mpsd) in the article "Multiplayer Session Directory overview".


### Can my title subscribe to changes for more than one session?

Yes, a title can subscribe to receive changes on up to 10 sessions per connection.


### Will a user be removed immediately if he/she loses a network connection or turns off the console?

The web socket connection allows MPSD to rapidly detect client disconnection and set the client to inactive.
Session members are removed as soon as the inactive removal timeout expires.
See the section [Session Timeouts](../mpsd/concepts/live-mpsd-details.md#session-timeouts) in the article "Multiplayer Session advanced topics".


### How do I find out what SCID, session template, and sandbox to use?

If you were not involved in the initial registration of your title, when this information was created, you do not have access to this information. Contact your Developer Account Manager, who can get this data for you.


### Is there an example of a request body that I can compare to the one for my title?

See the request structure in **MultiplayerSessionRequest (JSON)**


### I am getting an HTTP/403 code when calling MPSD.

This is usually a permissions or scope issue. Collect Fiddler traces to get more information and then check the messages returned as part of the HttpResponse body for common 403 messages:

-   The requested service config cannot be accessed.
    1.  Confirm that you are using an account that has access to the sandbox.
    2.  Confirm that you are within the correct sandbox.
     3.  If you are using certificate authentication and getting this error, contact your Developer Account Manager.   The requested session cannot be accessed. The calling user must have multiplayer privilege, and private sessions can only be read by session members.

    You don't have the ability to see the session, possibly because you are trying to access a session that has a visibility of Private. If the visibility is set to Private, only members of that session can read the session document.

| Note                                                                                                                                                  |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| A user must have a Gold account to register a new session. Without Gold account privileges for a playing user, requests to register a new session return HTTP/403. |

-   The request body can't contain existing member references unless the authentication principal includes a server.

    You cannot join another user to a session on behalf of a user. You can only invite. Set the index to "reserve\_&lt;number&gt;" to invite a player.


### I am getting an HTTP/404 code when calling MPSD.

Collect Fiddler traces to get more information and then do the following:

1.  Check the message returned as part of the HttpResponse body for common 404 messages:
    -   The requested service config is either invalid or not configured for sessions. Ensure that the SCID being used is correct.
    -   The requested session wasn't found. Ensure that the session is created and that the session template is correct before retrieving it. You can create a session with a PUT call.

2.  Check the URI you are using.
3.  Reboot the console or try with a new user.
4.  Check the Game Developer Forums for the error code or other solutions.
5.  Confirm that the session was not deleted as a result of being empty. Sessions can become empty because users time out. When this happens, it is frequently because all session members are in a state to which a timeout is applied, such as "ready" or "inactive". See the section [Session User States](../mpsd/concepts/live-mpsd-details.md#session-user-states) in the article "Multiplayer Session advanced topics".


### Why am I getting an HTTP/404 code when calling **MultiplayerService.WriteSessionByHandleAsync** or **MultiplayerService.GetCurrentSessionByHandleAsync**?

If your title is accessing an MPSD session by handle in response to a join protocol activation containing a handle ID, the handle ID in the protocol activation might be stale for one of the following reasons:

-   The UI view in the Xbox shell from which the title initiated the join might be out of date. Some UI views, for example, the user's profile card, do not automatically refresh join handles while they are open. To avoid receiving the HTTP/404 code, the title should close and reopen the view to refresh the data before joining.
-   The user that the title is joining might have switched activity sessions after the title selected the join operation from the Xbox shell UI. This reason for the HTTP/404 code should be rare.

In either of these cases, your title code should show the joining user an error message indicating that the join failed.


### I am getting an HTTP/412 code when calling MPSD.

The following request returns HTTP/412 if the session already exists:

```uri
PUT /serviceconfigs/00000000-0000-0000-0000-000000000000/sessiontemplates/quick/sessions/foo HTTP/1.1
Content-Type: application/json
If-None-Match: *
```

The following request returns HTTP/412 if the session etag doesn't match the If-Match header:

```uri
PUT /serviceconfigs/00000000-0000-0000-0000-000000000000/sessiontemplates/quick/sessions/foo HTTP/1.1
Content-Type: application/json
If-Match: 9555A7DE-8B91-40E4-8CFB-0629312C9C7D
```

See the section [Synchronization of Session Updates](../mpsd/live-mpsd-overview.md#synchronization-of-session-updates) in the article "Multiplayer Session Directory overview".


### I am getting an HTTP/400, 405, 409, 503, etc. code when calling MPSD.

Collect Fiddler traces to get more information, and then check messages returned as part of the HttpResponse body.
This should give you enough information to identify and fix the error, or you can search the developer forums for resolutions.

You can also get the response body if you are using XSAPI, as described in [Troubleshooting Xbox Live Services APIs](../../../test-release/troubleshooting/live-troubleshooting-apis.md).
Alternatively, your code can use the **XboxLiveContextSettings.EnableServiceCallRoutedEvents** property to send output to your title UI.


### What can or should I change in the session templates for my title?

Session templates are patterns for your sessions, and you can't override the constants already set in the templates. However, you can add new properties to the templates. See [Multiplayer session templates](../mpsd/concepts/live-session-templates.md) and [Multiplayer Session Directory overview](../mpsd/live-mpsd-overview.md).


### I'm getting an error that is saying my session isn't initialized.

Example response error:

400 - \[ResponseBody\]: This session is configured for managed initialization requiring at least 2 members to start.

The session can't be created because not enough session member reservations with the "initialize" field set to true are included in the request. Your code can set this field for a member using the *initializeRequested* parameter for the **MultiplayerSession.AddMemberReservation** method or the **MultiplayerSession.Join** method.

When initialization is specified in your session template, make sure that "initialize":"true" is set for enough of the member reservations to pass matchmaking QoS.
See [Target session initialization and QoS](../matchmaking/concepts/live-matchmaking-target-session.md).


### My session is not being created and I'm getting an HTTP/204 code.

This status code indicates that no users were added to the session when you created it. If there are no users in the session when it's created and the session empty timeout is zero (default), the session is not created.

Make sure that you include at least one player when creating a session.
For dedicated server scenarios, obtain a player who is trying to create a match or who needs to create a match and make that player the initial player in the match.
Alternatively, you can change or remove the session empty timeout.
See the section [Session Timeouts](../mpsd/concepts/live-mpsd-details.md#session-timeouts) in the article "Multiplayer Session advanced topics".


### When should I poll MPSD?

Your titles must avoid polling MPSD. If a title must discover changes to MPSD sessions, it should subscribe for session change events.
See the section [Subscribe for MPSD session change notifications](../mpsd/how-to/live-mpsd-how-tos.md#sfmscn) in the article "Multiplayer tasks".


### What happens if a player who was reserved or invited to the session does not join it?

It depends on whether or not the title is running when the player is notified that the game session is ready. If the player is in the title and does not accept the game session notification from the title UI, it is up to the title to remove the player from the game session with the **MultiplayerSession.Leave** method.

If the title is constrained or not running, the shell provides a notification that informs the player that a slot is available. If the player declines or ignores the system notification, MPSD removes that person from the game session.


### Why would a created session not be found by matchmaking?

On Xbox One (or later), simply creating a session isn't enough for matchmaking to find the new session. You must create a match ticket to start advertising the session to the matchmaking service. See [Matchmaking overview](../matchmaking/live-matchmaking-overview.md).


### If a game session has open player slots and supports join in progress, why would users not be able to find the session once it has started?

When a game session starts, it is no longer advertised on the matchmaking service. If player slots become available within the session and the arbiter (host) wants to attract new players, the arbiter must create a new match ticket for the in-progress session with the **MatchmakingService.CreateMatchTicketAsync** method. The ticket advertises the session again and finds more players. See [Matchmaking overview](../matchmaking/live-matchmaking-overview.md).


### If a game session is open, can a user who has just joined a game simply join the session and start playing without having to wait for the reservation?

Yes. This is especially useful in cases where your title uses multiple sessions to track sub-groups of players within a game session. The joining user might join the session representing his/her group, and then need to join the larger game session.


### When large game sessions are playing in my title, why aren't all session members seeing the game invite toast?

When your title adds a user to the session through joining, the title always sets the **MultiplayerSessionMember.InitializeRequested** property to true. This tells MPSD to wait for the rest of the session members before moving the game out of the initialization stage. Otherwise, users have a very short window in which to join and can miss toasts and notifications of session changes.


### Why am I seeing the syntax for v105 session documents in my traces although I have configured a v107 session template?

The MPSD performs automatic conversion between session document versions based on the client request. Currently all Xbox Service APIs use v105 for requests to the MPSD. This may result in different syntax between v107 session templates and v105 traces but has no other functional impact. Session templates should be configured as v107.

&copy; 2015 Microsoft Corporation. All rights reserved.
Submit feedback on <https://forums.xboxlive.com/spaces/22/index.html>.
Version: 2.0.90731.0
