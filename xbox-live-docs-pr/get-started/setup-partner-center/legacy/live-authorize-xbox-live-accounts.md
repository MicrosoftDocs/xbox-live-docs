---
title: Authorize test accounts, for Creators
description: Authorizing a public Xbox Live account for testing in your development environment.
ms.assetid: 9772b8f1-81db-4c57-a54d-4e9ca9142111
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, accounts, test accounts
ms.localizationpriority: medium
---

# Authorize test accounts, for Creators

This article shows the process of setting up an Xbox Live account with your publisher's test environment.


## Prerequisites

To authorize an Xbox Live test account, you will need the following:

* An [Xbox Live account](https://support.xbox.com/browse/my-account/manage-account/Create%20account)


## Navigate to the Xbox Test Account page

The Xbox Test Account page is located in the **Account Settings** section of Partner Center.

To the **Account Settings** section:

1. In [Partner Center](https://partner.microsoft.com/dashboard/windows/overview), in the upper right of the dashboard, click the settings gear ⚙️, and then click **Developer Settings**.

   A navigation menu appears on the left side of the screen.

2. Click the **Xbox Live** dropdown, then click the **Xbox test accounts** link.

Or:

1. In the Xbox Live Creators configuration page, locate the test section, and then click the link **Authorize Xbox Live accounts for your test environment**.


## Authorize an Xbox Live Account for your test environment

To authorize a new account:

1. In the Xbox test accounts page, all currently authorized accounts are listed. Click the **Add account** button.

![Adding Xbox Live Accounts](live-authorize-xbox-live-accounts-images/add_test_account.png)

   A modal dialog box appears, with one text box where you can enter the desired account’s email address:

![Adding Xbox Live Accounts Modal](live-authorize-xbox-live-accounts-images/add_test_account_modal.png)

2. Click the **Add** button to validate that the email address exists and has an associated Xbox Live Account.

   If the checks pass, the modal dialog box will disappear and you will see the new account in the table indicting it is now successfully authorized for your test environment:

![Adding Xbox Live Accounts Success](live-authorize-xbox-live-accounts-images/add_test_account_success.png)


## Troubleshooting

The email address that was entered in the modal dialog box is run through a few checks, including a lookup to ensure there is an Xbox Live account associated with it.
If any of these checks fail, the account is not added to the table and is therefore not authorized, and you may get a "Sorry, there was an issue adding your email address" error.

A good check if you are having issues is to try and sign in with the account on [Xbox.com](https://www.xbox.com/live/). If you can’t sign in then the account is not an Xbox Live account.
