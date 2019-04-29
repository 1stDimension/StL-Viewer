#pragma once

#include "TriangleStl.h"
#include <vector>

class ParserStl{
public:
    std::vector<TriangleStl> parse();
};
