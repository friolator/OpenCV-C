//
//  CVCImgProc.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/24/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#ifndef CVCIMGPROC_H
#define CVCIMGPROC_H

enum CVCSpecialFilter {
	CVC_FILTER_SCHARR = -1
};

enum CVCMorphTypes {
	CVC_MORPH_ERODE = 0,
	CVC_MORPH_DILATE = 1,
	CVC_MORPH_OPEN = 2,
	CVC_MORPH_CLOSE = 3,
	CVC_MORPH_GRADIENT = 4,
	CVC_MORPH_TOPHAT = 5,
	CVC_MORPH_BLACKHAT = 6,
	CVC_MORPH_HITMISS = 7
};

enum CVCMorphShapes {
	CVC_MORPH_RECT = 0,
	CVC_MORPH_CROSS = 1,
	CVC_MORPH_ELLIPSE = 2
};

enum CVCInterpolationFlags {
	CVC_INTER_NEAREST = 0,
	CVC_INTER_LINEAR = 1,
	CVC_INTER_CUBIC = 2,
	CVC_INTER_AREA = 3,
	CVC_INTER_LANCZOS4 = 4,
	CVC_INTER_LINEAR_EXACT = 5,
	CVC_INTER_NEAREST_EXACT = 6,
	CVC_INTER_MAX = 7,
	CVC_WARP_FILL_OUTLIERS = 8,
	CVC_WARP_INVERSE_MAP = 16
};

enum CVCWarpPolarMode {
	CVC_WARP_POLAR_LINEAR = 0,
	CVC_WARP_POLAR_LOG = 256
};

enum CVCInterpolationMasks {
	CVC_INTER_BITS = 5,
	CVC_INTER_BITS2 = CVC_INTER_BITS * 2,
	CVC_INTER_TAB_SIZE = 1 << CVC_INTER_BITS,
	CVC_INTER_TAB_SIZE2 = CVC_INTER_TAB_SIZE * CVC_INTER_TAB_SIZE
};

enum CVCDistanceTypes {
	CVC_DIST_USER = -1,
	CVC_DIST_L1 = 1,
	CVC_DIST_L2 = 2,
	CVC_DIST_C = 3,
	CVC_DIST_L12 = 4,
	CVC_DIST_FAIR = 5,
	CVC_DIST_WELSCH = 6,
	CVC_DIST_HUBER = 7
};

enum CVCDistanceTransformMasks {
	CVC_DIST_MASK_3 = 3,
	CVC_DIST_MASK_5 = 5,
	CVC_DIST_MASK_PRECISE = 0
};

enum CVCThresholdTypes {
	CVC_THRESH_BINARY = 0,
	CVC_THRESH_BINARY_INV = 1,
	CVC_THRESH_TRUNC = 2,
	CVC_THRESH_TOZERO = 3,
	CVC_THRESH_TOZERO_INV = 4,
	CVC_THRESH_MASK = 7,
	CVC_THRESH_OTSU = 8,
	CVC_THRESH_TRIANGLE = 16
};

enum CVCAdaptiveThresholdTypes {
	CVC_ADAPTIVE_THRESH_MEAN_C = 0,
	CVC_ADAPTIVE_THRESH_GAUSSIAN_C = 1
};

enum CVCGrabCutClasses {
	CVC_GC_BGD = 0,
	CVC_GC_FGD = 1,
	CVC_GC_PR_BGD = 2,
	CVC_GC_PR_FGD = 3
};

enum CVCGrabCutModes {
	CVC_GC_INIT_WITH_RECT = 0,
	CVC_GC_INIT_WITH_MASK = 1,
	CVC_GC_EVAL = 2,
	CVC_GC_EVAL_FREEZE_MODEL = 3
};

enum CVCDistanceTransformLabelTypes {
	CVC_DIST_LABEL_CCOMP = 0,
	CVC_DIST_LABEL_PIXEL = 1
};

enum CVCFloodFillFlags {
	CVC_FLOODFILL_FIXED_RANGE = 1 << 16,
	CVC_FLOODFILL_MASK_ONLY = 1 << 17
};

enum CVCConnectedComponentsTypes {
	CVC_CC_STAT_LEFT = 0,
	CVC_CC_STAT_TOP = 1,
	CVC_CC_STAT_WIDTH = 2,
	CVC_CC_STAT_HEIGHT = 3,
	CVC_CC_STAT_AREA = 4,
};

enum CVCConnectedComponentsAlgorithmsTypes {
	CVC_CCL_DEFAULT = -1,
	CVC_CCL_WU = 0,
	CVC_CCL_GRANA = 1,
	CVC_CCL_BOLELLI = 2,
	CVC_CCL_SAUF = 3,
	CVC_CCL_BBDT = 4,
	CVC_CCL_SPAGHETTI = 5,
};

enum CVCRetrievalModes {
	CVC_RETR_EXTERNAL = 0,
	CVC_RETR_LIST = 1,
	CVC_RETR_CCOMP = 2,
	CVC_RETR_TREE = 3,
	CVC_RETR_FLOODFILL = 4
};

enum CVCContourApproximationModes {
	CVC_CHAIN_APPROX_NONE = 1,
	CVC_CHAIN_APPROX_SIMPLE = 2,
	CVC_CHAIN_APPROX_TC89_L1 = 3,
	CVC_CHAIN_APPROX_TC89_KCOS = 4
};

enum CVCShapeMatchModes {
	CVC_CONTOURS_MATCH_I1 = 1,
	CVC_CONTOURS_MATCH_I2 = 2,
	CVC_CONTOURS_MATCH_I3 = 3
};

enum CVCHoughModes {
	HOUGH_STANDARD = 0,
	HOUGH_PROBABILISTIC = 1,
	HOUGH_MULTI_SCALE = 2,
	HOUGH_GRADIENT = 3,
	HOUGH_GRADIENT_ALT = 4,
};

enum CVCLineSegmentDetectorModes {
	CVC_LSD_REFINE_NONE = 0,
	CVC_LSD_REFINE_STD = 1,
	CVC_LSD_REFINE_ADV = 2
};

enum CVCHistCompMethods {
	CVC_HISTCMP_CORREL = 0,
	CVC_HISTCMP_CHISQR = 1,
	CVC_HISTCMP_INTERSECT = 2,
	CVC_HISTCMP_BHATTACHARYYA = 3,
	CVC_HISTCMP_HELLINGER = CVC_HISTCMP_BHATTACHARYYA,
	CVC_HISTCMP_CHISQR_ALT = 4,
	CVC_HISTCMP_KL_DIV = 5
};

