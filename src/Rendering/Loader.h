#pragma once

#include <string>
#include <tuple>
#include <cstdint>
#include <string>

class Loader {
public:
    static std::tuple<char *, uint64_t> loadFile(const char* name);
};


