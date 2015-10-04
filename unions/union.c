/*
Author: Akshay Joshi
Description: This is a simple program of how a union works, I have considered a example of
creating a union called film. This union has a call number in data type int, Film duration in float,
Name of the film in char and an new Call number assigned through pointer.


*/

#include <stdio.h>
#include <string.h>

 union Film
{
   int CallNumber;
   float FilmDuration;
   char  NameOfFilm[20];
   int* CNumber;
};

int main( )
{
   int NewCN=13;
   union  Film film;
   film.CallNumber=10;
   printf("\nCall Number of the film inside union is : %d\n",film.CallNumber);
   film.FilmDuration=3.58;
   printf("Duration of the film inside union is : %f Hours\n",film.FilmDuration);
   strcpy(film.NameOfFilm,"Gone with the wind");
   printf("Name of the film in the union is : %s\n",film.NameOfFilm);
   film.CNumber= &(NewCN);
   printf("New Call Number of the film inside union printed through pointer is : %d\n\n",*film.CNumber);
   return 0;
}

/*
Q:explain how a union works
  Answer: A union is a special kind of data type that helps us to store different data types
  in the same memory location, this is an efficient way to utilize a memory location. The data
  gets corrupted if it not used as soon as it is assigned cause the variable occupies the
  memory location, for example in above code if we print call number at the end line of the
  code before return 0 it will print a corrupted value.

Q: speculate how casting and unions are related
  Answer: They are not related.
  Casting is a way to convert data variable from one data type to another, where as union is
  what is explained in above answer.
  Casting uses cast operators here is a simple example for casing:
  int main()
  {
    int number = 13 ;
    double converted;
    converted = (double) number;
    printf("Value of converted number : %f\n", converted );
}

*/
