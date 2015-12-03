/*
Author: Akshay Joshi
Date: 2 December 2015
 */
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
/*  get
*  put
*  do_over (push a character back onto the deque)
*  eof
  (and as private data, your tracking deque)

Keeps track of getter and putter
Pushes a character onto the deque when put threatens
to overwrite unread character in file.
*/
