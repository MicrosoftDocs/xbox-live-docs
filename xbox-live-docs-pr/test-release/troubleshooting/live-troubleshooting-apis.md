---
title: Troubleshooting Xbox Live Services APIs
description: Hooking up the response logger and enabling debug tracing.
kindex: Troubleshooting Xbox Live Services APIs
kindex: debug tracing, enabling
ms.topic: article
ms.assetid: 3827bba1-902f-4f2d-ad51-af09bd9354c4
ms.localizationpriority: medium
ms.date: 04/04/2017
---

# Troubleshooting Xbox Live Services APIs

It is difficult to diagnose a failure using only the error from the Xbox Live Services API layer.
Additional, helpful error information — such as logging of all RESTful calls — can be made available to the server.

To listen to this additional data, hook up the response logger and enable debug tracing.
Response logging allows you to see HTTP traffic and web service response codes, which is often as useful as a Fiddler trace.


## Code example

The following code example enables response logging, and sets the debug error level to **Verbose**.
(You can also set the debug error level to **Error**, to show only trace failed calls; or to **Off**, to disable tracing.)

The resulting debug output is sent to the Output pane when running your project in Visual Studio.


**C API**
<!-- HCTraceSetTraceToDebugger.md -->
```cpp
HCSettingsSetTraceLevel(HCTraceLevel::Verbose); // See HCTraceLevel enum for various levels
HCTraceSetTraceToDebugger(true);
```


**C++ API**
```cpp
// Set up debug tracing to the Output window in Visual Studio.
xbox::services::system::xbox_live_services_settings::get_singleton_instance()->set_diagnostics_trace_level(
    xbox_services_diagnostics_trace_level::verbose
);
```

You can also choose to redirect debug output to your own log file, as follows:

```cpp
// Set up debug tracing of the Xbox Live Services API traffic to the game UI.
m_xboxLiveContext->Settings->EnableServiceCallRoutedEvents = true;
m_xboxLiveContext->Settings->ServiceCallRouted += ref new
Windows::Foundation::EventHandler<Microsoft::Xbox::Services::XboxServiceCallRoutedEventArgs^>(
    [=] ( Platform::Object^, Microsoft::Xbox::Services::XboxServiceCallRoutedEventArgs^ args )
    {
        gameUI->Log(L"[URL]: " + args->HttpMethod + " " + args->Url->AbsoluteUri);
        gameUI->Log(L"");
        gameUI->Log(L"[Response]: " + args->HttpStatus.ToString() + " " + args->ResponseBody);
    });
```
