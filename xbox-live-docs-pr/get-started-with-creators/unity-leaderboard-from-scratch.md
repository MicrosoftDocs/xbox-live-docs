---
title: Scripting a leaderboard in Unity
description: Building your own Leaderboard UI in Unity.
ms.date: 04/24/2018
ms.topic: get-started-article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, unity, leaderboards
---

# Scripting a leaderboard in Unity

For those of you who want a custom leaderboard experience, this article will give you the tools to implement your own leaderboard by going over the APIs available to Unity developers.

Once you understand how to pull down leaderboard data, you will be able to apply it to the user interface of your choosing.


## Call for Leaderboard data

There are two API calls to retrieve leaderboard data.

- `void GetLeaderboard(XboxLiveUser user, string statName, LeaderboardQuery query)`
- `void GetSocialLeaderboard(XboxLiveUSer user, string statName, string socialGroup, LeaderboardQuery query)`

To successfully make either of these calls return data, do the following steps:
* Acquire an `XboxLiveUser` by [sign-in](../get-started/setup-ide/creators/unity-win10/signin/unity-prefabs-and-sign-in.md).
* Have a [configured stat](add-stats-and-leaderboards-in-unity.md) with value for at least one player.
* Form a `LeaderboardQuery`.

Examples are below.


## Configuring a stat

Once you have an initialized statistic, the easiest way to associate it with your leaderboard script is to include one of the statistic prefabs: `IntegerStat`, `DoubleStat`, or `StringStat` as a public variable.
Your stat will need to have its ID property configured at the very least, because this is what we will use for the **statName** parameter when we call for our leaderboard data.


## Forming a LeaderboardQuery

Finally, you will need to form a `LeaderboardQuery` object.

A `LeaderboardQuery` has a few attributes that can be set which will effect the data returned:

- **SkipResultToRank**: if set, this uint variable will determine what ranking the leaderboard data will start with when returning. Rankings start at rank 1.

- **SkipResultToMe**: if set to true this boolean value will cause the leaderboard data returned to start at the `XboxLiveUser` used in the `GetLeaderboard()` call.

- **Order**: Enums of type `Microsoft.Xbox.Services.Leaderboard.SortOrder` have two possible values, ascending, and descending. Setting this variable for your query will determine the sort order of your leaderboard.

- **MaxItems**: This uint determines the maximum number of rows to return per call to `GetLeaderboard()` or `GetSocialLeaderboard()`.

Forming your leaderboardQuery may look like the following:

```csharp
using Microsoft.Xbox.Services.Leaderboard;

LeaderboardQuery query = new LeaderboardQuery
        {
            SkipResultToRank = 100,
            MaxItems = 5
        };
```

This query would return five rows of the leaderboard starting at the 100th ranked individual.

> [!WARNING]
> Setting SkipResultToRank higher than the number of players contained within the leaderboard will cause the leaderboard data to return with zero rows.


## Call GetLeaderboard()

Now that we have all of the pieces together we can call the `GetLeaderboard(XboxLiveUser user, string statName, LeaderboardQuery query)` function.

The `GetSocialLeaderboard(XboxLiveUSer user, string statName, string socialGroup, LeaderboardQuery query)` function has one extra parameter called socialGroup. This string acts as a relationship filter on the returned data. The acceptable values for socialGroup are as follows:

- "all": Returns a leaderboard filtered to the XboxLiveUser's friends.
- "favorite": Returns a leaderboard filtered to the XboxLiveUser's favorite friends.

You can use the `LeaderboardTypes` enum in the `Microsoft.Xbox.Services.Client` namespace to label your leaderboards socialGroup and then use the `LeaderboardHelper` class function `GetSocialGroupFromLeaderboardType(LeaderboardTypes leaderboardType)` to pull out the appropriate string.

> [!NOTE]
> Passing an empty string for the socialGroup parameter will return the same results as calling the `GetLeaderboard()` function. You will receive an unfiltered *global* leaderboard that shows everyone with a ranking in the leaderboard that has played the game.

