// Created by Jura Skrlec on 11.10.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import UIKit
import AVFoundation
import CaptureCore

protocol CameraViewControllerDelegate: AnyObject {
    func didCameraViewControllerFinishCapture(cameraViewController: CameraViewController, result: MBCCAnalyzerResult)
}

class CameraViewController: UIViewController, AVCaptureAudioDataOutputSampleBufferDelegate, AVCaptureVideoDataOutputSampleBufferDelegate {
    
    @IBOutlet var cameraPausedLabel: UILabel!
    @IBOutlet var tooltipLabel: UILabel!
    
    public weak var delegate: CameraViewControllerDelegate?
    
    var captureSession: AVCaptureSession?
    var isPauseRecognition = false
    
    @IBOutlet weak var myView: UIView!
    
    var session: AVCaptureSession?
    var device: AVCaptureDevice?
    var input: AVCaptureDeviceInput?
    var output: AVCaptureMetadataOutput?
    var prevLayer: AVCaptureVideoPreviewLayer?
    
    let cameraQueue = DispatchQueue(label: "cameraQueue")
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        startCaptureSession()
        
        self.tooltipLabel.text = "Scan the front side"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        
        // Note that the app delegate controls the device orientation notifications required to use the device orientation.
        coordinator.animate(alongsideTransition: { (context) -> Void in
            self.prevLayer?.connection?.videoOrientation = self.transformOrientation(orientation: UIInterfaceOrientation(rawValue: UIApplication.shared.windows.first!.windowScene!.interfaceOrientation.rawValue)!)
            self.prevLayer?.frame.size = self.myView.frame.size
        }, completion: { (context) -> Void in
            
        })
        
