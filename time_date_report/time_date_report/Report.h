#ifndef REPORT_H
#define REPORT_H
#include "Time.h"
#include "Date.h"
#include <string>
class Report {
  private:
    Date rep_date;
    Time rep_time;
    std::string rep_desc;
  public:
    Report(int , int , int , int, int, std::string);
    //TO DO: constructor
    void display()const; //you write the definition
};
#endif
