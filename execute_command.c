#include "main.h"
/**
 * execute_command - executes the command
 * @command: command to be executed
 * Return: returns 0 always
 */
int execute_command(char *command)
{
	pid_t child_process_id;
	int process_status;

	child_process_id = fork();
	if (child_process_id == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_process_id == 0)
	{
		char **args = malloc(2 * sizeof(char *));

		if (args == NULL)
		{
			perror("memory allocation failed");
			exit(EXIT_FAILURE);
		}
		args[0] = command;
		args[1] = NULL;
		if (execve(command, args, NULL) == -1)
		{
			/*perror("command execution failed");*/
			perror("hsh");
			free(args);
			exit(EXIT_FAILURE);
		}
	free(args);
	}
	else
	{
		waitpid(child_process_id, &process_status, 0);
	}

	return (0);
}
