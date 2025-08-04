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

// Rect
typedef void* CVCRect;

CVC_EXPORT CVCRect CVCRectCreate(int x, int y, int width, int height);
CVC_EXPORT void CVCRectFree(CVCRect size);
CVC_EXPORT int CVCRectX(CVCRect size);
CVC_EXPORT int CVCRectY(CVCRect size);
CVC_EXPORT int CVCRectWidth(CVCRect size);
CVC_EXPORT int CVCRectHeight(CVCRect size);
CVC_EXPORT int CVCRectArea(CVCRect size);
CVC_EXPORT bool CVCRectEmpty(CVCRect size);

// Mat
typedef void*	CVCMat;

CVC_EXPORT CVCMat CVCMatCreate(void);
CVC_EXPORT CVCMat CVCMatCreate1(int rows, int cols, int type);
CVC_EXPORT CVCMat CVCMatCreate2(int rows, int cols, int type, void* data);
CVC_EXPORT void CVCMatFree(CVCMat mat);
CVC_EXPORT int CVCMatHeight(CVCMat mat);
CVC_EXPORT int CVCMatWidth(CVCMat mat);
CVC_EXPORT CVCMat CVCMatRoi(CVCMat mat, CVCRect rect);
CVC_EXPORT int CVCMatType(CVCMat mat);
CVC_EXPORT int CVCMatDepth(CVCMat mat);
CVC_EXPORT const void* CVCMatDataPtr(CVCMat mat);

// Vector of Mat
typedef void* CVCMatVector;

CVC_EXPORT CVCMatVector CVCMatVectorCreate(void);
CVC_EXPORT void CVCMatVectorFree(CVCMatVector matVector);
CVC_EXPORT size_t CVCMatVectorSize(CVCMatVector matVector);
CVC_EXPORT CVCMat CVCMatVectorAt(CVCMatVector matVector, size_t index);
CVC_EXPORT void CVCMatVectorPushBack(CVCMatVector matVector, CVCMat mat);

typedef void* CVCMatRefVector;

CVC_EXPORT CVCMatRefVector CVCMatRefVectorCreate(void);
CVC_EXPORT void CVCMatRefVectorFree(CVCMatRefVector matVector);
CVC_EXPORT void CVCMatRefVectorPushBack(CVCMatRefVector matVector, CVCMat mat);

// InputArray
typedef void* CVCInputArray;

CVC_EXPORT CVCInputArray CVCInputArrayCreate(void);
CVC_EXPORT CVCInputArray CVCInputArrayCreateFromCVCMatRefVector(CVCMatRefVector mat);
CVC_EXPORT void CVCInputArrayFree(CVCInputArray array);

// OutputArray
typedef void* CVCOutputArray;

CVC_EXPORT CVCOutputArray CVCOutputArrayCreate(void);
CVC_EXPORT void CVCOutputArrayFree(CVCOutputArray array);

// InputOutputArray
typedef void* CVCInputOutputArray;

CVC_EXPORT CVCInputOutputArray CVCInputOutputArrayCreate(void);
CVC_EXPORT void CVCInputOutputArrayFree(CVCInputOutputArray array);

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
CVC_EXPORT int CVCSizeWidth(CVCSize size);
CVC_EXPORT int CVCSizeHeight(CVCSize size);
CVC_EXPORT double CVCSizeAspectRatio(CVCSize size);
CVC_EXPORT int CVCSizeArea(CVCSize size);
CVC_EXPORT bool CVCSizeEmpty(CVCSize size);

// Vector of Rect
typedef void* CVCRectVector;

CVC_EXPORT CVCRectVector CVCRectVectorCreate(void);
CVC_EXPORT void CVCRectVectorFree(CVCRectVector rectVector);
CVC_EXPORT size_t CVCRectVectorSize(CVCRectVector rectVector);
CVC_EXPORT CVCRect CVCRectVectorAt(CVCRectVector rectVector, size_t index);
CVC_EXPORT void CVCRectVectorPushBack(CVCRectVector rectVector, CVCRect rect);

// Vector of int
typedef void* CVCIntVector;

CVC_EXPORT CVCIntVector CVCIntVectorCreate(void);
CVC_EXPORT void CVCIntVectorFree(CVCIntVector intVector);
CVC_EXPORT size_t CVCIntVectorSize(CVCIntVector intVector);
CVC_EXPORT int CVCIntVectorAt(CVCIntVector intVector, size_t index);
CVC_EXPORT void CVCIntVectorPushBack(CVCIntVector intVector, int i);
CVC_EXPORT int * CVCIntVectorData(CVCIntVector intVector);

// Vector of float
typedef void* CVCFloatVector;

CVC_EXPORT CVCFloatVector CVCFloatVectorCreate(void);
CVC_EXPORT void CVCFloatVectorFree(CVCFloatVector floatVector);
CVC_EXPORT size_t CVCFloatVectorSize(CVCFloatVector floatVector);
CVC_EXPORT float CVCFloatVectorAt(CVCFloatVector floatVector, size_t index);
CVC_EXPORT void CVCFloatVectorPushBack(CVCFloatVector floatVector, float f);
CVC_EXPORT float * CVCFloatVectorData(CVCFloatVector floatVector);

// Vector of unsigned char
typedef void* CVCUCharVector;

CVC_EXPORT CVCUCharVector CVCUCharVectorCreate(void);
CVC_EXPORT void CVCUCharVectorFree(CVCUCharVector ucharVector);
CVC_EXPORT size_t CVCUCharVectorSize(CVCUCharVector ucharVector);
CVC_EXPORT unsigned char CVCUCharVectorAt(CVCUCharVector ucharVector, size_t index);
CVC_EXPORT void CVCUCharVectorPushBack(CVCUCharVector ucharVector, unsigned char c);
CVC_EXPORT unsigned char * CVCUCharVectorData(CVCUCharVector ucharVector);

// TermCriteria
typedef void* CVCTermCriteria;

enum CVCTermCriteriaType {
   CVC_COUNT=1,
   CVC_MAX_ITER=CVC_COUNT,
   CVC_EPS=2
};

CVC_EXPORT CVCTermCriteria CVCTermCriteriaCreate(int type, int maxCount, double epsilon);
CVC_EXPORT void CVCTermCriteriaFree(CVCTermCriteria);
CVC_EXPORT bool CVCTermCriteriaIsValid(CVCTermCriteria termCriteria);

#endif /* CVCTYPES_H */
