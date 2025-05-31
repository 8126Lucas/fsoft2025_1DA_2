//
// Created by lucas on 15/05/2025.
//

#include "NonExistingDataException.h"

NonExistingDataException::NonExistingDataException(const string &data)
    : runtime_error("!! Error: \"" + data + "\" does not exist !!") {}

const char *NonExistingDataException::what() const noexcept {
    return runtime_error::what();
}