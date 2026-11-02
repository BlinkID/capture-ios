// Created by Jura Skrlec on 10.05.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <CaptureUX/MBICCameraDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MBICCameraSettingsCameraResolution) {
    MBICCameraSettingsCameraResolution1080p, // AVCaptureSessionPreset1920x1080
    MBICCameraSettingsCameraResolution4K // AVCaptureSessionPreset3840x2160
};

/// Camera settings.
MBIC_CAMERA_FINAL
@interface MBICCameraSettings : NSObject

/// Set camera resolution.
/// Default: ``MBICCameraSettingsCameraResolution1080p``
@property (nonatomic) MBICCameraSettingsCameraResolution cameraResolution;

@end

NS_ASSUME_NONNULL_END
