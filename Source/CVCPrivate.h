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

#define CVCMatVectorPtr(value)      ((std::vector<cv::Mat>*)value)
#define CVCMatVectorRef(value)      (*(std::vector<cv::Mat>*)value)
#define ConstCVCMatVectorPtr(value)   ((const std::vector<cv::Mat>*)value)
#define ConstCVCMatVectorRef(value)   (*(const std::vector<cv::Mat>*)value)

#define CVCPointParam(value)	cv::Point(value.x, value.y)
#define CVCPoint2fParam(value)	cv::Point2f(value.x, value.y)
#define CVCScalarParam(value)	cv::Scalar(value.v0, value.v1, value.v2, value.v3)
#define CVCSizeParam(value)		cv::Size(value.width, value.height)
#define CVCRectParam(value)	cv::Rect(value.x, value.y, value.width, value.height)

#define CVCRectVectorPtr(value)      ((std::vector<cv::Rect>*)value)
#define CVCRectVectorRef(value)      (*(std::vector<cv::Rect>*)value)
#define ConstCVCRectVectorPtr(value)   ((const std::vector<cv::Rect>*)value)
#define ConstCVCRectVectorRef(value)   (*(const std::vector<cv::Rect>*)value)

#define CVCFloatVectorPtr(value)      ((std::vector<float>*)value)
#define CVCFloatVectorRef(value)      (*(std::vector<float>*)value)
#define ConstCVCFloatVectorPtr(value)   ((const std::vector<float>*)value)
#define ConstCVCFloatVectorRef(value)   (*(const std::vector<float>*)value)

#define CVCSizeRef(value)     (*(cv::Size*)value)
#define CVCTermCriteriaRef(value)      (*(cv::TermCriteria*)value)


#endif /* CVCPRIVATE_H */
