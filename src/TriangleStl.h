#pragma once

#include <tuple>

class TriangleStl {
private:
    std::tuple<float, float, float> direction;
    std::tuple<float, float, float> vertexOne;
    std::tuple<float, float, float> vertexTwo;
    std::tuple<float, float, float> vertexTree;
public:
    const std::tuple<float, float, float> &getDirection() const;
    const std::tuple<float, float, float> &getVertexOne() const;
    const std::tuple<float, float, float> &getVertexTwo() const;
    const std::tuple<float, float, float> &getVertexTree() const;

public:
    //each must contain 3 values
    TriangleStl(float* dir, float* one, float* two, float* tree);
    ~TriangleStl();

    //TODO Consider returning copy of array to encapsulate
};
