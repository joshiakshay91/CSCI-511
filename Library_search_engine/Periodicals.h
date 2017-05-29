/*

FileName: Periodicals.h
Description: Header file for Periodicals.cpp has display function and search other function
Author: Akshay Joshi

*/

#ifndef PERIODICALS_H
#define PERIODICALS_H
#include<vector>
#include<string>
#include"Media.h"
using namespace std;
class Periodic :public Media
{
	private:
		string author;
		string description;
		string publisher;
		string publishingHist;
		string series;
		//string notes;
		string relatedTitles;
		string OFormsTitle;
		string govtDoc;
	public:
		Periodic(const string& periodic_CN,const string& periodic_T,const string& periodic_subj, const string& periodic_auth, const string& periodic_des,const string& periodic_pub,const string& periodic_pubHist, const string& periodic_series,const string& periodic_notes,const string& periodic_rTitles, const string& periodic_OFT, const string& periodic_GDocsN);
		void Display()const;
		bool SearchOther(const string& keyword)const;
};
#endif
