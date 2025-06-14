//
// Created by vitor on 5/16/25.
//

#ifndef HEADERS_MODEL_DRIVER_H
#define HEADERS_MODEL_DRIVER_H

#include <list>

#include "Vacation.h"

using namespace std;

class Vacation;

class Driver {
private:
    int id;
    char license;
    int age;
    int timeToRetire;
    bool available;
    list<Vacation *> vacations;

public:
    Driver();

    Driver(int id, char &license, int age);

    ~Driver();

    int getID() const;
    char getLicense() const;
    int getAge() const;
    int getTimeToRetire() const;
    const list<Vacation*>& getVacations() const;
    list<Vacation*>& getVacations();
    Vacation *getVacation();
    bool getAvailability() const;
    int getVacationID();

    void setID(int id);
    void setLicense(char license);
    void setAge(int age);
    void setTimeToRetire(int age);
    void setVacation(Vacation *vacation);
    void setAvailability(bool available);

    void vacationAlert();
    void retirementAlert();
    bool isAvailable() const;

    char stringToChar(string &license);

    bool operator == (int id) const;
};

#endif //HEADERS_MODEL_DRIVER_H