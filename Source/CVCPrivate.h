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

#define CVCPointParam(value)	cv::Point(value.x, value.y)
#define CVCPoint2fParam(value)	cv::Point2f(value.x, value.y)
#define CVCScalarParam(value)	cv::Scalar(value.v0, value.v1, value.v2, value.v3)
#define CVCSizeParam(value)		cv::Size(value.width, value.height)
#define CVCRectParam(value)	cv::Rect(value.x, value.y, value.width, value.height)

#define CVCSizeRef(value)     (*(cv::Size*)value)
#define CVCTermCriteriaRef(value)      (*(cv::TermCriteria*)value)


#endif /* CVCPRIVATE_H */
