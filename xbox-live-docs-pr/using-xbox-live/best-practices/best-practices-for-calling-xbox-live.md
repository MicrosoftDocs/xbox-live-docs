---
title: Best practices for calling Xbox Live
description: Best practices for calling Xbox Live APIs, such as proper calling patterns and retry logic.
ms.assetid: f4c7156b-7736-41e5-9b3d-e87cc8dd2531
ms.date: 04/04/2017
ms.topic: article
keywords: xbox live, xbox, games, uwp, windows 10, xbox one, best practices
ms.localizationpriority: medium
---

# Best practices for calling Xbox Live

The Xbox Live services can be called from two primary ways: using the Xbox Services API (XSAPI), or calling the REST endpoints directly.
Regardless of how your code calls Xbox Live, it is important to have proper calling patterns and retry logic.

To understand how to write proper retry logic, it is necessary to know about the two types of REST endpoints - **idempotent** and **non-idempotent**.
These are described below.

 
## Non-idempotent endpoints

HTTP methods that have side effects upon repeat calls are considered to be **non-idempotent**.
This means that if a client were to call the endpoint and a network timeout occurs, it is not safe to retry the method because the resource may have been updated but the network wasn't able to notify the caller that it was successful.

Upon error, instead of retrying, the client must first query to see if the call was successful.
Only if the call was not successful then should it retry.

In the Xbox Services API, some APIs are internally marked as calling non-idempotent endpoints.
This means that if failures occur when calling these endpoints, the APIs will not automatically retry the endpoint.

The full list of non-idempotent APIs are:

* game\_server\_platform\_service::allocate\_cluster()
<br>
* game\_server\_platform\_service::allocate\_cluster\_inline()
<br>
* game\_server\_platform\_service::allocate\_session\_host()
<br>
* matchmaking\_service::create\_match\_ticket()
<br>
* multiplayer\_service::write\_session()
<br>
* multiplayer\_service::write\_session\_by\_handle()
<br>
* multiplayer\_service::send\_invites()
<br>
* reputation\_service::submit\_batch\_reputation\_feedback()
<br>
* reputation\_service::submit\_reputation\_feedback()
 

## Idempotent methods

**Idempotent** HTTP methods on the other hand do not leave side effects.
This in turn means they are safe to be retried.
In the Xbox Services API, all idempotent methods are automatically retried under certain conditions.

The full list of idempotent APIs are all APIs that were not listed above as being non-idempotent.


## Retry logic Best Practices

For idempotent calls, these conditions should be automatically retried:

* All network errors
* 401: Unauthorized
* 408: RequestTimeout
* 429: Too Many Requests
* 500: InternalError
* 502: BadGateway
* 503: ServiceUnavailable
* 504: GatewayTimeout

On UWP, 401: Unauthorized is treated special.
This value indicates the Xbox Live authentication token expired, so the Xbox Services API calls into the OS to refresh the token and then performs as a single retry.

When a retry is performed, it is best practice to not call the service until the "Retry-After" header time has been reached.
XSAPI now implements this best practice.
If a failure HTTP status code and "Retry-After" header was returned for any API, additional calls to that same API before the Retry-After time will immediately return with the original error without hitting the service.

When retrying a call, it is best practice to perform exponential back-off with a random jitter to spread out the load to the service.
XSAPI starts with a default delay of 2 seconds which is controlled using `xbox_live_context_settings::set_http_retry_delay()`.
This means by default each retry does an exponential back-off of 2, 4, 8, etc seconds and it jitters the delay between the current and next back-off value based on the response time to further spread out load across the set of devices attempting the retry.

Titles should be in control of how long to spend retrying a call.
Using XSAPI, developers have direct control of this by using the function `xbox_live_context_settings::set_http_timeout_window()`.
By default, this is set to 20 seconds.
Setting this to 0 seconds will effectively turn off retry logic.


### Dynamic adjustment of the internal HTTP timeout

XSAPI dynamically adjusts the internal HTTP timeout, based on how much time remains in the `http_timeout_window()`.

The internal HTTP timeout controls how long the OS spends doing the HTTP network operation before it aborts.

The call will not be retried unless there remains at least 5 seconds left in the `http_timeout_window()`, to give an enough reasonable time for the call to complete.
This rule doesn't apply to the first call, so setting the `http_timeout_window()` to 0 is acceptable, and will result in a single call.

This logic has the effect that `http_timeout_window()` is more deterministic about when the API call will return.

If a "Retry-After" header was returned, no retries will be made until after the "Retry-After" time has been reached.
If the "Retry-After" time is after the `http_timeout_window()`, then the call return at the end of the `http_timeout_window()`.


## Error handling

Title developers should **always** use proper error handling for **every** service call, they need to ensure that they are handling failed responses properly.
 
There are many real-world conditions that can result in a request to Xbox Live to return failure codes, such as

1. Network is not available. For example, the device lost 4G, lost Wi-Fi, or the network went down.
2.  Too much load on services over load (503).
3.  A failure happened on the service (500).
4.  Too many requests where sent to the service (429).
5.  Write operation conflict (412). For example, another player in a multiplayer session submitted a change first.
6.  The user has been banned or does not have permission.
7.  User has signed-out.

Proper error handler is crucial to ensure that the game functions correctly in these conditions.

XSAPI has two types of error handling patterns:
* One pattern when using the WinRT APIs from C++/CX, C\#, or Javascript
* Another pattern when using the C++ APIs.

For details on best practices of error handling, see [Error handling](../error-handling/error-handling_nav.md).

