//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_EXCEPTIONS_NONEXISTINGDATAEXCEPTION_H
#define HEADERS_EXCEPTIONS_NONEXISTINGDATAEXCEPTION_H
#include <stdexcept>
#include <string>

using namespace std;

class NonExistingDataException : public runtime_error {
public:
    NonExistingDataException(const string &data);
    const char *what() const noexcept override;
};

#endif //HEADERS_EXCEPTIONS_NONEXISTINGDATAEXCEPTION_H
