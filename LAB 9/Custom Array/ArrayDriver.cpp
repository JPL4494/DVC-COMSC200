/*
Lab 9a, The class array program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

#include "Array.h"
#include "Array.h"

int main()
{
  cout << "Lab 9a, The class array Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating 2 of the arrays using istringstream" << endl;

  istringstream sin;
  sin.str("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17\n17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1");

  cout << "Converting the istringstream into two arrays" << endl;
  Array a, b;
  sin >> a >> b;

  cout << endl << "Expeceted output from array 1: 1 2 3 4 5 6 7 8 9 10 in three rows" << endl;
  cout << a;

  cout << endl << "Expeceted output from array 2: 11 12 13 14 15 16 17 17 16 15 in three rows" << endl;
  cout << b;

  cout << endl << "Running copy constructor on array 1";
  Array c = a;
  cout << endl << "Expeceted output from array 3: 1 2 3 4 5 6 7 8 9 10 in three rows" << endl;
  cout << c;

  cout << endl << "Size of arrays, expected output 10, 10, 10" << endl;
  cout << a.getSize() << ", " << b.getSize() << ", " << c.getSize() << endl;

  cout << endl << "Testing the equality operator, ==, expected output false" << endl;
  if(a == b) cout << "True";
  if(a != b) cout << "False";

  cout << endl << "Testing the equality operator, ==, expected output true" << endl;
  if(a == c) cout << "True";
  if(a != c) cout << "False";
  cout << endl;

  {
    cout << endl << "Copying using inline copy" << endl;
    const Array copy = b;
    cout << "Expected output 11 12 13 14 15 16 17 17 16 15 in three rows" << endl;
    cout << copy;
  }
  {
    Array copy;
    copy = c;
    cout << endl << "Copying using after decleration copy" << endl;
    cout << "Expeceted output 1 2 3 4 5 6 7 8 9 10 in three rows" << endl;
    cout << copy;
  }


  cout << endl << endl;
}
