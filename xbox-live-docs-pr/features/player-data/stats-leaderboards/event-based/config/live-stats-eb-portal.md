---
title: Portal configuration of event-based Stats
description: Configuring stat rules at Partner Center. Stat rules control how user events in a game trigger updating of stats on the server.
kindex: Xbox Live stats
kindex: stats, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-stats-eb-portal.html
---

# Portal configuration of event-based Stats

<!-- article from old secure docs portal "Configure Xbox Live stats and stat rules in Windows Dev Center" -->

**Note:** This article describes the features available only with proper permissions. For details, talk to your account manager or another contact at Microsoft.

This article describes the procedures for adding and changing stat rules in the Partner Center service configuration for a title. Player stats are created and updated according to the stat rules triggered when a game sends events to the Xbox Live service.

For an intro to Xbox Live service configuration, see [Xbox Live service configuration](https://docs.microsoft.com/gaming/xbox-live/xbox-live-service-configuration).
For an intro to data platform 2013, see [How the event-based player data platform works](live-how-data-platform-works.md).

Sections in this article:  

   *  [What is a stat rule?](#ID4EMB)  
   *  [Prepare to configure a stat rule](#ID4ENC)
   *  [Create a stat rule](#ID4ELC)
   *  [Change a stat rule](#ID4E2C)  
   *  [Edit a stat rule](#ID4ELE)  
   *  [Copy an existing stat rule](#ID4EMS)
   *  [Delete a stat rule](#ID4EMF)


<a id="ID4EMB"></a>

## What is a stat rule?  

Stat rules are triggered when an event with a particular name is received by the Xbox data platform service. Triggering of a stat rule (by sending an appropriate event) causes the service to create or update one or more player stats.

Player stats are defined by the developer, calculated by the Xbox Live data platform, and stored as name-value pairs on a per-user basis. Here are a few examples of player stats:

*  Total number of zombies killed with a shotgun in hard difficulty
*  Highest number of enemies defeated in a match
*  Fastest time for completing a race
*  Name of the car driven most recently

Player stats can be displayed on the player's game hub UI as featured or hero stats, displayed in leaderboards, and used to unlock achievements.

Individual stat rules can be configured to produce one of the following:  

*  A single instance of a player stat  
*  Multiple instances of a player stat that's based on a stat template  

For info on stats and stat rules, see the following articles in the XDK documentation:

* **User Stats for Data Platform 2013**
* **User Stat Rules**
* **User Stats Scenarios**

The following diagram demonstrates the flow of an event that triggers stat rules that update stat instances:

![Event triggers stat rule to update stat](../../../../../../../resources/gamecore/secure/images/en-us/live/stats/evented/portal/event-stat-rule-instance-template.png)


<a id="ID4ENC"></a>

## Prepare to configure a stat rule

**Prerequisite:** Because stat rules are based on events, you must create an event before you can create a stat rule. See [Portal configuration of events](live-events-portal.md).

1. Sign in with your account on [Partner Center](https://partner.microsoft.com/dashboard/).

   The "Overview" page appears, showing a list of products.

2. Find and select your title.

   The "Game Overview" page appears.

   ![The "Game Overview" page](../../../../../../../resources/gamecore/secure/images/en-us/live/stats/pctr-product2013-gameoverview.png)

3. In the middle navigation column with a white background, click **Xbox Live** to expand it, and then click **Gameplay settings**.

   <!-- 1. Go to **Services** > **Xbox Live**. -->

   <!-- 1. Click the link to **Stat rules**. -->

   The "Gameplay Setting" page appears:

   ![The "Gameplay Setting" page](../../../../../../../resources/gamecore/secure/images/en-us/live/stats/pctr-gameplay-setting-page.png)

4. At the top, click the **Player stats** menu, then click **Stat rules**.
   In this Partner Center UI, "player stats" means event-based User Stats.

   ![The Stat rules menu](../../../../../../../resources/gamecore/secure/images/en-us/live/stats/pctr-stat-rules-menu.png)

   In the "Gameplay Setting" page, the "Events and stat rules" page appears:

   ![The "Events and stat rules" page](../../../../../../../resources/gamecore/secure/images/en-us/live/stats/pctr-events-and-stat-rules-page.png)

   Initially, the table at the bottom is empty and reads "No player stats configured".

5. On the **Events and stat rules** page, configure the events and the stat rules that are based on those events. For details, see the following sections.


<a id="ID4ELC"></a>

## Create a stat rule

**Prerequisite:** Because stat rules are based on events, you must create an event before you can create a stat rule. See [Portal configuration of events](live-events-portal.md).

1. Go to the **Events and stat rules** page, as described in the section above.

2. On an event row, in the **Actions** column on the right, click the **...** button, and then click **New stat rule**.

   ![Selecting an event for which to create a stat rule](../../../../../../../resources/gamecore/secure/images/en-us/live/stats/evented/portal/new-stat-rule-menuitem.png)

   The "Add stat rule" dialog box appears:

   ![The Add stat rule dialog box](../../../../../../../resources/gamecore/secure/images/en-us/live/stats/evented/portal/add-stat-rule-dbox.png)

   *  **Event fields added to the stat rule**  
      - This optional field lets you select fields included in the base event as part of the stat rule. 
      - In the drop-down box, select a field to be added to the stat rule. You can add multiple fields this way. The selected fields will be appended to the stat rule's root name and separated by the dot character.
      - To remove a field, click X next to its name.

   *  **Stat Rule Name**
      Specify a name that characterizes the stat rule and that you'll easily remember and recognize. Names of stat rules are composed of a *root* name, optionally followed by one or more *fields* separated by the dot character. For the naming requirements of stat rule names, see [Overview of event-based Stat rules](live-user-stat-rules.md).

   *  **Operator**
      Select one of the following operators:  

      *  **Sum**
      Increment the existing stat value by the value specified in the **Parameter** field.  

      *  **Min**
      Use the minimum of the existing stat value and the **Parameter** field's value.  

      *  **Max**
      Use the maximum of the existing stat value and the **Parameter** field's value.  

      *  **Replace**
         Replace the stat value with the value specified in the **Parameter** field.  

         We do not recommend using the **Replace** operator for stats that drive achievements: events are not always processed in order, and  this might cause an achievement to never unlock. Instead, use the **SUM** operator.   

   *  **Parameter**  
   Specify the value to be used in the operator selected in the **Operator** field.  

         * If you want to use a static number that you specify, select the **literal** radio button and specify the value in the box below the radio button.  

         * If you want to use the value of a field, select the **field** radio button and, in the drop-down box below the radio button, select the field to be used.  

   * **Restrict other features like achievements and featured stats from accessing this info.**  
   Select this check box to make the stat rule private.

   * **Only allow changes to this stat from a server event. Client events will be ignored.**  
   Select this check box to indicate that the stat rule is triggered only by events sent via the server-to-server API, not from game clients running on the console or PC.

Your new stat rule is now listed on the **Events & Stat Rules** page whenever the rule's event is selected.


<a id="ID4E2C"></a>

## Change an existing stat rule  

> [!IMPORTANT]
> After a title passes Final Certification, existing stat rules for an event in that title can no longer be changed or deleted.  

   1. In the **Stat rules** column on the **Events and stat rules** page for the product instance, click the stat rule you want to change.  

   1. Make the changes in the **Update stat rule** dialog box for the event.

   1. Click **Save**.


<a id="ID4ELE"></a>

## Edit a stat rule

Editing of a stat rule takes place when a stat rule's name or an event field has been removed, added, or reordered.
This operation will be treated as a deletion and creation of a new stat rule. All stat instances will be deleted as part of editing, according to this definition.  


<a id="ID4EMS"></a>

## Copy an existing stat rule  

> [!IMPORTANT]
> After a title passes Final Certification, existing stat rules for an event in that title can no longer be changed or deleted.  

   1. On the **Events and stat rules** page for the product instance, find the row with the stat rule you want to delete.

   2. Click **Copy** in the **Actions** column on that row.

   3. Make the changes in the **Update stat rule** dialog box for the event.

   4. Click **Save**.


<a id="ID4EMF"></a>

## Delete an existing stat rule  

> [!IMPORTANT]
> * After a title passes Final Certification, existing stat rules for an event in that title can no longer be changed or deleted.
>  
> * Deletion of a stat rule is a permanent action and can't be undone or reversed.
>
> * Deleting a stat rule deletes any chained dependencies it might have. Before deleting a stat rule, be sure that you also want to delete all of its dependencies.

   1. On the **Events and stat rules** page for the product instance, find the row with the stat rule you want to delete.

   1. Click **Delete** in the **Actions** column on that row.

   1. Click **Delete** in the **Confirmation** dialog box.

   **Figure:** Deleting a stat event rule deletes any dependencies on that rule

   ![Deleting a stat rule deletes dependencies](../../../../../../../resources/gamecore/secure/images/en-us/live/stats/evented/portal/event_delete_dependency.png)

When you are ready to write code: at Partner Center, publish the product, download the manifest file, and create a header file based on it.
See [Download the Events Manifest file from Partner Center](live-downloading-events-manifest.md).
