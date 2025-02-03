//
//  CVCCore.cpp
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/12/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

void CVCswap(CVCMat a, CVCMat b)
{
	cv::swap(CVCMatRef(a), CVCMatRef(b));
}
/*
void CVCswap(UMat& a, UMat& b)
{
}
*/
int CVCborderInterpolate(int p, int len, int borderType)
{
	return cv::borderInterpolate(p, len, borderType);
}
/*
void CVCcopyMakeBorder(const CVCMat src, CVCMat dst, int top, int bottom, int left, int right, int borderType, const Scalar& value)
{
}
*/
void CVCadd(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask, int dtype)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::add(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), CVCMatRef(mask), dtype);
}

void CVCsubtract(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask, int dtype)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::subtract(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), CVCMatRef(mask), dtype);
}

void CVCmultiply(CVCMat src1, CVCMat src2, CVCMat dst, double scale, int dtype)
{
	cv::multiply(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), scale, dtype);
}

void CVCdivide(CVCMat src1, CVCMat src2, CVCMat dst, double scale, int dtype)
{
	cv::divide(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), scale, dtype);
}
/*
void CVCdivide(double scale, CVCMat src2, CVCMat dst, int dtype)
{
}
*/
void CVCscaleAdd(CVCMat src1, double alpha, CVCMat src2, CVCMat dst)
{
	cv::scaleAdd(CVCMatRef(src1), alpha, CVCMatRef(src2), CVCMatRef(dst));
}

void CVCaddWeighted(CVCMat src1, double alpha, CVCMat src2, double beta, double gamma, CVCMat dst, int dtype)
{
	cv::addWeighted(CVCMatRef(src1), alpha, CVCMatRef(src2), beta, gamma, CVCMatRef(dst), dtype);
}

void CVCconvertScaleAbs(CVCMat src, CVCMat dst, double alpha, double beta)
{
	cv::convertScaleAbs(CVCMatRef(src), CVCMatRef(dst), alpha, beta);
}

void CVCconvertFp16(CVCMat src, CVCMat dst)
{
	cv::convertFp16(CVCMatRef(src), CVCMatRef(dst));
}

void CVCLUT(CVCMat src, CVCMat lut, CVCMat dst)
{
	cv::LUT(CVCMatRef(src), CVCMatRef(lut), CVCMatRef(dst));
}
/*
Scalar CVCsumElems(CVCMat src)
{
}
*/

int CVCcountNonZero(CVCMat src)
{
	return cv::countNonZero(CVCMatRef(src));
}

void CVCfindNonZero(CVCMat src, CVCMat idx)
{
	cv::findNonZero(CVCMatRef(src), CVCMatRef(idx));
}
/*
Scalar CVCmean(CVCMat src, CVCMat mask)
{
	return cv::mean(CVCMatRef(src), CVCMatRef(mask));
}
*/
void CVCmeanStdDev(CVCMat src, CVCMat mean, CVCMat stddev, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::meanStdDev(CVCMatRef(src), CVCMatRef(mean), CVCMatRef(stddev), CVCMatRef(mask));
}

double CVCnorm(CVCMat src1, int normType, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	return cv::norm(CVCMatRef(src1), normType, CVCMatRef(mask));
}
/*
double CVCnorm(CVCMat src1, CVCMat src2, int normType, CVCMat mask)
{
}

double CVCnorm(const SparseMat& src, int normType)
{
}
*/
double CVCPSNR(CVCMat src1, CVCMat src2, double R)
{
	return cv::PSNR(CVCMatRef(src1), CVCMatRef(src2), R);
}

