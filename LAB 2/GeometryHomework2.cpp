/*
Lab 2b, The second version og the geometry homework Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::cin;
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

struct Square
{
  double side;
};

struct Rectangle
{
  double length;
  double width;
};

struct Circle
{
  double radius;
};

struct Cube
{
  double side;
};

struct Prism
{
  double length;
  double width;
  double height;
};

struct Cylinder
{
  double radius;
  double height;
};

void printSquare(Square*);
void printRectangle(Rectangle*);
void printCircle(Circle*);
void printCube(Cube*);
void printPrism(Prism*);
void printCylinder(Cylinder*);

int main()
{
  fstream source;
  source.open("geo.txt", ios::in);

  cout << "Lab 2b, The geometry homework Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;


  int counter = 0;
  int shapeID[100], t[100];
  void * shapes[100];

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
        double temp = token[1] ? atof(token[1]) : 0;
        shapeID[counter] = 1;
        Square * s = new Square;
        s -> side = temp;
        shapes[counter] = s;
        counter++;
      }
      if (strstr(token[0],"RECTANGLE"))
      {
        double temp1 = token[1] ? atof(token[1]) : 0;
        double temp2 = token[2] ? atof(token[2]) : 0;
        shapeID[counter] = 2;
        Rectangle * r = new Rectangle;
        r -> length = temp1;
        r -> width = temp2;
        shapes[counter] = r;
        counter++;
      }
      if (strstr(token[0],"CIRCLE"))
      {
        double temp = token[1] ? atof(token[1]) : 0;
        shapeID[counter] = 3;
        Circle * c = new Circle;
        c -> radius = temp;
        shapes[counter] = c;
        counter++;
      }
      if (strstr(token[0],"CUBE"))
      {
        double temp = token[1] ? atof(token[1]) : 0;
        shapeID[counter] = 4;
        Cube * c = new Cube;
        c -> side = temp;
        shapes[counter] = c;
        counter++;
      }
      if (strstr(token[0],"PRISM"))
      {
        double temp1 = token[1] ? atof(token[1]) : 0;
        double temp2 = token[2] ? atof(token[2]) : 0;
        double temp3 = token[3] ? atof(token[3]) : 0;
        shapeID[counter] = 5;
        Prism * p = new Prism;
        p -> length = temp1;
        p -> width = temp2;
        p -> height = temp3;
        shapes[counter] = p;
        counter++;
      }
      if (strstr(token[0],"CYLINDER"))
      {
        double temp1 = token[1] ? atof(token[1]) : 0;
        double temp2 = token[2] ? atof(token[2]) : 0;
        shapeID[counter] = 6;

        Cylinder * c = new Cylinder;
        c -> radius = temp1;
        c -> height = temp2;
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
      printSquare((Square*)shapes[i]);
      cout << endl;
    }

    if (shapeID[i] == 2)
    {
      printRectangle((Rectangle*)shapes[i]);
      cout << endl;
    }

    if (shapeID[i] == 3)
    {
      printCircle((Circle*)shapes[i]);
      cout << endl;
    }

    if (shapeID[i] == 4)
    {
      printCube((Cube*)shapes[i]);
      cout << endl;
    }

    if (shapeID[i] == 5)
    {
      printPrism((Prism*)shapes[i]);
      cout << endl;
    }

    if (shapeID[i] == 6)
    {
      printCylinder((Cylinder*)shapes[i]);
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

void printSquare(Square* shapes)
{
  double side = ((Square*)shapes)->side;
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

void printRectangle(Rectangle* shapes)
{
  double length = ((Rectangle*)shapes)->length;
  double width = ((Rectangle*)shapes)->width;
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

void printCircle(Circle* shapes)
{
  double radius = ((Circle*)shapes)->radius;
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

void printCube(Cube* shapes)
{
  double side = ((Cube*)shapes)->side;
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

void printPrism(Prism* shapes)
{
  double length = ((Prism*)shapes)->length;
  double width = ((Prism*)shapes)->width;
  double height = ((Prism*)shapes)->height;
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

void printCylinder(Cylinder* shapes)
{
  double radius = ((Cylinder*)shapes)->radius;
  double height = ((Cylinder*)shapes)->height;
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
