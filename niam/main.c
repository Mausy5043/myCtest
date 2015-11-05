#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define SIZE 256
//#include "functions.h"

int main(int argc, char* argv[])
{
  time_t systime;
  char timebuffer[SIZE];
  struct tm *glbtime;
  struct tm *loctime;
  //char fmttime[16];

  // 1. determine date and time
  systime = time(NULL);
  // convert to GMT representation
  glbtime = gmtime(&systime);
  // convert to localtime representation
  loctime = localtime(&systime);
  // convert to formatted representation
  strftime(timebuffer, SIZE, "%Y-%m-%dT%H:%M", loctime);
  //fmttime = buffer;

  if(systime != -1)
  {
    printf("The current GMT time is %s (%ju seconds since the Epoch)\n",
            asctime(glbtime), (uintmax_t)systime);

    printf("The local time is %s \n", asctime(loctime));

    printf("The useful time is %s \n", timebuffer);
  }
  // 2. read a line of data from a file
  // 3. write formatted data to a file

  return 0;
}
