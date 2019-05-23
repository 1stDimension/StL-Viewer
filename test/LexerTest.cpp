#include <Lexer.h>
#include "Catch/catch.hpp"
#include <cstring>
//LEXER
TEST_CASE("Check if lexer loads part of ASCI file and returns a correct token", "[lexer][getNextString]") {
    auto pifstream = new std::ifstream("./example.stl", std::ifstream::in | std::ifstream::binary);
    auto lexer = new Lexer(pifstream);
    while (!(pifstream->eof())) {
        char *token = lexer->getNextString();
        REQUIRE(token != nullptr);
        delete token;
    }

    pifstream->close();
    delete lexer;
    delete pifstream;
}
const float reference = -13.0f;
TEST_CASE("Check if lexer loads part of Binary file and returns a correct token", "[lexer][getNextFloat]"){
    auto pifstream = new std::ifstream("./exampleBin.stl", std::ifstream::in | std::ifstream::binary);
    auto lexer = new Lexer(pifstream);
    char* tmp = new char[1];
    char* identifier = lexer->getNextString();
    REQUIRE( strcmp(identifier, "solid" ) != 0 );
    lexer->binaryMode();
    float token = reference;
    while (!(pifstream->eof())) {
        token = lexer->getNextFloat();
        REQUIRE(token != reference);
    }
    pifstream->close();
    delete identifier;
    delete lexer;
    delete pifstream;
}