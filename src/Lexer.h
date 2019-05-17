#pragma once


#include <fstream>

class Lexer {
    std::ifstream* input;
    char buffer[128] = {0}; //TODO consider decreasing size of buffer
public:
    Lexer(std::ifstream* input);

public:
    char* getNext();
};


