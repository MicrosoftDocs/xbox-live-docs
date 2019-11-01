---
title: Example code for event-based Leaderboards
description: Code for basic leaderboard display, getting a specified page of results, and skipping to a specified user in the leaderboard.
kindex: Xbox Live Leaderboards
kindex: Leaderboards, Xbox Live
author: v-mihof
ms.author: v-mihof
ms.topic: conceptual
ms.prod: xboxlive
ms.technology: 
permalink: en-us/games/xbox/docs/gxdk/live-eb-leaderboards-apis.html
---

# Example code for event-based Leaderboards

<!-- 
From "Xbox Live" TOC: "Overview of leaderboards" aka "Leaderboards"
https://review.docs.microsoft.com/gaming/xbox-live/leaderboards-and-stats-2017/leaderboards
copied only the "2013" sections
 -->
This article describes how to make your first API calls for Leaderboards.


## Leaderboards APIs

Leaderboards 2013 is the preferred approach.
Leaderboards 2017 is not recommended for new code.

To see all of the Stats Leaderboard APIs, see the `leaderboard_service` namespace.


### Basic leaderboard display

#### C++

The following `get_leaderboard` C++ function is the most basic version of the API.
This returns the leaderboard values for the given leaderboard, starting from the player at the top of the leaderboard.

```cpp
pplx::task<xbox_live_result<leaderboard_result>> get_leaderboard(
        const string_t& scid,
        const string_t& name
        );
```

#### C\#

The following `GetLeaderboardAsync` WinRT C# function gets a leaderboard for a single leaderboard, given a service configuration ID and a leaderboard name.

```csharp
Windows::Foundation::IAsyncOperation< LeaderboardResult^> ^  GetLeaderboardAsync (
        _In_ Platform::String^ serviceConfigurationId,
         _In_ Platform::String^ leaderboardName
        )
```


### Get a specified page of results

#### C++

The following `get_leaderboard` C++ function provides more flexibility; you can specify the rank (position) that you want to display, as well as the maximum number of items to return.
For example, you can use this API to display the leaderboard starting at position 1000.

```cpp
pplx::task<xbox_live_result<leaderboard_result>> get_leaderboard(
    _In_ const string_t& scid,
    _In_ const string_t& name,
    _In_ uint32_t skipToRank,
    _In_ uint32_t maxItems = 0
    );

```

#### C\#

The following `GetLeaderboardAsync` WinRT C# function gets a page of leaderboard results for a single leaderboard, given a service configuration ID and a leaderboard name.
The leaderboard results will start at the "skipToRank" rank.

```csharp
Windows::Foundation::IAsyncOperation< LeaderboardResult^> ^  GetLeaderboardAsync (
         _In_ Platform::String^ serviceConfigurationId,
         _In_ Platform::String^ leaderboardName,
         _In_ uint32 skipToRank,
         _In_ uint32 maxItems
        )
```


### Skip to specified player

#### C++

The following `get_leaderboard_skip_to_xuid` C++ function skips to the specified user in the leaderboard.
A `XUID` is a unique identifier for each Xbox User.
You can obtain the `XUID` for the signed-in user, or any one of their friends, and pass that into this function.

```cpp
pplx::task<xbox_live_result<leaderboard_result>> get_leaderboard_skip_to_xuid(
    _In_ const string_t& scid,
    _In_ const string_t& name,
    _In_ const string_t& skipToXuid = string_t(),
    _In_ uint32_t maxItems = 0
    );

```

#### C\#

The following `GetLeaderboardWithSkipToUserAsync` WinRT C# function gets a leaderboard starting at a specified player, regardless of the player's rank or score, ordered by the player's percentile rank.

```csharp
Windows::Foundation::IAsyncOperation< LeaderboardResult^> ^  GetLeaderboardWithSkipToUserAsync (
         _In_ Platform::String^ serviceConfigurationId,
         _In_ Platform::String^ leaderboardName,
         _In_opt_ Platform::String^ skipToXboxUserId,
         _In_ uint32 maxItems
        )
```


## 2013 C++ Example

When using the C++ API layer, you can then set a callback to be invoked once the Leaderboard results are returned from the service.
An example is shown below.

