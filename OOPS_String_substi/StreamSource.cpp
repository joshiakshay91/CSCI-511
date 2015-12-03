/*
Author: Akshay Joshi
Date: 2 December 2015
 */
#include "StreamSource.h"

	StreamSource::StreamSource(string old_str, string new_str, string file_name)
:ReplacementString(new_str),SearchString(old_str),filename(file_name),ReplacementCount(0),
	SearchCount(0),SearchStringLength(0),MatchCount(0)
{
	filein.open(filename,std::ios::in | std::ios::out);
	changer();
}
StreamSource::~StreamSource()
{
	char * named = new char [filename.size() + 1];
	strcpy(named, filename.c_str());
	truncate(named,(filein.putPoint));
	delete named;
}

void StreamSource::changer()
{
	int searchStringLen=SearchString.size();
	MatchCount =0;
	while(!get(ch).eof())
	{
		if(ch==SearchString[MatchCount] && ! (currentlyReplacing()))
		{
			++MatchCount;
			if(MatchCount < searchStringLen)
				continue;
		}
		if(MatchCount == searchStringLen ) //matched
		{
			changeIt();
		}
		else if( MatchCount > 0)
		{
			partialMatchFound(ch);
		}
		else
		{
			filein.put(ch);
		}
		MatchCount=0;
	}
}

StreamSource& StreamSource::get(char &ch)
{
	if(ReplacementCount>0)
	{
		ch = ReplacementString[ReplacementString.size() - ReplacementCount--];
		ReplacementGet = true;
	}
	else if(SearchCount>0)
	{
		ch = SearchString[ SearchStringLength  - SearchCount--];
		SearchGet = true;
	}
	else
	{
		filein.get(ch);
		ReplacementGet =SearchGet= false;
	}
	return *this;
}

bool StreamSource::currentlyReplacing()
{
	return ReplacementGet;
}
void StreamSource::changeIt()
{
	ReplacementCount = ReplacementString.size();
}

void StreamSource::partialMatchFound(char ch)
{
	if(SearchGet)
	{
		++SearchOrigin;
	}
	else
	{
		SearchOrigin=0;
		SearchStringLength=MatchCount;
		filein.DoOver(ch);
	}
	filein.put(SearchString[SearchOrigin]);
	SearchCount = SearchStringLength-1-SearchOrigin;
}

bool StreamSource::eof()
{
	if(ReplacementGet || SearchGet)
	{
		return false;
	}
	else
	{
		return filein.EndofFileFunc();
	}
}
