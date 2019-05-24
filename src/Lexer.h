#pragma once


#include <fstream>

class Lexer {
    std::ifstream* input;
    char buffer[128] = {0}; //TODO consider decreasing size of buffer
    //TODO make buffer only allocated on the heap
//    TODO Let change of ifstream after parseing
public:
    Lexer(std::ifstream* input);
    char* getNextString(); //Asks Lexer for next string of non white space characters. Should be used only in tekst mode
    float getNextFloat(); //Asks Lexer for next float. Should be used only in binary mode
    void binaryMode(); //Makes Lexer enter binary mode
};


