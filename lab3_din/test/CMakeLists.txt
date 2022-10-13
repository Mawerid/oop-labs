enable_testing()
add_executable(testword test.cpp)
include_directories(../include)

target_link_libraries(testword GTest::gtest_main word)

include(GoogleTest)
gtest_discover_tests(testword)