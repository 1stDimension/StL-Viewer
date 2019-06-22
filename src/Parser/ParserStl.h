#pragma once

#include "TriangleStl.h"
#include <vector>
#include <fstream>
#include "Lexer.h"

class ParserStl {
    std::ifstream* input;//external reference
    Lexer lexer;

    float* parseCordinates();

    std::vector<TriangleStl *> * parseBin();

    std::vector<TriangleStl *> * parseAscii();

public:
    ParserStl(std::ifstream* input);
    ~ParserStl();

    std::vector<TriangleStl *> * parseFile();

};
