# OpenCV-C
OpenCV-C is a Plain C API for Open CV 4.5+. 

The purpose of this API is to allow programming environments such as Xojo the ability to use modern
versions of OpenCV. Previously the only way to do this was with OpenCVX, which tied into the now-deprecated
OpenCV C-API, and was limited to 32bit. 

The initial release was commissioned by Gamma Ray Digital, Inc. (http://www.gammaraydigital.com) and 
has been released under the Apache 2.0 license. 

## How to Use:

### Memory Management:

* Some structures (ie. CVCMat) must be manualy allocated and deallocated with their create/free functions. (ie. CVCMatCreate, CVCMatFree). If a function *returns* a manually allocated structure, the return value must be manually deallocated.
