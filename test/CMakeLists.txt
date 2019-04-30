cmake_minimum_required(VERSION 3.13)
project(TESTS_VIEWER)

set(EXECUTBLE_TEST runTests)

include_directories(test_lib)

aux_source_directory(. TEST_SOURCE)
add_executable(${EXECUTBLE_TEST} ${TEST_SOURCE})