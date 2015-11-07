 #include <unistd.h>
 #include <stdlib.h>

#include "daemonize.h";

int main()
{
  daemonize();
  while(1)                                        // main loop of daemon
  {
    sleep(1);
  }

  return 0;
}

/* EOF */
