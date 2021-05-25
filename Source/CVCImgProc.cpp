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
	// TODO: ...
	return NULL;
}

void CVCgetDerivKernels(CVCMat kx, CVCMat ky, int dx, int dy, int ksize, bool normalize, int ktype)
{
	// TODO: ...
}

CVCMat CVCgetGaborKernel(CVCSize ksize, double sigma, double theta, double lambd, double gamma, double psi, int ktype)
{
	// TODO: ...
	return NULL;
}

CVCScalar CVCmorphologyDefaultBorderValue(void)
{
	return { DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX};
}

CVCMat CVCgetStructuringElement(int shape, CVCSize ksize, CVCPoint anchor)
{
	// TODO: ...
	return NULL;
}

void CVCmedianBlur(CVCMat src, CVCMat dst, int ksize)
{
	// TODO: ...
}

void CVCGaussianBlur(CVCMat src, CVCMat dst, CVCSize ksize, double sigmaX, double sigmaY, int borderType)
{
	cv::GaussianBlur(ConstCVCMatRef(src), CVCMatRef(dst), CVCSizeParam(ksize), sigmaX, sigmaY, borderType);
}

void CVCbilateralFilter(CVCMat src, CVCMat dst, int d, double sigmaColor, double sigmaSpace, int borderType)
{
	// TODO: ...
}

void CVCboxFilter(CVCMat src, CVCMat dst, int ddepth, CVCSize ksize, CVCPoint anchor, bool normalize, int borderType)
{
	// TODO: ...
}

void CVCsqrBoxFilter(CVCMat src, CVCMat dst, int ddepth, CVCSize ksize, CVCPoint anchor, bool normalize, int borderType)
{
	// TODO: ...
}

void CVCblur(CVCMat src, CVCMat dst, CVCSize ksize, CVCPoint anchor, int borderType)
{
	// TODO: ...
}

void CVCfilter2D(CVCMat src, CVCMat dst, int ddepth, CVCMat kernel, CVCPoint anchor, double delta, int borderType)
{
	// TODO: ...
}

void CVCsepFilter2D(CVCMat src, CVCMat dst, int ddepth, CVCMat kernelX, CVCMat kernelY, CVCPoint anchor, double delta, int borderType)
{
	// TODO: ...
}

void CVCSobel(CVCMat src, CVCMat dst, int ddepth, int dx, int dy, int ksize, double scale, double delta, int borderType)
{
	// TODO: ...
}

void CVCspatialGradient(CVCMat src, CVCMat dx, CVCMat dy, int ksize, int borderType)
{
	// TODO: ...
}

void CVCScharr(CVCMat src, CVCMat dst, int ddepth, int dx, int dy, double scale, double delta, int borderType)
{
	// TODO: ...
}

void CVCLaplacian(CVCMat src, CVCMat dst, int ddepth, int ksize, double scale, double delta, int borderType)
{
	// TODO: ...
}

void CVCCanny(CVCMat image, CVCMat edges, double threshold1, double threshold2, int apertureSize, bool L2gradient)
{
	cv::Canny(ConstCVCMatRef(image), CVCMatRef(edges), threshold1, threshold2, apertureSize, L2gradient);
}

//void CVCCanny(CVCMat dx, CVCMat dy, CVCMat edges, double threshold1, double threshold2, bool L2gradient)

void CVCcornerMinEigenVal(CVCMat src, CVCMat dst, int blockSize, int ksize, int borderType)
{
	// TODO: ...
}

void CVCcornerHarris(CVCMat src, CVCMat dst, int blockSize, int ksize, double k, int borderType)
{
	// TODO: ...
}

void CVCcornerEigenValsAndVecs(CVCMat src, CVCMat dst, int blockSize, int ksize, int borderType)
{
	// TODO: ...
}

void CVCpreCornerDetect(CVCMat src, CVCMat dst, int ksize, int borderType)
{
	// TODO: ...
}

//void CVCcornerSubPix(CVCMat image, CVCMat corners, CVCSize winSize, CVCSize zeroZone, TermCriteria criteria)

void CVCgoodFeaturesToTrack(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, int blockSize, bool useHarrisDetector, double k)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	// TODO: ...
}

//void CVCgoodFeaturesToTrack(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, int blockSize, int gradientSize, bool useHarrisDetector, double k)

