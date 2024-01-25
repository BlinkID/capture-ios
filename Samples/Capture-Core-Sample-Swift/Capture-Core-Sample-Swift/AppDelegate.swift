// Created by Jura Skrlec on 10.10.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import UIKit
import CaptureCore

@main
class AppDelegate: UIResponder, UIApplicationDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // Valid until: 2025-01-24
        MBCCCaptureCoreSDK.shared().setLicenseKey("sRwCAChjb20ubWljcm9ibGluay5DYXB0dXJlLUNvcmUtU2FtcGxlLVN3aWZ0AQptaWNyb2JsaW5rFGmzXoFHduMdE6TKrigG29w15eJ2LEIpp6o2ZXx2gF/pGkYFA4HQXLvC9DXnW29LHXBgxTnQkJSwuuOwBOU3JpENpgzJw6d68Pc7HG0BNYBTl20ouWCoV41G29Wn") { _ in
            
        };
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

