// Created by Jura Skrlec on 14.06.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import UIKit
import CaptureUX
import CaptureCore

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func startCapture(_ sender: Any) {
        
        let captureVC: MBICCaptureViewController = MBICCaptureViewController()
        
        // Set delegate.
        captureVC.delegate = self
        
        // We recommend to use it in full screen mode.
        captureVC.modalPresentationStyle = .fullScreen
        present(captureVC, animated: true)
    }
}

// Conform to MBICCaptureViewControllerDelegate
extension ViewController: MBICCaptureViewControllerDelegate {
    
    func captureViewController(captureViewController: MBICCaptureViewController, didFinishCaptureWithResult analyzerResult: MBCCAnalyzerResult) {
        // UI Changes.
        DispatchQueue.main.async {
            captureViewController.dismiss(animated: true)
            
            // Show results.
            let resultViewController = ResultViewController(analyserResult: analyzerResult)
            resultViewController.modalPresentationStyle = .fullScreen
            self.present(resultViewController, animated: true)
        }
    }

}

