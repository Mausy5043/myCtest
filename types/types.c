#include <stdio.h>
#include <float.h>

int main()
{
  printf("\tCHAR\n");
  printf("sizeof(char)        == %i\n", (int)sizeof(char));
  printf("\n\tINT\n");
  printf("sizeof(int)         == %i\n", (int)sizeof(int));
  printf("sizeof(short)       == %i\n", (int)sizeof(short));
  printf("sizeof(short int)   == %i\n", (int)sizeof(short int));
  printf("sizeof(long)        == %i\n", (int)sizeof(long));
  printf("sizeof(long int)    == %i\n", (int)sizeof(long int));
  printf("sizeof(long long)   == %i\n", (int)sizeof(long long));
  printf("\n\tDOUBLE\n");
  printf("sizeof(double)      == %i\n", (int)sizeof(double));
  //printf("double maximum      == %f\n", DBL_MAX);
  printf("sizeof(long double) == %i\n", (int)sizeof(long double));
  //printf("long double maximum == %Lf\n", LDBL_MAX);
  printf("\n\tFLOAT\n");
  printf("sizeof(float)       == %i\n", (int)sizeof(float));
  //printf("float maximum       == %f\n", FLT_MAX);
  //printf("sizeof(long float)  == %lu\n", sizeof(long float));
}
