---
title: Configuring localized strings in Partner Center
description: Configuring localized strings in Partner Center.
kindex: Configuring localized strings in Partner Center
kindex: localized strings, configuring
kindex: Partner Center, localized strings
ms.topic: article
ms.assetid: e0f307d2-ea02-48ea-bcdf-828272a894d4
ms.localizationpriority: medium
ms.date: 11/17/2017
---

# Configuring localized strings in Partner Center

To localize all your Xbox Live configurations to all the languages that your game supports, you can use the **Localized strings** page in Partner Center.
All of the service configurations that you have created on any of the subsequent Xbox Live pages will be added to the file that you would download.

You can use [Partner Center](https://partner.microsoft.com/dashboard) to configure the localized strings in all languages associated with your game.

Add configuration by doing the following:

1. In Partner Center, click **Services** > **Xbox Live** > **Localized strings**.

   The **Localized strings** section for your title appears.

2. Click the **Download** button.

   A `localization.xml` file is downloaded onto your local machine.

![Screenshot of the localized strings configuration page in Partner Center](live-localized-strings-config-images/localized-strings-1.png)

3. You can add the localized strings by duplicating the tag `<Value locale="en-US">Mazes Played</Value>` and changing the value of the locale to the language and country of your choice and the value of the localized string.  To avoid errors, you must have at least one `Value` tag within the developer display locale.

   The value of the `locale` attribute must include the language code followed by a hyphen (-) and the country code.
   For example, `locale="en-US"` means the English language as used in the United States.
   See <a href="https://docs.microsoft.com/en-us/partner-center/develop/partner-center-supported-languages-and-locales" target="_blank">Partner Center supported languages and locales &#11008;</a>.

![edit localized strings](live-localized-strings-config-images/localized-strings.gif)

4. Once you have added all the localized strings, you can upload the file by dragging or browsing your local machine.

![Image of the button to upload the localization.xml file](live-localized-strings-config-images/localized-strings-2.png)

The following errors might appear when you upload the `localization.xml` file:

| Error | Reason |
|---------------------------|-------------|
| Failed XSD Validation: The element 'LocalizedString' in namespace 'http://config.mgt.xboxlive.com/schema/localization/1' cannot contain text. List of possible elements expected: 'Value' in namespace 'http://config.mgt.xboxlive.com/schema/localization/1' | This occurs when the XML document is malformed. |
| Localization string is missing an entry for the developer display locale | This occurs when a localized string is missing an entry whose locale does not match the dev display locale. |
| Failed XSD Validation: The 'locale' attribute is invalid - The value ' ' is invalid according to its datatype 'http://config.mgt.xboxlive.com/schema/localization/1:NonEmptyString' - The Pattern constraint failed. | This occurs when a localized string is missing the locale value in the `<Value>` tag. The value of the `locale` attribute must include the language code followed by a hyphen (-) and the country code. |
