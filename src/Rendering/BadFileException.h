#pragma once
#include <exception>

class BadFileException : public std::exception {
    const char* what() const noexcept override;
};