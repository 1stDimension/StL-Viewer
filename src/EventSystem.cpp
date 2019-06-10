#include "EventSystem.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer.h"


void EventSystem::process() {
    glfwPollEvents();
}

void EventSystem::mouseButtonEvents(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "\t" "GLFW_MOUSE_BUTTON_LEFT + GLFW_PRESS" << std::endl;
    }
}

void EventSystem::keyEvents(GLFWwindow *window, int key, int scancode, int action, int mods) {
    float sensitivity = 1.0f;
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_LEFT:
            case GLFW_KEY_A:
                renderer->move(-1 * sensitivity, 0.0f, 0.0f);
                break;
            case GLFW_KEY_RIGHT:
            case GLFW_KEY_D:
                renderer->move(sensitivity, 0.0f, 0.0f);
                break;
            case GLFW_KEY_RIGHT_SHIFT:
            case GLFW_KEY_LEFT_SHIFT:
                    std::cout << "\t" "Shift" << std::endl;
                break;
            default:
                std::cout << "Key activated" << std::endl;
        }
    }
}

void EventSystem::setup() {
    glfwSetKeyCallback(this->wwindow, keyEvents);
    glfwSetMouseButtonCallback(this->wwindow, mouseButtonEvents);
    glfwSetWindowSizeCallback(this->wwindow, window_size_callback);
}

void EventSystem::window_size_callback(GLFWwindow *window, int width, int height) {
    renderer->resize(width, height);
}

EventSystem::EventSystem(GLFWwindow *wwindow) {
    this->wwindow = wwindow;
    this->setup();
}

void EventSystem::setRenderer(Renderer *renderer1) {
    renderer = renderer1;
}
