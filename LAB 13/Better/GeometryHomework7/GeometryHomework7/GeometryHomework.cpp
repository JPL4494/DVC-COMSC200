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

Shape::Shape(const char* const token[])
:x(token[1] ? atof(token[1]) : 0), y(token[2] ? atof(token[2]) : 0), z(token[3] ? atof(token[3]) : 0)
{}

Square::Square(const char* const token[])
: Shape(token)
{}

JPL::Rectangle::Rectangle(const char* const token[])
: Shape(token)
{}

Circle::Circle(const char* const token[])
: Shape(token)
{}

Cube::Cube(const char* const token[])
: Square(token)
{}

Prism::Prism(const char* const token[])
: Rectangle(token)
{}

Cylinder::Cylinder(const char* const token[])
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

void Square::print(ostream& out) const
{
  double area, per;

  area = x * x;
  per = 4 * x;

  out << "side= " << x << endl << "area= ";
  out << set << area << endl << "perimeter= " << per;
  out << endl;
  out << reset;
}

void JPL::Rectangle::print(ostream& out) const
{
  double area, per;

  area = x * y;
  per = (2 * x) + (2 * y);

  out << "length= " << x << endl << "width= " << y << endl << "area= ";
  out << set << area << endl << "perimeter= " << per;
  out << endl;
  out << reset;
}

void Circle::print(ostream& out) const
{
  double area, cir;

  area = pi * x * x;
  cir = 2 * pi * x;

  out << "radius= " << x << endl << "area= ";
  out << set << area << endl << "circumference= " << cir;
  out << endl;
  out << reset;
}

void Cube::print(ostream& out) const
{
  double sa, v;

  v = x * x * x;
  sa = 6 * x * x;

  out << "side= " << x << endl  << "surface area= ";
  out << set << sa << endl << "volume= " << v;
  out << endl;
  out << reset;
}

void Prism::print(ostream& out) const
{
  double sa, v;

  v = x * y * z;
  sa = (2 * x * y) + (2 * y * z) + (2 * x * z);

  out << "length= " << x << endl << "width= " << y << endl << "height= " << z << endl << "surface area=";
  out << set << sa << endl << "volume= " << v;
  out << endl;
  out << reset;
}

void Cylinder::print(ostream& out) const
{
  double sa, v;

  v = pi * x * x * y;
  sa = (2 * pi * x * x) + (2 * pi * x * y);

  out << "radius= " << x << endl << "height= " << y << endl << "surface area= ";
  out << set << sa << endl << "volume= " << v;
  out << endl;
  out << reset;
}
