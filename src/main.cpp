#include <glad/glad.h> //This is the only possible order. Otherwise OpenGL would be included twice
#include <GLFW/glfw3.h>
#include <iostream>
#include "TriangleStl.h"
#include "ParserStl.h"
#include "EventSystem.h"
#include "Renderer.h"
#include "ContentSplitter.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <yaml-cpp/yaml.h>

//TODO Check if file is an stl file If it's nor throw an exception
int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Too few arguments" << std::endl;
        return 1;
    }

    YAML::Node config = YAML::LoadFile("config.yaml");
    std::cout << "Last logged in: " << config["lastLogin"]<<std::endl;

    auto dataInput = new std::ifstream(argv[1], std::ifstream::in | std::ifstream::binary);
    auto parser = new ParserStl(dataInput);
    auto triangles = parser->parseFile();
    auto contentSplitter = new ContentSplitter(triangles);
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(600, 600, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Use Glad for modern openGL*/
    int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    auto renderer = new Renderer(contentSplitter);

    EventSystem::setRenderer(renderer);
    auto eventSystem = new EventSystem(window);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

       /* Swap front and back buffers */

        renderer->draw();
        eventSystem->process();

        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
