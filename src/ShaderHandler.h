#pragma once


class ShaderHandler {
    unsigned int id;
    int shaders[2] = {0 , 0}; //TODO make it grow accordingly
    char c_size = 0;
public:
    ShaderHandler();
    ~ShaderHandler();
    void addShader(unsigned int type, const char * source);
    void buildShader();
    unsigned int getId() const;
};


