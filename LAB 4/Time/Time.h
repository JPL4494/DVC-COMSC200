#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

/*
Lab 4a, The time Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

class Time
{
public:
  Time(int=0, int=0, int=0);

  void setTime(int,int,int);
  void setHour(int);
  void setMinute(int);
  void setSecond(int);

  int getHour() const;
  int getMinute() const;
  int getSecond() const;

  void printUniversal() const;
  void printStandard() const;

private:
  int hour;
  int minute;
  int second;
};

#endif

#ifdef TIME_H_INCLUDED
#endif
