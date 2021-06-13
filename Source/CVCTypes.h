//
//  CVCTypes.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/13/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#ifndef CVCTYPES_H
#define CVCTYPES_H

#ifdef _WIN32
#ifdef __cplusplus
#define CVC_EXPORT extern "C" __declspec(dllexport)
#else
#define CVC_EXPORT __declspec(dllexport)
#endif // __cplusplus
#else
#ifdef __cplusplus
#define CVC_EXPORT extern "C"
#else
#define CVC_EXPORT
#endif // __cplusplus
#endif // _WIN32

typedef void*	CVCMat;

// Rect
typedef struct CVCRect {
   int x, y, width, height;
} CVCRect;

CVC_EXPORT CVCMat CVCMatCreate(void);
CVC_EXPORT void CVCMatFree(CVCMat mat);
CVC_EXPORT int CVCMatHeight(CVCMat mat);
CVC_EXPORT int CVCMatWidth(CVCMat mat);
CVC_EXPORT CVCMat CVCMatRoi(CVCMat mat, CVCRect rect);

// Point
typedef struct CVCPoint {
	int x, y;
} CVCPoint;

typedef struct CVCPoint2f {
	float x, y;
} CVCPoint2f;

// Scalar
typedef struct CVCScalar {
	double v0, v1, v2, v3;
} CVCScalar;

// Size
typedef void* CVCSize;

CVC_EXPORT CVCSize CVCSizeCreate(int width, int height);
CVC_EXPORT void CVCSizeFree(CVCSize size);
CVC_EXPORT double CVCSizeAspectRatio(CVCSize size);
CVC_EXPORT int CVCSizeArea(CVCSize size);
CVC_EXPORT bool CVCSizeEmpty(CVCSize size);

// Vector of Rect
typedef void* CVCRectVector;

CVC_EXPORT CVCRectVector CVCRectVectorCreate(void);
CVC_EXPORT void CVCRectVectorFree(CVCRectVector rectVector);
CVC_EXPORT size_t CVCRectVectorSize(CVCRectVector rectVector);
CVC_EXPORT CVCRect CVCRectVectorAt(CVCRectVector rectVector, size_t index);

// TermCriteria
typedef void* CVCTermCriteria;

enum CVCTermCriteriaType {
   COUNT=1,
   MAX_ITER=COUNT,
   EPS=2
};

CVC_EXPORT CVCTermCriteria CVCTermCriteriaCreate(int type, int maxCount, double epsilon);
CVC_EXPORT void CVCTermCriteriaFree(CVCTermCriteria);
CVC_EXPORT bool CVCTermCriteriaIsValid(CVCTermCriteria termCriteria);

#endif /* CVCTYPES_H */
