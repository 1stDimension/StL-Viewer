# StL-Viewer
It is being developed on Windows 10 using MinGW, with goal of being OS and compiler independant. However it was not yet tested on any machine with different OS nor compiled using different compiler.
## Description
#### Introduction
This is a student project. I wanted like to learn graphics API like OpenGL. My supervisor tasked me with making a viewer for stl Files.
#### AtL files
According to StL format specification every surface of a 3d object is broken down into a number of triangles. Each triangle is described by 4 3-element vectors. 1st one is the normal vector of this figure, the rest are positions of the vertices. Files come in 2 forms, binary and ASCII.



## Compilation
This is project was made using [CMake][cmake]. From their project website:
 > CMake is an open-source, cross-platform family of tools designed to build, test and package software.

## Dependencies:
* [GLFW][glfw] for OS independent windows
* [Glad][glad] for modern OpenGL
* [OpenGL Mathematics][glm] for matrix calculationsx`
* [Catch2][Catch2] for tests
* [Yaml-cpp][yaml] for configuration file 

[cmake]: https://cmake.org/
[glfw]: https://www.glfw.org/
[glad]: https://glad.dav1d.de/
[glm]: https://github.com/g-truc/glm
[Catch2]: https://github.com/catchorg/Catch2
[yaml]: https://github.com/jbeder/yaml-cpp
