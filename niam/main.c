#include <stdio.h>
#include <stdint.h>
#include <time.h>

//#include "functions.h"

int main(int argc, char* argv[])
{
  time_t starttime;
  // 1. determine date and time
  starttime = time(NULL);

  if(starttime != -1)
  {
    printf("The current time is %s (%ju seconds since the Epoch)\n",
            asctime(gmtime(&starttime)), (uintmax_t)starttime);
  }
  // 2. read a line of data from a file
  // 3. write formatted data to a file

  return 0;
}
