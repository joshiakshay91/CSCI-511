#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "deque.h"
using namespace std;

class Wrapper : public fstream
{
  public:
		int  putPoint; //std::streampos
	private:
		int  getPoint; //std::streampos
		int  match;
		char ch;
		bool RealEoF;
		TrackingDeque<char> myBuff;

	public:
		Wrapper();
		~Wrapper();
		char get(char& ch);
		void put(char ch);
		void DoOver(char ch);
		bool EndofFileFunc();
};
