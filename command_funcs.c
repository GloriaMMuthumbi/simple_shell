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
		/*fflush(stdout);*/
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("wait failed");
		free(args);
	}
}
