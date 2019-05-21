//
// Created by ʇooꓤ on 17.05.2019.
//

#include <iostream>
#include <string>
#include <windows.h>
#include "Lexer.h"

//File must be open
Lexer::Lexer(std::ifstream* input){
    this->input = input;
}
char* Lexer::getNext() {
    if (input->is_open()) {
        if ( !(input->eof()) ){
        *(this->input) >> buffer;
        char tokenLength= strlen(buffer);
        char* tmp = new char[tokenLength+1];
        strncpy(tmp, buffer, tokenLength+1);

        return tmp;
        //TODO consider figuring out how to remove necessity to call delete after receiving a token
        }
    }
    return nullptr;
}