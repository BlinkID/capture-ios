// Created by Jura Skrlec on 19.06.2024..
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <UIKit/UIKit.h>
#import <CaptureUX/MBICCaptureFilterResult.h>

#ifndef MBICCaptureFilter_h
#define MBICCaptureFilter_h

typedef NS_ENUM(NSInteger, MBICCaptureSide) {
    MBICCaptureSideFirst,
    MBICCaptureSideSecond
};

typedef void (^MBICCompletionBlock)(MBICCaptureFilterResult *result);

@protocol MBICCaptureFilter <NSObject>

- (void)shouldAcceptFrame:(UIImage *)image side:(MBICCaptureSide)side completion:(MBICCompletionBlock)completion;
- (void)onDocumentCaptured;
- (void)cleanup;

@end

#endif /* MBICCaptureFilter_h */
