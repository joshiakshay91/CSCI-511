/*
Author: Akshay Joshi
Date: 2 December 2015
 */
#include "Wrapper.h"
#include <unistd.h>
#include <cstring>

class StreamSource
{
	private:
		char ch;
		int  ReplacementCount;
		int  SearchCount;
		int  SearchStringLength;
		string SearchString;
		string ReplacementString;
		string filename;
		Wrapper filein;
		bool SearchGet;
		bool ReplacementGet;
		int SearchOrigin;
		int MatchCount;
	public:
		StreamSource(string, string, string);
		~StreamSource();
		StreamSource& get(char& ch);
		void changer();
		void partialMatchFound(char ch);
		void changeIt();
		bool eof();
		bool currentlyReplacing();
};
/*+ A BufferFile object
 + replacement_count number of characters to be replaced (still)
 + search_origin - where in search string to start search again
 + search_count - number of letters remaining to grab from search string
   (due to an unsuccessful match)
 + string_length (of the replacement string. Convenience variable)
 + bool search_get (did we just get a character from the search string?)
 + bool replacement_get (did we just get a character from the repl string?)
*/
