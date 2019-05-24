#pragma once

#include "TriangleStl.h"
#include <vector>
#include <fstream>
#include "Lexer.h"

class Parser {
    std::ifstream* input;
    Lexer* lexer;
public:
    Parser(std::ifstream* input);

    std::vector<TriangleStl> *parseFile();

    std::vector<TriangleStl> *parseBin();

    std::vector<TriangleStl> *parseAscii();

};
