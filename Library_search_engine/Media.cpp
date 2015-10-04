/*

FileName: media.cpp
Description: This is media.cpp and has all the definations for the functions declared in
Media.h here virtual media destructor handles deletion of all the strings and variables created
by book.cpp, film.cpp, video.cpp and Periodicals.cpp. The bool also takes the answer form those
files and returns the result to engine.cpp
Author: Akshay Joshi

*/
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include "Media.h"
using namespace std;

Media::~Media() //virtual destructor
{

}

// virtual search other function this function only searches notes and therefore is called from
// individually from book.cpp, film.cpp, video.cpp, Periodicals.cpp
bool Media::SearchOther(const string& keywords)const
{
	if (this->notes.find(keywords) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Media intilization list
Media::Media(const string& Ca,const string& Ti,const string& subj, const string& note):CallNumber(Ca),title(Ti), subject(subj), notes(note)
{
}

void Media::Display()const
{
	cout << "Call Number:	" << CallNumber << endl;
	cout << "Title :	" << title << endl;
	cout << "Subject :	" << subject << endl;
	cout << "Notes :	" << notes << endl;
}

bool Media::searchCallN(const string& cn)const
{
	if (this->CallNumber.find(cn) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Media::searchTitle(const string& Ti)const
{
	if(this->title.find(Ti)!= string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Media::searchSubject(const string& sub)const
{
	if(this->subject.find(sub)!= string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}
