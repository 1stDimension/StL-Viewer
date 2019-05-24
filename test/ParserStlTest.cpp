#include "Catch/catch.hpp"
#include <iosfwd>
#include <parserStl.h>

TEST_CASE("Check if ParserStl parses ASCI file and returns correct vector of Traingles", "[ParserStl][parseFile][ascii]"){
    auto ifstream = new std::ifstream("./example.stl", std::ifstream::in | std::ifstream::binary);
//    auto parser = new Parser
}

TEST_CASE("Check if ParserStl parses bin file and returns correct vector of Traingles", "[ParserStl][parseFile][bin]"){

}
