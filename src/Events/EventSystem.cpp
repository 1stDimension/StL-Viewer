#include "EventSystem.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer.h"


EventSystem::EventSystem(GLFWwindow *wwindow) {
    this->wwindow = wwindow;
    this->setup();
}

void EventSystem::setup() {
    glfwSetKeyCallback(this->wwindow, keyEvents);
    glfwSetMouseButtonCallback(this->wwindow, mouseButtonEvents);
    glfwSetWindowSizeCallback(this->wwindow, window_size_callback);
    glfwSetScrollCallback(this->wwindow, scrollEvents);
}

void EventSystem::setRenderer(Renderer *renderer1) {
    renderer = renderer1;
}

void EventSystem::process() {
    glfwPollEvents();
}

void EventSystem::scrollEvents(GLFWwindow *window, double xoffset, double yoffset) {

}

void EventSystem::mouseButtonEvents(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "\t" "GLFW_MOUSE_BUTTON_LEFT + GLFW_PRESS" << std::endl;
    }
}

void EventSystem::keyEvents(GLFWwindow *window, int key, int scancode, int action, int mods) {
    float sensitivity = 10.0f;
    float rotationSensitivity = 10; //degrees;

    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_LEFT:
            case GLFW_KEY_A:
                if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS ||
                    glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
                    renderer->rotateY(-1 * rotationSensitivity);
                else
                    renderer->move(-1 * sensitivity, 0.0f, 0.0f);
                break;
            case GLFW_KEY_UP:
            case GLFW_KEY_W:
                if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS ||
                    glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
                    renderer->move(0.0f, 0.0f, sensitivity);
                else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS ||
                         glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
                    renderer->rotateX(rotationSensitivity);
                else
                    renderer->move(0.0f, sensitivity, 0.0f);
                break;
            case GLFW_KEY_DOWN:
            case GLFW_KEY_S:
                if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS ||
                    glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
                    renderer->move(0.0f, 0.0f, -1 * sensitivity);
                else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS ||
                         glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
                    renderer->rotateX(-1 * rotationSensitivity);
                else
                    renderer->move(0.0f, -1 * sensitivity, 0.0f);
                break;
            case GLFW_KEY_RIGHT:
            case GLFW_KEY_D:
                if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS ||
                    glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
                    renderer->rotateY(rotationSensitivity);
                else
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

void EventSystem::window_size_callback(GLFWwindow *window, int width, int height) {
    renderer->resize(width, height);
}
