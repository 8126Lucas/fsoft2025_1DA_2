//
// Created by Vitor Teixeira on 08/06/2025.
//

#include "gtest/gtest.h"
#include "Date.h"
#include "InvalidDataException.h"

TEST(DateConstructorTest, ValidDate){
  bool flag = false;

  try{
     Date date(2, 5, 1996);
  }catch(InvalidDataException& error){
    flag = true;
  }
  EXPECT_FALSE(flag);
}

TEST(DateConstructorTest, InvalidDate){
  bool flag = false;

  try{
    Date date(2, 13, 1996);
  }catch(InvalidDataException& error){
    flag = true;
  }
  EXPECT_TRUE(flag);
}

TEST(DateSetTest, ValidDate){
  Date date;
  bool flag = false;

  try{
    date.setDate(2, 5, 1996);
  }catch(InvalidDataException& error){
    flag = true;
  }
  EXPECT_FALSE(flag);
}

TEST(DateSetTest, InvalidDate){
  Date date;
  bool flag = false;

  try{
    date.setDate(50, 5, 1996);
  }catch(InvalidDataException& error){
    flag = true;
  }
  EXPECT_TRUE(flag);
}

TEST(DateEqualTest, EqualDate){
  Date date1(2, 5, 1996);
  Date date2(2, 5, 1996);

  bool flag = (date1 == date2);
  EXPECT_TRUE(flag);
}

TEST(DateOperatorHigherTest, HigherDate){
  Date date1(8, 6, 2025);
  Date date2(2, 5, 1996);

  bool flag = (date1 > date2);
  EXPECT_TRUE(flag);
}

TEST(DateOperatorHigherTest, LowerDate){
  Date date1(2, 5, 1996);
  Date date2(8, 6, 2025);

  bool flag = (date1 > date2);
  EXPECT_FALSE(flag);
}

TEST(DateOperatorLowerTest, HigherDate){
  Date date1(2, 5, 1996);
  Date date2(8, 6, 2025);

  bool flag = (date1 < date2);
  EXPECT_TRUE(flag);
}

TEST(DateOperatorLowerTest, LowerDate){
  Date date1(8, 6, 2025);
  Date date2(2, 5, 1996);

  bool flag = (date1 < date2);
  EXPECT_FALSE(flag);
}
