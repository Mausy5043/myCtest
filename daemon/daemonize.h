#ifndef DAEMONIZE_H
#define DAEMONIZE_H


// function declarations
void fnsome(void);
void log_message(char *filename,char *message);
void signal_handler(int sig);
void daemonize(void);
#endif /* DAEMONIZE_H */
