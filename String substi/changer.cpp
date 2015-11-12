/*
Author: Akshay Joshi
Date: 11 Nov 2015
*/
#include <sstream>
#include <unistd.h>
#include "changer.h"
	changer::changer(string old, string new1, string fileN)
:fileName(fileN),old_one(old),new_one(new1),match(0),getPoint(0),putPoint(0),OldSize(old_one.size())
{
	filein.open(fileName,std::ios::out|std::ios::in); //("myfile.txt", std::ios::out|std::ios::in)
	sizer();
}

void changer::sizer()
{
	if(old_one.size()==new_one.size())
	{
		equalChange();
	}
	else if(old_one.size()>new_one.size())
	{
		smallChange();
	}
	else if(old_one.size()<new_one.size())
	{
		BigChange();
	}
}
void changer::equalChange()
{
	int flag=0;
	char ch;
	//cout<<"FIle name : "<<fileName<<"\n"<<endl;
	//	std::fstream filein(fileName,std::ios::out|std::ios::in); //("myfile.txt", std::ios::out|std::ios::in)
	if (filein.is_open())
	{
		getPoint=putPoint=filein.tellg();
		while(filein)
		{
	//		filein.clear();
			flag=0;
			ch=filein.get();
			if(ch==old_one[0])   //if the first char of the string matches
			{
				if(old_one.size()==1) //if the size of old string is 1
				{
					ch=new_one[0];
					putPoint=getPoint;
				 	//cout<<"HERE:"<<ch<<endl;
				 	filein.clear();
					filein.seekp(putPoint);
					filein<<ch;
				}
				else
				{         //for string of size greater than 1
					putPoint=getPoint;//put pointer moves to first char of matching pos
					int Ooner=0;//for moving accross the old string Ooner is used to traverse//
					while(ch==old_one[Ooner] &&match<OldSize)//across old string//
					{
						++match;//i1s2s3i4
						++getPoint;//now point at s,point at s,points i,points at s outside
						++Ooner;//point at s, points at s, points i, points at p outside
						ch=filein.get();//gets s, gets s, gets i, get s outside
						/*if(ch==old_one[0]&&(!flag)){ //comment this one out
						  flag=getPoint;
						}*/
					}
					if(match==OldSize)
					{
						int i=0;
						while(match)
						{
							ch=new_one[i];
							filein.clear();
							//cout<<"PUT pointer vatiable over here is "<<putPoint<<endl;
							filein.seekp(putPoint);
							//cout<<"Tell p gives me"<<filein.tellp()<<endl;
							filein<<ch;
							++putPoint;
							++i;
							--match;
						}
						flag=1;
					}
					if(match<OldSize)
					{
						int j=0;
							while (match)
							{
								filein.clear();
								filein.seekp(putPoint);
								//cout<<"While partial matchTell p gives me"<<filein.tellp()<<endl;
								ch=old_one[j];
								filein<<ch;
								ch='\0';
								++putPoint;
								--match;
								++j;
							}
/*						if(flag!=0){//comment this one out
						  //cout<<"FLAG"<<flag<<endl;
						  getPoint=flag;}*/
						flag=1;
					}
					match=0;
				}
			}
			//  //cout<<"location: "<<filein.tellg()<<" Char: "<<ch<<endl;
			if(!flag)//flag wether to move this getpointer
			{
				++getPoint;
			}
			filein.seekg(getPoint);
		//	filein.clear();
			filein.seekp(getPoint);
		}
			filein.clear();
	}

	match=0;
}
void changer::smallChange()
{
	match=0;
	int newSize=new_one.size();
	//cout<<new_one.size()<<"new string size()\n";
	int flag=0;
	char ch;
//	TrackingDeque<char> mybuffer;
	//cout<<"FIle name : "<<fileName<<"\n"<<endl;
	if (filein.is_open())
	{
		getPoint=putPoint=filein.tellg();
		while(filein.good())
		{
			flag=0;
			ch=filein.get();
			if(ch==old_one[0])   //if the first char of the string matches
			{
				//			putPoint=getPoint;//put pointer moves to first char of matching pos
				int Ooner=0;//for moving accross the old string Ooner is used to traverse//
				while(ch==old_one[Ooner] &&match<OldSize)//across old string//
				{
					++match;//a1b2c3
					//cerr<<"MATCH IS"<<match<<endl;
					++getPoint;//now point at b,point at c,points outside
					++Ooner;//point at b, points at c, points outside
					ch=filein.get();//gets b, gets c, gets outside
				}
				if(match==OldSize)
				{
					int i=0;
					while(newSize){
						ch=new_one[i];
						filein.clear();
						//cout<<"PUT pointer vatiable over here is "<<putPoint<<endl;
						filein.seekp(putPoint);
						//cout<<ch<<"LOCATION of tellp:"<< filein.tellp()<<endl;
						//cout<<ch<<"<--From the matcher"<<endl;
						filein<<ch;
						ch='\0';
						++putPoint;
						++i;
						--newSize;
					}
					newSize=new_one.size();
					match=0;
					flag=1;
					trunk_counter=0;
				}
				if(match<OldSize)
				{
					while (match)
					{
						++putPoint;
						--match;
					}
					match=0;
					flag=1;
				}
			}
			filein.seekg(getPoint);
			ch=filein.get();
//			mybuffer.push_back(ch);
//			filein.clear();
		//	//cout<<"PUT pointer vatiable over here is "<<putPoint<<endl;
			filein.seekp(putPoint);
	//		ch=mybuffer.front();
			//cout<<ch<<"LOCATION of tellp:"<< filein.tellp()<<endl;
			//cout<<ch<<"<--From normal pusher"<<" The front"<<mybuffer.front()<<endl;
		//	mybuffer.pop_front();
			filein<<ch;
			ch='\0';
			if(!flag)
			{
				++getPoint;
				++putPoint;
			}
			filein.seekg(getPoint);
			++trunk_counter;
			//cout<<"location: "<<filein.tellg()<<" Char: "<<ch<<endl;
		}
		//filein.clear();
		truncq();
	}
}

