/*
Lab 4b, The fourth version of the geometry homework Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;
using std::ios;

#include <fstream>
using std::fstream;

#include<iomanip>
using std::setprecision;

#include<string>
using std::string;

#include<cstdlib>
#include<cstring>

const float pi = 3.14159265359;
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char * const DELIMITER = " ";

class Square
{
  const double side;

public:
  Square(const char* const []);
  void print() const;
};

Square::Square(const char* const token[])
: side(token[1] ? atof(token[1]) : 0)
{}

class Rectangle
{
  const double length;
  const double width;

public:
  Rectangle(const char* const []);
  void print() const;
};

Rectangle::Rectangle(const char* const token[])
: length(token[1] ? atof(token[1]) : 0), width(token[2] ? atof(token[2]) : 0)
{}

class Circle
{
  const double radius;

public:
  Circle(const char* const []);
  void print() const;
};

Circle::Circle(const char* const token[])
: radius(token[1] ? atof(token[1]) : 0)
{}

class Cube
{
  const double side;

public:
  Cube(const char* const []);
  void print() const;
};

Cube::Cube(const char* const token[])
: side(token[1] ? atof(token[1]) : 0)
{}

class Prism
{
  const double length;
  const double width;
  const double height;

public:
  Prism(const char* const []);
  void print() const;
};

Prism::Prism(const char* const token[])
: length(token[1] ? atof(token[1]) : 0), width(token[2] ? atof(token[2]) : 0), height(token[3] ? atof(token[3]) : 0)
{}

class Cylinder
{
  const double radius;
  const double height;

public:
  Cylinder(const char* const []);
  void print() const;
};

Cylinder::Cylinder(const char* const token[])
: radius(token[1] ? atof(token[1]) : 0), height(token[2] ? atof(token[2]) : 0)
{}

int main()
{
  fstream source;
  source.open("geo.txt", ios::in);

  cout << "Lab 4b, The geometry homework Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  int counter = 0;
  int shapeID[100];
  const void * shapes[100];

  if (source.fail())
  {
    cout << "ERROR-No file to get information from!";
    exit(EXIT_FAILURE);
  }

  while (!source.eof())
  {
    char buf [MAX_CHARS_PER_LINE];
    source.getline(buf, MAX_CHARS_PER_LINE);

    int n = 0;

    const char * const token [] = {strtok(buf, DELIMITER), strtok(0, DELIMITER), strtok(0, DELIMITER), strtok(0, DELIMITER)};

    if (token[0])
    {
      if (strstr(token[0],"SQUARE"))
      {
        shapeID[counter] = 1;
        const Square* const s = new Square(token);
        shapes[counter] = s;
        counter++;
      }
      if (strstr(token[0],"RECTANGLE"))
      {
        shapeID[counter] = 2;
        const Rectangle* const r = new Rectangle(token);
        shapes[counter] = r;
        counter++;
      }
      if (strstr(token[0],"CIRCLE"))
      {
        shapeID[counter] = 3;
        const Circle* const c = new Circle(token);
        shapes[counter] = c;
        counter++;
      }
      if (strstr(token[0],"CUBE"))
      {
        shapeID[counter] = 4;
        const Cube* const c = new Cube(token);
        shapes[counter] = c;
        counter++;
      }
      if (strstr(token[0],"PRISM"))
      {
        shapeID[counter] = 5;
        const Prism* const p = new Prism(token);
        shapes[counter] = p;
        counter++;
      }
      if (strstr(token[0],"CYLINDER"))
      {
        shapeID[counter] = 6;
        const Cylinder* const c = new Cylinder(token);
        shapes[counter] = c;
        counter++;
      }
    }
  }
  source.close();

  for (int i = 0; i < counter; i++)
  {
    if (shapeID[i] == 1)
    {
      const Square* const s = (Square*) shapes[i];
      s->print();
      cout << endl;
    }

    if (shapeID[i] == 2)
    {
      const Rectangle* const r = (Rectangle*) shapes[i];
      r->print();
      cout << endl;
    }

    if (shapeID[i] == 3)
    {
      const Circle* const c = (Circle*) shapes[i];
      c->print();
      cout << endl;
    }

    if (shapeID[i] == 4)
    {
      const Cube* const c = (Cube*) shapes[i];
      c->print();
      cout << endl;
    }

    if (shapeID[i] == 5)
    {
      const Prism* const p = (Prism*) shapes[i];
      p->print();
      cout << endl;
    }

    if (shapeID[i] == 6)
    {
      const Cylinder* const c = (Cylinder*) shapes[i];
      c->print();
      cout << endl;
    }
  }

  for (int i = 0; i < counter; i++)
  {
    if (shapeID[i] == 1)
    {
      delete (Square*)shapes[i];
    }

    if (shapeID[i] == 2)
    {
      delete (Rectangle*)shapes[i];
    }

    if (shapeID[i] == 3)
    {
      delete (Circle*)shapes[i];
    }

    if (shapeID[i] == 4)
    {
      delete (Cube*)shapes[i];
    }

    if (shapeID[i] == 5)
    {
      delete (Prism*)shapes[i];
    }

    if (shapeID[i] == 6)
    {
      delete (Cylinder*)shapes[i];
    }
  }
  cout << endl << endl;
}

void Square::print() const
{
  double area, per;

  area = side * side;
  per = 4 * side;

  cout << "SQUARE side=" << side << " area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << area << " perimeter=" << per;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void Rectangle::print() const
{
  double area, per;

  area = length * width;
  per = (2 * length) + (2 * width);

  cout << "RECTANGLE length=" << length << " width=" << width << " area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << area << " perimeter=" << per;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void Circle::print() const
{
  double area, cir;

  area = pi * radius * radius;
  cir = 2 * pi * radius;

  cout << "CIRCLE radius=" << radius << " area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << area << " circumference=" << cir;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void Cube::print() const
{
  double sa, v;

  v = side * side * side;
  sa = 6 * side * side;

  cout << "CUBE side=" << side  << " surface area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << sa << " volume=" << v;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void Prism::print() const
{
  double sa, v;

  v = length * width * height;
  sa = (2 * length * width) + (2 * width * height) + (2 * length * height);

  cout << "PRISM length=" << length << " width=" << width << " height=" << height << " surface area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << sa << " volume=" << v;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void Cylinder::print() const
{
  double sa, v;

  v = pi * radius * radius * height;
  sa = (2 * pi * radius * radius) + (2 * pi * radius * height);

  cout << "CYLINDER radius=" << radius << " height=" << height << " surface area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << sa << " volume=" << v;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}