enum CVCColorConversionCodes {
	CVC_COLOR_BGR2BGRA = 0,
	CVC_COLOR_RGB2RGBA = CVC_COLOR_BGR2BGRA,
	CVC_COLOR_BGRA2BGR = 1,
	CVC_COLOR_RGBA2RGB = CVC_COLOR_BGRA2BGR,
	CVC_COLOR_BGR2RGBA = 2,
	CVC_COLOR_RGB2BGRA = CVC_COLOR_BGR2RGBA,
	CVC_COLOR_RGBA2BGR = 3,
	CVC_COLOR_BGRA2RGB = CVC_COLOR_RGBA2BGR,
	CVC_COLOR_BGR2RGB = 4,
	CVC_COLOR_RGB2BGR = CVC_COLOR_BGR2RGB,
	CVC_COLOR_BGRA2RGBA = 5,
	CVC_COLOR_RGBA2BGRA = CVC_COLOR_BGRA2RGBA,
	CVC_COLOR_BGR2GRAY = 6,
	CVC_COLOR_RGB2GRAY = 7,
	CVC_COLOR_GRAY2BGR = 8,
	CVC_COLOR_GRAY2RGB = CVC_COLOR_GRAY2BGR,
	CVC_COLOR_GRAY2BGRA = 9,
	CVC_COLOR_GRAY2RGBA = CVC_COLOR_GRAY2BGRA,
	CVC_COLOR_BGRA2GRAY = 10,
	CVC_COLOR_RGBA2GRAY = 11,
	CVC_COLOR_BGR2BGR565 = 12,
	CVC_COLOR_RGB2BGR565 = 13,
	CVC_COLOR_BGR5652BGR = 14,
	CVC_COLOR_BGR5652RGB = 15,
	CVC_COLOR_BGRA2BGR565 = 16,
	CVC_COLOR_RGBA2BGR565 = 17,
	CVC_COLOR_BGR5652BGRA = 18,
	CVC_COLOR_BGR5652RGBA = 19,
	CVC_COLOR_GRAY2BGR565 = 20,
	CVC_COLOR_BGR5652GRAY = 21,
	CVC_COLOR_BGR2BGR555 = 22,
	CVC_COLOR_RGB2BGR555 = 23,
	CVC_COLOR_BGR5552BGR = 24,
	CVC_COLOR_BGR5552RGB = 25,
	CVC_COLOR_BGRA2BGR555 = 26,
	CVC_COLOR_RGBA2BGR555 = 27,
	CVC_COLOR_BGR5552BGRA = 28,
	CVC_COLOR_BGR5552RGBA = 29,
	CVC_COLOR_GRAY2BGR555 = 30,
	CVC_COLOR_BGR5552GRAY = 31,
	CVC_COLOR_BGR2XYZ = 32,
	CVC_COLOR_RGB2XYZ = 33,
	CVC_COLOR_XYZ2BGR = 34,
	CVC_COLOR_XYZ2RGB = 35,
	CVC_COLOR_BGR2YCrCb = 36,
	CVC_COLOR_RGB2YCrCb = 37,
	CVC_COLOR_YCrCb2BGR = 38,
	CVC_COLOR_YCrCb2RGB = 39,
	CVC_COLOR_BGR2HSV = 40,
	CVC_COLOR_RGB2HSV = 41,
	CVC_COLOR_BGR2Lab = 44,
	CVC_COLOR_RGB2Lab = 45,
	CVC_COLOR_BGR2Luv = 50,
	CVC_COLOR_RGB2Luv = 51,
	CVC_COLOR_BGR2HLS = 52,
	CVC_COLOR_RGB2HLS = 53,
	CVC_COLOR_HSV2BGR = 54,
	CVC_COLOR_HSV2RGB = 55,
	CVC_COLOR_Lab2BGR = 56,
	CVC_COLOR_Lab2RGB = 57,
	CVC_COLOR_Luv2BGR = 58,
	CVC_COLOR_Luv2RGB = 59,
	CVC_COLOR_HLS2BGR = 60,
	CVC_COLOR_HLS2RGB = 61,
	CVC_COLOR_BGR2HSV_FULL = 66,
	CVC_COLOR_RGB2HSV_FULL = 67,
	CVC_COLOR_BGR2HLS_FULL = 68,
	CVC_COLOR_RGB2HLS_FULL = 69,
	CVC_COLOR_HSV2BGR_FULL = 70,
	CVC_COLOR_HSV2RGB_FULL = 71,
	CVC_COLOR_HLS2BGR_FULL = 72,
	CVC_COLOR_HLS2RGB_FULL = 73,
	CVC_COLOR_LBGR2Lab = 74,
	CVC_COLOR_LRGB2Lab = 75,
	CVC_COLOR_LBGR2Luv = 76,
	CVC_COLOR_LRGB2Luv = 77,
	CVC_COLOR_Lab2LBGR = 78,
	CVC_COLOR_Lab2LRGB = 79,
	CVC_COLOR_Luv2LBGR = 80,
	CVC_COLOR_Luv2LRGB = 81,
	CVC_COLOR_BGR2YUV = 82,
	CVC_COLOR_RGB2YUV = 83,
	CVC_COLOR_YUV2BGR = 84,
	CVC_COLOR_YUV2RGB = 85,
	CVC_COLOR_YUV2RGB_NV12 = 90,
	CVC_COLOR_YUV2BGR_NV12 = 91,
	CVC_COLOR_YUV2RGB_NV21 = 92,
	CVC_COLOR_YUV2BGR_NV21 = 93,
	CVC_COLOR_YUV420sp2RGB = CVC_COLOR_YUV2RGB_NV21,
	CVC_COLOR_YUV420sp2BGR = CVC_COLOR_YUV2BGR_NV21,
	CVC_COLOR_YUV2RGBA_NV12 = 94,
	CVC_COLOR_YUV2BGRA_NV12 = 95,
	CVC_COLOR_YUV2RGBA_NV21 = 96,
	CVC_COLOR_YUV2BGRA_NV21 = 97,
	CVC_COLOR_YUV420sp2RGBA = CVC_COLOR_YUV2RGBA_NV21,
	CVC_COLOR_YUV420sp2BGRA = CVC_COLOR_YUV2BGRA_NV21,
	CVC_COLOR_YUV2RGB_YV12 = 98,
	CVC_COLOR_YUV2BGR_YV12 = 99,
	CVC_COLOR_YUV2RGB_IYUV = 100,
	CVC_COLOR_YUV2BGR_IYUV = 101,
	CVC_COLOR_YUV2RGB_I420 = CVC_COLOR_YUV2RGB_IYUV,
	CVC_COLOR_YUV2BGR_I420 = CVC_COLOR_YUV2BGR_IYUV,
	CVC_COLOR_YUV420p2RGB = CVC_COLOR_YUV2RGB_YV12,
	CVC_COLOR_YUV420p2BGR = CVC_COLOR_YUV2BGR_YV12,
	CVC_COLOR_YUV2RGBA_YV12 = 102,
	CVC_COLOR_YUV2BGRA_YV12 = 103,
	CVC_COLOR_YUV2RGBA_IYUV = 104,
	CVC_COLOR_YUV2BGRA_IYUV = 105,
	CVC_COLOR_YUV2RGBA_I420 = CVC_COLOR_YUV2RGBA_IYUV,
	CVC_COLOR_YUV2BGRA_I420 = CVC_COLOR_YUV2BGRA_IYUV,
	CVC_COLOR_YUV420p2RGBA = CVC_COLOR_YUV2RGBA_YV12,
	CVC_COLOR_YUV420p2BGRA = CVC_COLOR_YUV2BGRA_YV12,
	CVC_COLOR_YUV2GRAY_420 = 106,
	CVC_COLOR_YUV2GRAY_NV21 = CVC_COLOR_YUV2GRAY_420,
	CVC_COLOR_YUV2GRAY_NV12 = CVC_COLOR_YUV2GRAY_420,
	CVC_COLOR_YUV2GRAY_YV12 = CVC_COLOR_YUV2GRAY_420,
	CVC_COLOR_YUV2GRAY_IYUV = CVC_COLOR_YUV2GRAY_420,
	CVC_COLOR_YUV2GRAY_I420 = CVC_COLOR_YUV2GRAY_420,
	CVC_COLOR_YUV420sp2GRAY = CVC_COLOR_YUV2GRAY_420,
	CVC_COLOR_YUV420p2GRAY = CVC_COLOR_YUV2GRAY_420,
	CVC_COLOR_YUV2RGB_UYVY = 107,
	CVC_COLOR_YUV2BGR_UYVY = 108,
	//CVC_COLOR_YUV2RGB_VYUY = 109,
	//CVC_COLOR_YUV2BGR_VYUY = 110,
	CVC_COLOR_YUV2RGB_Y422 = CVC_COLOR_YUV2RGB_UYVY,
	CVC_COLOR_YUV2BGR_Y422 = CVC_COLOR_YUV2BGR_UYVY,
	CVC_COLOR_YUV2RGB_UYNV = CVC_COLOR_YUV2RGB_UYVY,
	CVC_COLOR_YUV2BGR_UYNV = CVC_COLOR_YUV2BGR_UYVY,
	CVC_COLOR_YUV2RGBA_UYVY = 111,
	CVC_COLOR_YUV2BGRA_UYVY = 112,
	//CVC_COLOR_YUV2RGBA_VYUY = 113,
	//CVC_COLOR_YUV2BGRA_VYUY = 114,
	CVC_COLOR_YUV2RGBA_Y422 = CVC_COLOR_YUV2RGBA_UYVY,
	CVC_COLOR_YUV2BGRA_Y422 = CVC_COLOR_YUV2BGRA_UYVY,
	CVC_COLOR_YUV2RGBA_UYNV = CVC_COLOR_YUV2RGBA_UYVY,
	CVC_COLOR_YUV2BGRA_UYNV = CVC_COLOR_YUV2BGRA_UYVY,
	CVC_COLOR_YUV2RGB_YUY2 = 115,
	CVC_COLOR_YUV2BGR_YUY2 = 116,
	CVC_COLOR_YUV2RGB_YVYU = 117,
	CVC_COLOR_YUV2BGR_YVYU = 118,
	CVC_COLOR_YUV2RGB_YUYV = CVC_COLOR_YUV2RGB_YUY2,
	CVC_COLOR_YUV2BGR_YUYV = CVC_COLOR_YUV2BGR_YUY2,
	CVC_COLOR_YUV2RGB_YUNV = CVC_COLOR_YUV2RGB_YUY2,
	CVC_COLOR_YUV2BGR_YUNV = CVC_COLOR_YUV2BGR_YUY2,
	CVC_COLOR_YUV2RGBA_YUY2 = 119,
	CVC_COLOR_YUV2BGRA_YUY2 = 120,
	CVC_COLOR_YUV2RGBA_YVYU = 121,
	CVC_COLOR_YUV2BGRA_YVYU = 122,
	CVC_COLOR_YUV2RGBA_YUYV = CVC_COLOR_YUV2RGBA_YUY2,
	CVC_COLOR_YUV2BGRA_YUYV = CVC_COLOR_YUV2BGRA_YUY2,
	CVC_COLOR_YUV2RGBA_YUNV = CVC_COLOR_YUV2RGBA_YUY2,
	CVC_COLOR_YUV2BGRA_YUNV = CVC_COLOR_YUV2BGRA_YUY2,
	CVC_COLOR_YUV2GRAY_UYVY = 123,
	CVC_COLOR_YUV2GRAY_YUY2 = 124,
	//CVC_CV_YUV2GRAY_VYUY = CVC_CV_YUV2GRAY_UYVY,
	CVC_COLOR_YUV2GRAY_Y422 = CVC_COLOR_YUV2GRAY_UYVY,
	CVC_COLOR_YUV2GRAY_UYNV = CVC_COLOR_YUV2GRAY_UYVY,
	CVC_COLOR_YUV2GRAY_YVYU = CVC_COLOR_YUV2GRAY_YUY2,
	CVC_COLOR_YUV2GRAY_YUYV = CVC_COLOR_YUV2GRAY_YUY2,
	CVC_COLOR_YUV2GRAY_YUNV = CVC_COLOR_YUV2GRAY_YUY2,
	CVC_COLOR_RGBA2mRGBA = 125,
	CVC_COLOR_mRGBA2RGBA = 126,
	CVC_COLOR_RGB2YUV_I420 = 127,
	CVC_COLOR_BGR2YUV_I420 = 128,
	CVC_COLOR_RGB2YUV_IYUV = CVC_COLOR_RGB2YUV_I420,
	CVC_COLOR_BGR2YUV_IYUV = CVC_COLOR_BGR2YUV_I420,
	CVC_COLOR_RGBA2YUV_I420 = 129,
	CVC_COLOR_BGRA2YUV_I420 = 130,
	CVC_COLOR_RGBA2YUV_IYUV = CVC_COLOR_RGBA2YUV_I420,
	CVC_COLOR_BGRA2YUV_IYUV = CVC_COLOR_BGRA2YUV_I420,
	CVC_COLOR_RGB2YUV_YV12 = 131,
	CVC_COLOR_BGR2YUV_YV12 = 132,
	CVC_COLOR_RGBA2YUV_YV12 = 133,
	CVC_COLOR_BGRA2YUV_YV12 = 134,
	CVC_COLOR_BayerBG2BGR = 46,
	CVC_COLOR_BayerGB2BGR = 47,
	CVC_COLOR_BayerRG2BGR = 48,
	CVC_COLOR_BayerGR2BGR = 49,
	CVC_COLOR_BayerBG2RGB = CVC_COLOR_BayerRG2BGR,
	CVC_COLOR_BayerGB2RGB = CVC_COLOR_BayerGR2BGR,
	CVC_COLOR_BayerRG2RGB = CVC_COLOR_BayerBG2BGR,
	CVC_COLOR_BayerGR2RGB = CVC_COLOR_BayerGB2BGR,
	CVC_COLOR_BayerBG2GRAY = 86,
	CVC_COLOR_BayerGB2GRAY = 87,
	CVC_COLOR_BayerRG2GRAY = 88,
	CVC_COLOR_BayerGR2GRAY = 89,
	CVC_COLOR_BayerBG2BGR_VNG = 62,
	CVC_COLOR_BayerGB2BGR_VNG = 63,
	CVC_COLOR_BayerRG2BGR_VNG = 64,
	CVC_COLOR_BayerGR2BGR_VNG = 65,
	CVC_COLOR_BayerBG2RGB_VNG = CVC_COLOR_BayerRG2BGR_VNG,
	CVC_COLOR_BayerGB2RGB_VNG = CVC_COLOR_BayerGR2BGR_VNG,
	CVC_COLOR_BayerRG2RGB_VNG = CVC_COLOR_BayerBG2BGR_VNG,
	CVC_COLOR_BayerGR2RGB_VNG = CVC_COLOR_BayerGB2BGR_VNG,
	CVC_COLOR_BayerBG2BGR_EA = 135,
	CVC_COLOR_BayerGB2BGR_EA = 136,
	CVC_COLOR_BayerRG2BGR_EA = 137,
	CVC_COLOR_BayerGR2BGR_EA = 138,
	CVC_COLOR_BayerBG2RGB_EA = CVC_COLOR_BayerRG2BGR_EA,
	CVC_COLOR_BayerGB2RGB_EA = CVC_COLOR_BayerGR2BGR_EA,
	CVC_COLOR_BayerRG2RGB_EA = CVC_COLOR_BayerBG2BGR_EA,
	CVC_COLOR_BayerGR2RGB_EA = CVC_COLOR_BayerGB2BGR_EA,
	CVC_COLOR_BayerBG2BGRA = 139,
	CVC_COLOR_BayerGB2BGRA = 140,
	CVC_COLOR_BayerRG2BGRA = 141,
	CVC_COLOR_BayerGR2BGRA = 142,
	CVC_COLOR_BayerBG2RGBA = CVC_COLOR_BayerRG2BGRA,
	CVC_COLOR_BayerGB2RGBA = CVC_COLOR_BayerGR2BGRA,
	CVC_COLOR_BayerRG2RGBA = CVC_COLOR_BayerBG2BGRA,
	CVC_COLOR_BayerGR2RGBA = CVC_COLOR_BayerGB2BGRA,
	CVC_COLOR_COLORCVT_MAX = 143
};

