#pragma once

#include <yaml-cpp/node/node.h>

enum primitiveDrawn {triangles, lines};
enum projectionType {orthographic, perspective};

class Configuration {
    YAML::Node configRoot;

    float left;
    float right;
    float bottom;
    float top;
    float near_;
    float far_;

    float sensitivity;
    primitiveDrawn primitive;
    projectionType projectionType;
    float fov;

    static bool ifFileExists(const std::string &file);

public:
    explicit Configuration(const std::string &file);
};


