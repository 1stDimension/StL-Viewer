#pragma once

#include "ContentSplitter.h"
#include <glm/mat4x4.hpp>
#include "ShaderHandler.h"

class Renderer {

    float left = -2.0f;
    float right = 2.0f;
    float bottom = -2.0f;
    float top = 2.0f;
    float nearer = -2.0f;
    float farer = 2.0f;

    float scale = 1.0f;

    unsigned int vertices;//TODO add index buffer support
    unsigned int indices;
    unsigned int vao;
    ContentSplitter* contentSplitter;

    glm::mat4x4 projection;
    glm::mat4x4 view;
    glm::mat4x4 model;

    int32_t u_M_V_P_location;
    ShaderHandler shaderHandler;

    void shaderSetUP();
public:

    Renderer(ContentSplitter* contentSplitter);

    void move(float x, float y, float z);
    void rotateX(float rotation);
    void rotateY(float rotation);
    void rotateZ(float rotation);
    void rotate( float X, float Y, float Z);
    void scaleX(float scaleX);
    void scaleY(float scaleY);
    void scaleZ(float scaleZ);
    void scaleAll(float scale);
    void resize(int width, int height);
    void draw();
//    void draw(float* data, int NumElements);
};


