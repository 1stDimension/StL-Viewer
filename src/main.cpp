#include <glad/glad.h> //This is the only possible order. Otherwise OpenGL would be included twice
#include <GLFW/glfw3.h>
#include <iostream>
#include "TriangleStl.h"
#include "ParserStl.h"
#include "Loader.h"
#include "ShaderHandler.h"
#include "EventSystem.h"

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//TODO Check if file is an stl file If it's nor throw an exception
//TODO Write translation unit from TriangleStl to OpenGL's/ Vulkan's triangle

glm::mat4x4 projectionMatrix;// = glm::mat4x4(1.0f);
glm::mat4x4 modelViewMatrix;// = glm::mat4x4(1.0f);

GLfloat left = -2.0f;
GLfloat right = 2.0f;

GLfloat scale = 1.0f;

GLfloat rotateX = 0.52532198881;
GLfloat rotateY = 0.52532198881f;

GLfloat translateX = 0.0f;
GLfloat translateY = 0.0f;

GLfloat bottom = -2.0f;
GLfloat top = 2.0f;
GLfloat nearer = -2.0f;
GLfloat farer = 2.0f;

static void window_size_callback(GLFWwindow *window, int width, int height) {
    if (width < height)
        projectionMatrix = glm::ortho(left, right, bottom * height / width, top * height / width, nearer, farer);
    else
        projectionMatrix = glm::ortho(left * width / height, right * width / height, bottom, top, nearer, farer);
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Too few arguments" << std::endl;
        return 1;
    }
    std::tuple<char *, uint64_t> loadedData;
    try {
        loadedData = Loader::loadFile(argv[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 2;
    }

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
    /*TODO DELETE*/
    modelViewMatrix = glm::mat4x4(1.0);
    modelViewMatrix = glm::scale(modelViewMatrix, glm::vec3(scale, scale, scale));
    modelViewMatrix = glm::translate(modelViewMatrix, glm::vec3(translateX, translateY, 0.0f));

    modelViewMatrix = glm::rotate(modelViewMatrix, rotateX, glm::vec3(1.0f, 0.0f, 0.0f));
    modelViewMatrix = glm::rotate(modelViewMatrix, rotateY, glm::vec3(0.0f, 1.0f, 0.0f));
    /*TODO DELETE*/

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Use Glad for modern openGL*/
    int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    float example[] = {
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f, -1.0f, 1.0f,
            1.0f, -1.0f, 1.0f,

            1.0f, 1.0f, -1.0f,
            -1.0f, 1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f
    };

    unsigned int vertices;
    glGenBuffers(1, &vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(example), example, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    ShaderHandler shaderHandler;
    std::tuple<char *, uint64_t> vertexShader = Loader::loadFile("../shaders/Vertex_HelloWorld.glsl");
    shaderHandler.addShader(GL_VERTEX_SHADER, std::get<0>(vertexShader));

    std::tuple<char *, uint64_t> fragmentShader = Loader::loadFile("../shaders/Fragment_HelloWorld.glsl");
    shaderHandler.addShader(GL_FRAGMENT_SHADER, std::get<0>(fragmentShader));
    shaderHandler.buildShader();
    glUseProgram(shaderHandler.getId());

    int location_u_Color = glGetUniformLocation(shaderHandler.getId(), "u_Color");
    int location_u_M_V_P = glGetUniformLocation(shaderHandler.getId(), "u_M_V_P");

    float b = 0.0f;
    float slope = 0.05f;

    auto eventSystem = new EventSystem(window);
    glfwSetWindowSizeCallback(window, window_size_callback);
    eventSystem->setup();
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        if (location_u_Color != -1)
            glUniform4f(location_u_Color, 1.0f, 1.0f, b, 1.0f);
        glm::mat4x4 mvp = projectionMatrix * modelViewMatrix;
        if (location_u_M_V_P != -1)
            glUniformMatrix4fv(location_u_M_V_P, 1, GL_FALSE, glm::value_ptr(mvp));
        if (b > 1.0f)
            slope *= -1;
        else if (b < 0.0f)
            slope *= -1;

        b += slope;
//        Change to triangles
        glDrawArrays(GL_LINES, 0, 24); // Draw coll

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        eventSystem->proces();
    }


    glfwTerminate();
    return 0;
}
