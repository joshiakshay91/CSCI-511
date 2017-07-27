
#include "stampbuff.h"
#include "stamp.h"
#include <streambuf>
#include <stdexcept>
using namespace stamping_press;

stampbuf::stampbuf(int col, int row1):streambuf(),maxRow(row1),maxCol(col),buffer(new char[col/2])
{
    SetRow(0);
    SetColoumn(0);
    setp(buffer,buffer+(col/2));
    try {
        insert_plate(col, row1);
    }catch (...){}
}

int stampbuf::sync()
{
  char* letter= pbase();
  while(letter != pptr())
  {
    if(coloumn<maxCol)
    {
      try{
        set_die(*letter);
        try{
        stamp(coloumn,row1);
        }catch(...){}
        SetColoumn(++coloumn);
      }catch(std::invalid_argument){
      if(*letter==get_die())
      {
        try{
        stamp(coloumn,row1);
        }catch(...){}
        SetColoumn(++coloumn);
      }else if(*letter==' ')
      {
        SetColoumn(++coloumn);
      }
      else{++coloumn;}
    }
    }
    ++letter;
  }
  setp(buffer, buffer+coloumn);
  return 0;
}

int stampbuf::overflow(int character)
{
  char* letter= pbase();
  while(letter != pptr())
  {
    if(coloumn<maxCol){
      try{
        set_die(*letter);
        try{stamp(coloumn,row1);}
        catch(...){}
        SetColoumn(++coloumn);
      }catch(std::invalid_argument){
      if(*letter==get_die())
      {
        try{stamp(coloumn,row1);}
        catch(...){}
        SetColoumn(++coloumn);
      }else if(*letter==' ')
      {
        SetColoumn(++coloumn);
      }
      else{++coloumn;}
    }
    }
    ++letter;
  }
  setp(buffer, buffer+coloumn);
	sputc(character);
  //pubsync();
	return character;

}

void stampbuf::SetRow(int r)
{
  row1=r;
}

void stampbuf::SetColoumn(int c)
{
    coloumn=c;
}

int stampbuf::GetRow() const
{
    return row1;
}

stampbuf::~stampbuf()
{
    pubsync();
    try{
    eject_plate();
    }catch(...){}
    delete buffer;
}
