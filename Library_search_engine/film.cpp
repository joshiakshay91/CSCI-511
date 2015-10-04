/*

FileName: film.cpp
Description: stores all the film values except the once that media holds, has a display
function and search other function.
Author: Akshay Joshi

*/

#include <iostream>
#include <iomanip>
#include "film.h"
#include <string>
using namespace std;

	Film::Film(const string& film_CN,const string& film_T,const string& film_subj, const string& film_dir, const string& film_notes,const string& film_year)
:Media(film_CN, film_T, film_subj,film_notes), director(film_dir), year(film_year)
{}
void Film::Display()const
{
	cout << "--------------------FILM--------------------" << endl;
	Media::Display();
	cout << "Director:	"<<director << endl;
	cout << "Year:	"<<year << endl;
	cout << "--------------------------------------------\n" << endl;
}
bool Film::SearchOther(const string& keywords)const
{
	bool flag;
	{
		if((this->director.find(keywords)!= string::npos) || (this->year.find(keywords)!= string::npos) )
		{
			flag= true;
		}
		else
		{
			flag= false;
		}
	}
	bool mflag=Media::SearchOther(keywords);
	if (flag || mflag)
	{
		return true;
	}
	else{
		return false;
	}

}
