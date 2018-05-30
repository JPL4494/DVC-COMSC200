/*
Lab 14, The elevator class program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <iostream>
using std::ostream;
using std::endl;

#include <vector>
using std::vector;

#include <cstdlib>

#include "Floor.h"
#include "Rider.h"
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
  out << "Elevator: " << e.ID << " Location: " << e.location << " ";
  if(e.direction == 0) out << "IDLE";
  if(e.direction == 1) out << "UP";
  if(e.direction == -1) out << "DOWN";
  out << " Door: ";
  if(e.doorOpen) out << "Open";
  else out << "Closed";
  if(e.riders.size() == 0) out << " No Riders" << endl;
  else if(e.riders.size() == 1) out << " One Rider" << endl;
  else out << " " << e.riders.size() << " Riders" << endl;
  return out;
}

bool Elevator::isNearDestination() const
{
  bool result = false;
  if(direction == UP)
  {
    if(location >= 0)
    {
      if((toFloor->getLocation()) == location)return true;
      if(((toFloor->getLocation()) - location) <= speed)
      {
        return true;
      }
    }
    if(location < 0)
    {
      if(((toFloor->getLocation()) + location) <= speed)return true;
    }
  }
  if(direction == DOWN)
  {
    if((toFloor->getLocation()) == location)return true;
    if(location >= 0)
    {
      if(((toFloor->getLocation()) + location) >= speed)return true;
    }
    if(location < 0)
    {
      if(((toFloor->getLocation()) - location) >= speed)return true;
    }
  }

  return result;
}

void Elevator::moveToDestinationFloor()
{
  location = toFloor->getLocation();
}

vector<Rider> Elevator::removeRidersForDestinationFloor()
{
  /// create empty vector of removed riders to be used as return value
  vector <Rider> removed;
  /// if elevator has any riders
  if(riders.size() != 0)
  {
    /// create an empty vector for riders who remain on elevator
    vector <Rider> stay;
    /// traverse vector of current riders
    for(int i = 0; i < riders.size(); i++)
    {
      /// if a rider's destination floor is same as elevator's destination...
      if(riders[i].destination->getLocation() == location)
        removed.push_back(riders[i]);/// add rider to vector of removed riders

      /// else
      else
        stay.push_back(riders[i]);/// add rider to vector of remaining riders
    }
    /// reassign elevator rider vector to vector of remaining riders
    riders = stay;
  }
  /// return vector of removed riders
  return removed;
}

void Elevator::addRiders(const vector<Rider>& r)
{
  /// if the parameter vector is empty
  if(r.size() == 0) return;/// exit the function

  /// traverse the parameter vector
  for(int i = 0; i < r.size(); i++)
  {
    /// if there is still room on the elevator
    if(riders.size() < capacity) riders.push_back(r[i]);
      /// add the rider to the elevator's rider vector
  }
}

void Elevator::setDestinationBasedOnRiders()
{
  /// if there are no riders on the elevator
  if(riders.size() == 0) return;/// exit the function

  /// create an int to track the closest rider's distance to his destination
  int d = -1;/// initialize it to a negative number (to signify that it is not yet set)

  /// traverse the vector of elevator riders
  for(int i = 0; i < riders.size(); i++)
  {
    /// calculate the distance from the elevator to the rider's destination floor
    int temp = abs(riders[i].destination->getLocation() - location);/// convert to absolute value

    /// if closest rider's distance is negative OR is greater than the above value
    if((temp < 0 || temp > d))
       {
         /// set closest rider's distance to the above value
         d = temp;
         /// set elevator's destination floor to rider's destination floor
         setDestination(riders[i].destination);
       }
  }
}
