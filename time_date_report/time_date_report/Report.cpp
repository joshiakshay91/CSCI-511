#include "Report.h"
#include <string>
#include <iostream>
using namespace std;
Report::Report(int mm, int dd, int yy, int hr, int min, string str1)
:rep_date(mm, dd, yy), rep_time(hr,min),rep_desc( str1)
{
}// This constructor is used by using initialization list
void Report::display()const
{
rep_date.display();
rep_time.display();
cout<<rep_desc<<endl;
}//this function calls display function of date and time
// write a display function
