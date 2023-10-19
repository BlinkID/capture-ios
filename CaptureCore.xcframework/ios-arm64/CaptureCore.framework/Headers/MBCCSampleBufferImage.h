// Created by Jura Skrlec on 04.04.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <CaptureCore/MBCCImage.h>
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

/// ``MBCCImage`` wrapper for SampleBufferImage.
MBCC_CORE_FINAL
@interface MBCCSampleBufferImage : MBCCImage

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithSampleBuffer:(CMSampleBufferRef)buffer NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithSampleBuffer:(CMSampleBufferRef)buffer roi:(CGRect)roi;

/// Camera buffer.
@property (nonatomic, readonly) CMSampleBufferRef buffer;

@end

NS_ASSUME_NONNULL_END
