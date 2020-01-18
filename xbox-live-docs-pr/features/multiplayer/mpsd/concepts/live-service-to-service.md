---
title: Service-to-service multiplayer session management
description: Using service-to-service calling patterns with MPSD.
ms.date: 05/21/2019
ms.topic: conceptual
ms.prod: gaming
ms.technology: xboxlive
keywords: xbox live, xbox, games, multiplayer, service-to-service, s2s
ms.localizationpriority: medium
---

# Service-to-service multiplayer session management

Like other services, the Multiplayer Session Directory (MPSD) supports service-to-service (S2S) calling patterns. These extend the client calling patterns and allow title services to efficiently manage multiple users through single service calls.

Management of multiplayer sessions through a title service, instead of clients, can reduce error handling logic and avoid race conditions for session write operations. This specifically applies for large session types with large session membership. Therefore, it is best practice for MMOs and titles with many players in a session to manage MPSD sessions through the title server.

For general information about RESTful MPSD calling patterns, refer to [Xbox Live REST Additional Reference](../../../../api-ref/xbox-live-rest/additional/atoc-xboxlivews-reference-additional.md).


## MPSD service-to-service authentication

Authentication for S2S calls to the Xbox Live Multiplayer service vary from other Xbox Live services. Calls with a Delegation token are not supported and only calls with service authentication must be used. This authentication type enables the additional MPSD S2S functionality.

As for other S2S calls a Business Partner Certificate is required. A full-access Multiplayer.Manage policy must be in place for the web service that the Business Partner Certificate was created under to provide the correct access level for S2S calls.

The following authentication flow is used for service authentication:

1. Call XASS with the Business Partner Certificate to retrieve an S token.

1. Call XSTS with this S token and a SandboxId to receive an X token. A Delegation token or User token must not be used in this step. The SandboxId specified through this flow, must also be in the set of sandboxes specified during the creation of the Business Partner Certificate. Business Partner Certificates without a specific sandbox are not supported and will cause authentication errors that indicate a missing sandbox.

1. Call the MPSD service service with the X token and headers (as specified in the next section). 
<!--For detailed information on S2S authentication refer to [S2S Auth Doc topic].-->


## MPSD service-to-service headers


### Title header

To act as the correct title, the X-Xbl-OnBehalfOf-Title header is required in the following format:

```json
X-Xbl-OnBehalfOf-Title:[titleid in decimal]
```

*Example:*

```json
Request.Headers["X-Xbl-OnBehalfOf-Title"] = "484921321";
```

This header must be specified to make calls for a particular title.


### User header

To act as a specific user or set of users, the `X-Xbl-OnBehalfOf-Users` header is required in the following format:

```json
X-Xbl-OnBehalfOf-Users:[xuid][;privilege][,xuid[;privilege]]...
```

*Example:*

```json
Request.Headers["X-Xbl-OnBehalfOf-Users"] = "741837829132;priv=multiplayer","8922333146718;priv=multiplayer"
```

The only privilege currently supported is `priv=multiplayer`, which indicates that the user has the multiplayer privilege.

When using the `X-Xbl-OnBehalfOf-Users` header, it is as though the user identified in the header is making the call directly from his or her console. Because of this, the calling service is required to maintain the user’s security.

* Only real XUIDs can be used.
* The privileges declared for the user must be correct.
* The user must have consented to any action taken on their behalf.

The last requirement means that the service is permitted to take only actions that the console title could have taken itself.

For example, a service can set a user as active in a title only if the user is, in fact, running and interacting with that title on the console. The service must then set the user to inactive when he or she is no longer interacting with the title on the console. Similarly, a service can send an invite on behalf of a user only if the user has taken an explicit action to send the invite.


### Deny-Scope header

The `Multiplayer.Manage` access policy overrides user access permissions for service-to-service calls to the MPSD service. Any session access is therefore not restricted based on user permissions. To re-enable user permission checks, you can use the `X-Xbl-Deny-Scope` header:

