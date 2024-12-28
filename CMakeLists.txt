cmake_minimum_required(VERSION 3.10)

project(ISS)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
add_subdirectory(sgp4)
include_directories(sgp4/libsgp4)
include_directories(sofa/20231011/c/src)
# Find all source files in sofa
file(GLOB SOFA_SOURCES "sofa/20231011/c/src/*.c")
file(GLOB SOFA_INKS "sofa/20231011/c/src/*.h")

file(GLOB SGP4_SOURCES "sgp4/libsgp4/*.cc" )
file(GLOB SGP4_INKS "sgp4/libsgp4/*.h")

if(NOT SOFA_SOURCES)
    message(FATAL_ERROR "No source files found in sofa")
endif()
if(NOT SGP4_SOURCES)
    message(FATAL_ERROR "No source files found in sgp4")
endif()

add_library(sofa STATIC ${SOFA_SOURCES} ${SOFA_INKS})
# Find all source files in src directory

file(GLOB PROJECT_SOURCES "src/*.cpp" "src/*.h")

# Check if we found any source files for the ISS project
if(NOT PROJECT_SOURCES)
    message(FATAL_ERROR "No source files found in src")
endif()

# Create executable
add_executable(ISS ${PROJECT_SOURCES})

# Link the SOFA library
target_link_libraries(ISS sofa sgp4)