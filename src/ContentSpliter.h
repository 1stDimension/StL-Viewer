#pragma once

#include "TriangleStl.h"
#include "Leyout.h"
#include <vector>

class ContentSpliter {
    float* data;
    uint32_t size;
    Leyout* leyout;
public:
    explicit ContentSpliter(std::vector<TriangleStl *> *vector);
    Leyout* getLeyout();
    float* getNextChunk();
    //TODO consider replacing it with template
public:

};


