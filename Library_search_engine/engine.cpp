/*

FileName: engine.cpp
Description: This file is Search Engine cpp file called engine.cpp this file processess all
the input txt database , and stores in a card catlog called data. It is a vector and it stores
book.txt, periodic.txt, film.txt and video.txt
Author: Akshay Joshi

*/
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include <string.h>
#include <fstream>
#include "engine.h"
#include "book.h"
#include "Periodicals.h"
#include "film.h"
#include "video.h"
using namespace std;
Engine::Engine()		//engine constructor
{
	processFile ( "book.txt" );				//calls functions to process input
	processFile1 ( "periodic.txt" );
	processFile2 ( "film.txt" );
	processFile3("video.txt");
}

Engine::~Engine()		//engine destructor
{
	for (unsigned int i = 0; i < data.size(); i++)
	{
		delete data[i];
	}
}
void Engine::processFile(string key) //this functions stores the input from txt file
{
	ifstream filein(key.c_str());
	string word_line;
	if (filein.is_open())
	{
		{
			while(getline(filein, word_line))
			{
				string CallNumber=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string title =word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string subject=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string author=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string description =word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string publisher=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string city=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string year=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string series=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string notes=word_line;
				Book* bk=new Book(CallNumber,title,subject,author,description,publisher,city,year,series,notes);
				data.emplace_back(bk);
			}
		}
		filein.close();
	}
}


void Engine::processFile1(string key) 	//this functions stores the input from txt file
{
	ifstream filein(key.c_str());
	string word_line;
	if (filein.is_open())
	{
		{
			while(getline(filein, word_line))
			{
				string CallNumber=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string title =word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string subject=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string author=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string description =word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string publisher=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string pHist=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string series=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string notes=word_line;
				word_line.erase(0,word_line.find('|')+1);
				string rTitiles=word_line;
				word_line.erase(0,word_line.find('|')+1);
				string OFT=word_line;
				word_line.erase(0,word_line.find('|')+1);
				string Gdocs=word_line;
				Periodic* pc=new Periodic(CallNumber,title,subject,author,description,publisher,pHist,series,notes,rTitiles,OFT,Gdocs);
				data.emplace_back(pc);
			}
		}
		filein.close();
	}
}

void Engine::processFile2(string key)		//this functions stores the input from txt file
{
	ifstream filein(key.c_str());
	string word_line;
	if (filein.is_open())
	{
		{
			while(getline(filein, word_line))
			{
				string CallNumber=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string title =word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string subject=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string director=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string notes=word_line;
				word_line.erase(0,word_line.find('|')+1);
				string yearr=word_line;
				Film* FM=new Film(CallNumber,title,subject,director,notes,yearr);
				data.emplace_back(FM);
			}
		}
		filein.close();
	}
}

void Engine::processFile3(string key)		//this functions stores the input from txt file
{
	ifstream filein(key.c_str());
	string word_line;
	if (filein.is_open())
	{
		{
			while(getline(filein, word_line))
			{
				string CallNumber=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string title =word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string subject=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string description =word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string distributor=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string notes=word_line;
				word_line.erase(0,word_line.find('|')+1);
				string series=word_line.substr(0,word_line.find('|'));
				word_line.erase(0,word_line.find('|')+1);
				string labels=word_line;
				Video* vk=new Video(CallNumber,title,subject,description,distributor,notes,series,labels);
				data.emplace_back(vk);
			}
		}
		filein.close();
	}
}

vector<Media*> Engine:: searchCN(const string& CN)const //search by call number
{
	vector<Media*> tempResults;
	for (unsigned int i = 0; i < data.size(); i++)
	{
		bool resultFlag=data[i]->searchCallN(CN);
		if (resultFlag)
		{
			tempResults.emplace_back(data[i]);
		}
	}
	return tempResults;
}

vector<Media*> Engine:: searchTi(const string& Ti)const  //search by title
{
	vector<Media*> tempResults;
	for (unsigned int i = 0; i < data.size(); i++)
	{
		bool resultFlag=data[i]->searchTitle(Ti);
		if (resultFlag)
		{
			tempResults.emplace_back(data[i]);
		}
	}
	return tempResults;
}

vector<Media*> Engine:: searchSub(const string& Si)const  //search by subject
{
	vector<Media*> tempResults;
	for (unsigned int i = 0; i < data.size(); i++)
	{
		bool resultFlag=data[i]->searchSubject(Si);
		if (resultFlag)
		{
			tempResults.emplace_back(data[i]);
		}
	}
	return tempResults;
}

vector<Media*> Engine:: searchOTH(const string& OTH)const //search by other
{
	vector<Media*> tempResults;
	for (unsigned int i = 0; i < data.size(); i++)
	{
		bool resultFlag=data[i]->SearchOther(OTH);
		if (resultFlag)
		{
			tempResults.emplace_back(data[i]);
		}
	}
	return tempResults;
}
