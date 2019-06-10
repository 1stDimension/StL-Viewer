#pragma once


class ShaderHandler {
    uint32_t id;
    int shaders[2] = {0 , 0}; //TODO make it grow accordingly
    char c_size = 0;
public:
    ShaderHandler();
    ~ShaderHandler();
    void addShader(unsigned int type, const char * source);
    void buildShader();
    unsigned int getId() const;
    int32_t getUniformLocation(const char *name);
};


