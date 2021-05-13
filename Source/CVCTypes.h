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

CVC_EXPORT CVCMat CVCMatCreate(void);
CVC_EXPORT void CVCMatFree(CVCMat mat);
CVC_EXPORT int CVCMatHeight(CVCMat mat);
CVC_EXPORT int CVCMatWidth(CVCMat mat);

#endif /* CVCTYPES_H */
