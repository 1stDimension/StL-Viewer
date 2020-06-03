# StL-Viewer

## Description

### Introduction
This is a student project. I wanted like to learn graphics API like ***OpenGL***. My supervisor tasked me with making a viewer for StL Files.

### Side note

It is being developed on ***Windows 10*** using ***MinGW 8.1.0***, with goal of being OS and compiler independent. However it was not yet tested on any machine with different OS nor compiled using different compiler.

### StL files
According to StL format specification every surface of a 3d object is broken down into a number of triangles. Each triangle is described by 4 3-element vectors. 1st one is the normal vector of this figure, the rest are positions of the vertices. Files come in 2 forms, binary and ASCII. More on that can be found [here][stl].

### Compilation
This is project was made using [CMake][cmake], therefore it is essential to install it. What is [CMake][cmake]? From their project website:
 > CMake is an open-source, cross-platform family of tools designed to build, test and package software.
 
First clone this repository to a folder using git then run command

    cmake folder

Where _folder_ is path to root folder of project. [CMake][cmake] will then generate all files needed to build StL-Viewer on your system. In case of Linux it will be Makefiles and so on and so forth.

## Requirements
* CMake 3.13 or newer
* C++ compiler supporting C++17
* Graphics card supporting OpenGL 3.3
 
## Dependencies:

All of listed below are used as gitsubmodules in the libs directory. Because by default git doesn't download submodules you will need to use 

    git submodule update --init --recursive
 
 If it's your first time checkout a repo. With that said dependencies are as follows:
 
* [GLFW][glfw] for OS independent windows
* [Glad][glad] for modern OpenGL
* [OpenGL Mathematics][glm] for matrix calculations`
* [Catch2][Catch2] for tests
* [Yaml-cpp][yaml] for configuration file 

[stl]: https://www.fabbers.com/tech/STL_Format#Sct_specs
[cmake]: https://cmake.org/
[glfw]: https://www.glfw.org/
[glad]: https://glad.dav1d.de/
[glm]: https://github.com/g-truc/glm
[Catch2]: https://github.com/catchorg/Catch2
[yaml]: https://github.com/jbeder/yaml-cpp
