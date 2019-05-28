#pragma once


#include <GLFW/glfw3.h>

class EventSystem {
    GLFWwindow* wwindow;
//    TODO Consider adding multi threading
//    friend void mouseButtonEvents(GLFWwindow *window, int button, int action, int mods);
//    friend void keyEvents(GLFWwindow *window, int key, int scancode, int action, int mods);
public:
    EventSystem(GLFWwindow *wwindow);

    void setup(); //TODO consider throwing exceptions or returning error codes
    void proces();

};


