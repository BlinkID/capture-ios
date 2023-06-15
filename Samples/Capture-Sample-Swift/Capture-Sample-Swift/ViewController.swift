// Created by Jura Skrlec on 14.06.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import UIKit
import Capture

class ViewController: UIViewController {
    
    let captureVC: MBICCaptureViewController = MBICCaptureViewController()

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func startCapture(_ sender: Any) {
        // Set delegate.
        captureVC.delegate = self
        
        // We recommend to use it in full screen mode.
        captureVC.modalPresentationStyle = .fullScreen
        present(captureVC, animated: true)
    }
}

// Conform to MBICCaptureViewControllerDelegate
extension ViewController: MBICCaptureViewControllerDelegate {
    
    // This is the required implementation.
    // This is returned on the background queue.
    func captureViewController(captureViewController: MBICCaptureViewController, didFinishCaptureWithResult analyserResult: MBICAnalyserResult) {
        
        // UI Changes.
        DispatchQueue.main.async {
            captureViewController.dismiss(animated: true)
            
            // Show results.
            let resultViewController = ResultViewController(analyserResult: analyserResult)
            resultViewController.modalPresentationStyle = .fullScreen
            self.present(resultViewController, animated: true)
        }
    }
}

