// Created by Jura Skrlec on 13.04.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <Capture/MBICCoreDefines.h>
#import <Capture/MBICImage.h>
#import <Capture/MBICTransformedImage.h>

NS_ASSUME_NONNULL_BEGIN

/// Document side classification returned as front, back or unknown.
typedef NS_ENUM(NSInteger, MBICSideCaptureResultSide) {
    MBICSideCaptureResultSideUnknown,
    MBICSideCaptureResultSideFront,
    MBICSideCaptureResultSideBack
};

/// Document group.
typedef NS_ENUM(NSInteger, MBICDocumentGroup) {
    MBICDocumentGroupUnknown,
    MBICDocumentGroupDL,
    MBICDocumentGroupID,
    MBICDocumentGroupPassport,
    MBICDocumentGroupPassportCard,
    MBICDocumentGroupVisa
};

/// Completness status of capture process.
typedef NS_ENUM(NSInteger, MBICCompletnessStatus) {
    MBICCompletnessStatusEmpty,
    MBICCompletnessStatusOneSideMissing,
    MBICCompletnessStatusComplete
};

@class MBICSideCaptureResult;

MBIC_CORE_FINAL
@interface MBICAnalyserResult : NSObject

/// Result of the first side capture.
/// See ``MBICSideCaptureResult`` for more details.
@property (nonatomic, nullable) MBICSideCaptureResult *firstCapture;

/// Result of the second side capture.
/// See ``MBICSideCaptureResult`` for more details.
@property (nonatomic, nullable) MBICSideCaptureResult *secondCapture;

/// Document group.
/// See ``MBICDocumentGroup`` for more details.
@property (nonatomic) MBICDocumentGroup documentGroup;

/// Completness status of capture process.
/// See ``MBICCompletnessStatus`` for more details.
@property (nonatomic) MBICCompletnessStatus completnessStatus;

@end

/// Side capture result.
MBIC_CORE_FINAL
@interface MBICSideCaptureResult : NSObject

/// Original image of the captured document, untransformed, as it was used in analysis.
/// See ``MBICImage`` for more details.
@property (nonatomic) MBICImage *capturedImage;

/// Image of a cropped and perspective-corrected document.
/// See ``MBICTransformedImage`` for more details.
@property (nonatomic) MBICTransformedImage *transformedImage;

/// Document side classification returned as front or back.
///
/// If side classification was uncertain ``MBICSideCaptureResultSideUnknown`` is returned.
///
/// See ``MBICSideCaptureResultSide`` for more details.
@property (nonatomic) MBICSideCaptureResultSide side;

@end

NS_ASSUME_NONNULL_END