enum CVCRectanglesIntersectTypes {
	CVC_INTERSECT_NONE = 0,
	CVC_INTERSECT_PARTIAL = 1,
	CVC_INTERSECT_FULL = 2
};

enum CVCLineTypes {
	CVC_FILLED = -1,
	CVC_LINE_4 = 4,
	CVC_LINE_8 = 8,
	CVC_LINE_AA = 16
};

enum CVCHersheyFonts {
	CVC_FONT_HERSHEY_SIMPLEX = 0,
	CVC_FONT_HERSHEY_PLAIN = 1,
	CVC_FONT_HERSHEY_DUPLEX = 2,
	CVC_FONT_HERSHEY_COMPLEX = 3,
	CVC_FONT_HERSHEY_TRIPLEX = 4,
	CVC_FONT_HERSHEY_COMPLEX_SMALL = 5,
	CVC_FONT_HERSHEY_SCRIPT_SIMPLEX = 6,
	CVC_FONT_HERSHEY_SCRIPT_COMPLEX = 7,
	CVC_FONT_ITALIC = 16
};

enum CVCMarkerTypes {
	CVC_MARKER_CROSS = 0,
	CVC_MARKER_TILTED_CROSS = 1,
	CVC_MARKER_STAR = 2,
	CVC_MARKER_DIAMOND = 3,
	CVC_MARKER_SQUARE = 4,
	CVC_MARKER_TRIANGLE_UP = 5,
	CVC_MARKER_TRIANGLE_DOWN = 6
};

enum CVCTemplateMatchModes {
	CVC_TM_SQDIFF = 0,
	CVC_TM_SQDIFF_NORMED = 1,
	CVC_TM_CCORR = 2,
	CVC_TM_CCORR_NORMED = 3,
	CVC_TM_CCOEFF = 4,
	CVC_TM_CCOEFF_NORMED = 5
};

