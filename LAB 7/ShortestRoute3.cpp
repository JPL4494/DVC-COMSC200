/*
Lab 7b, The third version of the shortest route Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

#include<string>
using std::string;

class Route;

class Leg
{
  const string city1;
  const string city2;
  const double distance;

public:
  Leg(const string, const string, const double = 0);
  friend void printLeg(ostream&, const Leg&);
  friend class Route;
  friend void printRoute(ostream&, const Route&);
};

Leg::Leg(const string cityA, const string cityB, const double d)
:city1(cityA), city2(cityB), distance(d)
{}

void printLeg(ostream& out, const Leg& temp)
{
  out << "From " << temp.city1 << " to " << temp.city2 << " " << temp.distance << " miles" << endl ;
}

class Route
{
  const int counter;
  const double distance;
  const Leg** const leg;

public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  Route(const Route&);
  bool isGreaterThan(const Route&) const;

  friend void printRoute(ostream&, const Route&);

  ~Route() {delete [] leg;};
};

Route::Route(const Leg& l)
:counter(1), distance(l.distance), leg(new const Leg* [counter])
{
  int c = counter - 1;
  leg[c] = (&l);
}

Route::Route(const Route& r, const Leg& l)
:counter(r.counter+1), distance(l.distance+r.distance), leg(new const Leg* [counter])
{
  if(l.city1 != (r.leg[r.counter-1] -> city2))
  {
    delete [] leg;
    throw "CITY1 != CITY2";
  }

  for(int i = 0; i < r.counter; i++)
  {
    leg[i] = (r.leg[i]);
  }
  leg[r.counter] = (&l);
}

Route::Route(const Route& r)
:counter(r.counter), distance(r.distance), leg(new const Leg* [counter])
{
  for(int i = 0; i < r.counter; i++)
  {
    leg[i] = (r.leg[i]);
  }
}

bool Route::isGreaterThan(const Route& route) const
{
  if(distance > route.distance)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void printRoute(ostream& out, const Route& r)
{
  out << "From " << (r.leg[0]) -> city1;
  for(int i = 0; i < r.counter; i++)
  {
    out << " to ";
    out << (r.leg[i]) -> city2;
  }
  out << ", Distance: " << r.distance << endl;
}

int main()
{
  cout << "Lab 7b, The shortest route Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Leg a("Concord", "San Francisco", 30.8);
  Leg b("San Francisco", "San Jose", 47.8);
  Leg c("San Jose", "Santa Cruz", 32.7);
  Leg d("Santa Cruz", "Monterey", 42.3);
  Leg e("Monterey", "Santa Barbara", 235);

  cout << endl;

  Route ra(a);
  Route rb(ra, b);
  Route rc(rb, c);
  Route rd(rc, d);
  Route re(rd, e);
  printRoute(cout, re);

  {
    cout << endl << "Copying through inline decleration" << endl;
    Route rCopy = re;
    printRoute(cout,rCopy);
  }

  {
    cout << endl << "Testing copy function" << endl;
    Route reCopy(re);
    printRoute(cout,reCopy);
  }

  cout << endl << "Testing isGreaterThan member function between route a and b, expected false" << endl;
  if(ra.isGreaterThan((rb)))
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }

  cout << endl << "Testing isGreaterThan member function between route e and b, expected true" << endl;
  if(re.isGreaterThan((rb)))
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }

  cout << endl << "Testing isGreaterThan member function between route a and d, expected false" << endl;
  if(ra.isGreaterThan((rd)))
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }

  cout << endl << "Running throw and catch error, expected result ERROR: CITY1 != CITY2" << endl;

  try
  {
    Route(Route(Leg("a", "b", 0)), Leg("c", "d", 0));
  }
  catch (const char* ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }

  cout << endl << endl;
}
