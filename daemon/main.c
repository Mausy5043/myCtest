#include <unistd.h>                                                             // sleep(3)
#include <stdlib.h>
#include <syslog.h>

#include "daemonize.h"

int main()
{
  daemonize();

  syslog(LOG_INFO, "started successfully.");

  while (1)                                                                     // main loop of daemon
  {
    sleep(1);                                                                   // Don't block context switches
    syslog(LOG_DEBUG, "DEBUG");
    sleep(10);
    syslog(LOG_INFO, "INFO");
    sleep(10);
    syslog(LOG_NOTICE, "NOTICE");
    sleep(10);
    syslog(LOG_WARNING, "WARNING");
    sleep(10);
    syslog(LOG_ERR, "ERR");
    sleep(10);
    syslog(LOG_CRIT, "CRIT");
    sleep(10);
    syslog(LOG_ALERT, "ALERT");
    sleep(10);
    syslog(LOG_EMERG, "EMERG");
    sleep(360);
    break;                                                                      // for testing purposes
  }

  // cleanup and stop the daemon gracefully
  cleanup();
  syslog(LOG_NOTICE, "terminating automatically.");
  closelog();

  return EXIT_SUCCESS;
}

/*
 LOG_EMERG      system is unusable
 LOG_ALERT      action must be taken immediately
 LOG_CRIT       critical conditions
 LOG_ERR        error conditions
 LOG_WARNING    warning conditions
 LOG_NOTICE     normal, but significant, condition
 LOG_INFO       informational message
 LOG_DEBUG      debug-level message
*/
