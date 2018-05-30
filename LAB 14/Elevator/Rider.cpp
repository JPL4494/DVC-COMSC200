/*
Lab 14, The elevator program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include "Rider.h"

static int IDhelper = 0;

class Floor;

Rider::Rider(const Floor & level)
:ID(IDhelper), destination(&level)
{
  IDhelper++;
}

bool operator< (const Rider& riderA, const Rider& riderB)
{
  if(riderA.ID < riderB.ID)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool operator== (const Rider& riderA, const Rider& riderB)
{
  if(riderA.ID == riderB.ID)
  {
    return true;
  }
  else
  {
    return false;
  }
}

const Floor& Rider::getDestination() const
{
  return *destination;
}

Rider& Rider::operator= (const Rider& temp)
{
  return *this;
}
