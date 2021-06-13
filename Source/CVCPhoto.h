//
//  CVCPhoto.h
//  OpenCVC
//
//  Created by Kin-Hong Wong on 6/13/21.
//  Copyright © 2021 Gamma Ray Digital. All rights reserved.
//

#ifndef CVCPHOTO_H
#define CVCPHOTO_H

#include <stdio.h>

/** @brief Restores the selected region in an image using the region neighborhood. */
CVC_EXPORT void CVCinpaint(CVCMat src, CVCMat inpaintMask, CVCMat dst, double inpaintRadius, int flags);

/** @brief Perform image denoising using Non-local Means Denoising algorithm */
CVC_EXPORT void CVCfastNlMeansDenoising(CVCMat src, CVCMat dst, float h, int templateWindowSize, int searchWindowSize);

/** @brief Perform image denoising using Non-local Means Denoising algorithm */
CVC_EXPORT void CVCfastNlMeansDenoising2(CVCMat src, CVCMat dst, CVCFloatVector h, int templateWindowSize, int searchWindowSize, int normType);

/** @brief Modification of fastNlMeansDenoising function for colored images */
CVC_EXPORT void CVCfastNlMeansDenoisingColored(CVCMat src, CVCMat dst, float h, float hColor, int templateWindowSize, int searchWindowSize);

/** @brief Modification of fastNlMeansDenoising function for images sequence where consecutive images have been captured in small period of time. For example video. This version of the function is for grayscale images or for manual manipulation with colorspaces. For more details see
 <http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.131.6394> */
CVC_EXPORT void CVCfastNlMeansDenoisingMulti(CVCMatVector srcImgs, CVCMat dst, int imgToDenoiseIndex, int temporalWindowSize, float h, int templateWindowSize, int searchWindowSize);

/** @brief Modification of fastNlMeansDenoising function for images sequence where consecutive images have been captured in small period of time. For example video. This version of the function is for grayscale images or for manual manipulation with colorspaces. For more details see <http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.131.6394> */
CVC_EXPORT void CVCfastNlMeansDenoisingMulti2(CVCMatVector srcImgs, CVCMat dst, int imgToDenoiseIndex, int temporalWindowSize, CVCFloatVector h, int templateWindowSize, int searchWindowSize, int normType);

/** @brief Modification of fastNlMeansDenoisingMulti function for colored images sequences */
CVC_EXPORT void CVCfastNlMeansDenoisingColoredMulti(CVCMatVector srcImgs, CVCMat dst, int imgToDenoiseIndex, int temporalWindowSize, float h, float hColor, int templateWindowSize, int searchWindowSize);

/** @brief Primal-dual algorithm is an algorithm for solving special types of variational problems (that is, finding a function to minimize some functional). As the image denoising, in particular, may be seen as the variational problem, primal-dual algorithm then can be used to perform denoising and this is exactly what is implemented. */
CVC_EXPORT void CVCdenoise_TVL1(CVCMatVector observations, CVCMat result, double lambda, int niters);

/** @brief Transforms a color image to a grayscale image. It is a basic tool in digital printing, stylized black-and-white photograph rendering, and in many single channel image processing applications @cite CL12 . */
CVC_EXPORT void CVCdecolor(CVCMat src, CVCMat grayscale, CVCMat color_boost);

enum
{
   CVC_NORMAL_CLONE = 1,
   CVC_MIXED_CLONE  = 2,
   CVC_MONOCHROME_TRANSFER = 3
};

/** @brief Image editing tasks concern either global changes (color/intensity corrections, filters, deformations) or local changes concerned to a selection. Here we are interested in achieving local changes, ones that are restricted to a region manually selected (ROI), in a seamless and effortless manner. The extent of the changes ranges from slight distortions to complete replacement by novel content @cite PM03 . */
CVC_EXPORT void CVCseamlessClone(CVCMat src, CVCMat dst, CVCMat mask, CVCPoint p, CVCMat blend, int flags);

/** @brief Given an original color image, two differently colored versions of this image can be mixed seamlessly. */
CVC_EXPORT void CVCcolorChange(CVCMat src, CVCMat mask, CVCMat dst, float red_mul, float green_mul, float blue_mul);

/** @brief Applying an appropriate non-linear transformation to the gradient field inside the selection and then integrating back with a Poisson solver, modifies locally the apparent illumination of an image. */
CVC_EXPORT void CVCilluminationChange(CVCMat src, CVCMat mask, CVCMat dst, float alpha, float beta);

/** @brief By retaining only the gradients at edge locations, before integrating with the Poisson solver, one washes out the texture of the selected region, giving its contents a flat aspect. Here Canny Edge %Detector is used. */
CVC_EXPORT void CVCtextureFlattening(CVCMat src, CVCMat mask, CVCMat dst, float low_threshold, float high_threshold, int kernel_size);

enum
{
   CVC_RECURS_FILTER = 1,
   CVC_NORMCONV_FILTER = 2
};

/** @brief Filtering is the fundamental operation in image and video processing. Edge-preserving smoothing filters are used in many different applications @cite EM11 . */
CVC_EXPORT void CVCedgePreservingFilter(CVCMat src, CVCMat dst, int flags, float sigma_s, float sigma_r);

/** @brief This filter enhances the details of a particular image. */
CVC_EXPORT void CVCdetailEnhance(CVCMat src, CVCMat dst, float sigma_s, float sigma_r);

/** @brief Pencil-like non-photorealistic line drawing */
CVC_EXPORT void CVCpencilSketch(CVCMat src, CVCMat dst1, CVCMat dst2, float sigma_s, float sigma_r, float shade_factor);

/** @brief Stylization aims to produce digital imagery with a wide variety of effects not focused on photorealism. Edge-aware filters are ideal for stylization, as they can abstract regions of low contrast while preserving, or enhancing, high-contrast features. */
CVC_EXPORT void CVCstylization(CVCMat src, CVCMat dst, float sigma_s, float sigma_r);

#endif /* CVCPHOTO_H */
