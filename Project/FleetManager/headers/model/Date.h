//
// Created by vitor on 5/16/25.
//

#ifndef HEADERS_MODEL_DATE_H_
#define HEADERS_MODEL_DATE_H_



class Date {
    private:
      int day;
      int month;
      int year;
      bool isLeapYear(int year);
      bool isValid(int day, int month, int year);
};

    public:
      Date();
      void setDate(int day, int month, int year);
      void getDate(int& day, int& month, int& year);

#endif //HEADERS_MODEL_DATE_H
