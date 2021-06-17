//
//  CVCImgProc.cpp
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/24/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

//Ptr<LineSegmentDetector> CVCcreateLineSegmentDetector(int _refine, double _scale, double _sigma_scale, double _quant, double _ang_th, double _log_eps, double _density_th, int _n_bins)

CVCMat CVCgetGaussianKernel(int ksize, double sigma, int ktype)
{
	CVCMat mat = CVCMatCreate();
	CVCMatRef(mat) = cv::getGaussianKernel(ksize, sigma, ktype);
	return mat;
}

void CVCgetDerivKernels(CVCMat kx, CVCMat ky, int dx, int dy, int ksize, bool normalize, int ktype)
{
	cv::getDerivKernels(CVCMatRef(kx), CVCMatRef(ky), dx, dy, ksize, normalize, ktype);
}

CVCMat CVCgetGaborKernel(CVCSize ksize, double sigma, double theta, double lambd, double gamma, double psi, int ktype)
{
	CVCMat mat = CVCMatCreate();
	CVCMatRef(mat) = cv::getGaborKernel(CVCSizeRef(ksize), sigma, theta, lambd, gamma, psi, ktype);
	return mat;
}

CVCScalar CVCmorphologyDefaultBorderValue(void)
{
	return { DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX};
}

CVCMat CVCgetStructuringElement(int shape, CVCSize ksize, CVCPoint anchor)
{
	CVCMat mat = CVCMatCreate();
	CVCMatRef(mat) = cv::getStructuringElement(shape, CVCSizeRef(ksize), CVCPointParam(anchor));
	return mat;
}

void CVCmedianBlur(CVCMat src, CVCMat dst, int ksize)
{
	cv::medianBlur(CVCMatRef(src), CVCMatRef(dst), ksize);
}

void CVCGaussianBlur(CVCMat src, CVCMat dst, CVCSize ksize, double sigmaX, double sigmaY, int borderType)
{
	cv::GaussianBlur(ConstCVCMatRef(src), CVCMatRef(dst), CVCSizeRef(ksize), sigmaX, sigmaY, borderType);
}

void CVCbilateralFilter(CVCMat src, CVCMat dst, int d, double sigmaColor, double sigmaSpace, int borderType)
{
	cv::bilateralFilter(CVCMatRef(src), CVCMatRef(dst), d, sigmaColor, sigmaSpace);
}

void CVCboxFilter(CVCMat src, CVCMat dst, int ddepth, CVCSize ksize, CVCPoint anchor, bool normalize, int borderType)
{
	cv::boxFilter(CVCMatRef(src), CVCMatRef(dst), ddepth, CVCSizeRef(ksize), CVCPointParam(anchor), normalize, borderType);
}

void CVCsqrBoxFilter(CVCMat src, CVCMat dst, int ddepth, CVCSize ksize, CVCPoint anchor, bool normalize, int borderType)
{
	cv::sqrBoxFilter(CVCMatRef(src), CVCMatRef(dst), ddepth, CVCSizeRef(ksize), CVCPointParam(anchor), normalize, borderType);
}

void CVCblur(CVCMat src, CVCMat dst, CVCSize ksize, CVCPoint anchor, int borderType)
{
	cv::blur(CVCMatRef(src), CVCMatRef(dst), CVCSizeRef(ksize), CVCPointParam(anchor), borderType);
}

void CVCfilter2D(CVCMat src, CVCMat dst, int ddepth, CVCMat kernel, CVCPoint anchor, double delta, int borderType)
{
	cv::filter2D(CVCMatRef(src), CVCMatRef(dst), ddepth, CVCMatRef(kernel), CVCPointParam(anchor), delta, borderType);
}

void CVCsepFilter2D(CVCMat src, CVCMat dst, int ddepth, CVCMat kernelX, CVCMat kernelY, CVCPoint anchor, double delta, int borderType)
{
	cv::sepFilter2D(CVCMatRef(src), CVCMatRef(dst), ddepth, CVCMatRef(kernelX), CVCMatRef(kernelY), CVCPointParam(anchor), delta, borderType);
}

