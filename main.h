#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#define PRINT(c) (write(STDOUT_FILENO, c, str_len(c)))

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int str_len(char *s);
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);

#endif
