//


#include "stampstream.h"
#include "stampbuff.h"
#include "stamp.h"
#include <fstream>
#include <ostream>
using namespace stamping_press;

row::row(int r):myRow(r)
{}

int row::GetmyRow() const
{
  return myRow;
}

stampstream::stampstream(int col,int row):ostream(new stampbuf(col,row)){}

stampstream::~stampstream()
{
    delete rdbuf();//this pointer is protected to ostream so rdbuf

}
ostream& operator<<(ostream& os, const row& row)
{
	stampbuf* buffy = static_cast<stampbuf*>(os.rdbuf());
	os.flush();
  (*buffy).SetColoumn(0);
	(*buffy).SetRow(row.GetmyRow());
	return os;

}

ostream& endrow(ostream& os)
{
  	stampbuf* buffy = static_cast<stampbuf*>(os.rdbuf());
  	(*buffy).pubsync();//called pubsync on purpose to show that flush() eventually calls
  	(*buffy).SetColoumn(0); //pubsync() which in return invokes my overrided func sync()
  	(*buffy).SetRow((*buffy).GetRow() + 1);
	return os;
}
