/*
Term Project, The final version of the shortest route Program
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

#include<vector>
using std::vector;

#include<cassert>

class Route;
class ShortestRoute;

class Leg
{
  const string city1;
  const string city2;
  const double distance;

public:
  Leg(const string, const string, const double = 0);
  friend class Route;
  friend class ShortestRoute;
  friend ostream& operator<<(ostream&, const Leg&);
  friend ostream& operator<<(ostream&, const Route&);
  void operator=(const Leg&){assert(false);}
};

Leg::Leg(const string cityA, const string cityB, const double d)
:city1(cityA), city2(cityB), distance(d)
{}

ostream& operator<<(ostream& out, const Leg& temp)
{
  out << "From " << temp.city1 << " to " << temp.city2 << " " << temp.distance << " miles" << endl ;
  return out;
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
  void operator=(const Route&){assert(false);}

  friend ostream& operator<<(ostream&, const Route&);

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

ostream& operator<<(ostream& out, const Route& r)
{
  out << "From " << (r.leg[0]) -> city1;
  for(int i = 0; i < r.counter; i++)
  {
    out << " to ";
    out << (r.leg[i]) -> city2;
  }
  out << ", Distance: " << r.distance << endl;
  return out;
}

class ShortestRoute
{
public:
  static const Leg Network [];
  static const Route getAnyRoute(const string, const string);
  static const Route getShortestRoute(const string, const string);
};

const Leg ShortestRoute::Network[] =
{
  Leg("San Francisco","Reno",218),
  Leg("San Francisco","Bakersfield",283),
  Leg("San Francisco","Redding",217),
  Leg("Redding","Portland",422),
  Leg("Redding","Elko",484),
  Leg("Bakersfield","Phoenix",483),
  Leg("Bakersfield","Las Vegas",293),
  Leg("Reno","St. George",535),
  Leg("Reno","Elko",289),
  Leg("Baltimore","New York City",191),
  Leg("Syracuse","New York City",246),
  Leg("Johnstown","New York City",303),
  Leg("St. George","Payson",245),
  Leg("St. George","Clifton",394),
  Leg("Clifton","Denver",237),
  Leg("Clifton","Pueblo",284),
  Leg("Denver","Kearney",359),
  Leg("Denver","Hays",338),
  Leg("Hays","Kansas City",265),
  Leg("Hays","Lincoln",280),
  Leg("Kansas City","St. Louis",251),
  Leg("Kansas City","Iowa City",251),
  Leg("Iowa City","Indianapolis",361),
  Leg("Iowa City","St. Louis",261),
  Leg("Indianapolis","Akron",299),
  Leg("Indianapolis","Pittsburgh",359),
  Leg("Pittsburgh","Johnstown",67.1),
  Leg("Pittsburgh","Baltimore",249),
  Leg("Elko","Butte",526),
  Leg("Elko","Rock Springs",411),
  Leg("Rock Springs","Denver",333),
  Leg("Portland","Spokane",351),
  Leg("Portland","Walla Walla",242),
  Leg("Spokane","Butte",315),
  Leg("Spokane","Great Falls",365),
  Leg("Butte","Miles City",370),
  Leg("Butte","Sheridan",355),
  Leg("Sheridan","Rapid City",243),
  Leg("Sheridan","Cheyenne",324),
  Leg("Cheyenne","North Platte",222),
  Leg("North Platte","Kansas City",415),
  Leg("Rapid City","Watertown",359),
  Leg("Rapid City","Bismark",324),
  Leg("Miles City","Bismark",272),
  Leg("Bismark","Bemidji",326),
  Leg("Bismark","Minneapolis",426),
  Leg("Minneapolis","Oshkosh",274),
  Leg("Bemidji","Oshkosh",483),
  Leg("Oshkosh","Chicago",175),
  Leg("Chicago","Akron",366),
  Leg("Akron","Johnstown",172),
  Leg("Akron","Syracuse",356),
  Leg("Great Falls","Williston",416),
  Leg("Williston","Bismark",228),
  Leg("Williston","Bemidji",450),
  Leg("Walla Walla","Boise",253),
  Leg("Boise","Rock Springs",480),
  Leg("Rock Springs","Cheyenne",257),
  Leg("Las Vegas","Flagstaff",249),
  Leg("Las Vegas","Phoenix",286),
  Leg("Flagstaff","Santa Fe",383),
  Leg("Flagstaff","Alamogordo",461),
  Leg("Phoenix","Alamogordo",454),
  Leg("Alamogordo","Abilene",400),
  Leg("Alamogordo","Amarillo",349),
  Leg("Santa Fe","Amarillo",279),
  Leg("Amarillo","Wichita",352),
  Leg("Amarillo","Oklahoma City",259),
  Leg("Abilene","Oklahoma City",291),
  Leg("Abilene","Houston",354),
  Leg("Wichita","Kansas City",197),
  Leg("Wichita","Springfield",247),
  Leg("Oklahoma City","Springfield",286),
  Leg("Oklahoma City","Little Rock",339),
  Leg("Houston","Little Rock",435),
  Leg("Houston","Hattiesburg",436),
  Leg("Springfield","St. Louis",216),
  Leg("St. Louis","Indianapolis",242),
  Leg("Springfield","Nashville",431),
  Leg("Little Rock","Nashville",349),
  Leg("Little Rock","Montgomery",462),
  Leg("Hattiesburg","Montgomery",249),
  Leg("Nashville","Asheville",294),
  Leg("Nashville","Ironville",329),
  Leg("Montgomery","Asheville",367),
  Leg("Asheville","Richmond",373),
  Leg("Ironville","Richmond",389),
  Leg("Richmond","Baltimore",147),
  Leg("Las Vegas","Elko",431),
  Leg("Las Vegas","St. George",120),
  Leg("Flagstaff","Pueblo",656),
  Leg("St. George","Rock Springs",461),
  Leg("Rock Springs","Denver",333),
  Leg("Santa Fe","Denver",390),
  Leg("Amarillo","Hays",349),
  Leg("Santa Fe","Hays",525),
  Leg("Bakersfield","Boise",826),
  Leg("Boise","Butte",420),
  Leg("Rock Springs","Sheridan",372),
  Leg("Boise","Sheridan",667),
  Leg("Rapid City","Kearney",423),
  Leg("Kearney","Iowa City",430),
  Leg("Rapid City","Iowa City",726),
  Leg("Minneapolis","Iowa City",303),
  Leg("Iowa City","Indianapolis",361),
  Leg("Kansas City","Ironville",583),
  Leg("Indianapolis","Ironville",190),
  Leg("Richmond","Pittsburgh",344),
  Leg("Pueblo","Denver",113),
  Leg("San Francisco","New York City",21000)
};


const Route ShortestRoute::getAnyRoute(const string from, const string to)
{
  for(int i = 0; i < 110; i++)
  {
    if(Network[i].city2 == to)
    {
      if(Network[i].city1 == from)
      {
        return Route(Network[i]);
      }

      else
      {
        return Route(getAnyRoute(from, Network[i].city1),Network[i]);
      }
    }
  }
}

const Route ShortestRoute::getShortestRoute(const string from, const string to)
{
  vector <Route> result;

  for(int i = 0; i < 110; i++)
  {
    if(Network[i].city2 == to)
    {
      if(Network[i].city1 == from)result.push_back(Network[i]);

      else
      {
        result.push_back(Route(getShortestRoute(from, Network[i].city1),Network[i]));
      }
    }
  }

  if(result.size() == 0)
  {cout << from << " " << to << endl;
    throw "ERROR!";
  }

  Route temp(result[0]);
  int finder = 0;
  int compare = 0;

  for(int i = 0; i < result.size(); i++)
  {
    if(result[i].isGreaterThan(temp) == false)
    {
      compare = i;
      if(result[finder].isGreaterThan(result[compare]) == true)
      {
        finder = compare;

      }
    }
  }
  return Route(result[finder]);
}

int main()
{
  cout << "Term Project, The shortest route Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << ShortestRoute::getAnyRoute("San Francisco", "New York City") << endl;
  cout << ShortestRoute::getShortestRoute("San Francisco", "New York City");

  cout << endl << endl;
}
