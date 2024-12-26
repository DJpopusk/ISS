cmake_minimum_required(VERSION 3.10)

project(SpaceControlSimulation)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Include directories
include_directories(src)
# Find SOFA library - Adjust these to your local installation if needed

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(SpaceSimulator ${SOURCES})

# Link the SOFA library
