/*

FileName: video.h
Description: Header file for video.cpp has display function and search other function
Author: Akshay Joshi

*/

#ifndef VIDEO_H
#define VIDEO_H
#include<vector>
#include<string>
#include"Media.h"
using namespace std;
class Video :public Media
{
	private:
		string description;
		string distributor;
		//  string notes;
		string series;
		string labels;
	public:
		Video(const string& video_CN,const string& video_T,const string& video_subj, const string& video_des,const string& video_distro,const string& video_notes, const string& video_series,const string& video_labels);
		void Display()const;
		bool SearchOther(const string& keyword)const;
};
#endif
