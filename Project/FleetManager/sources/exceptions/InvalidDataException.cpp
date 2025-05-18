//
// Created by lucas on 15/05/2025.
//

#include "InvalidDataException.h"

InvalidDataException::InvalidDataException(string data) {
    this->data = "!! Error: \"" + data + "\" is invalid !!";
}

const char *InvalidDataException::what() {
    return this->data.c_str();
}