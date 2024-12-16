cmake_minimum_required(VERSION 3.1)
project(my_json_project LANGUAGES CXX)

# Find the nlohmann_json package
find_package(nlohmann_json REQUIRED)

# Create an executable from the example source file
add_executable(example main.cpp)
 
# Link the nlohmann_json library to your executable
target_link_libraries(example PRIVATE nlohmann_json::nlohmann_json)

