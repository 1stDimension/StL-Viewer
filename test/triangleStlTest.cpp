#include "Catch/catch.hpp"
#include "Parser/TriangleStl.h"


float dir[3] = {0.0f, 0.0f, 0.0f};
float vertxOne[3] = {1.0f, 1.0f, 1.0f};
float vertexTwo[3] = {0.5f, 0.5f, 0.5f};
float vertexTree[3] = {-1.0f, -1.0f, -1.0f};



TEST_CASE("Check full functionality", "[full][TraingleStl]") {

}

TEST_CASE("Check if getAll method works", "[getAll][TraingleStl]") {
    float refference[12] = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, 0.5f, -1.0f, -1.0f, -1.0f};
    auto test = new TriangleStl(dir, vertxOne, vertexTwo, vertexTree);
    float *data = test->getAll();
    for(int i=0; i < 12; i++){
        REQUIRE(data[i] == refference[i]);
    }
}