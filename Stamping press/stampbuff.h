#include <iostream>
using namespace std;
//The purpose of stampbuf is to manage the char buffer(arrays of char)
class stampbuf : public std::streambuf{
public:
  stampbuf(int c, int r);
  ~stampbuf();
void SetRow(int);//set row
void SetColoumn(int);//set column
virtual int sync();
int GetRow() const;
virtual int overflow(int);
private:
  char* buffer;
  int maxRow;
  int maxCol;
  int row1;
  int coloumn;
};
