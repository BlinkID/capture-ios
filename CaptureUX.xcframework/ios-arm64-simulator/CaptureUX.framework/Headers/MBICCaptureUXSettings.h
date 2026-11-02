// Created by Jura Skrlec on 15.05.2023..
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

/// Capture UX Settings.
/// Used for cusotmizing UX.
MBIC_UX_FINAL
@interface MBICCaptureUXSettings : NSObject

/// Defines whether tutorial alert will be presented on appear.
///
/// Default: `NO`
@property (nonatomic) BOOL showIntroductionDialog;

/// Defines whether button for presenting onboarding screens will be present on screen.
///
/// Default: `YES`
@property (nonatomic) BOOL showOnboardingInfo;

/// Defines whether whether the idle timer is disabled for the ``MBICCaptureViewController``.
/// Set this to NO if you want that ``MBICCaptureViewController`` goes to sleep.
/// 
/// Default: `YES`
@property (nonatomic, getter=isIdleTimerDisabled) BOOL idleTimerDisabled;

/// Defines side capture timeout.
///
/// Use this to set the timeout for each side capture.
///
/// Default: `15 seconds`
@property (nonatomic) NSTimeInterval sideCaptureTimeout;

/// Defines whether to show tooltip above help button.
///
/// Default: `YES`
@property (nonatomic) BOOL showCaptureHelpTooltip;

/// Defines timer's timeout for tooltip. If there is no activity, tooltip is showed after this timeout.
///
/// Default: `8 seconds`
@property (nonatomic) NSTimeInterval captureHelpTooltipTimeoutInterval;

@end

NS_ASSUME_NONNULL_END
