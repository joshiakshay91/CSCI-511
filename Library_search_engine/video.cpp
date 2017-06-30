/*

FileName: video.cpp
Description: stores all the video values except the once that media holds, has a display
function and search other function.
Author: Akshay Joshi

*/

#include <iostream>
#include <iomanip>
#include "video.h"
#include <string>
using namespace std;

	Video::Video(const string& video_CN,const string& video_T,const string& video_subj, const string& video_des,const string& video_distro,const string& video_notes, const string& video_series,const string& video_labels)
:Media(video_CN, video_T, video_subj,video_notes), description(video_des), distributor(video_distro), series(video_series), labels(video_labels)
{}
void Video::Display()const
{
	cout << "--------------------VIDEO-------------------" << endl;
	Media::Display();
	cout << "Description:  "<<description << endl;
	cout << "Distributor:  "<<distributor << endl;
	cout << "Series:  "<<series << endl;
	cout << "Labels:  " << labels << endl;
	cout << "--------------------------------------------\n" << endl;
}
bool Video::SearchOther(const string& keywords)const
{
	bool flag;
	{
		if((this->description.find(keywords)!= string::npos) || (this->distributor.find(keywords)!= string::npos))
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