void CVCbatchDistance(CVCMat src1, CVCMat src2, CVCMat dist, int dtype, CVCMat nidx, int normType, int K, CVCMat mask, int update, bool crosscheck)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::batchDistance(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dist), dtype, CVCMatRef(nidx), normType, K, CVCMatRef(mask), update, crosscheck);
}
/*
void CVCnormalize(CVCMat src, InputOutputArray dst, double alpha, double beta, int norm_type, int dtype, CVCMat mask)
{
}

void CVCnormalize(const SparseMat& src, SparseMat& dst, double alpha, int normType)
{
}

void CVCminMaxLoc(CVCMat src, double* minVal, double* maxVal, Point* minLoc, Point* maxLoc, CVCMat mask)
{
}
*/
void CVCminMaxIdx(CVCMat src, double* minVal, double* maxVal, int* minIdx, int* maxIdx, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::minMaxIdx(CVCMatRef(src), minVal, maxVal, minIdx, maxIdx, CVCMatRef(mask));
}
/*
void CVCminMaxLoc(const SparseMat& a, double* minVal, double* maxVal, int* minIdx, int* maxIdx)
{
}
*/
void CVCreduce(CVCMat src, CVCMat dst, int dim, int rtype, int dtype)
{
	cv::reduce(CVCMatRef(src), CVCMatRef(dst), dim, rtype, dtype);
}

void CVCmerge1(const CVCMat mv, size_t count, CVCMat dst)
{
	cv::merge(ConstCVCMatPtr(mv), count, CVCMatRef(dst));
}
void CVCmerge2(CVCInputArray array, CVCMat dst)
{
	cv::merge(CVCInputArrayRef(array), CVCMatRef(dst));
}
void CVCsplit1(const CVCMat src, CVCMat mvbegin)
{
	cv::split(ConstCVCMatRef(src), CVCMatRef(mvbegin));
}

void CVCsplit2(CVCMat m, CVCOutputArray mv)
{
	cv::split(CVCMatRef(m), CVCOutputArrayRef(mv));
}

void CVCmixChannels1(const CVCMat src, size_t nsrcs, CVCMat dst, size_t ndsts, const int* fromTo, size_t npairs)
{
	cv::mixChannels(ConstCVCMatPtr(src), nsrcs, CVCMatPtr(dst), ndsts, fromTo, npairs);
}

void CVCmixChannels2(CVCInputArray src, CVCInputOutputArray dst, const int* fromTo, size_t npairs)
{
	cv::mixChannels(CVCInputArrayRef(src), ConstCVCInputOutputArrayRef(dst), fromTo, npairs);
}
/*
void CVCmixChannels(InputArrayOfArrays src, InputOutputArrayOfArrays dst, const std::vector<int>& fromTo)
{
}
*/
void CVCextractChannel(CVCMat src, CVCMat dst, int coi)
{
	cv::extractChannel(CVCMatRef(src), CVCMatRef(dst), coi);
}

void CVCinsertChannel(CVCMat src, CVCInputOutputArray dst, int coi)
{
	cv::insertChannel(CVCMatRef(src), CVCInputOutputArrayRef(dst), coi);
}
void CVCflip(CVCMat src, CVCMat dst, int flipCode)
{
	cv::flip(CVCMatRef(src), CVCMatRef(dst), flipCode);
}

void CVCrotate(CVCMat src, CVCMat dst, int rotateCode)
{
	cv::rotate(CVCMatRef(src), CVCMatRef(dst), rotateCode);
}

void CVCrepeat(CVCMat src, int ny, int nx, CVCMat dst)
{
	cv::repeat(CVCMatRef(src), ny, nx, CVCMatRef(dst));
}
/*
CVCMat CVCrepeat(const CVCMat src, int ny, int nx)
{
}
*/


void CVChconcat1(const CVCMat src, size_t nsrc, CVCMat dst)
{
	cv::hconcat(ConstCVCMatRef(src), nsrc, CVCMatRef(dst));
}

void CVChconcat2(CVCMat src1, CVCMat src2, CVCMat dst)
{
	cv::hconcat(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst));
}

void CVChconcat3(CVCInputArray src, CVCMat dst)
{
	cv::hconcat(CVCInputArrayRef(src), CVCMatRef(dst));
}

void CVCvconcat1(const CVCMat src, size_t nsrc, CVCMat dst)
{
	cv::vconcat(ConstCVCMatRef(src), nsrc, CVCMatRef(dst));
}

