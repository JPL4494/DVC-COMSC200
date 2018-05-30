/*
Lab 13, The geometry homework Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: Visual Studio
*/

#include "stdafx.h"

#include<iostream>
using std::endl;
using std::ios;

#include<iomanip>
using std::setprecision;

#include<cstdlib>
#include "GeometryHomework.h"

const float pi = 3.14159265359;

JPL::Shape::Shape(const char* const token[])
:x(token[1] ? atof(token[1]) : 0), y(token[2] ? atof(token[2]) : 0), z(token[3] ? atof(token[3]) : 0)
{}

JPL::Square::Square(const char* const token[])
: Shape(token)
{}

JPL::Rectangle::Rectangle(const char* const token[])
: Shape(token)
{}

JPL::Circle::Circle(const char* const token[])
: Shape(token)
{}

JPL::Cube::Cube(const char* const token[])
: Square(token)
{}

JPL::Prism::Prism(const char* const token[])
: Rectangle(token)
{}

JPL::Cylinder::Cylinder(const char* const token[])
: Circle(token)
{}

ostream& reset(ostream& out)
{
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  return out;
}

ostream& set(ostream& out)
{
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  return out;
}

void JPL::Square::print(ostream& out) const
{
  double area, per;

  area = x * x;
  per = 4 * x;

  out << "SQUARE side=" << x << " area=";
  out << set << area << " perimeter=" << per;
  out << endl;
  out << reset;
}

void JPL::Rectangle::print(ostream& out) const
{
  double area, per;

  area = x * y;
  per = (2 * x) + (2 * y);

  out << "RECTANGLE length=" << x << " width=" << y << " area=";
  out << set << area << " perimeter=" << per;
  out << endl;
  out << reset;
}

void JPL::Circle::print(ostream& out) const
{
  double area, cir;

  area = pi * x * x;
  cir = 2 * pi * x;

  out << "CIRCLE radius=" << x << " area=";
  out << set << area << " circumference=" << cir;
  out << endl;
  out << reset;
}

void JPL::Cube::print(ostream& out) const
{
  double sa, v;

  v = x * x * x;
  sa = 6 * x * x;

  out << "CUBE side=" << x  << " surface area=";
  out << set << sa << " volume=" << v;
  out << endl;
  out << reset;
}

void JPL::Prism::print(ostream& out) const
{
  double sa, v;

  v = x * y * z;
  sa = (2 * x * y) + (2 * y * z) + (2 * x * z);

  out << "PRISM length=" << x << " width=" << y << " height=" << z << " surface area=";
  out << set << sa << " volume=" << v;
  out << endl;
  out << reset;
}

void JPL::Cylinder::print(ostream& out) const
{
  double sa, v;

  v = pi * x * x * y;
  sa = (2 * pi * x * x) + (2 * pi * x * y);

  out << "CYLINDER radius=" << x << " height=" << y << " surface area=";
  out << set << sa << " volume=" << v;
  out << endl;
  out << reset;
}
