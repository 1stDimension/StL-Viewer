#pragma once

#include <tuple>

class TriangleStl {
private:
    mutable float data[12];
//  0 - 2   direction;
//  3 - 5   vertexOne;
//  6 - 8   vertexTwo;
//  9 - 11  vertexTree;
public:

    float* getDirection() const;
    float* getVertexOne() const;
    float* getVertexTwo() const;
    float* getVertexTree() const;
    float* getAll() const;

public:
    //each must contain 3 values
    TriangleStl(float* dir, float* one, float* two, float* tree);
    ~TriangleStl();

    //TODO Consider returning copy of array to encapsulate
};
