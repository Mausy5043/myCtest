#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define SIZE 256

int main(int argc, char *argv[])
{
  //time_t systime;
  //char timebuffer[SIZE];
  //struct tm *loctime;

  int a;    // a is an integer
  int *p;   // p is a pointer to an integer object
  a = 1234; // a contains the value 1234
  p = &a;   // p contains the address of integer a.

  printf(" a   %i\n", a);
  printf("&a   %p\n",&a);
  printf(" p   %p\n", p);
  printf("&p   %p\n",&p);
  printf("*p   %i\n",*p);

  char *pc = (char*)2;
  printf(" pc  %p\n", pc);
  pc++;
  printf(" pc++ %p\n", pc);


  int *pi = (int*)2;
  printf(" pi  %p\n", pi);
  pi++;
  printf(" pi++ %p\n", pi);


/*




  char  name[] = "Bill";
  char  *p;

  printf(" name %s\n", name);
  printf("&name %p\n",&name);

  p=name;
  printf(" p    %s\n", p);
  printf("*p    %c\n",*p);
  printf("&p    %p\n",&p);
  ++p;
  printf(" p    %s\n", p);
  printf("*p    %c\n",*p);
  printf("&p    %p\n",&p);


  // 1. determine date and time
  systime = time(NULL);
  // convert to localtime representation
  loctime = localtime(&systime);
  // convert to formatted representation
  strftime(timebuffer, SIZE, "%Y-%m-%dT%H:%M", loctime);

  if(systime != -1)
  {
    printf("The local time is %s \n", asctime(loctime));
    printf("The useful time is %s \n", timebuffer);
  }
  // 2. read a line of data from a file
  // 3. write formatted data to a file
*/
  return 0;
}
