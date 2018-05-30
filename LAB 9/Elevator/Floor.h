/*
Lab 8b, The elevator program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED

class Floor
{
private:
  const int level;

public:
  Floor(int);
  int getLocation() const;
};

#endif // FLOOR_H_INCLUDED