void CVCvconcat2(CVCMat src1, CVCMat src2, CVCMat dst)
{
	cv::vconcat(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst));
}

void CVCvconcat3(CVCInputArray src, CVCMat dst)
{
	cv::vconcat(CVCInputArrayRef(src), CVCMatRef(dst));
}
void CVCbitwise_and(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::bitwise_and(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), CVCMatRef(mask));
}

void CVCbitwise_or(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::bitwise_or(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), CVCMatRef(mask));
}

void CVCbitwise_xor(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::bitwise_xor(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), CVCMatRef(mask));
}

void CVCbitwise_not(CVCMat src, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::bitwise_not(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(mask));
}

void CVCabsdiff(CVCMat src1, CVCMat src2, CVCMat dst)
{
	cv::absdiff(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst));
}

void CVCcopyTo(CVCMat src, CVCMat dst, CVCMat mask)
{
	if (mask == NULL) mask = (CVCMat)&cv::noArray();
	cv::copyTo(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(mask));
}

void CVCinRange(CVCMat src, CVCMat lowerb, CVCMat upperb, CVCMat dst)
{
	cv::inRange(CVCMatRef(src), CVCMatRef(lowerb), CVCMatRef(upperb), CVCMatRef(dst));
}

void CVCcompare(CVCMat src1, CVCMat src2, CVCMat dst, int cmpop)
{
	cv::compare(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), cmpop);
}

void CVCmin(CVCMat src1, CVCMat src2, CVCMat dst)
{
	cv::min(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst));
}
/*
void CVCmin(const CVCMat src1, const CVCMat src2, CVCMat dst)
{
}

void CVCmin(const UMat& src1, const UMat& src2, UMat& dst)
{
}
*/
void CVCmax(CVCMat src1, CVCMat src2, CVCMat dst)
{
	cv::max(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst));
}
/*
void CVCmax(const CVCMat src1, const CVCMat src2, CVCMat dst)
{
}

void CVCmax(const UMat& src1, const UMat& src2, UMat& dst)
{
}
*/
void CVCsqrt(CVCMat src, CVCMat dst)
{
	cv::sqrt(CVCMatRef(src), CVCMatRef(dst));
}

void CVCpow(CVCMat src, double power, CVCMat dst)
{
	cv::pow(CVCMatRef(src), power, CVCMatRef(dst));
}

void CVCexp(CVCMat src, CVCMat dst)
{
	cv::exp(CVCMatRef(src), CVCMatRef(dst));
}

void CVClog(CVCMat src, CVCMat dst)
{
	cv::log(CVCMatRef(src), CVCMatRef(dst));
}

void CVCpolarToCart(CVCMat magnitude, CVCMat angle, CVCMat x, CVCMat y, bool angleInDegrees)
{
	cv::polarToCart(CVCMatRef(magnitude), CVCMatRef(angle), CVCMatRef(x), CVCMatRef(y), angleInDegrees);
}

void CVCcartToPolar(CVCMat x, CVCMat y, CVCMat magnitude, CVCMat angle, bool angleInDegrees)
{
	cv::cartToPolar(CVCMatRef(x), CVCMatRef(y), CVCMatRef(magnitude), CVCMatRef(angle), angleInDegrees);
}

void CVCphase(CVCMat x, CVCMat y, CVCMat angle, bool angleInDegrees)
{
	cv::phase(CVCMatRef(x), CVCMatRef(y), CVCMatRef(angle), angleInDegrees);
}

void CVCmagnitude(CVCMat x, CVCMat y, CVCMat magnitude)
{
	cv::magnitude(CVCMatRef(x), CVCMatRef(y), CVCMatRef(magnitude));
}
/*
bool CVCcheckRange(CVCMat a, bool quiet, Point* pos, double minVal, double maxVal)
{
}
*/
void CVCpatchNaNs(CVCInputOutputArray a, double val)
{
	cv::patchNaNs(CVCInputOutputArrayRef(a), val);
}

