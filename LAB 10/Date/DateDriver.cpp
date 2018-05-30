/*
Lab 10a, The date program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"
#include "Date.h"

int main()
{
  cout << "Lab 10a, The date Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Date d1(4,4,1994);
  Date d2(12,31,2013);
  Date d3(2,29,2004);
  Date d4(2,29,2003);

  cout << "Creating 4 date objects" << endl;
  cout << "Displaying date 1, expected output April 4, 1994" << endl;
  cout << d1;
  cout << "Displaying date 1 added +1 pre, expected output April 5, 1994" << endl;
  cout << ++d1;
  cout << "Displaying date 1 added +1 post, expected output April 5, 1994" << endl;
  cout << d1++;
  cout << "Now displaying date 1 after +1 post, expected output April 6, 1994" << endl;
  cout << d1;

  cout << endl << endl;

  cout << "Displaying date 2, expected output December 31, 2013" << endl;
  cout << d2;
  cout << "Displaying date 2 +1 pre, expected output January 1, 2014" << endl;
  cout << ++d2;

  cout << endl << endl;

  cout << "Displaying date 3,  expected output February 29, 2004" << endl;
  cout << d3;
  cout << "Displaying date 4,  expected output February 1, 2003" << endl;
  cout << d4;

  {
    const Date copy = d1;
    cout << endl << endl << "Creating a const copy using inline copy" << endl;
    cout << "Displaying date copy, expected output April 6, 1994" << endl;
    cout << copy;
  }
  {
    Date copy;
    copy = d1;
    cout << endl << endl << "Creating a const copy using after decleration copy" << endl;
    cout << "Displaying date copy, expected output April 6, 1994" << endl;
    cout << copy;
  }

  cout << endl << endl;
}