```csharp
using Microsoft.Xbox.Services.Leaderboard;
using Microsoft.Xbox.Services.Statistics.Manager;
using Microsoft.Xbox.Services;

public void LoadLeaderboard()
{

    if (this.stat == null)
    {
        // TO DO: Display "Stat not specified" error message!
        return;
    }

    if (this.xboxLiveUser == null)
    {
        if (SignInManager.Instance.GetCurrentNumberOfPlayers() > 0)
        {
            this.xboxLiveUser = SignInManager.Instance.GetPlayer(1);
            this.isLocalUserAdded = true;
        }
        else
        {
            // TO DO: Display "No user signed-in" error message!
            return;
        }
    }

    LeaderboardQuery query = new LeaderboardQuery
    {
        MaxItems = 5,
    };

    XboxLive.Instance.StatsManager.GetLeaderboard(this.xboxLiveUser, this.stat.ID, otherQuery);
}

```

These two leaderboard-retrieving functions return void, and thus do not return the leaderboard data we are looking for.
We will retrieve the leaderboard data in an event function, discussed in the next section.


## Retrieving the Leaderboard data

To retrieve the leaderboard data, you need to add a listening function to the `StatsManagerComponent` instance for your title.
Add the following line of code to the `Awake()` function of your code: `StatsManagerComponent.Instance.GetLeaderboardCompleted += this.MyGetLeaderboardCompletedFunction`.

The `StatsManagerComponent` in the `Microsoft.Xbox.Services.Client` namespace listens for leaderboard completion events.
This line of code adds a function to the list of functions to be called when a leaderboard completion event occurs.

In this example, that function is named `MyGetLeaderBoardCompletedFunction`; you can name the function as you like in your own script.

The function `MyGetLeaderboardCompletedFunction` needs to take two parameters: an object that represents the sender, and a `Microsoft.Xbox.Services.Client.StatEventArgs` parameter.

The shell of your function may look something like this:

```csharp
using Microsoft.Xbox.Services.Client;
using Microsoft.Xbox.Services.Statistics.Manager;

private void GetLeaderboardCompleted(object sender, StatEventArgs statArgs)
    {
        //Do Something;
    }
```


## Checking for errors

The first thing this function should do is check for errors, which can be found in the `StatEventArgs` parameter `statArgs`.
`statArgs` contains a `StatisticEvent` EventData which contains error data.

If there was an error in retrieving the leaderboard data, you can find it in `statArgs.EventData.ErrorCode` or `statArgs.EventData.ErrorMessage`.

If there was no error, the ErrorCode will be 0 and the ErrorMessage will be the empty string, "".

You can add a simple `if` statement to the previous code to check for errors.

```csharp
using Microsoft.Xbox.Services.Client;
using Microsoft.Xbox.Services.Statistics.Manager;

private void GetLeaderboardCompleted(object sender, StatEventArgs statArgs)
    {
        if (statArgs.EventData.ErrorCode != 0) //if there is an error
        {
            // TO DO: Display error message
            return;
        }
    }
```


## Storing the results of the leaderboard request

After confirming that there are no errors, store the results of the leaderboard request, which are found in `statArgs.EventData.EventArgs.Result`. `Result` is a `LeaderBoardResult` object which contains the data you need to populate your leaderboard.

In our example code, we will extract this data and send it to another function called `LoadResult()`:

```csharp
using Microsoft.Xbox.Services.Client;
using Microsoft.Xbox.Services.Statistics.Manager;

private void GetLeaderboardCompleted(object sender, StatEventArgs statArgs)
    {
        if (statArgs.EventData.ErrorCode != 0)
        {
            // TO DO: Display error message
            return;
        }

        LeaderboardResultEventArgs leaderboardArgs = (LeaderboardResultEventArgs)statArgs.EventData.EventArgs;
        this.LoadResult(leaderboardArgs.Result);
    }
```

The `LeaderboardResult` result that we send to the `LoadResult()` function will have all the data we need to both read the leaderboard data that was returned as well as make additional calls to retrieve ranks not yet returned by the original call.

You will want to store the results in a class variable for your leaderboard script like so:

```csharp
using Microsoft.Xbox.Services.Leaderboard;

void LoadResult(LeaderboardResult result)
    {
        this.leaderboardData = result;
    }
```

This is important because the `LeaderboardResult` contains a `HasNext` property that determines whether or not there is a later section of the leaderboard that can be retrieved.
The result also contains a total count of the rows that make up the leaderboard.
These properties will be important to navigating your leaderboard.


## Concatenating LeaderboardRow values into a display string

To pull data from your `LeaderBoardResult`, implement a `for` loop using the `LeaderboardResults` list of `LeaderboardRow` called `Rows`.

