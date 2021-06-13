//
//  CVCPhoto.c
//  OpenCVC
//
//  Created by Kin-Hong Wong on 6/13/21.
//  Copyright © 2021 Gamma Ray Digital. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

void CVCinpaint(CVCMat src, CVCMat inpaintMask, CVCMat dst, double inpaintRadius, int flags)
{
   cv::inpaint(CVCMatRef(src), CVCMatRef(inpaintMask), CVCMatRef(dst), inpaintRadius, flags);
}

void CVCfastNlMeansDenoising(CVCMat src, CVCMat dst, float h, int templateWindowSize, int searchWindowSize)
{
   cv::fastNlMeansDenoising(CVCMatRef(src), CVCMatRef(dst), h, templateWindowSize, searchWindowSize);
}

void CVCfastNlMeansDenoising2(CVCMat src, CVCMat dst, CVCFloatVector h, int templateWindowSize, int searchWindowSize, int normType)
{
   cv::fastNlMeansDenoising(CVCMatRef(src), CVCMatRef(dst), ConstCVCFloatVectorRef(h), templateWindowSize, searchWindowSize, normType);
}

void CVCfastNlMeansDenoisingColored(CVCMat src, CVCMat dst, float h, float hColor, int templateWindowSize, int searchWindowSize)
{
   cv::fastNlMeansDenoisingColored(CVCMatRef(src), CVCMatRef(dst), h, hColor, templateWindowSize, searchWindowSize);
}

void CVCfastNlMeansDenoisingMulti(CVCMatVector srcImgs, CVCMat dst, int imgToDenoiseIndex, int temporalWindowSize, float h, int templateWindowSize, int searchWindowSize)
{
   cv::fastNlMeansDenoisingMulti(CVCMatVectorRef(srcImgs), CVCMatRef(dst), imgToDenoiseIndex, temporalWindowSize, h, templateWindowSize, searchWindowSize);
}

void CVCfastNlMeansDenoisingMulti2(CVCMatVector srcImgs, CVCMat dst, int imgToDenoiseIndex, int temporalWindowSize, CVCFloatVector h, int templateWindowSize, int searchWindowSize, int normType)
{
   cv::fastNlMeansDenoisingMulti(CVCMatVectorRef(srcImgs), CVCMatRef(dst), imgToDenoiseIndex, temporalWindowSize, ConstCVCFloatVectorRef(h), templateWindowSize, searchWindowSize, normType);
}

void CVCfastNlMeansDenoisingColoredMulti(CVCMatVector srcImgs, CVCMat dst, int imgToDenoiseIndex, int temporalWindowSize, float h, float hColor, int templateWindowSize, int searchWindowSize)
{
   cv::fastNlMeansDenoisingColoredMulti(CVCMatVectorRef(srcImgs), CVCMatRef(dst), imgToDenoiseIndex, temporalWindowSize, h, hColor, templateWindowSize, searchWindowSize);
}

void CVCdenoise_TVL1(CVCMatVector observations, CVCMat result, double lambda, int niters)
{
   cv::denoise_TVL1(CVCMatVectorRef(observations), CVCMatRef(result), lambda, niters);
}

void CVCdecolor(CVCMat src, CVCMat grayscale, CVCMat color_boost)
{
   cv::decolor(CVCMatRef(src), CVCMatRef(grayscale), CVCMatRef(color_boost));
}

void CVCseamlessClone(CVCMat src, CVCMat dst, CVCMat mask, CVCPoint p, CVCMat blend, int flags)
{
   cv::seamlessClone(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(mask), CVCPointParam(p), CVCMatRef(blend), flags);
}

void CVCcolorChange(CVCMat src, CVCMat mask, CVCMat dst, float red_mul, float green_mul, float blue_mul)
{
   cv::colorChange(CVCMatRef(src), CVCMatRef(mask), CVCMatRef(dst), red_mul, green_mul, blue_mul);
}

void CVCilluminationChange(CVCMat src, CVCMat mask, CVCMat dst, float alpha, float beta)
{
   cv::illuminationChange(CVCMatRef(src), CVCMatRef(mask), CVCMatRef(dst), alpha, beta);
}

void CVCtextureFlattening(CVCMat src, CVCMat mask, CVCMat dst, float low_threshold, float high_threshold, int kernel_size)
{
   cv::textureFlattening(CVCMatRef(src), CVCMatRef(mask), CVCMatRef(dst), low_threshold, high_threshold, kernel_size);
}

void CVCedgePreservingFilter(CVCMat src, CVCMat dst, int flags, float sigma_s, float sigma_r)
{
   cv::edgePreservingFilter(CVCMatRef(src), CVCMatRef(dst), flags, sigma_s, sigma_r);
}

void CVCdetailEnhance(CVCMat src, CVCMat dst, float sigma_s, float sigma_r)
{
   cv::detailEnhance(CVCMatRef(src), CVCMatRef(dst), sigma_s, sigma_r);
}

void CVCpencilSketch(CVCMat src, CVCMat dst1, CVCMat dst2, float sigma_s, float sigma_r, float shade_factor)
{
   cv::pencilSketch(CVCMatRef(src), CVCMatRef(dst1), CVCMatRef(dst2), sigma_s, sigma_r, shade_factor);
}

void CVCstylization(CVCMat src, CVCMat dst, float sigma_s, float sigma_r)
{
   cv::stylization(CVCMatRef(src), CVCMatRef(dst), sigma_s, sigma_r);
}