void CVCgemm(CVCMat src1, CVCMat src2, double alpha, CVCMat src3, double beta, CVCMat dst, int flags)
{
	cv::gemm(CVCMatRef(src1), CVCMatRef(src2), alpha, CVCMatRef(src3), beta, CVCMatRef(dst), flags);
}

void CVCmulTransposed(CVCMat src, CVCMat dst, bool aTa, CVCMat delta, double scale, int dtype)
{
	if (delta == NULL) delta = (CVCMat)&cv::noArray();
	cv::mulTransposed(CVCMatRef(src), CVCMatRef(dst), aTa, CVCMatRef(delta), scale, dtype);
}

void CVCtranspose(CVCMat src, CVCMat dst)
{
	cv::transpose(CVCMatRef(src), CVCMatRef(dst));
}

void CVCtransform(CVCMat src, CVCMat dst, CVCMat m)
{
	cv::transform(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(m));
}

void CVCperspectiveTransform(CVCMat src, CVCMat dst, CVCMat m)
{
	cv::perspectiveTransform(CVCMatRef(src), CVCMatRef(dst), CVCMatRef(m));
}

void CVCcompleteSymm(CVCInputOutputArray m, bool lowerToUpper)
{
	cv::completeSymm(CVCInputOutputArrayRef(m), lowerToUpper);
}
/*
void CVCsetIdentity(InputOutputArray mtx, const Scalar& s)
{
}
*/
double CVCdeterminant(CVCMat mtx)
{
	return cv::determinant(CVCMatRef(mtx));
}
/*
Scalar CVCtrace(CVCMat mtx)
{
}
*/
double CVCinvert(CVCMat src, CVCMat dst, int flags)
{
	return cv::invert(CVCMatRef(src), CVCMatRef(dst), flags);
}

bool CVCsolve(CVCMat src1, CVCMat src2, CVCMat dst, int flags)
{
	return cv::solve(CVCMatRef(src1), CVCMatRef(src2), CVCMatRef(dst), flags);
}

void CVCsort(CVCMat src, CVCMat dst, int flags)
{
	cv::sort(CVCMatRef(src), CVCMatRef(dst), flags);
}

void CVCsortIdx(CVCMat src, CVCMat dst, int flags)
{
	cv::sortIdx(CVCMatRef(src), CVCMatRef(dst), flags);
}

int CVCsolveCubic(CVCMat coeffs, CVCMat roots)
{
	return cv::solveCubic(CVCMatRef(coeffs), CVCMatRef(roots));
}

double CVCsolvePoly(CVCMat coeffs, CVCMat roots, int maxIters)
{
	return cv::solvePoly(CVCMatRef(coeffs), CVCMatRef(roots), maxIters);
}

bool CVCeigen(CVCMat src, CVCMat eigenvalues, CVCMat eigenvectors)
{
	if (eigenvectors == NULL) eigenvectors = (CVCMat)&cv::noArray();
	return cv::eigen(CVCMatRef(src), CVCMatRef(eigenvalues), CVCMatRef(eigenvectors));
}

void CVCeigenNonSymmetric(CVCMat src, CVCMat eigenvalues, CVCMat eigenvectors)
{
	cv::eigenNonSymmetric(CVCMatRef(src), CVCMatRef(eigenvalues), CVCMatRef(eigenvectors));
}

void CVCcalcCovarMatrix(const CVCMat samples, int nsamples, CVCMat covar, CVCMat mean, int flags, int ctype)
{
	cv::calcCovarMatrix(ConstCVCMatPtr(samples), nsamples, CVCMatRef(covar), CVCMatRef(mean), flags, ctype);
}

void CVCcalcCovarMatrix2(CVCMat samples, CVCMat covar, CVCInputOutputArray mean, int flags, int ctype)
{
	cv::calcCovarMatrix(CVCMatRef(samples), CVCMatRef(covar), CVCInputOutputArrayRef(mean), flags, ctype);
}

void CVCPCACompute1(CVCMat data, CVCInputOutputArray mean, CVCMat eigenvectors, int maxComponents)
{
	cv::PCACompute(CVCMatRef(data), CVCInputOutputArrayRef(mean), CVCMatRef(eigenvectors), maxComponents);
}

