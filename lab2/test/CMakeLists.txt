enable_testing()
add_executable(testcon test.cpp)
include_directories(../include)

target_link_libraries(testcon GTest::gtest_main conchoid)

include(GoogleTest)
gtest_discover_tests(testcon)