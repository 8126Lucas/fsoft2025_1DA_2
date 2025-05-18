//
// Created by lucas on 15/05/2025.
//

#include "DuplicatedDataException.h"

DuplicatedDataException::DuplicatedDataException(string data) {
    this->data = "!! Error: \"" + data + "\" duplicated !!";
}

const char *DuplicatedDataException::what() {
    return this->data.c_str();
}