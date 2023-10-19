// Created by Jura Skrlec on 13.04.2023..
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

/// Status of the document side analysis
/// In order to finish capture of the document all sides are required to be captured only once.
typedef NS_ENUM(NSInteger, MBCCDocumentSideAnalysisStatus) {
    /// Status is not available.
    MBCCDocumentSideAnalysisStatusNotAvailable,
    /// Side has already been captured.
    MBCCDocumentSideAnalysisStatusSideAlreadyCaptured,
    /// Side has not been captured.
    MBCCDocumentSideAnalysisStatusSideNotCaptured
};

/// State of the document capture.
/// Describes state of the capture process in general.
typedef NS_ENUM(NSInteger, MBCCCaptureState) {
    /// Side has been captured and next side is expected to be captured in order to finish capture of the document.
    MBCCCaptureStateSideCaptured,
    /// Document has been captured and no further processing is required
    MBCCCaptureStateDocumentCaptured,
    /// First side is being captured.
    MBCCCaptureStateFirstSideCaptureInProgress,
    /// Second side is being captured.
    MBCCCaptureStateSecondSideCaptureInProgress
};

/// Status of the document framing.
typedef NS_ENUM(NSInteger, MBCCDocumentFramingStatus) {
    /// Status is not available.
    MBCCDocumentFramingStatusNotAvailable,
    /// Document is not visible on the frame.
    MBCCDocumentFramingStatusNoDocument,
    /// Camera is too far from the document.
    MBCCDocumentFramingStatusCameraTooFar,
    /// Camera is too close to the document.
    MBCCDocumentFramingStatusCameraTooClose,
    /// Camera angle is too steep because document is tilted.
    MBCCDocumentFramingStatusCameraAngleTooSteep,
    /// Document is too close to the frame edge and additional margin around document is required.
    MBCCDocumentFramingStatusDocumentTooCloseToFrameEdge,
    /// Camera orientation is not suitable for document capture; Framing angle change is required to allow document capture.
    MBCCDocumentFramingStatusCameraOrientationUnsuitable,
    /// Document is well positioned.
    MBCCDocumentFramingStatusDocumentOk
};

/// Status of the document lighting condintions estatimation.
typedef NS_ENUM(NSInteger, MBCCDocumentLightingStatus) {
    /// Status is not available.
    MBCCDocumentLightingStatusNotAvailable,
    /// Document lihgting is too bright.
    MBCCDocumentLightingStatusTooBright,
    /// Document lihgting is too dark.
    MBCCDocumentLightingStatusTooDark,
    /// Document lighting is normal.
    MBCCDocumentLightingStatusNormal
};

/// Status of the document blur detection.
typedef NS_ENUM(NSInteger, MBCCDocumentBlurStatus) {
    /// Status is not available.
    MBCCDocumentBlurStatusNotAvailable,
    /// Blur is detected.
    MBCCDocumentBlurStatusBlurDetected,
    /// Blur is not detected.
    MBCCDocumentBlurStatusBlurNotDetected
};

/// Status of the document glare detection.
typedef NS_ENUM(NSInteger, MBCCDocumentGlareStatus) {
    /// Status is not available.
    MBCCDocumentGlareStatusNotAvailable,
    /// Glare is detected.
    MBCCDocumentGlareStatusGlareDetected,
    /// Glare is not detected.
    MBCCDocumentGlareStatusGlareNotDetected
};

/// Status of the document occlusion detection.
typedef NS_ENUM(NSInteger, MBCCDocumentOcclusionStatus) {
    /// Status is not available.
    MBCCDocumentOcclusionStatusNotAvailable,
    /// Occlusion is detected.
    MBCCDocumentOcclusionStatusOccluded,
    /// Occlusion is not detected.
    MBCCDocumentOcclusionStatusNotOccluded
};

@class MBCCFrameAnalysisStatus;

/// Result of frame analysis and current state of analysis info.
MBCC_CORE_FINAL
@interface MBCCFrameAnalysisResult : NSObject

/// State of the capture process.
///
/// See ``MBCCCaptureState`` for more details.
@property (nonatomic, readonly) MBCCCaptureState captureState;

/// If `true` frame has been captured and participates in captured frames count, otherwise frame has not been captured
/// because at least one of the checks has failed.
///
/// See ``MBCCFrameAnalysisStatus`` for more details.
@property (nonatomic, readonly) BOOL isFrameCaptured;

/// Status of the current frame analysis.
@property (nonatomic, readonly) MBCCFrameAnalysisStatus *frameAnalysisStatus;

@end

/// Analysis result of last of the frame.
MBCC_CORE_FINAL
@interface MBCCFrameAnalysisStatus: NSObject

/// The document side analysis status.
///
/// See ``MBCCDocumentSideAnalysisStatus`` for more details.
@property (nonatomic, readonly) MBCCDocumentSideAnalysisStatus sideAnalysisStatus;

/// The document framing status.
///
/// See ``MBCCDocumentFramingStatus`` for more details.
@property (nonatomic, readonly) MBCCDocumentFramingStatus framingStatus;

/// The document lighting condintions status.
///
/// See ``MBCCDocumentLightingStatus`` for more details.
@property (nonatomic, readonly) MBCCDocumentLightingStatus lightingStatus;

/// Status of the document blur detection.
///
/// See ``MBCCDocumentBlurStatus`` for more details.
@property (nonatomic, readonly) MBCCDocumentBlurStatus blurStatus;

/// Status of the document glare detection.
///
/// See ``MBCCDocumentGlareStatus`` for more details.
@property (nonatomic, readonly) MBCCDocumentGlareStatus glareStatus;

/// Status of the document occlusion detection.
///
/// See ``MBCCDocumentOcclusionStatus`` for more details.
@property (nonatomic, readonly) MBCCDocumentOcclusionStatus occlusionStatus;

@end

NS_ASSUME_NONNULL_END
