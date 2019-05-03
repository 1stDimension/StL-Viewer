#define CATCH_CONFIG_MAIN
#include "Catch/catch.hpp"

#include <cstring>
#include "parserStl.h"
#include "TriangleStl.h"
#include "Loader.h"
#include <string>

char* referenceVertex = "vertex 0.0 0.0 0.0\n";

char* referenceTriangle = "facet normal 0.0 -1.0 0.0\n"
                            "            outer loop\n"
                        "              vertex 0.0 0.0 0.0\n"
                        "              vertex 1.0 0.0 0.0\n"
                        "              vertex 0.0 0.0 1.0\n"
                        "            endloop\n";

auto referenceFile = "solid cube_corner\n"
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
TEST_CASE("Parser::parseFile PC", "[parser][full]") {
    REQUIRE(0 == 1);
}
//TODO Parser::readTriangleAscii
TEST_CASE("Parser::readTriangleAscii PC", "[parser][readTriangleAscii]") {
    float normal[] = {0.0, -1.0, 0.0};
    float vertexOne[] = {0.0, -1.0, 0.0};
    float vertexTwo[] = {0.0, -1.0, 0.0};
    float vertexTree[] = {0.0, -1.0, 0.0};
    auto reference = new TriangleStl(normal, vertexOne, vertexTwo, vertexTree);
    auto  tested   = Parser::readTriangleAscii(referenceTriangle, strlen(referenceTriangle));
    REQUIRE(tested != nullptr);
    auto testedTriangle = tested->first;
    REQUIRE(reference->getDirection() == testedTriangle.getDirection());
    REQUIRE(reference->getVertexOne() == testedTriangle.getVertexOne());
    REQUIRE(reference->getVertexTwo() == testedTriangle.getVertexTwo());
    REQUIRE(reference->getVertexTree() == testedTriangle.getVertexTree());
}
//TODO Parser::readVertex
TEST_CASE("Parser::readVertex PC", "[parser][shift]") {
    char* end = nullptr;
    float* tested = Parser::readVertex(referenceVertex, strlen(referenceVertex), &end);
    float epsilon = 0.000001;
    REQUIRE(tested != nullptr);
    CHECK((tested[0] - 0.0f) < epsilon);
    CHECK((tested[1] - 0.0f) < epsilon);
    CHECK((tested[2] - 0.0f) < epsilon);
}
//TODO Parser::shift
TEST_CASE("Parser::shift PC", "[parser][shift]") {
    REQUIRE(0 == 1);
}
//TODO Parser::omitWhiteSpaces
TEST_CASE("Parser::omitWhiteSpaces PC", "[parser][omitWhiteSpaces]") {
    REQUIRE(0 == 1);
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
TEST_CASE("Check if files are loaded correctly", "[loader][full]"){
    try {
        const std::string file = "example.stl";
        auto loader = new Loader();
        auto loaded = loader->loadFile(file);
        REQUIRE(strncmp(std::get<0>(loaded), referenceFile, std::get<1>(loaded)) == 0);
        delete loader;
    } catch (std::exception& e) {
        std::cout << e.what()<<std::endl;
    }
}