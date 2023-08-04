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
            url: "https://github.com/BlinkID/capture-ios/releases/download/v1.0.4/Capture.xcframework.zip",
            checksum: "44a9ed482e99eb67aebcfd5fca98dcb349bfe693484c354639dbdd1b52e68b08")
    ]
)
