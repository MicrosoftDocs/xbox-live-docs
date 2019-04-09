---
title: Tabs test
description: Tabs test.
author: mikehoffms
ms.author: v-mihof
ms.date: 04/08/2019
ms.topic: article
keywords: windows 10, uwp, games, xbox, xbox live
ms.localizationpriority: medium
---

# Tabs test

  <div class="tabGroup" id="tabgroup_1">
    <ul role="tablist">
      <li role="presentation">
        <a href="#tabpanel_tab1" role="tab" aria-controls="tabpanel_tab1" data-tab="tab1" tabindex="0" aria-selected="true" data-linktype="self-bookmark">Tab 1</a>
      </li>
      <li role="presentation">
        <a href="#tabpanel_tab2" role="tab" aria-controls="tabpanel_tab2" data-tab="tab2" tabindex="-1" data-linktype="self-bookmark">Tab 2</a>
      </li>
    </ul>
    <section id="tabpanel_tab1" role="tabpanel" data-tab="tab1">
      <p>HTML content 1.</p>
```cpp
void CALLBACK XAL_TryResolveUserIssue_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
    XalUserHandle user = reinterpret_cast<XblUserHandle>(asyncBlock->context);

    // TODO: If XAsyncGetStatus fails, tell user to sign in again

    // Close the Reference if one was created during XalUserDuplicateHandle
    if (user) { XalUserCloseHandle(user); }

    delete asyncBlock;
}
```
    </section>
    <section id="tabpanel_tab2" role="tabpanel" data-tab="tab2" aria-hidden="true" hidden="hidden">
      <p>HTML content 2.</p>
<code>
```cpp
void CALLBACK XAL_TryResolveUserIssue_Callback(_In_ XAsyncBlock* asyncBlock)
{
    HRESULT hr = XAsyncGetStatus(asyncBlock, false);
    XalUserHandle user = reinterpret_cast<XblUserHandle>(asyncBlock->context);

    // TODO: If XAsyncGetStatus fails, tell user to sign in again

    // Close the Reference if one was created during XalUserDuplicateHandle
    if (user) { XalUserCloseHandle(user); }

    delete asyncBlock;
}
```
</code>
    </section>
  </div>
