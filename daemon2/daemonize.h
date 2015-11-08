#ifndef DAEMONIZE_H
#define DAEMONIZE_H


// function declarations
void predaemon(char *cmd);
void cleanup(void);
void log_message(char *filename,char *message);
void signal_handler(int sig);
void daemonize(void);
#endif /* DAEMONIZE_H */
