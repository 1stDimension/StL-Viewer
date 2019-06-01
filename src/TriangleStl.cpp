#include <memory>
#include "TriangleStl.h"

//all pointers need to point to a 3 element array
TriangleStl::TriangleStl(float* dir, float* one, float* two, float* tree) {
    memcpy(data    , dir,  3 * sizeof(*dir));
    memcpy(data + 3, one,  3 * sizeof(*one));
    memcpy(data + 6, two,  3 * sizeof(*two));
    memcpy(data + 9, tree, 3 * sizeof(*tree));
}

TriangleStl::~TriangleStl() = default;

float* TriangleStl::getDirection() const {
    auto result = new float[3];
    memcpy(result, data, 3);
    return result;
}
float* TriangleStl::getVertexOne() const {
    auto result = new float[3];
    memcpy(result, data + 3, 3);
    return result;
}
float* TriangleStl::getVertexTwo() const {
    auto result = new float[3];
    memcpy(result, data + 6, 3);
    return result;
}
float* TriangleStl::getVertexTree() const {
    auto result = new float[3];
    memcpy(result, data + 9, 3);
    return result;
}

float* TriangleStl::getAll() const {
    return data;
}

