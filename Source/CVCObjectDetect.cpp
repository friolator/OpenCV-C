//
//  CVCObjectDetect.c
//  OpenCVC
//
//  Created by Kin-Hong Wong on 6/12/21.
//  Copyright © 2021 Gamma Ray Digital. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

CVCCascadeClassifier CVCCascadeClassifierCreate(void)
{
   try {
      cv::CascadeClassifier* cascadeClassifier = new cv::CascadeClassifier();
      return (CVCCascadeClassifier)cascadeClassifier;
   }
   catch (...) {}
   
   return NULL;
}

void CVCCascadeClassifierFree(CVCCascadeClassifier cascadeClassifier) {
      // safety check
   if (cascadeClassifier != NULL) {
      return;
   }
   
   delete (cv::CascadeClassifier*)cascadeClassifier;
}

bool CVCCascadeClassifierLoad(CVCCascadeClassifier cascadeClassifier, const char* filename)
{
   return ((cv::CascadeClassifier*)cascadeClassifier)->load(filename);
}

void CVCCascadeClassifierDetectMultiScale(CVCCascadeClassifier cascadeClassifier, CVCMat image, CVCRectVector rects, double scaleFactor, int minNeighbors, int flags, CVCSize minSize, CVCSize maxSize)
{
   ((cv::CascadeClassifier*)cascadeClassifier)->detectMultiScale(CVCMatRef(image), CVCRectVectorRef(rects), scaleFactor, minNeighbors, flags, CVCSizeRef(minSize), CVCSizeRef(maxSize));
}
