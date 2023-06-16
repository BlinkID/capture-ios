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
            url: "https://github.com/BlinkID/capture-ios/releases/download/v1.0.0/Capture.xcframework.zip",
            checksum: "a8a124dee0320c1b69824e5cb496b72f69af8bdb37b71ecd5ff3c27ff4260a9c")
    ]
)