In our sample code, we simply concatenate the values in each `LeaderboardRow` into a string to be displayed:


```csharp
using Microsoft.Xbox.Services.Leaderboard

void LoadResult(LeaderboardResult result)
{

    this.leaderboardData = result;

    this.leaderBoardText.text = "" // leaderBoardText is a UnityEngine.UI text box.

    foreach (LeaderboardRow row in this.leaderboardData.Rows)
    {
        leaderBoardText.text += string.Format("Rank: {0} | Gamertag: {1} | {2}:{3}\n\n", row.Rank, row.Gamertag, this.stat.DisplayName, row.Values[0]);
    }
}
```

The above example uses the Rank, Gamertag, and Values properties of LeaderBoardResult to populate the strings, as well as the DisplayName of the stat associated with the leaderboard.

You can implement a creative user experience with all of this leaderboard data.


## Navigating the Leaderboard data

In the most common instances, you will not load every single rank in your leaderboard at once, and will need to be able to navigate the ranks to display different sections of the leaderboard for the user.

Suppose you have a leaderboard with 100 ranked players.
In your initial call to `GetLeaderboard()` or `GetSocialLeaderboard`, you retrieve ten `LeaderboardRows` and display them for the player.

The player may want to see more than the top ten players.
The easiest way to get the next set of ten users is to determine whether or not the `LeaderboardResult` you stored from your last query has more rows to retrieve, and then call `GetLeaderboard()` with that LeaderboardResult's next query.

To use a LeaderBoardResult's *nextQuery* you must use the function `LeaderBoardResult.GetNextQuery()`.

The code to retrieve the next set of ranks would look like the following.

```csharp
using Microsoft.Xbox.Services;
using Microsoft.Xbox.Services.Leaderboard;

void GetNextLeaders()
    {
        if(this.leaderboardData.HasNext)
        {
            LeaderboardQuery query = this.leaderboardData.GetNextQuery();
            XboxLive.Instance.StatsManager.GetLeaderboard(this.xboxLiveUser, this.stat.ID, query);
        }
        else
        {
            //TO DO: Display an error message or go back to the beginning of the leaderboard as the situation demands.
        }
    }
```


## Moving backwards in a leaderboard

Moving backwards in your leaderboard is a little more difficult, because there is no function to pull the previous X number of ranks from your leaderboard.
To retrieve previous rankings, you must write your own logic.

One approach for moving backwards in this leaderboard is to store your `MaxItems` per `LeaderboardQuery` and calculate what rank you need to skip to using the `SkipToRank` attribute of your `LeaderboardQuery`:

```csharp
using Microsoft.Xbox.Services;
using Microsoft.Xbox.Services.Leaderboard;

void GetPreviousLeader()
{
    if(leaderboardData == null || leaderboardData.Rows.Count < 1)
    {
        return;
    }

    uint topRank = leaderboardData.Rows[0].Rank; //get the first rank of the leaderboard.
    uint targetRank = topRank - this.maxItems > 0 ? topRank - this.maxItems : 0; //set your targetRank equal to the current top rank of your leaderboard minus the configured number of rows to display at a time.

    LeaderboardQuery query = new LeaderboardQuery // make a new query with the calculated targetRank
    {
        SkipResultToRank = targetRank,
        MaxItems = this.maxItems
    };

    XboxLive.Instance.StatsManager.GetLeaderboard(this.xboxLiveUser, this.stat.ID, query); // call the GetLeaderboard() function with the new query
}
```

## Showing player's position on the leaderboard

The final most common scenario is that a player may simply want to see their spot on the Leaderboard.
This is achieved by calling the `GetLeaderboard()` function with a query, where the `SkipResultToMe` attribute is set to `true`:

```csharp
using Microsoft.Xbox.Services;
using Microsoft.Xbox.Services.Leaderboard;

    void GetRankForTag()
    {

        LeaderboardQuery query = new LeaderboardQuery // make a new query with the calculated targetRank
        {
            SkipResultToMe = true,
            MaxItems = this.maxItems
        };

        XboxLive.Instance.StatsManager.GetLeaderboard(this.xboxLiveUser, this.stat.ID, query); // call the GetLeaderboard() function with the new query
    }
```


## See also

For a more detailed Leaderboard example, see the `Leaderboard.cs` script in the XboxLive Plugin folder under **Assets >> XboxLive >> Scripts >> Leaderboard.cs**.
