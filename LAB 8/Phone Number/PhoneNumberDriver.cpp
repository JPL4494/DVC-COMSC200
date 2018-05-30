/*
Lab 8a, The phone number program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

#include "PhoneNumber.h"
#include "PhoneNumber.h"

int main()
{
  cout << "Lab 8a, The phone number Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating 3 phone numbers in a istringstream" << endl;

  istringstream sin;
  sin.str("(925) 330-3741(925) 689-1760(123) 456-7890");

  cout << "Converting the istringstream into PhoneNumber objects" << endl;
  PhoneNumber a, b, c;
  sin >> a >> b >> c;

  cout << endl;

  cout << "Phone number 1 expected output (925) 330-3741" << endl;
  cout << a << endl << endl;
  cout << "Phone number 2 expected output (925) 689-1760" << endl;
  cout << b << endl << endl;
  cout << "Phone number 3 expected output (123) 456-7890" << endl;
  cout << c << endl << endl;

  {
    const PhoneNumber copy = a;
    cout << "Copying phone number 1 using inline copy" << endl;
    cout << "Phone number copy expected output (925) 330-3741" << endl;
    cout << copy << endl << endl;
  }

  {
    PhoneNumber copy;
    copy = b;
    cout << "Copying phone number 2 using after decleration copy" << endl;
    cout << "Phone number copy expected output (925) 689-1760" << endl;
    cout << copy << endl << endl;
  }
  cout << endl << endl;
}
