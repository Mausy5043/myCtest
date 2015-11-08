#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>

#include "daemonize.h"

int main()
{
  int LFP;
  LFP = daemonize();
  syslog(LOG_NOTICE, "Daemon started.");
  while(1)                                                                      // main loop of daemon
  {
    sleep(1);                                                                   // Don't block context switches
    sleep(3600);
    break;
  }



  //lockf(lfp,F_ULOCK,0);
  if (lockf(LFP,F_ULOCK,0) > 0)
    syslog(LOG_NOTICE, "Lockfile could not be released.");
  else
    syslog(LOG_NOTICE, "Lockfile released.");
    unlink(LOCK_FILE);

  syslog(LOG_NOTICE, "Automatically terminated.");
  closelog();

  return EXIT_SUCCESS;
}
