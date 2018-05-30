/*
Lab 12, The geometry homework Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <fstream>
using std::fstream;

#include<iomanip>
using std::setprecision;

#include<string>
using std::string;

#include <vector>
using std::vector;

#include<cstdlib>
#include<cstring>

const float pi = 3.14159265359;
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char * const DELIMITER = " ";

struct Shape
{
  const double x, y, z;
  Shape(const char* const []);
  friend ostream& operator<<(ostream& out, const Shape* s){s->print(out); return out;}
  virtual void print(ostream&) const = 0;
  virtual ~Shape(){}
};

Shape::Shape(const char* const token[])
:x(token[1] ? atof(token[1]) : 0), y(token[2] ? atof(token[2]) : 0), z(token[3] ? atof(token[3]) : 0)
{}

struct Square : public Shape
{
  Square(const char* const []);
  void print(ostream&) const;
};

Square::Square(const char* const token[])
: Shape(token)
{}

struct Rectangle : public Shape
{
  Rectangle(const char* const []);
  void print(ostream&) const;
};

Rectangle::Rectangle(const char* const token[])
: Shape(token)
{}

struct Circle : public Shape
{
  Circle(const char* const []);
  void print(ostream&) const;
};

Circle::Circle(const char* const token[])
: Shape(token)
{}

struct Cube : public Square
{
  Cube(const char* const []);
  void print(ostream&) const;
};

Cube::Cube(const char* const token[])
: Square(token)
{}

struct Prism : public Rectangle
{
  Prism(const char* const []);
  void print(ostream&) const;
};

Prism::Prism(const char* const token[])
: Rectangle(token)
{}

struct Cylinder : public Circle
{
  Cylinder(const char* const []);
  void print(ostream&) const;
};

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

int main()
{
  fstream source;
  source.open("geo.txt", ios::in);

  cout << "Lab 12, The geometry homework Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  vector <const Shape*> shapes;

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
        const Square* const s = new Square(token);
        shapes.push_back(s);
      }
      if (strstr(token[0],"RECTANGLE"))
      {
        const Rectangle* const r = new Rectangle(token);
        shapes.push_back(r);
      }
      if (strstr(token[0],"CIRCLE"))
      {
        const Circle* const c = new Circle(token);
        shapes.push_back(c);
      }
      if (strstr(token[0],"CUBE"))
      {
        const Cube* const c = new Cube(token);
        shapes.push_back(c);
      }
      if (strstr(token[0],"PRISM"))
      {
        const Prism* const p = new Prism(token);
        shapes.push_back(p);
      }
      if (strstr(token[0],"CYLINDER"))
      {
        const Cylinder* const c = new Cylinder(token);
        shapes.push_back(c);
      }
    }
  }
  source.close();

  for (int i = 0; i < shapes.size(); i++)
  {
    cout << shapes[i] << endl;
  }

  for (int i = 0; i < shapes.size(); i++)
  {
    delete shapes[i];
  }
  cout << endl << endl;
}

void Square::print(ostream& out) const
{
  double area, per;

  area = x * x;
  per = 4 * x;

  out << "SQUARE side=" << x << " area=";
  out << set << area << " perimeter=" << per;
  out << endl;
  out << reset;
}

void Rectangle::print(ostream& out) const
{
  double area, per;

  area = x * y;
  per = (2 * x) + (2 * y);

  out << "RECTANGLE length=" << x << " width=" << y << " area=";
  out << set << area << " perimeter=" << per;
  out << endl;
  out << reset;
}

void Circle::print(ostream& out) const
{
  double area, cir;

  area = pi * x * x;
  cir = 2 * pi * x;

  out << "CIRCLE radius=" << x << " area=";
  out << set << area << " circumference=" << cir;
  out << endl;
  out << reset;
}

void Cube::print(ostream& out) const
{
  double sa, v;

  v = x * x * x;
  sa = 6 * x * x;

  out << "CUBE side=" << x  << " surface area=";
  out << set << sa << " volume=" << v;
  out << endl;
  out << reset;
}

void Prism::print(ostream& out) const
{
  double sa, v;

  v = x * y * z;
  sa = (2 * x * y) + (2 * y * z) + (2 * x * z);

  out << "PRISM length=" << x << " width=" << y << " height=" << z << " surface area=";
  out << set << sa << " volume=" << v;
  out << endl;
  out << reset;
}

void Cylinder::print(ostream& out) const
{
  double sa, v;

  v = pi * x * x * y;
  sa = (2 * pi * x * x) + (2 * pi * x * y);

  out << "CYLINDER radius=" << x << " height=" << y << " surface area=";
  out << set << sa << " volume=" << v;
  out << endl;
  out << reset;
}
