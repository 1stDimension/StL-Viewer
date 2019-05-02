#pragma once

#include "TriangleStl.h"
#include <vector>
#include <fstream>
class Parser{
private:
    static char* omitWhiteSpaces(char * input, uint64_t size);
    static std::vector<TriangleStl>* parseBin( char input[], uint64_t  size);
    static std::vector<TriangleStl>* parseAscii( char input[], uint64_t  size);
public:
    static std::vector<TriangleStl>* parseFile( char input[], uint64_t  size);

};
