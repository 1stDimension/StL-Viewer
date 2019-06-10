#pragma once


#include <GLFW/glfw3.h>

class EventSystem {
    GLFWwindow* wwindow;
//TODO
    static void keyEvents(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouseButtonEvents(GLFWwindow *window, int button, int action, int mods);
    static void window_size_callback(GLFWwindow *window, int width, int height);
//    TODO Consider adding multi threading
    void setup(); //TODO consider throwing exceptions or returning error codes
public:

    explicit EventSystem(GLFWwindow *wwindow);
    void proces();
};


