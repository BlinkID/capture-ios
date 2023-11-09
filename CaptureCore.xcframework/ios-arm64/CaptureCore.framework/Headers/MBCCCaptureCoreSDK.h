// Created by Jura Skrlec on 04.04.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import <CaptureCore/MBCCCoreDefines.h>
#import <CaptureCore/MBCCLicenseError.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Entry class for Capture SDK - used for setting up license key and to add support for
 * optimisation of passing data.
 *
 * NOTE: It is strongly recommended to set the license key in the `AppDelegate`'s `didFinishLaunchingWithOptions` method.
 */
MBCC_CORE_FINAL
@interface MBCCCaptureCoreSDK : NSObject

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/**
 * Set license buffer and unlock the SDK. Application package will be used to validate the license.
 * @param licenseBuffer Byte array containing the license.
 * @param errorCallback A block that get executed when an issue with the license occurs. The only parameter represents the type of the issue.
 */
- (void)setLicenseBuffer:(NSData * _Nonnull)licenseBuffer errorCallback:(MBCCLicenseErrorBlock)errorCallback;

/**
 * Set license buffer and unlock the SDK. Also define licensee that will be used to validate the license.
 * This method can be used to unlock the SDK in library mode, i.e. when Microblink SDK is being
 * packaged inside 3rd party SDK. Unlocking Microblink SDK in library mode allows usage of
 * single license within multiple application packages.
 * @param licenseBuffer Byte array containing the license.
 * @param licensee Licensee to which license is given to.
 * @param errorCallback A block that get executed when an issue with the license occurs. The only parameter represents the type of the issue.
 */
- (void)setLicenseBuffer:(NSData * _Nonnull)licenseBuffer andLicensee:(NSString * _Nonnull)licensee errorCallback:(MBCCLicenseErrorBlock)errorCallback;

/**
 * Set license key and unlock the SDK. Application package will be used to validate the license.
 * @param base64LicenseKey License file encoded as base64 string.
 * @param errorCallback A block that get executed when an issue with the license occurs. The only parameter represents the type of the issue.
 */
- (void)setLicenseKey:(NSString * _Nonnull)base64LicenseKey errorCallback:(MBCCLicenseErrorBlock)errorCallback;

/**
 * Set license key and unlock the SDK. Also define licensee that will be used to validate the license.
 * This method can be used to unlock the SDK in library mode, i.e. when Microblink SDK is being
 * packaged inside 3rd party SDK. Unlocking Microblink SDK in library mode allows usage of
 * single license within multiple application packages.
 * @param base64LicenseKey Byte array containing the license.
 * @param licensee Licensee to which license is given to.
 * @param errorCallback A block that get executed when an issue with the license occurs. The only parameter represents the type of the issue.
 */
- (void)setLicenseKey:(NSString * _Nonnull)base64LicenseKey andLicensee:(NSString * _Nonnull)licensee errorCallback:(MBCCLicenseErrorBlock)errorCallback;

/**
 * Set the license file and unlock the SDK. Application package will be used to validate the license.
 * @param fileName The name of resource file contained in the directory specified by subdirectory. If you specify nil, the method returns the first resource file it finds with the specified extension in that directory.
 * @param extension The filename extension of the file (etc. txt). If you specify an empty string or nil, the extension is assumed not to exist and the file URL is the first file encountered that exactly matches name.
 * @param subdirectory The valid path of top-level directory in which file is located inside bundle (etc. licenseFiles/). If you specify an empty string or nil, root direcotry of bundle will be searched.
 * @param bundle NSBundle bundle required to access file.
 * @param errorCallback A block that get executed when an issue with the license occurs. The only parameter represents the type of the issue.
 */
- (void)setLicenseResource:(NSString * _Nonnull)fileName withExtension:(NSString * _Nullable)extension inSubdirectory:(NSString * _Nullable)subdirectory forBundle:(NSBundle * _Nonnull)bundle errorCallback:(MBCCLicenseErrorBlock)errorCallback;

/**
 * Set the license file and unlock the SDK. Also define licensee that will be used to validate the license.
 * This method can be used to unlock the SDK in library mode, i.e. when Microblink SDK is being
 * packaged inside 3rd party SDK. Unlocking Microblink SDK in library mode allows usage of
 * single license within multiple application packages.
 * @param fileName The name of resource file contained in the directory specified by subdirectory.
 * @param extension The filename extension of the file (etc. txt). If you specify an empty string or nil, the extension is assumed not to exist and the file URL is the first file encountered that exactly matches name.
 * @param subdirectory The valid path of top-level directory in which file is located inside bundle (etc. licenseFiles/). If you specify an empty string or nil, root direcotry of bundle will be searched.
 * @param bundle NSBundle bundle required to access file.
 * @param licensee Licensee to which license is given to.
 * @param errorCallback A block that get executed when an issue with the license occurs. The only parameter represents the type of the issue.
 */
- (void)setLicenseResource:(NSString * _Nonnull)fileName withExtension:(NSString * _Nullable)extension inSubdirectory:(NSString * _Nullable)subdirectory forBundle:(NSBundle * _Nonnull)bundle andLicensee:(NSString *)licensee errorCallback:(MBCCLicenseErrorBlock)errorCallback;

/**
 * Returns the string that contains the library build version
 *
 *  @return string that contains the library build version
 */
+ (NSString *)buildVersionString;

/// Returns the default resources bundle. If it doesn't exist, it will be nil.
+ (NSBundle *)getDefaultResourcesBundle;

/// Bundle with resources used in framework
@property (nonatomic) NSBundle *resourcesBundle;

@end

NS_ASSUME_NONNULL_END
