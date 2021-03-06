#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Building.h"

int getArrivalsForThisSecond(double averageRiderArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageRiderArrivalRate); // for n=0 -- requires cmath
  for(double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib AND srand in main
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageRiderArrivalRate / ++arrivals);
  return arrivals;
}

int main()
{
  srand(time(0)); rand(); // requires cstdlib and ctime
  Building building;

  int average = rand() % 12;
  cout << average << endl;

  // add one rider per second for 10 seconds
  cout << "ENTERING FOR LOOP!\n";


  // continue the simulation for 600 more seconds (expect all riders to be gone by then)
  while(cin.get() != 'X')
  {
    cout << "Press ENTER to continue, X-ENTER to quit...\n";

    cout << building.step(average) << endl; // time-step with no riders added
    ///average = (average + getArrivalsForThisSecond(average)) % 30;
    ///average = getArrivalsForThisSecond(average);
    if(average == 0)average = rand() % 10;
    do{average = getArrivalsForThisSecond(average);}while(average > 3);
    cout << average << endl;
  }
  cout<< "DONE: All riders should be gone, and all elevators idle\n";
  cout << building << endl << endl;
}
