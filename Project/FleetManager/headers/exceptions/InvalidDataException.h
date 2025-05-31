//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H
#define HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H
#include <stdexcept>
#include <string>

using namespace std;

class InvalidDataException : public runtime_error {
public:
    InvalidDataException(const string &data);
    const char *what() const noexcept override;
};


#endif //HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H
