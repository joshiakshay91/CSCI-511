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
