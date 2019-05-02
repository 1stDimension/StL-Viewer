#include <fstream>
#include "parserStl.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>

//TODO consider adding class for error checking
//TODO add strict error checking
//TODO check if file is of a right size


std::vector<TriangleStl> *Parser::parseFile(char input[], uint64_t size) {
    auto output = new std::vector<TriangleStl>();
    uint64_t index = 0;
    auto reference = "solid";
    bool ifText = strncmp(input, reference, strlen(reference)) == 0;
    if (ifText)
        return parseAscii(input + strlen(reference), size - strlen(reference));
    else
        return parseBin(input + 80, size - 80); //skip the 80 bytes long header
}

//TODO Create parser of ASCII files
//TODO Check if keywords are strictly correct
std::vector<TriangleStl> *Parser::parseAscii(char *input, uint64_t size) {
    auto output = new std::vector<TriangleStl>;
    uint64_t afterWhiteSpace = omitWhiteSpaces(input, size);
    uint64_t nameLength = shift(input + afterWhiteSpace, size - afterWhiteSpace);
    char* trianglesStart = input + afterWhiteSpace + nameLength;
    //TODO fix possible segmentation fault of strncmp it can reach out besides input + size
    while (strncmp(trianglesStart, "endsolid", strlen("endsolid")) != 0) {
        //omit white spaces
        auto tuple = readTriangleAscii(input, size);
        if(tuple != nullptr) {//if there was a TriangleStl
            output->push_back(tuple->first);
            input = tuple->second;
        } //TODO if three was an error while getting triangle
    }
    return output;
}

//TODO Create parser of binary files
std::vector<TriangleStl> *Parser::parseBin(char *input, uint64_t size) {
    return nullptr;
}

//TODO consider just incrementing pointer to speed up
uint64_t Parser::omitWhiteSpaces(char *input, uint64_t limit) {
    uint64_t index = 0;
    while (index < limit && (isspace((int) input[index])) != 0) {
        index++;
    }
    return index;
}

//TODO consider just incrementing pointer to speed up
uint64_t Parser::shift(char *input, uint64_t limit) {
    uint64_t index = 0;
    while (index < limit && (isspace((int) input[index])) == 0) {
        index++;
    }
    return index;
}

//TODO create function that reads input and returns one triangle and pointer to after triangle
std::pair<TriangleStl, char *> *Parser::readTriangleAscii(char *input, uint64_t limit) {
    //facet normal ni nj nk
    //TODO fix possible segmentation fault
    bool ifFacetbegin = strncmp(input, "facet normal", strlen("facet normal")) == 0;
    if (ifFacetbegin) {
        input += strlen("facet normal"); //Now input point to after "facet normal"
    } else
        return nullptr;
}