void CVCSobel(CVCMat src, CVCMat dst, int ddepth, int dx, int dy, int ksize, double scale, double delta, int borderType)
{
	cv::Sobel(CVCMatRef(src), CVCMatRef(dst), ddepth, dx, dy, ksize, scale, delta, borderType);
}

void CVCspatialGradient(CVCMat src, CVCMat dx, CVCMat dy, int ksize, int borderType)
{
	cv::spatialGradient(CVCMatRef(src), CVCMatRef(dx), CVCMatRef(dy), ksize, borderType);
}

void CVCScharr(CVCMat src, CVCMat dst, int ddepth, int dx, int dy, double scale, double delta, int borderType)
{
	cv::Scharr(CVCMatRef(src), CVCMatRef(dst), ddepth, dx, dy, scale, delta, borderType);
}

void CVCLaplacian(CVCMat src, CVCMat dst, int ddepth, int ksize, double scale, double delta, int borderType)
{
	cv::Laplacian(CVCMatRef(src), CVCMatRef(dst), ddepth, ksize, scale, delta, borderType);
}

void CVCCanny(CVCMat image, CVCMat edges, double threshold1, double threshold2, int apertureSize, bool L2gradient)
{
	cv::Canny(ConstCVCMatRef(image), CVCMatRef(edges), threshold1, threshold2, apertureSize, L2gradient);
}

//void CVCCanny(CVCMat dx, CVCMat dy, CVCMat edges, double threshold1, double threshold2, bool L2gradient)

void CVCcornerMinEigenVal(CVCMat src, CVCMat dst, int blockSize, int ksize, int borderType)
{
	cv::cornerMinEigenVal(CVCMatRef(src), CVCMatRef(dst), blockSize, ksize, borderType);
}

void CVCcornerHarris(CVCMat src, CVCMat dst, int blockSize, int ksize, double k, int borderType)
{
	cv::cornerHarris(CVCMatRef(src), CVCMatRef(dst), blockSize, ksize, k, borderType);
}

void CVCcornerEigenValsAndVecs(CVCMat src, CVCMat dst, int blockSize, int ksize, int borderType)
{
	cv::cornerEigenValsAndVecs(CVCMatRef(src), CVCMatRef(dst), blockSize, ksize, borderType);
}

void CVCpreCornerDetect(CVCMat src, CVCMat dst, int ksize, int borderType)
{
	cv::preCornerDetect(CVCMatRef(src), CVCMatRef(dst), ksize, borderType);
}

void CVCcornerSubPix(CVCMat image, CVCMat corners, CVCSize winSize, CVCSize zeroZone, CVCTermCriteria criteria)
{
   cv::cornerSubPix(CVCMatRef(image), CVCMatRef(corners), CVCSizeRef(winSize), CVCSizeRef(zeroZone), CVCTermCriteriaRef(criteria));
}

void CVCgoodFeaturesToTrack(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, int blockSize, bool useHarrisDetector, double k)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();

	cv::goodFeaturesToTrack(CVCMatRef(image), CVCMatRef(corners), maxCorners, qualityLevel, minDistance, CVCMatRef(mask), blockSize, useHarrisDetector, k);
}

//void CVCgoodFeaturesToTrack(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, int blockSize, int gradientSize, bool useHarrisDetector, double k)

void CVCgoodFeaturesToTrackWithQuality(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, CVCMat cornersQuality, int blockSize, int gradientSize, bool useHarrisDetector, double k)
{
	cv::goodFeaturesToTrack(CVCMatRef(image), CVCMatRef(corners), maxCorners, qualityLevel, minDistance, CVCMatRef(mask), CVCMatRef(cornersQuality), blockSize, gradientSize, useHarrisDetector, k);
}

void CVCHoughLines(CVCMat image, CVCMat lines, double rho, double theta, int threshold, double srn, double stn, double min_theta, double max_theta)
{
	cv::HoughLines(CVCMatRef(image), CVCMatRef(lines), rho, theta, threshold, srn, stn, min_theta, max_theta);
}

