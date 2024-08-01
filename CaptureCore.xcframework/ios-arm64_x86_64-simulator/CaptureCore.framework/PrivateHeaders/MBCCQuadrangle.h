// Created by Jura Skrlec on 29.05.2024..
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBCCQuadrangle : NSObject

/** Upper left point */
@property (nonatomic) CGPoint upperLeft;

/** Upper right point */
@property (nonatomic) CGPoint upperRight;

/** Lower left point */
@property (nonatomic) CGPoint lowerLeft;

/** Lower right point */
@property (nonatomic) CGPoint lowerRight;

/**
 * Designated initializer which initializes all four corners of the quadrangle
 *
 *  @param upperLeft  upper left corner of the quadrangle
 *  @param upperRight upper right corner of the quadrangle
 *  @param lowerLeft  lower left corner of the quadrangle
 *  @param lowerRight lower right corner of the quadrangle
 *
 *  @return initialized quadrangle with four corners
 */
- (instancetype)initWithUpperLeft:(CGPoint)upperLeft
                       upperRight:(CGPoint)upperRight
                        lowerLeft:(CGPoint)lowerLeft
                       lowerRight:(CGPoint)lowerRight;

/**
 * Returns points of the quadrangle in array in the following order:
 * - upperLeft, upperRight, lowerLeft, lowerRight.
 *
 * The array contains object obtained by, e.g: [NSValue valueWithCGPoint:CGPointMake(0.0, 1.0)]
 *
 *  @return points of the quadrangle in an array
 */
- (NSArray *)toPointsArray;

/**
 * Creates new quadrangle from this quadrangle, transformed by specified affine transformation.
 */
- (instancetype)quadrangleWithTransformation:(CGAffineTransform)transform;

/**
 * Returns the center point of the Quadrangle
 * @return center point
 */
- (CGPoint)center;


@end

NS_ASSUME_NONNULL_END
