#include <memory>
#include "TriangleStl.h"

#define NUMBER_OF_COORDINATES 3

TriangleStl::TriangleStl(float* dir, float* one, float* Two, float* tree) {

     direction = new float[NUMBER_OF_COORDINATES];
     vertexOne = new float[NUMBER_OF_COORDINATES];
     vertexTwo = new float[NUMBER_OF_COORDINATES];
     vertexTree = new float[NUMBER_OF_COORDINATES];
    memcpy(direction, dir, NUMBER_OF_COORDINATES * sizeof(float));
    memcpy(vertexOne, one, NUMBER_OF_COORDINATES * sizeof(float));
    memcpy(vertexTwo, Two, NUMBER_OF_COORDINATES * sizeof(float));
    memcpy(vertexTree, tree, NUMBER_OF_COORDINATES * sizeof(float));
}

TriangleStl::~TriangleStl() {
    delete direction;
    delete vertexOne;
    delete vertexTwo;
    delete vertexTree;
}

float* TriangleStl::getDirection() const {
    return direction;
}

float* TriangleStl::getVertexOne() const {
    return vertexOne;
}

float* TriangleStl::getVertexTwo() const {
    return vertexTwo;
}

float* TriangleStl::getVertexTree() const {
    return vertexTree;
}
