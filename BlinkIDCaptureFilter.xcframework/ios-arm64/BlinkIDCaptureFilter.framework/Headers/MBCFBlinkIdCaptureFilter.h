// Created by Jura Skrlec on 21.06.2024..
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <CaptureUX/MBICCaptureFilter.h>
#import <BlinkID/BlinkID.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MBCFBlinkIdCaptureFilterDelegate;

__attribute__((objc_subclassing_restricted))
@interface MBCFBlinkIdCaptureFilter : NSObject<MBICCaptureFilter>

@property (nonatomic, weak) id<MBCFBlinkIdCaptureFilterDelegate> delegate;

@end

@protocol MBCFBlinkIdCaptureFilterDelegate <NSObject>

@optional
- (void)blinkIdCaptureFilter:(MBCFBlinkIdCaptureFilter *)blinkIdCaptureFilter didExtractResult:(MBBlinkIdMultiSideRecognizerResult *)result;

@end

NS_ASSUME_NONNULL_END
