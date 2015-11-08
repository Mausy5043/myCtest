/*
* UNIX Daemon Server Programming Sample Program
* Levent Karakas <levent at mektup dot at> May 2001
*  http://www.enderunix.org/docs/eng/daemon.php
*
* Adapted for use by M. Hendrix - 2011NOV
*
*   To test daemon: ps -ef|grep exampled (or ps -aux on BSD systems)
*   To test log:    tail -f /tmp/exampled.log
*   To test signal: kill -HUP $(cat /tmp/exampled.lock)
*   To terminate:   kill $(cat /tmp/exampled.lock)
*/

#include <fcntl.h>                                                              //file descriptors
#include <signal.h>                                                             //signal(3)
#include <stdio.h>
#include <stdlib.h>                                                             //exit(3)
#include <string.h>
#include <syslog.h>
#include <unistd.h>                                                             //fork(3), chdir(3)
#include <sys/types.h>
#include <sys/stat.h>                                                           //umask(3)

#define RUNNING_DIR "/"
#define LOCK_FILE   "/tmp/exampled.lock"
#define LOG_FILE    "/tmp/exampled.log"
#define APP_NAME    "exampled"

int hLFP;                                                                       // filehandle pidfile

void predaemon(char *cmd){
  /* switch (cmd)  */
  if (strcmp(cmd, "start") == 0){                                               // case "start":
    fprintf(stdout, "%s requested\n", cmd);
    //break;
      /*  Returns to main() and starts daemonize().
          This may still fail if daemon is already running.
      */
  }
  else if (strcmp(cmd, "stop") == 0){                                           // case "stop":
    fprintf(stdout, "%s requested\n", cmd);
      /*  Stop code to be executed here.
      */
    exit(EXIT_FAILURE);
    //break;
  }
  else{                                                                         // default:
    fprintf(stderr, "ERROR: Invalid command: %s\n", cmd);
    fprintf(stderr, "       Only one of (start | stop) allowed\n");
    exit(EXIT_FAILURE);
  }
}

void cleanup(){
  if (lockf(hLFP,F_ULOCK,0) < 0){
    syslog(LOG_WARNING, "pidfile could not be released.");
  }
  else{
    syslog(LOG_NOTICE, "pidfile released.");
  }

  // delete lockfile
  if (unlink(LOCK_FILE) < 0){
    syslog(LOG_WARNING, "pidfile could not be removed.");
  }
  else{
    syslog(LOG_NOTICE, "pidfile removed.");
  };
}

void log_message(char *filename,char *message){
  FILE *logfile;
  logfile = fopen(filename, "a");
  if (!logfile)
  {
    syslog(LOG_ERR, "Can not open file %s", filename);
    return;
  }
  fprintf(logfile, "%s\n", message);
  fclose(logfile);
}

void signal_handler(int sig){
  switch (sig)
  {
    case SIGHUP:
      syslog(LOG_INFO, "received SIGHUP.");
      break;
    case SIGTERM:
      syslog(LOG_INFO, "received SIGTERM.");
      cleanup();
      closelog();
      exit(EXIT_SUCCESS);
      break;
  }
}

void daemonize(){
  pid_t pid;
  int i;
  char str[10];

  /* first fork() */
  pid = fork();
  if (pid < 0){                                                                 // fork error
    fprintf(stderr, "ERROR: failed first fork\n");
    exit(EXIT_FAILURE);
  }
  if (pid > 0) exit(EXIT_SUCCESS);                                              // parent exits

  /* decouple from parent environment */
  if (setsid() < 0){                                                            // obtain a new process group
    fprintf(stderr, "ERROR: failed setsid\n");
    exit(EXIT_FAILURE);
  }

  umask(000);                                                                   // set newly created file permissions

  if (chdir(RUNNING_DIR) < 0) {                                                 // change current working directory
    fprintf(stderr, "ERROR: failed chdir()\n");
    exit(EXIT_FAILURE);
  }

  /* second fork() not needed ? */
  pid = fork();
  if (pid < 0){                                                                 // fork error
    fprintf(stderr, "ERROR: failed second fork\n");
    exit(EXIT_FAILURE);
  }
  if (pid > 0) exit(EXIT_SUCCESS);                                              // parent exits

  /* second fork continues */
  for (i = getdtablesize(); i >= 0; --i) close(i);                              // close all descriptors
  i = open("/dev/null", O_RDWR); dup(i); dup(i);                                // handle stdin/stdout/stderr

  /* Open the log file */
  openlog(APP_NAME, LOG_PID, LOG_DAEMON);

  /* create pidfile */
  hLFP = open(LOCK_FILE, O_RDWR|O_CREAT, 0640);                                 // create pidfile
  if (hLFP < 0){
    syslog(LOG_ERR, "Can not open pidfile");
    exit(EXIT_FAILURE);                                                         // can not open
  }
  if (lockf(hLFP, F_TLOCK, 0) < 0){
    syslog(LOG_ERR, "Can not lock pidfile");
    exit(EXIT_FAILURE);                                                         // can not lock
  }
  sprintf(str, "%d\n", getpid());
  write(hLFP, str, strlen(str));                                                // record pid to lockfile

  signal(SIGCHLD, SIG_IGN);                                                     // ignore child
  signal(SIGTSTP, SIG_IGN);                                                     // ignore tty signals
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  signal(SIGHUP,  signal_handler);                                              // catch hangup signal
  signal(SIGTERM, signal_handler);                                              // catch kill signal
}
