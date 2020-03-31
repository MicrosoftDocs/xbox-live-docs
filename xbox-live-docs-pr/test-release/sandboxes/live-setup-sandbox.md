---
title: Xbox Live Sandboxes overview
description: Publishing a game to a development sandbox, to work on changes to the title in an isolated environment.
kindex: Xbox Live Sandboxes overview
ms.topic: article
ms.assetid: a5acb5bf-dc11-4dff-aa94-6d1f01472d2a
ms.localizationpriority: medium
ms.date: 04/04/2017
---



# Xbox Live Sandboxes overview

Before using Xbox Live services from your game, you must configure information about your title online in <a href="https://partner.microsoft.com/dashboard" target="_blank">Partner Center &#11008;</a>.
This information includes things like the leaderboards your title wants to display, achievements that players can unlock, matchmaking configuration, etc.

When you make changes to your service configuration, these need to be published from Partner Center before the changes are picked up by the rest of Xbox Live and can be seen by your title.

You publish to a *development sandbox*.
Sandboxes allow you to work on changes to your title in an isolated environment.

By default, Xbox One (or later) consoles <!--and Windows 10 PCs--> are in the RETAIL sandbox.

See also [Advanced Xbox Live sandboxes](live-advanced-sandboxes.md).


## Benefits

Development sandboxes offer several benefits:

1. You can iterate on changes to an update for your title without affecting the currently available version.
2. Some tools only work in a development sandbox for security reasons.
3. Some developers on your team may want to "branch" and test service config changes without affecting your primary in-development service configuration.
4. Other publishers cannot see what you are working on without being granted access to your sandbox.

You can also _optionally_ create test accounts.
You can use these if you don't want to use your regular Xbox Live account for testing your title, or you need several accounts to test scenarios such as social interaction (eg: view a friend's stats) or multiplayer.

Test accounts can only sign-in to development sandboxes, and will be explained in a section below.


## Finding out about your Sandbox

The vast majority of developers need only one sandbox.
Fortunately a sandbox is created for you when you create a title.

<!--
The below steps and captures were modified in the chm copy of this article.
Need to specify whether these steps and captures are for Managed Partners or Creators.
-->

1. You find out about your sandbox by going to Partner Center here:
![Partner Center ribbon dashboard location screenshot](live-setup-sandbox-images/first_xbltitle_dashboard.png)

1. Then click on your title:
![Title location in Partner Center menu screenshot](../../images/getting_started/first_xbltitle_dashboard_overview.png)

1. Finally, in the left menu, click **Services** -> **Xbox Live**:
![Xbox Live services in Partner Center menu](live-setup-sandbox-images/first_xbltitle_leftnav.png)

1. You can now see your sandbox listed, as follows:
![Title info in Partner Center. Includes Sandbox ID.](../../images/getting_started/devcenter_sandbox_id.png)


## How your Sandbox impacts your workflow

Typically you work with sandboxes in the following ways:

1. (One-time) Switch your PC or Xbox to your development sandbox.

2. (Many times) As you make changes to your service configuration, you will publish changes to your development sandbox. Service configuration changes are things such as defining achievements, adding leaderboards, or modifying a Multiplayer Session Template.

3. (A few times) If you are working with other team members, you can give them access to your sandbox.

4. (One-time) If you need to test something in RETAIL, or want to take a break to play your favorite Xbox game, you will need to switch your sandbox back to RETAIL.

These scenarios will be described in more detail below.
The process has some differences on PC and Console, so there are separate sections for each.


## Switch your PC's development sandbox

If you want to switch your PC's development sandbox, the recommended way to do so is using Windows Device Portal (WDP).
You may also do so via the Command Line.
Both ways are described below.


### Windows Device Portal

