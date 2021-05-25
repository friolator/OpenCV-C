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
