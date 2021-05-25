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

// high gui functions
CVC_EXPORT void CVCdestroyAllWindows(void);
CVC_EXPORT void CVCimshow(const char *windowName, CVCMat image);
CVC_EXPORT int CVCwaitKey(int delay);

#endif /* OPENCVC_H */
