#pragma once

#include "TriangleStl.h"
#include <vector>
#include <fstream>
class Parser{
private:
    std::vector<TriangleStl>* parseBin( char input[], uint64_t  size);
    std::vector<TriangleStl>* parseAscii( char input[], uint64_t  size);
public:
    static std::vector<TriangleStl>* parseFile( char input[], uint64_t  size);

};
