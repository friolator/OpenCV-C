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


#endif /* CVCPRIVATE_H */
