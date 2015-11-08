#ifndef DAEMONIZE_H
#define DAEMONIZE_H


// function declarations
void log_message(char *filename,char *message);
void signal_handler(int sig);
void fnsome(void);
int daemonize(void);
#endif /* DAEMONIZE_H */
