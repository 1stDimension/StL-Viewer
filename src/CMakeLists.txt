file(GLOB_RECURSE SOURCE *.cpp)

include_directories( ./Parser)
include_directories( ./Events)
include_directories( ./Rendering)
include_directories( ./Config)

add_executable(${EXECUTABLE_NAME} ${SOURCE})