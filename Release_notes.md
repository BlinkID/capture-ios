# Release notes

## v1.4.3

- Fixed issue where the `didFinishCaptureWithResult` method was sometimes triggered twice after the capture process finished, resulting in the `empty` completeness status.

## v1.4.2

- Added experimental feature `overrideAppPreferredLanguage` which allows setting the language from inside the app. As this is not aligned with [Apple guidelines](https://developer.apple.com/news/?id=u2cfuj88), customers are advised to use it ONLY if needed for transitional period. Any issues that might arise from using this setting are left on customer's discretion for solving.

## v1.4.1

- Remote license fix

## v1.4.0

- Add Capture Filter:
    - Capture filter filters capture results after each successful side capture (accepts or drops captured side)
- SDK now supports localization - see `Localizable.xcstrings`:
	- Arabic
	- Chinese (Simplified and Traditional)
	- Croatian
	- Czech
	- Dutch
	- Filipino
	- French
	- German
	- Hebrew
	- Hungarian
	- Indonesian
	- Italian
	- Malay
	- Portuguese (Portugal)
	- Romanian
	- Serbian (Latin)
	- Slovak
	- Slovenian
	- Spanish
	- Thai
	- Vietnamese 
- Internal threading optimizations

## v1.3.1

- License key remote check fix
- Change from `kCVPixelFormatType_420YpCbCr8BiPlanarFullRange` to `kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange`
- ROI fix:
    - Output connection video orientation fix
- iPhone 15 Pro fix 

## v1.3.0

- Added option `Keep DPI on image`:
    - Determines whether to preserve the captured document DPI on transformed document image. If disabled, the document DPI is downscaled to 400 DPI.
- Added option `Enforced document group`:
    - Enforces a specific document group, overriding the analyzer's document classification. This setting impacts the number of sides scanned to match the enforced group, and the way document image is transformed.

## v1.2.3

- Add privacy manifest
- Downgrade Swift tools version to 5.7

## v1.2.2

- Add portrait support for [AVCaptureConnection's videoOrientation](https://developer.apple.com/documentation/avfoundation/avcaptureconnection/1389415-videoorientation?language=objc) and [AVCaptureConnection's videoRotationAngle](https://developer.apple.com/documentation/avfoundation/avcaptureconnection/4172595-videorotationangle?language=objc)
	- Set `MBCCImage` `videoRotationAngle` to `MBCCVideoRotationAnglePortrait`: 
- `MBCCSideCaptureResult`:
	- Properties `capturedImage` and `transformedImage` are now nullable

## v1.2.1

- Bugfix:
    - License key release unlock

## v1.2.0

- Introduced `BlurPolicy`, `GlarePolicy`, `TiltPolicy` which are used to enable `strict`, `normal`, `relaxed` or `disabled` policies.
- Analyzer settings changes:
    - replaced `tiltThreshold` with `tiltPolicy`
    - replaced `ignoreGlare` with `glarePolicy`
    - replaced `ignoreBlur` with `blurPolicy`

## v1.1.1

- Cocopods Xcode 15 support

## v1.1.0

### Improvements

- SDK is available on Microblink Cocoapods and SPM repositories for easier integration. You no longer need to worry about additional dependencies required by the Capture SDK - they are included as transitive dependencies.
- Introduced support for the **Direct API** integration: 
    - When using the Direct API, you are responsible for preparing input image stream (or static images) for analysis and building a completely custom UX from scratch based on the image-by-image feedback from the SDK.
    - Direct API gives you more flexibility with the cost of a significantly larger integration effort. For example, if you need a camera, you will be responsible for camera management and displaying real-time user guidance.
- Introduced validation of the DPI requirements from the `AnalyzerSettings`:
    - If the user should position the document aligned with the device screen to occupy a larger area on the input image (enables higher capture resolution), we display the animated instructions to rotate the document or phone (to landscape or portrait).
    - If the required `minimumDocumentDpi` cannot be satisfied because of the selected camera resolution on a specific device and automatic DPI adjustment is not enabled by the `adjustMinimumDocumentDpi` flag - we display the error dialog and terminate the Capture screen immediately after the dialog dismissal.
- Added a new option `adjustMinimumDocumentDpi` to the `AnalyzerSettings`. It is used to enable minimum document DPI adjustment. If it is enabled, the minimum DPI is adjusted to the optimal value for the provided input resolution to facilitate the capture of all document groups.
- Added `dpiAdjusted` member to `SideCaptureResult`. If the document is captured at a lower DPI than requesteed by `AnalyzerSettings.minimumDocumentDpi`, a flag is set to `true`.
- Added support for online checked licenses.
- 4K Capture is now default.
- Capture experience with our CaptureUX is smoother and better.

### Minor API changes

- SDK is distributed as two separate libraries:
    - `CaptureCore` provides image analysis and capture without UX, which is enough for Direct API integration
    - `CaptureUX` depends on *CaptureCore* and contains default UX implementation with limited customization possibilities. It enables straightforward integration with minimal effort.
- Renamed all occurrences of `analyse` to `analyze` in code.

## v1.0.5

- Internal capture improvements
- Bug fix:
	- Fix a memory leak

## v1.0.4

- Bug fix:
	- Fix side capture timeout invalidation

## v1.0.3

- Bug fix:
	- Fix capture timeout for the second side capture - return the result after a timeout if valid candidate is captured

## v1.0.2

- Various capture improvements
- Bug fix:
	- Fix text colour on the help screen for dark mode

## v1.0.1

- Various capture optimiziations
- Bug fixes:
	- Fix localization issue of multiple `Cancel` text on help screen
	- Fix code signing of localization strings for custom localization
	- Fix issue where user couldn't open help screen multiple times

## v1.0.0

- Initial release of the Capture SDK for iOS
