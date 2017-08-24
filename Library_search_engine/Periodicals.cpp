/*

FileName: Periodicals.cpp
Description: stores all the Periodicals values except the once that media holds, has a display
function and search other function.
Author: Akshay Joshi

*/

#include <iostream>
#include <iomanip>
#include "Periodicals.h"
#include <string>
using namespace std;

	Periodic::Periodic(const string& periodic_CN,const string& periodic_T,const string& periodic_subj, const string& periodic_auth, const string& periodic_des,const string& periodic_pub,const string& periodic_pubHist, const string& periodic_series,const string& periodic_notes,const string& periodic_rTitles, const string& periodic_OFT, const string& periodic_GDocsN)
:Media(periodic_CN, periodic_T, periodic_subj,periodic_notes), author(periodic_auth), description(periodic_des), publisher(periodic_pub), publishingHist(periodic_pubHist), series(periodic_series), relatedTitles(periodic_rTitles), OFormsTitle(periodic_OFT), govtDoc(periodic_GDocsN)
{}
void Periodic::Display()const
{
	cout << "----------------PERIODICALS-----------------" << endl;
	Media::Display();
	cout << "Author: "<<author << endl;
	cout << "Description:  "<<description << endl;
	cout << "Publisher:  "<<publisher << endl;
	cout << "Publishing History: "<<publishingHist << endl;
	cout << "Series: "<<series << endl;
	cout << "Related Titiles: "<< relatedTitles << endl;
	cout << "Other Forms: "<< OFormsTitle << endl;
	cout << "Govt documents:  "<< govtDoc << endl;
	cout << "-----------------------------------------------\n" << endl;
}
bool Periodic::SearchOther(const string& keywords)const
{
	bool flag;
	{
		if((this->description.find(keywords)!= string::npos)  || (this->series.find(keywords)!= string::npos)|| (this->relatedTitles.find(keywords)!= string::npos) )
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
