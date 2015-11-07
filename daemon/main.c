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
    sleep(10);
    break;
  }

  syslog(LOG_NOTICE, "Daemon terminated.");
  closelog();

  return EXIT_SUCCESS;
}
