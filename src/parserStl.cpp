#include <fstream>
#include "parserStl.h"
#include <cstdint>
#include <cstring>
//TODO consider adding class for error checking
//TODO add strict error checking
//TODO check if file is of a right size
//TODO check if


//TODO consider just incrementing pointer to speed up
//Returns the pointer to place after the white space what ever this may be
char* Parser::omitWhiteSpaces(char * input, uint64_t size){
    uint64_t index = 0;
    int ifWhiteSpace;
    while (index < size(ifWhiteSpace = isspace((int)input[index]))){
        index++;
    }
    return input+index;
}
std::vector<TriangleStl>* Parser::parseFile(char input[], uint64_t size) {
    auto output = new std::vector<TriangleStl>();
    uint64_t  index = 0;
    auto reference = "solid";
    bool ifText = strncmp(input, reference, strlen(reference));
    if(ifText)
        return parseAscii(input + strlen(reference), size - strlen(reference));
    else
        return parseBin(input + 80, size - 80); //skip the 80 bytes long header
}
//TODO Create parser of ASCII files
//TODO Check if keywords are strictly correct
//input point's to a place after the header
std::vector<TriangleStl> *Parser::parseAscii(char *input, uint64_t size) {
    input = omitWhiteSpaces(input, size);
    return nullptr;
}
//TODO Create parser of binary files
//input point's to a place after the header
std::vector<TriangleStl> *Parser::parseBin(char *input, uint64_t size) {
    return nullptr;
}