void CVCgoodFeaturesToTrackWithQuality(CVCMat image, CVCMat corners, int maxCorners, double qualityLevel, double minDistance, CVCMat mask, CVCMat cornersQuality, int blockSize, int gradientSize, bool useHarrisDetector, double k)
{
	// TODO: ...
}

void CVCHoughLines(CVCMat image, CVCMat lines, double rho, double theta, int threshold, double srn, double stn, double min_theta, double max_theta)
{
	// TODO: ...
}

void CVCHoughLinesP(CVCMat image, CVCMat lines, double rho, double theta, int threshold, double minLineLength, double maxLineGap)
{
	// TODO: ...
}

void CVCHoughLinesPointSet(CVCMat _point, CVCMat _lines, int lines_max, int threshold, double min_rho, double max_rho, double rho_step, double min_theta, double max_theta, double theta_step)
{
	// TODO: ...
}

void CVCHoughCircles(CVCMat image, CVCMat circles, int method, double dp, double minDist, double param1, double param2, int minRadius, int maxRadius)
{
	// TODO: ...
}

void CVCerode(CVCMat src, CVCMat dst, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue)
{
	// TODO: ...
}

void CVCdilate(CVCMat src, CVCMat dst, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue)
{
	// TODO: ...
}

void CVCmorphologyEx(CVCMat src, CVCMat dst, int op, CVCMat kernel, CVCPoint anchor, int iterations, int borderType, CVCScalar borderValue)
{
	// TODO: ...
}

void CVCresize(CVCMat src, CVCMat dst, CVCSize dsize, double fx, double fy, int interpolation)
{
	cv::resize(ConstCVCMatRef(src), CVCMatRef(dst), CVCSizeParam(dsize), fx, fy, interpolation);
}

void CVCwarpAffine(CVCMat src, CVCMat dst, CVCMat M, CVCSize dsize, int flags, int borderMode, CVCScalar borderValue)
{
	// TODO: ...
}

void CVCwarpPerspective(CVCMat src, CVCMat dst, CVCMat M, CVCSize dsize, int flags, int borderMode, CVCScalar borderValue)
{
	// TODO: ...
}

void CVCremap(CVCMat src, CVCMat dst, CVCMat map1, CVCMat map2, int interpolation, int borderMode, CVCScalar borderValue)
{
	// TODO: ...
}

void CVCconvertMaps(CVCMat map1, CVCMat map2, CVCMat dstmap1, CVCMat dstmap2, int dstmap1type, bool nninterpolation)
{
	// TODO: ...
}

CVCMat CVCgetRotationMatrix2D(CVCPoint2f center, double angle, double scale)
{
	// TODO: ...
	return NULL;
}

//Matx23d CVCgetRotationMatrix2D_(CVCPoint2f center, double angle, double scale)

//CVCMat CVCgetAffineTransform(const CVCPoint2f src[], const CVCPoint2f dst[])

void CVCinvertAffineTransform(CVCMat M, CVCMat iM)
{
	// TODO: ...
}

CVCMat CVCgetPerspectiveTransform(CVCMat src, CVCMat dst, int solveMethod)
{
	// TODO: ...
	return NULL;
}

//CVCMat CVCgetPerspectiveTransform(const CVCPoint2f src[], const CVCPoint2f dst[], int solveMethod)

CVCMat CVCgetAffineTransform(CVCMat src, CVCMat dst)
{
	// TODO: ...
	return NULL;
}

void CVCgetRectSubPix(CVCMat image, CVCSize patchSize, CVCPoint2f center, CVCMat patch, int patchType)
{
	// TODO: ...
}

void CVClogPolar(CVCMat src, CVCMat dst, CVCPoint2f center, double M, int flags)
{
	// TODO: ...
}

void CVClinearPolar(CVCMat src, CVCMat dst, CVCPoint2f center, double maxRadius, int flags)
{
	// TODO: ...
}

void CVCwarpPolar(CVCMat src, CVCMat dst, CVCSize dsize, CVCPoint2f center, double maxRadius, int flags)
{
	// TODO: ...
}

void CVCintegral(CVCMat src, CVCMat sum, int sdepth)
{
	// TODO: ...
}

void CVCintegral2(CVCMat src, CVCMat sum, CVCMat sqsum, int sdepth, int sqdepth)
{
	// TODO: ...
}

