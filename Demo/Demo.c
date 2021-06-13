//
//  main.c
//  Demo
//
//  Created by Gerrit Goossen on 5/10/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "OpenCVC.h"

void demoObjectDetect(void);

int main(int argc, const char * argv[])
{
	printf("Running...\n");

	if (argc > 1 && strcmp(argv[1], "-od") == 0) {
		demoObjectDetect();
		return 0;
	}

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

void demoObjectDetect()
{
	CVCVideoCapture videoStream = CVCVideoCaptureCreate();

	if (!CVCVideoCaptureIsOpened(videoStream))
	{
		printf("Error: Cannot open video stream from camera\n");
		return;
	}

   CVCRectVector faces = CVCRectVectorCreate();
   CVCRectVector eyes = CVCRectVectorCreate();
   CVCCascadeClassifier faceCascade = CVCCascadeClassifierCreate();
   CVCCascadeClassifier eyeCascade = CVCCascadeClassifierCreate();
   
   // load pre-trained classifiers
   CVCCascadeClassifierLoad(faceCascade, "data/haarcascades/haarcascade_frontalface_default.xml");
   CVCCascadeClassifierLoad(eyeCascade, "data/haarcascades/haarcascade_eye.xml");
   
   // detect faces
   CVCSize size = CVCSizeCreate(0, 0);
   
	do
	{
		CVCMat frame = CVCMatCreate();
		if (CVCVideoCaptureRead(videoStream, frame))
		{
         CVCMat gray = CVCMatCreate();
         CVCcvtColor(frame, gray, CVC_COLOR_RGB2GRAY, 0);
         
         CVCCascadeClassifierDetectMultiScale(faceCascade, gray, faces, 1.1, 3, 0, size, size);
         
         for (size_t i = 0; i < CVCRectVectorSize(faces); ++i) {
            CVCRect roiRect = CVCRectVectorAt(faces, i);
            CVCMat roiGray = CVCMatRoi(gray, roiRect);
            CVCMat roiSrc = CVCMatRoi(frame, roiRect);
            CVCPoint point1 = {roiRect.x, roiRect.y};
            CVCPoint point2 = {roiRect.x + roiRect.width, roiRect.y + roiRect.height};
            CVCrectangle(frame, point1, point2, (CVCScalar){255, 0, 0, 255}, 1, CVC_LINE_8, 0);
            
            // detect eyes in face ROI
            CVCCascadeClassifierDetectMultiScale(eyeCascade, roiGray, eyes, 1.1, 3, 0, size, size);
            for (size_t j = 0; j < CVCRectVectorSize(eyes); ++j) {
               CVCRect roiRect = CVCRectVectorAt(eyes, j);
               CVCPoint point1 = {roiRect.x, roiRect.y};
               CVCPoint point2 = {roiRect.x + roiRect.width, roiRect.y + roiRect.height};
               CVCrectangle(roiSrc, point1, point2, (CVCScalar){0, 0, 255, 255}, 1, CVC_LINE_8, 0);
            }
            CVCMatFree(roiGray);
            CVCMatFree(roiSrc);
         }
			CVCimshow("Object Detection", frame);

         CVCMatFree(gray);
		}
		CVCMatFree(frame);

	} while (CVCwaitKey(30) < 0);

	CVCdestroyAllWindows();

	// cleanup
   CVCSizeFree(size);
   CVCCascadeClassifierFree(eyeCascade);
   CVCCascadeClassifierFree(faceCascade);
   CVCRectVectorFree(eyes);
   CVCRectVectorFree(faces);
	CVCVideoCaptureFree(videoStream);
}
