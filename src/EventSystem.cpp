#include "EventSystem.h"
#include <GLFW/glfw3.h>
#include <iostream>

EventSystem::EventSystem(GLFWwindow *wwindow) : wwindow(wwindow) {
    this->setup();
}

void EventSystem::proces() {
    glfwPollEvents();
}

void EventSystem::mouseButtonEvents(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "\t" "GLFW_MOUSE_BUTTON_LEFT + GLFW_PRESS" << std::endl;
    }
}

void EventSystem::keyEvents(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if ((key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT) && (action == GLFW_PRESS))
        std::cout << "\t" "Shift" << std::endl;
}

void EventSystem::setup() {
    glfwSetKeyCallback(this->wwindow, keyEvents);
    glfwSetMouseButtonCallback(this->wwindow, mouseButtonEvents);
//    glfwSetWindowSizeCallback(wwindow, window_size_callback);
}
