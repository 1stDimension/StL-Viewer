#include <fstream>
#include "Loader.h"
#include <tuple>
#include "BadFileException.h"
#include <string>
#include <cstdint>

//Loads entire file into memory as char []

std::tuple<char *, uint64_t> Loader::loadFile(const char * name) {
    std::ifstream input (name, std::ifstream::binary | std::ifstream::in);
    if(!input.is_open()) throw BadFileException();
    auto buffer = input.rdbuf();
    //Read size
    uint64_t size = buffer->pubseekoff(0,input.end, input.in);
    buffer->pubseekpos(0, input.in);
    char* loaded = new char[size];
    buffer->sgetn(loaded, size);
    input.close();
    return std::make_tuple( loaded , size);
}
