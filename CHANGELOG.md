# Changelog

## v1.4.3

- Fixed issue where the `didFinishCaptureWithResult` method was sometimes triggered twice after the capture process finished, resulting in the `empty` completeness status.

## v1.4.2

- Added experimental feature `overrideAppPreferredLanguage` which allows setting the language from inside the app. As this is not aligned with [Apple guidelines](https://developer.apple.com/news/?id=u2cfuj88), customers are advised to use it ONLY if needed for transitional period. Any issues that might arise from using this setting are left on customer's discretion for solving.

## v1.4.1

- No changes

## v1.4.0

- No changes

## v1.3.1

- Change from `kCVPixelFormatType_420YpCbCr8BiPlanarFullRange` to `kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange`

## v1.3.0

- No changes

## v1.2.3

- No changes

## v1.2.2

- `MBCCSideCaptureResult`:
	- Properties `capturedImage` and `transformedImage` are now nullable

## v1.2.1

- No changes

## v1.2.0

- Introduced `BlurPolicy`, `GlarePolicy`, `TiltPolicy` which are used to enable `strict`, `normal`, `relaxed` or `disabled` policies.
- Analyzer settings changes:
    - replaced `tiltThreshold` with `tiltPolicy`
    - replaced `ignoreGlare` with `glarePolicy`
    - replaced `ignoreBlur` with `blurPolicy`

## v1.1.1

- No changes

## v1.1.0

- See release notes.

## v1.0.5

- No changes

## v1.0.4

- No changes

## v1.0.3

- No changes

## v1.0.2

- No changes

## v1.0.1

- No changes

## v1.0.0

- Initial release of the Capture SDK for iOS
