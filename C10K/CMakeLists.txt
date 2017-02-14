cmake_minimum_required(VERSION 2.7)
project(c10k_problem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message(STATUS "build project C10K")
include_directories(./include)
add_subdirectory(./src)

