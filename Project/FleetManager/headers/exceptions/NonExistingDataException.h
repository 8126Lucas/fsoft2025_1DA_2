//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_EXCEPTIONS_NONEXISTINGDATAEXCEPTION_H
#define HEADERS_EXCEPTIONS_NONEXISTINGDATAEXCEPTION_H
#include <exception>
#include <string>

using namespace std;

class NonExistingDataException : public exception {
private:
    string data;
public:
    NonExistingDataException(string data);
    const char *what();
};

#endif //HEADERS_EXCEPTIONS_NONEXISTINGDATAEXCEPTION_H