1. If you have not already enabled WDP on your PC, do the steps in section [Set up Device Portal on Windows Desktop](https://docs.microsoft.com/windows/uwp/debug-test-perf/device-portal-desktop#set-up-device-portal-on-windows-desktop) in the article "Device Portal for Windows Desktop" at UWP.

2. Open Windows Dev Portal by connecting to it in your web browser as described in the above article.

3. Click on **Xbox Live** to go the appropriate section as shown below.

   ![Sandbox configuration in Windows Device Portal](../../images/getting_started/wdp_switch_sandbox.png)

4. Enter your sandbox which you got via the steps in the *Finding Out Your Sandbox* and click **Change**.

   To switch back to RETAIL, you can enter "RETAIL" here.


### Xbox Live PC Sandbox Switcher (XBLPCSandbox.exe)

The Xbox Live development tools file (`XboxLiveTools.zip`) contains a command-line tool to switch sandboxes for PC development.
See the section [Xbox Live PC Sandbox Switcher (XBLPCSandbox.exe)](../services-tools/live-tools.md#xpssc) in the article "Development tools for Xbox Live".


## Switch your Xbox console development sandbox


### Using Windows Dev Portal

You can use the Windows Dev Portal to change the sandbox on your console.
To do this, go to "Dev Home" on your console and enable it.

After that you can type in the IP address on the web browser on your PC to connect to your console.
You can then click on "Xbox Live" and enter the sandbox in the textbox there.


### Using Xbox One Manager

Xbox One Manager lets you administer certain aspects of your Xbox One (or later) console from your PC.
This includes rebooting, managing installed apps, and changing your sandbox.

Right click on the console you want to change the sandbox for and go to "Settings..."

You can then enter a sandbox there.


### Using the Xbox console UI

If you want to change your development sandbox right from your Xbox One (or later) console, you can go to "Settings".
Then go to "Developer Settings" and you will see an option to change your sandbox.


## Sandbox uses


### Data that is sandboxed

You can use the sandbox features to manage access between developers on your team during the development process.
For example, you may want to isolate data between your development team and testers.

Sandboxed data includes:

- Achievements, Leaderboards and Stats for a user. Achievements accumulated for a user in one sandbox do not translate to another sandbox.

- Multiplayer and Matchmaking. Users cannot play a multiplayer game with someone is a different sandbox.

- Service configuration. If you add a new achievement to a title in one sandbox, it is not visible in a different sandbox. This applies to all service configuration data.

Non-sandboxed data is predominantly social information.
So for example, if a user follows another user, that relationship is sandbox-agnostic.


### Examples

The below examples show some of the benefits of using multiple sandboxes.

> **Note**: If you are in the Xbox Creators Program, you can only have one sandbox. To create multiple sandboxes, you must be in the Managed Partners Program.


#### Service config isolation

As mentioned above, service configuration is sandbox-specific.
So you might have a *Development* sandbox, and a *Testing* sandbox.
When you give a build of your title to your testers, you would publish your Xbox Live Service Configuration to the *Testing* sandbox.

Then in the meantime, you could add achievements, or different multiplayer session types to your *Development* sandbox without affecting the service configuration that your testers are seeing.


#### Multiplayer

Take the above example with a *Development* and *Testing* sandbox.
Maybe your service configuration is the same between sandboxes, but your developers are creating multiplayer features and want to testing matchmaking with each other.
Your testers are also testing multiplayer.

In a case like this, your developers might not want the Xbox Live Matchmaking service to match them with testers, because they are debugging issues separately.
A good way to prevent this would be for your developers to be in the *Development* sandbox and testers to be in a separate *Testing* sandbox.
This keeps both groups isolated.


#### Broadcasting

To prevent leaking title information accidentally, broadcasting through Mixer is also content-isolated.
Broadcasts are automatically redirected into a development stream that is not accessible by other players.
Titles that need to test specific broadcast functionality can do so through a limited Beta release in a retail scenario.


### See also

* [Advanced Xbox Live sandboxes](live-advanced-sandboxes.md)
