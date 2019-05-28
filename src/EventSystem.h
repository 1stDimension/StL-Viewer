#pragma once


#include <GLFW/glfw3.h>

class EventSystem {
    GLFWwindow* wwindow;
//    TODO Consider adding multi threading
public:
    EventSystem(GLFWwindow *wwindow);

    void setup(); //TODO consider throwing exceptions or returning error codes
    void proces();

};