void CVCintegral3(CVCMat src, CVCMat sum, CVCMat sqsum, CVCMat tilted, int sdepth, int sqdepth)
{
	// TODO: ...
}

void CVCaccumulate(CVCMat src, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	// TODO: ...
}

void CVCaccumulateSquare(CVCMat src, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	// TODO: ...
}

void CVCaccumulateProduct(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	// TODO: ...
}

void CVCaccumulateWeighted(CVCMat src, CVCMat dst, double alpha, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	// TODO: ...
}
/*
Point2d CVCphaseCorrelate(CVCMat src1, CVCMat src2, CVCMat window, double* response)
{
	if (window == NULL) window = (CVCMat)&cv::noArray();
	// TODO: ...
}
*/
void CVCcreateHanningWindow(CVCMat dst, CVCSize winSize, int type)
{
	// TODO: ...
}

double CVCthreshold(CVCMat src, CVCMat dst, double thresh, double maxval, int type)
{
	// TODO: ...
	return 0.0;
}

void CVCadaptiveThreshold(CVCMat src, CVCMat dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C)
{
	// TODO: ...
}

void CVCpyrDown(CVCMat src, CVCMat dst, CVCSize dstsize, int borderType)
{
	// TODO: ...
}

void CVCpyrUp(CVCMat src, CVCMat dst, CVCSize dstsize, int borderType)
{
	// TODO: ...
}

//void CVCbuildPyramid(CVCMat src, OutputArrayOfArrays dst, int maxlevel, int borderType)

//void CVCcalcHist(const Mat* images, int nimages, const int* channels, CVCMat mask, CVCMat hist, int dims, const int* histSize, const float** ranges, bool uniform, bool accumulate)

//void CVCcalcHist(const Mat* images, int nimages, const int* channels, CVCMat mask, SparseMat& hist, int dims, const int* histSize, const float** ranges, bool uniform, bool accumulate)

//void CVCcalcHist(InputArrayOfArrays images, const std::vector<int>& channels, CVCMat mask, CVCMat hist, const std::vector<int>& histSize, const std::vector<float>& ranges, bool accumulate)

//void CVCcalcBackProject(const Mat* images, int nimages, const int* channels, CVCMat hist, CVCMat backProject, const float** ranges, double scale, bool uniform)

//void CVCcalcBackProject(const Mat* images, int nimages, const int* channels, const SparseMat& hist, CVCMat backProject, const float** ranges, double scale, bool uniform)

//void CVCcalcBackProject(InputArrayOfArrays images, const std::vector<int>& channels, CVCMat hist, CVCMat dst, const std::vector<float>& ranges, double scale)

double CVCcompareHist(CVCMat H1, CVCMat H2, int method)
{
	// TODO: ...
	return 0.0;
}

//double CVCcompareHist(const SparseMat& H1, const SparseMat& H2, int method)

void CVCequalizeHist(CVCMat src, CVCMat dst)
{
	// TODO: ...
}

//Ptr<CLAHE> CVCcreateCLAHE(double clipLimit, CVCSize tileGridSize)

float CVCEMD(CVCMat signature1, CVCMat signature2, int distType, CVCMat cost, float* lowerBound, CVCMat flow)
{
	if (cost == NULL) cost = (CVCMat)&cv::noArray();
	if (flow == NULL) flow = (CVCMat)&cv::noArray();

	// TODO: ...

	return 0.0f;
}

//float CVCEMD(CVCMat signature1, CVCMat signature2, int distType, CVCMat cost = noArray(), Ptr<float> lowerBound = Ptr<float>(), CVCMat flow = noArray())

void CVCwatershed(CVCMat image, CVCMat markers)
{
	// TODO: ...
}

//void CVCpyrMeanShiftFiltering(CVCMat src, CVCMat dst, double sp, double sr, int maxLevel, TermCriteria termcrit = TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS,5,1))

//void CVCgrabCut(CVCMat img, CVCMat mask, Rect rect, CVCMat bgdModel, CVCMat fgdModel, int iterCount, int mode)

void CVCdistanceTransformWithLabels(CVCMat src, CVCMat dst, CVCMat labels, int distanceType, int maskSize, int labelType)
{
	// TODO: ...
}