If you are unfamiliar with the `pplx::task` being returned from these APIs, this is an asynchronous task object from the Microsoft Parallel Programming Library (PPL).
You can learn more about that at [https://github.com/Microsoft/cpprestsdk/wiki/Programming-with-Tasks](https://github.com/Microsoft/cpprestsdk/wiki/Programming-with-Tasks).

The section below shows how you might retrieve Leaderboard results and use them.


### 1. Create an async task to retrieve leaderboard results

The first step is to call the Leaderboard service to retrieve the results for a particular leaderboard.

```cpp
pplx::task<xbox_live_result<leaderboard_result>> asyncTask;
auto& leaderboardService = xboxLiveContext->leaderboard_service();

asyncTask = leaderboardService.get_leaderboard(
             m_liveResources->GetServiceConfigId(), LeaderboardIdEnemyDefeats);
```


### 2. Set up a callback

You can set up a [continuation task](https://msdn.microsoft.com/library/dd492427(v=vs.110).aspx#continuations) to be called once the leaderboard results are returned, as follows:

```cpp
asyncTask.then([this](
  xbox::services::xbox_live_result<xbox::services::leaderboard::leaderboard_result>
                                                                        result)
{
    // Handle result here
});
```

This continuation task is called in the context of the object that originally invoked it, and receives the `leaderboard_result`, which can be displayed in a manner that suits your title.


### 3. Display Leaderboard

The leaderboard data is contained in `leaderboard_result` and the fields are self-explanatory, as follows:

```cpp
auto leaderboard = result.payload();

for (const xbox::services::leaderboard::leaderboard_row& row : leaderboard.rows())
{
    string_t colValues;
    for (auto columnValue : row.column_values())
    {
        colValues = colValues + L" ";
        colValues = colValues + columnValue;
    }
    m_console->Format(L"%18s %8d %14f %10s\n", row.gamertag().c_str(),
                              row.rank(), row.percentile(), colValues.c_str());
}
```


## 2013 WinRT C# Example

When using the WinRT C# layer, you will not need to make a separate callback task, and will simply need to use the `await` keyword when calling the leaderboard service.


### 1. Access the LeaderboardService

The `LeaderboardService` can be retrieved from the `XboxLiveContext` that was created when signing-in a user to the game.
You will need it to call for leaderboard data.

```csharp
XboxLiveContext xboxLiveContext = idManager.xboxLiveContext;
LeaderboardService boardService = xboxLiveContext.LeaderboardService;
```


### 2. Call the LeaderboardService

```csharp
LeaderboardResult boardResult = await boardService.GetLeaderboardAsync(
     xboxLiveConfig.ServiceConfigurationId,
     leaderboardName
     );
```


### 3. Retrieve Leaderboard data

`GetLeaderboardAsync()` returns a `LeaderboardResult` that contains the statistics populating the named leaderboard.

`LeaderboardResult` has several functions and properties to facilitate the reading of leaderboard data.

|Property  |Description  |
|---------|---------|
| `public IAsyncOperation<LeaderboardResult> GetNextAsync(uint maxItems);` | Retrieves the next set of ranks, up to the number of the `maxItems` parameter. This is essentially another call to `GetLeaderboard()`. |
| `public LeaderboardQuery GetNextQuery();` | Retrieves the `LeaderboardQuery` that could be used to make the Leaderboard call to retrieve the next set of data. |
| `public bool HasNext { get; }` | Indicates whether there are more leaderboard rows to retrieve. |
| `public IReadOnlyList<LeaderboardRow> Rows { get; }` | Rows containing leaderboard data per rank. |
| `public IReadOnlyList<LeaderboardColumn> Columns { get; }` | The list of columns that make up the leaderboard. |
| `public uint TotalRowCount { get; }` | The total number of rows in the leaderboard. |
| `public string DisplayName { get; }` | The name to be displayed for the leaderboard. |

Leaderboard data is provided one page at a time.
You may loop through the `LeaderboardResult` Rows and Columns to retrieve the data.
To retrieve subsequent pages of leaderboard data, use the `HasNext` boolean and the `GetNextAsync()` function.

```csharp
if (boardResult != null)
{
    foreach (LeaderboardRow row in boardResult.Rows)
    {
        Debug.Write(string.Format("Rank: {0} | Gamertag: {1} | {2}\n",
                               row.Rank, row.Gamertag, row.Values.ToString()));
    }
}
```
