/*

FileName: book.h
Description: Header file for book cpp has display function and search other function
Author: Akshay Joshi

*/

#ifndef BOOK_H
#define BOOK_H
#include<vector>
#include<string>
#include"Media.h"
using namespace std;
class Book :public Media
{
	private:
		string author;
		string description;
		string publisher;
		string city;
		string year;
		string series;
		//  string notes;
	public:
		Book(const string& book_CN,const string& book_T,const string& book_subj, const string& book_auth, const string& book_des,const string& book_pub,const string& book_city,const string& book_year,const string& book_series,const string& book_notes);
		void Display()const;
		bool SearchOther(const string& keyword)const;
};
#endif
