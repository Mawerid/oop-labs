enable_testing()
add_executable(test_game test.cpp)
include_directories(../include)

target_link_libraries(test_game GTest::gtest_main kdtree cell common field immortal lord landscape school skill squad)

include(GoogleTest)
gtest_discover_tests(test_game)