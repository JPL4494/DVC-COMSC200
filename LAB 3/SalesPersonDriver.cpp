/*
Lab 3a, The salesperson earnings Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;

#include "SalesPerson.h"
#include "SalesPerson.h"

int main()
{
  cout << "Lab 3a, The Sales person encapsulation Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  SalesPerson salesPerson;

  cout << "Running setSales function with entered values 13 and 100 for months and amount" << endl;
  cout << "Expected results will be error message since over 12" << endl;
  salesPerson.setSales(13,100);
  cout << endl;

  cout << "Enter 100 200 300 400 500 600 700 800 900 100 200 300" << endl;
  salesPerson.getSalesFromUser();

  cout << endl << endl << "Expected annual sales $5100.00";
  salesPerson.printAnnualSales();

  cout << endl << "Entering month 2 amd $700 to change annual sales";
  salesPerson.setSales(2,700);

  cout << endl << "Expected annual sales $5600.00";
  salesPerson.printAnnualSales();

  {
    SalesPerson copy = salesPerson;
    cout << endl << "Copying salesperson information to in line copy" << endl;
    cout << endl << "Expected annual sales $5600.00";
    copy.printAnnualSales();
  }

  {
    SalesPerson copy;
    copy = salesPerson;
    cout << endl << "Copying salesperson information to after declaration copy" << endl;
    cout << endl << "Expected annual sales $5600.00";
    copy.printAnnualSales();
  }
}