enum CVCColormapTypes {
	CVC_COLORMAP_AUTUMN = 0,
	CVC_COLORMAP_BONE = 1,
	CVC_COLORMAP_JET = 2,
	CVC_COLORMAP_WINTER = 3,
	CVC_COLORMAP_RAINBOW = 4,
	CVC_COLORMAP_OCEAN = 5,
	CVC_COLORMAP_SUMMER = 6,
	CVC_COLORMAP_SPRING = 7,
	CVC_COLORMAP_COOL = 8,
	CVC_COLORMAP_HSV = 9,
	CVC_COLORMAP_PINK = 10,
	CVC_COLORMAP_HOT = 11,
	CVC_COLORMAP_PARULA = 12,
	CVC_COLORMAP_MAGMA = 13,
	CVC_COLORMAP_INFERNO = 14,
	CVC_COLORMAP_PLASMA = 15,
	CVC_COLORMAP_VIRIDIS = 16,
	CVC_COLORMAP_CIVIDIS = 17,
	CVC_COLORMAP_TWILIGHT = 18,
	CVC_COLORMAP_TWILIGHT_SHIFTED = 19,
	CVC_COLORMAP_TURBO = 20,
	CVC_COLORMAP_DEEPGREEN = 21
};

// MARK: -

#if IGNORE_ALGORITHM

/** @brief finds arbitrary template in the grayscale image using Generalized Hough Transform */
class GeneralizedHough : public Algorithm {

public:
	//! set template to search
	virtual void setTemplate(InputArray templ, CVCPoint templCenter) = 0;
	virtual void setTemplate(InputArray edges, InputArray dx, InputArray dy, CVCPoint templCenter) = 0;

	//! find template on image
	virtual void detect(InputArray image, CVCMat positions, CVCMat votes = noArray()) = 0;
	virtual void detect(InputArray edges, InputArray dx, InputArray dy, CVCMat positions, CVCMat votes = noArray()) = 0;

	//! Canny low threshold.
	virtual void setCannyLowThresh(int cannyLowThresh) = 0;
	virtual int getCannyLowThresh() const = 0;

	//! Canny high threshold.
	virtual void setCannyHighThresh(int cannyHighThresh) = 0;
	virtual int getCannyHighThresh() const = 0;

	//! Minimum distance between the centers of the detected objects.
	virtual void setMinDist(double minDist) = 0;
	virtual double getMinDist() const = 0;

	//! Inverse ratio of the accumulator resolution to the image resolution.
	virtual void setDp(double dp) = 0;
	virtual double getDp() const = 0;

	//! Maximal size of inner buffers.
	virtual void setMaxBufferSize(int maxBufferSize) = 0;
	virtual int getMaxBufferSize() const = 0;
};

/** @brief finds arbitrary template in the grayscale image using Generalized Hough Transform. */
class GeneralizedHoughBallard : public GeneralizedHough {

public:
	//! R-Table levels.
	virtual void setLevels(int levels) = 0;
	virtual int getLevels() const = 0;

	//! The accumulator threshold for the template centers at the detection stage. The smaller it is, the more false positions may be detected.
	virtual void setVotesThreshold(int votesThreshold) = 0;
	virtual int getVotesThreshold() const = 0;
};

/** @brief finds arbitrary template in the grayscale image using Generalized Hough Transform. */
class GeneralizedHoughGuil : public GeneralizedHough {

public:
	//! Angle difference in degrees between two points in feature.
	virtual void setXi(double xi) = 0;
	virtual double getXi() const = 0;

	//! Feature table levels.
	virtual void setLevels(int levels) = 0;
	virtual int getLevels() const = 0;

	//! Maximal difference between angles that treated as equal.
	virtual void setAngleEpsilon(double angleEpsilon) = 0;
	virtual double getAngleEpsilon() const = 0;

	//! Minimal rotation angle to detect in degrees.
	virtual void setMinAngle(double minAngle) = 0;
	virtual double getMinAngle() const = 0;

	//! Maximal rotation angle to detect in degrees.
	virtual void setMaxAngle(double maxAngle) = 0;
	virtual double getMaxAngle() const = 0;

	//! Angle step in degrees.
	virtual void setAngleStep(double angleStep) = 0;
	virtual double getAngleStep() const = 0;

	//! Angle votes threshold.
	virtual void setAngleThresh(int angleThresh) = 0;
	virtual int getAngleThresh() const = 0;

	//! Minimal scale to detect.
	virtual void setMinScale(double minScale) = 0;
	virtual double getMinScale() const = 0;

	//! Maximal scale to detect.
	virtual void setMaxScale(double maxScale) = 0;
	virtual double getMaxScale() const = 0;

	//! Scale step.
	virtual void setScaleStep(double scaleStep) = 0;
	virtual double getScaleStep() const = 0;

	//! Scale votes threshold.
	virtual void setScaleThresh(int scaleThresh) = 0;
	virtual int getScaleThresh() const = 0;

	//! Position votes threshold.
	virtual void setPosThresh(int posThresh) = 0;
	virtual int getPosThresh() const = 0;
};

/** @brief Base class for Contrast Limited Adaptive Histogram Equalization. */
class CLAHE : public Algorithm {

public:
	/** @brief Equalizes the histogram of a grayscale image using Contrast Limited Adaptive Histogram Equalization.

	@param src Source image of type CV_8UC1 or CV_16UC1.
	@param dst Destination image.
	 */
	virtual void apply(InputArray src, CVCMat dst) = 0;

	/** @brief Sets threshold for contrast limiting.

	@param clipLimit threshold value.
	*/
	virtual void setClipLimit(double clipLimit) = 0;

	//! Returns threshold value for contrast limiting.
	virtual double getClipLimit() const = 0;

	/** @brief Sets size of grid for histogram equalization. Input image will be divided into
	equally sized rectangular tiles.

	@param tileGridSize defines the number of tiles in row and column.
	*/
	virtual void setTilesGridSize(CVCSize tileGridSize) = 0;

	//!@brief Returns Size defines the number of tiles in row and column.
	virtual CVCSize getTilesGridSize() const = 0;

	virtual void collectGarbage() = 0;
};

class Subdiv2D {

public:
	/** Subdiv2D point location cases */
	enum {
		PTLOC_ERROR = -2,
		PTLOC_OUTSIDE_RECT = -1,
		PTLOC_INSIDE = 0,
		PTLOC_VERTEX = 1,
		PTLOC_ON_EDGE = 2
	};

	/** Subdiv2D edge type navigation (see: getEdge()) */
	enum {
		NEXT_AROUND_ORG = 0x00,
		NEXT_AROUND_DST = 0x22,
		PREV_AROUND_ORG = 0x11,
		PREV_AROUND_DST = 0x33,
		NEXT_AROUND_LEFT = 0x13,
		NEXT_AROUND_RIGHT = 0x31,
		PREV_AROUND_LEFT = 0x20,
		PREV_AROUND_RIGHT = 0x02
	};

	/** @brief creates an empty Subdiv2D object. */
	Subdiv2D();

	/** @overload */
	Subdiv2D(Rect rect);

	/** @brief Creates a new empty Delaunay subdivision */
	void initDelaunay(Rect rect);

	/** @brief Insert a single point into a Delaunay triangulation. */
	int insert(CVCPoint2f pt);

	/** @brief Insert multiple points into a Delaunay triangulation. */
	void insert(const std::vector<CVCPoint2f>& ptvec);

	/** @brief Returns the location of a point within a Delaunay triangulation. */
	int locate(CVCPoint2f pt, int& edge, int& vertex);

	/** @brief Finds the subdivision vertex closest to the given point. */
	int findNearest(CVCPoint2f pt, CVCPoint2f* nearestPt = 0);

	/** @brief Returns a list of all edges. */
	void getEdgeList(std::vector<Vec4f>& edgeList) const;

	/** @brief Returns a list of the leading edge ID connected to each triangle. */
	void getLeadingEdgeList(std::vector<int>& leadingEdgeList) const;

	/** @brief Returns a list of all triangles. */
	void getTriangleList(std::vector<Vec6f>& triangleList) const;

	/** @brief Returns a list of all Voronoi facets. */
	void getVoronoiFacetList(const std::vector<int>& idx, std::vector<std::vector<CVCPoint2f> >& facetList, std::vector<CVCPoint2f>& facetCenters);

	/** @brief Returns vertex location from vertex ID. */
	CVCPoint2f getVertex(int vertex, int* firstEdge = 0) const;

	/** @brief Returns one of the edges related to the given edge. */
	int getEdge( int edge, int nextEdgeType ) const;

	/** @brief Returns next edge around the edge origin. */
	int nextEdge(int edge) const;

	/** @brief Returns another edge of the same quad-edge. */
	int rotateEdge(int edge, int rotate) const;
	int symEdge(int edge) const;

