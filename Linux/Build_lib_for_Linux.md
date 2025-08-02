# libOpenCVC for Linux

This project builds a shared library for the OpenCV-C project.

## Building the Library

To build the shared library, follow these steps:

1. Ensure you have CMake installed on your system.
2. Install the openCV SDK: `sudo apt-get install libopencv-dev`
3. Open a terminal and navigate to the Sources directory.
4. Issue these commands to build the lib:
   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

## Using the Library

After building, either copy the shared lib from `build/libOpenCVC.so` to `/usr/lib` or embed it directly with your built app.

## Further info

See [this Xojo forum post](https://forum.xojo.com/t/announcing-xojo-opencvc-opencv-4-5-for-xojo/70956/67?u=thomas_tempelmann) and further msgs
