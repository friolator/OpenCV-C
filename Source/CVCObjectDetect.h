//
//  CVCObjectDetect.h
//  OpenCVC
//
//  Created by Kin-Hong Wong on 6/12/21.
//  Copyright © 2021 Gamma Ray Digital. All rights reserved.
//

#ifndef CVCOBJECTDETECT_H
#define CVCOBJECTDETECT_H

#include <stdio.h>

typedef void*   CVCCascadeClassifier;

CVC_EXPORT CVCCascadeClassifier CVCCascadeClassifierCreate(void);
CVC_EXPORT void CVCCascadeClassifierFree(CVCCascadeClassifier cascadeClassifier);
CVC_EXPORT bool CVCCascadeClassifierLoad(CVCCascadeClassifier cascadeClassifier, const char* path);
CVC_EXPORT void CVCCascadeClassifierDetectMultiScale(CVCCascadeClassifier cascadeClassifier, CVCMat image, CVCRectVector rects, double scaleFactor, int minNeighbors, int flags, CVCSize minSize, CVCSize maxSize);

#endif /* CVCOBJECTDETECT_H */
