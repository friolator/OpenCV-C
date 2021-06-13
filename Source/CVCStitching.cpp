//
//  CVCStitching.c
//  OpenCVC
//
//  Created by Kin-Hong Wong on 6/12/21.
//  Copyright © 2021 Gamma Ray Digital. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

CVCStitcher CVCStitcherCreate(int mode)
{
   try {
      cv::Ptr<cv::Stitcher>* stitcher = new cv::Ptr<cv::Stitcher>(cv::Stitcher::create());
      return (CVCStitcher)stitcher;
   }
   catch (...) {}
   
   return NULL;
}

void CVCStitcherFree(CVCStitcher stitcher)
{
      // safety check
   if (stitcher == NULL) {
      return;
   }
   
   delete (cv::Ptr<cv::Stitcher> *)stitcher;
}

int CVCStitcherStitch(CVCStitcher stitcher, CVCMatVector images, CVCMat pano)
{
   std::vector<cv::Mat*>* ptrVector = (std::vector<cv::Mat*>*)images;
   std::vector<cv::Mat> refVector;
   for(size_t i = 0; i < ptrVector->size(); i++) {
      refVector.push_back(*ptrVector->at(i));
   }
   
   return (*(cv::Ptr<cv::Stitcher> *)stitcher)->stitch(refVector, CVCMatRef(pano));
}

