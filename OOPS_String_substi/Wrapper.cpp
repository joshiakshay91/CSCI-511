/*
Author: Akshay Joshi
Date: 2 December 2015
 */
#include "Wrapper.h"
Wrapper::Wrapper():putPoint(0),getPoint(0),match(0),RealEoF(false)
{}

Wrapper::~Wrapper()
{
	fstream::close();
}
void Wrapper::DoOver(char ch)
{
	myBuff.push_front(ch);
}

char Wrapper::get(char &ch)
{
	if(!myBuff.empty())
	{
		ch=myBuff.front();
		myBuff.pop_front();
		return ch;
	}

	fstream::seekg(getPoint);
	ch=fstream::get();

	if(fstream::eof())
	{
		fstream::clear();
		RealEoF = true;
	}

	getPoint++;
	return ch;
}


void Wrapper::put(char ch)
{
	//cerr<<"In Wrapper put ch is: "<<ch<<endl;
	if(putPoint >= getPoint && !RealEoF)
	{
		fstream::seekg(getPoint);
		myBuff.push_back(fstream::get());

		if(fstream::eof())
		{
			fstream::clear();
			RealEoF = true;
		}
		getPoint++;
	}
	fstream::seekp(putPoint);
	fstream::put(ch);
	putPoint++;

}

bool Wrapper::EndofFileFunc()
{
	if(!myBuff.empty())
	{
		return false;
	}
	else
	{
		return RealEoF;
	}
}
