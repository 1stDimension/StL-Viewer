#include "BadFileException.h"

const char *BadFileException::what() const noexcept {
    return "An error occurred while reading file";
}