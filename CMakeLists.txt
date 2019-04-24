cmake_minimum_required(VERSION 3.13)
project(STL-viewer)


if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME stlViewer)
set(LIBS_DIR ${${PROJECT_NAME}_SOURCE_DIR}/libs)
set(EXECUTABLR_TESTS Test${PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

include_directories(${LIBS_DIR}/glfw/include)
include_directories( ${LIBS_DIR}/glad/include)
#include_directories( ${LIBS_DIR}/libs/glad/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(src)
add_subdirectory(libs)
#add_subdirectory(test)

target_link_libraries(${EXECUTABLE_NAME}  glfw3)
target_link_libraries(${EXECUTABLE_NAME}  glad)