//
//  CVCBase.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/12/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#ifndef CVCBASE_H
#define CVCBASE_H

//#include <climits>
//#include <algorithm>

/*
namespace Error {
	//! error codes
	enum Code {
		StsOk =                       0,  //!< everything is ok
		StsBackTrace =               -1,  //!< pseudo error for back trace
		StsError =                   -2,  //!< unknown /unspecified error
		StsInternal =                -3,  //!< internal error (bad state)
		StsNoMem =                   -4,  //!< insufficient memory
		StsBadArg =                  -5,  //!< function arg/param is bad
		StsBadFunc =                 -6,  //!< unsupported function
		StsNoConv =                  -7,  //!< iteration didn't converge
		StsAutoTrace =               -8,  //!< tracing
		HeaderIsNull =               -9,  //!< image header is NULL
		BadImageSize =              -10,  //!< image size is invalid
		BadOffset =                 -11,  //!< offset is invalid
		BadDataPtr =                -12,  //!<
		BadStep =                   -13,  //!< image step is wrong, this may happen for a non-continuous matrix.
		BadModelOrChSeq =           -14,  //!<
		BadNumChannels =            -15,  //!< bad number of channels, for example, some functions accept only single channel matrices.
		BadNumChannel1U =           -16,  //!<
		BadDepth =                  -17,  //!< input image depth is not supported by the function
		BadAlphaChannel =           -18,  //!<
		BadOrder =                  -19,  //!< number of dimensions is out of range
		BadOrigin =                 -20,  //!< incorrect input origin
		BadAlign =                  -21,  //!< incorrect input align
		BadCallBack =               -22,  //!<
		BadTileSize =               -23,  //!<
		BadCOI =                    -24,  //!< input COI is not supported
		BadROISize =                -25,  //!< incorrect input roi
		MaskIsTiled =               -26,  //!<
		StsNullPtr =                -27,  //!< null pointer
		StsVecLengthErr =           -28,  //!< incorrect vector length
		StsFilterStructContentErr = -29,  //!< incorrect filter structure content
		StsKernelStructContentErr = -30,  //!< incorrect transform kernel content
		StsFilterOffsetErr =        -31,  //!< incorrect filter offset value
		StsBadSize =                -201, //!< the input/output structure size is incorrect
		StsDivByZero =              -202, //!< division by zero
		StsInplaceNotSupported =    -203, //!< in-place operation is not supported
		StsObjectNotFound =         -204, //!< request can't be completed
		StsUnmatchedFormats =       -205, //!< formats of input/output arrays differ
		StsBadFlag =                -206, //!< flag is wrong or not supported
		StsBadPoint =               -207, //!< bad CvPoint
		StsBadMask =                -208, //!< bad format of mask (neither 8uC1 nor 8sC1)
		StsUnmatchedSizes =         -209, //!< sizes of input/output structures do not match
		StsUnsupportedFormat =      -210, //!< the data format/type is not supported by the function
		StsOutOfRange =             -211, //!< some of parameters are out of range
		StsParseError =             -212, //!< invalid syntax/structure of the parsed file
		StsNotImplemented =         -213, //!< the requested function/feature is not implemented
		StsBadMemBlock =            -214, //!< an allocated block has been corrupted
		StsAssert =                 -215, //!< assertion failed
		GpuNotSupported =           -216, //!< no CUDA support
		GpuApiCallError =           -217, //!< GPU API call error
		OpenGlNotSupported =        -218, //!< no OpenGL support
		OpenGlApiCallError =        -219, //!< OpenGL API call error
		OpenCLApiCallError =        -220, //!< OpenCL API call error
		OpenCLDoubleNotSupported =  -221,
		OpenCLInitError =           -222, //!< OpenCL initialization error
		OpenCLNoAMDBlasFft =        -223
	};
};
*/

enum CVCDecompTypes {
	CVC_DECOMP_LU = 0,
	CVC_DECOMP_SVD = 1,
	CVC_DECOMP_EIG = 2,
	CVC_DECOMP_CHOLESKY = 3,
	CVC_DECOMP_QR = 4,
	CVC_DECOMP_NORMAL = 16
};

enum CVCNormTypes {
	CVC_NORM_INF = 1,
	CVC_NORM_L1 = 2,
	CVC_NORM_L2 = 4,
	CVC_NORM_L2SQR = 5,
	CVC_NORM_HAMMING = 6,
	CVC_NORM_HAMMING2 = 7,
	CVC_NORM_TYPE_MASK = 7,
	CVC_NORM_RELATIVE = 8,
	CVC_NORM_MINMAX = 32
};

enum CVCCmpTypes {
	CVC_CMP_EQ = 0,
	CVC_CMP_GT = 1,
	CVC_CMP_GE = 2,
	CVC_CMP_LT = 3,
	CVC_CMP_LE = 4,
	CVC_CMP_NE = 5
};

enum CVCGemmFlags {
	CVC_GEMM_1_T = 1,
	CVC_GEMM_2_T = 2,
	CVC_GEMM_3_T = 4
};

enum CVCDftFlags {
	CVC_DFT_INVERSE = 1,
	CVC_DFT_SCALE = 2,
	CVC_DFT_ROWS = 4,
	CVC_DFT_COMPLEX_OUTPUT = 16,
	CVC_DFT_REAL_OUTPUT = 32,
	CVC_DFT_COMPLEX_INPUT = 64,
	CVC_DCT_INVERSE = CVC_DFT_INVERSE,
	CVC_DCT_ROWS = CVC_DFT_ROWS
};

enum CVCBorderTypes {
	CVC_BORDER_CONSTANT = 0,
	CVC_BORDER_REPLICATE = 1,
	CVC_BORDER_REFLECT = 2,
	CVC_BORDER_WRAP = 3,
	CVC_BORDER_REFLECT_101 = 4,
	CVC_BORDER_TRANSPARENT = 5,
	CVC_BORDER_REFLECT101 = CVC_BORDER_REFLECT_101,
	CVC_BORDER_DEFAULT = CVC_BORDER_REFLECT_101,
	CVC_BORDER_ISOLATED = 16
};

#endif /* CVCBASE_H */