void CVCHoughLinesP(CVCMat image, CVCMat lines, double rho, double theta, int threshold, double minLineLength, double maxLineGap)
{
	cv::HoughLinesP(CVCMatRef(image), CVCMatRef(lines), rho, theta, threshold, minLineLength, maxLineGap);
}

void CVCHoughLinesPointSet(CVCMat _point, CVCMat _lines, int lines_max, int threshold, double min_rho, double max_rho, double rho_step, double min_theta, double max_theta, double theta_step)
{
	cv::HoughLinesPointSet(CVCMatRef(_point), CVCMatRef(_lines), lines_max, threshold, min_rho, max_rho, rho_step, min_theta, max_theta, theta_step);
}

void CVCHoughCircles(CVCMat image, CVCMat circles, int method, double dp, double minDist, double param1, double param2, int minRadius, int maxRadius)
{
	cv::HoughCircles(CVCMatRef(image), CVCMatRef(circles), method, dp, minDist, param1, param2, minRadius, maxRadius);
}

void CVCerode(CVCMat src, CVCMat dst, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue)
{
	cv::erode(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(kernel), CVCPointParam(anchor), iterations, borderType, CVCScalarParam(borderValue));
}

void CVCdilate(CVCMat src, CVCMat dst, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue)
{
	cv::dilate(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(kernel), CVCPointParam(anchor), iterations, borderType, CVCScalarParam(borderValue));
}

void CVCmorphologyEx(CVCMat src, CVCMat dst, int op, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue)
{
	cv::morphologyEx(CVCMatRef(src), CVCMatRef(dst), op, CVCMatRef(kernel), CVCPointParam(anchor), iterations, borderType, CVCScalarParam(borderValue));
}

void CVCresize(CVCMat src, CVCMat dst, CVCSize dsize, double fx, double fy, int interpolation)
{
	cv::resize(ConstCVCMatRef(src), CVCMatRef(dst), CVCSizeRef(dsize), fx, fy, interpolation);
}

void CVCwarpAffine(CVCMat src, CVCMat dst, CVCMat M, CVCSize dsize, int flags, int borderMode, CVCScalar borderValue)
{
	cv::warpAffine(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(M), CVCSizeRef(dsize), flags, borderMode, CVCScalarParam(borderValue));
}

void CVCwarpPerspective(CVCMat src, CVCMat dst, CVCMat M, CVCSize dsize, int flags, int borderMode, CVCScalar borderValue)
{
	cv::warpPerspective(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(M), CVCSizeRef(dsize), flags, borderMode, CVCScalarParam(borderValue));
}

void CVCremap(CVCMat src, CVCMat dst, CVCMat map1, CVCMat map2, int interpolation, int borderMode, CVCScalar borderValue)
{
	cv::remap(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(map1), CVCMatRef(map2), interpolation, borderMode, CVCScalarParam(borderValue));
}

void CVCconvertMaps(CVCMat map1, CVCMat map2, CVCMat dstmap1, CVCMat dstmap2, int dstmap1type, bool nninterpolation)
{
	cv::convertMaps(CVCMatRef(map1), CVCMatRef(map2), CVCMatRef(dstmap1), CVCMatRef(dstmap2), dstmap1type, nninterpolation);
}

CVCMat CVCgetRotationMatrix2D(CVCPoint2f center, double angle, double scale)
{
	CVCMat mat = CVCMatCreate();
	CVCMatRef(mat) = cv::getRotationMatrix2D(CVCPoint2fParam(center), angle, scale);
	return mat;
}

//Matx23d CVCgetRotationMatrix2D_(CVCPoint2f center, double angle, double scale)

//CVCMat CVCgetAffineTransform(const CVCPoint2f src[], const CVCPoint2f dst[])

void CVCinvertAffineTransform(CVCMat M, CVCMat iM)
{
	cv::invertAffineTransform(CVCMatRef(M), CVCMatRef(iM));
}

