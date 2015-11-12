#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include "deque.h"
using namespace std;
class changer{
private:
  string new_one;
  string old_one;
  string fileName;
  int match;
  int OldSize;
  int getPoint;
	int putPoint;
  int trunk_counter;
  fstream filein;
public:
  changer(string, string, string);
  void sizer();
  void smallChange();
  void BigChange();
  void equalChange();
  void truncq();
};
