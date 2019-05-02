#define CATCH_CONFIG_MAIN
#include "Catch/catch.hpp"

#include <cstring>
#include "parserStl.h"
#include "Loader.h"
#include <string>

auto refferenceFile = "solid cube_corner\n"
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
//Parser
TEST_CASE( "Full check of parser capability", "[parser][full]" ) {
    REQUIRE( 0 == 1);
}
//Loader
TEST_CASE("Check if files are loaded correctly", "[loader][full]"){
    try {
        const std::string file = "example.stl";
        auto loader = new Loader();
        auto loaded = loader->loadFile(file);
        REQUIRE(strncmp(std::get<0>(loaded), refferenceFile, std::get<1>(loaded)) == 0);
        delete loader;
    } catch (std::exception& e) {
        std::cout << e.what()<<std::endl;
    }
}