//
// Created by vitor on 5/16/25.
//

#ifndef HEADERS_MODEL_DRIVER_H
#define HEADERS_MODEL_DRIVER_H

#include <string>
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
    Driver(int id, char license, int age, bool available = true, bool vacationStatus = false);

    ~Driver();

    // void addDriver();
    // void removeDriver();

    int getID();
    char getLicense() const;
    int getAge() const;
    int getTimeToRetire() const;
    list<Vacation *> getVacations();
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

    bool operator == (int id) const;
};

#endif //HEADERS_MODEL_DRIVER_H