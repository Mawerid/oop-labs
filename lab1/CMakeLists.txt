cmake_minimum_required(VERSION 3.16)
project(lab1)

set(CMAKE_CPP_STANDARD 20)

add_library(matrix lab1.h lab1.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(lab1 main.cpp)
target_link_libraries(lab1 matrix)