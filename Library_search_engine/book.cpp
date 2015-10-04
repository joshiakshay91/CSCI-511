/*

FileName: book.cpp
Description: stores all the book values except the once that media holds, has a display
function and search other function
Author: Akshay Joshi

*/

#include <iostream>
#include <iomanip>
#include "book.h"
#include <string>
using namespace std;

Book::Book(const string& book_CN,const string& book_T,const string& book_subj,const string& book_auth,const string& book_des,const string& book_pub,const string& book_city, const string& book_year, const string& book_series,const string& book_notes)
:Media(book_CN, book_T, book_subj,book_notes), author(book_auth), description(book_des), publisher(book_pub), city(book_city), year(book_year), series(book_series) //,notes(book_notes)
{}
void Book::Display()const
{
	cout << "--------------------BOOK--------------------" << endl;
	Media::Display();
	cout << "Author:	"<<author << endl;
	cout << "Description: "<<description << endl;
	cout << "Publisher:	"<<publisher << endl;
	cout << "City:	"<<city << endl;
	cout << "Year:	"<<year << endl;
	cout << "Series:	"<<series << endl;
	cout << "--------------------------------------------\n" << endl;
}
bool Book::SearchOther(const string& keywords)const
{
	bool flag;
	{
		if((this->description.find(keywords)!= string::npos) ||(this->year.find(keywords)!= string::npos) )
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
