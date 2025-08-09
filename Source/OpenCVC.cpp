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

CVCVideoCapture CVCVideoCaptureCreate(void)
{
	return CVCVideoCaptureCreateWithIndex(0);
}

CVCVideoCapture CVCVideoCaptureCreateWithIndex(int index)
{
	try {
		cv::VideoCapture* videoCapture = new cv::VideoCapture(index);
		return (CVCVideoCapture)videoCapture;
	}
	catch (...) {}

	return NULL;
}

CVCVideoCapture CVCVideoCaptureCreateWithIndexApi(int index, int api)
{
	try {
		cv::VideoCapture* videoCapture = new cv::VideoCapture(index, api);
		return (CVCVideoCapture)videoCapture;
	}
	catch (...) {}

	return NULL;
}

void CVCVideoCaptureFree(CVCVideoCapture videoCapture) {
	// safety check
	if (videoCapture == NULL) {
		return;
	}

	delete (cv::VideoCapture*)videoCapture;
}

bool CVCVideoCaptureIsOpened(CVCVideoCapture videoCapture)
{
	return ((cv::VideoCapture*)videoCapture)->isOpened();
}

bool CVCVideoCaptureRead(CVCVideoCapture videoCapture, CVCMat image)
{
	return ((cv::VideoCapture*)videoCapture)->read(CVCMatRef(image));
}

double CVCVideoCaptureGet(CVCVideoCapture videoCapture, int propId)
{
	return ((cv::VideoCapture*)videoCapture)->get(propId);
}

bool CVCVideoCaptureSet(CVCVideoCapture videoCapture, int propId, double value)
{
	return ((cv::VideoCapture*)videoCapture)->set(propId, value);
}

CVC_EXPORT bool CVCVideoCaptureGrab(CVCVideoCapture videoCapture)
{
	return ((cv::VideoCapture*)videoCapture)->grab();
}

CVC_EXPORT bool CVCVideoCaptureRetrieve(CVCVideoCapture videoCapture, CVCMat image, int flag)
{
	return ((cv::VideoCapture*)videoCapture)->retrieve(CVCMatRef(image), flag);
}
