/*

FileName: Menu.cpp
Description: This file is main driver or menu function .cpp file for Search Engine
project for Library
Author: Akshay Joshi

*/
#include "engine.h"
#include <iostream>
#include <iomanip>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
int main ( ) {

	Engine engSearch;// ( "book.txt", "periodic.txt", "video.txt", "film.txt" );
	string keyword;
	int digit=0;
	while(digit !=5)
	{
		vector<Media*> results;
		while(!results.empty())
		{
			results.pop_back();
		}
		cout << "\n--------------------MENU--------------------"<< endl;
		cout<< "Please Enter A valid numeric option for searching"<<endl;
		cout << "1.Search by Call Number"<<endl;
		cout << "2.Search by Title"<<endl;
		cout << "3.Search by Subject"<<endl;
		cout << "4.Search by Other Fields"<<endl;
		cout << "5.Quit"<<endl;
		cout<< "\nEnter Your Numeric Input: ";
		cin.clear();
		cin >> digit;
		cin.clear();
		if (digit==1){
			cout << "Input for Search by Call Number: ";
			cin.ignore();
			getline(cin, keyword);
			cin.clear();
			results=engSearch.searchCN(keyword);
		}
		else if(digit==2){
			cout<<"Input for Search by Title:  ";
			cin.ignore();
			getline(cin,keyword);
			cin.clear();
			results=engSearch.searchTi(keyword);
		}
		else if(digit==3){
			cout<<"Input for Search by Subject Name: ";
			cin.ignore();
			getline(cin,keyword);
			cin.clear();
			results=engSearch.searchSub(keyword);
		}
		else if(digit==4){
			cout<<"Input for Search by Other: ";
			cin.ignore();
			getline(cin,keyword);
			cin.clear();
			results=engSearch.searchOTH(keyword);
		}
		else if(digit==5)
		{
			break;
		}
		if (results.size() == 0 && digit <=4)
		{
			cout << "No match found \n";
		}
		else if((digit != 5) )
		{
			unsigned int i = 0;
			while( i < results.size())
			{
				results[i]->Display();
				i++;
			}
		}
		if(digit > 5 || digit <1) {
			std::cin.clear(); //clear bad input flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			std::cout << "Invalid input; please re-enter.\n";
		}
	}
	return 0;
}
