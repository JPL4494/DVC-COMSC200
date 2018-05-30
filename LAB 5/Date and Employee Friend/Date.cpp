/*
Lab 5a, The friend Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

Date::Date(int mn, int dy, int yr)
{
  if (mn > 0 && mn <= monthsPerYear)
  {
    month = mn;
  }
  else
  {
    month = 1;
    cout << "Invalid month(" << mn << "), now set to 1" << endl;
  }

  year = yr;
  day = checkDay(dy);

  cout << "Date object constructor for date ";
  print();
  cout << endl;
}

void Date::print() const
{
  cout << month << "/" << day << "/" << year;
}

Date::~Date()
{
  cout << "Date object destructor for date ";
  print();
  cout << endl;
}

int Date::checkDay(int testDay) const
{
  static const int daysPerMonth[monthsPerYear + 1] =
    {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (testDay > 0 && testDay <= daysPerMonth[month])
    {
      return testDay;
    }
    if (month == 2 && testDay == 29 && (year % 400 == 0 ||
          (year % 4 == 0 && year % 100 != 0)))
    {
      return testDay;
    }

    cout << "Invalid day, (" << testDay << "), now set to 1" << endl;
    return 1;
}
