#pragma once

#include "TriangleStl.h"
#include <vector>
#include <fstream>
class Parser{
public:
    static std::vector<TriangleStl>* parseFile( char input[], uint64_t  size);

};
