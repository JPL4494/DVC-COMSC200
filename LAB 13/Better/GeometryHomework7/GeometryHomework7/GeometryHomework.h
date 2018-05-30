/*
Lab 13, The geometry homework Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: Visual Studio
*/

#include "stdafx.h"

#include<iostream>
using std::ostream;

#ifndef GEOMETRYHOMEWORK_H_INCLUDED
#define GEOMETRYHOMEWORK_H_INCLUDED

struct Shape
{
	const double x, y, z;
	Shape(const char* const[]);
	friend ostream& operator<<(ostream& out, const Shape* s){ s->print(out); return out; }
	virtual void print(ostream&) const = 0;
	virtual ~Shape(){}
};

struct Square : public Shape
{
	Square(const char* const[]);
	void print(ostream&) const;
};

namespace JPL
{
  struct Rectangle : public Shape
  {
    Rectangle(const char* const []);
    void print(ostream&) const;
  };
}

struct Circle : public Shape
{
	Circle(const char* const[]);
	void print(ostream&) const;
};

  struct Cube : public Square
{
	Cube(const char* const[]);
	void print(ostream&) const;
};

struct Prism : public JPL::Rectangle
{
	Prism(const char* const[]);
	void print(ostream&) const;
};

struct Cylinder : public Circle
{
	Cylinder(const char* const[]);
	void print(ostream&) const;
};


#endif // GEOMETRYHOMEWORK_H_INCLUDED
