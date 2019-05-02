cmake_minimum_required(VERSION 3.13)
project(TESTS_VIEWER)

set(EXECUTBLE_TEST runTests)

include_directories(test_lib)
include_directories(../src)

link_directories(../src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./test_bin)

aux_source_directory(../src SOURCE)
list(REMOVE_ITEM SOURCE "../src/main.cpp")
#TODO consider creating a lib from files in src
aux_source_directory(. TEST_SOURCE)
add_executable(${EXECUTBLE_TEST} ${TEST_SOURCE} ${SOURCE})