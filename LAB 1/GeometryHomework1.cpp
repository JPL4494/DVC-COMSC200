/*
Lab 1b, The geomentry homework Program
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

#include<cstdlib>
#include<cstring>

const float pi = 3.14159265359;
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char * const DELIMITER = " ";

void square(float s = 0);
void rectangle(float w = 0,float l = 0);
void circle(float r = 0);
void cube(float s = 0);
void prism(float w = 0,float l = 0,float h = 0);
void cylinder(float r = 0,float h = 0);
void noFormula();

int main()
{
  fstream source;
  source.open("geo.txt", ios::in);

  cout << "Lab 1b, The geomentry homework Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

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
    }


    for (int i = 0; i < n; i++)
    {
    if (strstr(token[0],"SQUARE"))
    {
      if (token[1] > 0)
      {
        double temp = atof(token[1]);
        square(temp);
      }
      else
      {
        square();
      }
      n = 1;
    }

    else if (strstr(token[0],"RECTANGLE"))
    {
      if (token[1] > 0 && token[2] > 0)
      {
        double temp1 = atof(token[1]);
        double temp2 = atof(token[2]);
        rectangle(temp1,temp2);
      }
      else if (token[1] > 0 && token[2] == 0)
      {
        double temp1 = atof(token[1]);
        rectangle(temp1);
      }
      else if (token[1] == 0 && token[2] > 0)
      {
        double temp1 = atof(token[2]);
        rectangle(0,temp1);
      }
      else
      {
        rectangle();
      }
      n = 1;
    }

    else if (strstr(token[0],"CIRCLE"))
    {
      if (token[1] > 0)
      {
        double temp = atof(token[1]);
        circle(temp);
      }
      else
      {
        circle();
      }
      n = 1;
    }

    else if (strstr(token[0],"CUBE"))
    {
      if (token[1] > 0)
      {
        double temp = atof(token[1]);
        cube(temp);
      }
      else
      {
        cube();
      }
      n = 1;
    }

    else if (strstr(token[0],"PRISM"))
    {
      if (token[1] > 0 && token[2] > 0 && token[3] > 0)
      {
        double temp1 = atof(token[1]);
        double temp2 = atof(token[2]);
        double temp3 = atof(token[3]);
        prism(temp1,temp2,temp3);
      }
      else if (token[1] > 0 && token[2] > 0 && token[3] == 0)
      {
        double temp1 = atof(token[1]);
        double temp2 = atof(token[2]);
        prism(temp1,temp2);
      }
      else if (token[1] > 0 && token[2] == 0 && token[3] > 0)
      {
        double temp1 = atof(token[1]);
        double temp2 = atof(token[3]);
        prism(temp1,0,temp2);
      }
      else if (token[1] == 0 && token[2] > 0 && token[3] > 0)
      {
        double temp1 = atof(token[2]);
        double temp2 = atof(token[3]);
        prism(0,temp1,temp2);
      }
      else if (token[1] > 0 && token[2] == 0 && token[3] == 0)
      {
        double temp = atof(token[1]);
        prism(temp);
      }
      else if (token[1] == 0 && token[2] > 0 && token[3] == 0)
      {
        double temp = atof(token[2]);
        prism(0,temp);
      }
      else if (token[1] == 0 && token[2] == 0 && token[3] > 0)
      {
        double temp = atof(token[3]);
        prism(0,0,temp);
      }
      else
      {
        prism();
      }
      n = 1;
    }

    else if (strstr(token[0],"CYLINDER"))
    {
      if (token[1] > 0 && token[2] > 0)
      {
        double temp1 = atof(token[1]);
        double temp2 = atof(token[2]);
        cylinder(temp1,temp2);
      }
      else if (token[1] > 0 && token[2] == 0)
      {
        double temp = atof(token[1]);
        cylinder(temp);
      }
      else if (token[1] == 0 && token[2] > 0)
      {
        double temp = atof(token[2]);
        cylinder(0,temp);
      }
      else
      {
        cylinder();
      }
      n = 1;
    }

    else
    {
      cout << token[0];
      noFormula();
      n = 1;
    }
    }


    cout << endl;
  }
}

void square(float s)
{
  float area, per;

  area = s * s;
  per = 4 * s;

  cout << "SQUARE side=" << s << " area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << area << " perimeter= " << per;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void rectangle(float w, float l)
{
  float area, per;

  area = l * w;
  per = (2 * l) + (2 * w);

  cout << "RECTANGLE length=" << l << " width=" << w << " area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << area << " perimeter= " << per;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void circle(float r)
{
  float area, cir;

  area = pi * r * r;
  cir = 2 * pi * r;

  cout << "CIRCLE radius=" << r << " area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << area << " circumference= " << cir;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void cube(float s)
{
  float sa, v;

  v = s * s * s;
  sa = 6 * s * s;

  cout << "CUBE side=" << s  << " surface area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << sa << " volume= " << v;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void prism(float w, float l, float h)
{
  float sa, v;

  v = l * w * h;
  sa = (2 * l * w) + (2 * w * h) + (2 * l * h);

  cout << "PRISM length=" << l << " width=" << w << " height=" << h << " surface area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << sa << " volume= " << v;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void cylinder(float r, float h)
{
  float sa, v;

  v = pi * r * r * h;
  sa = (2 * pi * r * r) + (2 * pi * r * h);

  cout << "CYLINDER radius=" << r << " height=" << h << " surface area=";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << sa << " volume= " << v;
  cout << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void noFormula()
{
  cout << " INVLAID OBJECT" << endl;
}
