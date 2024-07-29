// Created by Jura Skrlec on 29.05.2024..
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <CaptureCore/MBCCQuadrangle.h>
#import <CaptureCore/MBCCDisplayableQuad.h>

NS_ASSUME_NONNULL_BEGIN

@class MBCCQuadrangle;

@interface MBCCFrameAnalysisDebugStatus : NSObject

@property (nonatomic) NSInteger sideCapturePercentage;
//@property (nonatomic, nullable) MBCCQuadrangle *quadrangle;
@property (nonatomic, nullable) MBCCDisplayableQuad *displayableQuadrangle;
@property (nonatomic, nullable) NSNumber *documentDpi;
@property (nonatomic, nullable) NSNumber *documentScale;
@property (nonatomic, nullable) NSNumber *blurScore;
@property (nonatomic, nullable) NSNumber *glareScore;
@property (nonatomic, nullable) NSNumber *darknessScore;
@property (nonatomic, nullable) NSNumber *brightnessScore;
@property (nonatomic, nullable) NSNumber *handOcclusionScore;
@property (nonatomic, nullable) NSNumber *documentQualityScore;

@end

NS_ASSUME_NONNULL_END
