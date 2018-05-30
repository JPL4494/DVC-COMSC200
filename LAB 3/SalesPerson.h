/*
Lab 3a, The salesperson earnings Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;

#ifndef SALESP_H
#define SALESP_H

class SalesPerson
{
public:
  static const int monthsPerYear = 12;
  SalesPerson();
  void getSalesFromUser();
  void setSales(int, double);
  void printAnnualSales();

private:
  double totalAnnualSales();
  double sales[monthsPerYear];
};

#endif

#ifdef SALESP_H

#endif
