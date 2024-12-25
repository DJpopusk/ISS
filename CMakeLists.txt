cmake_minimum_required(VERSION 3.12)

# Set the project name
project(SpaceControlSystem)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(include)

# Add source files
add_executable(SpaceControlSystem
        src/main.cpp
        src/spacecontrol.cpp
)

# If using C++17 and above, ensure filesystem library is linked