// Created by Jura Skrlec on 14.06.2023..
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import UIKit
import CaptureCore

class ResultViewController: UIViewController {
    
    let captureResultTableView = UITableView()
    let cancelButton = UIButton()
    var analyserResult: MBCCAnalyzerResult?
    
    init(analyserResult: MBCCAnalyzerResult) {
        self.analyserResult = analyserResult
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }

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
       
        captureResultTableView.register(ResultTableViewCell.self, forCellReuseIdentifier: "resultTableViewCell")
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
    
    @objc func cancelButtonPressed(sender: UIButton) {
        dismiss(animated: true)
    }
    
}

extension ResultViewController: UITableViewDataSource {
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 4
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if (indexPath.row == 0) {
            let cell = tableView.dequeueReusableCell(withIdentifier: "resultTableViewCell", for: indexPath) as! ResultTableViewCell
            cell.captureDocumentTitleLabel.text = "First Side Capture"
            cell.captureDocumentImageView.image = analyserResult?.firstCapture?.capturedImage.image
            return cell
        }
        else if (indexPath.row == 1) {
            let cell = tableView.dequeueReusableCell(withIdentifier: "resultTableViewCell", for: indexPath) as! ResultTableViewCell
            cell.captureDocumentTitleLabel.text = "First Side Transformed Capture"
            cell.captureDocumentImageView.image = analyserResult?.firstCapture?.transformedImage.image
            return cell
        }
        else if (indexPath.row == 2) {
            let cell = tableView.dequeueReusableCell(withIdentifier: "resultTableViewCell", for: indexPath) as! ResultTableViewCell
            cell.captureDocumentTitleLabel.text = "Second Side Capture"
            cell.captureDocumentImageView.image = analyserResult?.secondCapture?.capturedImage.image
            return cell
        }
        else if (indexPath.row == 3) {
            let cell = tableView.dequeueReusableCell(withIdentifier: "resultTableViewCell", for: indexPath) as! ResultTableViewCell
            cell.captureDocumentTitleLabel.text = "Second Side Transformed Capture"
            cell.captureDocumentImageView.image = analyserResult?.secondCapture?.transformedImage.image
            return cell
        }
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        return cell
    }
}

extension ResultViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return UITableView.automaticDimension
    }
    
    func tableView(_ tableView: UITableView, estimatedHeightForRowAt indexPath: IndexPath) -> CGFloat {
        return 250;
    }
}

class ResultTableViewCell: UITableViewCell {
    let captureDocumentImageView: UIImageView = {
         let img = UIImageView()
         img.contentMode = .scaleAspectFit
         img.translatesAutoresizingMaskIntoConstraints = false
         return img
    }()
    
    let captureDocumentTitleLabel:UILabel = {
        let label = UILabel()
        label.font = UIFont.boldSystemFont(ofSize: 20)
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        self.contentView.addSubview(captureDocumentTitleLabel)
        captureDocumentTitleLabel.topAnchor.constraint(equalTo: self.contentView.topAnchor).isActive = true
        captureDocumentTitleLabel.leadingAnchor.constraint(equalTo: self.contentView.leadingAnchor, constant: 8).isActive = true
        
        self.contentView.addSubview(captureDocumentImageView)
        captureDocumentImageView.topAnchor.constraint(equalTo: captureDocumentTitleLabel.bottomAnchor, constant: 8).isActive = true
        captureDocumentImageView.centerXAnchor.constraint(equalTo: self.contentView.centerXAnchor).isActive = true
        captureDocumentImageView.bottomAnchor.constraint(equalTo: self.contentView.bottomAnchor).isActive = true
        captureDocumentImageView.heightAnchor.constraint(equalToConstant: 250).isActive = true
        captureDocumentImageView.widthAnchor.constraint(equalToConstant: 250).isActive = true
     }
}
