---
title: Event-based Achievements portal config
description: Adding and changing achievements.
kindex: Event-based Achievements portal config
kindex: Achievements
kindex: Xbox Live, Achievements
author: v-andrg
ms.author: v-andrg
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: "en-us/games/xbox/docs/gxdk/live-achievements-eb-config.html"
---

# Event-based Achievements portal config

>![](../../../../../images/common/note.gif) **NOTE:** If your title is currently using event-based Achievements (formerly called Achievements 2013), and you want to enable support between multiple platforms going forward, you must continue using event-based Achievements. This is required, for the user to retain their Achievements across all the platforms.

>![](../../../../../images/common/note.gif) **NOTE:** This article describes the features available only with proper permissions. For details, talk to your account manager or another contact at Microsoft.

This article describes how to use event-based Achievements to add and change achievements in the Partner Center service configuration for a title. Achievements are unlocked according to the logic you define in the service configuration. This logic is based on the values of player stats in the service, and when the player stats meet the specific requirements for an achievement, it's unlocked automatically.

For an intro to the Xbox Live service configuration, see [Xbox Live service configuration](https://docs.microsoft.com/gaming/xbox-live/xbox-live-service-configuration).
For an intro to the event-based data platform, see [How event-based Stats, Achievements, and Leaderboards work](../../../stats-leaderboards/event-based/live-how-data-platform-works.md).

You can use title-managed Achievements rather than event-based Achievements, even if you use event-based Stats.
Title-managed Achievements provides a simpler configuration experience but does not support challenges, and it requires that titles manage unlocking achievements.

Sections in this article:  

* [How achievements work in Xbox Live for Xbox One](#ID4EYB)  
* [Create an achievement](#ID4EJC)  
* [Change an achievement](#ID4EXC)  
* [Delete an achievement](#ID4E5D)
* [Configure an achievement](#ID4E5L)


<a id="ID4EYB"></a>

## How achievements work in Xbox Live for Xbox One  

An achievement represents a specific goal set for the player by the title's developers.
In the event-based data platform, the service uses the values of specific player stats to determine whether the player has achieved the goal; the values are defined in the service configuration.

For a new player, achievements are *locked*. When the player meets the conditions required to meet an achievement's goal, the service grants the achievement by *unlocking* it. The player receives a reward in the form of Gamerscore, but the title might grant additional rewards, such as art or in-game items.

Achievements can be based on a single player stat or multiple player stats. For example, an achievement might require that a player who has reached the Advanced Level use Orange Arrows to defeat three Blue Dragons in the Western Province.  

Achievements can be hidden from the player until they are achieved, or they can be made visible in a list of possible achievements.  

Planning the events and stat rules needed to unlock achievements often requires a top-down approach:

1. Decide what achievements and player experiences you want to present in your game.
2. Create the stat rules and events to power those experiences.


<a id="ID4E5L"></a>

## Configure an achievement

1. Sign in with your account on [Partner Center](https://developer.microsoft.com/dashboard/windows/overview).

2. Select your title, and go to **Services** > **Xbox Live**.

2. Click the link to **Achievements**.

1. On the **Achievements** page, create and manage the achievements for your title.



<a id="ID4EJC"></a>
## Create an achievement

1. On the **Achievements** page, click the **New achievement** button. This will take you to the **New achievement** page.

2. In the **Achievement name** field, provide the name to be shown to players. The maximum length of the string is 44 characters.

3. In the **Locked description** field, describe the circumstances under which the achievement will get locked. The maximum length of the string is 100 characters, and it will be shown to users. If the **Secret** option is selected, then this description won't be displayed in the list of achievements.

4. In the **Image icon** field, provide the achievement icon that will serve as the visual representation ("badge") of the achievement. Ensure that the icon is formatted as a PNG file and is 1920x1080 pixels in size. 

    The icon will be visible to users. Xbox will automatically scale it to a thumbnail size when a user is viewing the list of the achievements, but selecting any individual achievement will set the icon as the background image. If the **Hidden** check box is selected, then the icon won't be displayed in the list until the user unlocks it.

    While developing your title, you can click **use placeholder image** to use a default Xbox icon until your final art is ready to replace it.

5. Under **What type of achievement is this?**, select from the following options:

    * **Base achievement**  
        The achievement will be available to players when the game is initially released.  

    * **Non-base achievement**  
        The achievement won't be available to players until after the game is launched.

6. In the **Gamerscore** field, indicate the amount of Gamerscore to be awarded when an achievement is unlocked. Specify a value greater than 0 and less than or equal to 200. Your title has a total of 1000 Gamerscore points that you can allocate among the base achievements.

7. Under **How should the details be treated?**, select from the following options:

    * **Public**  
    The achievement and its details will be visible to all players.  

    * **Secret**  
    The achievement and its details will be visible only to players who have unlocked the achievement. This is useful for avoiding plot spoilers and rewarding players for experimenting.


8. Optional: In the **Achievement deep link** field, specify the in-game location to which players will be redirected to attempt the achievement immediately. For example, in `ms-xbl-11aa99ff://default?trackId=18`, `11aa99ff` is the TitleId and `default?trackId=18` is the code that your game will understand and use to redirect players to the desired location in the game.

9.  Select an **Unlock logic** that will determine how an achievement will be unlocked:

    * **Do something with incremental progress**  
    Select a single player stat. When the player stat meets the specified criteria, the achievement will be unlocked. Players will be able to see their progress towards unlocking of the achievement.  
    
        To meet the criteria, a stat must be equal to or greater than the specified value. This does not apply to a stat configured with the **min** operator; such a stat must be less than or equal to the specified value.

    * **Do multiple things, cumulatively**  
    Select multiple player stats configured with the **sum** operator. When all the player stats you selected meet the specified criteria, the achievement will be unlocked.

    * **Min/max one of several things**  
    Select multiple player stats that have been configured with the **max** or **min** operator. When at least one player stat requirement is met, the achievement will be unlocked.

    * **Do something once**  
    Select a player stat. When its instance is created as a result of triggering of a stat rule, the achievement will be unlocked.

    * **Custom logic**  
        To create a complex condition for unlocking the achievement, click the **Add stat** button and add a stat condition to the current condition. To add a new condition clause, click the **Add condition** button. 
        
         * All stats in a single condition clause must be of the same operator type and must meet the same criteria for satisfying the condition.
         * If the stats use the **min** or **max** operator, the clause uses the OR logic to meet the condition. 
         * If the stats use the **sum** operator, the clause uses the AND logic to meet the condition.  
                
        When all conditions are met, the achievement will be unlocked.


10. Optional: To grant an additional reward (art or in-game) for unlocking the achievement, do the following:

    1. Click the **Add reward** button.

    2. On the **Achievement rewards** page, select **Art** or **In-game**.

    3. In the **Display name** field, provide the reward's name to be shown to players.

    4. In the **Description** field, provide the reward's description to be shown to players. The description can't be longer than 90 characters and should include details such as the reward's duration (if applicable) and instructions for redeeming the reward. 
   
    5. Perform the following according to the reward type you selected:  

        * If you selected the reward type **Art**, then use the **Art** field to specify the art reward that the player will get upon unlocking the achievement. The reward must be 1920x1080 pixels in size and formatted as a PNG file. While developing your title, you can click **use placeholder image** to use a default Xbox image until your final art is ready to replace it.

        * If you selected the reward type **In-game**, then:
          
          1. Use the **Image** field to specify an image that represents the reward that the player will get upon unlocking the achievement. While developing your title, you can click **use placeholder image** to use a default Xbox image until your final art is ready to replace it.
          
          2. Use the **In-game value** field to specify a value or code passed to your game. Ensure that your game can use this code to unlock a reward.

    1. Click **Add** to add the reward to the achievement, or click **Cancel** to cancel and return to the **New achievement** page.

1.  Click **Save** to save the achievement, or click **Cancel** to cancel and return to the **Achievements** page.


<a id="ID4EXC"></a>

## Change an achievement  

> [!IMPORTANT]
> After a title passes Final Certification, existing achievements in that title can no longer be changed or deleted.

1. In the list of achievements on the **Achievements** page, click the **Achievement name** for the achievement you want to change. This will open a page whose title is the name of the achievement. 

2. Make the changes to the achievement.   

3. Click **Save** to save the achievement, or click **Cancel** to cancel and return to the **Achievements** page.


<a id="ID4E5D"></a>

## Delete an achievement  

> [!IMPORTANT]
> After a title passes Final Certification, existing achievements in that title can no longer be changed or deleted.  


1. In the list of achievements on the **Achievements** page, click **Delete** next to the achievement you want to remove.

2. In the **Confirmation** dialog, click **Delete** or **Cancel**.
