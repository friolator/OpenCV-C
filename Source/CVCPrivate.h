//
//  CVCPrivate.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/13/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#ifndef CVCPRIVATE_H
#define CVCPRIVATE_H

#define CVCMatPtr(value)		((cv::Mat*)value)
#define CVCMatRef(value)		(*(cv::Mat*)value)
#define ConstCVCMatPtr(value)	((const cv::Mat*)value)
#define ConstCVCMatRef(value)	(*(const cv::Mat*)value)

#define CVCInputArrayPtr(value)		((cv::_InputArray*)value)
#define CVCInputArrayRef(value)		(*(cv::_InputArray*)value)
#define ConstCVCInputArrayPtr(value)	((const cv::_InputArray*)value)
#define ConstCVCInputArrayRef(value)	(*(const cv::_InputArray*)value)

#define CVCOutputArrayPtr(value)		((cv::_OutputArray*)value)
#define CVCOutputArrayRef(value)		(*(cv::_OutputArray*)value)
#define ConstCVCOutputArrayPtr(value)	((const cv::_OutputArray*)value)
#define ConstCVCOutputArrayRef(value)	(*(const cv::_OutputArray*)value)

#define CVCInputOutputArrayPtr(value)		((cv::_InputOutputArray*)value)
#define CVCInputOutputArrayRef(value)		(*(cv::_InputOutputArray*)value)
#define ConstCVCInputOutputArrayPtr(value)	((const cv::_InputOutputArray*)value)
#define ConstCVCInputOutputArrayRef(value)	(*(const cv::_InputOutputArray*)value)

#define CVCMatVectorPtr(value)      ((std::vector<cv::Mat>*)value)
#define CVCMatVectorRef(value)      (*(std::vector<cv::Mat>*)value)
#define ConstCVCMatVectorPtr(value)   ((const std::vector<cv::Mat>*)value)
#define ConstCVCMatVectorRef(value)   (*(const std::vector<cv::Mat>*)value)

#define CVCPointParam(value)	cv::Point(value.x, value.y)
#define CVCPoint2fParam(value)	cv::Point2f(value.x, value.y)
#define CVCScalarParam(value)	cv::Scalar(value.v0, value.v1, value.v2, value.v3)

#define CVCRectVectorPtr(value)      ((std::vector<cv::Rect>*)value)
#define CVCRectVectorRef(value)      (*(std::vector<cv::Rect>*)value)
#define ConstCVCRectVectorPtr(value)   ((const std::vector<cv::Rect>*)value)
#define ConstCVCRectVectorRef(value)   (*(const std::vector<cv::Rect>*)value)

#define CVCIntVectorPtr(value)      ((std::vector<int>*)value)
#define CVCIntVectorRef(value)      (*(std::vector<int>*)value)
#define ConstCVCIntVectorPtr(value)   ((const std::vector<int>*)value)
#define ConstCVCIntVectorRef(value)   (*(const std::vector<int>*)value)

#define CVCFloatVectorPtr(value)      ((std::vector<float>*)value)
#define CVCFloatVectorRef(value)      (*(std::vector<float>*)value)
#define ConstCVCFloatVectorPtr(value)   ((const std::vector<float>*)value)
#define ConstCVCFloatVectorRef(value)   (*(const std::vector<float>*)value)

#define CVCUCharVectorPtr(value)      ((std::vector<uchar>*)value)
#define CVCUCharVectorRef(value)      (*(std::vector<uchar>*)value)
#define ConstCVCUCharVectorPtr(value)   ((const std::vector<uchar>*)value)
#define ConstCVCUCharVectorRef(value)   (*(const std::vector<uchar>*)value)

#define CVCRectPtr(value)      ((cv::Rect*)value)
#define CVCRectRef(value)     (*(cv::Rect*)value)

#define CVCSizePtr(value)      ((cv::Size*)value)
#define CVCSizeRef(value)     (*(cv::Size*)value)

#define CVCTermCriteriaRef(value)      (*(cv::TermCriteria*)value)


#endif /* CVCPRIVATE_H */
