//
//  CVCCore.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/12/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#ifndef CVCCORE_H
#define CVCCORE_H

//CVC_EXPORT CV_NORETURN void error(const Exception& exc);

enum CVCSortFlags {
	CVC_SORT_EVERY_ROW = 0,
	CVC_SORT_EVERY_COLUMN = 1,
	CVC_SORT_ASCENDING = 0,
	CVC_SORT_DESCENDING = 16
};

enum CVCCovarFlags {
	CVC_COVAR_SCRAMBLED = 0,
	CVC_COVAR_NORMAL = 1,
	CVC_COVAR_USE_AVG = 2,
	CVC_COVAR_SCALE = 4,
	CVC_COVAR_ROWS = 8,
	CVC_COVAR_COLS = 16
};

enum CVCKmeansFlags {
	CVC_KMEANS_RANDOM_CENTERS = 0,
	CVC_KMEANS_PP_CENTERS = 2,
	CVC_KMEANS_USE_INITIAL_LABELS = 1
};

enum CVCReduceTypes {
	CVC_REDUCE_SUM = 0,
	CVC_REDUCE_AVG = 1,
	CVC_REDUCE_MAX = 2,
	CVC_REDUCE_MIN = 3
};


/** @brief Swaps two matrices */
CVC_EXPORT void CVCswap(CVCMat a, CVCMat b);
//CVC_EXPORT void CVCswap(UMat& a, UMat& b);

/** @brief Computes the source location of an extrapolated pixel. */
CVC_EXPORT int CVCborderInterpolate(int p, int len, int borderType);

/** @brief Forms a border around an image. */
//CVC_EXPORT void CVCcopyMakeBorder(CVCMat src, CVCMat dst, int top, int bottom, int left, int right, int borderType, const Scalar& value);

/** @brief Calculates the per-element sum of two arrays or an array and a scalar. */
CVC_EXPORT void CVCadd(const CVCMat src1, const CVCMat src2, CVCMat dst, const CVCMat mask, int dtype);

/** @brief Calculates the per-element difference between two arrays or array and a scalar. */
CVC_EXPORT void CVCsubtract(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask, int dtype);

/** @brief Calculates the per-element scaled product of two arrays. */
CVC_EXPORT void CVCmultiply(CVCMat src1, CVCMat src2, CVCMat dst, double scale, int dtype);

/** @brief Performs per-element division of two arrays or a scalar by an array. */
CVC_EXPORT void CVCdivide(CVCMat src1, CVCMat src2, CVCMat dst, double scale, int dtype);

//CVC_EXPORT void CVCdivide(double scale, CVCMat src2, CVCMat dst, int dtype);

/** @brief Calculates the sum of a scaled array and another array. */
CVC_EXPORT void CVCscaleAdd(CVCMat src1, double alpha, CVCMat src2, CVCMat dst);

/** @brief Calculates the weighted sum of two arrays. */
CVC_EXPORT void CVCaddWeighted(CVCMat src1, double alpha, CVCMat src2, double beta, double gamma, CVCMat dst, int dtype);

/** @brief Scales, calculates absolute values, and converts the result to 8-bit. */
CVC_EXPORT void CVCconvertScaleAbs(CVCMat src, CVCMat dst, double alpha, double beta);

/** @brief Converts an array to half precision floating number. */
CVC_EXPORT void CVCconvertFp16(CVCMat src, CVCMat dst);

/** @brief Performs a look-up table transform of an array. */
CVC_EXPORT void CVCLUT(CVCMat src, CVCMat lut, CVCMat dst);

/** @brief Calculates the sum of array elements. */
//CVC_EXPORT Scalar CVCsumElems(CVCMat src);

/** @brief Counts non-zero array elements. */
CVC_EXPORT int CVCcountNonZero(CVCMat src);

/** @brief Returns the list of locations of non-zero pixels */
CVC_EXPORT void CVCfindNonZero(CVCMat src, CVCMat idx);

