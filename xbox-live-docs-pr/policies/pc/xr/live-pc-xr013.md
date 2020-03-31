---
title: "XR-013: Linking Microsoft Accounts with Publisher Accounts"
description: On Xbox One, titles that use partner-hosted services or accounts that require credentials must link that account with the user's Microsoft account.
kindex: "XR-013: Linking Microsoft Accounts with Publisher Accounts"
kindex: policies
ms.topic: article
ms.localizationpriority: medium
ms.date: 03/18/2019
---

# XR-013: Linking Microsoft Accounts with Publisher Accounts

On Xbox One consoles, titles that use partner-hosted services or accounts that require credentials must link that account with the user's Microsoft account.  

Outside of Xbox One, titles can choose to allow account linking to support their game experience.  

If account linking is enabled within the title, the following rules apply:

* Users must be notified of the account linking and given the choice to opt-out.

* If any account linking or access to partner hosted services is enabled, it must be made available to all users/account types.

* Linked accounts must be authenticated prior to linking.

* Users must be provided all applicable terms of use, privacy and other policies within the title (or a notice with a link to such information) both during the linking process and for as long as the accounts are linked.

* Users must have the ability to de-link accounts.


## More Information


### Account authentication

Titles performing account linking or account creation on the console must follow secure authentication procedures. Authentication can happen within the title or a partner website, or it can happen independently using a token to link authenticated accounts.


### Accommodate all users

Titles must accommodate account linking for all users if a linked account is required for gameplay. Publishers are responsible for ensuring the link to their service is handled in a manner that is compliant with the Children's Online Privacy Protection Act (COPPA) for titles shipping in the US.


### Unlinking

Users must have the ability to unlink publisher or service accounts from their Microsoft account. Linked Account Management is permitted in title, on the web, or in a third-party experience.


### Single sign-on

Titles must implement single sign-on with any device after an account link has been made for a user.


### Intent

Ensure that users have a consistent and safe experience when linking their Microsoft account to a publisher or service account.


## Recommended Test Cases


### 013-01 Linking Microsoft Accounts with Publisher Accounts


#### Test Steps

1. Verify that the title supports or requires non-Xbox accounts or login for services or functionality.

2. Using a newly created Xbox profile, use the publisher provided service account or login to enter non-Xbox account credentials during initial setup.

3. Verify the title allows the user to view the terms of use in the app, or informs the user how to view the terms of use, prior to completing the account linking process.

4. Verify that the user is not prompted to reenter his or her non-Xbox account credentials in any location.

5. Sign out and sign back in while the title is running.

6. Repeat Step [4].

7. Terminate and reactivate the title using the same profile.

8. Repeat Step [4].

9. Terminate the title.

10. Verify that the title does not store non-Xbox account credentials locally by deleting any saved files that may have been created by the title.

11. Reactivate the title and repeat Step [4].

12. On a different console, launch the title using the same profile and repeat Step [4].

13. Verify the title provides a method to view the terms of use while the accounts are linked.

14. Verify the user is able to unlink their Xbox profile from the non-Xbox account.  


#### Expected Result

The user should only have to provide his or her credentials once and allows the user to view the terms of use, or informs the user how to view the terms of use, prior to completing the account linking process. Users are provided with a mechanism to unlink their Xbox profile from their non-Xbox account.  


#### Pass Examples

1. The title never asks the user to reenter his or her non-Xbox account or login credentials at any point after he or she has initially entered them and the title provides a notification of the terms of use both during the linking process and for as long as the accounts are linked.  

#### Fail Examples

1. The title requires the user to enter his or her non-Xbox account or login credentials every time the title is launched.

2. The title requires the user to enter his or her non-Xbox account or login credentials when running the title from another console.

3. The title does not provide a method for viewing the terms of use during the account linking process.

4. The title does not provide a method for viewing the terms of use after the accounts are linked.

5. The title does not provide a method for unlinking their Xbox profile from their non-Xbox account.  