```json
    X-Xbl-Deny-Scope: Multiplayer.Manage
```

*Example:*

```json
    Request.Headers["X-Xbl-Deny-Scope"] = "Multiplayer.Manage";
```

This header ensures that the Multiplayer.Manage access policy is not used as an override when checking a user’s access (from the user header) to a session. It can be used to ensure that a user has the correct access to a session and that the server access is not overriding any other blocks because of visibility or join restrictions.

> [!NOTE]
> When setting this header, the `Multiplayer.Runtime` access must also be granted for the web service as a fall-back. This allows access even when user permissions are denied. Otherwise, no service access is granted in an error scenario and a 403 status will be returned. `Multiplayer.Runtime` access requires an acting user, so the `X-Xbl-Deny-Scope` header will only work together with the `X-Xbl-OnBehalfOf-Users` or a user claim obtained from a `DelegationToken` claim.


### Session member management

Session member management for S2S calls can be optimized by addressing multiple users in one call.

When the user header is specified, the standard "me" member in a session document body cannot be used. Instead, the following options are available:

```json
{
    "members": {

        // (e.g: me_59135345328) Requires a user principal with a xuid claim.
        "me_{xuid}": {
            "constants": { /* Property Bag */ },
            "properties": { /* Property Bag */ },
        },

        // Applies the requested change to each acting user's member.
        "me_all": {
            "constants": { /* Property Bag */ },
            "properties": { /* Property Bag */ },
        },

        // Applies the requested change to each acting user's member if they are 
           already in the session.
        "me_allInSession": {
            "constants": { /* Property Bag */ },
            "properties": { /* Property Bag */ },

        // Requires a single user principal with a xuid claim.
        "me": {
            "constants": { /* Property Bag */ },
            "properties": { /* Property Bag */ },
        },

        }
    }
}
```

Title services should use these patterns to perform operations on multiple users (e.g. adding/removing players) through a single MPSD call.


### Adding session members

Session members are added and modified by using one of the above patterns. Generally, the minimum operation to add a player is by setting a property or constant, typically the member’s active status property.

> [!NOTE]
> Members that are not set to active will be removed automatically by the service dependent on the `InactiveTimeout` value for the MPSD session.

Other required properties and constants for the player should be set through the same call as needed.

```json
{
    "members": {

        "me_{xuid}": {
            "constants": { /* Property Bag */ },
            "properties": { "system": { "active": true } 
                            /* Additional Properties */ },
        }
    }
}
```

*Example:*

```json
{
     // adding two session members with one call
    "members": {

        "me_1234567890123456": {
            "properties": { "system": { "active": true }},
        },

        "me_2345678901234567": {
            "properties": { "system": { "active": true }},        
        } 
    }
}
```


### Removing session members

Session members are removed by setting using null within the member section:

```json
{
    "members": {

        "me_{xuid}": {
            null,
        }
    }
}
```

*Example:*

```json
{
     // removing two session members with one call
    "members": {

        "me_1234567890123456": {
            null,
        },

        "me_2345678901234567": {
            null,
        } 
    }
}
```


### Member reservations

In general reservations for session members are not needed if all session management is performed by the title service. In this scenario session members can be added and removed directly without the need for reservations. Reservations for session members should only be used if created sessions are then also managed by the client.

Reservations for multiple users can be added to the session in the user order specified in the on-behalf-of-user header. The following pattern is only valid when creating a new session:

```json
{
    "members": {

        // Reservation requests must start with zero.
        "reserve_0": {
            "constants": { "system": {"xuid": "{xuid}" }
                           /* additional constants */ }
        },

        "reserve_1": {
            "constants": { "system": {"xuid": "{xuid}" }
                           /* additional constants */ }
        },

        //...//

    }
}
```

*Example:*

```json
{
     // adding reservations two session members with one call
    "members": {

        "reserve_0": {
            "constants": { "system": {"xuid": "1234567890123456" }}
        },

        "reserve_1": {
            "constants": { "system": {"xuid": "2345678901234567" }}
        },
    }
}
```

