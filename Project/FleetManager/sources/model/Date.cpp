//
// Created by lucas on 21/05/2025.
//

#include "Date.h"

#include <chrono>

#include "InvalidDataException.h"
#include <string>
#include <ctime>

using namespace std;

bool Date::isLeapYear(int year) {
    if (year % 400 == 0) {return true;}
    if (year % 100 == 0) {return false;}
    if (year % 4 == 0) {return true;}
    return false;
}

bool Date::isValid(int day, int month, int year) {
    bool is = true;
    if (day <= 0 || day > 31 || month <= 0 || month > 12) {
        is = false;
    }
    else {
        switch (month) {
            case 2:
                if (isLeapYear(year)) {
                    if (day > 29) {is = false;}
                }
                else {
                    if (day > 28) {is = false;}
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (day > 30) {is = false;}
                break;
        }
    }
    return is;
}

Date::Date() {
    try {
        const Date date = getToday();
        setDate(date.day, date.month, date.year);
    } catch (InvalidDataException &error) {
        cout << error.what() << endl;
        this->day = 1;
        this->month = 1;
        this->year = 2020;
    }
}

Date::Date(int day, int month, int year) {
    setDate(day, month, year);
}

Date::Date(const Date &date) {
    setDate(date.day, date.month, date.year);
}

bool Date::setDate(int day, int month, int year) {
    if (!isValid(day, month, year)) {
        string msg = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        throw InvalidDataException(msg);
    }
    this->day = day;
    this->month = month;
    this->year = year;
    return true;
}

void Date::getDate(int &day, int &month, int &year) const {
    day = this->day;
    month = this->month;
    year = this->year;
}

Date Date::getToday() {
    chrono::time_point now = chrono::system_clock::now();
    time_t timeNow = chrono::system_clock::to_time_t(now);
    tm localTime;
    #ifdef _WIN32
        if (localtime_s(&localTime, &timeNow) != 0) {
            throw InvalidDataException("Today's date");
        }
    #else
        tm *time = localtime(&timeNow);
        if (time == nullptr) {
            throw InvalidDataException("Today's date");
        }
        localTime = *time;
    #endif
        Date date = Date(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900);
        return date;
}

tm Date::mk_tm(int day, int month, int year) const {
    tm time = {0};
    time.tm_mday = day;
    time.tm_mon = month - 1;
    time.tm_year = year - 1900;
    return time;
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

bool Date::operator== (const Date &date) const {
    if (this->year == date.year && this->month == date.month && this->day == date.day) {
        return true;
    }
    return false;
}
bool Date::operator> (const Date &date) const {
    if (this->year > date.year) {return true;}
    if (this->month > date.month) {return true;}
    if (this->day > date.day) {return true;}
    return false;
}
bool Date::operator< (const Date &date) const {
    if (*this == date) {return false;}
    if (*this > date) {return false;}
    return true;
}

int Date::operator- (const Date &date) const {
    const int secondsPerDay = 60*60*24;
    tm today = mk_tm(date.day, date.month, date.year);
    tm existingDate = mk_tm(this->day, this->month, this->year);
    const time_t timeToday = mktime(&today);
    const time_t timeExistingDate = mktime(&existingDate);
    return difftime(timeToday, timeExistingDate) / secondsPerDay;
}

ostream &operator<<(ostream &stream, const Date &date) {
    stream << date.day << "/" << date.month << "/" << date.year;
    return stream;
}