	/** @brief Returns the edge origin. */
	int edgeOrg(int edge, CVCPoint2f* orgpt = 0) const;

	/** @brief Returns the edge destination. */
	int edgeDst(int edge, CVCPoint2f* dstpt = 0) const;

protected:

	int newEdge();
	void deleteEdge(int edge);
	int newPoint(CVCPoint2f pt, bool isvirtual, int firstEdge = 0);
	void deletePoint(int vtx);
	void setEdgePoints( int edge, int orgPt, int dstPt );
	void splice( int edgeA, int edgeB );
	int connectEdges( int edgeA, int edgeB );
	void swapEdges( int edge );
	int isRightOf(CVCPoint2f pt, int edge) const;
	void calcVoronoi();
	void clearVoronoi();
	void checkSubdiv() const;

	struct Vertex {
		Vertex();
		Vertex(CVCPoint2f pt, bool _isvirtual, int _firstEdge=0);
		bool isvirtual() const;
		bool isfree() const;

		int firstEdge;
		int type;
		CVCPoint2f pt;
	};

	struct QuadEdge {
		QuadEdge();
		QuadEdge(int edgeidx);
		bool isfree() const;

		int next[4];
		int pt[4];
	};

	//! All of the vertices
	std::vector<Vertex> vtx;
	//! All of the edges
	std::vector<QuadEdge> qedges;
	int freeQEdge;
	int freePoint;
	bool validGeometry;

	int recentEdge;
	//! Top left corner of the bounding rect
	CVCPoint2f topLeft;
	//! Bottom right corner of the bounding rect
	CVCPoint2f bottomRight;
};

/** @brief Line segment detector class */
class LineSegmentDetector : public Algorithm {

public:

	/** @brief Finds lines in the input image. */
	virtual void detect(InputArray _image, CVCMat _lines, CVCMat width = noArray(), CVCMat prec = noArray(), CVCMat nfa = noArray()) = 0;

	/** @brief Draws the line segments on a given image. */
	virtual void drawSegments(CVCMat _image, InputArray lines) = 0;

	/** @brief Draws two groups of lines in blue and red, counting the non overlapping (mismatching) pixels. */
	virtual int compareSegments(CVCSize size, InputArray lines1, InputArray lines2, CVCMat _image = noArray()) = 0;

	virtual ~LineSegmentDetector() { }
};

#endif // IGNORE_ALGORITHM

// MARK: -

/** @brief Creates a smart pointer to a LineSegmentDetector object and initializes it. */
//CVC_EXPORT Ptr<LineSegmentDetector> CVCcreateLineSegmentDetector(int _refine, double _scale, double _sigma_scale, double _quant, double _ang_th, double _log_eps, double _density_th, int _n_bins);

/** @brief Returns Gaussian filter coefficients. */
CVC_EXPORT CVCMat CVCgetGaussianKernel(int ksize, double sigma, int ktype);

/** @brief Returns filter coefficients for computing spatial image derivatives. */
CVC_EXPORT void CVCgetDerivKernels(CVCMat kx, CVCMat ky, int dx, int dy, int ksize, bool normalize, int ktype);

/** @brief Returns Gabor filter coefficients. */
CVC_EXPORT CVCMat CVCgetGaborKernel(CVCSize ksize, double sigma, double theta, double lambd, double gamma, double psi, int ktype);

/** @brief returns "magic" border value for erosion and dilation. It is automatically transformed to Scalar::all(-DBL_MAX) for dilation. */
CVC_EXPORT CVCScalar CVCmorphologyDefaultBorderValue(void);
//{
//	return CVCScalar::all(DBL_MAX);
//}

/** @brief Returns a structuring element of the specified size and shape for morphological operations. */
CVC_EXPORT CVCMat CVCgetStructuringElement(int shape, CVCSize ksize, CVCPoint anchor);

/** @brief Blurs an image using the median filter. */
CVC_EXPORT void CVCmedianBlur(CVCMat src, CVCMat dst, int ksize);

/** @brief Blurs an image using a Gaussian filter. */
CVC_EXPORT void CVCGaussianBlur(CVCMat src, CVCMat dst, CVCSize ksize, double sigmaX, double sigmaY, int borderType);

/** @brief Applies the bilateral filter to an image. */
CVC_EXPORT void CVCbilateralFilter(CVCMat src, CVCMat dst, int d, double sigmaColor, double sigmaSpace, int borderType);

/** @brief Blurs an image using the box filter. */
CVC_EXPORT void CVCboxFilter(CVCMat src, CVCMat dst, int ddepth, CVCSize ksize, CVCPoint anchor, bool normalize, int borderType);

/** @brief Calculates the normalized sum of squares of the pixel values overlapping the filter. */
CVC_EXPORT void CVCsqrBoxFilter(CVCMat src, CVCMat dst, int ddepth, CVCSize ksize, CVCPoint anchor, bool normalize, int borderType);

/** @brief Blurs an image using the normalized box filter. */
CVC_EXPORT void CVCblur(CVCMat src, CVCMat dst, CVCSize ksize, CVCPoint anchor, int borderType);

/** @brief Convolves an image with the kernel. */
CVC_EXPORT void CVCfilter2D(CVCMat src, CVCMat dst, int ddepth, CVCMat kernel, CVCPoint anchor, double delta, int borderType);

/** @brief Applies a separable linear filter to an image. */
CVC_EXPORT void CVCsepFilter2D(CVCMat src, CVCMat dst, int ddepth, CVCMat kernelX, CVCMat kernelY, CVCPoint anchor, double delta, int borderType);

/** @brief Calculates the first, second, third, or mixed image derivatives using an extended Sobel operator. */
CVC_EXPORT void CVCSobel(CVCMat src, CVCMat dst, int ddepth, int dx, int dy, int ksize, double scale, double delta, int borderType);

/** @brief Calculates the first order image derivative in both x and y using a Sobel operator */
CVC_EXPORT void CVCspatialGradient(CVCMat src, CVCMat dx, CVCMat dy, int ksize, int borderType);

/** @brief Calculates the first x- or y- image derivative using Scharr operator. */
CVC_EXPORT void CVCScharr(CVCMat src, CVCMat dst, int ddepth, int dx, int dy, double scale, double delta, int borderType);

/** @brief Calculates the Laplacian of an image. */
CVC_EXPORT void CVCLaplacian(CVCMat src, CVCMat dst, int ddepth, int ksize, double scale, double delta, int borderType);

/** @brief Finds edges in an image using the Canny algorithm @cite Canny86 . */
CVC_EXPORT void CVCCanny(CVCMat image, CVCMat edges, double threshold1, double threshold2, int apertureSize, bool L2gradient);

//CVC_EXPORT void CVCCanny(CVCMat dx, CVCMat dy, CVCMat edges, double threshold1, double threshold2, bool L2gradient);

/** @brief Calculates the minimal eigenvalue of gradient matrices for corner detection. */
CVC_EXPORT void CVCcornerMinEigenVal(CVCMat src, CVCMat dst, int blockSize, int ksize, int borderType);

/** @brief Harris corner detector. */
CVC_EXPORT void CVCcornerHarris(CVCMat src, CVCMat dst, int blockSize, int ksize, double k, int borderType);

/** @brief Calculates eigenvalues and eigenvectors of image blocks for corner detection. */
CVC_EXPORT void CVCcornerEigenValsAndVecs(CVCMat src, CVCMat dst, int blockSize, int ksize, int borderType);

/** @brief Calculates a feature map for corner detection. */
CVC_EXPORT void CVCpreCornerDetect(CVCMat src, CVCMat dst, int ksize, int borderType);

/** @brief Refines the corner locations. */
//CVC_EXPORT void CVCcornerSubPix(CVCMat image, CVCMat corners, CVCSize winSize, CVCSize zeroZone, TermCriteria criteria);

/** @brief Determines strong corners on an image. */
CVC_EXPORT void CVCgoodFeaturesToTrack(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, int blockSize, bool useHarrisDetector, double k);

//CVC_EXPORT void CVCgoodFeaturesToTrack(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, int blockSize, int gradientSize, bool useHarrisDetector, double k);

/** @brief Same as above, but returns also quality measure of the detected corners. */
CVC_EXPORT void CVCgoodFeaturesToTrackWithQuality(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, CVCMat cornersQuality, int blockSize, int gradientSize, bool useHarrisDetector, double k);

