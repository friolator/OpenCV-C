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

CVCMat CVCMatRoi(CVCMat mat, CVCRect rect)
{
   cv::Mat *roi = new cv::Mat(ConstCVCMatRef(mat)(CVCRectParam(rect)));
   return (CVCMat)roi;
}

// Vector of Rect
CVCRectVector CVCRectVectorCreate(void)
{
   try {
      std::vector<cv::Rect> *rectVector = new std::vector<cv::Rect>();
      return (CVCRectVector)rectVector;
   } catch (...) { }
   
   return NULL;
}

void CVCRectVectorFree(CVCRectVector rectVector)
{
      // safety check
   if (rectVector != NULL) {
      return;
   }
   
   delete (std::vector<cv::Rect>*)rectVector;
}

size_t CVCRectVectorSize(CVCRectVector rectVector)
{
   return ConstCVCRectVectorRef(rectVector).size();
}

CVCRect CVCRectVectorAt(CVCRectVector rectVector, size_t index)
{
   cv::Rect rect = ConstCVCRectVectorRef(rectVector).at(index);
   return { rect.x, rect.y, rect.width, rect.height };
}

// Size
CVCSize CVCSizeCreate(int width, int height)
{
   try {
      cv::Size *size = new cv::Size(width, height);
      return (CVCSize)size;
      
   } catch (...) { }
   
   return NULL;
}

void CVCSizeFree(CVCSize size)
{
      // safety check
   if (size != NULL) {
      return;
   }
   
   delete (cv::Size*)size;
}

double CVCSizeAspectRatio(CVCSize size)
{
	return ((cv::Size*)size)->aspectRatio();
}

int CVCSizeArea(CVCSize size)
{
   return ((cv::Size*)size)->area();
}

bool CVCSizeEmpty(CVCSize size)
{
   return ((cv::Size*)size)->empty();
}

// Term Criteria
CVCTermCriteria CVCTermCriteriaCreate(int type, int maxCount, double epsilon)
{
   try {
      cv::TermCriteria *termCriteria = new cv::TermCriteria(type, maxCount, epsilon);
      return (CVCTermCriteria)termCriteria;
      
   } catch (...) { }
   
   return NULL;
}

void CVCTermCriteriaFree(CVCTermCriteria termCriteria)
{
      // safety check
   if (termCriteria != NULL) {
      return;
   }
   
   delete (cv::TermCriteria*)termCriteria;
}

bool CVCTermCriteriaIsValid(CVCTermCriteria termCriteria)
{
   return ((cv::TermCriteria*)termCriteria)->isValid();
}