        super.viewWillTransition(to: size, with: coordinator)
    }
    
    @IBAction func closeCamera(_ sender: Any) {
        self.dismiss(animated: true, completion: nil)
    }
    
    func addNotificationObserver() {
        NotificationCenter.default.addObserver(self, selector: #selector(CameraViewController.appplicationWillResignActive(_:)), name: UIApplication.willResignActiveNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(CameraViewController.appplicationWillEnterForeground(_:)), name: UIApplication.willEnterForegroundNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(CameraViewController.applicationDidEnterBackgroundNotification(_:)), name: UIApplication.didEnterBackgroundNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(CameraViewController.applicationWillTerminateNotification(_:)), name: UIApplication.willTerminateNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(CameraViewController.captureSessionDidStartRunning(_:)), name: .AVCaptureSessionDidStartRunning, object: nil)
        NotificationCenter.default.addObserver(self, selector :#selector(CameraViewController.captureSessionDidStopRunning(_:)), name: .AVCaptureSessionDidStopRunning, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(CameraViewController.captureSessionRuntimeErrorNotification(_:)), name: .AVCaptureSessionRuntimeError, object: nil)
    }
    
    func removeNotificationObserver() {
        NotificationCenter.default.removeObserver(self)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        addNotificationObserver()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        stopCaptureSession()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        removeNotificationObserver()
    }
    
    @objc func appplicationWillResignActive(_ note: Notification?) {
        print("Will resign active!")
    }
    
    @objc func appplicationWillEnterForeground(_ note: Notification?) {
        print("appplicationWillEnterForeground!")
        startCaptureSession()
    }
    
    @objc func applicationDidEnterBackgroundNotification(_ note: Notification?) {
        print("applicationDidEnterBackgroundNotification!")
        stopCaptureSession()
    }
    
    @objc func applicationWillTerminateNotification(_ note: Notification?) {
        print("applicationWillTerminateNotification!")
    }
    
    @objc func captureSessionDidStartRunning(_ note: Notification?) {
        print("captureSessionDidStartRunningNotification!")
        DispatchQueue.main.async { [weak self] in
            UIView.animate(withDuration: 0.3, animations: {() -> Void in
                self?.cameraPausedLabel.alpha = 0.0
            })
        }
    }
    
    @objc func captureSessionDidStopRunning(_ note: Notification?) {
        print("captureSessionDidStopRunningNotification!")
        DispatchQueue.main.async { [weak self] in
            UIView.animate(withDuration: 0.3, animations: {() -> Void in
                self?.cameraPausedLabel.alpha = 1.0
            })
        }
    }
    
    @objc func captureSessionRuntimeErrorNotification(_ note: Notification?) {
        print("captureSessionRuntimeErrorNotification!")
    }
    
    func startCaptureSession() {
        
        // Create session
        captureSession = AVCaptureSession()
        captureSession?.sessionPreset = .high
        // Init the device inputs
        let videoInput = try? AVCaptureDeviceInput(device: cameraWithPosition(AVCaptureDevice.Position.back)!)
        if let anInput = videoInput {
            captureSession?.addInput(anInput)
        }
        // setup video data output
        let videoDataOutput = AVCaptureVideoDataOutput()
        // You need to use YUV format
        videoDataOutput.videoSettings = [kCVPixelBufferPixelFormatTypeKey : kCVPixelFormatType_420YpCbCr8BiPlanarFullRange] as [String : Any]
        
        captureSession?.addOutput(videoDataOutput)
        
        if let captureConnection = videoDataOutput.connection(with: .video) {
             captureConnection.videoOrientation = .portrait
         }
        
        let queue = DispatchQueue(label: "myQueue")
        videoDataOutput.setSampleBufferDelegate(self, queue: queue)
        
        prevLayer = AVCaptureVideoPreviewLayer(session: captureSession!)
        prevLayer?.frame.size = myView.frame.size
        prevLayer?.videoGravity = AVLayerVideoGravity.resizeAspectFill
        
        prevLayer?.connection?.videoOrientation = transformOrientation(orientation: UIInterfaceOrientation(rawValue: UIApplication.shared.windows.first!.windowScene!.interfaceOrientation.rawValue)!)
        
        myView.layer.addSublayer(prevLayer!)
        
        MBCCAnalyzerRunner.shared().delegate = self
        
        cameraQueue.async { [weak self] in
            self?.captureSession?.startRunning()
        }
    }
    
    func stopCaptureSession() {
        cameraQueue.async { [weak self] in
            self?.captureSession?.stopRunning()
            self?.captureSession = nil
        }
    }
    
    // Find a camera with the specificed AVCaptureDevicePosition, returning nil if one is not found
    func cameraWithPosition(_ position: AVCaptureDevice.Position) -> AVCaptureDevice?
    {
        let deviceDescoverySession = AVCaptureDevice.DiscoverySession.init(deviceTypes: [AVCaptureDevice.DeviceType.builtInWideAngleCamera],
                                                                              mediaType: AVMediaType.video,
                                                                             position: AVCaptureDevice.Position.unspecified)
        for device in deviceDescoverySession.devices {
            if device.position == position {
                return device
            }
        }
        return nil
    }
    
    func captureOutput(_ output: AVCaptureOutput, didOutput sampleBuffer: CMSampleBuffer, from connection: AVCaptureConnection) {
        let image = MBCCSampleBufferImage(sampleBuffer: sampleBuffer)
        // For portrait
        image.imageOrientation = .right
        image.videoRotationAngle = .portrait
        
        if !isPauseRecognition {
            MBCCAnalyzerRunner.shared().analyzeStreamImage(image)
        }
    }
    
    func transformOrientation(orientation: UIInterfaceOrientation) -> AVCaptureVideoOrientation {
        switch orientation {
        case .landscapeLeft:
            return .landscapeLeft
        case .landscapeRight:
            return .landscapeRight
        case .portraitUpsideDown:
            return .portraitUpsideDown
        default:
            return .portrait
        }
    }

}

extension UIDeviceOrientation {
    var videoOrientation: AVCaptureVideoOrientation? {
        switch self {
        case .portraitUpsideDown: return .portraitUpsideDown
        case .landscapeRight: return .landscapeLeft
        case .landscapeLeft: return .landscapeRight
        case .portrait: return .portrait
        default: return nil
        }
    }
}

extension UIInterfaceOrientation {
    var videoOrientation: AVCaptureVideoOrientation? {
        switch self {
        case .portraitUpsideDown: return .portraitUpsideDown
        case .landscapeRight: return .landscapeRight
        case .landscapeLeft: return .landscapeLeft
        case .portrait: return .portrait
        default: return nil
        }
    }
}


extension CameraViewController : MBCCAnalyzerRunnerDelegate {
    func analyzerRunner(_ analyzerRunner: MBCCAnalyzerRunner, didAnalyzeFrameWith frameAnalysisResult: MBCCFrameAnalysisResult) {
        
        if (frameAnalysisResult.captureState == .sideCaptured) {
            DispatchQueue.main.async {
                self.tooltipLabel.text = "Scan the second side"
            }
        }
        else if (frameAnalysisResult.captureState == .documentCaptured) {
            isPauseRecognition = true
            DispatchQueue.main.async {
                self.tooltipLabel.text = "Document captured"
                self.delegate?.didCameraViewControllerFinishCapture(cameraViewController: self, result: analyzerRunner.detachResult())
            }
        }
    }
    
    func analyzerRunner(_ analyzerRunner: MBCCAnalyzerRunner, didFailWithAnalyzerError analyzerError: MBCCAnalyzerRunnerError) {
        
    }
}
