/*
Lab 16, The elevator program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

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
  int ticker = 0;
  int average = rand() % 5;

  cout << "Press enter to enter building loop" << endl;

  while(cin)
  {
    if((ticker % 1 == 0))
    {
      cout << "Press ENTER to continue, X-ENTER to quit...\n";
      if(cin.get() == 'X')break;
      system("CLS");
    }

    cout << building.step(average) << endl;
    if(average == 0 || average > 12)average = rand() % 5;
    average = getArrivalsForThisSecond(average);
    ticker++;
  }

  cout << building << endl << endl;
}
