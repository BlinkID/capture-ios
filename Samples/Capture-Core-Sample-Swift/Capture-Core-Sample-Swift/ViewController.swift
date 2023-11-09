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

class ViewController: UIViewController {
    
    var imagePicker = UIImagePickerController()
    var settings = MBCCAnalyzerSettings()

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func showCameraViewController(_ sender: Any) {
        
        settings.captureSingleSide = false
        settings.captureStrategy = .default
        
        MBCCAnalyzerRunner.shared().settings = settings
        self.performSegue(withIdentifier: "CameraViewControllerSegue", sender: self)
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier  == "CameraViewControllerSegue" {
            let cameraVC = segue.destination as! CameraViewController
            cameraVC.delegate = self
        }
    }
    
    @IBAction func showPhotoGallery(_ sender: Any) {
        if UIImagePickerController.isSourceTypeAvailable(.savedPhotosAlbum){
            imagePicker.delegate = self
            imagePicker.sourceType = .savedPhotosAlbum
            imagePicker.allowsEditing = false
            
            settings.captureSingleSide = true
            settings.captureStrategy = .singleFrame
                        
            MBCCAnalyzerRunner.shared().settings = settings
            MBCCAnalyzerRunner.shared().delegate = self

            present(imagePicker, animated: true, completion: nil)
        }
    }
}

extension ViewController : UIImagePickerControllerDelegate, UINavigationControllerDelegate {
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
        
        picker.dismiss(animated: true, completion: nil)
        guard let image = info[.originalImage] as? UIImage else {
            fatalError("Error: \(info)")
        }
        
        MBCCAnalyzerRunner.shared().analyze(MBCCImage(uiImage: image))
    }
    
    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
        dismiss(animated: true, completion:nil)
    }
}

extension ViewController: MBCCAnalyzerRunnerDelegate {
    func analyzerRunner(_ analyzerRunner: MBCCAnalyzerRunner, didAnalyzeFrameWith frameAnalysisResult: MBCCFrameAnalysisResult) {
        
        let resultVC = CaptureResultViewController()
        resultVC.analyzerResult = analyzerRunner.detachResult()
        resultVC.modalPresentationStyle = .fullScreen
        
        present(resultVC, animated: true)
    }
    
    func analyzerRunner(_ analyzerRunner: MBCCAnalyzerRunner, didFailWithAnalyzerError analyzerError: MBCCAnalyzerRunnerError) {
        
    }
}

extension ViewController: CameraViewControllerDelegate {
    func didCameraViewControllerFinishCapture(cameraViewController: CameraViewController, result: MBCCAnalyzerResult) {
        cameraViewController.dismiss(animated: true)
        
        let resultVC = CaptureResultViewController()
        resultVC.analyzerResult = result
        resultVC.modalPresentationStyle = .fullScreen
        
        present(resultVC, animated: true)
    }
}

