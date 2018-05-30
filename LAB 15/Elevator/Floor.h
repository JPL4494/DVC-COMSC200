/*
Lab 14, The elevator program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

class Rider;
class Elevator;

class Floor
{
  const string NAME; /// name of floor, for example: Mezzanine
  const int location; /// inches above ground level
  vector<Rider> upRiders; /// affected by addNewRider, removeUpRiders,...
  vector<Rider> downRiders; /// ...and removeDownRiders functions

  public:
  Floor(const int, const char* const = "unnamed"); /// name and location (inches above ground) of floor

  /// inline functions
  int getLocation() const {return location;};
  bool hasRidersWaiting() const {if(upRiders.size() > 0 || downRiders.size() > 0)return true; else return false;};
  bool hasUpRiders() const {if(upRiders.size() > 0)return true; else return false;};
  bool hasDownRiders() const {if(downRiders.size() > 0)return true; else return false;};
  int getUpRiderCount() const {return (upRiders.size());};
  int getDownRiderCount() const {return (downRiders.size());};
  string getName() const {return NAME;};

  /// non-inline functions
  bool isPreferredDirectionUp() const; /// based on Rider with smallest ID
  void addNewRider(const Rider&); /// add to up- or down-vector
  vector<Rider> removeUpRiders(int); /// int is max #of riders...
  vector<Rider> removeDownRiders(int); ///...to move onto elevator

  /// just in case you prefer to use "if (...== *toFloor)"
  ///  in Elevator::removeRidersForDestinationFloor(), instead of "...== toFloor)"
  bool operator==(const Floor& floor) const {return NAME == floor.NAME;}

  friend ostream& operator<<(ostream&, const Floor&); /// say name, location, #'s of up/down riders waiting
};

#endif // FLOOR_H_INCLUDED
