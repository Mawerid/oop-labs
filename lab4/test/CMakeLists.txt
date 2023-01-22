enable_testing()
add_executable(test_game test.cpp)
include_directories(../include)

target_link_libraries(test_game GTest::gtest_main kdtree landscape cell immortal lord common school skill squad unit)

include(GoogleTest)
gtest_discover_tests(test_game)