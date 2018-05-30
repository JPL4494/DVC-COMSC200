/*
Lab 8b, The elevator program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include "Floor.h"

Floor::Floor(int x)
:level(x)
{}

int Floor::getLocation() const
{
  return level;
}
