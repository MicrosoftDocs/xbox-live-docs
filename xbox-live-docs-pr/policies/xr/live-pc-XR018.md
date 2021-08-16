---
title: XR-018 User-Generated Content
author: mwester
ms.topic: conceptual
description: TBD
---

# XR-018: User Generated Content \* 

Version 1.4, 7/1/2021

User generated content is content that users contribute to an app or product and can be viewed or accessed by other users in an online state. If your product contains UGC, you must: 

* Publish and make available to users a product terms of service and/or content guidelines for User Generated Content either in game or on a title’s website 
* Provide a means for users to report inappropriate or harmful content within the product to the developer for review and removal/disablement if in violation of content guidelines and/or implement a method for proactive detection of inappropriate or harmful UGC (for example, text filtering) 
* Titles must remove/disable UGC when requested by Microsoft 
* Gracefully handle scenarios in which a user does not have access to UGC in game 
* Titles integrated with 3rd party mod platforms must integrate with the product’s report / complaint API if available and must moderate content if required by respective 3rd party contracts 
* Titles integrated with 3rd party mod platforms must present a disclaimer, dialog, or visual cue to users if the content is not sourced from the developer 

## More Information

### User Generated Content (UGC) 

For the purposes of this XR, the term user generated content (UGC) *refers to any in-game digital content produced by a player and then shared by a player with one or more other people, or otherwise made available through a title, in an online state*. Note that in this context, ‘sharing’ simply means that the content is visible to or accessible by another person; it doesn't necessarily require an action on the part of the player. 

Game modifications (aka mods) are also considered UGC. Mods that are in scope are supported by developer-controlled distribution methods, such as the developer’s store or a designated upload and share area controlled by the developer, mods created and shared via in-game experiences, and mods enabled through 3rd party mod platforms requiring moderation by the developer.

At a high level, UGC can include (but is not limited to):  

* Player-customizable text fields, for example: player nicknames and bio info, character names, weapon names, clan tags, and text posted on signs/boards
* Player-created or uploaded images, videos, and GIFs
* Player-created maps, terrains, worlds, player emblems, textures, models, assets, liveries, skins, drawings, sounds, and character behaviors: emotes, animated gestures or actions, body part physics 
* Player-created in-game photos, videos, and GIFs (excludes content uploaded to the Xbox Network, e.g. Xbox Screenshots and Game clips)
  * Note – titles that implement in-game capture features with limited editing capabilities or player customization (e.g. photo filters, cropping, resizing, etc.) and are less likely to produce objectionable content may qualify for exemption 

Examples of what is not considered UGC: 

* Prefabricated in-game player responses governed by the developer (e.g. “Hi”, “GG”)
* Player avatar emotes designed by the developer
* Recordings or ‘ghosts’ of a player’s game activity
* Scenarios where players can minimally customize developer created and vetted content within strictly established parameters
  * For example, players changing the color or size of a player emblem is not UGC. *However*, allowing players to layer multiple emblems could result in an unintended outcome and is considered UGC. 

### UGC as a Core Gameplay Mechanic 

Titles that leverage UGC as its core gameplay mechanic must comply with this XR. Be sure to examine what qualifies as UGC and what scenarios are exempt in the respective sections of this XR. Examples of such games include but are not limited to: 

* Sandbox games that allow for customizable worlds 
* Drawing games 
* Games that require text entry from players that is unfiltered 

### Proactive Detection of Harmful or Inappropriate Text 

