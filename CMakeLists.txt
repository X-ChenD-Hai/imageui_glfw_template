cmake_minimum_required(VERSION 3.10)

project(GLlearn LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(third_party)
add_subdirectory(test)
add_subdirectory(src)