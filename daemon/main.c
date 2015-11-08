#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>

#include "daemonize.h"

int main()
{
  daemonize();
  syslog(LOG_NOTICE, "Daemon started.");
  while(1)                                                                      // main loop of daemon
  {
    sleep(1);                                                                   // Don't block context switches
    sleep(3600);
    break;
  }


  cleanup();

  syslog(LOG_NOTICE, "Automatically terminated.");
  closelog();

  return EXIT_SUCCESS;
}
