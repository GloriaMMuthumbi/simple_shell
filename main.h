#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#define MAX_ARGS 100
#define PRINT(c) (write(STDOUT_FILENO, c, str_len(c)))
#define DELIM " \t\r\n\a"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

/**String functions*/
int str_len(char *s);
char *str_dup(char *str);
char *str_cpy(char *dest, char *src);
char *str_tok(char *str, const char *tok);
unsigned int delim_check(char c, const char *str);

/**Input functions*/
void display_prompt(void);

/**Command functions*/
char *read_command(void);
void execute_command(char *command);
void _exec_command1(char *command);

#endif