void CVCdistanceTransform(CVCMat src, CVCMat dst, int distanceType, int maskSize, int dstType)
{
	// TODO: ...
}

//int CVCfloodFill(CVCMat image, CVCPoint seedPoint, CVCScalar newVal, Rect* rect = 0, CVCScalar loDiff, CVCScalar upDiff, int flags)

//int CVCfloodFill(CVCMat image, CVCMat mask, CVCPoint seedPoint, CVCScalar newVal, Rect* rect=0, CVCScalar loDiff, CVCScalar upDiff, int flags)

void CVCblendLinear(CVCMat src1, CVCMat src2, CVCMat weights1, CVCMat weights2, CVCMat dst)
{
	// TODO: ...
}

void CVCcvtColor(CVCMat src, CVCMat dst, int code, int dstCn)
{
	cv::cvtColor(ConstCVCMatRef(src), CVCMatRef(dst), code, dstCn);
}

void CVCcvtColorTwoPlane(CVCMat src1, CVCMat src2, CVCMat dst, int code)
{
	// TODO: ...
}

void CVCdemosaicing(CVCMat src, CVCMat dst, int code, int dstCn)
{
	// TODO: ...
}

//Moments CVCmoments(CVCMat array, bool binaryImage)

//void CVCHuMoments(const Moments& moments, double hu[7])

//void CVCHuMoments(const Moments& m, CVCMat hu)

void CVCmatchTemplate(CVCMat image, CVCMat templ, CVCMat result, int method, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	// TODO: ...
}

int CVCconnectedComponentsWithAlgorithm(CVCMat image, CVCMat labels, int connectivity, int ltype, int ccltype)
{
	// TODO: ...
	return 0;
}

int CVCconnectedComponents(CVCMat image, CVCMat labels, int connectivity, int ltype)
{
	// TODO: ...
	return 0;
}

int CVCconnectedComponentsWithStatsWithAlgorithm(CVCMat image, CVCMat labels, CVCMat stats, CVCMat centroids, int connectivity, int ltype, int ccltype)
{
	// TODO: ...
	return 0;
}

int CVCconnectedComponentsWithStats(CVCMat image, CVCMat labels, CVCMat stats, CVCMat centroids, int connectivity, int ltype)
{
	// TODO: ...
	return 0;
}

//void CVCfindContours(CVCMat image, OutputArrayOfArrays contours, CVCMat hierarchy, int mode, int method, CVCPoint offset)

//void CVCfindContours(CVCMat image, OutputArrayOfArrays contours, int mode, int method, CVCPoint offset)

void CVCapproxPolyDP(CVCMat curve, CVCMat approxCurve, double epsilon, bool closed)
{
	// TODO: ...
}

double CVCarcLength(CVCMat curve, bool closed)
{
	// TODO: ...
	return 0.0;
}

//Rect CVCboundingRect(CVCMat array)

double CVCcontourArea(CVCMat contour, bool oriented)
{
	// TODO: ...
	return 0.0;
}

//RotatedRect CVCminAreaRect(CVCMat points)

//void CVCboxPoints(RotatedRect box, CVCMat points)

void CVCminEnclosingCircle(CVCMat points, CVCPoint2f *center, float* radius)
{
	// TODO: ...
}

double CVCminEnclosingTriangle(CVCMat points, CVCMat triangle)
{
	// TODO: ...
	return 0.0;
}

double CVCmatchShapes(CVCMat contour1, CVCMat contour2, int method, double parameter)
{
	// TODO: ...
	return 0.0;
}

void CVCconvexHull(CVCMat points, CVCMat hull, bool clockwise, bool returnPoints)
{
	// TODO: ...
}

void CVCconvexityDefects(CVCMat contour, CVCMat convexhull, CVCMat convexityDefects)
{
	// TODO: ...
}

bool CVCisContourConvex(CVCMat contour)
{
	// TODO: ...
	return false;
}

float CVCintersectConvexConvex(CVCMat _p1, CVCMat _p2, CVCMat _p12, bool handleNested)
{
	// TODO: ...
	return 0.0f;
}

//RotatedRect CVCfitEllipse(CVCMat points)

//RotatedRect CVCfitEllipseAMS(CVCMat points)

//RotatedRect CVCfitEllipseDirect(CVCMat points)

void CVCfitLine(CVCMat points, CVCMat line, int distType, double param, double reps, double aeps)
{
	// TODO: ...
}

