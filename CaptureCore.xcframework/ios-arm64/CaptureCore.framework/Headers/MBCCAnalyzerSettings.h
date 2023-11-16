// Created by Jura Skrlec on 03.04.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <CaptureCore/MBCCCoreDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Configures capture strategy used to select the best frame.
typedef NS_ENUM(NSInteger, MBCCCaptureStrategy) {
    /// Analysis is faster, but it is possible to capture frames with lower quality.
    MBCCCaptureStrategyOptimizeForSpeed,
    /// Analysis is slower in order to capture high quality frames.
    MBCCCaptureStrategyOptimizeForQuality,
    /// Trade-off for quality and speed.
    MBCCCaptureStrategyDefault,
    /// Captures first acceptable frame.
    MBCCCaptureStrategySingleFrame
};

/// Policy used to detect tilted documents.
typedef NS_ENUM(NSInteger, MBCCTiltPolicy) {
    /// Disables tilt detection
    MBCCTiltPolicyDisabled,
    /// Strict tilt detection
    /// Enables capture of document with minimum tilt tolerance.
    MBCCTiltPolicyStrict,
    /// Trade-off for strict and relaxed
    MBCCTiltPolicyNormal,
    /// Relaxed tilt detection
    /// Enables capture of documents with higher tilt tolerance.
    MBCCTiltPolicyRelaxed
};

/// Policy used to discard frames with blurred documents.
typedef NS_ENUM(NSInteger, MBCCBlurPolicy) {
    /// Disables blur detection
    MBCCBlurPolicyDisabled,
    /// Strict blur detection
    /// Enables capture of documents with minimum blur degradation.
    MBCCBlurPolicyStrict,
    /// Trade-off for strict and relaxed
    MBCCBlurPolicyNormal,
    /// Relaxed blur detection
    /// Enables capture of documents with relaxed blur degradation, allowing capture of more blurry documents.
    MBCCBlurPolicyRelaxed
};

/// Policy used to discard frames with glare detected on the document.
typedef NS_ENUM(NSInteger, MBCCGlarePolicy) {
    /// Disables glare detection
    MBCCGlarePolicyDisabled,
    /// Strict glare detection
    /// Enables capture of documents with minimum glare degradation.
    MBCCGlarePolicyStrict,
    /// Trade-off for strict and relaxed
    MBCCGlarePolicyNormal,
    /// Relaxed glare detection
    /// Enables capture of documents with relaxed glare detection, allowing capture of documents with more glare.
    MBCCGlarePolicyRelaxed
};

/// See ``MBCCLightingThresholds`` for more details.
@class MBCCLightingThresholds;

/// Analyser settings.
///
/// Used for tweaking capture settings.
MBCC_CORE_FINAL
@interface MBCCAnalyzerSettings : NSObject

/// Defines whether to capture a single side or capture all possible sides of a document with automatic side detection.
///
/// Default: `NO`
@property (nonatomic) BOOL captureSingleSide;

/// Defines whether to return an image of a cropped and perspective-corrected document.
///
/// Default: `YES`
@property (nonatomic) BOOL returnTransformedDocumentImage;

/// Defines whether to return an image of the transformed document with applied margin used during document framing.
///
/// Default: `NO`
@property (nonatomic) BOOL keepMarginOnTransformedDocumentImage;

/// Enables document capture with a margin defined as the percentage of the dimensions of the framed document.
///
/// Both margin and document are required to be fully visible on camera frame in order to finish capture.
///
/// Allowed values are from 0 to 1.
///
/// - Throws: `MBCCInvalidDocumentFramingMarginException` if the quantity is less than 0 and more than 1.
///
/// Default: `0.01f`
@property (nonatomic) CGFloat documentFramingMargin;

/// Defines percentage of the document area that is allowed to be occluded by hand.
/// Allowed values are from 0 to 1.
///
/// - Throws: `MBCCInvalidHandOcclusionTresholdException` if the quantity is less than 0 and more than 1.
///
/// Default: `0.05f`
@property (nonatomic) CGFloat handOcclusionThreshold;

/// Configures capture strategy used to select the best frame.
/// See ``MBCCCaptureStategy`` for more details.
@property (nonatomic) MBCCCaptureStrategy captureStrategy;

/// Parameters for lighting estimation.
/// See ``MBCCLightingThresholds`` for more details.
@property (nonatomic) MBCCLightingThresholds *lightingThresholds;

/// Required minimum DPI of the captured document on transformed image.
///
/// Affects how close the document needs to be to the camera in order to get captured and meet dpi requirements.
/// Allowed values are [ 150, 400 ].
///
/// - Throws: `MBCCInvalidDocumentDpiException` if the quantity is less than 200 and more than 400.
/// 
/// Default: `250`
@property (nonatomic) NSInteger minimumDocumentDpi;

/// Whether to automatically adjust minimum document dpi.
///
/// If it is enabled, minimum dpi is adjusted to optimal value for provided input resolution
/// to enable capture of all document groups.
///
/// Default: `YES`
@property (nonatomic) BOOL adjustMinimumDocumentDpi;

/// Policy used to detect tilted documents.
/// See ``MBCCTiltPolicy`` for more details.
///
/// Default: `MBCCTiltPolicyNormal`
@property (nonatomic) MBCCTiltPolicy tiltPolicy;

/// Policy used to discard frames with blurred documents.
/// See ``MBCCBlurPolicy`` for more details.
///
/// Default: `MBCCBlurPolicyNormal`
@property (nonatomic) MBCCBlurPolicy blurPolicy;

/// Policy used to discard frames with glare detected on the document.
/// See ``MBCCGlarePolicy`` for more details.
///
/// Default: `MBCCGlarePolicyNormal`
@property (nonatomic) MBCCGlarePolicy glarePolicy;

@end

/// Parameters for lighting estimation.
MBCC_CORE_FINAL
@interface MBCCLightingThresholds : NSObject

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithTooDarkTreshold:(CGFloat)tooDarkThreshold tooBrightThreshold:(CGFloat)tooBrightThreshold;

/// Threshold used to classify the frame as too dark.
/// If the calculated lighting score is above this threshold, it is discarded.
///
/// Allowed values are from 0 to 1.
///
/// - Throws: `MBCCInvalidLightingThrsholdsException` if the quantity is less than 0 and more than 1.
///
/// Default: `0.99f`
@property (nonatomic) CGFloat tooDarkThreshold;

/// Threshold used to classify the frame as too bright.
/// If the calculated lighting score is above this threshold, it is discarded.
///
/// - Throws: `MBCCInvalidLightingThrsholdsException` if the quantity is less than 0 and more than 1.
///
/// Allowed values are from 0 to 1.
///
/// Default: `0.99f`
@property (nonatomic) CGFloat tooBrightThreshold;

@end

NS_ASSUME_NONNULL_END
