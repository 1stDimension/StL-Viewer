#include <cstring>
#include "ContentSplitter.h"

ContentSplitter::ContentSplitter(std::vector<TriangleStl *> *vector) {
    const char triangleSize = 12;
    const char normalsSize = 3;
    const char verticesSize = triangleSize - normalsSize;
    this->vertices = new float[vector->size() * verticesSize];
    this->normals = new float[vector->size() * normalsSize];
    this->NumVertices = vector->size() * 3;
    this->NumNormals = vector->size();
    uint32_t i = 0;
    for (auto &var : *vector) {
        memcpy(this->vertices + i * verticesSize, var->getAll() + normalsSize,
               verticesSize * sizeof(*(this->vertices)));
        memcpy(this->normals + i * normalsSize, var->getAll(),
               normalsSize * sizeof(*(this->vertices)));
        i++;
    }
}

float *ContentSplitter::getVertices() const {
    return vertices;
}

uint32_t ContentSplitter::getNumVertices() const {
    return NumVertices;
}

float *ContentSplitter::getNormals() const {
    return normals;
}

uint32_t ContentSplitter::getNumNormals() const {
    return NumNormals;
}
