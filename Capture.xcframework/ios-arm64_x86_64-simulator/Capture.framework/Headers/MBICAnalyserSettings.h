// Created by Jura Skrlec on 03.04.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <Capture/MBICCoreDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Configures capture strategy used to select the best frame.
typedef NS_ENUM(NSInteger, MBICCaptureStrategy) {
    /// Analysis is faster, but it is possible to capture frames with lower quality.
    MBICCaptureStrategyOptimizeForSpeed,
    /// Analysis is slower in order to capture high quality frames.
    MBICCaptureStrategyOptimizeForQuality,
    /// Trade-off for quality and speed.
    MBICCaptureStrategyDefault,
    /// Captures first acceptable frame.
    MBICCaptureStrategySingleFrame
};

@class MBICLightingThresholds;

/// Analyser settings.
///
/// Used for tweaking capture settings.
MBIC_CORE_FINAL
@interface MBICAnalyserSettings : NSObject

/// Defines whether to capture a single side or capture all possible sides of a document with automatic side detection.
///
/// Default: `NO`
@property (nonatomic) BOOL captureSingleSide;

/// Defines whether to return an image of a cropped and perspective-corrected document.
///
/// Default: `YES`
@property (nonatomic) BOOL returnTransformedDocumentImage;

/// Defines whether to discard frames with blurred documents.
///
/// If enabled, the capture process is allowed to finish with blurry documents.
///
/// Default: `NO`
@property (nonatomic) BOOL ignoreBlur;

/// Defines whether to return an image of the transformed document with applied margin used during document framing.
///
/// Default: `NO`
@property (nonatomic) BOOL keepMarginOnTransformedDocumentImage;

/// Defines whether to discard frames with glare detected on the document.
///
/// If enabled, the capture process is allowed to finish with glare on the document.
///
/// Default: `NO`
@property (nonatomic) BOOL ignoreGlare;

/// Enables document capture with a margin defined as the percentage of the dimensions of the framed document.
///
/// Both margin and document are required to be fully visible on camera frame in order to finish capture.
///
/// Allowed values are from 0 to 1.
///
/// - Throws: `MBICInvalidDocumentFramingMarginException` if the quantity is less than 0 and more than 1.
///
/// Default: `0.01f`
@property (nonatomic) CGFloat documentFramingMargin;

/// Defines percentage of the document area that is allowed to be occluded by hand.
/// Allowed values are from 0 to 1.
///
/// - Throws: `MBICInvalidHandOcclusionTresholdException` if the quantity is less than 0 and more than 1.
///
/// Default: `0.05f`
@property (nonatomic) CGFloat handOcclusionThreshold;

/// Threshold for detecting tilted documents.
/// Frames with documents tilted more than defined by this threshold are discarded.
///
/// Allowed values are from 0 to 1.
///
/// - Throws: `MBICInvalidTiltTresholdException` if the quantity is less than 0 and more than 1.
///
/// Default:` 0.17f`
@property (nonatomic) CGFloat tiltThreshold;

/// Configures capture strategy used to select the best frame.
/// See ``MBICCaptureStategy`` for more details.
@property (nonatomic) MBICCaptureStrategy captureStrategy;

/// Parameters for lighting estimation.
/// See ``MBICLightingThresholds`` for more details.
@property (nonatomic) MBICLightingThresholds *lightingThresholds;

/// Required minimum DPI of the captured document on transformed image.
///
/// Affects how close the document needs to be to the camera in order to get captured and meet dpi requirements.
/// Allowed values are [ 150, 400 ].
///
/// - Throws: `MBICInvalidDocumentDpiException` if the quantity is less than 200 and more than 400.
/// 
/// Default: `250`
@property (nonatomic) NSInteger minimumDocumentDpi;

@end

/// Parameters for lighting estimation.
MBIC_CORE_FINAL
@interface MBICLightingThresholds : NSObject

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithTooDarkTreshold:(CGFloat)tooDarkThreshold tooBrightThreshold:(CGFloat)tooBrightThreshold;

/// Threshold used to classify the frame as too dark.
/// If the calculated lighting score is above this threshold, it is discarded.
///
/// Allowed values are from 0 to 1.
///
/// - Throws: `MBICInvalidLightingThrsholdsException` if the quantity is less than 0 and more than 1.
///
/// Default: `0.99f`
@property (nonatomic) CGFloat tooDarkThreshold;

/// Threshold used to classify the frame as too bright.
/// If the calculated lighting score is above this threshold, it is discarded.
///
/// - Throws: `MBICInvalidLightingThrsholdsException` if the quantity is less than 0 and more than 1.
///
/// Allowed values are from 0 to 1.
///
/// Default: `0.99f`
@property (nonatomic) CGFloat tooBrightThreshold;

@end

NS_ASSUME_NONNULL_END
