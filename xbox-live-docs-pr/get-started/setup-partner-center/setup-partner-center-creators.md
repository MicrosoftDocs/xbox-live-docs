---
title: Setting up a game at Partner Center, for Creators
description: Get started adding Xbox Live functionality to your game, by setting up an app at Partner Center.
ms.date: 02/08/2019
ms.topic: article
keywords: xbox live, xbox, games, xbox one, sign-in
ms.localizationpriority: medium
---
# Setting up a game at Partner Center, for Creators

<!--
todo:
o  Open a different browser, go to partner center, create a Creators app, see if after 5 minutes, on the "Submission #" page:
   o  The "Xbox Live Creators Program" section is available
   o  The "Submissions: Submission #: Xbox Live Creators Program" left-nav item is present.
   Both of those UI items load the "Xbox Live Creators Program" page.
o  Misc "todo" questions.
-->

To add Xbox Live functionality to your game, start by setting up an app in Partner Center, by following the steps below.


## Prerequisite: Become a Creator

   > [!IMPORTANT]
   > Prerequisite steps for Creators:
   > Create a Dev Account (also called a Partner Center account).
   > To create a Dev Account, see <a href="https://docs.microsoft.com/partner-center/mpn-create-a-partner-center-account" target="_blank">Create a Partner Center account</a> at the Partner Center documentation site.
   > Follow the instructions at that site.


<!--===========================================================-->
## 1. Create a new app

At Partner Center, create a new app representing your game, as follows.

1. Go to <a href="https://partner.microsoft.com/dashboard/" target="_blank">Partner Center</a>.

   The Partner Center dashboard appears, showing the "Overview" page, within the "WINDOWS" section.

   !["Overview" page at Partner Center](images/pc_overview_pg.png)

2. Click the **Create a new app** button.

   The page "Create your app by reserving a name" appears.

   ![The "Create your app by reserving a name" page](images/pc_createappreservename_no_opts.png)

3. In the text box, enter the name of your product.
   You can change the name later.

4. If you see option buttons **Create this product in a sandbox** and **Do not create this product in a sandbox**, you must select the option button **Do not create this product in a sandbox**.

5. Click the **Reserve product name** button.

   The "App overview" page appears.

   ![The "App overview" page](images/pc_app_overview01_pg.png)

6. Click the **Start your submission** button.

   After a delay, the "Submission #" page appears, showing the submission number; for example, "Submission 1".

   ![The "Submission #" page before setting the Category to "Games"](images/pc_cr_initl_submission_pg.png)

   In the "Xbox Live Creators Program" section of the page, the message appears:
   "To enable Xbox Live Creators Program, the product's category (on the Properties page) must be Games."

   Your app has now been created at Partner Center and is awaiting being Xbox Live-enabled.


<!--===========================================================-->
## 2. Enable Xbox Live for the game

<!-- todo: closing browser will cause to lose their place in this doc. tell how to return here. -->

1. In the "Submission #" page, click the **Properties** section.

   The "Properties" page appears.

   ![The "Properties" page before setting the Category to "Games"](images/pc_cr_initl_properties_pg.png)

2. In the **Category and subcategory** section, in the **Pick a category** drop-down list, select the **Games** category.

   > [!IMPORTANT]
   > Do not select a category other than Games, or else the "Xbox Live" options won't be available.

   Because you selected Games, the "Genre(s) section appears.

   !["Genre(s)" section of "Properties" page](images/pc_creators_submission_num_pg_games_cat.png)

3. In the **Genre(s)** section, select one or more check boxes.

   <!-- todo: update the below steps-->
   Skip the other fields for now.

4. Scroll down to the bottom of the page, and click the **Save** button.

   The "Submission #" page reappears, and the "Xbox Live Creators Program" section of the page is now available.

   !["Xbox Live Creators Program" section of "Submission #" page](images/pc_cr_2nd_submission_pg.png)

5. Click the **Xbox Live Creators Program** section in the page.

   The "Enable Xbox Live Creators Program" page appears, the first time through this process for a new game.

   ![The "Enable Xbox Live Creators Program" page](images/pc_cr_enablexblcrpgm_pg.png)

6. Click the **Enable** button.

   The "Setup" dialog box appears.

   ![The "Setup" dialog box](images/pc_cr_setup_dbx.png)

7. In the **Xbox Live game name** text box, enter the name of your game.
   This can be the same as the name of the app you specified at the beginning, but it doesn't need to be the same.

