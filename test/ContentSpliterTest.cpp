#include <Catch/catch.hpp>
#include <ParserStl.h>
#include "ContentSplitter.h"

TEST_CASE("Check if data is converted correctly", "[ContentSplitter]"){
    // Code from project START
    auto pIfstream = new std::ifstream("./example.stl", std::ifstream::in | std::ifstream::binary);
    auto parser = new ParserStl(pIfstream);
    auto triangles = parser->parseFile();
    // Code from project END
    auto contentSpliter = ContentSplitter(triangles);

}