#ifndef DAEMONIZE_H
#define DAEMONIZE_H


extern LOCK_FILE

// function declarations
void log_message(char *filename,char *message);
void signal_handler(int sig);
int daemonize(void);
#endif /* DAEMONIZE_H */
