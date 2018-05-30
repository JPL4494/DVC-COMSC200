#ifndef EMPLOYEE_H
#define EMPLOYEE_H

/*
Lab 5a, The friend Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <string>
using std::string;

#include "Date.h"

class Employee
{
public:
  Employee(const string&, const string&, const Date&, const Date&);
  void print() const;
  ~Employee();

private:
  string firstName;
  string lastName;
  const Date birthDate;
  const Date hireDate;
};

#endif // EMPLOYEE_H