CVCMat CVCgetPerspectiveTransform(CVCMat src, CVCMat dst, int solveMethod)
{
	CVCMat mat = CVCMatCreate();
	CVCMatRef(mat) = cv::getPerspectiveTransform(CVCMatRef(src), CVCMatRef(dst), solveMethod);
	return mat;
}

//CVCMat CVCgetPerspectiveTransform(const CVCPoint2f src[], const CVCPoint2f dst[], int solveMethod)

CVCMat CVCgetAffineTransform(CVCMat src, CVCMat dst)
{
	CVCMat mat = CVCMatCreate();
	CVCMatRef(mat) = cv::getAffineTransform(CVCMatRef(src), CVCMatRef(dst));
	return mat;
}

void CVCgetRectSubPix(CVCMat image, CVCSize patchSize, CVCPoint2f center, CVCMat patch, int patchType)
{
	cv::getRectSubPix(CVCMatRef(image), CVCSizeRef(patchSize), CVCPoint2fParam(center), CVCMatRef(patch), patchType);
}

void CVClogPolar(CVCMat src, CVCMat dst, CVCPoint2f center, double M, int flags)
{
	cv::logPolar(CVCMatRef(src), CVCMatRef(dst), CVCPoint2fParam(center), M, flags);
}

void CVClinearPolar(CVCMat src, CVCMat dst, CVCPoint2f center, double maxRadius, int flags)
{
	cv::linearPolar(CVCMatRef(src), CVCMatRef(dst), CVCPoint2fParam(center), maxRadius, flags);
}

void CVCwarpPolar(CVCMat src, CVCMat dst, CVCSize dsize, CVCPoint2f center, double maxRadius, int flags)
{
	cv::warpPolar(CVCMatRef(src), CVCMatRef(dst), CVCSizeRef(dsize), CVCPoint2fParam(center), maxRadius, flags);
}

void CVCintegral(CVCMat src, CVCMat sum, int sdepth)
{
	cv::integral(CVCMatRef(src), CVCMatRef(sum), sdepth);
}

void CVCintegral2(CVCMat src, CVCMat sum, CVCMat sqsum, int sdepth, int sqdepth)
{
	cv::integral(CVCMatRef(src), CVCMatRef(sum), CVCMatRef(sqsum), sdepth, sqdepth);
}

void CVCintegral3(CVCMat src, CVCMat sum, CVCMat sqsum, CVCMat tilted, int sdepth, int sqdepth)
{
	cv::integral(CVCMatRef(src), CVCMatRef(sum), CVCMatRef(sqsum), CVCMatRef(tilted), sdepth, sqdepth);
}

void CVCaccumulate(CVCMat src, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::accumulate(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(mask));
}

void CVCaccumulateSquare(CVCMat src, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::accumulateSquare(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(mask));
}

void CVCaccumulateProduct(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::accumulateProduct(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), CVCMatRef(mask));
}

void CVCaccumulateWeighted(CVCMat src, CVCMat dst, double alpha, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::accumulateWeighted(CVCMatRef(src), CVCMatRef(dst), alpha, CVCMatRef(mask));
}
/*
Point2d CVCphaseCorrelate(CVCMat src1, CVCMat src2, CVCMat window, double* response)
{
	if (window == NULL) window = (CVCMat)&cv::noArray();
}
*/
void CVCcreateHanningWindow(CVCMat dst, CVCSize winSize, int type)
{
	cv::createHanningWindow(CVCMatRef(dst), CVCSizeRef(winSize), type);
}

double CVCthreshold(CVCMat src, CVCMat dst, double thresh, double maxval, int type)
{
	return cv::threshold(CVCMatRef(src), CVCMatRef(dst), thresh, maxval, type);
}

void CVCadaptiveThreshold(CVCMat src, CVCMat dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C)
{
	cv::adaptiveThreshold(CVCMatRef(src), CVCMatRef(dst), maxValue, adaptiveMethod, thresholdType, blockSize, C);
}

void CVCpyrDown(CVCMat src, CVCMat dst, CVCSize dstsize, int borderType)
{
	cv::pyrDown(CVCMatRef(src), CVCMatRef(dst), CVCSizeRef(dstsize), borderType);
}

