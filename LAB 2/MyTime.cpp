/*
Lab 2a, The universal clock Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;

#include<iomanip>
using std::setfill;
using std::setw;

#include<cstdlib>

class Time
{
public:
  Time();
  void setTime(int,int,int);
  void printUniversal();
  void printStandard();

private:
  int hour;
  int minute;
  int second;
};

Time::Time()
{
  hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s)
{
  hour = (h >= 0 && h < 24) ? h : 0;
  minute = (m >= 0 && m < 60) ? m : 0;
  second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printUniversal()
{
  cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":"
    << setw(2) << second;
}

void Time::printStandard()
{
  cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setfill('0') << setw(2)
    << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM");
}

int main()
{
  Time t;

  cout << "Lab 2a, The universal clock Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "This program takes in the time and then displays it in universal and standard" << endl << endl;

  cout << endl;
  cout << "The initial universal time is ";
  t.printUniversal();
  cout << endl;
  cout << "The initial standard time is ";
  t.printStandard();
  cout << endl;

  t.setTime(13,27,6);

  cout << endl;
  cout << "Entered universal time is ";
  t.printUniversal();
  cout << endl;
  cout << "Entered standard time is ";
  t.printStandard();

  t.setTime(99,99,99);

  cout << endl << endl << "After atemping invalid settings:" << endl;
  cout << "Universal time: ";
  t.printUniversal();
  cout << endl;
  cout << "Standard time: ";
  t.printStandard();
  cout << endl << endl;
}
