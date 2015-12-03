/*
Author: Akshay Joshi
Date: 2 December 2015
 */
#include "StreamSource.h"
#include <iostream>
#define USAGE "<OldString> <NewString> <FileName>"
using namespace std;

int main(int argc, char* argv[])
{
  if(argc<4)
  {
    cout<<"Not enough arguments: "<<(argc-1)<<endl;
    cout<<"Usage: " <<USAGE<<endl;
    return -1;
  }
  StreamSource c ((string)argv[1], (string)argv[2], (string)argv[3]);//("abc","x", "test.txt");
  return 0;
}
