#include <fstream>
#include "parserStl.h"
#include <cstdint>
#include <cstring>
//TODO consider adding class for error checking
//TODO add strict error checking
//TODO check if file is of a right size


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
std::vector<TriangleStl> *Parser::parseAscii(char *input, uint64_t size) {
    uint64_t afterWhiteSpace = omitWhiteSpaces(input, size);



    return nullptr;
}
//TODO Create parser of binary files
std::vector<TriangleStl> *Parser::parseBin(char *input, uint64_t size) {
    return nullptr;
}
//TODO consider just incrementing pointer to speed up
uint64_t Parser::omitWhiteSpaces(char * input, uint64_t limit){
    uint64_t index = 0;
    while (index < limit && (isspace((int)input[index])) != 0 ){
        index++;
    }
    return index;
}
//TODO consider just incrementing pointer to speed up
uint64_t Parser::shift(char *input, uint64_t limit) {
    uint64_t index = 0;
    while (index < limit && (isspace((int)input[index])) == 0 ){
        index++;
    }
    return index;
}
