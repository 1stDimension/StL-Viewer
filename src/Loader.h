#pragma once

#include <string>
#include <tuple>
#include <cstdint>
#include <string>

class Loader {
public:
    std::tuple<char *, uint64_t> loadFile(const std::string& name);
};


