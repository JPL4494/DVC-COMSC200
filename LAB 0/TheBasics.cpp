/*
Lab 0c, The multiple input Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include<string>
using std::string;

#include<iomanip>
using std::setprecision;

#include<cstdlib>

int main()
{
  int age;
  double degree, convert;
  string name, city, buf;

  cout << "This program takes your information that you input and then ouputs it" << endl;
  cout << "Input information here:" << endl << endl;

  cout << "Enter age: ";
  getline(cin,buf);
  age = atoi(buf.c_str());

  cout << "Enter name: ";
  getline(cin,name);

  cout << "Enter outside temperature(degrees F): ";
  getline(cin,buf);
  degree = atof(buf.c_str());

  cout << "Enter city currently in: ";
  getline(cin,city);

  convert = 5 * (degree - 32) / 9;

  cout << endl << endl;
  cout << name << " is " << age << " years old, and will be " << (age + 1) << " a year from now" << endl;
  cout << "It's " << degree << " degrees F in " << city;
  cout << " -- that's " << setprecision(1) << setiosflags(ios::fixed|ios::showpoint) << convert << " degrees C";
  cout << endl << endl;
}
