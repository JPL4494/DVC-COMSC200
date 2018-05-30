/*
Lab 3b, The third version of the geometry homework Program
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
  double side;

public:
  Square(const char* []);
  void print();
};

Square::Square(const char* token[])
{
  side = token[1] ? atof(token[1]) : 0;
}

class Rectangle
{
  double length;
  double width;

public:
  Rectangle(const char* []);
  void print();
};

Rectangle::Rectangle(const char* token[])
{
  length = token[1] ? atof(token[1]) : 0;
  width = token[2] ? atof(token[2]) : 0;
}

class Circle
{
  double radius;

public:
  Circle(const char* []);
  void print();
};

Circle::Circle(const char* token[])
{
  radius = token[1] ? atof(token[1]) : 0;
}

class Cube
{
  double side;

public:
  Cube(const char* []);
  void print();
};

Cube::Cube(const char* token[])
{
  side = token[1] ? atof(token[1]) : 0;
}

class Prism
{
  double length;
  double width;
  double height;

public:
  Prism(const char* []);
  void print();
};

Prism::Prism(const char* token[])
{
  length = token[1] ? atof(token[1]) : 0;
  width = token[2] ? atof(token[2]) : 0;
  height = token[3] ? atof(token[3]) : 0;
}

class Cylinder
{
  double radius;
  double height;

public:
  Cylinder(const char* []);
  void print();
};

Cylinder::Cylinder(const char* token[])
{
  radius = token[1] ? atof(token[1]) : 0;
  height = token[2] ? atof(token[2]) : 0;
}

int main()
{
  fstream source;
  source.open("geo.txt", ios::in);

  cout << "Lab 3b, The geometry homework Program" << endl;
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

    const char * token[MAX_TOKENS_PER_LINE] = {};

    token[0] = strtok(buf, DELIMITER);

    if (token[0])
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER);

        if (!token[n])
        {
          break;
        }
      }

      if (strstr(token[0],"SQUARE"))
      {
        shapeID[counter] = 1;
        Square* s = new Square(token);
        shapes[counter] = s;
        counter++;
      }
      if (strstr(token[0],"RECTANGLE"))
      {
        shapeID[counter] = 2;
        Rectangle* r = new Rectangle(token);
        shapes[counter] = r;
        counter++;
      }
      if (strstr(token[0],"CIRCLE"))
      {
        shapeID[counter] = 3;
        Circle* c = new Circle(token);
        shapes[counter] = c;
        counter++;
      }
      if (strstr(token[0],"CUBE"))
      {
        shapeID[counter] = 4;
        Cube* c = new Cube(token);
        shapes[counter] = c;
        counter++;
      }
      if (strstr(token[0],"PRISM"))
      {
        shapeID[counter] = 5;
        Prism* p = new Prism(token);
        shapes[counter] = p;
        counter++;
      }
      if (strstr(token[0],"CYLINDER"))
      {
        shapeID[counter] = 6;
        Cylinder* c = new Cylinder(token);
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
      Square* s = (Square*) shapes[i];
      s->print();
      cout << endl;
    }

    if (shapeID[i] == 2)
    {
      Rectangle* r = (Rectangle*) shapes[i];
      r->print();
      cout << endl;
    }

    if (shapeID[i] == 3)
    {
      Circle* c = (Circle*) shapes[i];
      c->print();
      cout << endl;
    }

    if (shapeID[i] == 4)
    {
      Cube* c = (Cube*) shapes[i];
      c->print();
      cout << endl;
    }

    if (shapeID[i] == 5)
    {
      Prism* p = (Prism*) shapes[i];
      p->print();
      cout << endl;
    }

    if (shapeID[i] == 6)
    {
      Cylinder* c = (Cylinder*) shapes[i];
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

void Square::print()
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

void Rectangle::print()
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

void Circle::print()
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

void Cube::print()
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

void Prism::print()
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

void Cylinder::print()
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