/** @brief Finds lines in a binary image using the standard Hough transform. */
CVC_EXPORT void CVCHoughLines(CVCMat image, CVCMat lines, double rho, double theta, int threshold, double srn, double stn, double min_theta, double max_theta);

/** @brief Finds line segments in a binary image using the probabilistic Hough transform. */
CVC_EXPORT void CVCHoughLinesP(CVCMat image, CVCMat lines, double rho, double theta, int threshold, double minLineLength, double maxLineGap);

/** @brief Finds lines in a set of points using the standard Hough transform. */
CVC_EXPORT void CVCHoughLinesPointSet(CVCMat _point, CVCMat _lines, int lines_max, int threshold, double min_rho, double max_rho, double rho_step, double min_theta, double max_theta, double theta_step);

/** @brief Finds circles in a grayscale image using the Hough transform. */
CVC_EXPORT void CVCHoughCircles(CVCMat image, CVCMat circles, int method, double dp, double minDist, double param1, double param2, int minRadius, int maxRadius);

/** @brief Erodes an image by using a specific structuring element. */
CVC_EXPORT void CVCerode(CVCMat src, CVCMat dst, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue);

/** @brief Dilates an image by using a specific structuring element. */
CVC_EXPORT void CVCdilate(CVCMat src, CVCMat dst, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue);

/** @brief Performs advanced morphological transformations. */
CVC_EXPORT void CVCmorphologyEx(CVCMat src, CVCMat dst, int op, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue);

/** @brief Resizes an image. */
CVC_EXPORT void CVCresize(CVCMat src, CVCMat dst, CVCSize dsize, double fx, double fy, int interpolation);

/** @brief Applies an affine transformation to an image. */
CVC_EXPORT void CVCwarpAffine(CVCMat src, CVCMat dst, CVCMat M, CVCSize dsize, int flags, int borderMode, CVCScalar borderValue);

/** @brief Applies a perspective transformation to an image. */
CVC_EXPORT void CVCwarpPerspective(CVCMat src, CVCMat dst, CVCMat M, CVCSize dsize, int flags, int borderMode, CVCScalar borderValue);

/** @brief Applies a generic geometrical transformation to an image. */
CVC_EXPORT void CVCremap(CVCMat src, CVCMat dst, CVCMat map1, CVCMat map2, int interpolation, int borderMode, CVCScalar borderValue);

/** @brief Converts image transformation maps from one representation to another. */
CVC_EXPORT void CVCconvertMaps(CVCMat map1, CVCMat map2, CVCMat dstmap1, CVCMat dstmap2, int dstmap1type, bool nninterpolation);

/** @brief Calculates an affine matrix of 2D rotation. */
CVC_EXPORT CVCMat CVCgetRotationMatrix2D(CVCPoint2f center, double angle, double scale);

//CVC_EXPORT Matx23d CVCgetRotationMatrix2D_(CVCPoint2f center, double angle, double scale);

/** @brief Calculates an affine transform from three pairs of the corresponding points. */
//CVC_EXPORT CVCMat CVCgetAffineTransform(const CVCPoint2f src[], const CVCPoint2f dst[]);

/** @brief Inverts an affine transformation. */
CVC_EXPORT void CVCinvertAffineTransform(CVCMat M, CVCMat iM);

/** @brief Calculates a perspective transform from four pairs of the corresponding points. */
CVC_EXPORT CVCMat CVCgetPerspectiveTransform(CVCMat src, CVCMat dst, int solveMethod);

//CVC_EXPORT CVCMat CVCgetPerspectiveTransform(const CVCPoint2f src[], const CVCPoint2f dst[], int solveMethod);

CVC_EXPORT CVCMat CVCgetAffineTransform(CVCMat src, CVCMat dst);

/** @brief Retrieves a pixel rectangle from an image with sub-pixel accuracy. */
CVC_EXPORT void CVCgetRectSubPix(CVCMat image, CVCSize patchSize, CVCPoint2f center, CVCMat patch, int patchType);

/** @brief Remaps an image to semilog-polar coordinates space. */
CVC_EXPORT void CVClogPolar(CVCMat src, CVCMat dst, CVCPoint2f center, double M, int flags);

/** @brief Remaps an image to polar coordinates space. */
CVC_EXPORT void CVClinearPolar(CVCMat src, CVCMat dst, CVCPoint2f center, double maxRadius, int flags);

/** @brief Remaps an image to polar or semilog-polar coordinates space */
CVC_EXPORT void CVCwarpPolar(CVCMat src, CVCMat dst, CVCSize dsize, CVCPoint2f center, double maxRadius, int flags);

/** @overload */
CVC_EXPORT void CVCintegral(CVCMat src, CVCMat sum, int sdepth);

/** @overload */
CVC_EXPORT void CVCintegral2(CVCMat src, CVCMat sum, CVCMat sqsum, int sdepth, int sqdepth);

/** @brief Calculates the integral of an image. */
CVC_EXPORT void CVCintegral3(CVCMat src, CVCMat sum, CVCMat sqsum, CVCMat tilted, int sdepth, int sqdepth);

/** @brief Adds an image to the accumulator image. */
CVC_EXPORT void CVCaccumulate(CVCMat src, CVCMat dst, CVCMat mask);

/** @brief Adds the square of a source image to the accumulator image. */
CVC_EXPORT void CVCaccumulateSquare(CVCMat src, CVCMat dst, CVCMat mask);

/** @brief Adds the per-element product of two input images to the accumulator image. */
CVC_EXPORT void CVCaccumulateProduct(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask);

/** @brief Updates a running average. */
CVC_EXPORT void CVCaccumulateWeighted(CVCMat src, CVCMat dst, double alpha, CVCMat mask);

/** @brief The function is used to detect translational shifts that occur between two images. */
//CVC_EXPORT Point2d CVCphaseCorrelate(CVCMat src1, CVCMat src2, CVCMat window, double* response);

/** @brief This function computes a Hanning window coefficients in two dimensions. */
CVC_EXPORT void CVCcreateHanningWindow(CVCMat dst, CVCSize winSize, int type);

/** @brief Applies a fixed-level threshold to each array element. */
CVC_EXPORT double CVCthreshold(CVCMat src, CVCMat dst, double thresh, double maxval, int type);

/** @brief Applies an adaptive threshold to an array. */
CVC_EXPORT void CVCadaptiveThreshold(CVCMat src, CVCMat dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C);

/** @brief Blurs an image and downsamples it. */
CVC_EXPORT void CVCpyrDown(CVCMat src, CVCMat dst, CVCSize dstsize, int borderType);

/** @brief Upsamples an image and then blurs it. */
CVC_EXPORT void CVCpyrUp(CVCMat src, CVCMat dst, CVCSize dstsize, int borderType);

/** @brief Constructs the Gaussian pyramid for an image. */
//CVC_EXPORT void CVCbuildPyramid(CVCMat src, OutputArrayOfArrays dst, int maxlevel, int borderType);

/** @brief Calculates a histogram of a set of arrays. */
//CVC_EXPORT void CVCcalcHist(const Mat* images, int nimages, const int* channels, CVCMat mask, CVCMat hist, int dims, const int* histSize, const float** ranges, bool uniform, bool accumulate);

//CVC_EXPORT void CVCcalcHist(const Mat* images, int nimages, const int* channels, CVCMat mask, SparseMat& hist, int dims, const int* histSize, const float** ranges, bool uniform, bool accumulate);

/** @overload */
//CVC_EXPORT void CVCcalcHist(InputArrayOfArrays images, const std::vector<int>& channels, CVCMat mask, CVCMat hist, const std::vector<int>& histSize, const std::vector<float>& ranges, bool accumulate);

/** @brief Calculates the back projection of a histogram. */
//CVC_EXPORT void CVCcalcBackProject(const Mat* images, int nimages, const int* channels, CVCMat hist, CVCMat backProject, const float** ranges, double scale, bool uniform);

/** @overload */
//CVC_EXPORT void CVCcalcBackProject(const Mat* images, int nimages, const int* channels, const SparseMat& hist, CVCMat backProject, const float** ranges, double scale, bool uniform);

/** @overload */
//CVC_EXPORT void CVCcalcBackProject(InputArrayOfArrays images, const std::vector<int>& channels, CVCMat hist, CVCMat dst, const std::vector<float>& ranges, double scale);

/** @brief Compares two histograms. */
CVC_EXPORT double CVCcompareHist(CVCMat H1, CVCMat H2, int method);

