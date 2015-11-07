/*
* UNIX Daemon Server Programming Sample Program
* Levent Karakas <levent at mektup dot at> May 2001
*
* Adapted for use by M. Hendrix - 2011NOV
*
*   To compile:     cc -o exampled examped.c
*   To run:         ./exampled
*   To test daemon: ps -ef|grep exampled (or ps -aux on BSD systems)
*   To test log:    tail -f /tmp/exampled.log
*   To test signal: kill -HUP `cat /tmp/exampled.lock`
*   To terminate:   kill `cat /tmp/exampled.lock`
*/

#include <fcntl.h>
#include <signal.h>                                                             //signal(3)
#include <stdio.h>
#include <stdlib.h>                                                             //exit(3)
#include <string.h>
#include <syslog.h>
#include <unistd.h>                                                             //fork(3), chdir(3)
#include <sys/types.h>
#include <sys/stat.h>                                                           //umask(3)

#define RUNNING_DIR	"/tmp"
#define LOCK_FILE	"exampled.lock"
#define LOG_FILE	"exampled.log"

void log_message(char *filename,char *message){
  FILE *logfile;
  logfile=fopen(filename,"a");
  if(!logfile) return;
  fprintf(logfile,"%s\n",message);
  fclose(logfile);
}

void signal_handler(int sig){
  switch(sig)
    {
    case SIGHUP:
      log_message(LOG_FILE,"hangup signal catched");
      syslog(LOG_NOTICE, "Daemon received SIGHUP.");
      break;
    case SIGTERM:
      log_message(LOG_FILE,"terminate signal catched");
      syslog(LOG_NOTICE, "Daemon received SIGTERM.");
      closelog();
      exit(EXIT_SUCCESS);
      break;
  }
}

void daemonize(){
  pid_t pid;
  int i;
  int lfp;
  char str[10];

  if(getppid()==1) return;                                                      // already a daemon

  /* first fork() */
  pid=fork();
  if (pid < 0){                                                                   // fork error
    fprintf(stderr,"error: failed first fork\n");
    exit(EXIT_FAILURE);
  }
  if (pid > 0) exit(EXIT_SUCCESS);                                                // parent exits

  /* decouple from parent environment */
  if (setsid() < 0){                                                            // obtain a new process group
    fprintf(stderr,"error: failed setsid\n");
    exit(EXIT_FAILURE);
  }
  umask(0);                                                                     // set newly created file permissions
  chdir(RUNNING_DIR);                                                           // change running directory

  /* second fork() */
  pid=fork();
  if (pid < 0){                                                                 // fork error
    fprintf(stderr,"error: failed second fork\n");
    exit(EXIT_FAILURE);
  }
  if (pid > 0) exit(EXIT_SUCCESS);                                              // parent exits

  for (i=getdtablesize();i>=0;--i) close(i);                                    // close all descriptors
  i=open("/dev/null",O_RDWR); dup(i); dup(i);                                   // handle standard I/O
  lfp=open(LOCK_FILE,O_RDWR|O_CREAT,0640);
  if (lfp<0) exit(1);                                                           // can not open
  if (lockf(lfp,F_TLOCK,0)<0) exit(0);                                          // can not lock

  /* second fork continues */
  sprintf(str,"%d\n",getpid());
  write(lfp,str,strlen(str));                                                   // record pid to lockfile
  signal(SIGCHLD,SIG_IGN);                                                      // ignore child
  signal(SIGTSTP,SIG_IGN);                                                      // ignore tty signals
  signal(SIGTTOU,SIG_IGN);
  signal(SIGTTIN,SIG_IGN);
  signal(SIGHUP,signal_handler);                                                // catch hangup signal
  signal(SIGTERM,signal_handler);                                               // catch kill signal

  /* Open the log file */
  openlog("TestDaemon", LOG_PID, LOG_DAEMON);
}
