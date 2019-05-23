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
            *(this->input) >> std::setw(80) >> buffer;
            std::cout << "\tgetNextString" << input->gcount();
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
            std::cout << "\tgetNextFloat" << input->gcount();
            return output;
        }
    }//TODO rise an error
    return -13.0f;
}

void Lexer::binaryMode() {
    int read = input->gcount();
    if (read >= 80)
        return; //TODO rise an error
    input->ignore(80 - read);
}
