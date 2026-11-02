// Created by Jura Skrlec on 12.05.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <CaptureUX/MBICUXDefines.h>

NS_ASSUME_NONNULL_BEGIN

MBIC_UX_FINAL
@interface MBICCaptureUISDK : NSObject

/// Sets the language used in CaptureSDK
@property (nonatomic) NSString *language DEPRECATED_MSG_ATTRIBUTE("Use this property at your own risk as it does not comply with Apple guidelines. This will be removed in future releases.");

/// Bundle with resources used in framework
@property (nonatomic) NSBundle *resourcesBundle;

/// Custom bundle for overriding resourcesBundle
@property (nonatomic) NSBundle *customResourcesBundle;

/// Localization file in main bundle used for overrideing framework's localizations
@property (nonatomic) NSString *customLocalizationFileName DEPRECATED_MSG_ATTRIBUTE("Use this property at your own risk as it does not comply with Apple guidelines. This will be removed in future releases.");

/// Language Localizable.strings
@property (nonatomic, readonly) NSBundle *localizableLanguageBundle DEPRECATED_MSG_ATTRIBUTE("Use this property at your own risk as it does not comply with Apple guidelines. This will be removed in future releases.");

/// Overrides device langauge. You need to set your own language.
/// Set this to YES, if you want to have in-app language selection.
///
/// WARNING: Use Apple intended way of localization from Settings screen.
/// Default: NO
@property (nonatomic) BOOL overrideAppPreferredLanguage DEPRECATED_MSG_ATTRIBUTE("Use this property at your own risk as it does not comply with Apple guidelines. This will be removed in future releases.");

/// Obtain the shared instance
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/// Sets the language to default (i.e. language specified in the user's device settings)..
- (void)setDefaultLanguage;

@end

static inline NSString * MBIC_UI_LOCALIZED_DEFAULT_STRING(NSString *key) {
    return ([NSString stringWithFormat:@"[[%@]]", key]);
}

static inline NSString * MBIC_UI_LOCALIZED_FOR_LANGUAGE(NSString *key, NSString *language) {
    NSBundle *bundle = [MBICCaptureUISDK sharedInstance].localizableLanguageBundle;
    
    // If a custom resource bundle is defined, use it for the localization
    NSString *overridenStringFromCustomBundle = NSLocalizedStringWithDefaultValue(
        key,
        nil,
        [MBICCaptureUISDK sharedInstance].customResourcesBundle ?: bundle,
        @"",
        @""
    );
    
    // If we found an override in the custom bundle, return it
    if (overridenStringFromCustomBundle != nil && ![overridenStringFromCustomBundle isEqualToString:key]) {
        return overridenStringFromCustomBundle;
    }

    // If not, fallback to the localizable bundle
    return NSLocalizedStringFromTableInBundle(
        key,
        @"Localizable",
        bundle,
        @""
    );
}

static inline NSString * MBIC_UI_LOCALIZED(NSString *key) {
    NSString *localizationFileName = [MBICCaptureUISDK sharedInstance].customLocalizationFileName;
    
    // First, check if we have a custom localization file
    if (localizationFileName) {
        NSString *overridenStringFromCustomLocalizationFile = NSLocalizedStringWithDefaultValue(
            key,
            localizationFileName,
            [NSBundle mainBundle],
            @"",
            @""
        );

        // If we found a match in the custom localization file, return it
        if (![overridenStringFromCustomLocalizationFile isEqualToString:key]) {
            return overridenStringFromCustomLocalizationFile;
        }
    }

    // Get the language currently set in the SDK
    NSString *language = [MBICCaptureUISDK sharedInstance].language;
    
    // Now, attempt to localize the string for the selected language
    NSString *localizedString = MBIC_UI_LOCALIZED_FOR_LANGUAGE(key, language);
    
    return localizedString;
}

NS_ASSUME_NONNULL_END