/** @brief Calculates an average (mean) of array elements. */
//CVC_EXPORT Scalar CVCmean(CVCMat src, CVCMat mask);

CVC_EXPORT void CVCmeanStdDev(CVCMat src, CVCMat mean, CVCMat stddev, CVCMat mask);

/** @brief Calculates the absolute norm of an array. */
CVC_EXPORT double CVCnorm(CVCMat src1, int normType, CVCMat mask);

/** @brief Calculates an absolute difference norm or a relative difference norm. */
//CVC_EXPORT double CVCnorm(CVCMat src1, CVCMat src2, int normType, CVCMat mask);
//CVC_EXPORT double CVCnorm(const SparseMat& src, int normType);

/** @brief Computes the Peak Signal-to-Noise Ratio (PSNR) image quality metric. */
CVC_EXPORT double CVCPSNR(CVCMat src1, CVCMat src2, double R);

/** @brief naive nearest neighbor finder */
CVC_EXPORT void CVCbatchDistance(CVCMat src1, CVCMat src2, CVCMat dist, int dtype, CVCMat nidx, int normType, int K, CVCMat mask, int update, bool crosscheck);

/** @brief Normalizes the norm or value range of an array. */
//CVC_EXPORT void CVCnormalize(CVCMat src, InputOutputArray dst, double alpha, double beta, int norm_type, int dtype, CVCMat mask);

//CVC_EXPORT void CVCnormalize(const SparseMat& src, SparseMat& dst, double alpha, int normType);

/** @brief Finds the global minimum and maximum in an array. */
//CVC_EXPORT void CVCminMaxLoc(CVCMat src, double* minVal, double* maxVal, Point* minLoc, Point* maxLoc, CVCMat mask);

/** @brief Finds the global minimum and maximum in an array */
CVC_EXPORT void CVCminMaxIdx(CVCMat src, double* minVal, double* maxVal, int* minIdx, int* maxIdx, CVCMat mask);

//CVC_EXPORT void CVCminMaxLoc(const SparseMat& a, double* minVal, double* maxVal, int* minIdx, int* maxIdx);

/** @brief Reduces a matrix to a vector. */
CVC_EXPORT void CVCreduce(CVCMat src, CVCMat dst, int dim, int rtype, int dtype);

/** @brief Creates one multi-channel array out of several single-channel ones. */
CVC_EXPORT void CVCmerge1(const CVCMat mv, size_t count, CVCMat dst);

CVC_EXPORT void CVCmerge2(CVCInputArray mv, CVCMat dst);

/** @brief Divides a multi-channel array into several single-channel arrays. */
CVC_EXPORT void CVCsplit1(const CVCMat src, CVCMat mvbegin);

CVC_EXPORT void CVCsplit2(CVCMat m, CVCOutputArray mv);

/** @brief Copies specified channels from input arrays to the specified channels of */
CVC_EXPORT void CVCmixChannels1(const CVCMat src, size_t nsrcs, CVCMat dst, size_t ndsts, const int* fromTo, size_t npairs);

CVC_EXPORT void CVCmixChannels2(CVCInputArray src, CVCInputOutputArray dst, const int* fromTo, size_t npairs);

//CVC_EXPORT void CVCmixChannels(CVCInputArray src, CVCInputOutputArray dst, const std::vector<int>& fromTo);

/** @brief Extracts a single channel from src (coi is 0-based index) */
CVC_EXPORT void CVCextractChannel(CVCMat src, CVCMat dst, int coi);

/** @brief Inserts a single channel to dst (coi is 0-based index) */
CVC_EXPORT void CVCinsertChannel(CVCMat src, CVCInputOutputArray dst, int coi);

/** @brief Flips a 2D array around vertical, horizontal, or both axes. */
CVC_EXPORT void CVCflip(CVCMat src, CVCMat dst, int flipCode);

enum CVCRotateFlags {
	CVC_ROTATE_90_CLOCKWISE = 0,
	CVC_ROTATE_180 = 1,
	CVC_ROTATE_90_COUNTERCLOCKWISE = 2,
};

