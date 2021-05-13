//
//  OpenCVC.cpp
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/10/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

// MARK: Image Processing

void CVCCanny(CVCMat inputImage, CVCMat outputEdges, double threshold1, double threshold2)
{
	cv::Canny(ConstCVCMatRef(inputImage), CVCMatRef(outputEdges), threshold1, threshold2);
}

void CVCcvtColor(CVCMat inputImage, CVCMat outputImage)
{
	cv::cvtColor(ConstCVCMatRef(inputImage), CVCMatRef(outputImage), cv::COLOR_RGB2GRAY);
}

void CVCGaussianBlur(CVCMat inputImage, CVCMat outputImage, double sigmaX, double sigmaY)
{
	cv::GaussianBlur(ConstCVCMatRef(inputImage), CVCMatRef(outputImage), cv::Size(0, 0), sigmaX, sigmaY, cv::BORDER_DEFAULT);
}

CVCMat CVCimread(const char *filePath)
{
	try {
		cv::Mat image = cv::imread(filePath, cv::IMREAD_COLOR);
		if (image.data != NULL) {
			cv::Mat *returnImage = new cv::Mat(image);
			return (CVCMat)returnImage;
		}
	} catch (...) { }

	return NULL;
}

void CVCresize(CVCMat inputImage, CVCMat outputImage, int width, int height)
{
	cv::resize(ConstCVCMatRef(inputImage), CVCMatRef(outputImage), cv::Size(width, height), cv::INTER_AREA);
}

// MARK: -
// MARK: High GUI

void CVCdestroyAllWindows(void)
{
	cv::destroyAllWindows();
}

void CVCimshow(const char *windowName, CVCMat image)
{
	cv::imshow(windowName, ConstCVCMatRef(image));
}

int CVCwaitKey(int delay)
{
	return cv::waitKey(delay);
}
