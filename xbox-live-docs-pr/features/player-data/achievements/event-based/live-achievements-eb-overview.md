---
title: Event-based Achievements overview
description: Overview of event-based Achievements.
kindex: Event-based Achievements overview
kindex: Achievements
kindex: Xbox Live, Achievements
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: "en-us/games/xbox/docs/gxdk/live-achievements-eb-overview.html"
---

# Event-based Achievements overview

>![](note.gif) **NOTE:** If your title is currently using event-based Achievements (formerly called Achievements 2013), and you want to enable support between multiple platforms going forward, you must continue using event-based Achievements. This is required, for the user to retain their Achievements across all the platforms.

<!-- # Achievements Design for event-based Achievements -->

In order to help developers and publishers manage their titles as a service, the achievement system for Xbox One is built on top of the Xbox Live event-based Data Platform.

The event-based Data Platform consists of a single event-driven data model and pipeline for title developers to collect usage telemetry and build user experiences based on this data. One of the key value propositions for the Data Platform is a common user statistics taxonomy that supports shared semantics for publishers to obtain deep insights into their players' behavior.

With Xbox One, all achievements will be keyed off of user statistics rather than requiring direct API calls from the title. This was done for two reasons.

First, to empower developers to add achievements after title launch without requiring additional code changes or title updates. If the title is well-instrumented at launch, the developer can add new achievements simply by updating the title's service configuration in the cloud.

Second, to minimize the number of service calls required of the title for the same in-title user behavior. For example, the title might log a single event whose user statistics ultimately contribute to an achievement, a leaderboard, and to business intelligence reports.


### Data pipeline ###

The following steps provide a high-level view of the key stages in using the achievement system:

1. Configuration
  The developer experience of designing, capturing, and publishing the title configuration that informs Xbox LIVE of the pertinent data to process and/or store.

2. Instrumentation
  The actual implementation of event logging by the title such that data is properly encoded and transmitted.

3. Collection
  The title uses the client logging library (CLL) to feed events into the Data Platform, whose services process events to aggregate, correlate, route, and store statistics as appropriate, based on title configuration.

4. Achievement processing
  The service processes incoming changes to statistics to detect when achievement goals are met, to unlock achievements, to alert the appropriate reward system(s), and to store the achievement records, all based on the title configuration.

5. Notifications
  The Achievements service communicates unlock activity to users (via system toast notifications), to titles, to Xbox LIVE clients, and to other Xbox LIVE services to power additional experiences and features.

6. Analytics
  The online reporting and BI platform that publishers use to understand how customers are using their title.


### Key features of the achievement system ###

With Xbox One, Xbox LIVE is greatly expanding the achievement system, which gives title developers more options and control in how they can use achievements to drive user engagement. New features include the following:

* Cloud-triggered unlocks
* Using deeplinks in achievements
* Achievement progression


### Cloud-triggered unlocks ###

On Xbox One, titles no longer make a discrete call to Xbox LIVE to unlock an achievement. Instead, developers & publishers now configure the achievement's unlocking rules on the service configuration in the cloud, and Xbox LIVE handles the processing of those rules in real-time in the cloud. This empowers developers & publishers to add new achievements & challenges after title launch without a title update.


### Challenges (limited-time achievements) ###

With Xbox One, we introduced a type of achievement called a challenge, also known as limited-time achievements. Challenges are time-bound achievements that users can only unlock during a specified time window. They are configured just like achievements—with an icon, unlock rules, and the ability to be hidden—except that they also require that an eligible time window be defined.

When a user completes a challenge, it is stored as an unlocked achievement in the user's achievement history. If a user participated in a challenge, but the challenge did not unlock during the eligible time window, then that record does not persist in the user's achievement history.


### Using deeplinks in achievements ###

The achievement schema provides support for a title to specify a deeplink that appears in the details view of the achievement. The deeplink links to the spot in the game where the achievement can be earned. The format of the link is a string that is passed to the game when it is protocol activated. The title must parse the string to determine where in the game to go. For example, an achievement related to completing a level in the game can include a deeplink in the achievement details that passes a string to the game that tells the game to go to that level.


### Achievement progression ###

On Xbox 360, games occasionally include logic that allowed them to display how close the user is toward unlocking an achievement. On Xbox One, the Xbox Live achievement system facilitates this functionality by providing some data and logic to measure a user's progression toward unlocking an achievement, data that can be leveraged by the title and that will be used by the Xbox One console to display to users even when outside of the game.

The Achievements service provides progression details per achievement rule. If an achievement has multiple requirements that must be met to unlock it, the API response will include progression details for each requirement. If an achievement has one requirement that is based on multiple stats, the API will return a single progression value that is combined across all underlying stats.

* Progression Object
* Scenarios


### Progression Object ###

Querying for a list of user achievements will always return a Progression object, which contains the detailed data about the achievement rule (requirement) and the user's current progression state toward fulfilling that requirement.


#### Progression ####

Member | Type | Nullable | Description
--- | --- | --- | ---
requirements | Requirement[] | No | The rules that must be met to earn the achievement and how far along the user is toward unlocking it.
timeUnlocked | DateTime | Yes | The time when the achievement was unlocked.


#### Requirement ####

Member | Type | Nullable | Description
--- | --- | --- | ---
id | string | No | The ID of the requirement.
current | tring | Yes | The user's current progression value toward the meeting the requirement.
target | string | No | The target value of the requirement that must be met.
operationType | string | No | The achievement rule type.
valueType | string | No | The data type of the requirement's target value.
ruleParticipationType | string | No | The participation type of the rule.
