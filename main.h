#ifndef MAIN_H
#define MAIN_H

/**
 * marcos
 */
#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINT(c) (write(STDOUT_FILENO, c, strlen(c)))

/**
 * imported libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute_command(char *command);
void display_prompt(void);
char *get_line(void);
void sigint_handler(int signum);

#endif

