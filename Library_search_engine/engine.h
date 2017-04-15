/*

FileName: engine.h
Description: This file is Search Engine header it includes all the signature for
search engine class called engine.cpp
Author: Akshay Joshi

*/
#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include <list>
#include <vector>
#include "Media.h"
using std::string;
using std::list;
using std::vector;


class Engine {

	public:
		Engine();
		~Engine();
		void processFile(string);
		void processFile1(string);
		void processFile2(string);
		void processFile3(string); //these process functions are used to get input from all
		// the text files book.txt, periodic.txt , film.txt and video.txt
		vector<Media*> searchCN(const string& CN)const;
		vector<Media*> searchTi(const string& Ti)const;
		vector<Media*> searchSub(const string& Si)const;
		vector<Media*> searchOTH(const string& OTH)const;
		//these search functions asks for boolean value for the string the search engine is searching

	private:
		vector<Media*> data;  //this is card catalog name: data
};
#endif