double CVCpointPolygonTest(CVCMat contour, CVCPoint2f pt, bool measureDist)
{
	// TODO: ...
	return 0.0;
}

//int CVCrotatedRectangleIntersection(const RotatedRect& rect1, const RotatedRect& rect2, CVCMat intersectingRegion)

//Ptr<GeneralizedHoughBallard> CVCcreateGeneralizedHoughBallard()

//Ptr<GeneralizedHoughGuil> CVCcreateGeneralizedHoughGuil()

void CVCapplyColorMap(CVCMat src, CVCMat dst, int colormap)
{
	// TODO: ...
}

//void CVCapplyColorMap(CVCMat src, CVCMat dst, CVCMat userColor)

void CVCline(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int lineType, int shift)
{
	// TODO: ...
}

void CVCarrowedLine(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int line_type, int shift, double tipLength)
{
	// TODO: ...
}

void CVCrectangle(CVCMat img, CVCPoint pt1, CVCPoint pt2, CVCScalar color, int thickness, int lineType, int shift)
{
	// TODO: ...
}

//void CVCrectangle(CVCMat img, Rect rec, CVCScalar color, int thickness, int lineType, int shift)

void CVCcircle(CVCMat img, CVCPoint center, int radius, CVCScalar color, int thickness, int lineType, int shift)
{
	// TODO: ...
}

void CVCellipse(CVCMat img, CVCPoint center, CVCSize axes, double angle, double startAngle, double endAngle, CVCScalar color, int thickness, int lineType, int shift)
{
	// TODO: ...
}

//void CVCellipse(CVCMat img, const RotatedRect& box, CVCScalar color, int thickness, int lineType)

void CVCdrawMarker(CVCMat img, CVCPoint position, CVCScalar color, int markerType, int markerSize, int thickness, int line_type)
{
	// TODO: ...
}

void CVCfillConvexPoly(CVCMat img, const CVCPoint* pts, int npts, CVCScalar color, int lineType, int shift)
{
	// TODO: ...
}

//void CVCfillConvexPoly(CVCMat img, CVCMat points, CVCScalar color, int lineType, int shift)

void CVCfillPoly(CVCMat img, const CVCPoint** pts, const int* npts, int ncontours, CVCScalar color, int lineType, int shift, CVCPoint offset)
{
	// TODO: ...
}

//void CVCfillPoly(CVCMat img, InputArrayOfArrays pts, CVCScalar color, int lineType, int shift, CVCPoint offset)

void CVCpolylines(CVCMat img, const CVCPoint* const* pts, const int* npts, int ncontours, bool isClosed, CVCScalar color, int thickness, int lineType, int shift)
{
	// TODO: ...
}

//void CVCpolylines(CVCMat img, InputArrayOfArrays pts, bool isClosed, CVCScalar color, int thickness, int lineType, int shift)

//void CVCdrawContours( CVCMat image, InputArrayOfArrays contours, int contourIdx, CVCScalar color, int thickness, int lineType, CVCMat hierarchy = noArray(), int maxLevel, CVCPoint offset)

bool CVCclipLine(CVCSize imgSize, CVCPoint* pt1, CVCPoint* pt2)
{
	// TODO: ...
	return false;
}

//bool CVCclipLine(Size2l imgSize, Point2l& pt1, Point2l& pt2)

//bool CVCclipLine(Rect imgRect, CVCPoint* pt1, CVCPoint* pt2)

//void CVCellipse2Poly(CVCPoint center, CVCSize axes, int angle, int arcStart, int arcEnd, int delta, std::vector<CVCPoint>& pts)

//void CVCellipse2Poly(Point2d center, Size2d axes, int angle, int arcStart, int arcEnd, int delta, std::vector<Point2d>& pts)

void CVCputText(CVCMat img, const char* text, CVCPoint org, int fontFace, double fontScale, CVCScalar color, int thickness, int lineType, bool bottomLeftOrigin)
{
	// TODO: ...
}

CVCSize CVCgetTextSize(const char* text, int fontFace, double fontScale, int thickness, int* baseLine)
{
	// TODO: ...
	return { 0, 0 };
}

double CVCgetFontScaleFromHeight(int fontFace, int pixelHeight, int thickness)
{
	// TODO: ...
	return 0.0;
}
