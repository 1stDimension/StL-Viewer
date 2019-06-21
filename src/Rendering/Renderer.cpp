#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "Renderer.h"
#include "ShaderHandler.h"
#include "Loader.h"

Renderer::Renderer(ContentSplitter* contentSplitter) {
    //TODO add possibility to change perspective
    this->contentSplitter  = contentSplitter;
    this->projection = glm::ortho(left, right, bottom , top , nearer, farer);
    this->view = glm::mat4x4(1.0f);
    this->model = glm::mat4x4(1.0f);
    shaderSetUP();

    glPatchParameteri(GL_PATCH_VERTICES, 6);
    glEnable(GL_DEPTH_TEST);

//    glGenVertexArrays(1, &vao);
//    glBindVertexArray(this->vao);

    glGenBuffers( 1, &vertices);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
    glBufferData(GL_ARRAY_BUFFER,
            sizeof(float) *  3 * contentSplitter->getNumVertices()
            , contentSplitter->getVertices(), GL_STATIC_DRAW );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), 0);

    this->u_M_V_P_location =  shaderHandler.getUniformLocation("u_M_V_P");
    this->u_Colour_location = shaderHandler.getUniformLocation("u_Color");
}


void Renderer::move(float x, float y, float z) {
    this->view = glm::translate(this->view, glm::vec3(x, y, z));
}

void Renderer::rotateX(float rotation) {
    this->view = glm::rotate(this->view, glm::radians(rotation)
            , glm::vec3(1.0f, 0.0f, 0.0f));
}

void Renderer::rotateY(float rotation) {
    this->view = glm::rotate(this->view, glm::radians(rotation)
            , glm::vec3(0.0f, 1.0f, 0.0f));
}

void Renderer::rotateZ(float rotation) {
    this->view = glm::rotate(this->view, glm::radians(rotation)
            , glm::vec3(0.0f, 1.0f, 0.0f));
}

void Renderer::shaderSetUP() {
    //TODO find a batter way than hard codding
    std::tuple<char *, uint64_t> vertexShader = Loader::loadFile("../shaders/Vertex_HelloWorld.glsl");
    shaderHandler.addShader(GL_VERTEX_SHADER, std::get<0>(vertexShader));

    std::tuple<char *, uint64_t> fragmentShader = Loader::loadFile("../shaders/Fragment_HelloWorld.glsl");
    shaderHandler.addShader(GL_FRAGMENT_SHADER, std::get<0>(fragmentShader));
    shaderHandler.buildShader();
    glUseProgram(shaderHandler.getId());
}

void Renderer::resize(int width, int height) {
//    TODO add possibility to choose projection matrix type
    glViewport( 0,0, width, height);
    if (width < height && width > 0)
        projection = glm::ortho(left, right, bottom * height / width, top * height / width, nearer, farer);
    else if (width >= height && height > 0)
        projection = glm::ortho(left * width / height, right * width / height, bottom, top, nearer, farer);
    else
        projection = glm::ortho(left, right, bottom, top, nearer, farer);

}

void Renderer::rotate(float X, float Y, float Z) {
    //TODO Fix possible overhead
    this->view = glm::rotate(this->view, glm::radians(X)
            , glm::vec3(1.0f, 0.0f, 0.0f));
    this->view = glm::rotate(this->view, glm::radians(Y)
            , glm::vec3(0.0f, 1.0f, 0.0f));
    this->view = glm::rotate(this->view, glm::radians(Z)
            , glm::vec3(0.0f, 0.0f, 1.0f));
}

void Renderer::draw() {
    glm::mat4x4 mvp = this->projection * this->view * this->model;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (u_M_V_P_location != -1)
        glUniformMatrix4fv(u_M_V_P_location, 1, GL_FALSE, glm::value_ptr(mvp));
    if (u_Colour_location != -1)
        glUniform4f(u_Colour_location, 1.0f, 0.0f, 0.0f, 1.0f);
    glDrawArrays( GL_TRIANGLES,0, contentSplitter->getNumVertices() );

}

void Renderer::scaleAll(float factor) {

}
