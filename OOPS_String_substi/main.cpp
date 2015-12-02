/*
Author: Akshay Joshi
Date: 12 Nov 2015
 */
#include "StreamSource.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  StreamSource c ((string)argv[1], (string)argv[2], (string)argv[3]);//("abc","x", "test.txt");
  return 0;
}
