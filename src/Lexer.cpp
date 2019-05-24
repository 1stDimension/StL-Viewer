//
// Created by ʇooꓤ on 17.05.2019.
//

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Lexer.h"

//File must be open
Lexer::Lexer(std::ifstream *input) {
    this->input = input;
}

char *Lexer::getNextString() {
    if (input->is_open()) {
        if (!(input->eof())) {
            *(this->input) >>  buffer;
            char tokenLength = strlen(buffer);
            char *tmp = new char[tokenLength + 1];
            if(tokenLength == 0){
                *tmp = 0;
                return tmp;
            }
            strncpy(tmp, buffer, tokenLength + 1);
            return tmp;
            //TODO consider figuring out how to remove necessity to call delete after receiving a token
        }
    }
    return nullptr;
}

float Lexer::getNextFloat() {
    if (input->is_open()) {
        if (!(input->eof())) {
            float output;
            input->read(reinterpret_cast<char *>(&output), sizeof(output));
            std::cout << "\tgetNextFloat " << input->gcount() << std::endl; //TODO remove in release
            return output;
        }
    }//TODO rise an error
    return -13.0f;
}

void Lexer::binaryMode() {
    input->seekg(80);
}

uint32_t Lexer::getNext32int() {
    if (input->is_open()) {
        if (!(input->eof())) {
            uint32_t output;
            input->read(reinterpret_cast<char *>(&output), sizeof(output));
            std::cout << "\tgetNext32int " << input->gcount() << std::endl; //TODO remove in release
            return output;
        }
    }//TODO rise an error
    return 0;
}

uint16_t Lexer::getNext16int() {
    if (input->is_open()) {
        if (!(input->eof())) {
            uint16_t output;
            input->read(reinterpret_cast<char *>(&output), sizeof(output));
            std::cout << "\tgetNext16int " << input->gcount() << std::endl; //TODO remove in release
            return output;
        }
    }//TODO rise an error
    return 0;
}