/** @brief Rotates a 2D array in multiples of 90 degrees. */
CVC_EXPORT void CVCrotate(CVCMat src, CVCMat dst, int rotateCode);

/** @brief Fills the output array with repeated copies of the input array. */
CVC_EXPORT void CVCrepeat(CVCMat src, int ny, int nx, CVCMat dst);

//CVC_EXPORT CVCMat CVCrepeat(const CVCMat src, int ny, int nx);

/** @brief Applies horizontal concatenation to given matrices. */
CVC_EXPORT void CVChconcat1(const CVCMat src, size_t nsrc, CVCMat dst);
CVC_EXPORT void CVChconcat2(CVCMat src1, CVCMat src2, CVCMat dst);
CVC_EXPORT void CVChconcat3(CVCInputArray src, CVCMat dst);

/** @brief Applies vertical concatenation to given matrices. */
CVC_EXPORT void CVCvconcat1(const CVCMat src, size_t nsrc, CVCMat dst);
CVC_EXPORT void CVCvconcat2(CVCMat src1, CVCMat src2, CVCMat dst);
CVC_EXPORT void CVCvconcat3(CVCInputArray src, CVCMat dst);

/** @brief computes bitwise conjunction of the two arrays (dst = src1 & src2) */
CVC_EXPORT void CVCbitwise_and(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask);

/** @brief Calculates the per-element bit-wise disjunction of two arrays or an */
CVC_EXPORT void CVCbitwise_or(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask);

/** @brief Calculates the per-element bit-wise "exclusive or" operation on two */
CVC_EXPORT void CVCbitwise_xor(CVCMat src1, CVCMat src2, CVCMat dst, CVCMat mask);

/** @brief Inverts every bit of an array. */
CVC_EXPORT void CVCbitwise_not(CVCMat src, CVCMat dst, CVCMat mask);

/** @brief Calculates the per-element absolute difference between two arrays or between an array and a scalar. */
CVC_EXPORT void CVCabsdiff(CVCMat src1, CVCMat src2, CVCMat dst);

/** @brief This is an overloaded member function, provided for convenience (python) */
CVC_EXPORT void CVCcopyTo(CVCMat src, CVCMat dst, CVCMat mask);

/** @brief Checks if array elements lie between the elements of two other arrays. */
CVC_EXPORT void CVCinRange(CVCMat src, CVCMat lowerb, CVCMat upperb, CVCMat dst);

/** @brief Performs the per-element comparison of two arrays or an array and scalar value. */
CVC_EXPORT void CVCcompare(CVCMat src1, CVCMat src2, CVCMat dst, int cmpop);

/** @brief Calculates per-element minimum of two arrays or an array and a scalar. */
CVC_EXPORT void CVCmin(CVCMat src1, CVCMat src2, CVCMat dst);
//CVC_EXPORT void CVCmin(const CVCMat src1, const CVCMat src2, CVCMat dst);
//CVC_EXPORT void CVCmin(const UMat& src1, const UMat& src2, UMat& dst);

/** @brief Calculates per-element maximum of two arrays or an array and a scalar. */
CVC_EXPORT void CVCmax(CVCMat src1, CVCMat src2, CVCMat dst);
//CVC_EXPORT void CVCmax(const CVCMat src1, const CVCMat src2, CVCMat dst);
//CVC_EXPORT void CVCmax(const UMat& src1, const UMat& src2, UMat& dst);

/** @brief Calculates a square root of array elements. */
CVC_EXPORT void CVCsqrt(CVCMat src, CVCMat dst);

/** @brief Raises every array element to a power. */
CVC_EXPORT void CVCpow(CVCMat src, double power, CVCMat dst);

/** @brief Calculates the exponent of every array element. */
CVC_EXPORT void CVCexp(CVCMat src, CVCMat dst);

