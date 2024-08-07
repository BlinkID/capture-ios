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

@property (nonatomic) NSString *language;

/// Bundle with resources used in framework
@property (nonatomic) NSBundle *resourcesBundle;

/// Custom bundle for overriding resourcesBundle
@property (nonatomic) NSBundle *customResourcesBundle;

/// Localization file in main bundle used for overrideing framework's localizations
@property (nonatomic) NSString *customLocalizationFileName;

/// Obtain the shared instance
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/// Sets the language used in CaptureSDK
- (void)setLanguage:(NSString *)language;

/// Sets the language to default (i.e. language specified in the user's device settings.
- (void)setDefaultLanguage;

@end

static inline NSString * MBIC_UI_LOCALIZED_DEFAULT_STRING(NSString *key) {
    return ([NSString stringWithFormat:@"%@", key]);
}

static inline NSString * MBIC_UI_LOCALIZED_FOR_LANGUAGE(NSString *key) {

    NSString *overridenStringFromCustomBundle = NSLocalizedStringWithDefaultValue(key,
                                                                                  nil,
                                                                                  [MBICCaptureUISDK sharedInstance].customResourcesBundle,
                                                                                  @"",
                                                                                  @"");
    if (overridenStringFromCustomBundle != nil && ![overridenStringFromCustomBundle isEqualToString:key]) {
        return overridenStringFromCustomBundle;
    }
    
    return NSLocalizedStringFromTableInBundle(key, nil, [MBICCaptureUISDK sharedInstance].resourcesBundle, @"");
}

static inline NSString * MBIC_UI_LOCALIZED(NSString *key) {
    NSString *localizationFileName = [MBICCaptureUISDK sharedInstance].customLocalizationFileName;
    if (localizationFileName) {
        NSString *overridenStringFromCustomLocalizationFile = NSLocalizedStringWithDefaultValue(key, localizationFileName, [NSBundle mainBundle], @"", @"");

        if (![overridenStringFromCustomLocalizationFile isEqualToString:key]) {
            return overridenStringFromCustomLocalizationFile;
        }
    }
    
    NSString *localizedString = MBIC_UI_LOCALIZED_FOR_LANGUAGE(key);
    
    return localizedString;
}

NS_ASSUME_NONNULL_END