/** @overload */
//CVC_EXPORT double CVCcompareHist(const SparseMat& H1, const SparseMat& H2, int method);

/** @brief Equalizes the histogram of a grayscale image. */
CVC_EXPORT void CVCequalizeHist(CVCMat src, CVCMat dst);

/** @brief Creates a smart pointer to a cv::CLAHE class and initializes it. */
//CVC_EXPORT Ptr<CLAHE> CVCcreateCLAHE(double clipLimit, CVCSize tileGridSize);

/** @brief Computes the "minimal work" distance between two weighted point configurations. */
CVC_EXPORT float CVCEMD(CVCMat signature1, CVCMat signature2, int distType, CVCMat cost, float* lowerBound, CVCMat flow);

//CVC_EXPORT float CVCEMD(CVCMat signature1, CVCMat signature2, int distType, CVCMat cost = noArray(), Ptr<float> lowerBound = Ptr<float>(), CVCMat flow = noArray());

/** @brief Performs a marker-based image segmentation using the watershed algorithm. */
CVC_EXPORT void CVCwatershed(CVCMat image, CVCMat markers);

/** @brief Performs initial step of meanshift segmentation of an image. */
//CVC_EXPORT void CVCpyrMeanShiftFiltering(CVCMat src, CVCMat dst, double sp, double sr, int maxLevel, TermCriteria termcrit = TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS,5,1));

/** @brief Runs the GrabCut algorithm. */
//CVC_EXPORT void CVCgrabCut(CVCMat img, CVCMat mask, Rect rect, CVCMat bgdModel, CVCMat fgdModel, int iterCount, int mode);

/** @brief Calculates the distance to the closest zero pixel for each pixel of the source image. */
CVC_EXPORT void CVCdistanceTransformWithLabels(CVCMat src, CVCMat dst, CVCMat labels, int distanceType, int maskSize, int labelType);

/** @overload */
CVC_EXPORT void CVCdistanceTransform(CVCMat src, CVCMat dst, int distanceType, int maskSize, int dstType);

/** @overload */
//CVC_EXPORT int CVCfloodFill(CVCMat image, CVCPoint seedPoint, CVCScalar newVal, Rect* rect = 0, CVCScalar loDiff, CVCScalar upDiff, int flags);

/** @brief Fills a connected component with the given color. */
//CVC_EXPORT int CVCfloodFill(CVCMat image, CVCMat mask, CVCPoint seedPoint, CVCScalar newVal, Rect* rect=0, CVCScalar loDiff, CVCScalar upDiff, int flags);

/** @brief Performs linear blending of two images. */
CVC_EXPORT void CVCblendLinear(CVCMat src1, CVCMat src2, CVCMat weights1, CVCMat weights2, CVCMat dst);

/** @brief Converts an image from one color space to another. */
CVC_EXPORT void CVCcvtColor(CVCMat src, CVCMat dst, int code, int dstCn);

/** @brief Converts an image from one color space to another where the source image is stored in two planes. */
CVC_EXPORT void CVCcvtColorTwoPlane(CVCMat src1, CVCMat src2, CVCMat dst, int code);

/** @brief main function for all demosaicing processes */
CVC_EXPORT void CVCdemosaicing(CVCMat src, CVCMat dst, int code, int dstCn);

/** @brief Calculates all of the moments up to the third order of a polygon or rasterized shape. */
//CVC_EXPORT Moments CVCmoments(CVCMat array, bool binaryImage);

/** @brief Calculates seven Hu invariants. */
//CVC_EXPORT void CVCHuMoments(const Moments& moments, double hu[7]);

/** @overload */
//CVC_EXPORT void CVCHuMoments(const Moments& m, CVCMat hu);

/** @brief Compares a template against overlapped image regions. */
CVC_EXPORT void CVCmatchTemplate(CVCMat image, CVCMat templ, CVCMat result, int method, CVCMat mask);

/** @brief computes the connected components labeled image of boolean image */
CVC_EXPORT int CVCconnectedComponentsWithAlgorithm(CVCMat image, CVCMat labels, int connectivity, int ltype, int ccltype);

/** @overload */
CVC_EXPORT int CVCconnectedComponents(CVCMat image, CVCMat labels, int connectivity, int ltype);

/** @brief computes the connected components labeled image of boolean image and also produces a statistics output for each label. */
CVC_EXPORT int CVCconnectedComponentsWithStatsWithAlgorithm(CVCMat image, CVCMat labels, CVCMat stats, CVCMat centroids, int connectivity, int ltype, int ccltype);

/** @overload */
CVC_EXPORT int CVCconnectedComponentsWithStats(CVCMat image, CVCMat labels, CVCMat stats, CVCMat centroids, int connectivity, int ltype);

/** @brief Finds contours in a binary image. */
//CVC_EXPORT void CVCfindContours(CVCMat image, OutputArrayOfArrays contours, CVCMat hierarchy, int mode, int method, CVCPoint offset);

/** @overload */
//CVC_EXPORT void CVCfindContours(CVCMat image, OutputArrayOfArrays contours, int mode, int method, CVCPoint offset);

/** @brief Approximates a polygonal curve(s) with the specified precision. */
CVC_EXPORT void CVCapproxPolyDP(CVCMat curve, CVCMat approxCurve, double epsilon, bool closed);

/** @brief Calculates a contour perimeter or a curve length. */
CVC_EXPORT double CVCarcLength(CVCMat curve, bool closed);

/** @brief Calculates the up-right bounding rectangle of a point set or non-zero pixels of gray-scale image. */
//CVC_EXPORT Rect CVCboundingRect(CVCMat array);

/** @brief Calculates a contour area. */
CVC_EXPORT double CVCcontourArea(CVCMat contour, bool oriented);

/** @brief Finds a rotated rectangle of the minimum area enclosing the input 2D point set. */
//CVC_EXPORT RotatedRect CVCminAreaRect(CVCMat points);

/** @brief Finds the four vertices of a rotated rect. Useful to draw the rotated rectangle. */
//CVC_EXPORT void CVCboxPoints(RotatedRect box, CVCMat points);

/** @brief Finds a circle of the minimum area enclosing a 2D point set. */
CVC_EXPORT void CVCminEnclosingCircle(CVCMat points, CVCPoint2f *center, float* radius);

/** @brief Finds a triangle of minimum area enclosing a 2D point set and returns its area. */
CVC_EXPORT double CVCminEnclosingTriangle(CVCMat points, CVCMat triangle);

/** @brief Compares two shapes. */
CVC_EXPORT double CVCmatchShapes(CVCMat contour1, CVCMat contour2, int method, double parameter);

/** @brief Finds the convex hull of a point set. */
CVC_EXPORT void CVCconvexHull(CVCMat points, CVCMat hull, bool clockwise, bool returnPoints);

/** @brief Finds the convexity defects of a contour. */
CVC_EXPORT void CVCconvexityDefects(CVCMat contour, CVCMat convexhull, CVCMat convexityDefects);

/** @brief Tests a contour convexity. */
CVC_EXPORT bool CVCisContourConvex(CVCMat contour);

/** @brief Finds intersection of two convex polygons */
CVC_EXPORT float CVCintersectConvexConvex(CVCMat _p1, CVCMat _p2, CVCMat _p12, bool handleNested);

/** @brief Fits an ellipse around a set of 2D points. */
//CVC_EXPORT RotatedRect CVCfitEllipse(CVCMat points);

/** @brief Fits an ellipse around a set of 2D points. */
//CVC_EXPORT RotatedRect CVCfitEllipseAMS(CVCMat points);

/** @brief Fits an ellipse around a set of 2D points. */
//CVC_EXPORT RotatedRect CVCfitEllipseDirect(CVCMat points);

/** @brief Fits a line to a 2D or 3D point set. */
CVC_EXPORT void CVCfitLine(CVCMat points, CVCMat line, int distType, double param, double reps, double aeps);

/** @brief Performs a point-in-contour test. */
CVC_EXPORT double CVCpointPolygonTest(CVCMat contour, CVCPoint2f pt, bool measureDist);

/** @brief Finds out if there is any intersection between two rotated rectangles. */
//CVC_EXPORT int CVCrotatedRectangleIntersection(const RotatedRect& rect1, const RotatedRect& rect2, CVCMat intersectingRegion);

/** @brief Creates a smart pointer to a cv::GeneralizedHoughBallard class and initializes it. */
//CVC_EXPORT Ptr<GeneralizedHoughBallard> CVCcreateGeneralizedHoughBallard();

