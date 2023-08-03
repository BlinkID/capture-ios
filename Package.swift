// swift-tools-version:5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Capture",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "Capture",
            targets: ["Capture"]
            )
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "Capture",
            url: "https://github.com/BlinkID/capture-ios/releases/download/v1.0.3/Capture.xcframework.zip",
            checksum: "488efa9d7027d5d4c061ec31c6a7712933334419155fa738fb94e3f86e9006af")
    ]
)
