#include "Catch/catch.hpp"
#include <iosfwd>
#include <Parser/ParserStl.h>
#include <iostream>

TEST_CASE("Check if ParserStl parses ASCI file and returns correct vector of Traingles", "[ParserStl][parseFile][ascii]"){
    auto pIfstream = new std::ifstream("./example.stl", std::ifstream::in | std::ifstream::binary);
    auto parser = new ParserStl(pIfstream);
    auto triangles = parser->parseFile();
    REQUIRE(triangles != nullptr);
    REQUIRE(!triangles->empty());
    std::cout << "\t" << triangles->size() <<std::endl;
}

TEST_CASE("Check if ParserStl parses bin file and returns correct vector of Traingles", "[ParserStl][parseFile][bin]"){
    auto pIfstream = new std::ifstream("./exampleBin.stl", std::ifstream::in | std::ifstream::binary);
    auto parser = new ParserStl(pIfstream);
    auto triangles = parser->parseFile();
    REQUIRE(triangles != nullptr);
    REQUIRE(!triangles->empty());
    pIfstream->close();
    delete pIfstream;
    delete parser;
    delete triangles;
}
