/*
Lab 4a, The time Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;

#include "Time.h"
#include "Time.h"

int main()
{
  cout << "Lab 4a, The time Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time t;

  cout << "Running individual setters, entering 1 2 3" << endl;
  t.setHour(1);
  t.setMinute(2);
  t.setSecond(3);

  cout << endl << "Running getter functions, expected outputs 1, 2, 3" << endl;
  cout << t.getHour() << ", " << t.getMinute() << ", " << t.getSecond() << endl << endl;

  cout << "Entering 16 44 65" << endl;
  t.setTime(16,44,65);

  cout << endl << endl << "Running print, expected outputs 16:44:00 and 4:44:00 PM" << endl;
  t.printUniversal();
  cout << endl;
  t.printStandard();
  cout << endl;


  {
    const Time copy = t;
    cout << endl << "Copying information from Time t using in line";
    cout << endl << "Expected outputs 16:44:00 and 4:44:00 PM" << endl;
    copy.printUniversal();
    cout << endl;
    copy.printStandard();
    cout << endl;
  }

  {
    Time copy;
    copy = t;
    cout << endl << "Copying information from Time t using after decleration";
    cout << endl << "Expected outputs 16:44:00 and 4:44:00 PM" << endl;
    copy.printUniversal();
    cout << endl;
    copy.printStandard();
    cout << endl;
  }
}
