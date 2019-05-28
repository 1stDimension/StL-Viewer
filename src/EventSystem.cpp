#include "EventSystem.h"
#include <GLFW/glfw3.h>
#include <iostream>

EventSystem::EventSystem(GLFWwindow *wwindow) : wwindow(wwindow) {}

void EventSystem::proces() {
    glfwPollEvents();
}

void arrowEvents(GLFWwindow *window, int key, int scancode, int action, int mods) {
//    GLFW_KEY_RIGHT    262
//    GLFW_KEY_LEFT    263
//    GLFW_KEY_DOWN    264
//    GLFW_KEY_UP     265
    if (key >= GLFW_KEY_RIGHT && key <= GLFW_KEY_UP && action == GLFW_PRESS){
        std::cout<< "\t"<< key <<std::endl;
    }
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "\t" "GLFW_MOUSE_BUTTON_LEFT + GLFW_PRESS" << std::endl;
    }
}

void shift_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if ((key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT) && (action == GLFW_PRESS))
        std::cout << "\t" "Shift" << std::endl;
}

void EventSystem::setup() {
//    keyFunctions[0]  = shift_callback;
    glfwSetKeyCallback(this->wwindow, shift_callback);
    glfwSetMouseButtonCallback(this->wwindow, mouse_button_callback);
}
