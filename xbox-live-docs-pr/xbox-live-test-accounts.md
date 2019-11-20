---
title: Xbox Live test accounts
description: Creating accounts for testing your Xbox Live-enabled game during development.
ms.assetid: e8076233-c93c-4961-86ac-27ec74917ebc
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, test account
ms.localizationpriority: medium
---

# Xbox Live test accounts

When testing functionality in your title during development, it can be helpful to create additional Xbox Live accounts.
For example, you might want a fresh account with no achievements.
Or you might want to make several accounts and make them friends of each other for testing Social scenarios.

It can be time consuming to create multiple Microsoft Accounts (MSA) so an easy way to create many test accounts at once is provided.

Test accounts have some other benefits also.
They can sign into your *Development Sandbox*, whereas a regular MSA cannot due to security restrictions.
See [Xbox Live Sandboxes](xbox-live-sandboxes.md).


## Types of test accounts

There are two options of test accounts.
Regular MSAs that are provisioned to work in your Development Sandbox, or test accounts that only work in a development sandbox.

If you are developing a title with the Creators Program, you may only use Regular MSAs that are provisioned for your Development Sandbox.

Below we will discuss how to create both types.


## Provisioning Regular MSAs

If you have a pre-existing Xbox Live Account, a good starting point would be to provision it for use with your Development Sandbox.

If you do not have an existing Xbox Live Account or require additional MSAs, you can create some at [https://account.microsoft.com/account](https://account.microsoft.com/account).


## Creating Test Accounts

If you are in the Managed Partners Program, then you may also create test accounts exclusively for use in your development sandboxes.
You can also create multiple test accounts at once.

To go to the Test Account management page in Partner Center:
1. Go to [Partner Center](https://partner.microsoft.com/dashboard).
2. Click on the gear icon at the top right to go to Developer settings.
3. Expand Xbox Live
4. Click **Xbox test accounts**.

Screenshot showing where to find this:

![Partner Center screenshot highlighting gear icon and Test Accounts on the account Settings page](images/getting_started/devcenter_testaccount_nav.png)

Once you click on "Xobx test accounts", you will see a summary of any existing test accounts if you have any.
You also have the option to create new test accounts.

![Partner Center test account editing and creation screenshot](images/getting_started/devcenter_testaccount_summary.png)

You can click on "New Test Account" and you will be presented with a form you can use to create test accounts.

![Partner Center new test account dialogue box screenshot](images/getting_started/devcenter_testaccount_new.png)

Any test accounts you create will be prefixed with the name of your development sandbox, and will automatically have access to your development sandbox.

## Exporting Test Accounts

If you are in the Managed Partners Program, then you may also export the test accounts for viewing. 
**Note:** Opening the .csv file without transforming the Xuid column may result in the column giving incorrect Xuid information.

To go to the Test Account management page in Partner Center:
1. Go to [Partner Center](https://partner.microsoft.com/dashboard).
2. Click on the gear icon at the top right to go to Developer Settings.
3. Expand Xbox Live.
4. Click Xbox Test Accounts.
5. Click on **Export all**.
6. Save the .csv file locally.
7. Open a new blank sheet in Excel
8. Click on 'Data'
9. Click 'From Text/CSV' and select the .csv file you saved
10. Click Import
11. Click Transform Data and ensure the Xuid column is of Text data type
12. Close and Load

For additional information on importing or exporting with Excel, see [Import or export text (.txt or .csv) files](https://support.office.com/en-us/article/Import-or-export-text-txt-or-csv-files-5250ac4c-663c-47ce-937b-339e391393ba)
