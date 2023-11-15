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
	int status;

	char **args = malloc(2 * sizeof(char *));
	if (args == NULL)
	{
		perror("memory allocation error");
		return;
	}
	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		free(args);
		return;
	}
	if(pid == 0)
	{
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