Titles that use the [StringService](https://docs.microsoft.com/dotnet/api/microsoft.xbox.services.system.stringservice?view=xboxlive-dotnet-2017.11.20171204.01&preserve-view=true) API meet the proactive detection requirement (for text scenarios) automatically. Titles should default to leveraging the StringService API, but if there are technical or other limiting circumstances, titles can choose to implement their own variant of text filtering by restricting a set of terms from being displayed to another player on Xbox services. See the [list of core words](https://aka.ms/forbidden-terms-games) that must be blocked or obfuscated from non-local players on Xbox services.  

### Terms of Service and/or Content Guidelines

Titles must publish and make available to users a product terms of service and/or content guidelines for User Generated Content either in game or on a title’s website. Developers can reference the [Xbox Community Standards](https://www.xbox.com/legal/community-standards) as an example of such guidelines.

### Additional Related XRs 

There are other XRs that you must comply with when implementing UGC: 

* **Console Games Only** [XR-007 (Cross-Network play, Data Usage, and Companion App Interactions)](https://developer.microsoft.com/games/xbox/partner/xr007): If your title supports cross-network play, ensure the title is compliant with UGC requirements outlined in XR-007 
* [XR-045 (Xbox Network and Account Privileges)](https://developer.microsoft.com/games/xbox/partner/xr045): Ensure proper privilege checks are occurring 

## Exemptions

* UGC created and shared in local/LAN online scenarios, including via a connected companion app, and is not shared to players beyond that local group (couch or living room scenarios)
* UGC created and shared offline which is not uploaded to a service. UGC that originated offline and then is later shared online is not exempt 
* ‘Content’ that is created in a multiplayer or online setting where it is transient in nature, does not produce a UGC artifact (photo, text, custom world or map save file, mods package file, etc.), and the developer did not provide the means to intentionally create and share said content 
  * Examples of exemptions: 
    * Bullet holes (could be used to spell something harmful or offensive) 
    * Placing in-game items in a particular formation (could be used to spell or depict something harmful or offensive)
  * Examples of non-exemptions: 
    * Custom worlds that are shared to other players via the developer’s supported distribution system 
* Player-entered text messaging that is shared real time in-app (such as a lobby or in experience text overlay) is exempt from text filtering
* UGC shared between friends does not require filtration. “Friends” in this case is defined as a two-way relationship between players where both of the following are true:
  * The player who shares the content has previously requested to Follow the recipient of the content, and that recipient has accepted the Follow request. 
  * The player who shares the content has previously received a Follow request from the recipient of the content and has accepted that request.
* Game modifications that are distributed via channels outside of the developer’s control, such as 3rd party websites (e.g. Nexus Mods) or stores (e.g. Steam), unless the 3rd party entity requires moderation through contract agreements 
* Game modifications obtained by players through servers not owned or maintained by the developer 
* Game modifications that alter game mechanics or configuration. For example: player stats, weapon stats, gravity, hitboxes, and weather 
* Game modifications that alter basic game elements. For example, color swaps for textures or changes to character/avatar size. However, extra precautions should be considered with textures that can be applied to characters/avatars, as offensive UGC can be created with simple color swaps, or removal of textures. 

## Implementation Guidance and Best Practices

### General guidance for UGC moderation 

* If the title implements their own variant of text filtering, the publisher should commit to a regular cadence of updating and maintaining their terms list (note that Microsoft’s core word list terms must remain active) 
* Titles that leverage UGC as their core gameplay mechanic (e.g. drawing, sandbox games, etc.) should implement a mechanism for players to capture screenshots for evidence associated with reports 
* Titles that implement in-game capture features (e.g. photos and videos) without editing and customization capabilities should deeply consider if objectionable content may be created and requires moderation 
* Players should be provided with categorical options (e.g. player emblem, clan tag, map, etc.) as to why they are reporting the UGC and should also have an option to provide more context via a text field 
* If UGC is removed/disabled and it is not the original source content (shared and duplicated), steps should be taken to remove the origin UGC 
* Players should receive a notification that their UGC report was successfully received 
* If a player’s UGC is removed/disabled, a reason behind the removal should be provided to them 
* The title or title’s website should have a link to its takedown process for copyright material 
* When a player reports UGC they should no longer see that content on their devices and are given an option to block all content from that creator 
* UGC reporting and moderation requires fundamental attributes to make UGC actionable. The minimum data for successful moderation generally consists of:  
  * Unique Target User ID 
  * UGC report type (player nickname, player emblem, texture, etc.) 
  * UGC evidence (text, image, in-game metadata, etc.) 
  * Date and time of report 
  * Comments (more info) from report submitter 
  * Origin location of report (web page, in-game view) 
* Titles are empowered to implement systems that enable mitigations for repeat or egregious offenders, such as suspending a player’s UGC sharing capability, and informing them why they cannot share UGC 
* For repeat or egregious offenders, titles are empowered to implement systems that enable preventative capabilities, such as disallowing UGC sharing on a per user basis 

### Additional guidance for Game Mods 

#### Local disabling of User Generated Content 

* If your game could become unresponsive when using different combinations of User Generated Content you should consider providing a way to disable all User Generated Content at the title screen. This will prevent your game from becoming permanently unplayable. 

#### Device security & Scripting 

**Format** 

* **[Console Games Only]** User Generated Content may not contain standalone executables or be constructed in such a way that an intermediary step (JIT, script compilation etc) would output an executable file. 

**Network access**

* **[Console Games Only]** Mods should not be allowed any type of direct network access. If you would like to make game-internal functions available to User Generated Content (e.g. “auto-join server”), you should reach out to your Microsoft representative for approval before implementation. 

**File system access**

* **[Console Games Only]** Mods should not be allowed any type of direct file system access. Game-internal functions that entail file system access may be available to User Generated Content (e.g “auto-save”), but if they are, you must enforce caps on how often and how much a title can write (see XR-133). 
* **[Console games only]** Mods should be stored in an appropriate location on disk and not be mixed in with system/game locations/files. 

**Peripheral access**

* **[PC/mobile Games Only]** Mods should not be allowed access to HID units (cameras, microphones etc.) without the user first being notified and approval requested and granted. 

#### Malicious software detection

* **[PC/Mobile Games Only]** In order to avoid spread of malware from content creator to player, mods that are created outside of the console should be run through automatic malware detection systems on submission and should not be published before it passes those checks. 

## Additional Resources

## Certification Test Cases

**018-01 Reporting Inappropriate Content and UGC Text-String Verification**   
  
>
>**Test Steps**  
>1. Identify any areas of the title where text can be entered between non Xbox Network friends and is then viewable by users on another device.
>2. Verify the title provides a way to report other users’ inappropriate content to the title or Microsoft.
>3. If there is no way to report inappropriate content, in each area, enter a string, sub string, etc. that is in the published list of banned words.
>* Enter the banned word directly (i.e. "BannedWord").
>* Enter a banned word with another non-banned word separated by a space i.e. ("Good BannedWord").
>4. If the title allows UGC to be created in an offline state, e.g. character names, disconnect the device from the network, enter banned word combinations and reconnect to the network. 
>5. Verify that the inappropriate string is not visible to any other user on another device.
>5. Repeat Steps [3-5] in each language supported by the title and using banned words from the matching locale.  
>
>**Expected Result**  
>The title must provide a way for users to report other users’ inappropriate content; or inappropriate language must either be blocked with an error message, or have the offending words replaced/masked with an inoffensive substitute.  
>
>**Pass Examples**  
> 1. User entered text messaging which is shared real time in game, such as a lobby or in game text overlay, or only between friends is not filtered.  
>2. The title provides a way for users to report other users’ inappropriate content to the title or Microsoft.
>3. The title prevents posting of inappropriate language and notifies the user of the reason the posting failed.
>4. The title replaces any inappropriate terms with alternative words or characters (such as [BLOCKED] or [!$%and£$]).
>5. Offensive strings are visible to users on the local console but are not transmitted to other non-Xbox Network friends beyond the local console.  
>
>**Fail Examples**  
>1. The title does not provide a way for users to report other users’ inappropriate content and allows inappropriate strings to be visible to non-Xbox Live friends on another console.
>2. The title allows the user to circumvent the title's inappropriate content filter by creating UGC in an offline state.    
