// Created by Jura Skrlec on 19.06.2024..
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MBICCaptureFilterResultType) {
    MBICCaptureFilterResultTypePassed,
    MBICCaptureFilterResultTypeFilteredOut
};

@interface MBICCaptureFilterResult : NSObject

@property (nonatomic, readonly) MBICCaptureFilterResultType type;

- (instancetype)initWithType:(MBICCaptureFilterResultType)type;

@end

@interface MBICCaptureFilterPassed : MBICCaptureFilterResult

@end

// Define the FilteredOut subclass
@interface MBICCaptureFilterFilteredOut : MBICCaptureFilterResult

@property (nonatomic, readonly, nullable) NSString *uiMessage;

- (instancetype)initWithMessage:(nullable NSString *)message;

@end

NS_ASSUME_NONNULL_END
