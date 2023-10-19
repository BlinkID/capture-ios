// Created by Jura Skrlec on 06.04.2023..
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

MBCC_CORE_FINAL
@interface MBCCCameraFrameAdjuster : NSObject

/// Roi used for camera frame adjustment.
@property (nonatomic) CGRect roi;

/// Size of adjusted image.
@property (nonatomic, readonly) CGSize apertureSize;

- (instancetype)init NS_UNAVAILABLE;

/// Initializes the adjuster with given sizes.
- (instancetype)initWithapertureSize:(CGSize)apertureSize NS_DESIGNATED_INITIALIZER;

/// Method returns adjusted roi for video processing.
- (CGRect)adjustedRoi;

@end

NS_ASSUME_NONNULL_END
