#include "Report.h"
void func(const Report& r) //copy ctor
{
  r.display();
}


int main()
{
  Report r(12,31,1999,23,59,"Y2K, The Millennium bug");
  // Create Report r;
  func(r);
}
