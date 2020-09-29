---
title: Multiplayer Activity URIs

description: ' Multiplayer Activity URIs'
ms.date: 9/21/2020
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one
ms.localizationpriority: medium
---
# Multiplayer Activity URIs
 
This section provides detail about the Universal Resource Identifier (URI) addresses and associated Hypertext Transport Protocol (HTTP) methods from Xbox Live Services for the *Multiplayer Activity* system.
 
The domain for these URIs is multiplayeractivity.xboxlive.com.
 
<a id="ID4EPB"></a>

 
## In this section


[/titles/{titleId}/users/{xuid}/activities](swagger-uris/GetActivity.yml)
  
Gets the activity for a user playing a specific title. Uses the GET operation.  
  
[/titles/{titleId}/users/{xuid}/activities](swagger-uris/UpdateActivity.yml)
  
Sets or updates the activity for a user playing a specific title. Uses the PUT operation.  
  
[/titles/{titleId}/users/{xuid}/activities](swagger-uris/DeleteActivity.yml)
  
Deletes the activity for a user playing a specific title. Uses the DELETE operation.  
  
[/titles/{titleId}/activities/query](swagger-uris/ExternalGetActivityBatch.yml)
  
Gets a batch of multiplayer activities for a list of users. Uses the POST operation.  
  
[/titles/{titleId}/recentplayers](swagger-uris/PostUniRecentPlayers.yml)

Appends to or updates a user's list of recent players (unidirectional). Uses the POST operation.  
  
[/titles/{titleId}/recentplayers/server](swagger-uris/PostServerUniRecentPlayers.yml)

Appends to or updates a set of users' lists of recent players (unidirectional). This is essentially a batch API of the client API, for servers. Uses the POST operation.  
  
[/titles/{titleId}/recentplayergroups/server](swagger-uris/PostServerRecentPlayerGroup.yml)

Appends to or updates all users' recent players within a group (bidirectional). Uses the POST operation.  

[/titles/{titleId}/invites](swagger-uris/sendInvite.yml)

Send an invite to an Xbox Live user. Uses the POST operation.  

[/titles/{titleId}/invites/server](swagger-uris/sendServerInvite.yml)

Sends an invite to an Xbox user with the given connection string.  Uses the POST operation.  

<a id="ID4EAC"></a>

##### Parent 

[Universal Resource Identifier (URI) Reference](../atoc-xboxlivews-reference-uris.md)

   