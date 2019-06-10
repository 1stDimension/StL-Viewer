#include <glad/glad.h>
#include "ShaderHandler.h"
#include <iostream>

unsigned int ShaderHandler::getId() const {
    return id;
}

ShaderHandler::ShaderHandler() {
    this->id = glCreateProgram();
}
//TODO Error finding
void ShaderHandler::addShader(unsigned int type, const char *source) {
    if(this->c_size < 2) {
        auto shaderId = glCreateShader(type);
        glShaderSource(shaderId, 1, &source, nullptr);
        glCompileShader(shaderId);

        int result;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE){
            int length;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
            char errorMassage[length];
            glGetShaderInfoLog(shaderId, length, &length, errorMassage);
            std::cout << "***** ERROR ***** ID = "<< this->id << std::endl;
            std::cout << errorMassage << std::endl;
        }

        glAttachShader(this->id, shaderId);
        shaders[c_size] = shaderId;
        c_size++;
    }
}

void ShaderHandler::buildShader() {
    glLinkProgram(this->id);
    glValidateProgram(this->id);
}

int32_t ShaderHandler::getUniformLocation(const char *name) {
    return glGetUniformLocation(this->id, name);
}

ShaderHandler::~ShaderHandler() = default;
