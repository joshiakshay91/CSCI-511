/*

Author: Akshay Joshi
Date: 11 Nov 2015

 */
#include "changer.h"
	changer::changer(string old, string new1, string fileN)
:fileName(fileN),old_one(old),new_one(new1),match(0),getPoint(0),putPoint(0),
OldSize(old_one.size()),newSize(new_one.size()),flag(0)
{
	filein.open(fileName,std::ios::out|std::ios::in); //("myfile.txt", std::ios::out|std::ios::in)
	sizer();
}
changer::~changer()
{}
void changer::sizer()
{
	if(old_one.size()==new_one.size()){equalChange();}
	else if(old_one.size()>new_one.size()){smallChange();}
	else if(old_one.size()<new_one.size()){BigChange();}
}

void changer::equalChange()
{
	if (filein.is_open())
	{
		getPoint=putPoint=filein.tellg();
		while(filein)
		{
			flag=0;
			ch=filein.get();
			if(ch==old_one[0])   //if the first char of the string matches
			{
				if(old_one.size()==1) //if the size of old string is 1
				{
					ch=new_one[0];
					putPoint=getPoint;
					filein.clear();
					filein.seekp(putPoint);
					filein<<ch;
				}
				else
				{
					if(checker(1))
					{
						substituter();
					}
					if(match<OldSize)
					{
						falseAlarm();
					}
				}
			}
			if(!flag)//flag wether to move this getpointer
			{
				++getPoint;
			}
			filein.seekg(getPoint);
			filein.seekp(getPoint);
		}
		filein.clear();
	}

	match=0;
}
void changer::smallChange()
{
	match=0;
	if (filein.is_open())
	{
		getPoint=putPoint=filein.tellg();
		while(filein.good())
		{
			flag=0;
			ch=filein.get();
			if(ch==old_one[0])   //if the first char of the string matches
			{
				if(checker(0))
				{
					substituter();
					newSize=new_one.size();
					trunk_counter=0;
				}
				if(match<OldSize)
				{
					falseAlarm();
				}
			}
			traversing();
			++trunk_counter;
		}
		truncq();
	}
}

void changer::BigChange()
{
	match=0;
	TrackingDeque<char> mybuffer;
	int diff=newSize-OldSize;
	if (filein.is_open())
	{
		getPoint=putPoint=filein.tellg();
		while(filein.good())
		{
			flag=0;
			ch=filein.get();
			if(ch==old_one[0])   //if the first char of the string matches
			{
				if(checker(0))
				{
					int d=diff;
					while(d)
					{
						mybuffer.push_back(ch);
						++getPoint;
						filein.seekg(getPoint);
						ch=filein.get();
						--d;
					}
					substituter();
					newSize=new_one.size();
					trunk_counter=0;
				}
				if(match<OldSize)
				{
					falseAlarm();
				}
			}
			if(!mybuffer.empty())
			{
				if(!flag)
				{
					++getPoint;
					++putPoint;
				}
				ch=mybuffer.front();
				mybuffer.pop_front();
				filein.seekg(getPoint);
				mybuffer.push_back(filein.get());//because of this only one deque element is used
				filein.seekp(putPoint);
				filein<<ch;
			}
			else
			{
					traversing();
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
	if(trunk_counter==1)
	{
		truncate(named,(putPoint));
	}
	else
	{
		truncate(named,(putPoint-1));
	}
	delete named;
}

bool changer::checker(int CaseA)
{
	if(CaseA==1)
	{
		putPoint=getPoint;
	}
	int Ooner=0;//for moving accross the old string Ooner is used to traverse//
  while(ch==old_one[Ooner] &&match<OldSize)//across old string//
  {
    ++match;//i1s2s3i4
    ++getPoint;//now point at s,point at s,points i,points at s outside
    ++Ooner;//point at s, points at s, points i, points at p outside
    ch=filein.get();//gets s, gets s, gets i, get s outside
  }
	if (match==OldSize)
	{
		return true;
	}
	else{
		return false;
	}
}

void changer::falseAlarm()
{
	int j=0;
	while (match)
	{
		filein.clear();
		filein.seekp(putPoint);
		ch=old_one[j];
		filein<<ch;
		ch='\0';
		++putPoint;
		--match;
		++j;
	}
	flag=1;
	match=0;
	return;
}

void changer::traversing()
{
	filein.seekg(getPoint);//204-215, 123-133
	ch=filein.get();
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

void changer::substituter()
{
	int i =0;
	while(newSize)
	{
	  ch=new_one[i];
	  filein.clear();
	  filein.seekp(putPoint);
	  filein<<ch;
	  ch='\0';
	  ++putPoint;
	  ++i;
	  --newSize;
	}
	match=0;
	flag=1;
	return;
}
