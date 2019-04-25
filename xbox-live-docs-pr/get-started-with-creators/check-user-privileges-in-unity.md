---
title: Checking user privilege settings in Unity
description: Checking user privilege settings in Unity for a signed-in Xbox Live account.
ms.date: 10/26/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, accounts, test accounts, parental controls, user privileges, enforcement bans, upsell
---

# Checking user privilege settings in Unity

On Xbox Live, every authenticated user’s account has associated privileges.
Privileges control which features of Xbox Live a user can access at a given point in time.

Some of these privileges are for system-controlled features, while others may be associated with specific games or extension subscriptions.
In addition, parental controls and bans issued by the Xbox Live enforcement team can restrict the privileges of a user.

These privileges cover a number of common scenarios, including multiplayer, accessing user generated content, chatting, or to streaming video.
Games use this information to make access control and personalization decisions.


## Prerequisites

In order to determine user privilege settings, you must have configured your game for authentication with Xbox Live and successfully signed a user in.

>[!IMPORTANT]
> If you are testing your game in the Unity editor, your game is not connected to the Xbox Live service, and is using fake data to simulate a connection. This results in a null value when you check for privileges. To test with real data, perform a Universal Windows Platform build of your Unity game and open the generated project file in Visual Studio.

The following articles outline the steps that you can take:

* [Sign in to Xbox Live in Unity (build and test sign-in)](unity-prefabs-and-sign-in.md#build-and-test-sign-in)
* [Test your Unity game build in Visual Studio](test-visual-studio-build.md)


## Determine privileges

A user’s privileges are carried in the token received at authentication time.
In Unity, you can access the list of privileges that a user has in the `XboxLiveUser` class, after the user has successfully signed in.

Privileges are stored as a single string, separated by a space.
For example, you might see a user with the following privileges:

```csharp
public XboxLiveUserInfo XboxLiveUser;

//sign in is done and the user has been successfully signed in

Debug.Log(XboxLiveUser.User.Privileges);

//Console would read:
// Privileges: "188 191 192 193 194 195 196 198 199 200 201 203 204 205 206 207 208 211 214 215 216 217 220 224 227 228 235 238 245 247 249 252 254 255"
```

If you want to look for a specific permission, you can check to see if the `Privileges` property contains the associated code:

```csharp
public XboxLiveUserInfo XboxLiveUser;

//sign in is done and the user has been successfully signed in

if (XboxLiveUser.User.Privileges.Contains("247"))
{
    Debug.Log("User has the user_created_content privilege");
}
```

## Privilege codes

See [Privilege codes for Social Manager](../features/social/friends-list/social-manager/privilege-codes.md).
