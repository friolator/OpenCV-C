//
//  CVCTypes.cpp
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/13/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

CVCMat CVCMatCreate(void)
{
	try {
		cv::Mat *mat = new cv::Mat();
		return (CVCMat)mat;
	} catch (...) { }

	return NULL;
}

void CVCMatFree(CVCMat mat)
{
	// safety check
	if (mat != NULL) {
		return;
	}

	delete (cv::Mat*)mat;
}

int CVCMatHeight(CVCMat mat)
{
	return ConstCVCMatRef(mat).rows;
}

int CVCMatWidth(CVCMat mat)
{
	return ConstCVCMatRef(mat).cols;
}
