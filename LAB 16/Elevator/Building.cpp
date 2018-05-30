/*
Lab 15, The elevator program
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
#include <ctime>

#include"Building.h"
#include"Floor.h"
#include"Elevator.h"
#include"Rider.h"

Building::Building()
:time(0)
{
  Floor* f1 = new Floor(-100, "Basement");
  Floor* f2 = new Floor(0, "Ground Floor");
  Floor* f3 = new Floor(100, "First Floor");
  Floor* f4 = new Floor(200, "Second Floor");
  Floor* f5 = new Floor(300, "Third Floor");
  Floor* f6 = new Floor(400, "Fourth Floor");
  level.push_back(f1);
  level.push_back(f2);
  level.push_back(f3);
  level.push_back(f4);
  level.push_back(f5);
  level.push_back(f6);

  Elevator* e1 = new Elevator(18,50,*level[0]);
  Elevator* e2 = new Elevator(28,35,*level[1]);
  Elevator* e3 = new Elevator(25,40,*level[2]);
  Elevator* e4 = new Elevator(35,35,*level[3]);
  Elevator* e5 = new Elevator(18,60,*level[4]);
  Elevator* e6 = new Elevator(30,35,*level[5]);
  elevators.push_back(e1);
  elevators.push_back(e2);
  elevators.push_back(e3);
  elevators.push_back(e4);
  elevators.push_back(e5);
  elevators.push_back(e6);
}

ostream& operator<<(ostream& out, const Building& b)
{
  out << "Time: " << b.time << "\n";
  for(int i = 0; i < b.getElevatorCount(); i++) out << *(b.elevators[i]);
  for(int i = 0; i < b.getFloorCount(); i++)
  {
    if(b.level[i]->hasRidersWaiting())
    {
      out << *(b.level[i]);
    }
  }
  return out;
}

Building::~Building()
{
  for(int i = 0; i < level.size(); i++)
  {
    delete level[i];
  }
  for(int i = 0; i < elevators.size(); i++)
  {
    delete elevators[i];
  }
}

void Building::getDifferentInts(int max, int& a, int& b)
{
  do
  {
    a = rand() % max; // range is 0 to (max-1)
    b = rand() % max; // range is 0 to (max-1)
  } while (a == b); // try again if they are the same
}

Building& Building::step(int addRider)
{
  int onFloor, toFloor;
  // POSSIBLE RIDER ACTION [1]
  vector<Rider> addNew;
  // add rider(s) in this time step (The number of riders to be added is sent to this function in the argument list, and is greater or equal to 0.) [1]
  for(int i = 0; i < addRider; i++)
  {
    // create a rider with randomly selected from- and to-floors (where from- and to- are not the same!) [1]
    getDifferentInts(getFloorCount(), onFloor, toFloor);
    addNew.push_back(getFloor(toFloor));
    // tell the from-floor to add this rider [1]
    level[onFloor]->addNewRider(addNew[i]);
  }

  // ELEVATOR ACTIONS [3]
  // tell each elevator to perform an action [3]
  for(int i = 0; i < elevators.size(); i++)
  {
    // if elevator door is closed (move up or down) [3]
    if(!elevators[i]->isDoorOpen())
    {
      // if not near enough to destination to reach it in this time step, continue moving [3]
      if(!elevators[i]->isNearDestination())
      {
        // if elevator direction is up, move up [3]
        if(elevators[i]->isDirectionUp())
        {
          if((elevators[i]->getDestination().getLocation()-elevators[i]->getLocation()) > 0)elevators[i]->moveUp();
          else
          {
            elevators[i]->moveDown();
            elevators[i]->setDirectionDown();
          }
        }
        // otherwise, move down [3]
        else if(elevators[i]->isDirectionDown())
        {
          if((elevators[i]->getDestination().getLocation()-elevators[i]->getLocation()) < 0)elevators[i]->moveDown();
          else
          {
            elevators[i]->moveUp();
            elevators[i]->setDirectionUp();
          }
        }
      }

      // otherwise it's near enough to destination to reach it in this time step... [4]
      else
      {
        // tell elevator to move to its destination floor [4]
        elevators[i]->moveToDestinationFloor();
        // tell elevator to open its door [4]
        elevators[i]->openDoor();
        // tell elevator to remove riders for its destination floor -- ignore returned vector of removed riders [4]
        vector<Rider> gettingOff = elevators[i]->removeRidersForDestinationFloor();

        // get a non-const pointer to the elevator's destination floor (using const_cast) [5]
        Floor* destinFloor = const_cast<Floor*>(&elevators[i]->getDestination());

        // if elevator is empty, choose a direction based on longest-waiting rider (the one with the smallest ID) on the floor: [5]
        if(elevators[i]->getRiderCount() == 0)
        {
          // if the floor's chosen direction is up [5]
          if(destinFloor->isPreferredDirectionUp())
          {
            // tell elevator to set its direction to up [5]
            elevators[i]->setDirectionUp();
          }

          // otherwise [5]
          else
          {
            // tell elevator to set its direction to down [5]
            elevators[i]->setDirectionDown();
          }

        }

        // if there is space in the elevator after letting off riders, board new ones [6]
        if(elevators[i]->getAvailableSpace() > 0)
        {
          // if elevator direction is up, board up-riders (if any)... [6]
          if(elevators[i]->isDirectionUp())elevators[i]->addRiders(destinFloor->removeUpRiders(elevators[i]->getAvailableSpace()));
          // otherwise, board down-riders (if any) [6]
          else elevators[i]->addRiders(destinFloor->removeDownRiders(elevators[i]->getAvailableSpace()));
        }
      }
      // reassess elevator destination based on its riders [8]
      elevators[i]->setDestinationBasedOnRiders();
    }

    // otherwise (then it already let off riders, or is in its initial state) [7]
    if(elevators[i]->isDoorOpen())
    {
      // if elevator has any riders (then they just boarded in the previous time step) [7]
      if(elevators[i]->hasRiders())
      {
        // tell elevator to close its door [7]
        elevators[i]->closeDoor();
      }

      // otherwise [9]
      else
      {
        // tell elevator to go idle [9]
        elevators[i]->setIdle();
      }
    }
  }

  // FLOOR ACTIONS [2]
  // check each floor (for waiting riders) [2]
  for(int l = 0; l < level.size(); l++)
  {
    // if there are no riders waiting on this floor, continue with next floor [2]
    if(level[l]->hasRidersWaiting())
    {
    // look at each elevator to see if it needs to be sent here [2]
      for(int e = 0; e < elevators.size(); e++)
      {
        // get elevator's relative location (negative if elevator is below floor) [2]
        int relativeLocation = elevators[e]->getLocation() - level[l]->getLocation();
        // if this elevator's idle... [2]
        if(elevators[e]->isIdle())
        {
          // if elevator is above the floor, set elevator direction to down [2]
          if(relativeLocation > 0)elevators[e]->setDirectionDown();
          // otherwise if it's below, set elevator direction to up [2]
          else elevators[e]->setDirectionUp();
          // set elevator's destination to this floor [2]
          elevators[e]->setDestination(level[l]);
          // tell elevator to close its door [2]
          elevators[e]->closeDoor();
        }

      // else if there are riders on this floor waiting to go up, and the elevator is going up... [10]
        else if(level[l]->hasUpRiders() && elevators[e]->isDirectionUp())
        {
          // get distance from elevator's destination floor to this floor (positive if elevator destination is above this floor) [10]
          int getUpDistance = elevators[e]->getDestination().getLocation() - level[l]->getLocation();
          // if elevator is below floor and elevator destination is above this floor [10]
          if(relativeLocation < 0 && getUpDistance > 0)
          {
            // set elevator's destination to this floor [10]
            elevators[e]->setDestination(level[l]);
          }

        }
        // else if there are riders on this floor waiting to go down, and the elevator is going down... [10]
        else if(level[l]->hasDownRiders() && elevators[e]->isDirectionDown())
        {
          // get distance from elevator's destination floor to this floor (negative if elevator destination is below this floor) [10]
          int getDownDistance = elevators[e]->getDestination().getLocation() - level[l]->getLocation();
          // if elevator is above floor and elevator destination is below this floor [10]
          if(relativeLocation > 0 && getDownDistance < 0)
          {
            // set elevator's destination to this floor [10]
            elevators[e]->setDestination(level[l]);
          }

        }
      }
    }
  }
  time++;
  return *this;
}
