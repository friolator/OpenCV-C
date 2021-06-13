//
//  CVCStitching.h
//  OpenCVC
//
//  Created by Kin-Hong Wong on 6/12/21.
//  Copyright © 2021 Gamma Ray Digital. All rights reserved.
//

#ifndef CVCSTITCHING_H
#define CVCSTITCHING_H

#include <stdio.h>

typedef void*   CVCStitcher;

enum CVCStitcherStatus {
   CVC_OK = 0,
   CVC_ERR_NEED_MORE_IMGS = 1,
   CVC_ERR_HOMOGRAPHY_EST_FAIL = 2,
   CVC_ERR_CAMERA_PARAMS_ADJUST_FAIL = 3
};

enum CVCStitcherMode {
   CVC_PANORAMA = 0,
   CVC_SCANS = 1,
};


CVC_EXPORT CVCStitcher CVCStitcherCreate(int mode);
CVC_EXPORT void CVCStitcherFree(CVCStitcher stitcher);
CVC_EXPORT int CVCStitcherStitch(CVCStitcher stitcher, CVCMatVector images, CVCMat pano);

#endif /* CVCSTITCHING_H */
