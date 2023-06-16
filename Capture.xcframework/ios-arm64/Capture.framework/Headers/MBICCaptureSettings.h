// Created by Jura Skrlec on 10.05.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <Capture/MBICUXDefines.h>
#import <Capture/MBICCameraSettings.h>
#import <Capture/MBICAnalyserSettings.h>
#import <Capture/MBICCaptureUXSettings.h>
#import <Capture/MBICCaptureViewControllerTheme.h>

NS_ASSUME_NONNULL_BEGIN

/// Settings configuration class.
/// Use it to configure ``analyserSettings``, ``cameraSettings``, ``uxSettings`` and ``captureViewControllerTheme``.
MBIC_UX_FINAL
@interface MBICCaptureSettings : NSObject

/// Capture analyser settings.
/// See ``MBICAnalyserSettings`` for more details.
@property (nonatomic) MBICAnalyserSettings *analyserSettings;

/// Camera settings.
/// See ``MBICCameraSettings`` for more details.
@property (nonatomic) MBICCameraSettings *cameraSettings;

/// UX settings.
/// See ``MBICCaptureUXSettings`` for more details.
@property (nonatomic) MBICCaptureUXSettings *uxSettings;

/// Overlay customization settings.
/// See ``MBICCaptureViewControllerTheme`` for more details.
@property (nonatomic) MBICCaptureViewControllerTheme *captureViewControllerTheme;

@end

NS_ASSUME_NONNULL_END
