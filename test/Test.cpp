#include "Catch/catch.hpp"
#include <cstring>
#include "parserStl.h"
#include "TriangleStl.h"
#include "Loader.h"
#include "Lexer.h"
#include <string>
#include <iostream>

char *referenceVertex = "vertex 0.0 0.0 0.0\n";

char *referenceTriangle = "facet normal 0.0 -1.0 0.0\n"
                          "            outer loop\n"
                          "              vertex 0.0 0.0 0.0\n"
                          "              vertex 1.0 0.0 0.0\n"
                          "              vertex 0.0 0.0 1.0\n"
                          "            endloop\n"
                          "          endfacet\n";

char *referenceFile = "solid cube_corner\n"
                      "          facet normal 0.0 -1.0 0.0\n"
                      "            outer loop\n"
                      "              vertex 0.0 0.0 0.0\n"
                      "              vertex 1.0 0.0 0.0\n"
                      "              vertex 0.0 0.0 1.0\n"
                      "            endloop\n"
                      "          endfacet\n"
                      "          facet normal 0.0 0.0 -1.0\n"
                      "            outer loop\n"
                      "              vertex 0.0 0.0 0.0\n"
                      "              vertex 0.0 1.0 0.0\n"
                      "              vertex 1.0 0.0 0.0\n"
                      "            endloop\n"
                      "          endfacet\n"
                      "          facet normal -1.0 0.0 0.0\n"
                      "            outer loop\n"
                      "              vertex 0.0 0.0 0.0\n"
                      "              vertex 0.0 0.0 1.0\n"
                      "              vertex 0.0 1.0 0.0\n"
                      "            endloop\n"
                      "          endfacet\n"
                      "          facet normal 0.577 0.577 0.577\n"
                      "            outer loop\n"
                      "              vertex 1.0 0.0 0.0\n"
                      "              vertex 0.0 1.0 0.0\n"
                      "              vertex 0.0 0.0 1.0\n"
                      "            endloop\n"
                      "          endfacet\n"
                      "endsolid";
//Parser:
//TODO Parser::parseFile
TEST_CASE("Parser::parseFile ascii PC", "[parser][full][ascii]") {
auto tested = Parser::parseFile(referenceFile, strlen(referenceFile));
REQUIRE(tested != nullptr);
REQUIRE(!tested->empty());
REQUIRE(tested->size() == 4);
//    TODO make precise tests
}
//TODO mock somehow binary file in order not to use project's created classes
TEST_CASE("Parser::parseFile bin PC", "[parser][full][bin]") {
std::tuple<char *, uint64_t> reference = Loader::loadFile(
        "exampleBin.stl");
std::vector<TriangleStl> *tested = Parser::parseFile(std::get<0>(reference), std::get<1>(reference));
REQUIRE(tested != nullptr);
REQUIRE(!tested->empty());
REQUIRE(tested->size() == 4);
//    TODO make precise tests compering triangles
delete tested;
}
//TODO Parser::parseAscii
TEST_CASE("Parser::parseAscii PC", "[parser][parseAscii]") {
REQUIRE(0 == 1);
}
//TODO Parser::parseBin
TEST_CASE("Parser::parseBin PC", "[parser][parseBin]") {
REQUIRE(0 == 1);
}
//Loader
TEST_CASE("Check if files are loaded correctly", "[loader][full]") {
try {
const std::string file = "";
std::tuple<char *, uint64_t> loaded;
REQUIRE_NOTHROW(loaded = Loader::loadFile(file.c_str()));
REQUIRE(strncmp(std::get<0>(loaded), referenceFile, std::get<1>(loaded)) == 0);
} catch (std::exception &e) {
std::cout << e.what() << std::endl;
}
}