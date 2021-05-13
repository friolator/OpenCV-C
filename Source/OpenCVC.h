//
//  OpenCVC.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/10/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#ifndef OPENCVC_H
#define OPENCVC_H

#include <ctype.h>
#include <stdbool.h>

#include "CVCTypes.h"
#include "CVCBase.h"
#include "CVCCore.h"

// image processing functions
CVC_EXPORT void CVCCanny(CVCMat inputImage, CVCMat outputEdges, double threshold1, double threshold2);
CVC_EXPORT void CVCcvtColor(CVCMat inputImage, CVCMat outputImage);
CVC_EXPORT void CVCGaussianBlur(CVCMat inputImage, CVCMat outputImage, double sigmaX, double sigmaY);
CVC_EXPORT CVCMat CVCimread(const char *filePath);
CVC_EXPORT void CVCresize(CVCMat inputImage, CVCMat outputImage, int width, int height);

// high gui functions
CVC_EXPORT void CVCdestroyAllWindows(void);
CVC_EXPORT void CVCimshow(const char *windowName, CVCMat image);
CVC_EXPORT int CVCwaitKey(int delay);

#endif /* OPENCVC_H */
