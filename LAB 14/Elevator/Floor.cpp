/*
Lab 14, The elevator program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include <iostream>
using std::endl;

#include "Floor.h"
#include "Rider.h"

Floor::Floor(const int x, const char* const label)
:NAME(label), location(x)
{}

bool Floor::isPreferredDirectionUp() const
{
  if(downRiders.size() == 0) return true;
  if(upRiders.size() == 0) return false;
  if(upRiders[0] < downRiders[0]) return true;
  else return false;
}

void Floor::addNewRider(const Rider& r)
{
  if(r.getDestination().getLocation() < getLocation()) downRiders.push_back(r);

  else upRiders.push_back(r);
}

vector <Rider> Floor::removeUpRiders(int total)
{
  vector <Rider> stay;
  vector <Rider> leave;

  if(upRiders.size() == 0) return leave;

  for(int i = 0; i < upRiders.size(); i++)
  {
    if(i <= total) leave.push_back(upRiders[i]);
    else stay.push_back(upRiders[i]);
  }

  upRiders = stay;

  return leave;
}

vector<Rider> Floor::removeDownRiders(int total)
{
  vector <Rider> stay;
  vector <Rider> leave;

  if(downRiders.size() == 0) return leave;

  for(int i = 0; i < downRiders.size(); i++)
  {
    if(i <= total) leave.push_back(downRiders[i]);
    else stay.push_back(downRiders[i]);
  }

  downRiders = stay;

  return leave;
}

ostream& operator<<(ostream& out, const Floor& floor)
{
  out << "Name: " << floor.NAME << " Location: " << floor.location << " UpRiders: " << floor.upRiders.size()
    << " DownRiders: " << floor.downRiders.size() << endl;

    return out;
}
