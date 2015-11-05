#include <stdio.h>
#include <math.h>

#include "functions.h"

int main(int argc, char* argv[])
{
  int counter;
  int ps;

  printf("This program calls three functions\n");
  ps = function_one(2,4);
  printf("%d\n",ps);
  ps = function_two(2,4);
  printf("%d\n",ps);
  function_three();

  printf("argc = %d\n",argc);
  for (counter = 0; counter < argc; counter++)
  {
    printf ("%s\n", argv[counter]);
  }
  printf("%d squared is %.3f --- %s\n", ps, pow(ps,2),"fin" ); // forgot 2 arguments

  return 0;
}
