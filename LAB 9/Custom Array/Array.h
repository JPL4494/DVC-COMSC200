/*
Lab 9a, The class array program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include<iostream>
using std::ostream;
using std::istream;

class Array
{
  friend ostream& operator<<(ostream &, const Array &);
  friend istream& operator>>(istream &, Array &);

public:
  Array(int = 10);
  Array(const Array &);
  ~Array();
  int getSize() const;
  const Array& operator=(const Array &);
  bool operator==(const Array &) const;
  bool operator!=(const Array & right) const {return !(*this == right);}
  int& operator[](int);
  int operator[](int) const;

private:
  int size;
  int* ptr;
};

#endif // ARRAY_H_INCLUDED