/** @brief Calculates the natural logarithm of every array element. */
CVC_EXPORT void CVClog(CVCMat src, CVCMat dst);

/** @brief Calculates x and y coordinates of 2D vectors from their magnitude and angle. */
CVC_EXPORT void CVCpolarToCart(CVCMat magnitude, CVCMat angle, CVCMat x, CVCMat y, bool angleInDegrees);

/** @brief Calculates the magnitude and angle of 2D vectors. */
CVC_EXPORT void CVCcartToPolar(CVCMat x, CVCMat y, CVCMat magnitude, CVCMat angle, bool angleInDegrees);

/** @brief Calculates the rotation angle of 2D vectors. */
CVC_EXPORT void CVCphase(CVCMat x, CVCMat y, CVCMat angle, bool angleInDegrees);

/** @brief Calculates the magnitude of 2D vectors. */
CVC_EXPORT void CVCmagnitude(CVCMat x, CVCMat y, CVCMat magnitude);

/** @brief Checks every element of an input array for invalid values. */
//CVC_EXPORT bool CVCcheckRange(CVCMat a, bool quiet, Point* pos, double minVal, double maxVal);

/** @brief converts NaNs to the given number */
CVC_EXPORT void CVCpatchNaNs(CVCInputOutputArray a, double val);

/** @brief Performs generalized matrix multiplication. */
CVC_EXPORT void CVCgemm(CVCMat src1, CVCMat src2, double alpha, CVCMat src3, double beta, CVCMat dst, int flags);

/** @brief Calculates the product of a matrix and its transposition. */
CVC_EXPORT void CVCmulTransposed(CVCMat src, CVCMat dst, bool aTa, CVCMat delta, double scale, int dtype);

/** @brief Transposes a matrix. */
CVC_EXPORT void CVCtranspose(CVCMat src, CVCMat dst);

/** @brief Performs the matrix transformation of every array element. */
CVC_EXPORT void CVCtransform(CVCMat src, CVCMat dst, CVCMat m);

/** @brief Performs the perspective matrix transformation of vectors. */
CVC_EXPORT void CVCperspectiveTransform(CVCMat src, CVCMat dst, CVCMat m);

/** @brief Copies the lower or the upper half of a square matrix to its another half. */
CVC_EXPORT void CVCcompleteSymm(CVCInputOutputArray m, bool lowerToUpper);

/** @brief Initializes a scaled identity matrix. */
//CVC_EXPORT void CVCsetIdentity(InputOutputArray mtx, const Scalar& s);

/** @brief Returns the determinant of a square floating-point matrix. */
CVC_EXPORT double CVCdeterminant(CVCMat mtx);

/** @brief Returns the trace of a matrix. */
//CVC_EXPORT Scalar CVCtrace(CVCMat mtx);

/** @brief Finds the inverse or pseudo-inverse of a matrix. */
CVC_EXPORT double CVCinvert(CVCMat src, CVCMat dst, int flags);

/** @brief Solves one or more linear systems or least-squares problems. */
CVC_EXPORT bool CVCsolve(CVCMat src1, CVCMat src2, CVCMat dst, int flags);

/** @brief Sorts each row or each column of a matrix. */
CVC_EXPORT void CVCsort(CVCMat src, CVCMat dst, int flags);

/** @brief Sorts each row or each column of a matrix. */
CVC_EXPORT void CVCsortIdx(CVCMat src, CVCMat dst, int flags);

/** @brief Finds the real roots of a cubic equation. */
CVC_EXPORT int CVCsolveCubic(CVCMat coeffs, CVCMat roots);

/** @brief Finds the real or complex roots of a polynomial equation. */
CVC_EXPORT double CVCsolvePoly(CVCMat coeffs, CVCMat roots, int maxIters);

/** @brief Calculates eigenvalues and eigenvectors of a symmetric matrix. */
CVC_EXPORT bool CVCeigen(CVCMat src, CVCMat eigenvalues, CVCMat eigenvectors);

