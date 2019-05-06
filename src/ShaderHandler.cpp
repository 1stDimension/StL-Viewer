#include "ShaderHandler.h"
#include <glad/glad.h>
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

        int reasult;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &reasult);
        if (reasult == GL_FALSE){
            int lenght;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &lenght);
            char errorMassage[lenght];
            glGetShaderInfoLog(shaderId, lenght, &lenght, errorMassage);
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

ShaderHandler::~ShaderHandler() = default;
