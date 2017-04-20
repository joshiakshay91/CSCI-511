/*

FileName: film.h
Description: Header file for film.cpp has display function and search other function
Author: Akshay Joshi

*/
#ifndef FILM_H
#define FILM_H
#include<vector>
#include<string>
#include"Media.h"
using namespace std;
class Film :public Media
{
	private:
		string director;
		//  string notes;
		string year;
	public:
		Film(const string& film_CN,const string& film_T,const string& film_subj, const string& film_dir, const string& film_notes,const string& film_year);
		void Display()const;
		bool SearchOther(const string& keyword)const;
};

#endif
