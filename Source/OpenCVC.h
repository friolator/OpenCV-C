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
CVC_EXPORT void CVCVideoCaptureFree(CVCVideoCapture videoCapture);
CVC_EXPORT bool CVCVideoCaptureIsOpened(CVCVideoCapture videoCapture);
CVC_EXPORT bool CVCVideoCaptureRead(CVCVideoCapture videoCapture, CVCMat image);

#endif /* OPENCVC_H */
