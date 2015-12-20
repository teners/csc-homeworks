cmake_minimum_required(VERSION 3.3)
project(lp1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wpedantic -Wextra")

set(SOURCE_FILES main.cpp linked_ptr.hpp)
add_executable(lp1 ${SOURCE_FILES})