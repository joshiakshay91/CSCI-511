/*
Name: This program goes through understandig of function pointers in C
It is a simple program for doing basic math calculations.
Author: Akshay Joshi
Date:9/23/2015

*/

#include <stdio.h>

float addition (float Val1,float Val2)
{
return(Val1 + Val2);
}

float subtraction(float Val1, float Val2)
{
  return (Val2-Val1);
}

float multiplication (float Val1,float Val2)
{
return((Val1) * ( Val2));
}

float division(float Val1, float Val2)
{
  return (Val2/Val1);
}


int main()
{
  float f1=10.2;
  float f2 =13.3;
  printf("\nThe two numbers that we will do math calculations are\nnum1= %f, num2= %f \n",f1,f2);
  float result;
  //Declared all the variables
  float (*add)(float, float);
  add=&addition;            //simple pointer function for float step 1
  float (*sub)(float,float);
  sub=&subtraction;     //simple pointer function for float with subtraction
  result=(*add)(f1,f2);
  printf("Addition : %f\n",result);//printing out the results
  result=(*sub)(f1,f2);
  printf("Subtraction : %f\n",result);

  float (*mul)(float, float); //similarly implmenting it for multiplication and division
  mul=&multiplication;
  float (*divi)(float,float);
  divi=&division;
  result=(*mul)(f1,f2);
  printf("Multiplication : %f\n",result);
  result=(*divi)(f1,f2);
  printf("Division : %f\n",result);

// The part in which, I assign each of these functions to one element of the array.
//Invoke them in a for-loop
  printf("\n\nInvokinng the functions through array in for loop\n");
  float (*arr[4])(float f11,float f22);
  arr[0]=&addition;
  arr[1]=&subtraction;
  arr[2]=&multiplication;
  arr[3]=&division;
  int x;
  for(x=0;x<4;x++)
  {
    result=arr[x](f1,f2);
    printf("\nResult number:%d \nresult: %f\n",(x+1),result);
  }
  return 0;
}
