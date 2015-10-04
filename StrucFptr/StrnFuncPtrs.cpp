#include <iostream>
using namespace std;

struct Triangle {
    char TColor;
    char Tshade;
    short height;
    short base;
};

struct  Circle {
    char color;
    char shade;
    short radius;
};

union func_vtc{
  void (*drawCircle)(struct Circle *C);
  float (*areaCircle)(struct Circle*);
};

union func_vtt{
  void (*drawTriangle)(struct Triangle *T);
  float (*areaTriangle)(struct Triangle*);
};


void setCircle (struct Circle *C, char col, char shad, short rad);
void drawCircle (struct Circle *C) ;
float areaCircle(struct Circle*);

void setTriangle (struct Triangle *T, char col, char shad, short heigh, short bass);
void drawTriangle (struct Triangle *T);
float areaTriangle(struct Triangle*);


int main() {

  Triangle t1;//created triangle object
  Circle c1;// created circle object
  setCircle (&c1,'R' , 'L', 3 );
  union func_vtc vtc[2];
  vtc[0].drawCircle=drawCircle;
  vtc[1].areaCircle=areaCircle;
  vtc[0].drawCircle(&c1);
  float area= vtc[1].areaCircle(&c1);
  cout<<"Area of circle :"<<area<<endl;

  setTriangle (&t1, 'G', 'D', 6, 2);
  union func_vtt vtt[2];
  vtt[0].drawTriangle=&drawTriangle;
  vtt[1].areaTriangle=&areaTriangle;
  vtt[0].drawTriangle(&t1);
  area= vtt[1].areaTriangle(&t1);
  cout<<"Area of triangle :"<<area<<"\n"<<endl;

  return 0;
}

float areaCircle(struct Circle* ACirc)
{
  short rad;
  rad=  (*ACirc).radius;
  float area= ((rad)*(rad)*(3.14));
  return area;
}

void setCircle (struct Circle *C, char col, char shad, short rad)
{

 C->color=col;
 C->shade=shad;
 C->radius=rad;

}

void drawCircle (struct Circle* Cad)
{
  string Colour, Shadow;
  switch(Cad->color)
 {
   case 'R':
        Colour="Red";
        break;
  case 'G':
       Colour="Green";
       break;
  case 'B':
        Colour="Blue";
        break;
  default:
        Colour="Invalid Colour";
        break;
    }

    switch(Cad->shade)
    {
     case 'D':
          Shadow="Dark";
          break;
    case 'L':
         Shadow="Light";
         break;
    default:
          Shadow="Invalid Shade";
          break;
      }

  cout<<"\nThese are Circles's features \nColor:"<< Colour <<"\nShade: " <<Shadow <<"\nRadius: " <<(*Cad).radius<<endl;
}



float areaTriangle(struct Triangle* Atri)
{
  short H, bas;
  H=  (*Atri).height;
  bas=  (*Atri).base;
  float area= ((H)*(bas)*(0.5));
  return area;
}

void setTriangle (struct Triangle *T, char col, char shad, short heigh, short bass)
{

T->TColor=col;
T->Tshade=shad;
T->height=heigh;
T->base=bass;

}

void drawTriangle (struct Triangle* Tad)
{

  string Colour, Shadow;
  switch(Tad->TColor)
 {
   case 'R':
        Colour="Red";
        break;
  case 'G':
       Colour="Green";
       break;
  case 'B':
        Colour="Blue";
        break;
  default:
        Colour="Invalid Colour";
        break;
    }

    switch(Tad->Tshade)
    {
     case 'D':
          Shadow="Dark";
          break;
    case 'L':
         Shadow="Light";
         break;
    default:
          Shadow="Invalid Shade";
          break;
      }

  cout<<"\nThese are Triangle's features \nColor:"<< Colour <<"\nShade: " <<Shadow <<"\nHeight: " << (*Tad).height<<"\nBase: " << (*Tad).base<<endl;
}
