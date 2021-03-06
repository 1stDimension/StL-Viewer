#pragma once

#include <GLFW/glfw3.h>
#include "Renderer.h"

class EventSystem {
    inline static Renderer* renderer;
    GLFWwindow* wwindow;
//TODO
    static void keyEvents(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouseButtonEvents(GLFWwindow *window, int button, int action, int mods);
    static void window_size_callback(GLFWwindow *window, int width, int height);
    static void scrollEvents(GLFWwindow* window, double xoffset, double yoffset);
//    TODO Consider adding multi threading
    void setup(); //TODO consider throwing exceptions or returning error codes
public:
    static void setRenderer(Renderer* renderer1);
    explicit EventSystem(GLFWwindow *wwindow);
    void process();
};


