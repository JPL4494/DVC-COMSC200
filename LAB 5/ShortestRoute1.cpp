/*
Lab 5b, The first version of the shortest route Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

#include<cstdlib>

class Leg
{
  const char* const city1;
  const char* const city2;
  const double distance;

public:
  Leg(const char* const, const char* const, const double);
  friend void printLeg(ostream&, const Leg&);
};

Leg::Leg(const char* const cityA, const char* const cityB, const double d)
:city1(cityA), city2(cityB), distance(d)
{}

void printLeg(ostream& out, const Leg& temp)
{
  out << "From " << temp.city1 << " to " << temp.city2 << " " << temp.distance << " miles" << endl ;
}

int main()
{
  cout << "Lab 5b, The shortest route Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Leg leg1("Concord", "San Francisco", 30.8);
  printLeg(cout, leg1);

  Leg leg2("San Francisco", "San Jose", 47.8);
  printLeg(cout, leg2);

  Leg leg3("San Jose", "Santa Cruz", 32.7);
  printLeg(cout, leg3);

  Leg leg4("Santa Cruz", "Monterey", 42.3);
  printLeg(cout, leg4);

  Leg leg5("Monterey", "Santa Barbara", 235);
  printLeg(cout, leg5);

  cout << endl << endl;
}
