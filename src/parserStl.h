#pragma once

#include "TriangleStl.h"
#include <vector>
#include <fstream>
#include "Lexer.h"

class ParserStl {
    std::ifstream* input;
    Lexer* lexer;

    void cleanUp();

    float* parseCordinates();

    std::vector<TriangleStl *> * parseBin();

    std::vector<TriangleStl *> * parseAscii();

public:
    ParserStl(std::ifstream* input);

    std::vector<TriangleStl *> * parseFile();

};
