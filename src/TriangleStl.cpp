#include <memory>
#include "TriangleStl.h"

//all pointers need to point to a 3 element array
TriangleStl::TriangleStl(float* dir, float* one, float* two, float* tree) {
    direction = std::make_tuple(dir[0], dir[1], dir[2]);
    vertexOne = std::make_tuple(one[0], one[1], one[2]);
    vertexTwo = std::make_tuple(two[0], two[1], two[2]);
    vertexTree = std::make_tuple(tree[0], tree[1], tree[2]);
}

TriangleStl::~TriangleStl() = default;

const std::tuple<float, float, float> &TriangleStl::getDirection() const {
    return direction;
}

const std::tuple<float, float, float> &TriangleStl::getVertexOne() const {
    return vertexOne;
}

const std::tuple<float, float, float> &TriangleStl::getVertexTwo() const {
    return vertexTwo;
}

const std::tuple<float, float, float> &TriangleStl::getVertexTree() const {
    return vertexTree;
}

