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

int main()
{
  cout << "Lab 5a, The friend Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Passing date 4 4 1994 into constructor, expected result 4/4/1994" << endl;
  Date d(4,4,1994);
  cout << endl;

  cout << "Passing 13 31 1994 into constructor, expected result 2 errors then 1/1/1994" << endl;
  Date e(13,32,1994);
  cout << endl;

  cout << "Passing 2 29 1994 into constructor, expected result 1 error then 2/1/1994" << endl;
  Date f(2,29,1994);
  cout << endl;

  {
    const Date copy = d;
    cout << "Copying date 1 using upon declaration copy, expected result 4/4/1994" << endl;
    copy.print();
    cout << endl << endl;
  }

  {
    Date copy;
    copy = d;
    cout << endl << "Copying date 1 using after declaration copy, expected result 4/4/1994" << endl;
    copy.print();
    cout << endl << endl;
  }
}
