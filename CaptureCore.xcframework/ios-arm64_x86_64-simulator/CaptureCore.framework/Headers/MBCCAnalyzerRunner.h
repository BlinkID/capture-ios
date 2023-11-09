// Created by Jura Skrlec on 10.10.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>

#import <Foundation/Foundation.h>
#import <CaptureCore/MBCCCoreDefines.h>
#import <CaptureCore/MBCCAnalyzer.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MBCCAnalyzerRunnerError) {
    /// License key is not valid to use CaptureSDK functionality.
    MBCCAnalyzerRunnerErrorInvalidLicenseKey,
    /// License key is locked.
    MBCCAnalyzerRunnerErrorLicenseLocked,
    /// Unable to activate online license.
    MBCCAnalyzerRunnerErrorUnableToActivateOnlineLicense,
    /// Device does not have enough memory for processing.
    MBCCAnalyzerRunnerErrorMemoryReserveFailure,
    /// Resource are missing in assets folder.
    MBCCAnalyzerRunnerErrorMissingResources,
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
    MBCCAnalyzerRunnerErrorAnalyzerSettingsUnsuitable
};

@protocol MBCCAnalyzerRunnerDelegate;

/// DirectAPI component responsible for image analysis and best frame capture.
MBCC_CORE_FINAL
@interface MBCCAnalyzerRunner : NSObject

/// Initialize ``MBCCAnalyzerRunner`` with default settings.
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/// Performs analysis and capture of the document on one image.
- (void)analyzeImage:(nonnull MBCCImage *)frame;

/// Performs analysis and capture of the document.
- (void)analyzeStreamImage:(nonnull MBCCImage *)frame;

/// Resume frame analyser. The state is not reset.
- (void)resume;

/// Pause frame analyser without dismissing the camera view.
/// If there is camera frame being processed at a time, the processing will finish, but the results of processing will not be returned.
- (void)pause;

/// Reset analyzer state.
/// Use this when you want to reset the whole state and start the analyser from the beginning.
- (void)reset;

/// Releases ownership of the result object and returns analyzer to initial state.
/// Method provides zero copy API for consuming result.
- (nonnull MBCCAnalyzerResult *)detachResult;

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

/// Capture analyser settings.
/// See ``MBCCAnalyzerSettings`` for more details.
@property (nonatomic) MBCCAnalyzerSettings *settings;

/// Analyzer result.
///
/// See ``MBCCAnalyzerResult`` for more details.
@property (nonatomic, readonly, nullable) MBCCAnalyzerResult *result;

/// Analyzer delegate.
///
/// Set this to get ``MBCCFrameAnalysisResult``.
@property (nonatomic) id<MBCCAnalyzerRunnerDelegate> delegate;

@end

@protocol MBCCAnalyzerRunnerDelegate <NSObject>

/// Fired when frame is analysed.
///
/// Returned on the separate queue, so handle every UI change on the main queue.
///
/// - Parameters:
///   - analyzerRunner: Component responsible for image analysis and best frame capture.
///   - frameAnalysisResult: Current status of the analysis and the capture process and further required actions.
- (void)analyzerRunner:(nonnull MBCCAnalyzerRunner *)analyzerRunner didAnalyzeFrameWithResult:(nonnull MBCCFrameAnalysisResult *)frameAnalysisResult;

/// Fired when error occurs.
///
/// - Parameters:
///   - analyzerRunner: Component responsible for image analysis and best frame capture.
///   - analysisError: Did fail with error. See ``MBCCAnalyzerRunnerError`` for more details.
- (void)analyzerRunner:(nonnull MBCCAnalyzerRunner *)analyzerRunner didFailWithAnalyzerError:(MBCCAnalyzerRunnerError)analyzerError;

@optional
/// Method used to finish capture of current side when `analyzeImage` didn't return
/// ``MBCCSideCaptureResult`` state.
///
/// Method tries to fill ``MBCCSideCaptureResult`` with current best frame, if there isn't one method returns `false`
/// and result is not changed, otherwise `true` is returned and current best frame is filled in current SideCaptureResult.
///
/// Method can be used only once per side capture session.
///
/// - Parameters:
///  - analyzerRunner: Component responsible for image analysis and best frame capture.
///  - isSideCaptureFinished: Current status of the analysis and the capture process and further required actions.
- (void)analyzerRunner:(nonnull MBCCAnalyzerRunner *)analyzerRunner isSideCaptureFinished:(BOOL)isSideCaptureFinished;

@end

NS_ASSUME_NONNULL_END
