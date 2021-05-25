//
//  CVCImgCodecs.cpp
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/24/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

CVCMat CVCimread(const char* filename, int flags)
{
	try {
		cv::Mat image = cv::imread(filename, flags);
		if (image.data != NULL) {
			cv::Mat *returnImage = new cv::Mat(image);
			return (CVCMat)returnImage;
		}
	} catch (...) { }

	return NULL;
}
/*
bool CVCimreadmulti(const char* filename, CV_OUT std::vector<Mat>& mats, int flags)
{
}
*/
bool CVCimwrite(const char* filename, CVCMat img, const int* params, int paramCount)
{
	// convert the parameters
	std::vector<int> cvParams;
	for (int c = 0; c < paramCount; c++) {
		cvParams.push_back(params[c]);
	}

	return cv::imwrite(filename, CVCMatRef(img), cvParams);
}
/*
bool CVCimwritemulti(const char *filename, InputArrayOfArrays img, const std::vector<int>& params = std::vector<int>())
{
}
*/
CVCMat CVCimdecode(CVCMat buf, int flags)
{
	CVCMat mat = CVCMatCreate();
	CVCMatRef(mat) = cv::imdecode(CVCMatRef(buf), flags);
	return mat;
}
/*
CVCMat CVCimdecode(CVCMat buf, int flags, CVCMat dst);
{
}

bool CVCimencode(const char* ext, CVCMat img, CV_OUT std::vector<uchar>& buf, const int* params, int paramCount)
{
	// convert the parameters
	std::vector<int> cvParams;
	for (int c = 0; c < paramCount; c++) {
		cvParams.push_back(params[c]);
	}

	// TODO: convert the buf parameter

	return cv::imencode(ext, CVCMatRef(img), buf, cvParams);
}
*/
bool CVChaveImageReader(const char* filename)
{
	return cv::haveImageReader(filename);
}

bool CVChaveImageWriter(const char* filename)
{
	return cv::haveImageWriter(filename);
}
