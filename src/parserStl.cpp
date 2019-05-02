#include <fstream>
#include "parserStl.h"
#include <cstdint>
#include <cstring>

std::vector<TriangleStl>* Parser::parseFile(char input[], uint64_t size) {
    auto output = new std::vector<TriangleStl>();
//TODO read first 5 bytes as char check if they are equal to solid if they are this is a ascii type stl
//  Other wise it's binary and omit first 80 bytes
    uint64_t  index = 0;
    auto reference = "solid";
    bool iftext = strncmp(input, reference, strlen(reference));

    if(iftext)
        else


    return output;
}

std::vector<TriangleStl> *Parser::parseAscii(char *input, uint64_t size) {
    return nullptr;
}

std::vector<TriangleStl> *Parser::parseBin(char *input, uint64_t size) {
    return nullptr;
}

//TODO Create parser of binary files
//TODO Create parser of ASCII files