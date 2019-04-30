#pragma once

#include "TriangleStl.h"
#include <vector>
#include <fstream>

std::vector<TriangleStl> parseFile( std::ifstream input);
