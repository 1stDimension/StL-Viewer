#include <fstream>
#include "ParserStl.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>

//TODO consider adding class for error checking
//TODO add strict error checking
//TODO check if file is of a right size


std::vector<TriangleStl *> * ParserStl::parseFile() {
    lexer = new Lexer(input);
    char *identifier = lexer->getNextString();
    auto reference = "solid";
    if (strcmp(reference, identifier) == 0)
        return parseAscii();
    else {
        lexer->binaryMode();
        return parseBin(); //skip the 80 bytes long header
    }
}

//TODO Create parser of ASCII files
//TODO Check if keywords are strictly correct
std::vector<TriangleStl *> * ParserStl::parseAscii() {
//    TODO consider changing initial size
    auto output = new std::vector<TriangleStl*>(20);
    return output;
}

//TODO Create parser of binary files
std::vector<TriangleStl *> *ParserStl::parseBin() {
    uint32_t NumberFaces = lexer->getNext32int();
    auto output = new std::vector<TriangleStl *>(NumberFaces);

    for (uint64_t i = 0; i < NumberFaces; i++) {
        auto direction = new float[3];
        auto vertexOne = new float[3];
        auto vertexTwo = new float[3];
        auto vertexTree = new float[3];


        direction[0] = lexer->getNextFloat();
        direction[1] = lexer->getNextFloat();
        direction[2] = lexer->getNextFloat();

        vertexOne[0] = lexer->getNextFloat();
        vertexOne[1] = lexer->getNextFloat();
        vertexOne[2] = lexer->getNextFloat();

        vertexTwo[0] = lexer->getNextFloat();
        vertexTwo[1] = lexer->getNextFloat();
        vertexTwo[2] = lexer->getNextFloat();

        vertexTree[0] = lexer->getNextFloat();
        vertexTree[1] = lexer->getNextFloat();
        vertexTree[2] = lexer->getNextFloat();

        lexer->getNext16int();

        auto triangleStl = new TriangleStl(direction, vertexOne, vertexTwo, vertexTree);
        output->push_back(triangleStl);
    }
//TODO Think what to do when there where incorrectly loaded fies
    delete lexer;
    return output;
}

ParserStl::ParserStl(std::ifstream *input) {
    this->input = input;
    lexer = nullptr;
}
