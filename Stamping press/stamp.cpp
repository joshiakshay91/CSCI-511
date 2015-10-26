// Version 3/2011
#include <stdexcept>
#include <iostream>
#include <cctype>
#include <string>
#include "stamp.h"

static char** plate=0;
static int num_cols=0;
static int num_rows=0;
static char current_die=0;

void stamping_press::set_die(char die)
{
  if(die==current_die || (die != '#' && die !='*' && !isalnum(die)))
  {
    std::string s="no such die: '";
    s+=die;
    s+= "'";
    throw std::invalid_argument(s);
  }
  current_die=die;
}

char stamping_press::get_die()
{
  return current_die;
}

void stamping_press::insert_plate(int cols, int rows)
{
  if(plate!=0)
    throw std::logic_error("plate already inserted");
  plate=new char*[cols];
  for(int x=0; x<cols; x++)
    plate[x]=new char[rows];
  for(int x=0; x<cols; x++)
    for(int y=0; y<rows; y++)
      plate[x][y]=' ';
  num_cols=cols;
  num_rows=rows;
}

void stamping_press::eject_plate()
{
  if(plate==0)
    throw std::logic_error("no plate to eject");

  std::cout << '/';
  for(int x=0; x<num_cols; x++)
    std::cout << '-';
  std::cout << '\\' << std::endl;

  for(int y=0; y<num_rows; y++)
  {
    std::cout << '|';
    for(int x=0; x<num_cols; x++)
      std::cout << plate[x][y];
    std::cout << '|' << std::endl;
  }

  std::cout << '\\';
  for(int x=0; x<num_cols; x++)
    std::cout << '-';
  std::cout << '/' << std::endl;

  for(int x=0; x<num_cols; x++)
    delete [] plate[x];
  delete [] plate;
  plate=0;
}

void stamping_press::stamp(int col, int row)
{
  if(plate==0)
    throw std::logic_error("no plate to stamp");
  if(current_die==0)
    throw std::logic_error("no die to stamp");
  if(col >= num_cols || col < 0)
    throw std::out_of_range("invalid col");
  if(row >= num_rows || row < 0)
    throw std::out_of_range("invalid rowumn");
  plate[col][row]=current_die;
}
