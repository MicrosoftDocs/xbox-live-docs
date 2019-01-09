---
title: Social Manager memory and performance
description: Memory and performance considerations when using the Social Manager API.
ms.assetid: 2540145e-b8e2-4ab5-9390-65e2c9b19792
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, social manager, people
ms.localizationpriority: medium
---

# Social Manager memory and performance


## Memory

Xbox Live Social Manager now allows its allocated persistent memory to be held in title space.
A custom memory allocator for use by social manager can be specified by calling `xbox_live_services_settings::set_memory_allocation_hooks()`.
This memory allocator hook will may also be used for future large memory allocations that the Xbox Live Services API (XSAPI) uses.

The worst case for memory allocation by Social Manager by default should be around 4.75 MB.
The 4.75 MB comes from = 1000 `xbox_social_user` at 2.43 KB each * 2.
The multiplier of 2 is because Social Manager keeps a double memory buffer.

There is some additional overhead that the Social Manager may allocate based on RTA and HTTP updates.
If creating an `xbox_social_user_group` from list, each added member will take up an additional 2.43 KB.
If a user is added either via the `create_social_social_user_group_from_list`, `update_social_user_group`, or the user adding a friend outside of the title, this may cause a realloc to find contiguous memory space.


## Additional user limits

Social Manager currently has a restriction of 100 added users to the graph.
This is due to two constraints:
1. The maximum number of RTA subscriptions that a user can have is 1100. If a local user has 1000 friends, that only leaves 100 for additional subscriptions.
2. The maximum batch size of users that can be sent to PeopleHub is currently around 100.

Social Manager communicates this by not allowing a social user group from list to contain more than 100 users.
There is a global limit of 100 total additional users that can be in the system at any time via `create_social_user_group_from_list`.


## Processing time

Social Manager will have at worst case 1100 users.
The performance characteristics of Social Manager on a Xbox One has a worst case of 0.3 ms to 0.5 ms for `do_work`, depending on the number of social graphs created.

The typical case is 0.01 ms for with no groups created and up to 0.2 ms for a group with 1000 users in it.
