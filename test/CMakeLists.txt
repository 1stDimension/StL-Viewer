cmake_minimum_required(VERSION 3.13)
project(TESTS_VIEWER)

set(EXECUTBLE_TEST runTests)
set(CMAKE_BUILD_PARALLEL_LEVEL 4)

MESSAGE(WARNING ${CMAKE_BUILD_PARALLEL_LEVEL})

include_directories(test_lib)
include_directories(../src)

include_directories(../libs/glfw/include)
include_directories( ../libs/glad/include)


link_directories(../src)
link_directories(../lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./test_bin)

set(EXECUTABLE_OUTPUT_PATH ./test_bin)

aux_source_directory(../src SOURCE)
list(REMOVE_ITEM SOURCE "../src/main.cpp")
list(REMOVE_ITEM SOURCE "../src/ShaderHandler.cpp")#TODO figure out why it doesn't work
#TODO somehow add glad to libs included in tests
#TODO consider creating a lib from files in src
aux_source_directory(. TEST_SOURCE)
add_executable(${EXECUTBLE_TEST} ${TEST_SOURCE} ${SOURCE})