> [!NOTE]
> Reservations are not supported by large sessions. Mixing reservations and adding/removing session members is not supported.


### Session member state

A title service can track and set the state of a session member through system properties. This allows full control of member state and information.


### Member active status

The active status of a member is marking the player active in the session and prevents removal through the system as defined in the inactiveRemovalTimeout session configuration.

```json
{
    "members": {

        // Member access through XUID
        "me_{xuid}": {
            "properties": { "system": {"active": [true|false] }
                           /* additional constants */ }
        }
    }
}
```

Session members should generally always be set to active when they are added to the session. Inactive members should only be used in flows where session members should temporarily remain in the session even if they are disconnected. For S2S flows this can also be managed directly in the title server.


### Member reserve status

The reservation status of a session member can be determined through the reserved member property. If this property is set to true then the session member is in a reserved state and not yet active in the session.

Example session document:

```json
{
    /.../

    "members": {

        // First session member as example
        "1": {
            "constants": { /* Property Bag */ },
            "properties": { /* Property Bag */ },

            /.../

            "reserved”: true,
            /.../
        }
    }
}
```

These members will be removed from the session by the MPSD once the `reservedRemovalTimeout` expires.

## Large Session limitations

MPSD sessions with the large capability enabled support more than 100 players. These sessions function differently than regular sessions, refer to [Using large sessions for Multiplayer](live-large-sessions.md) for more information.

Operations to large sessions are always carried out as a single user. As a result, S2S calls to large sessions must only include a single user in the `X-Xbl-OnBehalfOf-Users` header. Multiple user operations are not supported. Adding/removing users must be performed through individual calls for each user. Such S2S calls must be performed sequentially to avoid lock congestion on the underlying session document. Parallel operations to the same document will result in longer call times and not speed up the total operation time.

S2S call results also do not provide access to the full member list of a large session. Only the member data for the user specified in the call will be returned.

Title services should therefore track the user information for members of large sessions in their own logic and use the MPSD membership to correctly support XR requirements.

### Encounters and Groups

Sessions with the large capabilities do not update the recent player list automatically. Instead other players are added directly to the recent player list trough Encounters and Groups. For details, see [Using large sessions for Multiplayer](live-large-sessions.md).

The following pattern is used for flagging session members as part of an encounter:

```json
{
    "members": {

        "me_{xuid}": {
            "properties": { 
                "system": { 
                    "encounters": [ "{uniqueEncounterID1}", 
                                    "{uniqueEncounterID2}",
                                    // ... //
                                  ] },
        }
    }
}
```

*Example:*

```json
{
     // marking two members as part of the same encounter
    "members": {

        "me_1234567890123456": {
            "properties": {
                "system": {
                    "encounters": [ "757093D8-E41F-49D0-BB13-17A49B20C6B9" ] }},
        },

        "me_2345678901234567": {
            "properties": {
                "system": {
                    "encounters": [ "757093D8-E41F-49D0-BB13-17A49B20C6B9" ] }},
        },
    }
}
```

> [!NOTE]
> To correctly capture an encounter, the encounters property must be written to all participating session members in under 30 seconds. The set of encounters is a point-in-time property, it is immediately consumed and will not be visible in a response.

The following pattern is used for flagging session members as part of a group:

```json
{
    "members": {

        "me_{xuid}": {
            "properties": { 
                "system": { 
                    "groups": [ "{uniqueGroupID1}", 
                                "{uniqueGroupID2}",
                                // ... //
                              ] },
        }
    }
}
```

*Example:*

```json
{
     // marking two members as part of the same group
    "members": {

        "me_1234567890123456": {
            "properties": { 
                "system": { 
                    "groups": [ "group-ADFB431" ] }},
        },

        "me_2345678901234567": {
            "properties": { 
                "system": { 
                    "groups": [ "group-ADFB431" ] }},
        },
    }
}
```

