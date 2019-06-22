#pragma once

#include "ContentSplitter.h"
#include <glm/mat4x4.hpp>
#include "ShaderHandler.h"

class Renderer {
private:
        float left = -10.0f;
        float right = 10.0f;
        float bottom = -10.0f;
        float top = 10.0f;
        float nearer = -10.0f;
        float farer = 10.0f;

        float scale = 1.0f;

    unsigned int vertices;//TODO add index buffer support
    unsigned int normals;
    unsigned int indices;
    unsigned int vao;
    ContentSplitter* contentSplitter;

    glm::mat4x4 projection;
    glm::mat4x4 view;
    glm::mat4x4 model;

    int32_t u_M_location;
    int32_t u_V_location;
    int32_t u_P_location;
    int32_t u_Colour_location;

    ShaderHandler shaderHandler;
    void shaderSetUP();
public:

    explicit Renderer(ContentSplitter* contentSplitter);

    void move(float x, float y, float z);
    void rotateX(float rotation);
    void rotateY(float rotation);
    void rotateZ(float rotation);
    void rotate( float X, float Y, float Z);
    void scaleX(float scaleX);
    void scaleY(float scaleY);
    void scaleZ(float scaleZ);
    void scaleAll(float factor);
    void resize(int width, int height);
    void draw();
};


