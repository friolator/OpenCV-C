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

// Rect
CVCRect CVCRectCreate(int x, int y, int width, int height)
{
   try {
      cv::Rect *rect = new cv::Rect(x, y, width, height);
      return (CVCRect)rect;
      
   } catch (...) { }
   
   return NULL;
}

void CVCRectFree(CVCRect rect)
{
   // safety check
   if (rect == NULL) {
      return;
   }
   
   delete (cv::Rect*)rect;
}

int CVCRectX(CVCRect rect)
{
   return ((cv::Rect*)rect)->x;
}

int CVCRectY(CVCRect rect)
{
   return ((cv::Rect*)rect)->y;
}

int CVCRectWidth(CVCRect rect)
{
   return ((cv::Rect*)rect)->width;
}

int CVCRectHeight(CVCRect rect)
{
   return ((cv::Rect*)rect)->height;
}

int CVCRectArea(CVCRect rect)
{
   return ((cv::Size*)rect)->area();
}

bool CVCRectEmpty(CVCRect rect)
{
   return ((cv::Rect*)rect)->empty();
}

CVCMat CVCMatCreate(void)
{
	try {
		cv::Mat *mat = new cv::Mat();
		return (CVCMat)mat;
	} catch (...) { }

	return NULL;
}

CVCMat CVCMatCreate1(int rows, int cols, int type)
{
    try {
        cv::Mat* mat = new cv::Mat(rows, cols, type);
        return (CVCMat)mat;
    }
    catch (...) {}

    return NULL;
}


CVCMat CVCMatCreate2(int rows, int cols, int type, void* data)
{
    try {
        cv::Mat* mat = new cv::Mat(rows, cols, type, data);
        return (CVCMat)mat;
    }
    catch (...) {}

    return NULL;
}

