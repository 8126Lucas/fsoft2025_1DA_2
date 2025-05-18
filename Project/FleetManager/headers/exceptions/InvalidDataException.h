//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H
#define HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H
#include <exception>
#include <string>

using namespace std;

class InvalidDataException : public exception {
private:
    string data;
public:
    InvalidDataException(string data);
    const char *what();
};


#endif //HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H
