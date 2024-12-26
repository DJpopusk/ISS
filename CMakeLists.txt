cmake_minimum_required(VERSION 3.10)

project(ISS)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(sofa/20231011/c/include)
# Find all source files in sofa
file(GLOB SOFA_SOURCES "sofa/20231011/c/src/*.c")

# Check if we found any source files
if(NOT SOFA_SOURCES)
    message(FATAL_ERROR "No source files found in sofa/20231011/c/src")
endif()

add_library(sofa STATIC ${SOFA_SOURCES})

# Find all source files in src directory
file(GLOB PROJECT_SOURCES "src/*.cpp")

# Check if we found any source files for the ISS project
if(NOT PROJECT_SOURCES)
    message(FATAL_ERROR "No source files found in src")
endif()

# Create executable
add_executable(ISS ${PROJECT_SOURCES})

# Link the SOFA library
target_link_libraries(ISS sofa)