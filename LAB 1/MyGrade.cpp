/*
Lab 1a, The FileIO grade Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include<cstdlib>

int main()
{
  int total = 0, average = 0;
  int grade[10];
  string buf;

  cout << "Lab 1a, The FileIO grade Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "This program allows you to enter 10 grades and find the class average" << endl << endl;

  for (int counter = 0; counter < 10; counter++)
  {
    cout << "Enter grade " << (counter+1) << ": ";
    getline(cin,buf);
    grade[counter] = atoi(buf.c_str());

    total = total + grade[counter];
  }

  system("CLS");
  cout << "Grades entered:" << endl;

  for(int c = 0; c < 10; c++)
  {
    cout << "Grade " << (c+1) << ": " << grade[c] << endl;
  }

  cout << endl << "Total Grade: " << total << endl;

  average = total / 10;
  cout << "Average grade: " << average << endl;

  cout << endl << endl;
}
