enable_testing()
target_compile_features(testlib PRIVATE cxx_std_20)
add_executable(
    test
    test.cpp
)
target_link_libraries(
    test
    PRIVATE conchoid
    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test)