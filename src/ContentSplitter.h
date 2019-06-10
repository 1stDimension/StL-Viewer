#pragma once

#include "TriangleStl.h"
#include "Leyout.h"
#include <vector>

class ContentSplitter {
    float* vertices;
    float* normals;
    uint32_t size;
public:
    explicit ContentSplitter(std::vector<TriangleStl *> *vector);

    float *getVertices() const;

    uint32_t getSize() const;

    float *getNormals() const;

};


