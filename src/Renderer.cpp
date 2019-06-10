#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Renderer.h"
#include "ShaderHandler.h"
#include "Loader.h"

Renderer::Renderer(ContentSplitter* contentSplitter) {
    //TODO add possibility to change perspective
    this->contentSplitter  = contentSplitter;
    projection = glm::ortho(left, right, bottom , top , nearer, farer);
    view = glm::mat4x4(1.0f);
    model = glm::mat4x4(1.0f);
    shaderSetUP();

    glGenVertexArrays(1, &(this->vao));
    glBindVertexArray(this->vao);

    glGenBuffers( 1, &(this->vertices));
    glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
    glBufferData(GL_ARRAY_BUFFER,
            sizeof(contentSplitter->getVertices()) * contentSplitter->getSize()
            , contentSplitter->getVertices(), GL_STATIC_DRAW );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    this->u_M_V_P_location = shaderHandler.getUniformLocation("u_M_V_P");
}

void Renderer::move(float x, float y, float z) {
    model = glm::translate(model, glm::vec3(x, y, z));
}

void Renderer::rotateX(float rotation) {
    model = glm::rotate(model, rotation, glm::vec3(1.0f, 0.0f, 0.0f));
}

void Renderer::rotateY(float rotation) {
    model = glm::rotate(model, rotation, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Renderer::rotateZ(float rotation) {
    model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
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
    if (width < height) //TODO check for posible leaks
        projection = glm::ortho(left, right, bottom * height / width, top * height / width, nearer, farer);
    else
        projection = glm::ortho(left * width / height, right * width / height, bottom, top, nearer, farer);

}

void Renderer::rotate(float X, float Y, float Z) {

}

void Renderer::draw() {
    auto mvp = this->projection * this->view * this->model;
    if (u_M_V_P_location != -1)
        glUniformMatrix4fv(u_M_V_P_location, 1, GL_FALSE, glm::value_ptr(mvp));
    glDrawArrays( GL_TRIANGLES,0, contentSplitter->getSize()/12);
}
