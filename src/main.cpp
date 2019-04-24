#include <glad/glad.h> //This is the only possible order. Otherwise OpenGL would be included twice
#include <GLFW/glfw3.h>
#include <iostream>
#include "TriangleStl.h"

int main(int argc, char** argv) {
    //check if there is 1 argument
    //check file extension is correct
    //load file
    auto a = new float[3];
    auto b = new float[3];
    auto c = new float[3];
    auto d = new float[3];
    auto t = new TriangleStl(a, b, c, d);
    delete t;
    return 0;
}
//
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//    /* Use Glad for modern openGL*/
//    int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}
