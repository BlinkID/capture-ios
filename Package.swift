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
            url: "https://github.com/BlinkID/capture-ios/releases/download/v1.0.2/Capture.xcframework.zip",
            checksum: "6e5d4fe044d72d2b246bf660789a2a1e83e9b009026dd1e4fc05d0d2b39db5d0")
    ]
)
