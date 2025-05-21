//
// Created by vitor on 5/16/25.
//

#ifndef HEADERS_MODEL_DATE_H
#define HEADERS_MODEL_DATE_H
#include "Inspection.h"


class Date {
private:
      int day;
      int month;
      int year;
      bool isLeapYear(int year);
      bool isValid(int day, int month, int year);

public:
      Date();
      Date(int day, int month, int year);
      Date(const Date &date);
      void setDate(int day, int month, int year);
      void getDate(int &day, int &month, int &year) const;


      static Date getToday();
      tm mk_tm(int day, int month, int year) const;

      bool operator==(const Date &date) const;
      bool operator>(const Date &date) const;
      bool operator<(const Date &date) const;
      int operator-(const Date & date) const;


};


#endif //HEADERS_MODEL_DATE_H
