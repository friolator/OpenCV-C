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
void demoStitching(void);
void demoPhoto(void);

int main(int argc, const char * argv[])
{
	printf("Running...\n");

	if (argc > 1 && strcmp(argv[1], "-od") == 0) {
		demoObjectDetect();
		return 0;
	}
   else if (argc > 1 && strcmp(argv[1], "-st") == 0) {
      demoStitching();
      return 0;
   }
   else if (argc > 1 && strcmp(argv[1], "-ph") == 0) {
      demoPhoto();
      return 0;
   }

	CVCMat image = CVCimread("data/starry_night.jpeg", CVC_IMREAD_COLOR);
	if (image != NULL) {
		printf("Image loaded.\n");
	}
   else {
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
   CVCMatFree(image);
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

void demoStitching()
{
   CVCMatVector images = CVCMatVectorCreate();
   
   char path[128];
   for (int i = 1; i <= 6; i++) {
      snprintf(path, sizeof(path), "data/stitching/boat%d.jpg", i);
      CVCMatVectorPushBack(images, CVCimread(path, CVC_IMREAD_COLOR));
   }

   CVCMat pano = CVCMatCreate();
   CVCStitcher stitcher = CVCStitcherCreate(CVC_PANORAMA);
   int status = CVCStitcherStitch(stitcher, images, pano);
   if (status != CVC_OK) {
      printf("Can't stitch images, error code = %d\n", status);
   }
   else {
      // show the stitched image
      CVCimshow("Stitching", pano);
      CVCwaitKey(0);
      CVCdestroyAllWindows();
   }
   
   // cleanup
   for (int i = 0; i < CVCMatVectorSize(images); i++) {
      CVCMatFree(CVCMatVectorAt(images, i));
   }
   CVCStitcherFree(stitcher);
   CVCMatFree(pano);
   CVCMatVectorFree(images);
}

void demoPhoto()
{
	CVCMat src = CVCimread("data/starry_night.jpeg", CVC_IMREAD_COLOR);
	CVCMat dst = CVCMatCreate();
   CVCMat dst2 = CVCMatCreate();
   
   CVCimshow("Source", src);
   
   CVCedgePreservingFilter(src, dst, CVC_NORMCONV_FILTER, 60, 0.4f);
   CVCimshow("Edge Preserving Filter", dst);
   
   CVCdetailEnhance(src, dst, 10, 0.15f);
   CVCimshow("Detail Enhance", dst);
   
   CVCpencilSketch(src, dst, dst2, 10 , 0.1f, 0.03f);
   CVCimshow("Pencil Sketch", dst);
   CVCimshow("Color Pencil Sketch", dst2);
   
   CVCstylization(src, dst, 60, 0.45f);
   CVCimshow("Stylization", dst);
   
   CVCwaitKey(0);
   CVCdestroyAllWindows();

   // cleanup
   CVCMatFree(dst2);
	CVCMatFree(dst);
	CVCMatFree(src);
}
