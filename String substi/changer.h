#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <cstring>
#include "deque.h"
using namespace std;
class changer
{
private:
  string new_one;
  string old_one;
  string fileName;
  int match;
  int flag;
  int OldSize;
  int newSize;
  int getPoint;
	int putPoint;
  int trunk_counter;
  char ch;
  fstream filein;
public:
  changer(string, string, string);
  ~changer();
  void sizer();
  void smallChange();
  void BigChange();
  void equalChange();
  void truncq();
  bool checker( int CaseA);
  void falseAlarm();
  void traversing();
  void substituter();
};
