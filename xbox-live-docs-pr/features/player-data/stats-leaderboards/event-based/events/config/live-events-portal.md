---
title: Portal configuration of events
description: Portal configuration of events.
kindex: Xbox Live events
kindex: events, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-events-portal.html
---

# Portal configuration of events

<!-- 
article copied from secure docs portal "Events (Partner Center)"
# Configure Xbox Live events for data platform 2013 in Partner Center
-->

**Note:** This article only applies if you are using event-based User Stats, not title-managed User Stats.

**Note:** This topic describes the features available only with proper permissions. For details, talk to your account manager or another contact at Microsoft.

This topic describes the procedures for adding and changing events in the Partner Center service configuration for a title. If a title is using event-based Stats, events are the key data sent by the title to the Xbox Live service to update stats and leaderboards and to unlock achievements.

For an intro to the Xbox Live service configuration, see [Xbox Live service configuration](https://docs.microsoft.com/windows/uwp/xbox-live/xbox-live-service-configuration).

<!-- For an intro to data platform 2013, see the XDK topic, **How the Xbox Live data platform 2013 works**. -->


Sections in this topic:

   *  [What is an event?](#ID4EKB)  
   *  [Create an event](#ID4EUB) 
   *  [Configure an event](#ID4EYM)  
   *  [Change an event](#ID4EYE)  
   *  [Copy an event](#ID4EBG)  
   *  [Delete an event](#ID4EBL) 
   *  [Download the Events Manifest file](#ID4ERH)  


<a id="ID4EKB"></a>

## What is an event?  

An event is anything that happens during play and can be *captured*. A player acquiring a weapon is an event, and so is defeating an enemy by using that weapon.  

An event consists of the event name, an event description, and a number of fields that contain event-related data. When a title writes an event, the event is stored on the local device until it can be sent up to the Xbox Live service. The Xbox Live service receives the event and uses it to build and update stats, leaderboards, achievements, and other features of data platform 2013 according to the rules you define in the service configuration.

For details, see [Overview of events](../live-game-events.md).


<a id="ID4EYM"></a>

## Configure an event

1. Sign in with your account on [Partner Center](https://developer.microsoft.com/dashboard/windows/overview).

1. Select your title, and go to **Services** > **Xbox Live**.

1. Click the link to **Stat rules**.

1. On the **Events and stat rules** page, configure the events and the stat rules according to the events.

   <!-- old secure portal: Events and stat rules page ../media/events-and-stat-rules-1.png -->

   ![Events and stat rules page](live-events-portal-images/events-and-stat-rules-1.png)


<a id="ID4EUB"></a>
## Create an event

1. Go to the **Events and stat rules** page, as described in the section above.

1. Click the **New event** button.

   The "Add new event" dialog box appears:

   ![The "Add new event" dialog box](live-events-portal-images/pctr-add-new-event-dbox.png)

1. Specify the values for the following fields:

   * **Base event** - From the drop-down list, select the base event on which you want to build your new event. The selected base event will control the default fields with which your new event will be prepopulated. You can add any other fields but can't remove the default ones.

   ![The Base event list](../../../../../../resources/gamecore/secure/images/en-us/live/stats/pctr-base-event-list.png)

   *  **Event name** - Provide a name that characterizes the event and that you'll easily remember and recognize. The event name doesn't have to match the name of the base event selected for the new event. Event names aren't displayed to the gamer and are internal to the code and game studio. Event names must be unique within a provider namespace:  a single provider can't have two conflicting event names.  

   *  **Description** - Provide a brief description of the event. This text is optional and hidden from the gamer.

   ![The "Add new event" fields filled-in](../../../../../../resources/gamecore/secure/images/en-us/live/stats/pctr-add-new-event-dbox-filled-in.png)

   *  **Event fields**  
      * The fields in this list represent the data that will be captured in connection with the new event.  
      * To add an event field, click **Add Event Field** and specify the **Field** name and **DataType**.
      * There are character limits on the different types of fields:  

         *  Achievement name: 44  
         *  Locked description: 100  
         *  Unlocked description: 100  
         *  Achievement rule name: 44  
         *  In-app reward name: 57  
         *  In-app reward description: 90  
         *  Art reward name: 57  
         *  Art reward description: 90  
         *  Rich presence: 44  
         *  Hero stat name: 44  

   ![Adding an event field](../../../../../../resources/gamecore/secure/images/en-us/live/stats/pctr-add-event-field.png)

1. Click **Save** to create the event and close the dialog box.

   ![new event dialog box](../../../../../../resources/gamecore/secure/images/en-us/live/events/add-event-dialog.png)

Your new event is now listed on the **Events and stat rules** page:

![event added](../../../../../../resources/gamecore/secure/images/en-us/live/events/events-and-stat-rules-2.png)

Now that you have defined an event, you can click the right-hand side of the event row to define a stat rule that uses the event; see [Portal configuration of event-based Stats](live-stats-eb-portal.md).


<a id="ID4EYE"></a>

## Change an event  

> [!IMPORTANT]
> * After a title passes Final Certification, existing events in that title can no longer be changed except to add new event fields.
>
> * It's possible to delete custom event fields but not the default event fields provided automatically when the event was created.

   1. On the **Events and stat rules** page, under **Events**, click the name of the event you want to change.

   1. Make the changes in the **Update event** dialog box.

   1. Click **Save**.


<a id="ID4EBG"></a>
## Copy an event  

You can create a new event by copying an existing event and modifying its info for the new event.

   1. On the **Events and stat rules** page, under **Events**, click **Copy** for the event you want to copy.

   1. Provide the **Event name** for your new event.

   1. Update the description, and add or remove the event fields as needed.

   1. Click **Save** to create the event and close the dialog box.


<a id="ID4EBL"></a>
## Delete an event  

> [!IMPORTANT]
> * After a title passes Final Certification, existing events in that title can no longer be deleted.
>
> * Deleting an event deletes any chained dependencies it might have. Before deleting an event, be sure that you also want to delete all of its dependencies.
>
> * You can delete events while your game is in development but not after it has exited Final Certification&mdash;that is, after you've launched your product.


   1. On the **Events and stat rules** page, under **Events**, click **Delete** for the event you want to delete.

   1. In the **Confirmation** dialog box, click **Delete** or **Cancel**.

 ![delete dependency](../../../../../../resources/gamecore/secure/images/en-us/live/events/event_delete_dependency.png)


<a id="ID4ERH"></a>

## Download the Events Manifest file

After you finish defining and changing your title's events, you must publish them to Xbox Live and download the Events Manifest file, which you need in order to develop your title.  

For info on downloading the Events Manifest file, see [Downloading the Events Manifest file](live-downloading-events-manifest.md).
