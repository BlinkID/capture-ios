// Created by Jura Skrlec on 04.04.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <CaptureCore/MBCCCoreDefines.h>
#import <CaptureCore/MBCCAnalyzerSettings.h>
#import <CaptureCore/MBCCAnalyzerResult.h>
#import <CaptureCore/MBCCFrameAnalysisResult.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MBCCAnalysisType) {
    MBCCAnalysisTypeDirectAPI,
    MBCCAnalysisTypeDirectAPIOnVideoStream,
    MBCCAnalysisTypeVideoStream,
};

typedef NS_ENUM(NSInteger, MBCCAnalyzerError) {
    MBCCAnalyzerErrorInvalidLicenseKey,
    MBCCAnalyzerErrorMissingResources,
    MBCCAnalyzerErrorMemoryReserveFailure,
};

@protocol MBCCAnalyzerDelegate;

/**
 * This class is for internal use only. Do not use it in your code.
 * Use the ``MBCCAnalyzerRunner`` class instead.
 */
MBCC_CORE_FINAL
@interface _MBCCAnalyzer : NSObject

/// Initialize ``MBCCAnalyzer`` with default settings.
- (instancetype)init;

/// Initialize ``MBCCAnalyzer`` with custom ``MBCCAnalyzerSettings`` settings.
///
/// - Parameter settings: Used to tweak analyzer settings. See ``MBCCAnalyzerSettings`` for more customization details.
- (instancetype)initWithSettings:(MBCCAnalyzerSettings *)settings NS_DESIGNATED_INITIALIZER;

/// Performs analysis and capture of the document.
- (void)analyze:(MBCCImage *)frame analysisType:(MBCCAnalysisType)analysisType;;

/// Resume frame analyser. The state is not reset.
- (void)resume;

/// Pause frame analyser without dismissing the camera view.
/// If there is camera frame being processed at a time, the processing will finish, but the results of processing will not be returned.
- (void)pause;

/// Reset analyzer state.
///
/// Use this when you want to reset the whole state and start the analyser from the beginning.
- (void)reset;

/// Releases ownership of the result object and returns analyzer to initial state.
///
/// Method provides zero copy API for consuming result.
- (MBCCAnalyzerResult *)detachResult;

/// Terminates the analyzer and releases allocated memory for processing.
///
/// No further processing is possible after the `terminate` is called.
- (void)terminate;

/// Method tries to finish capture of current side before the side capture acceptance critea has been met
/// which is performed as part of the `analyze` function call.
///
/// Current ``MBCCSideCaptureResult`` is filled with captured best frame, if there isn't one method returns `false`
/// otherwise `true`, result is updated and analyzer transitions to next side capture if one exists through delegate's method. 
///
- (void)finishSideCapture;

/// Dispatch queue responsible for capture process.
@property (nonatomic, readonly) dispatch_queue_t analyzerQueue;

/// Used for tweaking capture settings.
///
/// See ``MBCCAnalyzerResult`` for more details.
@property (nonatomic) MBCCAnalyzerSettings *settings;

/// Analyzer result.
///
/// See ``MBCCAnalyzerResult`` for more details.
@property (nonatomic, readonly, nullable) MBCCAnalyzerResult *result;

/// Analyzer delegate.
/// 
/// Set this to get ``MBCCFrameAnalysisResult``.
@property (nonatomic) id<MBCCAnalyzerDelegate> delegate;

/// Check if frame analysis is paused.
@property (nonatomic, readonly) BOOL isFrameAnalysisPaused;

/// Check if first side is captures.
@property (nonatomic) BOOL isFirstSideCaptured;

/// Check if second side is captured.
@property (nonatomic) BOOL isSecondSideCaptured;

@end

@protocol MBCCAnalyzerDelegate <NSObject>

/// Fired when frame is analysed.
///
/// Returned on the `analyzerQueue`, so handle every UI change on the main queue.
///
/// - Parameters:
///   - analyzer: Component responsible for image analysis and best frame capture.
///   - frameAnalysisResult: Current status of the analysis and the capture process and further required actions.
- (void)analyzer:(_MBCCAnalyzer *)analyzer didAnalyzeFrameWithResult:(MBCCFrameAnalysisResult *)frameAnalysisResult;

/// Validates given combination of resolution and settings can be used to capture document.
///
/// Analyzer tries to capture document at requested minimum dpi with configured framing margin
/// on provided image resolution. Image resolution needs to have sufficient number of pixels
/// for capture process to finish.
/// Validation is done agains biggest documents, passports with physical size ( 4.921 x 3.465 inches ).
/// Unknown documents are treated as ID1 documents with size 3.37 x 2.125 inches.
///
/// Recommended ranges for resolutions:
///     - 720p  - [ 150, 200 ]
///     - 1080p - [ 150, 220 ]
///     - 1440p - [ 150, 300 ]
///     - 2160p - [ 150, 400 ]
///
/// Recommended documentFramingMargin [ 0, 0.1F ].
- (void)analyzerDidFailToValidateSettings:(_MBCCAnalyzer *)analyzer;

/// Fired when analyzer fails to initialize.
- (void)analyzerDidFailToInitializeWithError:(MBCCAnalyzerError)analyzerError;

@optional
/// Method used to finish capture of current side when `analyseFrame` didn't return
/// `FrameAnalysisResult::AnalyserState::SideCaptured` state.
///
/// Method tries to fill `SideCaptureResult` with current best frame, if there isn't one method returns `false`
/// and result is not changed, otherwise `true` is returned and current best frame is filled in current SideCaptureResult.
///
/// Method can be used only once per side capture session. If called after FrameAnalysisResult::AnalyserState::SideCaptured
/// method will return false because side was already captured.
///
/// - Parameters:
///  - analyzer: Component responsible for image analysis and best frame capture.
///  - isSideCaptureFinished: Current status of the analysis and the capture process and further required actions.
- (void)analyzer:(_MBCCAnalyzer *)analyzer isSideCaptureFinished:(BOOL)isSideCaptureFinished;

@end

NS_ASSUME_NONNULL_END