void CVCpyrUp(CVCMat src, CVCMat dst, CVCSize dstsize, int borderType)
{
	cv::pyrUp(CVCMatRef(src), CVCMatRef(dst), CVCSizeRef(dstsize), borderType);
}

//void CVCbuildPyramid(CVCMat src, OutputArrayOfArrays dst, int maxlevel, int borderType)

void CVCcalcHist(CVCMat images, int nimages, const int* channels, CVCMat mask, CVCMat hist, int dims, const int* histSize, const float** ranges, bool uniform, bool accumulate)
{
   cv::calcHist(ConstCVCMatPtr(images), 1, channels, CVCMatRef(mask), CVCMatRef(hist), dims, histSize, ranges, uniform, accumulate);
}

//void CVCcalcHist(const Mat* images, int nimages, const int* channels, CVCMat mask, SparseMat& hist, int dims, const int* histSize, const float** ranges, bool uniform, bool accumulate)

//void CVCcalcHist(InputArrayOfArrays images, const std::vector<int>& channels, CVCMat mask, CVCMat hist, const std::vector<int>& histSize, const std::vector<float>& ranges, bool accumulate)

//void CVCcalcBackProject(const Mat* images, int nimages, const int* channels, CVCMat hist, CVCMat backProject, const float** ranges, double scale, bool uniform)

//void CVCcalcBackProject(const Mat* images, int nimages, const int* channels, const SparseMat& hist, CVCMat backProject, const float** ranges, double scale, bool uniform)

//void CVCcalcBackProject(InputArrayOfArrays images, const std::vector<int>& channels, CVCMat hist, CVCMat dst, const std::vector<float>& ranges, double scale)

double CVCcompareHist(CVCMat H1, CVCMat H2, int method)
{
	return cv::compareHist(CVCMatRef(H1), CVCMatRef(H2), method);
}

//double CVCcompareHist(const SparseMat& H1, const SparseMat& H2, int method)

void CVCequalizeHist(CVCMat src, CVCMat dst)
{
	cv::equalizeHist(CVCMatRef(src), CVCMatRef(dst));
}

//Ptr<CLAHE> CVCcreateCLAHE(double clipLimit, CVCSize tileGridSize)

float CVCEMD(CVCMat signature1, CVCMat signature2, int distType, CVCMat cost, float* lowerBound, CVCMat flow)
{
	if (cost == NULL) cost = (CVCMat)&cv::noArray();
	if (flow == NULL) flow = (CVCMat)&cv::noArray();

	return cv::EMD(CVCMatRef(signature1), CVCMatRef(signature2), distType, CVCMatRef(cost), lowerBound, CVCMatRef(flow));
}

//float CVCEMD(CVCMat signature1, CVCMat signature2, int distType, CVCMat cost = noArray(), Ptr<float> lowerBound = Ptr<float>(), CVCMat flow = noArray())

void CVCwatershed(CVCMat image, CVCMat markers)
{
	cv::watershed(CVCMatRef(image), CVCMatRef(markers));
}

//void CVCpyrMeanShiftFiltering(CVCMat src, CVCMat dst, double sp, double sr, int maxLevel, TermCriteria termcrit = TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS,5,1))

//void CVCgrabCut(CVCMat img, CVCMat mask, Rect rect, CVCMat bgdModel, CVCMat fgdModel, int iterCount, int mode)

void CVCdistanceTransformWithLabels(CVCMat src, CVCMat dst, CVCMat labels, int distanceType, int maskSize, int labelType)
{
	cv::distanceTransform(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(labels), distanceType, maskSize, labelType);
}

void CVCdistanceTransform(CVCMat src, CVCMat dst, int distanceType, int maskSize, int dstType)
{
	cv::distanceTransform(CVCMatRef(src), CVCMatRef(dst), distanceType, maskSize, dstType);
}

