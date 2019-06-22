#pragma once

#include "TriangleStl.h"
#include <vector>

class ContentSplitter {
    float* vertices;
    float* normals;
    uint32_t NumVertices;
    uint32_t NumNormals;
public:
    explicit ContentSplitter(std::vector<TriangleStl *> *vector);

    float *getVertices() const;

    uint32_t getNumVertices() const;

    float *getNormals() const;

    uint32_t getNumNormals() const;

    ~ContentSplitter();

};


