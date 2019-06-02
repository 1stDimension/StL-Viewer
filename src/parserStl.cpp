#include <fstream>
#include "ParserStl.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <iostream>

//TODO consider adding class for error checking
//TODO add strict error checking
//TODO check if file is of a right size


std::vector<TriangleStl *> *ParserStl::parseFile() {
    lexer = new Lexer(input);
    char *identifier = lexer->getNextString();
    auto reference = "solid";
    if (strcmp(reference, identifier) == 0)
        return parseAscii();
    else {
        lexer->binaryMode();
        return parseBin(); //skip the 80 bytes long header
    }
}

//TODO Create parser of ASCII files
//TODO Check if keywords are strictly correct
std::vector<TriangleStl *> *ParserStl::parseAscii() {
//    TODO consider changing initial size
    auto output = new std::vector<TriangleStl *>(20);

    char *token;
    token = lexer->getNextString(); // we got name
    delete [] token;
    float* direction;
    float** vertices = new float*[3];
    while (token != nullptr) {
        token = lexer->getNextString();
        if (strcmp(token, "facet") == 0) {
            delete[] token;
            token = lexer->getNextString();
            if (strcmp(token, "normal") == 0) {
                delete[] token;
                direction = parseCordinates();
                token = lexer->getNextString();
                if (strcmp(token, "outer") == 0) {
                    delete[] token;
                    token = lexer->getNextString();
                    if (strcmp(token, "loop") == 0) {
                        delete[] token;
                        token = lexer->getNextString();
                        for (uint8_t i = 0; i < 3; i++) {
                            if (strcmp(token, "vertex") == 0) {
                                vertices[i] = parseCordinates();
                            } else {
                                delete token;
                                delete  [] direction;
                                for(uint8_t j = 0; j <=i; j++)
                                    delete vertices[j];
                                goto ending; //I KNOW IT'S BAD
                                //BUT ONLY ALTERNATIVE IS TO RISE AN EXCEPTION
                                //THIS COULD WORK IF I WOULD REPLACE RAW POINTERS TO SMART ONES
                            }
                            delete [] token;
                            token = lexer->getNextString();
                        }
                        if( strcmp(token, "endloop") == 0) {
                            delete [] token;
                            token = lexer->getNextString();
                            if (strcmp(token, "endfacet") == 0){
                                delete token;
                                output->push_back(new TriangleStl(direction, vertices[0], vertices[1], vertices[2]));
                            }
                        } else{
                            delete [] token;
                            delete  [] direction;
                            delete [] vertices[0];
                            delete [] vertices[1];
                            delete [] vertices[2];
                            break;
                        }
                    } else {
                        delete [] token;
                        delete  [] direction;
                        break;
                    }
                } else {
                    delete [] token;
                    delete  [] direction;
                    break;
                }
//TODO check if triangle is ended correctly
            } else {
                delete[] token;
                break;
            }
        }  else {
            delete [] token;
            break;
        }
    }
//    TODO check if file end with endsolid
ending:
    cleanUp();
    if(output->empty()) {
        delete output;
        return nullptr;
    }
    return output;
}

float *ParserStl::parseCordinates() {
    char * token;
    float* verteces = new float[3];
    for (uint8_t j = 0; j < 3; j++) {
        token = lexer->getNextString();
        char *end;
        verteces[j] = strtof(token, &end);
        if (end != (token + strlen(token))) {
            std::cout << "Error" << token << "Could not be converted to numer"
                      << std::endl;// rise an error
                      delete[] verteces;
            return nullptr;
        }
        delete token;
    }
    return verteces;
}

std::vector<TriangleStl *> *ParserStl::parseBin() {
    uint32_t NumberFaces = lexer->getNext32int();
    auto output = new std::vector<TriangleStl *>(NumberFaces);

    for (uint64_t i = 0; i < NumberFaces; i++) {
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

        lexer->getNext16int();

        auto triangleStl = new TriangleStl(direction, vertexOne, vertexTwo, vertexTree);
        output->push_back(triangleStl);
    }
//TODO Think what to do when there where incorrectly loaded fies
    cleanUp();
    return output;
}

ParserStl::ParserStl(std::ifstream *input) {
    this->input = input;
    lexer = nullptr;
}

void ParserStl::cleanUp() {
    delete lexer;
}