//int CVCfloodFill(CVCMat image, CVCPoint seedPoint, CVCScalar newVal, Rect* rect = 0, CVCScalar loDiff, CVCScalar upDiff, int flags)

//int CVCfloodFill(CVCMat image, CVCMat mask, CVCPoint seedPoint, CVCScalar newVal, Rect* rect=0, CVCScalar loDiff, CVCScalar upDiff, int flags)

void CVCblendLinear(CVCMat src1, CVCMat src2, CVCMat weights1, CVCMat weights2, CVCMat dst)
{
	cv::blendLinear(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(weights1), CVCMatRef(weights2), CVCMatRef(dst));
}

void CVCcvtColor(CVCMat src, CVCMat dst, int code, int dstCn)
{
	cv::cvtColor(ConstCVCMatRef(src), CVCMatRef(dst), code, dstCn);
}

void CVCcvtColorTwoPlane(CVCMat src1, CVCMat src2, CVCMat dst, int code)
{
	cv::cvtColorTwoPlane(ConstCVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), code);
}

void CVCdemosaicing(CVCMat src, CVCMat dst, int code, int dstCn)
{
	cv::demosaicing(CVCMatRef(src), CVCMatRef(dst), code, dstCn);
}

//Moments CVCmoments(CVCMat array, bool binaryImage)

//void CVCHuMoments(const Moments& moments, double hu[7])

//void CVCHuMoments(const Moments& m, CVCMat hu)

void CVCmatchTemplate(CVCMat image, CVCMat templ, CVCMat result, int method, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::matchTemplate(CVCMatRef(image), CVCMatRef(templ), CVCMatRef(result), method, CVCMatRef(mask));
}

int CVCconnectedComponentsWithAlgorithm(CVCMat image, CVCMat labels, int connectivity, int ltype, int ccltype)
{
	return cv::connectedComponents(CVCMatRef(image), CVCMatRef(labels), connectivity, ltype, ccltype);
}

int CVCconnectedComponents(CVCMat image, CVCMat labels, int connectivity, int ltype)
{
	return cv::connectedComponents(CVCMatRef(image), CVCMatRef(labels), connectivity, ltype);
}

int CVCconnectedComponentsWithStatsWithAlgorithm(CVCMat image, CVCMat labels, CVCMat stats, CVCMat centroids, int connectivity, int ltype, int ccltype)
{
	return cv::connectedComponentsWithStats(CVCMatRef(image), CVCMatRef(labels), CVCMatRef(stats), CVCMatRef(centroids), connectivity, ltype, ccltype);
}

int CVCconnectedComponentsWithStats(CVCMat image, CVCMat labels, CVCMat stats, CVCMat centroids, int connectivity, int ltype)
{
	return cv::connectedComponentsWithStats(CVCMatRef(image), CVCMatRef(labels), CVCMatRef(stats), CVCMatRef(centroids), connectivity, ltype);
}

//void CVCfindContours(CVCMat image, OutputArrayOfArrays contours, CVCMat hierarchy, int mode, int method, CVCPoint offset)

//void CVCfindContours(CVCMat image, OutputArrayOfArrays contours, int mode, int method, CVCPoint offset)

void CVCapproxPolyDP(CVCMat curve, CVCMat approxCurve, double epsilon, bool closed)
{
	cv::approxPolyDP(CVCMatRef(curve), CVCMatRef(approxCurve), epsilon, closed);
}

double CVCarcLength(CVCMat curve, bool closed)
{
	return cv::arcLength(CVCMatRef(curve), closed);
}

//Rect CVCboundingRect(CVCMat array)

double CVCcontourArea(CVCMat contour, bool oriented)
{
	return cv::contourArea(CVCMatRef(contour), oriented);
}

//RotatedRect CVCminAreaRect(CVCMat points)

//void CVCboxPoints(RotatedRect box, CVCMat points)

void CVCminEnclosingCircle(CVCMat points, CVCPoint2f *center, float* radius)
{
	cv::Point2f cvCenter = { center->x, center->y };
	cv::minEnclosingCircle(CVCMatRef(points), cvCenter, (*radius));
	center->x = cvCenter.x;
  	center->y = cvCenter.y;
}

