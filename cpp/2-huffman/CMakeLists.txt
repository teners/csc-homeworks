cmake_minimum_required(VERSION 3.3)
project(huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2 -Wpedantic")

set(SOURCE_FILES main.cpp huffman.cpp huffman.hpp)
add_executable(huffman ${SOURCE_FILES})