cmake_minimum_required(VERSION 3.3)
project(linked_ptr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

set(SOURCE_FILES linked_ptr_gen_smoke_test.cpp linked_ptr.hpp)
add_executable(linked_ptr ${SOURCE_FILES})
