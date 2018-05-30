/*
Lab 15, The elevator program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

class Floor;
class Elevator;

class Building
{
  int time;
  vector <Floor*> level;
  vector <Elevator*> elevators;

public:
  Building();
  ~Building();
  friend ostream& operator<<(ostream&, const Building &);

  int getFloorCount() const{return level.size();} /// return #of floors in the vector of Floor*'s
  int getElevatorCount() const{return elevators.size();} /// return #of elevators in the vector of Elevator*'s
  const Floor& getFloor(int index) const{return *level[index];} /// return a reference to the "indexth" floor
  const Elevator& getElevator(int index) const{return *elevators[index];} /// return a reference to the "indexth" elevator
  void getDifferentInts(int, int&, int&);
  Building& step(int);
};

#endif // BUILDING_H_INCLUDED
