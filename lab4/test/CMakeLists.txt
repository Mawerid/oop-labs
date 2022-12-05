enable_testing()
add_executable(test_game test.cpp)
include_directories(../include)

target_link_libraries(test_game GTest::gtest_main cell amoral field immortal_amoral immortal_moral immortal interface lord landscape moral school skill squad)

include(GoogleTest)
gtest_discover_tests(test_game)