For a video that covers this, see the talk in [*Xfest 2015 Videos*](https://developer.xboxlive.com/en-us/platform/documentlibrary/events/Pages/Xfest2015.aspx) called *XSAPI: C++, No Exceptions!*


## Best calling patterns


### Use batching requests

Some endpoints support batching or aggregating of a set of requests into a single call.
For example, with the Xbox Live profile service you can ask for a single user's profile or a set of users profiles.

So if you need a user profiles for a set of users, it would be very inefficient to call the endpoint or API one at a time for each user profile.

Each call adds a lot of authentication overhead.
So instead, pass all the users you want information about at once to the API, so that the endpoint can process all the user profiles at the same time and return a single response.


### Use the Real Time Activity (RTA) service instead of polling

A best practice is use the Real-Time Activity (RTA) service instead periodic polling.
The Real-Time Activity service exposes a websocket that sends a notification to clients when target resources change on the service.

The RTA service gives notifications on presence changes, statistic changes, multiplayer session document changes and social relationship changes.

To know what the information client is interested in, the client must first subscribe to the item over the websocket.
This avoids polling the service to detect changes since you will be told exactly when the item changes.

XSAPI exposes the RTA service as a set of subscribe APIs that clients can use.
Each of these APIs have corresponding `*_changed_handler` APIs which take in a callback function that will be called when an item changes.

* `presence_service::subscribe_to_device_presence_change`
<br>
* `presence_service::subscribe_to_title_presence_change`
<br>
* `user_statistics_service::subscribe_to_statistic_change`
<br>
* `social_service::subscribe_to_social_relationship_change`
<br>
 

## Use Xbox Live client-side managers

XSAPI has a set of managers which act as cache and state machines that do all the heavy lifting for certain scenarios.


### Social Manager

The Social Manager does all the heavy lifting around friends lists and profiles.
The Social Manager keeps your friends list, their profiles, and their presence data up to date using the RTA service.

The Social Manager exposes a synchronous API that is very game-engine friendly.
Games can call the Social Manager APIs frequently, because Social Manager maintains an in-memory cache of the latest information from the service.

See [The Social Manager](../../social-platform/social-manager_nav.md).


### Multiplayer Manager

For multiplayer session management, the Multiplayer Manager is a drop-in solution for traditional multiplayer games.
The Multiplayer Manager API includes player roster and session management, handles game invites, join in progress, matchmaking, and plugs into your existing networking solution.
It does all the heavy lifting around implementing traditional multiplayer flows.

See [Multiplayer Manager](../../multiplayer/multiplayer-manager.md).


## Throttling (fine grained rate limiting)

Xbox Live services have throttling in place to prevent any single device from putting extreme load on the service.
It's important to know when your title was throttled.

To determine whether your title was throttled, use any of these approaches:
* Monitoring for HTTP Status Code 429
* Using debug asserts
* Using the Xbox Live Trace Analyzer tool

These approaches are described below.


### Monitoring for HTTP Status Code 429

You can use Fiddler and watch if an HTTP Status Code 429 is returned.
The JSON response will contain detail about how the endpoint was throttled.

For example:

```json
{
  "version":1,
  "currentRequests":13,
  "maxRequests":10,
  "periodInSeconds":120,
  "limitType":"Rate"
}
```

If you are using XSAPI, APIs will return an `http_status_429_too_many_requests` error, and will set the error message to show detail about how the API was throttled.


### Using debug asserts

When using XSAPI, if the call is throttled while in a developer sandbox and using a debug build of the title, it will assert to immediately let the developer know that a throttle occurred.
This is to avoid unintentionally missing 429 throttle error due to incorrectly written code.
If you wish to disable these asserts to continue working without fixing the offending code, you can call this API:

```cpp
xboxLiveContext->settings()->disable_asserts_for_xbox_live_throttling_in_dev_sandboxes(
  xbox_live_context_throttle_setting::this_code_needs_to_be_changed_to_avoid_throttling
);
```

but note that this API will not prevent your title from being throttled.
Your title will still be throttled.
This simply disables the asserts when in dev sandboxes while using a debug build. 


### Using the Xbox Live Trace Analyzer tool

Another option for determining whether your title was throttled is to record a trace of the Xbox Live calls and then analyze that trace using the [Xbox Live Trace Analyzer tool](../../tools/analyze-service-calls.md).

To record a trace, you can either use Fiddler to record a .SAZ file, or by using the built-in trace logging of XSAPI.
For more information about turning on traces in XSAPI, see the Xbox Live documentation page "Analyze calls to Xbox Live Services". <!-- tbd: link, not found -->
Once you have a trace, the Xbox Live Trace Analyzer tool will warn you when it detects throttled calls.


## Is Xbox Live Up?

Xbox Live is a collection of microservices that expose Xbox Live features such as profile, friends and presence, stats, leaderboards, achievements, multiplayer, and matchmaking.
There isn’t a single server or endpoint that defines whether Xbox Live is up.
If a single server goes down, the rest of the Xbox Live microservices are largely independent and should be operational.

If a single service experiences a temporary outage, it’s important to know if this service call is mission critical for your game.
Try to provide reasonable experience while there are intermittent network or service issues.
For example, if the presence service is returning failure that call likely isn’t mission-critical for your game.
So simply report to the user the last known presence, instead of reporting that Xbox Live is down.

Xbox Live follows the consistency model of "eventual consistency".
This means that if no new updates are made, eventually all requests for that resource will report the last updated value.
This means that there is a short period during which the information is stale, while the data propagates.
