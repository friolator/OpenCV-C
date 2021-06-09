//
//  main.c
//  Demo
//
//  Created by Gerrit Goossen on 5/10/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#include <stdio.h>
#include "OpenCVC.h"

int main(int argc, const char * argv[])
{
	printf("Running...\n");

	CVCMat image = CVCimread("Test-Pattern.tif", CVC_IMREAD_COLOR);
	if (image != NULL) {
		printf("Image loaded.\n");
		CVCMatFree(image);
	} else {
		printf("Error loading image.\n");
		return 0;
	}

	// resize the image
	double scale = 0.125;
	CVCMat smaller = CVCMatCreate();
	int width = (int)((double)CVCMatWidth(image) * scale);
	int height = (int)((double)CVCMatHeight(image) * scale);
   CVCSize scaledSize = CVCSizeCreate(width, height);
	CVCresize(image, smaller, scaledSize, 0.0, 0.0, CVC_INTER_AREA);

	// convert to grayscale
	CVCMat gray = CVCMatCreate();
	CVCcvtColor(smaller, gray, CVC_COLOR_RGB2GRAY, 0);

	// apply gaussian blur
	CVCMat blur = CVCMatCreate();
	CVCSize blurSize = CVCSizeCreate(0, 0);
	CVCGaussianBlur(gray, blur, blurSize, 3.0, 3.0, CVC_BORDER_DEFAULT);

	// apply edge detection
	CVCMat canny = CVCMatCreate();
	CVCCanny(blur, canny, 125.0, 175.0, 3, false);

	// show the image
	CVCimshow("canny", blur);
	CVCwaitKey(0);
	CVCdestroyAllWindows();

	// cleanup
	CVCSizeFree(scaledSize);
	CVCSizeFree(blurSize);
	CVCMatFree(smaller);
	CVCMatFree(gray);
	CVCMatFree(blur);
	CVCMatFree(canny);

	printf("Finished.\n");

	return 0;
}
