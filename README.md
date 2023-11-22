<p align="center" >
  <img src="https://raw.githubusercontent.com/wiki/blinkid/blinkid-android/images/logo-microblink.png" alt="Microblink" title="Microblink">
</p>

[![SwiftPM compatible](https://img.shields.io/badge/SwiftPM-compatible-brightgreen.svg)](https://swift.org/package-manager/)
[![MBCaptureCore Version](https://img.shields.io/cocoapods/v/MBCaptureCore.svg?style=flat)](https://cocoapods.org/pods/MBCaptureCore)
[![MBCaptureUX Version](https://img.shields.io/cocoapods/v/MBCaptureUX.svg?style=flat)](https://cocoapods.org/pods/MBCaptureUX)
[![Platform](https://img.shields.io/cocoapods/p/MBCaptureCore.svg?style=flat)](https://github.com/MBCaptureCore/capture-ios#)

# _Capture_ SDK for iOS

The BlinkID Capture iOS SDK gives you the ability to auto-capture high quality images of identity documents in a user-friendly way. The SDK provides you with a rectified image of the document that ensures high success rate in extracting document text or verifying the document validity.

User is guided to avoid glare, blurred images, bad lighting conditions, fingers over the document or too much tilt. The SDK is able to recognize if a document is single sided (i.e. passport) or double sided (i.e. driving license) and prompt the user to scan the back side of the document when needed.

In the results, you can get a cropped, perspective-corrected image of the document, along with the original frame. Those can be processed by your app in any way required. The SDK is lightweight and can be easily integrated into your mobile app and bland in your design.

# Table of contents
- [Requirements](#requirements)
- [Quick Start](#quick-start)
  - [Getting started with the Capture SDK](#getting-started-with-the-capture-sdk)
      - [Manual integration](#manual-integration)
      - [Using Swift Package Manager](#using-swift-package-manager)
      - [Using Cocoapods](#using-cocoapods)
    - [Referencing header file](#referencing-header-file)
    - [Initiating the capture process](#initiating-the-capture-process)
    - [License key](#license-key)
    - [Registering for capturing events](#registering-for-capturing-events)
- [Customizing the look and UX](#customizing-the-look)
- [Localization](#localization)
- [Completely custom UX with Direct API (advanced)](#direct-api)
	- [The `AnalyzerRunner`](#analyzer-runner)
- [Troubleshooting](#troubleshooting)
- [Capture SDK size](#capture-sdk-size)
- [Additional info](#additional-info)

# <a name="requirements"></a> Requirements
SDK package contains `Capture` framework and one or more sample apps that demonstrate framework integration. The framework can be deployed on iOS 13.0 or later. The framework supports Swift and Objective-C projects. **NOTE**: The SDK doesn't contain bitcode.

# <a name="quick-start"></a> Quick Start

## <a name="getting-started-with-the-capture-sdk"></a> Getting started with the Capture SDK
This Quick Start guide will get you up and performing document capture as quickly as possible. All steps described in this guide are required for the integration.

This guide closely follows the CaptureSample app in the Samples folder of this repository. We highly recommend you try to run the sample app. The sample app should compile and run on your device.

The source code of the sample app can be used as a reference during the integration.

#### <a name="manual-integration"></a> Manual integration

[Download](https://github.com/BlinkID/capture-ios/releases) latest release (Download `Capture.xcframework.zip` file or clone this repository).

- Copy `CaptureUX.xcframework` and `CaptureCore.xcframework` to your project folder.

- In your Xcode project, open the Project navigator. Drag the `CaptureUX.xcframework` and `CaptureCore.xcframework` file to your project, ideally in the Frameworks group, together with other frameworks you're using. When asked, choose "Create groups", instead of the "Create folder references" option.

- Since `CaptureUX.xcframework` and `CaptureCore.xcframework` are dynamic frameworks, you also need to add them to embedded binaries section in General settings of your target and choose option `Embed & Sign`.

- Include the additional frameworks and libraries into your project in the "Linked frameworks and libraries" section of your target settings.
	- libc++.tbd
	- libz.tbd

#### <a name="using-swift-package-manager"></a> Using Swift Package Manager

Capture SDK is available as [Swift Package](https://swift.org/package-manager/). Please check out [Swift Package Manager documentation](https://github.com/apple/swift-package-manager) if you are new to Swift Package Manager.

We provide a URL to the public package repository that you can add in Xcode:

CaptureUX

```shell
https://github.com/BlinkID/capture-ux-sp
```

CaptureCore

```shell
https://github.com/BlinkID/capture-core-sp
```

#### <a name="using-cocoapods"></a> Using Cocoapods

Capture SDK is available as [Cocopods Package](https://cocoapods.org).
We provide podspecs for each framework. Project dependencies to be managed by CocoaPods are specified in a file called `Podfile`. Create this file in the same directory as your Xcode project (`.xcodeproj`) file.

If you don't have podfile initialized run the following in your project directory.

```
pod init
```

Copy and paste the following lines into the TextEdit window:

```ruby
platform :ios, '13.0'
target 'Your-App-Name' do
    pod 'MBCaptureCore', '~> 1.2.1'
    pod 'MBCaptureUX', '~> 1.2.1'
end
```

- Install the dependencies in your project:

```shell
$ pod install
```

- From now on, be sure to always open the generated Xcode workspace (`.xcworkspace`) instead of the project file when building your project:

```shell
open <YourProjectName>.xcworkspace
```

### <a name="referencing-header-file"></a> Referencing header file

In files in which you want to use the functionality of the SDK place the import directive.

Swift

```swift
import CaptureCore
import CaptureUX
```

Objective-C

```objective-c
#import <CaptureCore/CaptureCore.h>
#import <CaptureUX/CaptureUX>
```

### <a name="initiating-the-capture-process"></a> Initiating the capture process

To initiate the capture process, first decide where in your app you want to add capture functionality. Usually, users of the capture library have a button which, when tapped, starts the scanning process. Initialization code is then placed in touch handler for that button. Here we're listing the initialization code as it looks in a touch handler method.

```swift
class ViewController: UIViewController {
    
    var captureVC: MBICCaptureViewController?
    var settings: MBICCaptureSettings?
    
    @IBAction func startCapture(_ sender: Any) {
	    settings = MBICCaptureSettings()
	    captureVC = MBICCaptureViewController(captureSettings: settings!)
	    captureVC?.delegate = self
	    captureVC?.modalPresentationStyle = .fullScreen
	    
	    present(imageCaptureVC!, animated: true)
	}
}
```

```objective-c
@interface ViewController()<MBICCaptureViewControllerDelegate> {

@property (nonatomic) MBICCaptureViewController *captureVC;
@property (nonatomic) MBICCaptureSettings * settings;

@end

@implementation ViewController

- (void) startCapture:(UIButton *)sender {
	self.settings = [[MBICCaptureSettings alloc] init];
	self.captureVC = [[MBICCaptureViewController alloc] initWithCaptureSettings: self.settings];
	self.captureVC.delegate = self;
	self.captureVC.modalPresentationStyle = UIModalPresentationFullScreen;
	
	[self presentViewController:captureVC animated:YES completion:nil];
}

@end

}
```

### <a name="license-key"></a> License key

A valid license key is required to initialize capture. You can request a **free trial license key**, after you register, at [Microblink Developer Hub](https://account.microblink.com/signin).

You can include the license key in your app by passing a string or a file with license key.
**Note** that you need to set the license key before intializing capture. Ideally in `AppDelegate`.

#### License key as string
You can pass the license key as a string, the following way:

Swift

```swift
MBICCaptureSDK.shared().setLicenseKey("LICENSE-KEY", errorCallback: block)
```

Objective-C

```objective-c
[[MBICCaptureSDK sharedInstance] setLicenseKey:@"LICENSE-KEY" errorCallback:block];
```

#### License key as file
Or you can include the license key, with the code below. Please make sure that the file that contains the license key is included in your project and is copied during **Copy Bundle Resources** build phase.

Swift

```swift
MBICCaptureSDK.shared().setLicenseResource("license-key-file", withExtension: "key", inSubdirectory: "directory-to-license-key", for: Bundle.main, errorCallback: block)
```

Objective-C

```objective-c
[[MBICCaptureSDK sharedInstance] setLicenseResource:@"license-key-file" withExtension:@"key" inSubdirectory:@"" forBundle:[NSBundle mainBundle] errorCallback:block];
```

If the licence is invalid or expired then the methods above will throw an **exception**.

### <a name="registering-for-capturing-events"></a> Registering for capturing events

To get the capture result, you need to conform to `MBICCaptureViewControllerDelegate` protocol. 

```swift
extension ViewController: MBICCaptureViewControllerDelegate
```

```objective-c
@interface ViewController : UIViewController<MBICCaptureViewControllerDelegate>
```

Implement the required method and get the result:

```swift
captureViewController(captureViewController: MBICCaptureViewController, didFinishCaptureWithResult analyserResult: MBICAnalyserResult)
```

```objective-c
- (void)captureViewController:(nonnull MBICCaptureViewController *)captureViewController didFinishCaptureWithResult:(nonnull MBICAnalyserResult *)analyserResult
```

# <a name="#customizing-the-look"></a> Customizing the look and UX

The SDK comes with the ability to customize some aspects of the UI by using the UI theming. The screens can be customized to fit your app’s look and feel by defining themes in your application that override themes from the SDK. Each theme must extend the corresponding base theme from the SDK, as described in the following sections. Customization supports dark mode.

## CaptureViewController Theme

![customization_one](https://github.com/BlinkID/capture-ios/assets/26868155/9c08db8c-0e9c-4401-9eba-50340e643272)

![customization_two](https://github.com/BlinkID/capture-ios/assets/26868155/5e38642a-e97b-437a-9f7b-6381512decdd)

![customization_three](https://github.com/BlinkID/capture-ios/assets/26868155/cd9282d3-abd0-4c38-b56f-fde5d57ee22e)

![customization_four](https://github.com/BlinkID/capture-ios/assets/26868155/231286f9-92de-4e1c-a64c-92b26895cba9)

To customize `MBICCaptureViewController`, use `MBICCaptureViewControllerTheme` in `MBICCaptureSettings` when initializing `MBICCaptureViewController` to customize your look. You can customise elements labeled on the screenshot above by providing wanted properties to `MBICCaptureViewControllerTheme `:

- **captureOnboardingAlertViewTitleTextColor**
	- messageTextColor - set custom UIColor
	- messageFont - set custom UIFont
	- titleTextColor - set custom UIColor
	- titleFont - set custom UIFont
	- doneButtonTextColor - set custom UIColor
	- doneButtonTextFont - set custom UIFont

- **captureTutorialView**
	- actionButtonCloseTextColor - set custom UIColor
	- actionButtonCloseFont.- set custom UIFont
	- actionButtonNextTextColor - set custom UIColor
	- actionButtonNextFont - set custom UIFont
	- titleTextColor - set custom UIColor
	- titleTextFont - set custom UIColor
	- messageTextColor - set custom UIColor
	- messageFont - set custom UIColor
	- pageControlColor - set custom UIColor
	
- **captureStatusView**
	- font - set custom UIFont
	- cornerRadius - set custom corner radius

- **captureSuccesScan**
	- image - change success scan image

- **captureTooltip**
	- backgroundColor - set custom UIColor
	- textColor - set custom UIColor
	- cornerRadius - set custom corner radius

- **captureHelpButton**
	- image - change help button image

- **captureReticle**
	- reticleErrorColor - change custom error UIColor

- **captureTorch**
	- torchOnImage - change custom on image
	- torchOffImage - change custom off image

- **captureClipView**
	- firstSideDocumentImage - first side flip image
	- secondSideDocumentImage - first side flip image

- **captureFlashlightWarning**/**cameraTorchWarning**
	- font - set custom UIFont
	- backgroundColor - set custom UIColor
	- textColor - set custom UIColor
	- cornerRadius - set custom corner radius

## <a name="localization"></a> Localization

The SDK supports English language.

If you would like us to support additional languages or report incorrect translation, please contact us at [help.microblink.com](http://help.microblink.com).

If you want to add additional languages yourself or change existing translations, you need to set `customLocalizationFileName` property on `MBICCaptureUISDK` object to your strings file name.

For example, let's say that we want to change text "Scan the front side of a document" to "Scan the front side" in BlinkID sample project. This would be the steps:

* Find the translation key in en.strings file inside Capture.xcframework
* Add a new file MyTranslations.strings to the project by using "Strings File" template
* With MyTranslations.string open, in File inspector tap "Localize..." button and select English
* Add the translation key "mbic_scan_the_front_side" and the value "Scan the front side" to MyTranslations.strings
* Finally in AppDelegate.swift in method `application(_:, didFinishLaunchingWithOptions:)` add `MBICCaptureUISDK.shared().customLocalizationFileName = "MyTranslations"`

Also, you can change our .strings files directly in frameowrk. Go to Capture.framework and replace them.

# <a name="direct-api"></a> Completely custom UX with Direct API (advanced)

When using the **Direct API**, you are responsible for preparing input image stream (or static images) for analysis and building a completely custom UX from scratch based on the image-by-image feedback from the SDK. 

Direct API gives you more flexibility with the cost of a significantly larger integration effort. For example, if you need a camera, you will be responsible for camera management and displaying real-time user guidance.

Check out our [Direct API sample app](https://github.com/BlinkID/capture-ios/tree/main/Samples/Capture-Core-Sample-Swift/Capture-Core-Sample-Swift) for the implementation.

### Adding _Capture_ SDK dependency for Direct API

For Direct API, you need only Capture SDK core library: **CaptureCore**, CaptureUX is not needed.

## <a name="analyzer-runner"></a> The `MBCCAnalyzerRunner`

For the Direct API integration, use the [MBCCAnalyzerRunner](https://blinkid.github.io/capture-core-sp/documentation/capturecore/).  It is a singleton object, meaning it is possible to capture a single document at a time.

Like in the default UX, you can configure the `MBCCAnalyzerRunner` with desired [MBCCAnalyzerSettings](https://blinkid.github.io/capture-core-sp/documentation/capturecore/). It is allowed to update settings at any time during analysis.

```kotlin
AnalyzerRunner.settings = AnalyzerSettings(
    // set supported options
)
```

When starting the analysis of the next document, be sure that Analyzer has been reset to the initial state:

```swift
MBCCAnalyzerRunner.shared().reset()
```

```objective-c
[MBCCAnalyzerRunner sharedInstance] reset];
```

During analysis and after analysis is done, the current result is available via [MBCCFrameAnalysisResult](https://blinkid.github.io/capture-core-sp/documentation/capturecore/).

After analysis is done, and you don't need the `MBCCAnalyzerRunner` anymore, be sure to terminate it to release the allocated memory for processing:

```swift
MBCCAnalyzerRunner.shared().terminate()
```

```objective-c
[MBCCAnalyzerRunner sharedInstance] terminate]
```

After terminating, the `MBCCAnalyzerRunner` could be used later again. Just start feeding the frames for the next document.


### <a name="direct-api-image-stream"></a> Analyzing the stream of images

When you have a larger number of images coming from the stream, e.g. camera stream or pre-recorded
video stream, use [MBCCAnalyzerRunner analyzeStreamImage](https://blinkid.github.io/capture-core-sp/documentation/capturecore/) method.

It is expected that you will call this method multiple times to analyze the single document and all analyzed images are considered for building the final result.
		
For each frame, all relevant info for the current status of the analysis and the capture process
is returned by [didAnalyzeFrameWithResult](https://blinkid.github.io/capture-core-sp/documentation/capturecore/) delegate as [MBCCFrameAnalysisResult](https://blinkid.github.io/capture-core-sp/documentation/capturecore/), which could be used to guide the user through the scanning process and give real-time feedback.

When [MBCCFrameAnalysisResult captureState](https://blinkid.github.io/capture-core-sp/documentation/capturecore/) becomes `MBCCCaptureStateDocumentCaptured`, this means that the document has been successfully captured and you can use the result as a final capture result. To immediately reset the Analyzer to its initial state and avoid further result changes, you can use `MBCCAnalyzerRunner.shared().detachResult()`.

### <a name="direct-api-few-images"></a> Analyzing a few images (usually one or two)

When you have a fixed number of images to analyze, e.g. one (or few) for the front side
and another (or few) for the back side of the document, use [MBCCAnalyzerRunner analyzeImage](https://blinkid.github.io/capture-core-sp/documentation/capturecore/), which is optimized for single image analysis.

Make sure that you have set appropriate settings to enable capturing of the document side from the single image:

```swift
MBCCAnalyzerRunner.shared().settings.captureStrategy = .singleFrame
```

```objective-c
[MBCCAnalyzerRunner sharedInstance].settings.captureStrategy = MBCCCaptureStrategySingleFrame
```

# <a name="troubleshooting"></a> Troubleshooting

## <a name="troubleshooting-integration-problems"></a> Integration problems

In case of problems with integration of the SDK, first make sure that you have tried integrating it into Xcode by following [integration instructions](#quick-start).

If you have followed [Xcode integration instructions](#quick-start) and are still having integration problems, please contact us at [help.microblink.com](http://help.microblink.com).

## <a name="troubleshooting-sdk-problems"></a> SDK problems

In case of problems with using the SDK, you should do as follows:

### <a name="troubleshooting-licensing-problems"></a> Licencing problems

If you are getting "invalid licence key" error or having other licence-related problems (e.g. some feature is not enabled that should be or there is a watermark on top of camera), first check the console. All licence-related problems are logged to error log so it is easy to determine what went wrong.

When you have determine what is the licence-relate problem or you simply do not understand the log, you should contact us [help.microblink.com](http://help.microblink.com). When contacting us, please make sure you provide following information:

* exact Bundle ID of your app (from your `info.plist` file)
* licence that is causing problems
* please stress out that you are reporting problem related to iOS version of Capture SDK
* if unsure about the problem, you should also provide excerpt from console containing licence error

### <a name="troubleshooting-other-problems"></a> Other problems

If you are having problems with scanning certain items, undesired behaviour on specific device(s), crashes inside Capture SDK or anything unmentioned, please do as follows:
	
* Contact us at [help.microblink.com](http://help.microblink.com) describing your problem and provide following information:
	* log file obtained in previous step
	* high resolution scan/photo of the item that you are trying to scan
	* information about device that you are using
	* please stress out that you are reporting problem related to iOS version of Capture SDK

# <a name="capture-sdk-size"></a> Capture SDK size

Capture is really lightweight SDK. Compressed size is just **2.1MB**. SDK size calculation is done by [creating an App Size Report with Xcode](https://developer.apple.com/documentation/xcode/reducing-your-app-s-size), one with and one without the SDK.
Here is the SDK *App Size Report* for iPhone:

| Size | App + On Demand Resources size | App size |
| --- |:-------------:| :----------------:|
| compressed | 2.1 MB | 2.1 MB |
| uncompressed | 3.1 MB | 3.1 MB |

The uncompressed size is equivalent to the size of the installed app on the device, and the compressed size is the download size of your app.
You can find the *App Size Report* [here](https://github.com/BlinkID/core-ios/tree/master/size-report).

# <a name="info"></a> Additional info

Complete API references can be found:

* [CaptureUX](http://blinkid.github.io/capture-ux-sp/documentation/captureux/) 
* [CaptureCore](http://blinkid.github.io/capture-core-sp/documentation/capturecore/)

For any other questions, feel free to contact us at [help.microblink.com](http://help.microblink.com).