double CVCminEnclosingTriangle(CVCMat points, CVCMat triangle)
{
	return cv::minEnclosingTriangle(CVCMatRef(points), CVCMatRef(triangle));
}

double CVCmatchShapes(CVCMat contour1, CVCMat contour2, int method, double parameter)
{
	return cv::matchShapes(CVCMatRef(contour1), CVCMatRef(contour2), method, parameter);
}

void CVCconvexHull(CVCMat points, CVCMat hull, bool clockwise, bool returnPoints)
{
	cv::convexHull(CVCMatRef(points), CVCMatRef(hull), clockwise, returnPoints);
}

void CVCconvexityDefects(CVCMat contour, CVCMat convexhull, CVCMat convexityDefects)
{
	cv::convexityDefects(CVCMatRef(contour), CVCMatRef(convexhull), CVCMatRef(convexityDefects));
}

bool CVCisContourConvex(CVCMat contour)
{
	return cv::isContourConvex(CVCMatRef(contour));
}

float CVCintersectConvexConvex(CVCMat _p1, CVCMat _p2, CVCMat _p12, bool handleNested)
{
	return cv::intersectConvexConvex(CVCMatRef(_p1), CVCMatRef(_p2), CVCMatRef(_p12), handleNested);
}

//RotatedRect CVCfitEllipse(CVCMat points)

//RotatedRect CVCfitEllipseAMS(CVCMat points)

//RotatedRect CVCfitEllipseDirect(CVCMat points)

void CVCfitLine(CVCMat points, CVCMat line, int distType, double param, double reps, double aeps)
{
	cv::fitLine(CVCMatRef(points), CVCMatRef(line), distType, param, reps, aeps);
}

double CVCpointPolygonTest(CVCMat contour, CVCPoint2f pt, bool measureDist)
{
	return cv::pointPolygonTest(CVCMatRef(contour), CVCPoint2fParam(pt), measureDist);
}

//int CVCrotatedRectangleIntersection(const RotatedRect& rect1, const RotatedRect& rect2, CVCMat intersectingRegion)

//Ptr<GeneralizedHoughBallard> CVCcreateGeneralizedHoughBallard()

//Ptr<GeneralizedHoughGuil> CVCcreateGeneralizedHoughGuil()

void CVCapplyColorMap(CVCMat src, CVCMat dst, int colormap)
{
	cv::applyColorMap(CVCMatRef(src), CVCMatRef(dst), colormap);
}

//void CVCapplyColorMap(CVCMat src, CVCMat dst, CVCMat userColor)

void CVCline(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int lineType, int shift)
{
	cv::line(CVCMatRef(img), CVCPointParam(pt1), CVCPointParam(pt2), CVCScalarParam(color), thickness, lineType, shift);
}

void CVCarrowedLine(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int line_type, int shift, double tipLength)
{
	cv::arrowedLine(CVCMatRef(img), CVCPointParam(pt1), CVCPointParam(pt2), CVCScalarParam(color), thickness, line_type, shift, tipLength);
}

void CVCrectangle(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int lineType, int shift)
{
	cv::rectangle(CVCMatRef(img), CVCPointParam(pt1), CVCPointParam(pt2), CVCScalarParam(color), thickness, lineType, shift);
}

void CVCrectangle2(CVCMat img, CVCRect rect, CVCScalar color, int thickness, int lineType, int shift) {
	cv::rectangle(CVCMatRef(img), CVCRectParam(rect), CVCScalarParam(color), thickness, lineType, shift);
}

void CVCcircle(CVCMat img, CVCPoint center, int radius, CVCScalar color, int thickness, int lineType, int shift)
{
	cv::circle(CVCMatRef(img), CVCPointParam(center), radius, CVCScalarParam(color), thickness, lineType, shift);
}

void CVCellipse(CVCMat img, CVCPoint center, CVCSize axes, double angle, double startAngle, double endAngle, CVCScalar color, int thickness, int lineType, int shift)
{
	cv::ellipse(CVCMatRef(img), CVCPointParam(center), CVCSizeRef(axes), angle, startAngle, endAngle, CVCScalarParam(color), thickness, lineType, shift);
}