/** @brief Creates a smart pointer to a cv::GeneralizedHoughGuil class and initializes it. */
//CVC_EXPORT Ptr<GeneralizedHoughGuil> CVCcreateGeneralizedHoughGuil();

/** @brief Applies a GNU Octave/MATLAB equivalent colormap on a given image. */
CVC_EXPORT void CVCapplyColorMap(CVCMat src, CVCMat dst, int colormap);

/** @brief Applies a user colormap on a given image. */
//CVC_EXPORT void CVCapplyColorMap(CVCMat src, CVCMat dst, CVCMat userColor);

/** @brief Draws a line segment connecting two points. */
CVC_EXPORT void CVCline(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int lineType, int shift);

/** @brief Draws a arrow segment pointing from the first point to the second one. */
CVC_EXPORT void CVCarrowedLine(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int line_type, int shift, double tipLength);

/** @brief Draws a simple, thick, or filled up-right rectangle. */
CVC_EXPORT void CVCrectangle(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int lineType, int shift);

/** @overload */
//CVC_EXPORT void CVCrectangle(CVCMat img, Rect rec, CVCScalar color, int thickness, int lineType, int shift);

/** @brief Draws a circle. */
CVC_EXPORT void CVCcircle(CVCMat img, CVCPoint center, int radius, CVCScalar color, int thickness, int lineType, int shift);

/** @brief Draws a simple or thick elliptic arc or fills an ellipse sector. */
CVC_EXPORT void CVCellipse(CVCMat img, CVCPoint center, CVCSize axes, double angle, double startAngle, double endAngle, CVCScalar color, int thickness, int lineType, int shift);

/** @overload */
//CVC_EXPORT void CVCellipse(CVCMat img, const RotatedRect& box, CVCScalar color, int thickness, int lineType);

/** @brief Draws a marker on a predefined position in an image. */
CVC_EXPORT void CVCdrawMarker(CVCMat img, CVCPoint position, CVCScalar color, int markerType, int markerSize, int thickness, int line_type);

/** @overload */
CVC_EXPORT void CVCfillConvexPoly(CVCMat img, const CVCPoint* pts, int npts, CVCScalar color, int lineType, int shift);

/** @brief Fills a convex polygon. */
//CVC_EXPORT void CVCfillConvexPoly(CVCMat img, CVCMat points, CVCScalar color, int lineType, int shift);

/** @overload */
CVC_EXPORT void CVCfillPoly(CVCMat img, const CVCPoint** pts, const int* npts, int ncontours, CVCScalar color, int lineType, int shift, CVCPoint offset);

/** @brief Fills the area bounded by one or more polygons. */
//CVC_EXPORT void CVCfillPoly(CVCMat img, InputArrayOfArrays pts, CVCScalar color, int lineType, int shift, CVCPoint offset);

/** @overload */
CVC_EXPORT void CVCpolylines(CVCMat img, const CVCPoint* const* pts, const int* npts, int ncontours, bool isClosed, CVCScalar color, int thickness, int lineType, int shift);

/** @brief Draws several polygonal curves. */
//CVC_EXPORT void CVCpolylines(CVCMat img, InputArrayOfArrays pts, bool isClosed, CVCScalar color, int thickness, int lineType, int shift);

/** @brief Draws contours outlines or filled contours. */
//CVC_EXPORT void CVCdrawContours( CVCMat image, InputArrayOfArrays contours, int contourIdx, CVCScalar color, int thickness, int lineType, CVCMat hierarchy = noArray(), int maxLevel, CVCPoint offset);

/** @brief Clips the line against the image rectangle. */
CVC_EXPORT bool CVCclipLine(CVCSize imgSize, CVCPoint* pt1, CVCPoint* pt2);

/** @overload */
//CVC_EXPORT bool CVCclipLine(Size2l imgSize, Point2l& pt1, Point2l& pt2);

/** @overload */
//CVC_EXPORT bool CVCclipLine(Rect imgRect, CVCPoint* pt1, CVCPoint* pt2);

/** @brief Approximates an elliptic arc with a polyline. */
//CVC_EXPORT void CVCellipse2Poly(CVCPoint center, CVCSize axes, int angle, int arcStart, int arcEnd, int delta, std::vector<CVCPoint>& pts);

/** @overload */
//CVC_EXPORT void CVCellipse2Poly(Point2d center, Size2d axes, int angle, int arcStart, int arcEnd, int delta, std::vector<Point2d>& pts);

/** @brief Draws a text string. */
CVC_EXPORT void CVCputText(CVCMat img, const char* text, CVCPoint org, int fontFace, double fontScale, CVCScalar color, int thickness, int lineType, bool bottomLeftOrigin);

/** @brief Calculates the width and height of a text string. */
CVC_EXPORT CVCSize CVCgetTextSize(const char* text, int fontFace, double fontScale, int thickness, int* baseLine);

/** @brief Calculates the font-specific size to use to achieve a given height in pixels. */
CVC_EXPORT double CVCgetFontScaleFromHeight(int fontFace, int pixelHeight, int thickness);

// MARK: -

#if IGNORE_LINEITERATOR

/** @brief Line iterator */
class LineIterator {

public:
	/** @brief initializes the iterator */
	LineIterator(const Mat& img, CVCPoint pt1, CVCPoint pt2, int connectivity, bool leftToRight)
	{
		init(&img, Rect(0, 0, img.cols, img.rows), pt1, pt2, connectivity, leftToRight);
		ptmode = false;
	}

	LineIterator(CVCPoint pt1, CVCPoint pt2, int connectivity, bool leftToRight)
	{
		init(0, Rect(std::min(pt1.x, pt2.x),
					 std::min(pt1.y, pt2.y),
					 std::max(pt1.x, pt2.x) - std::min(pt1.x, pt2.x) + 1,
					 std::max(pt1.y, pt2.y) - std::min(pt1.y, pt2.y) + 1),
			 pt1, pt2, connectivity, leftToRight);
		ptmode = true;
	}

	LineIterator(CVCSize boundingAreaSize, CVCPoint pt1, CVCPoint pt2, int connectivity, bool leftToRight)
	{
		init(0, Rect(0, 0, boundingAreaSize.width, boundingAreaSize.height),
			 pt1, pt2, connectivity, leftToRight);
		ptmode = true;
	}

	LineIterator(Rect boundingAreaRect, CVCPoint pt1, CVCPoint pt2, int connectivity, bool leftToRight)
	{
		init(0, boundingAreaRect, pt1, pt2, connectivity, leftToRight);
		ptmode = true;
	}

	void init(const Mat* img, Rect boundingAreaRect, CVCPoint pt1, CVCPoint pt2, int connectivity, bool leftToRight);

	/** @brief returns pointer to the current pixel */
	uchar* operator *();

	/** @brief prefix increment operator (++it). shifts iterator to the next pixel */
	LineIterator& operator ++();

	/** @brief postfix increment operator (it++). shifts iterator to the next pixel */
	LineIterator operator ++(int);

	/** @brief returns coordinates of the current pixel */
	CVCPoint pos() const;

	uchar* ptr;
	const uchar* ptr0;
	int step, elemSize;
	int err, count;
	int minusDelta, plusDelta;
	int minusStep, plusStep;
	int minusShift, plusShift;
	CVCPoint p;
	bool ptmode;
};

uchar* LineIterator::operator *()
{
	return ptmode ? 0 : ptr;
}

LineIterator& LineIterator::operator ++()
{
	int mask = err < 0 ? -1 : 0;
	err += minusDelta + (plusDelta & mask);
	if(!ptmode)
	{
		ptr += minusStep + (plusStep & mask);
	}
	else
	{
		p.x += minusShift + (plusShift & mask);
		p.y += minusStep + (plusStep & mask);
	}
	return *this;
}

LineIterator LineIterator::operator ++(int)
{
	LineIterator it = *this;
	++(*this);
	return it;
}

CVCPoint LineIterator::pos() const
{
	if(!ptmode)
	{
		size_t offset = (size_t)(ptr - ptr0);
		int y = (int)(offset/step);
		int x = (int)((offset - (size_t)y*step)/elemSize);
		return CVCPoint(x, y);
	}
	return p;
}

#endif // IGNORE_LINEITERATOR

/* #include "./imgproc/segmentation.hpp" */

#endif /* CVCIMGPROC_H */
