#include <iostream>
class row
{
public:
    row(int r);
    int GetmyRow() const;
private:
    int myRow;
};

using namespace std;
class stampstream:public ostream{
public:
    stampstream(int col, int row);
    ~stampstream();
};
ostream& operator<<(ostream& os, const row& row);
ostream& endrow(ostream& os);
template< class CharT, class Traits >
std::basic_ostream<CharT, Traits>& flush( std::basic_ostream<CharT, Traits>& os );