void changer::BigChange()
{
	trunk_counter=999;
	match=0;
	TrackingDeque<char> mybuffer;
	int newSize=new_one.size();
	int diff=newSize-OldSize;
	int flag=0;
	char ch;
	if (filein.is_open())
	{
		getPoint=putPoint=filein.tellg();
		while(filein.good())
		{
			flag=0;
			ch=filein.get();
			if(ch==old_one[0])   //if the first char of the string matches
			{
				int Ooner=0;//for moving accross the old string Ooner is used to traverse//
				while(ch==old_one[Ooner] &&match<OldSize)//across old string//
				{
					++match;//a1b2c3
					++getPoint;//now point at b,point at c,points outside
					++Ooner;//point at b, points at c, points outside
					ch=filein.get();//gets b, gets c, gets outside
				}
				if(match==OldSize)
				{int d=diff;
					int i=0;
					while(d)
					{
						mybuffer.push_back(ch);
						++getPoint;
						filein.seekg(getPoint);
						ch=filein.get();
						--d;
					}
					while(newSize)
					{
						ch=new_one[i];
						filein.clear();
						//cout<<"Int putPoint val: "<<putPoint<<endl;
						//cout<<"PUTTING -> "<<ch<<" from subber In the file on loction "<<filein.tellp()<<endl;
						filein.seekp(putPoint);
						filein<<ch;
						ch='\0';
						++putPoint;
						++i;
						--newSize;
					}
					newSize=new_one.size();
					flag=1;
					trunk_counter=0;
				}
				if(match<OldSize)
				{
					while (match)
					{
						++putPoint;
						--match;
					}
					match=0;
					flag=1;
				}
			}
			if(!mybuffer.empty())
			{
	//			ch=filein.get();
//				mybuffer.push_back(ch);
				if(!flag){
				++getPoint;
				++putPoint;
				}
//				ch=filein.get();
//				mybuffer.push_back(ch);
				filein.seekg(getPoint);
				ch=filein.get();
				//cout<<"THis is char that will be pushed "<<ch<<" getPoint is<<"<<getPoint<<endl;
				mybuffer.push_back(ch);
				ch=mybuffer.front();
				mybuffer.pop_front();
				//cout<<"size of my buff "<<mybuffer.size()<<endl;
				//cout<<"Int putPoint val: "<<putPoint<<endl;
				//cout<<"PUTTING -> "<<ch<<" from queue In the file on loction "<<filein.tellp()<<endl;
				//filein.clear();
				filein.seekp(putPoint);
				filein<<ch;
//				ch='\0';
//			++getPoint;
			//	filein.seekg(getPoint);
		//		ch=filein.get();
		//		//cout<<"THis is char that will be pushed"<<ch<<"getPoint is<<"<<getPoint<<endl;
		//		mybuffer.push_back(ch);
			}
			else
			{
			filein.seekg(getPoint);
			ch=filein.get();
			//cout<<"Int putPoint val: "<<putPoint<<endl;
			//cout<<"PUTTING -> "<<ch<<" from normal In the file on loction "<<filein.tellp()<<endl;
			filein.seekp(putPoint);
			filein<<ch;
			ch='\0';
			if(!flag)
			{
			++getPoint;
			++putPoint;
			}
			filein.seekg(getPoint);
		}
		++trunk_counter;
	}
if(trunk_counter!=1)
{
	filein.clear();
	filein.seekp(putPoint);
	filein<<ch;
}
}
}

void changer::truncq()
{
	char * named = new char [fileName.size() + 1];
  strcpy(named, fileName.c_str());
	if(trunk_counter==1){
	truncate(named,(putPoint));}
	else{
		truncate(named,(putPoint-1));
	}
}
