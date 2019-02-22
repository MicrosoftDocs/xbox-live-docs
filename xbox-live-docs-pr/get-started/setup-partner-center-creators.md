---
title: Setting up a game at Partner Center, for Creators
description: Get started adding Xbox Live functionality to your game, by setting up an app at Partner Center.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Setting up a game at Partner Center, for Creators

<!--todo: open external links in new tab-->

To add Xbox Live functionality to your game, start by setting up an app in Partner Center, by following the steps below.

<!-- greg: Need sep articles for Creators & ID? -->

## Prerequisite: Become a Creator

   > [!IMPORTANT]
   > Prerequisite steps for Creators:
   > Create a Dev Account (also called a Partner Center account).
   > To create a Dev Account, right-click the following link and then click **Open in new window**: [Create a Partner Center account](https://docs.microsoft.com/partner-center/mpn-create-a-partner-center-account).
   > Follow the instructions at that site.


<!--===========================================================-->
## 1. Create a new app

Next, at Partner Center, create a new app, as follows.

1. Right-click the following link and then click **Open in new window**: [Partner Center dashboard](https://partner.microsoft.com/dashboard/).

   The Partner Center dashboard appears, showing the "Overview" page, within the "WINDOWS" section.

   <!-- status: ok -->
   ![](images/pc_overview_pg.png)

2. Click the **Create a new app** button.

   The page "Create your app by reserving a name" appears.

   <!-- status: make new capture w/o option buttons -->
   ![](images/pc_createappreservename.png)

3. In the text box, enter the name of your product.
   You can change the name later.

   Note: If you see option buttons **Create this product in a sandbox** and **Do not create this product in a sandbox**, select **Do not create this product in a sandbox**.

   <!-- status: ok -->
   ![](images/pc_createappreservename02.png)

4. Click the **Reserve product name** button.

   The "App overview" page appears.

   <!-- status: ok -->
   ![](images/pc_app_overview01_pg.png)

5. Click the **Start your submission** button.

   After a delay, the Submission page appears, showing the submission number; for example, "Submission 1".

   Your app has now been created at Partner Center and is awaiting being Xbox Live-enabled.


<!--===========================================================-->
## 3. Enable Xbox Live for the game

<!-- todo: closing browser will cause to lose their place in this doc. tell how to return here. -->

1. In the "Submission #" page, click the **Properties** section.

   The "Properties" page appears.

2. In the **Pick a category** drop-down, select the **Games** category.
   Do not select a category other than Games, or else the "Xbox Live" options won't appear, below.

   Because you selected Games, the "Genre(s) section appear.

   <!-- status: ok -->
   ![](images/pc_creators_submission_num_pg_games_cat.png)

   <!-- status: update the below -->
3. In the **Genre(s)** section, select one or more check boxes, such as "Strategy".

   Skip the other fields for now.

4. Scroll down to the bottom of the page, and click the **Save** button.

   The "Submission #" page reappears, and now includes a "Xbox Live Creators Program" section.

5. Click the "Xbox Live Creators Program" section in the page.

   The "Enable Xbox Live Creators Program" page appears.

   <!-- status: ? -->
   ![](images/pc_creators_enablexbl_pg.png)

6. Click the **Enable** button.

  The "Setup" dialog box appears.

   <!-- status: remove mihof -->
   ![](images/pc_cr_setup_dbx.png)

7. Click the **Confirm** button.

   Below the Confirm button, the message temporarily appears:
   "Your product is being Xbox Live enabled. This may take a few minutes."

   Then the "Xbox Live Creators Program" page appears, with the message "Please ensure to publish your changes to Xbox Live before you can upload files to global storage."

   <!-- status: clean up -->
   ![](images/pc_cr_xbl_creators_pgm_pg)


<!-- the above steps worked, including "Enable".  Below are steps we tried for Creators, to make Xbox Live appear under Services:

5. To the left of the "Submission #" page, click **Services** to expand it, and see whether **Xbox Live** appears within the **Services** options.

   ![](images/pc_creators_submission_num_pg.png)

6. If **Xbox Live** doesn't appear yet, try the following:

7. Try reloading the page in the web browser.

8. Try: In the "Submission #" page, click the Properties section.
   The "Properties" page appears.
   In the "Support info" section, click the **No** option button, and then at the bottom of the page, click the **Save** button.

   Under "Services", "Xbox Live" now appears.


ID STEPS:

9. Under **Services**, click **Xbox Live**.

   The "Enable Xbox Live" page appears, this first time only.

   ![](images/pc_enablexboxlive_pg.png)

2. In the "Xbox Live app name" text box, enter the name of your game.
   You can use the same name as shown at the top of the page, but it doesn't need to be the same.

5. Click the **Enable** button.  

   Below the "Enable" button, a message temporarily appears:
   "Your product is being Xbox Live enabled.  This may take a few minutes."

   After some time, the Xbox Live "Gameplay Setting" page automatically appears.

   ![](images/pc_gameplay_setting_pg.png) -->

You've now completed the initial setup of your game.
Your game cannot be tested yet; you need to publish the game first.
To do this, you take the identity information that was generated above, and push that information into the Xbox Live runtime system, as follows.


<!--===========================================================-->
## 4. Publish the game

In Partner Center, with your game selected as in the above procedures, do the following.

<!-- no Publish link for Creators -->

1. In the top right, click the **Publish** link.

   The "Publish gameplay settings" dialog box appears.

   <!-- status: ok -->
   ![](images/pc_pubgameplaysetgs_dbx.png)

2. Click the **Confirm** button.

   At the bottom of the dialog box, the message appears: "Publishing configuration..." and then "Publishing configuration finished successfully."
   The game is actually published after a delay of possibly 20 minutes.  IMPORTANT: THOUGH THE UI SAYS THE JOB IS COMPLETE, THE XBOX LIVE SERVERS CAN TAKE AS LONG AS 30 MINUTES TO REPLICATE THE NEW INFO.

3. Click the **Close** button.

   The "Publish gameplay settings" dialog box closes, and the "Gameplay Setting" page remains displayed.

The SDK can now be used in an application to sign-in.

Next, find the ID of your game, as follows.


<!--===========================================================-->
## Find your Xbox Live game information

In Partner Center, with your game selected as in the above procedures, do the following.

1. Click **Service**: **Xbox Live**: **Xbox Live Setup**.

   The "Xbox Live configuration" page appears.

   <!-- status: crop to exclude window frame and black left nav column. white-out "greg". blur the 3 numeric strings. -->
   ![](images/pc_xblconfign_pg.png)

2. Copy and save the two Title ID values for later, for use by the SDK.


<!--===========================================================-->
## 5. Create a Test Account

1. In Partner Center, click **Products* on the left: click the product you created.

   The "App overview" page appears.

   <!-- status: ok -->
   ![](images/pc_app_overview_02_pg.png)

2. Click the **Settings** gear in the upper right, then click **Developer settings**.

   The "Account settings" page appears.

   <!-- status: ok -->
   ![](images/pc_account_settings_pg.png)

3. In the **Settings** area in the middle, click **Xbox Live**: **Xbox test accounts**.

   <!-- status: ok -->
   ![](images/pc_account_settings_pg_xblmenu.png)

   The "Manage test accounts" page appears.

   <!-- status: white-out the existing entries, keep table header -->
   ![](images/pc_manage_test_accounts_pg.png)

4. Click the **New test account** button.

   The "New test accounts" page appears.

   <!-- status: white-out alternate email address v-mihof@ms... -->
   ![](images/pc_new_test_accounts_pg.png)

5. In the **Number of accounts to create** text box, enter a number, such as 5.

6. Fill in the **First name** and **Last name** text boxes.
   You can keep the default values "Test" and "Account".

7. In the **Email template** combo box to the left of the hyphen, is shown the sandbox prefix.
   You can keep the value shown.

8. In the email text box to the right of the hyphen, enter the name of your game, without spaces.

9. In the **Password** text box, enter a password.

10. In the **Secret question** drop-down list, select a question.

11. In the **Secret answer** text box, enter an answer for the selected question.

12. In the **Alternate email address** text box, enter an alternate email address.

13. In the **Keywords** text box, you can put your name.

14. Under **These accounts can access:**, there is a check box for each sandbox.
    Select the sandbox which you selected during the **Submission** step above.

15. Click the **Save** button.

    The "Manage test accounts" page appears, showing your new test accounts.
    You can use these acccount email addresses later to sign in with an app, that can access the sandbox.

   <!-- status: white-out "hoffman", white-out "ignore" 2x, white-out rightmost 50% of digits on Gamertag (2x) -->
   ![](images/pc_manage_test_accounts_pg_newaccts.png)

16. Under the **New test account** button, click the **View job history** link.  

    The "Job History" dialog box appears.  

    <!-- status: crop to only show the topmost 2 items -->
   ![](images/pc_job_history_dbx.png)

12. Click the page outside the dialog box.

    The dialog box closes; the "Manage test accounts" page remains displayed.

Your game is now set up at Partner Center.


<!--===========================================================-->
## Next step

After your game is set up at Partner Center, continue with step 2: set up an IDE with the Xbox Live SDK, for your target platforms.
See [Getting started](index.md).


<!--===========================================================-->
## See also

[Partner Center Xbox Live configuration Summary page](../configure-xbl/dev-center/summary.md)
