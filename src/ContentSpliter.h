#pragma once

#include "TriangleStl.h"
#include "Leyout.h"
#include <vector>

class ContentSpliter {
    std::vector<TriangleStl*>* rawData;
    float** batchedData;
    uint32_t batchingFactor;
    Leyout* leyout;
public:
    explicit ContentSpliter(std::vector<TriangleStl *> *rawData);
    Leyout* getLeyout();
    float* getNextChunk();
    //TODO consider replacing it with template
public:

};


