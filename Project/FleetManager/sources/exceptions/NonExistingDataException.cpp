//
// Created by lucas on 15/05/2025.
//

#include "NonExistingDataException.h"

NonExistingDataException::NonExistingDataException(string data) {
    this->data = "!! Error: \"" + data + "\" does not exist !!";
}

const char *NonExistingDataException::what() {
    return this->data.c_str();
}