8. Select the platforms that you would like to enable the Xbox Live Services for.
   Both **Xbox One** and **Desktop** are selected by default.

8. Click the **Confirm** button.

   Below the Confirm button, the message temporarily appears:
   "Your product is being Xbox Live enabled. This may take a few minutes."

   Then the "Xbox Live Creators Program" page appears, with the message at the top "Please ensure to publish your changes to Xbox Live before you can upload files to global storage."

   <!-- status: todo: blur the Title ID value, the SCID value, the Sandbox ID value -->
   ![The "Xbox Live Creators Program" page](images/pc_cr_xbl_creators_pgm_pg.png)

You've now completed the initial setup of your game.
Your game cannot be tested yet; you need to publish the game first.
To do this, you take the identity information that was generated above, and push that information into the Xbox Live runtime system, as follows.


<!--===========================================================-->
## 3. Publish the game


### Create an Xbox account for testing

1. If you don't have an Xbox account that you want to use for testing, create one.
   To create an Xbox account for testing, see <a href="https://www.xbox.com" target="_blank">Xbox.com</a>.

2. Click **Sign in**.

   The "Sign in" dialog box appears.

3. Click the "Create one!" link.

   Note the new email address and password.


### Go to the "Xbox Live Creators Program" page

In Partner Center, if you are not already at the "Xbox Live Creators Program" page for your game, go there as follows.

1. On the left, click **Products**, then under Products, click your game.

   The "App overview" page appears.

2. In the **Submissions** section of the page, click an item, such as **Submission 1**.

   The "Submission #" page appears. To the left, "Submissions: Submission #" is highlighted.

3. Click the **Xbox Live Creators Program** section.

   The "Xbox Live Creators Program" page appears.

   <!-- status: todo: blur the Title ID value, the SCID value, the Sandbox ID value (per above for this image file) -->
   ![The "Xbox Live Creators Program" page](images/pc_cr_xbl_creators_pgm_pg.png)


### Publish the game using the Test button

1. In the "Xbox Live Creators Program" page, scroll down to the **Test** section.

   <!-- status: todo: cleanup sandbox name -->
   ![The "Test" section of the "Xbox Live Creators Program" page](images/pc_cr_xblcrpgm_test_secn.png)

2. Click the **Authorize Xbox Live accounts** link.

   The "Manage Accounts" page appears.

   ![The "Manage Accounts" page](images/pc_creators_manageaccounts_pg.png)

3. Click the **Add account** button.

   The "Please enter an Xbox Live email address" dialog box appears.

   ![The "Please enter an Xbox Live email address" dialog box](images/pc_creators_enteremail_dbx.png)

4. In Partner Center, in the "Please enter an Xbox Live email address" dialog box, in the text box, enter your Xbox Live email address to use for testing.

5. Click the **Add** button.

   The "Manage Accounts" page reappears, now showing the added email address.  <!--todo: confirm-->

   Go to the "Xbox Live Creators Program" page: Test section: Test button, as follows.

6. Click the app name in the top of the left-nav bar, or elsewhere in the user interface.

   The "App overview" page appears.

7. Click "Submission #".

    The "Submission #" page appears.

8. Click the section **Xbox Live Creators Program**.

    The "Xbox Live Creators Program" page appears.

9. Scroll down to the "Test" section.

   <!-- status: todo: cleanup sandbox name (this is a copy of above) -->
   ![The "Test" section of the "Xbox Live Creators Program" page](images/pc_cr_xblcrpgm_test_secn.png)

10. Click the **Test** button.

   <!-- status: todo: cleanup sandbox name (copy of above img file) -->
   ![The "Test" section of "Xbox Live Creators Program" page](images/pc_cr_xblcrpgm_test_secn.png)

   Below the Test button, the message "Publishing" appears, and then "Success" appears.

   > [!IMPORTANT]
   > Though the UI says "Success", the Xbox Live servers can take as long as 30 minutes to replicate the new info.

Your game is now set up at Partner Center.
The SDK can now be used in an application to sign-in.


<!--===========================================================-->
## Next step

After your game is set up at Partner Center, continue with step 2: set up an IDE with the Xbox Live SDK, for your target platforms.
See [Getting started](index.md).


<!--===========================================================-->
## See also

[Partner Center Xbox Live configuration Summary page](../../configure-xbl/dev-center/summary.md)
