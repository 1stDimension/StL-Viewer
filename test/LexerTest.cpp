#include <Lexer.h>
#include "Catch/catch.hpp"

//LEXER
TEST_CASE("Check if lexer loads part of files and returns a token", "[lexer][getNext]") {
    auto pifstream = new std::ifstream("./example.stl", std::ifstream::in | std::ifstream::binary);
    auto lexer = new Lexer(pifstream);
    while (!(pifstream->eof())) {
        char *token = lexer->getNext();
        REQUIRE(token != nullptr);
        delete token;
    }

    pifstream->close();
    delete lexer;
    delete pifstream;
}