/** @brief Calculates eigenvalues and eigenvectors of a non-symmetric matrix (real eigenvalues only). */
CVC_EXPORT void CVCeigenNonSymmetric(CVCMat src, CVCMat eigenvalues, CVCMat eigenvectors);

/** @brief Calculates the covariance matrix of a set of vectors. */
CVC_EXPORT void CVCcalcCovarMatrix(const CVCMat samples, int nsamples, CVCMat covar, CVCMat mean, int flags, int ctype);

CVC_EXPORT void CVCcalcCovarMatrix2(CVCMat samples, CVCMat covar, CVCInputOutputArray mean, int flags, int ctype);

CVC_EXPORT void CVCPCACompute1(CVCMat data, CVCInputOutputArray mean, CVCMat eigenvectors, int maxComponents);

CVC_EXPORT void CVCPCACompute2(CVCMat data, CVCInputOutputArray mean, CVCMat eigenvectors, CVCMat eigenvalues, int maxComponents);

CVC_EXPORT void CVCPCACompute3(CVCMat data, CVCInputOutputArray mean, CVCMat eigenvectors, double retainedVariance);

CVC_EXPORT void CVCPCACompute4(CVCMat data, CVCInputOutputArray mean, CVCMat eigenvectors, CVCMat eigenvalues, double retainedVariance);

CVC_EXPORT void CVCPCAProject(CVCMat data, CVCMat mean, CVCMat eigenvectors, CVCMat result);

CVC_EXPORT void CVCPCABackProject(CVCMat data, CVCMat mean, CVCMat eigenvectors, CVCMat result);

CVC_EXPORT void CVCSVDecomp(CVCMat src, CVCMat w, CVCMat u, CVCMat vt, int flags);

CVC_EXPORT void CVCSVBackSubst(CVCMat w, CVCMat u, CVCMat vt, CVCMat rhs, CVCMat dst);

/** @brief Calculates the Mahalanobis distance between two vectors. */
CVC_EXPORT double CVCMahalanobis(CVCMat v1, CVCMat v2, CVCMat icovar);

/** @brief Performs a forward or inverse Discrete Fourier transform of a 1D or 2D floating-point array. */
CVC_EXPORT void CVCdft(CVCMat src, CVCMat dst, int flags, int nonzeroRows);

/** @brief Calculates the inverse Discrete Fourier Transform of a 1D or 2D array. */
CVC_EXPORT void CVCidft(CVCMat src, CVCMat dst, int flags, int nonzeroRows);

/** @brief Performs a forward or inverse discrete Cosine transform of 1D or 2D array. */
CVC_EXPORT void CVCdct(CVCMat src, CVCMat dst, int flags);

/** @brief Calculates the inverse Discrete Cosine Transform of a 1D or 2D array. */
CVC_EXPORT void CVCidct(CVCMat src, CVCMat dst, int flags);

/** @brief Performs the per-element multiplication of two Fourier spectrums. */
CVC_EXPORT void CVCmulSpectrums(CVCMat a, CVCMat b, CVCMat c, int flags, bool conjB);

/** @brief Returns the optimal DFT size for a given vector size. */
CVC_EXPORT int CVCgetOptimalDFTSize(int vecsize);

/** @brief Returns the default random number generator. */
//CVC_EXPORT RNG& CVCtheRNG();

/** @brief Sets state of default random number generator. */
CVC_EXPORT void CVCsetRNGSeed(int seed);

/** @brief Generates a single uniformly-distributed random number or an array of random numbers. */
//CVC_EXPORT void CVCrandu(InputOutputArray dst, CVCMat low, CVCMat high);

/** @brief Fills the array with normally distributed random numbers. */
//CVC_EXPORT void CVCrandn(InputOutputArray dst, CVCMat mean, CVCMat stddev);

/** @brief Shuffles the array elements randomly. */
//CVC_EXPORT void CVCrandShuffle(InputOutputArray dst, double iterFactor, RNG* rng);

#endif /* CVCCORE_H */
