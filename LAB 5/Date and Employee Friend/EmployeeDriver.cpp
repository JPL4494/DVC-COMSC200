/*
Lab 5a, The friend Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;

#include "Date.h"
#include "Date.h"
#include "Employee.h"
#include "Employee.h"

int main()
{
  cout << "Lab 5a, The friend Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Passing employee info as follows, Josh Long 4 4 1994 8 15 2011" << endl;
  Date b(4,4,1994);
  Date h(8,15,2011);
  Employee e("Josh","Long",b,h);
  cout << endl << "Expected out put Long, Josh Hired: 8/15/2011 Birthday: 4/4/1994" << endl;
  e.print();

  cout << endl << endl;

  {
    cout << "Copying employee information from above using upon declaration copy" << endl;
    const Employee copy = e;
    cout << endl << "Expected out put Long, Josh Hired: 8/15/2011 Birthday: 4/4/1994" << endl;
    copy.print();
    cout << endl << endl;
  }
  cout << endl;
}
