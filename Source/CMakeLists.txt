cmake_minimum_required(VERSION 3.10)
project(OpenCVC)

# Find OpenCV4 package
find_package(OpenCV REQUIRED)

# Collect all .cpp files in this directory
file(GLOB SOURCES "*.cpp")

# Create a shared library named OpenCVC (will produce libOpenCVC.so)
add_library(OpenCVC SHARED ${SOURCES})

# Include OpenCV headers
target_include_directories(OpenCVC PRIVATE ${OpenCV_INCLUDE_DIRS})

# Link OpenCV libraries
target_link_libraries(OpenCVC PRIVATE ${OpenCV_LIBS})

# Optionally, set the output library name explicitly
set_target_properties(OpenCVC PROPERTIES OUTPUT_NAME "OpenCVC")
