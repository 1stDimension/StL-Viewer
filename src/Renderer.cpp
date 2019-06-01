#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Renderer.h"
#include "Loader.h"

Renderer::Renderer() {
    //TODO add possibility to change perspective
    projection = glm::ortho(left, right, bottom , top , nearer, farer);
    view = glm::mat4x4(1.0f);
    model = glm::mat4x4(1.0f);
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
