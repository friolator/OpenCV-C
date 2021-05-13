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

	CVCMat image = CVCimread("Test-Pattern.tif");
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
	int scaledWidth = (int)((double)CVCMatWidth(image) * scale);
	int scaledHeight = (int)((double)CVCMatHeight(image) * scale);
	CVCresize(image, smaller, scaledWidth, scaledHeight); // cv::INTER_AREA);

	// convert to grayscale
	CVCMat gray = CVCMatCreate();
	CVCcvtColor(smaller, gray); // cv::COLOR_RGB2GRAY);

	// apply gaussian blur
	CVCMat blur = CVCMatCreate();
	CVCGaussianBlur(gray, blur, 3.0, 3.0);

	// apply edge detection
	CVCMat canny = CVCMatCreate();
	CVCCanny(blur, canny, 125.0, 175.0);

	// show the image
	CVCimshow("canny", blur);
	CVCwaitKey(0);
	CVCdestroyAllWindows();

	// cleanup
	CVCMatFree(smaller);
	CVCMatFree(gray);
	CVCMatFree(blur);
	CVCMatFree(canny);

	printf("Finished.\n");

	return 0;
}
