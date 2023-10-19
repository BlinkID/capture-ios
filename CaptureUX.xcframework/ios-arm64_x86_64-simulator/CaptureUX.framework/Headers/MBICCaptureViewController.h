// Created by Jura Skrlec on 22.02.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <UIKit/UIKit.h>
#import <CaptureUX/MBICUXDefines.h>
#import <CaptureUX/MBICCaptureSettings.h>
#import <CaptureCore/MBCCAnalyzerResult.h>


NS_ASSUME_NONNULL_BEGIN

@protocol MBICCaptureViewControllerDelegate;

MBIC_UX_FINAL
@interface MBICCaptureViewController : UIViewController

/// Initialize `MBICCaptureViewController`.
///
/// Use this to initialize ``MBICCaptureViewController`` with default ``MBICCaptureSettings``.
- (instancetype)init;

/// Designated initializer - Initialize `MBICCaptureViewController`.
///
/// Use this to initialize ``MBICCaptureViewController`` with custom ``MBICCaptureSettings``.
///
/// - Parameters:
///    - captureSettings: The capture settings.
- (instancetype)initWithCaptureSettings:(MBICCaptureSettings *)captureSettings NS_DESIGNATED_INITIALIZER;

/// Start new scan session.
///
/// This is a utility method when you want to start new scan session after the previouse session is completed without dismissing view controller.
- (void)startNewCaptureSession;

/// Capture settings.
@property (nonatomic, readonly) MBICCaptureSettings *captureSettings;

/// Delegate.
/// See ``MBICCaptureViewControllerDelegate`` for more details.
@property (nonatomic, weak) id<MBICCaptureViewControllerDelegate> delegate;

@end

@protocol MBICCaptureViewControllerDelegate <NSObject>

/// Fired when the capture process is done.
///
/// Returns on the `analyzerQueue`. Dispatch every UI change on the main queue.
///
/// - Parameters:
///    - captureViewController: Capture document view controller.
///    - analyzerResult: Frame analyzer result. See `MBICAnalyzerResult` for available results.
- (void)captureViewController:(nonnull MBICCaptureViewController *)captureViewController didFinishCaptureWithResult:(nonnull MBCCAnalyzerResult *)analyzerResult NS_SWIFT_NAME(captureViewController(captureViewController:didFinishCaptureWithResult:));

@optional
/// Fired when the view controller is manually dismissed.
///
/// - Parameters:
///    - captureViewController: Capture document view controller.
- (void)captureViewControllerDidClose:(nonnull MBICCaptureViewController *)captureViewController NS_SWIFT_NAME(captureViewControllerDidClose(captureViewController:));

/// Fired when the torch is toggled on/off.
///
/// - Parameters:
///    - captureViewController: Capture document view controller.
///    - didTurnTorchOn: Flag that indicates if the torch is turned on/off.
- (void)captureViewController:(nonnull MBICCaptureViewController *)captureViewController didTurnTorchOn:(BOOL)didTurnTorchOn NS_SWIFT_NAME(captureViewController(captureViewController:didTurnTorchOn:));

@end

NS_ASSUME_NONNULL_END