//void CVCellipse(CVCMat img, const RotatedRect& box, CVCScalar color, int thickness, int lineType)

void CVCdrawMarker(CVCMat img, CVCPoint position, CVCScalar color, int markerType, int markerSize, int thickness, int line_type)
{
	cv::drawMarker(CVCMatRef(img), CVCPointParam(position), CVCScalarParam(color), markerType, markerSize, thickness, line_type);
}
/*
void CVCfillConvexPoly(CVCMat img, const CVCPoint* pts, int npts, CVCScalar color, int lineType, int shift)
{
	cv::fillConvexPoly(CVCMatRef(img), pts, npts, CVCScalarParam(color), lineType, shift);
}
*/
//void CVCfillConvexPoly(CVCMat img, CVCMat points, CVCScalar color, int lineType, int shift)
/*
void CVCfillPoly(CVCMat img, const CVCPoint** pts, const int* npts, int ncontours, CVCScalar color, int lineType, int shift, CVCPoint offset)
{
	cv::fillPoly(CVCMatRef(img), pts, npts, ncontours, CVCScalarParam(color), lineType, shift, CVCPointParam(offset));
}
*/
//void CVCfillPoly(CVCMat img, InputArrayOfArrays pts, CVCScalar color, int lineType, int shift, CVCPoint offset)
/*
void CVCpolylines(CVCMat img, const CVCPoint* const* pts, const int* npts, int ncontours, bool isClosed, CVCScalar color, int thickness, int lineType, int shift)
{
	return cv::polylines(CVCMatRef(img), pts, npts, ncontours, isClosed, CVCScalarParam(color), thickness, lineType, shift);
}
*/
//void CVCpolylines(CVCMat img, InputArrayOfArrays pts, bool isClosed, CVCScalar color, int thickness, int lineType, int shift)

//void CVCdrawContours( CVCMat image, InputArrayOfArrays contours, int contourIdx, CVCScalar color, int thickness, int lineType, CVCMat hierarchy = noArray(), int maxLevel, CVCPoint offset)

bool CVCclipLine(CVCSize imgSize, CVCPoint* pt1, CVCPoint* pt2)
{
	cv::Point point1 = { pt1->x, pt1->y };
	cv::Point point2 = { pt2->x, pt2->y };
	bool result = cv::clipLine(CVCSizeRef(imgSize), point1, point2);
	pt1->x = point1.x; pt1->y = point1.y;
	pt2->x = point2.x; pt2->y = point2.y;
	return result;
}

//bool CVCclipLine(Size2l imgSize, Point2l& pt1, Point2l& pt2)

//bool CVCclipLine(Rect imgRect, CVCPoint* pt1, CVCPoint* pt2)

//void CVCellipse2Poly(CVCPoint center, CVCSize axes, int angle, int arcStart, int arcEnd, int delta, std::vector<CVCPoint>& pts)

//void CVCellipse2Poly(Point2d center, Size2d axes, int angle, int arcStart, int arcEnd, int delta, std::vector<Point2d>& pts)

void CVCputText(CVCMat img, const char* text, CVCPoint org, int fontFace, double fontScale, CVCScalar color, int thickness, int lineType, bool bottomLeftOrigin)
{
	cv::putText(CVCMatRef(img), text, CVCPointParam(org), fontFace, fontScale, CVCScalarParam(color), thickness, lineType, bottomLeftOrigin);
}

CVCSize CVCgetTextSize(const char* text, int fontFace, double fontScale, int thickness, int* baseLine)
{
	cv::Size size = cv::getTextSize(text, fontFace, fontScale, thickness, baseLine);
	return CVCSizeCreate(size.width, size.height);
}

double CVCgetFontScaleFromHeight(int fontFace, int pixelHeight, int thickness)
{
	return cv::getFontScaleFromHeight(fontFace, pixelHeight, thickness);
}
