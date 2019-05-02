#pragma once

#include "TriangleStl.h"
#include <vector>
#include <fstream>
class Parser{
private:
    //Return TriangleStl read from input and pointer to space after triangle
    static std::pair<TriangleStl, char*>* readTriangleAscii(char* input, uint64_t limit);
    //Returns length of data stream ahead
    static uint64_t shift(char *input, uint64_t limit);
    //Returns offset to place after the white space what ever this may be
    //limit indicates how many bytes can be omitted at max
    static uint64_t omitWhiteSpaces(char * input, uint64_t limit);
    //input point's to a place after the header
    static std::vector<TriangleStl>* parseBin( char input[], uint64_t  size);
    //input point's to a place after the header
    static std::vector<TriangleStl>* parseAscii( char input[], uint64_t  size);
public:
    static std::vector<TriangleStl>* parseFile( char input[], uint64_t  size);

};