The list of groups is replaced with every write operation. To remove a member from a group, remove the group from the `groups` property list. A write operations with an empty list removes all group memberships.

> [!NOTE]
> The `groups` property is persistent and will be visible in responses for a member.


### Activity Session management

The activity handle of a user determines which session is used for Platform invites and Join-in-Progress. This handle cannot be set through S2S calls and is currently only available through client APIs. A title server can share the session name with a client to enable activity handle creation for a S2S session.

For more information on handles, see:
* The section [Session handles](../../concepts/live-multiplayer-concepts.md#session-handles) in the article "Multiplayer concepts overview"
* The section [MPSD Handles to Sessions](../live-mpsd-overview.md#mpsd-handles-to-sessions) in the article "Multiplayer Session Directory overview"


## Best practices

When performing MPSD S2S calls titles should adhere to the following best practices to avoid issues and improve performance:

* *Merge operations for multiple users*  
  Whenever possible, S2S calls to the MPSD should be performed as batch operations for multiple users. This improves performance and reduces network traffic. An efficient approach to reduce calls is to queue MPSD operations on the title server and merge all requests in 5 second intervals. This provides a balance between efficiency and latency.

* *Merge multiple session & member operations*  
  Titles should ensure to merge user operations as feasible. Adding session members should always be combined with setting all relevant member properties at the same time.

* *Perform S2S calls to the same document sequentially*  
  All calls to the same MPSD document should always be performed sequentially. Performing parallel operations can cause lock congestion of the underling MPSD document and result in slower performance and failed requests.

* *Handle activity handle operations on the client*  
  Activity handles are currently only supported through client APIs. A title service must use a client to create these handles by sharing the session name and using the relevant client APIs.

* *Client session subscriptions and connectivity is not required*  
  For all MPSD sessions that are fully managed through S2S calls, the connectivity capability is not required. For S2S call flows WebSocket connections with the client are not needed. Instead the  title service should fully handle adding/removing session members directly.

* *Large session operations*  
  S2S logic for large sessions must be handled differently than for small sessions as operations with multiple users are not available. Title services should perform all operations to the same session document sequentially, including adding/removing players. For large numbers of members this can result in delays of the member operation. Such delays are acceptable and do not violate platform requirements.

  To simplify member logic for large sessions a title can use the MPSD session to only track player membership and handle all other player data internally. 

  It is simplest to create the large MPSD session for a title server upon server startup even without any players in it. This requires the configuration of the sessionEmptyTimeout in the MPSD session constants as shown in the examples below.

* *Large session join-in-progress/invites*  
  Large sessions support join-in-progress and invites through Xbox Live. For most scenarios it is simpler to use a regular session to support this functionality. This session can be controlled either by the title server or client and should contain information to join the relevant large session.

* *Large session encounters*  
  To ensure encounters in large sessions are captured correctly, all encounters member properties should be written in under 30 seconds. A title service should always attempt to batch updates to the encounters property for all participating members into a single service call. Encounters must use a unique identifier. The use of a GUID is recommended.


## Example S2S Session Template

The following session template is a starting point for a session that is controlled through S2S calls:

```json
{
   "constants": {
        "system": {
            "version": 1,
            // should be set to the maximum supported player number on server
            "maxMembersCount": 50,
            "visibility": "open",
            "inviteProtocol": "game",
            "capabilities": {
                "gameplay": true
            },
            // optional: allows session to linger for 60 minutes when empty
            "sessionEmptyTimeout": 3600
        },
        "custom": {}
    }
}
```


## Example S2S Large Session Template

The following session template is a starting point for a large session with S2S call flow:

```json
{
   "constants": {
        "system": {
            "version": 1,
            // should be set to the maximum supported player number on server
            "maxMembersCount": 5000,
            "visibility": "open",
            "capabilities": {
                "large": true,
                "gameplay": true
            },
            // optional: allows session to linger for 60 minutes when empty
            "sessionEmptyTimeout": 3600
        },
        "custom": {}
    }
}
```