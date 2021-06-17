//
//  CVCImgCodecs.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/24/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#ifndef CVCIMGCODECS_H
#define CVCIMGCODECS_H

enum CVCImreadModes {
	CVC_IMREAD_UNCHANGED = -1,
	CVC_IMREAD_GRAYSCALE = 0,
	CVC_IMREAD_COLOR = 1,
	CVC_IMREAD_ANYDEPTH = 2,
	CVC_IMREAD_ANYCOLOR = 4,
	CVC_IMREAD_LOAD_GDAL = 8,
	CVC_IMREAD_REDUCED_GRAYSCALE_2 = 16,
	CVC_IMREAD_REDUCED_COLOR_2 = 17,
	CVC_IMREAD_REDUCED_GRAYSCALE_4 = 32,
	CVC_IMREAD_REDUCED_COLOR_4 = 33,
	CVC_IMREAD_REDUCED_GRAYSCALE_8 = 64,
	CVC_IMREAD_REDUCED_COLOR_8 = 65,
	CVC_IMREAD_IGNORE_ORIENTATION = 128
};

enum CVCImwriteFlags {
	CVC_IMWRITE_JPEG_QUALITY = 1,
	CVC_IMWRITE_JPEG_PROGRESSIVE = 2,
	CVC_IMWRITE_JPEG_OPTIMIZE = 3,
	CVC_IMWRITE_JPEG_RST_INTERVAL = 4,
	CVC_IMWRITE_JPEG_LUMA_QUALITY = 5,
	CVC_IMWRITE_JPEG_CHROMA_QUALITY = 6,
	CVC_IMWRITE_PNG_COMPRESSION = 16,
	CVC_IMWRITE_PNG_STRATEGY = 17,
	CVC_IMWRITE_PNG_BILEVEL = 18,
	CVC_IMWRITE_PXM_BINARY = 32,
	CVC_IMWRITE_EXR_TYPE = 48,
	CVC_IMWRITE_EXR_COMPRESSION = 49,
	CVC_IMWRITE_WEBP_QUALITY = 64,
	CVC_IMWRITE_PAM_TUPLETYPE = 128,
	CVC_IMWRITE_TIFF_RESUNIT = 256,
	CVC_IMWRITE_TIFF_XDPI = 257,
	CVC_IMWRITE_TIFF_YDPI = 258,
	CVC_IMWRITE_TIFF_COMPRESSION = 259,
	CVC_IMWRITE_JPEG2000_COMPRESSION_X1000 = 272
};

enum CVCImwriteEXRTypeFlags {
	CVC_IMWRITE_EXR_TYPE_HALF = 1,
	CVC_IMWRITE_EXR_TYPE_FLOAT = 2
};

enum CVCImwriteEXRCompressionFlags {
	CVC_IMWRITE_EXR_COMPRESSION_NO = 0,
	CVC_IMWRITE_EXR_COMPRESSION_RLE = 1,
	CVC_IMWRITE_EXR_COMPRESSION_ZIPS = 2,
	CVC_IMWRITE_EXR_COMPRESSION_ZIP = 3,
	CVC_IMWRITE_EXR_COMPRESSION_PIZ = 4,
	CVC_IMWRITE_EXR_COMPRESSION_PXR24 = 5,
	CVC_IMWRITE_EXR_COMPRESSION_B44 = 6,
	CVC_IMWRITE_EXR_COMPRESSION_B44A = 7,
	CVC_IMWRITE_EXR_COMPRESSION_DWAA = 8,
	CVC_IMWRITE_EXR_COMPRESSION_DWAB = 9,
};

enum CVCImwritePNGFlags {
	CVC_IMWRITE_PNG_STRATEGY_DEFAULT = 0,
	CVC_IMWRITE_PNG_STRATEGY_FILTERED = 1,
	CVC_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY = 2,
	CVC_IMWRITE_PNG_STRATEGY_RLE = 3,
	CVC_IMWRITE_PNG_STRATEGY_FIXED = 4
};

enum CVCImwritePAMFlags {
	CVC_IMWRITE_PAM_FORMAT_NULL = 0,
	CVC_IMWRITE_PAM_FORMAT_BLACKANDWHITE = 1,
	CVC_IMWRITE_PAM_FORMAT_GRAYSCALE = 2,
	CVC_IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA = 3,
	CVC_IMWRITE_PAM_FORMAT_RGB = 4,
	CVC_IMWRITE_PAM_FORMAT_RGB_ALPHA = 5,
};

/** @brief Loads an image from a file. */
CVC_EXPORT CVCMat CVCimread(const char* filename, int flags);

/** @brief Loads a multi-page image from a file. */
//CVC_EXPORT bool CVCimreadmulti(const char* filename, std::vector<Mat>& mats, int flags);

/** @brief Saves an image to a specified file. */
CVC_EXPORT bool CVCimwrite(const char* filename, CVCMat img, const int* params, int paramCount);

/** @overload multi-image overload for bindings */
//CVC_EXPORT bool CVCimwritemulti(const char *filename, InputArrayOfArrays img, const std::vector<int>& params = std::vector<int>())

/** @brief Reads an image from a buffer in memory. */
CVC_EXPORT CVCMat CVCimdecode(CVCUCharVector buf, int flags);

//CVC_EXPORT CVCMat CVCimdecode(CVCMat buf, int flags, CVCMat dst);

/** @brief Encodes an image into a memory buffer. */
CVC_EXPORT bool CVCimencode(const char* ext, CVCMat img, CVCUCharVector buf, CVCIntVector params);

/** @brief Returns true if the specified image can be decoded by OpenCV */
CVC_EXPORT bool CVChaveImageReader(const char* filename);

/** @brief Returns true if an image with the specified filename can be encoded by OpenCV */
CVC_EXPORT bool CVChaveImageWriter(const char* filename);

#endif /* CVCIMGCODECS_H */
