#ifndef DATE_H
#define DATE_H

/*
Lab 5a, The friend Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

class Date
{
public:
  static const int monthsPerYear = 12;
  Date(int = 1, int = 1, int = 1900);
  void print() const;
  ~Date();

private:
  int month;
  int day;
  int year;

  int checkDay(int) const;
};

#endif // DATE_H
