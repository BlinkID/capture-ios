// Created by Jura Skrlec on 12.10.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import UIKit
import CaptureCore

class CaptureResultViewController: UIViewController {
    
    let captureResultTableView = UITableView()
    let cancelButton = UIButton()
    public var analyzerResult: MBCCAnalyzerResult?

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .white
        
        cancelButton.translatesAutoresizingMaskIntoConstraints = false
        cancelButton.setTitle("Cancel", for: .normal)
        cancelButton.addTarget(self, action: #selector(cancelButtonPressed(sender:)), for: .touchUpInside)
        cancelButton.setTitleColor(.blue, for: .normal)
        
        view.addSubview(cancelButton)
        
        cancelButton.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor).isActive = true
        cancelButton.leadingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.leadingAnchor, constant: 8).isActive = true
        
        captureResultTableView.register(CaptureResultTableViewCell.self, forCellReuseIdentifier: "captureResultCell")
        captureResultTableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
        captureResultTableView.translatesAutoresizingMaskIntoConstraints = false
        captureResultTableView.dataSource = self
        captureResultTableView.delegate = self
        view.addSubview(captureResultTableView)
        
        captureResultTableView.topAnchor.constraint(equalTo: cancelButton.bottomAnchor).isActive = true
        captureResultTableView.leadingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.leadingAnchor).isActive = true
        captureResultTableView.trailingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.trailingAnchor).isActive = true
        captureResultTableView.bottomAnchor.constraint(equalTo: view.safeAreaLayoutGuide.bottomAnchor).isActive = true
    }
    
    func setUpNavigation() {
     navigationItem.title = "Capture Result"
     self.navigationController?.navigationBar.isTranslucent = false
    }
    
    @objc func cancelButtonPressed(sender: UIButton) {
        dismiss(animated: true)
    }
}

extension CaptureResultViewController: UITableViewDataSource {
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 4
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if (indexPath.row == 0) {
            let cell = tableView.dequeueReusableCell(withIdentifier: "captureResultCell", for: indexPath) as! CaptureResultTableViewCell
            cell.documentImageView.image = analyzerResult?.firstCapture?.capturedImage?.image
            cell.imageLabel.text = "First Capture Image"
            return cell
        }
        else if (indexPath.row == 1) {
            let cell = tableView.dequeueReusableCell(withIdentifier: "captureResultCell", for: indexPath) as! CaptureResultTableViewCell
            cell.documentImageView.image = analyzerResult?.firstCapture?.transformedImage?.image
            cell.imageLabel.text = "Transformed First Capture Image"
            return cell
        }
        else if (indexPath.row == 2) {
            let cell = tableView.dequeueReusableCell(withIdentifier: "captureResultCell", for: indexPath) as! CaptureResultTableViewCell
            cell.documentImageView.image = analyzerResult?.secondCapture?.capturedImage?.image
            cell.imageLabel.text = "Second Capture Image"
            return cell
        }
        else if (indexPath.row == 3) {
            let cell = tableView.dequeueReusableCell(withIdentifier: "captureResultCell", for: indexPath) as! CaptureResultTableViewCell
            cell.documentImageView.image = analyzerResult?.secondCapture?.transformedImage?.image
            cell.imageLabel.text = "Transformed Second Capture Image"
            return cell
        }
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        return cell
    }
}

extension CaptureResultViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return UITableView.automaticDimension
    }
    
    func tableView(_ tableView: UITableView, estimatedHeightForRowAt indexPath: IndexPath) -> CGFloat {
        return 250;
    }
}

class CaptureResultTableViewCell: UITableViewCell {
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        self.contentView.addSubview(imageLabel)
        
        imageLabel.topAnchor.constraint(equalTo: self.contentView.topAnchor).isActive = true
        imageLabel.leadingAnchor.constraint(equalTo: self.contentView.leadingAnchor, constant: 8).isActive = true
        
        self.contentView.addSubview(resolutionLabel)
        resolutionLabel.topAnchor.constraint(equalTo: self.imageLabel.bottomAnchor, constant: 8).isActive = true
        resolutionLabel.leadingAnchor.constraint(equalTo: self.contentView.leadingAnchor, constant: 8).isActive = true
        
        self.contentView.addSubview(documentImageView)
        documentImageView.topAnchor.constraint(equalTo: resolutionLabel.bottomAnchor, constant: 8).isActive = true
        documentImageView.centerXAnchor.constraint(equalTo: self.contentView.centerXAnchor).isActive = true
        documentImageView.bottomAnchor.constraint(equalTo: self.contentView.bottomAnchor).isActive = true
        documentImageView.heightAnchor.constraint(equalToConstant: 250).isActive = true
        documentImageView.widthAnchor.constraint(equalToConstant: 250).isActive = true
     }

     required init?(coder aDecoder: NSCoder) {
       super.init(coder: aDecoder)
    }
    
    let documentImageView: UIImageView = {
         let img = UIImageView()
         img.contentMode = .scaleAspectFit
         img.translatesAutoresizingMaskIntoConstraints = false
         return img
    }()
    
    let imageLabel:UILabel = {
        let label = UILabel()
        label.font = UIFont.boldSystemFont(ofSize: 20)
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
    
    let resolutionLabel:UILabel = {
        let label = UILabel()
        label.font = UIFont.boldSystemFont(ofSize: 18)
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
}
