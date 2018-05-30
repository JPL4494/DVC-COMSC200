/*
Lab 9b, The elevator class program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <iostream>
using std::ostream;
using std::endl;

#include "Floor.h"
#include "Elevator.h"

static int elevatorID = 0; /// initialize to zero; use to assign unique ID to each elevator

Elevator::Elevator(const int c, const int s, const Floor& curr)
:ID(elevatorID),capacity(c),speed(s),toFloor(0),location(curr.getLocation())
{
  elevatorID++;
  direction = IDLE;
  doorOpen = true;
}

ostream& operator<<(ostream& out, const Elevator& e)
{
  out << "Elevator: " << e.ID << " Location: " << e.location << " Direction: ";
  if(e.direction == 0) out << "IDLE";
  if(e.direction == 1) out << "UP";
  if(e.direction == -1) out << "DOWN";
  out << " Doors: ";
  if(e.doorOpen) out << "Open" << endl;
  else out << "Closed" << endl;
  return out;
}

bool Elevator::isNearDestination() const
{
  bool result = false;
  if(direction == UP)
  {
    if(location >= 0)
    {
      if(((toFloor->getLocation()) + location) <= speed)result = true;
    }
    if(location < 0)
    {
      if(((toFloor->getLocation()) - location) <= speed)result = true;
    }
  }
  if(direction == DOWN)
  {
    if(location >= 0)
    {
      if(((toFloor->getLocation()) + location) <= speed)result = true;
    }
    if(location < 0)
    {
      if(((toFloor->getLocation()) - location) <= speed)result = true;
    }
  }

  return result;
}

void Elevator::moveToDestinationFloor()
{
  location = toFloor->getLocation();
}
