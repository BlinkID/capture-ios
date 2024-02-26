// Created by Jura Skrlec on 23.03.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <UIKit/UIKit.h>
#import <CaptureCore/MBCCCoreDefines.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger, MBCCVideoRotationAngle) {
    // Landscape left
    MBCCVideoRotationAngleLandscapeLeft,
    // Portrait
    MBCCVideoRotationAnglePortrait,
    // Landscape right
    MBCCVideoRotationAngleLandscapeRight,
    // Portrait upside down
    MBCCVideoRotationAnglePortraitUpsideDown
};

NS_ASSUME_NONNULL_BEGIN

@interface MBCCImage : NSObject

/// UIImage of wrapped image.
/// If this wasn't created with UIImage, UIImage will be created with first access of this property.
@property (nonatomic, readonly, nullable) UIImage *image;

/// Image orientation.
@property (nonatomic) UIImageOrientation imageOrientation;

/// Connection orientation.
/// Default: `MBCCVideoRotationAngleLandscapeRight` - landscape right.
@property (nonatomic) MBCCVideoRotationAngle videoRotationAngle;

/// Region of the image used for scanning, where the whole image is specified with CGRectMake(0.0, 0.0, 1.0, 1.0).
@property (nonatomic) CGRect roi;

/// Creates MBCCImage around UIImage.
+ (instancetype)imageWithUIImage:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
