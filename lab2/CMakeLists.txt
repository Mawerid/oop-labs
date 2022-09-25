cmake_minimum_required(VERSION 3.16)
project(
    lab2
    VERSION 0.1
    PROJECT_DESCRIPTION "Lab 2 with variant 5"
    LANGUAGE CXX)


set(CMAKE_CPP_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

include(CTest)
add_subdirectory(src)
add_subdirectory(app)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
