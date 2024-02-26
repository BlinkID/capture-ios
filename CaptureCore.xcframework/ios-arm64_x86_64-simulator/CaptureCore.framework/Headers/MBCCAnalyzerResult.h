// Created by Jura Skrlec on 13.04.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <CaptureCore/MBCCCoreDefines.h>
#import <CaptureCore/MBCCImage.h>
#import <CaptureCore/MBCCTransformedImage.h>

NS_ASSUME_NONNULL_BEGIN

/// Document side classification returned as front, back or unknown.
typedef NS_ENUM(NSInteger, MBCCSideCaptureResultSide) {
    MBCCSideCaptureResultSideUnknown,
    MBCCSideCaptureResultSideFront,
    MBCCSideCaptureResultSideBack
};

/// Document group.
typedef NS_ENUM(NSInteger, MBCCDocumentGroup) {
    MBCCDocumentGroupUnknown,
    MBCCDocumentGroupDL,
    MBCCDocumentGroupID,
    MBCCDocumentGroupPassport,
    MBCCDocumentGroupPassportCard,
    MBCCDocumentGroupVisa
};

/// Completness status of capture process.
typedef NS_ENUM(NSInteger, MBCCCompletnessStatus) {
    MBCCCompletnessStatusEmpty,
    MBCCCompletnessStatusOneSideMissing,
    MBCCCompletnessStatusComplete
};

@class MBCCSideCaptureResult;

/// ``MBCCAnalyzer`` result.
MBCC_CORE_FINAL
@interface MBCCAnalyzerResult : NSObject

/// Result of the first side capture.
/// See ``MBCCSideCaptureResult`` for more details.
@property (nonatomic, nullable) MBCCSideCaptureResult *firstCapture;

/// Result of the second side capture.
/// See ``MBCCSideCaptureResult`` for more details.
@property (nonatomic, nullable) MBCCSideCaptureResult *secondCapture;

/// Document group.
/// See ``MBCCDocumentGroup`` for more details.
@property (nonatomic) MBCCDocumentGroup documentGroup;

/// Completness status of capture process.
/// See ``MBCCCompletnessStatus`` for more details.
@property (nonatomic) MBCCCompletnessStatus completnessStatus;

@end

/// Side capture result.
MBCC_CORE_FINAL
@interface MBCCSideCaptureResult : NSObject

/// Original image of the captured document, untransformed, as it was used in analysis.
/// See ``MBCCImage`` for more details.
@property (nonatomic, nullable) MBCCImage *capturedImage;

/// Image of a cropped and perspective-corrected document.
/// See ``MBCCTransformedImage`` for more details.
@property (nonatomic, nullable) MBCCTransformedImage *transformedImage;

/// Document side classification returned as front or back.
///
/// If side classification was uncertain ``MBCCSideCaptureResultSideUnknown`` is returned.
///
/// See ``MBCCSideCaptureResultSide`` for more details.
@property (nonatomic) MBCCSideCaptureResultSide side;

/// Flag that indicates dpi was adjusted.
///
/// If document is captured at lower dpi than ``minimumDocumentDpi`` from ``MBCCAnalyzerSettings``,
/// flag is set to `YES`.
@property (nonatomic) BOOL dpiAdjusted;

@end

NS_ASSUME_NONNULL_END
