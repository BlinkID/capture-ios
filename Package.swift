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
            url: "https://github.com/BlinkID/capture-ios/releases/download/v1.0.5/Capture.xcframework.zip",
            checksum: "5902d307e873f8c4b31fcaaecdff801bf9b583a6da5778dc4141a19d8c1697bc")
    ]
)
