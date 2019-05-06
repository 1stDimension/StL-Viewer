#include <glad/glad.h> //This is the only possible order. Otherwise OpenGL would be included twice
#include <GLFW/glfw3.h>
#include <iostream>
#include "TriangleStl.h"
#include "parserStl.h"
#include "Loader.h"
#include "ShaderHandler.h"

//TODO Check if file is an stl file If it's nor throw an exception
//TODO Write translation unit from TriangleStl to OpenGL's/ Vulkan's triangle

int main(int argc, char** argv) {
    if(argc <= 1) {
        std::cout << "Too few arguments" << std::endl;
        return 1;
    }
    std::tuple<char* , uint64_t > loadedData;
    try{
        loadedData = Loader::loadFile(argv[1]);
    }
    catch (std::exception& e){
        std::cout<< e.what()<<std::endl;
        return 2;
    }


    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    /* Use Glad for modern openGL*/
    int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    float example [6] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};
    std::cout<< example[0] <<std::endl;
    unsigned int vertices;
    glGenBuffers(1, &vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vertices);
    glBufferData(GL_ARRAY_BUFFER, 6 *sizeof(float), example, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer( 0, 2, GL_FLOAT, false, 2 * sizeof(float),  0 );

    ShaderHandler shaderHandler;
    std::tuple<char *, uint64_t > vertexShader = Loader::loadFile( "../shaders/Vertex_HelloWorld.glsl");
    shaderHandler.addShader( GL_VERTEX_SHADER, std::get<0>(vertexShader));

    std::tuple<char *, uint64_t > fragmentShader = Loader::loadFile( "../shaders/Fragment_HelloWorld.glsl");
    shaderHandler.addShader( GL_FRAGMENT_SHADER, std::get<0>(fragmentShader));
    shaderHandler.buildShader();
    glUseProgram(shaderHandler.getId());

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3); // Draw coll

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
