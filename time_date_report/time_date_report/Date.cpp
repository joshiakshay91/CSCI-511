#include "Date.h"
#include<iostream>
#include<iomanip>
using namespace std;
Date::Date(const Date& d)
{
  cerr << "Date: Copy ctor" << endl;
  month=d.month;
  day=d.day;
  year=d.year;
}

Date::Date(int m, int d, int y)
{
  cerr << "Date: 3-arg ctor" << endl;
  month=m;
  day=d;
  year=y;
}

void Date::display()const
{
  cout << month << '/';
  cout << day << '/';
  cout << year << endl;
}
