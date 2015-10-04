#include "Time.h"
#include<iostream>
#include<iomanip>
using namespace std;


Time::Time(const Time& t)
{
  cerr << "Time: Copy ctor" << endl;
  hour=t.hour;
  minute=t.minute;
}

Time::Time(int hr, int min)
{
  cerr << "Time: 2-arg ctor" << endl;
  hour=hr;
  minute=min;
}

void Time::display()const
{
  cout << setfill('0');
  cout << setw(2) << hour << ':';
  cout << setw(2) << minute << endl;
}
