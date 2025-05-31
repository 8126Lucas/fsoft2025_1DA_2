//
// Created by lucas on 15/05/2025.
//

#include "DuplicatedDataException.h"

DuplicatedDataException::DuplicatedDataException(const string &data)
    : runtime_error("!! Error: \"" + data + "\" duplicated !!") {}

const char *DuplicatedDataException::what() const noexcept {
    return runtime_error::what();
}