void CVCMatFree(CVCMat mat)
{
	// safety check
	if (mat == NULL) {
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
   cv::Mat *roi = new cv::Mat(ConstCVCMatRef(mat)(CVCRectRef(rect)));
   return (CVCMat)roi;
}

// InputArray
CVCInputArray CVCInputArrayCreate(void)
{
    try {
        cv::_InputArray* inputArray = new cv::_InputArray();
        return (CVCInputArray)inputArray;
    }
    catch (...) {}

    return NULL;
}

CVCInputArray CVCInputArrayCreateFromCVCMatVector(CVCMatVector matVector)
{
    try {
        cv::_InputArray* inputArray = new cv::_InputArray(ConstCVCMatVectorRef(matVector));
        return (CVCInputArray)inputArray;
    }
    catch (...) {}

    return NULL;
}

void CVCInputArrayFree(CVCInputArray mat)
{
    // safety check
    if (mat == NULL) {
        return;
    }
    delete (cv::_InputArray*)mat;
}

// OutputArray
CVCOutputArray CVCOutputArrayCreate(void)
{
    try {
        cv::_OutputArray* mat = new cv::_OutputArray();
        return (CVCOutputArray)mat;
    }
    catch (...) {}

    return NULL;
}

void CVCOutputArrayFree(CVCOutputArray mat)
{
    // safety check
    if (mat == NULL) {
        return;
    }
    delete (cv::_OutputArray*)mat;
}

// InputOutputArray
CVCInputOutputArray CVCInputOutputArrayCreate(void)
{
    try {
        cv::_InputOutputArray* mat = new cv::_InputOutputArray();
        return (CVCInputOutputArray)mat;
    }
    catch (...) {}

    return NULL;
}

void CVCInputOutputArrayFree(CVCInputOutputArray mat)
{
    // safety check
    if (mat == NULL) {
        return;
    }
    delete (cv::_InputOutputArray*)mat;
}

// Vector of Mat
CVCMatVector CVCMatVectorCreate(void)
{
   try {
      std::vector<cv::Mat*> *matVector = new std::vector<cv::Mat*>();
      return (CVCMatVector)matVector;
   } catch (...) { }
   
   return NULL;
}

void CVCMatVectorFree(CVCMatVector matVector)
{
      // safety check
   if (matVector == NULL) {
      return;
   }
   
   delete (std::vector<cv::Mat*>*)matVector;
}

size_t CVCMatVectorSize(CVCMatVector matVector)
{
   return (*(std::vector<cv::Mat*>*)matVector).size();
}

CVCMat CVCMatVectorAt(CVCMatVector matVector, size_t index)
{
   return (CVCMat)(*(std::vector<cv::Mat*>*)matVector).at(index);
}

void CVCMatVectorPushBack(CVCMatVector matVector, CVCMat mat)
{
   (*(std::vector<cv::Mat*>*)matVector).push_back(CVCMatPtr(mat));
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
   if (rectVector == NULL) {
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
   return CVCRectCreate(rect.x, rect.y, rect.width, rect.height);
}

void CVCRectVectorPushBack(CVCRectVector rectVector, CVCRect rect)
{
   CVCRectVectorRef(rectVector).push_back(CVCRectRef(rect));
}

// Vector of int
CVCIntVector CVCIntVectorCreate(void)
{
   try {
      std::vector<int> *intVector = new std::vector<int>();
      return (CVCIntVector)intVector;
   } catch (...) { }
   
   return NULL;
}

void CVCIntVectorFree(CVCIntVector intVector)
{
      // safety check
   if (intVector == NULL) {
      return;
   }
   
   delete (std::vector<int>*)intVector;
}

size_t CVCIntVectorSize(CVCIntVector intVector)
{
   return ConstCVCIntVectorRef(intVector).size();
}

int CVCIntVectorAt(CVCIntVector intVector, size_t index)
{
   return ConstCVCIntVectorRef(intVector).at(index);
}

void CVCIntVectorPushBack(CVCIntVector intVector, int i)
{
   CVCIntVectorRef(intVector).push_back(i);
}

int * CVCIntVectorData(CVCIntVector intVector)
{
   return (int *)CVCIntVectorRef(intVector).data();
}

// Vector of float
CVCFloatVector CVCFloatVectorCreate(void)
{
   try {
      std::vector<float> *floatVector = new std::vector<float>();
      return (CVCFloatVector)floatVector;
   } catch (...) { }
   
   return NULL;
}

void CVCFloatVectorFree(CVCFloatVector floatVector)
{
      // safety check
   if (floatVector == NULL) {
      return;
   }
   
   delete (std::vector<float>*)floatVector;
}

size_t CVCFloatVectorSize(CVCFloatVector floatVector)
{
   return ConstCVCFloatVectorRef(floatVector).size();
}

float CVCFloatVectorAt(CVCFloatVector floatVector, size_t index)
{
   return ConstCVCFloatVectorRef(floatVector).at(index);
}

void CVCFloatVectorPushBack(CVCFloatVector floatVector, float f)
{
   CVCFloatVectorRef(floatVector).push_back(f);
}

float * CVCFloatVectorData(CVCFloatVector floatVector)
{
   return (float *)CVCFloatVectorRef(floatVector).data();
}
  
// Vector of unsigned char
CVCUCharVector CVCUCharVectorCreate(void)
{
   try {
      std::vector<uchar> *ucharVector = new std::vector<uchar>();
      return (CVCUCharVector)ucharVector;
   } catch (...) { }
   
   return NULL;
}

void CVCUCharVectorFree(CVCUCharVector ucharVector)
{
      // safety check
   if (ucharVector == NULL) {
      return;
   }
   
   delete (std::vector<uchar>*)ucharVector;
}

size_t CVCUCharVectorSize(CVCUCharVector ucharVector)
{
   return CVCUCharVectorRef(ucharVector).size();
}

unsigned char CVCUCharVectorAt(CVCUCharVector ucharVector, size_t index)
{
   return CVCUCharVectorRef(ucharVector).at(index);
}

void CVCUCharVectorPushBack(CVCUCharVector ucharVector, unsigned char c)
{
   CVCUCharVectorRef(ucharVector).push_back(c);
}

unsigned char * CVCUCharVectorData(CVCUCharVector ucharVector)
{
   return (unsigned char *)CVCUCharVectorRef(ucharVector).data();
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
   if (size == NULL) {
      return;
   }
   
   delete (cv::Size*)size;
}

int CVCSizeWidth(CVCSize size)
{
   return ((cv::Size*)size)->width;
}

int CVCSizeHeight(CVCSize size)
{
   return ((cv::Size*)size)->height;
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
   if (termCriteria == NULL) {
      return;
   }
   
   delete (cv::TermCriteria*)termCriteria;
}

bool CVCTermCriteriaIsValid(CVCTermCriteria termCriteria)
{
   return ((cv::TermCriteria*)termCriteria)->isValid();
}

