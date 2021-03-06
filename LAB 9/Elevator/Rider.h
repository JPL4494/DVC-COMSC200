/*
Lab 8b, The elevator program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#ifndef RIDER_H_INCLUDED
#define RIDER_H_INCLUDED

class Floor;

class Rider
{
private:
  const int ID;
  const Floor* const destination;

public:
  Rider(const Floor &);
  friend bool operator< (const Rider&,const Rider&);
  friend bool operator== (const Rider&,const Rider&);
  const Floor& getDestination() const;
};

#endif // RIDER_H_INCLUDED
