cmake_minimum_required(VERSION 3.13)
project(STL-viewer)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME stlViewer)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

find_package(OpenGL REQUIRED)

include_directories( ${${PROJECT_NAME}_SOURCE_DIR}/libs/glfw/include)
include_directories( ${${PROJECT_NAME}_SOURCE_DIR}/libs/glad/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(src)
add_subdirectory(libs)

target_link_libraries(${EXECUTABLE_NAME}  glfw3)
target_link_libraries(${EXECUTABLE_NAME}  glad)
target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_gl_LIBRARY})