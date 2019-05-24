#include <fstream>
#include "parserStl.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>

//TODO consider adding class for error checking
//TODO add strict error checking
//TODO check if file is of a right size


std::vector<TriangleStl> *Parser::parseFile() {
    lexer = new Lexer(input);
    char* identifier = lexer->getNextString();
    auto reference = "solid";
    if ( strcmp(reference, identifier) == 0 )
        return parseAscii();
    else
        return parseBin(); //skip the 80 bytes long header
}

//TODO Create parser of ASCII files
//TODO Check if keywords are strictly correct
std::vector<TriangleStl> *Parser::parseAscii() {
//    TODO consider changing initial size
    auto output = new std::vector<TriangleStl>(20);
    return output;
}

//TODO Create parser of binary files
std::vector<TriangleStl> *Parser::parseBin() {
    int Nfaces;
    {
        float tmp = lexer->getNextFloat();
        Nfaces = reinterpret_cast<int&>(tmp);
    }
    auto output = new std::vector<TriangleStl*>(Nfaces);

    float* direction = new ;
    float* vertexOne;
    float* vertexTwo;
    float* vertexTree;


    TriangleStl* triangleStl = new TriangleStl(direction, vertexOne, vertexTwo, vertexTree);



    return output;
}

Parser::Parser(std::ifstream* input){
    this->input = input;
}
