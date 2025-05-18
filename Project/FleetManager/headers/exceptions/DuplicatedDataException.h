//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H
#define HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class DuplicatedDataException : public exception {
private:
    string data;
public:
    explicit DuplicatedDataException(string data);
    const char *what();
};

#endif //HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H
