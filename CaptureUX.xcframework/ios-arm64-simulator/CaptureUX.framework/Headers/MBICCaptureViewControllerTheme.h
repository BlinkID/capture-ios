// Created by Jura Skrlec on 19.05.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <UIKit/UIKit.h>
#import <CaptureUX/MBICUXDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Capture overlay theme settings.
/// Used for UI customzation.
MBIC_UX_FINAL
@interface MBICCaptureViewControllerTheme : NSObject

/**
 * Successful scan image.
 *
 * Default: checkmark
*/
@property (nonatomic) UIImage *captureSuccessScanImage;

/**
 * Help button image.
 * Dimensions: 32x32
 *
 * Default: need-help-tooltip
*/
@property (nonatomic) UIImage *captureHelpButtonImage;

/**
 * Help button dark image.
 * Dimensions: 32x32
 *
 * Default: need-help-tooltip-dark
*/
@property (nonatomic) UIImage *captureHelpButtonDarkImage;

/**
 * Status view label's font. Status view handles all the messages.
 *
 * Default: SystemFont 17pt SemiBold
*/
@property (nonatomic) UIFont *captureStatusViewFont;

/**
 * Status view corner radius.
 *
 * Default: 6
*/
@property (nonatomic) CGFloat captureStatusViewCornerRadius;

/**
 * Flashlight warning font
 *
 * Default: System (iPhone - 14pt, iPad - 16pt)
 */
@property (nonatomic) UIFont *cameraTorchWarningFont;

/**
 * Flashlight warning background color. Same for dark mode.
 *
 * Default: #3A3A3C
*/
@property (nonatomic) UIColor *cameraTorchWarningBackgroundColor;

/**
 * Flashlight warning text color. Same for dark mode.
 *
 * Default: white
*/
@property (nonatomic) UIColor *cameraTorchWarningTextColor;

/**
 * Flashlight warning corner radius
 *
 * Default: 4
*/
@property (nonatomic) CGFloat cameraTorchWarningCornerRadius;

/**
 * Reticle error color. Same for dark mode.
 *
 * Default: Microblink red
*/
@property (nonatomic) UIColor *captureReticleErrorColor;

/**
 * Need help tootlip background color. Same as dark mode.
 *
 * Default: Microblink blue
*/
@property (nonatomic) UIColor *captureTooltipBackgroundColor;

/**
 * Need help tootlip text color. Same as dark mode.
 *
 * Default: white
*/
@property (nonatomic) UIColor *captureTooltipTextColor;

/**
 * Need help tootlip corner radius.
 *
 * Default: 4
*/
@property (nonatomic) CGFloat captureTooltipCornerRadius;

/**
 * Initial onboarding alert view title color. Same for dark mode.
 *
 * Default: Microblink blue
*/
@property (nonatomic) UIColor *captureOnboardingAlertViewTitleTextColor;

/**
 * Initial onboarding alert view font.
 *
 * Default: SystemFont 17pt Semibold
*/
@property (nonatomic) UIFont *captureOnboardingAlertViewTitleFont;

/**
 * Initial onboarding alert view title color. Same for dark mode.
 *
 * Default: Label
*/
@property (nonatomic) UIColor *captureOnboardingAlertViewMessageTextColor;

/**
 * Initial onboarding alert view font.
 *
 * Default: SystemFont 14pt Regular
*/
@property (nonatomic) UIFont *captureOnboardingAlertViewMessageFont;

/**
 * Initial onboarding alert view title color. Same for dark mode.
 *
 * Default: Microblink blue
*/
@property (nonatomic) UIColor *captureOnboardingAlertViewDoneButtonTextColor;

/**
 * Initial onboarding alert view font.
 *
 * Default: Microblink blue
*/
@property (nonatomic) UIFont *captureOnboardingAlertViewDoneButtonFont;

/**
 * Need help tutorial view title text color.
 *
 * Default: Microblink blue
*/
@property (nonatomic) UIColor *captureTutorialViewTitleTextColor;

/**
 * Need help tutorial view title font.
 *
 * Default: SystemFont 22pt SemiBold
*/
@property (nonatomic) UIFont *captureTutorialViewTitleFont;

/**
 * Need help tutorial view message text color.
 *
 * Default: Label
*/
@property (nonatomic) UIColor *captureTutorialViewMessageTextColor;

/**
 * Need help tutorial view message font.
 *
 * Default: SystemFont 15pt
*/
@property (nonatomic) UIFont *captureTutorialViewMessageFont;

/**
 * Need help tutorial view action buttons text color.
 *
 * Default: Microblink blue
*/
@property (nonatomic) UIColor *captureTutorialViewActionButtonsTextColor;

/**
 * Need help tutorial view action button next and done font.
 *
 * Default: SystemFont 17pt Bold
*/
@property (nonatomic) UIFont *captureTutorialViewActionButtonNextFont;

/**
 * Need help tutorial view action button close and back font.
 *
 * Default: SystemFont 17pt
*/
@property (nonatomic) UIFont *captureTutorialViewActionButtonCloseFont;

/**
 * Need help tutorial view page control color.
 *
 * Default: Microblink blue
*/
@property (nonatomic) UIColor *captureTutorialViewPageControlColor;

/**
 * First image in document flip animation when the first side is scanned.
 *
 * Default: document-front
 */
@property (nonatomic) UIImage *flipViewFirstSideDocumentImage;

/**
 * Second image in document flip animation when the first side is scanned.
 *
 * Default: document-back
 */
@property (nonatomic) UIImage *flipViewSecondSideDocumentImage;

/**
 * Close capture view controller image.
 *
 * Default: close
 */
@property (nonatomic) UIImage *closeCaptureViewControllerImage;

/**
 * Image when torch is enabled.
 *
 * Default: torch_on
 */
@property (nonatomic) UIImage *torchOnImage;

/**
 * Image when torch is enabled.
 *
 * Default: torch_off
 */
@property (nonatomic) UIImage *torchOffImage;

@end

NS_ASSUME_NONNULL_END
