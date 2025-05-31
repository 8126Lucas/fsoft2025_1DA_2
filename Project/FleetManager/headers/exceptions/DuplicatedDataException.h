//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H
#define HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class DuplicatedDataException : public runtime_error {
public:
    explicit DuplicatedDataException(const string &data);
    const char *what() const noexcept override;
};

#endif //HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H