void CVCPCACompute2(CVCMat data, CVCInputOutputArray mean, CVCMat eigenvectors, CVCMat eigenvalues, int maxComponents)
{
	cv::PCACompute(CVCMatRef(data), CVCInputOutputArrayRef(mean), CVCMatRef(eigenvectors), CVCMatRef(eigenvalues), maxComponents);
}

void CVCPCACompute3(CVCMat data, CVCInputOutputArray mean, CVCMat eigenvectors, double retainedVariance)
{
	cv::PCACompute(CVCMatRef(data), CVCInputOutputArrayRef(mean), CVCMatRef(eigenvectors), retainedVariance);
}

void CVCPCACompute4(CVCMat data, CVCInputOutputArray mean, CVCMat eigenvectors, CVCMat eigenvalues, double retainedVariance)
{
	cv::PCACompute(CVCMatRef(data), CVCInputOutputArrayRef(mean), CVCMatRef(eigenvectors), CVCMatRef(eigenvalues), retainedVariance);
}
void CVCPCAProject(CVCMat data, CVCMat mean, CVCMat eigenvectors, CVCMat result)
{
	cv::PCAProject(CVCMatRef(data), CVCMatRef(mean), CVCMatRef(eigenvectors), CVCMatRef(result));
}

void CVCPCABackProject(CVCMat data, CVCMat mean, CVCMat eigenvectors, CVCMat result)
{
	cv::PCABackProject(CVCMatRef(data), CVCMatRef(mean), CVCMatRef(eigenvectors), CVCMatRef(result));
}

void CVCSVDecomp(CVCMat src, CVCMat w, CVCMat u, CVCMat vt, int flags)
{
	cv::SVDecomp(CVCMatRef(src), CVCMatRef(w), CVCMatRef(u), CVCMatRef(vt), flags);
}

void CVCSVBackSubst(CVCMat w, CVCMat u, CVCMat vt, CVCMat rhs, CVCMat dst)
{
	cv::SVBackSubst(CVCMatRef(w), CVCMatRef(u), CVCMatRef(vt), CVCMatRef(rhs), CVCMatRef(dst));
}

double CVCMahalanobis(CVCMat v1, CVCMat v2, CVCMat icovar)
{
	return cv::Mahalanobis(CVCMatRef(v1), CVCMatRef(v2), CVCMatRef(icovar));
}

void CVCdft(CVCMat src, CVCMat dst, int flags, int nonzeroRows)
{
	cv::dft(CVCMatRef(src), CVCMatRef(dst), flags, nonzeroRows);
}

void CVCidft(CVCMat src, CVCMat dst, int flags, int nonzeroRows)
{
	cv::idft(CVCMatRef(src), CVCMatRef(dst), flags, nonzeroRows);
}

void CVCdct(CVCMat src, CVCMat dst, int flags)
{
	cv::dct(CVCMatRef(src), CVCMatRef(dst), flags);
}

void CVCidct(CVCMat src, CVCMat dst, int flags)
{
	cv::idct(CVCMatRef(src), CVCMatRef(dst), flags);
}

void CVCmulSpectrums(CVCMat a, CVCMat b, CVCMat c, int flags, bool conjB)
{
	cv::mulSpectrums(CVCMatRef(a), CVCMatRef(b), CVCMatRef(c), flags, conjB);
}

int CVCgetOptimalDFTSize(int vecsize)
{
	return cv::getOptimalDFTSize(vecsize);
}
/*
RNG& CVCtheRNG()
{
}
*/
void CVCsetRNGSeed(int seed)
{
	return cv::setRNGSeed(seed);
}
/*
void CVCrandu(InputOutputArray dst, CVCMat low, CVCMat high)
{
}

void CVCrandn(InputOutputArray dst, CVCMat mean, CVCMat stddev)
{
}

void CVCrandShuffle(InputOutputArray dst, double iterFactor, RNG* rng)
{
}
*/
