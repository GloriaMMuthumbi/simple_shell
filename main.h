#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#define MAX_ARGS 1000
#define PRINT(c) (write(STDOUT_FILENO, c, str_len(c)))
#define DELIM " \t\r\n\a"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>

/**String functions*/
int str_len(char *s);
char *str_dup(char *str);
char *str_cpy(char *dest, char *src);
char *str_tok(char *str, const char *tok);
unsigned int delim_check(char c, const char *str);
char *str_chr(char *s, char c);

/**Process functions*/
void child_process(char *command, char **args, int pipe_fd[2]);
void parent_process(int pipe_fd[2]);

/**Input functions*/
void display_prompt(void);
void pipe_handler(char *command);

/**Command functions*/
char *read_command(void);
void execute_command(char *command);

#endif
