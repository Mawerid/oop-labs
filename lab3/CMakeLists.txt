cmake_minimum_required(VERSION 3.16)
set(CMAKE_CPP_STANDARD 20)
project(lab3)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

include(CTest)
add_subdirectory(src)
add_subdirectory(app)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()