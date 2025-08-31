//
//  OpenCVC.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/10/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#ifndef OPENCVC_H
#define OPENCVC_H

#include <ctype.h>
#include <stdbool.h>

#include "CVCTypes.h"
#include "CVCBase.h"
#include "CVCCore.h"
#include "CVCImgCodecs.h"
#include "CVCImgProc.h"
#include "CVCObjectDetect.h"
#include "CVCPhoto.h"
#include "CVCStitching.h"

// high gui functions
CVC_EXPORT void CVCdestroyAllWindows(void);
CVC_EXPORT void CVCimshow(const char *windowName, CVCMat image);
CVC_EXPORT int CVCwaitKey(int delay);

// video functions
typedef void* CVCVideoCapture;
CVC_EXPORT CVCVideoCapture CVCVideoCaptureCreate(void);
CVC_EXPORT CVCVideoCapture CVCVideoCaptureCreateWithIndex(int index);
CVC_EXPORT CVCVideoCapture CVCVideoCaptureCreateWithIndexApi(int index, int api);
CVC_EXPORT void CVCVideoCaptureFree(CVCVideoCapture videoCapture);
CVC_EXPORT bool CVCVideoCaptureIsOpened(CVCVideoCapture videoCapture);
CVC_EXPORT bool CVCVideoCaptureRead(CVCVideoCapture videoCapture, CVCMat image);
CVC_EXPORT double CVCVideoCaptureGetDouble(CVCVideoCapture videoCapture, int propId);
CVC_EXPORT float CVCVideoCaptureGetFloat(CVCVideoCapture videoCapture, int propId);
CVC_EXPORT float64_t CVCVideoCaptureGetFloat64(CVCVideoCapture videoCapture, int propId);
CVC_EXPORT int64_t CVCVideoCaptureGetInt(CVCVideoCapture videoCapture, int propId);
CVC_EXPORT bool CVCVideoCaptureSetDouble(CVCVideoCapture videoCapture, int propId, double value);
CVC_EXPORT bool CVCVideoCaptureSetFloat(CVCVideoCapture videoCapture, int propId, float value);
CVC_EXPORT bool CVCVideoCaptureSetFloat64(CVCVideoCapture videoCapture, int propId, float64_t value);
CVC_EXPORT bool CVCVideoCaptureSetInt(CVCVideoCapture videoCapture, int propId, int64_t value);
CVC_EXPORT bool CVCVideoCaptureGrab(CVCVideoCapture videoCapture);
CVC_EXPORT bool CVCVideoCaptureRetrieve(CVCVideoCapture videoCapture, CVCMat image, int flag);

#endif /* OPENCVC_H */
