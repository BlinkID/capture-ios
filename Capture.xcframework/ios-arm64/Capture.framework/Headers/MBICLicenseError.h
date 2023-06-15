// Created by Jura Skrlec on 05.04.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>

extern NSString * const MBICLicenseErrorNotification;

typedef NS_ENUM(NSInteger, MBICLicenseError) {
    MBICLicenseErrorNetworkRequired,
    MBICLicenseErrorUnableToDoRemoteLicenceCheck,
    MBICLicenseErrorLicenseIsLocked,
    MBICLicenseErrorLicenseCheckFailed,
    MBICLicenseErrorInvalidLicense,
    MBICLicenseErrorPermissionExpired,
    MBICLicenseErrorPayloadCorrupted,
    MBICLicenseErrorPayloadSignatureVerificationFailed,
    MBICLicenseErrorIncorrectTokenState
};

typedef void(^MBICLicenseErrorBlock)(MBICLicenseError licenseError);
