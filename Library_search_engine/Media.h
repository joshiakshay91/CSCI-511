/*

FileName: media.h
Description: This file is header file for media.cpp it creates the class Media and has
signatures for virtual display function and boolean search functions with constants passed
by reference.
Author: Akshay Joshi

*/
#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <list>
#include <vector>
using std::string;
using std::list;
using std::vector;

class Media{
	private:
		string CallNumber;
		string title;
		string subject;
		string notes;
	public:
		Media(const string& Ca,const string& Ti,const string& subj, const string& note);
		virtual void Display()const;
		bool searchCallN(const string& cn)const;
		bool searchTitle(const string& Ti)const;
		bool searchSubject(const string& sub)const;
		virtual bool SearchOther(const string& keywords)const;
		virtual ~Media();
};
#endif
