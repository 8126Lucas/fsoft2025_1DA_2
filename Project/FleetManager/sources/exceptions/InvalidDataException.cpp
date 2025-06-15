//
// Created by lucas on 15/05/2025.
//

#include "InvalidDataException.h"

InvalidDataException::InvalidDataException(const string &data)
    : runtime_error("!! Error: \"" + data + "\" is invalid !!") {}

InvalidDataException::InvalidDataException(): runtime_error("") {}

const char *InvalidDataException::what() const noexcept {
    return runtime_error::what();
}