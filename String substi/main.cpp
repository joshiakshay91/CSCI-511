/*
Author: Akshay Joshi
Date: 12 Nov 2015
 */
#include "changer.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  string old_string = argv[1];
  string new_string = argv[2];
  string filename   = argv[3];
  changer c (old_string, new_string, filename);//("abc","x", "test.txt");
return 0;
}
