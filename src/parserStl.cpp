#include <fstream>
#include "parserStl.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>

//TODO consider adding class for error checking
//TODO add strict error checking
//TODO check if file is of a right size


std::vector<TriangleStl> *Parser::parseFile(char input[], uint64_t size) {
    uint64_t index = 0;
    auto reference = "solid";
    bool ifText = strncmp(input, reference, strlen(reference)) == 0;
    if (ifText)
        return parseAscii(input + strlen(reference), size - strlen(reference));
    else
        return parseBin(input + 80, size - 80); //skip the 80 bytes long header
}

//TODO Create parser of ASCII files
//TODO Check if keywords are strictly correct
std::vector<TriangleStl> *Parser::parseAscii(char *input, uint64_t size) {
    auto output = new std::vector<TriangleStl>;
    uint64_t afterWhiteSpace = omitWhiteSpaces(input, size);
    input += afterWhiteSpace;
    uint64_t nameLength = shift(input, size - afterWhiteSpace);
    input += nameLength;
    afterWhiteSpace = omitWhiteSpaces(input, size);
    input += afterWhiteSpace;
    //TODO fix possible segmentation fault of strncmp it can reach out besides input + size
    //TODO Decrease the size as it goes
    while (strncmp(input, "endsolid", strlen("endsolid")) != 0) {
        //omit white spaces
        auto tuple = readTriangleAscii(input, size);
        if(tuple != nullptr) {//if there was a TriangleStl
            output->push_back(tuple->first);
            input = tuple->second;
            input += Parser::omitWhiteSpaces(input , size);
        } //TODO if three was an error while getting triangle
    }
    return output;
}

//TODO Create parser of binary files
std::vector<TriangleStl> *Parser::parseBin(char *input, uint64_t size) {
    //TODO check if size is big enough
    //TODO consider using pointer incrementation for speed up
    uint32_t numberOfFacets = 0;
    uint64_t index = 0;

    for(int i = 0; i < 3; i++){
        numberOfFacets += input[i];
        numberOfFacets = numberOfFacets << 1;
    }
    index += 4;
    size  -= 4;

    while (numberOfFacets > 0){



        //TODO Omit 2 byte attribute byte count
        numberOfFacets--;
    }


    return nullptr;
}

//TODO consider just incrementing pointer to speed up
uint64_t Parser::omitWhiteSpaces(char *input, uint64_t limit) {
    uint64_t index = 0;
    while (index < limit && (isspace((int) input[index])) != 0) {
        index++;
    }
    return index;
}

//TODO consider just incrementing pointer to speed up
uint64_t Parser::shift(char *input, uint64_t limit) {
    uint64_t index = 0;
    while (index < limit && (isspace((int) input[index])) == 0) {
        index++;
    }
    return index;
}
//TODO Add possibility of Error checking
float* Parser::readVertex(char* input, uint64_t limit, char** endPtr){
    bool ifVertex = strncmp(input, "vertex", strlen("vertex")) == 0;
    if(ifVertex){
        input += strlen("vertex");
        limit -= strlen("vertex"); //TODO fix possible underflow

        auto output = new float[3]; //TODO possible out of memory
        char *tmp;
        for(int i =0 ; i < 3; i++){
            tmp = input;
            output[i] = strtof(input, &input);
            if(tmp == input) {//error no conversion was performed
                *endPtr = tmp+1;
                return nullptr;
            }
            limit -= input - tmp;
        }
        *endPtr = input;
        return output;
    }else
        return nullptr;
}
//TODO create function that reads input and returns one triangle and pointer to after triangle
std::pair<TriangleStl, char *>* Parser::readTriangleAscii(char *input, uint64_t limit) {
    //facet normal ni nj nk
    //TODO fix possible segmentation fault
    bool ifFacetbegin = strncmp(input, "facet normal", strlen("facet normal")) == 0;
    if (ifFacetbegin) {
        input += strlen("facet normal"); //Now input point to after "facet normal"
        limit -= strlen("facet normal"); //TODO possible underflow
        float ni = strtof(input, &input);//TODO fix possible segmentation fault
        float nj = strtof(input, &input);//TODO fix possible segmentation fault
        float nk = strtof(input, &input);//TODO fix possible segmentation fault
        float facet []= { ni, nj, nk };
        uint64_t shift = Parser::omitWhiteSpaces(input, limit ); //TODO change limit to prevent segmentation fault
        input += shift;
        limit -= shift;

        bool ifOuterLoop = strncmp(input, "outer loop", strlen("outer loop")) == 0;
        if (ifOuterLoop){ //TODO
            input += strlen("outer loop"); //Now input point to after "outer loop"
            limit -= strlen("outer loop"); //TODO possible underflow
            shift = Parser::omitWhiteSpaces(input, limit ); //TODO change limit to prevent segmentation fault
            input += shift;
            limit -= shift; //TODO possible underflow
            float* vertexOne =  readVertex(input,limit,&input); //TODO
            shift = Parser::omitWhiteSpaces(input, limit ); //TODO change limit to prevent segmentation fault
            input += shift;
            limit -= shift; //TODO possible underflow
            float* vertexTwo =  readVertex(input,limit,&input);
            shift = Parser::omitWhiteSpaces(input, limit ); //TODO change limit to prevent segmentation fault
            input += shift;
            limit -= shift; //TODO possible underflow
            float* vertexTree = readVertex(input,limit,&input);

            //goto endfacet
            shift = Parser::omitWhiteSpaces(input, limit ); //TODO change limit to prevent segmentation fault
            input += shift;
            limit -= shift;
            bool ifEndloop = strncmp(input, "endloop", strlen("endloop")) == 0;
            if (ifEndloop){
                input += strlen("endloop"); //Now input point to after "endloop"
                limit -= strlen("endloop");
                shift = Parser::omitWhiteSpaces(input, limit ); //TODO change limit to prevent segmentation fault
                input += shift;
                limit -= shift;

                bool ifEndfacet = strncmp(input, "endfacet", strlen("endfacet")) == 0;
                if(ifEndfacet){
                    input += strlen("endfacet"); //Now input point to after "endfacet"
                    limit -= strlen("endfacet");
                }else
                    return nullptr;
            }else
                return nullptr;

            TriangleStl triangleStl ( facet,vertexOne, vertexTwo, vertexTree);
            return new std::pair<TriangleStl, char*>( triangleStl,input);

        } else
        return nullptr;

    } else
        return nullptr;
}
