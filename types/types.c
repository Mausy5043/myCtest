#include <stdio.h>
#include <float.h>

int main()
{
  printf("char\n");
  printf("sizeof(char)        == %lu\n", sizeof(char));
  printf("\nvarious\n");
  printf("\nint\n");
  printf("sizeof(int)         == %lu\n", sizeof(int));
  printf("sizeof(short)       == %lu\n", sizeof(short));
  printf("sizeof(short int)   == %lu\n", sizeof(short int));
  printf("sizeof(long)        == %lu\n", sizeof(long));
  printf("sizeof(long int)    == %lu\n", sizeof(long int));
  printf("sizeof(long long)   == %lu\n", sizeof(long long));
  printf("\ndouble\n");
  printf("sizeof(double)      == %lu\n", sizeof(double));
  //printf("double maximum      == %f\n", DBL_MAX);
  printf("sizeof(long double) == %lu\n", sizeof(long double));
  //printf("long double maximum == %Lf\n", LDBL_MAX);
  printf("\nfloat\n");
  printf("sizeof(float)       == %lu\n", sizeof(float));
  //printf("float maximum       == %f\n", FLT_MAX);
  //printf("sizeof(long float)  == %lu\n", sizeof(long float));
}
