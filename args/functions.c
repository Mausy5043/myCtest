#include <stdio.h>

int function_one(int a, int b)
{
  printf("This is function one\n");

  return a*b;
}

int function_two(int a, int b)
{
  printf("This is function 2\n");
  return a+b;
}

int function_three()
{
  printf("This is function THREE\n");
  return 0;
}
