#include <fstream>
#include "parserStl.h"
#include <cstdint>

std::vector<TriangleStl> Parser::parseFile(char input[], uint64_t size) {
    auto output = new std::vector<TriangleStl>();
//TODO read first 5 bytes as char check if they are equal to solid if they are this is a ascii type stl
//  Other wise it's binary and omit first 80 bytes


    return output;
}
//TODO Create parser of binary files
//TODO Create parser of ASCII files