// Created by Jura Skrlec on 06.06.2024..
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBCCTransformMatrixFactory : NSObject

@property (nonatomic) CGRect sourceRect;
@property (nonatomic) CGRect destinationRect;
@property (nonatomic) CGRect roi;

- (CGAffineTransform)transformationMatrix;

@end

NS_ASSUME_NONNULL_END
