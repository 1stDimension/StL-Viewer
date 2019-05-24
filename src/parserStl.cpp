#include <fstream>
#include "parserStl.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>

//TODO consider adding class for error checking
//TODO add strict error checking
//TODO check if file is of a right size


std::vector<TriangleStl *> * Parser::parseFile() {
    lexer = new Lexer(input);
    char *identifier = lexer->getNextString();
    auto reference = "solid";
    if (strcmp(reference, identifier) == 0)
        return parseAscii();
    else
        return parseBin(); //skip the 80 bytes long header
}

//TODO Create parser of ASCII files
//TODO Check if keywords are strictly correct
std::vector<TriangleStl *> * Parser::parseAscii() {
//    TODO consider changing initial size
    auto output = new std::vector<TriangleStl*>(20);
    return output;
}

//TODO Create parser of binary files
std::vector<TriangleStl *> *Parser::parseBin() {
    int Nfaces;
    {
        float tmp = lexer->getNextFloat();
        Nfaces = reinterpret_cast<int &>(tmp);
    }
    auto output = new std::vector<TriangleStl *>(Nfaces);

    for (uint64_t i = 0; i < Nfaces; i++) {
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
        auto triangleStl = new TriangleStl(direction, vertexOne, vertexTwo, vertexTree);
        output->push_back(triangleStl);
    }
//TODO Think what to do when there where incorectlly loaded fies
    return output;
}

Parser::Parser(std::ifstream *input) {
    this->input = input;
}
