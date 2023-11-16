#include "main.h"
/**
 * read_command - reads command entered by user
 * Return: returns command entered
 */
char *read_command(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	characters = getline(&line, &bufsize, stdin);

	if (characters == -1)
	{
		if (feof(stdin))
		{
			free(line);
			PRINT("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(line);
			return (NULL);
		}
	}

	if (characters > 0 && line[characters - 1] == '\n')
		line[characters - 1] = '\0';

	return (line);
}

/**
 * execute_command - executes the command entered
 * @command: the command to be executed
 * Return: returns nothing
 */
void execute_command(char *command)
{
	pid_t pid;
	int status, i = 0;
	char *token;
	char **args = malloc((MAX_ARGS + 1) * sizeof(char *));

	if (args == NULL)
	{
		perror("memory allocation error");
		return;
	}
	token = str_tok(command, " ");
	while (token != NULL && i < MAX_ARGS)
	{
		args[i] = str_dup(token);
		token = str_tok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		free(args);
		return;
	}
	if (pid == 0)
	{
		fflush(stdout);
		if (execve(command, args, environ) == -1)
		{
			perror("execve failed");
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("wait failed");
		free(args);
	}
}
/**
 * _exec_command1 - a function that takes the user commandline input,
 * tokenize it, store it in an array and execuit it in a chiled process
 * and displays yhe result of the chiled befor the parent process.
 *
 * Return: No return value (void).
 *
 */
void _exec_command1(char *command)
{
	pid_t child_pid;
	char *token, *path, **cmd_and_args;
	char *arguments[MAX_ARGS], *env[];
	int status, i = 0;

	token = strtok(command, " ");

	while (token && i < MAX_ARGS - 1)
	{
		arguments[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	arguments[i] = NULL;
	if (i == 0)
	{
		return; /*No command*/
	}
	if (i > 1)
	{
		perror("./shell");
		return;
	}
		path = arguments[0]; /*1st arg is path*/
		cmd_and_args = &arguments[1];
		child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	if (child_pid == 0)
	{
		envp[] = { NULL };
		execve(path, cmd_and_args, envp);
		perror("./shell");
		exit(1);
	}
	else
		waitpid(child_pid, &status, 0);
}
