#include "main.h"
/**
 * main - entry point of shell
 * Return: returns 0 always
 */

int main(void)
{
	char *command;
	size_t length = 0;
	ssize_t read;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		display_prompt();

		read = getline(&command, &length, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				clearerr(stdin);
				continue;
			}
			else
			{
				printf("\n");
				free(command);
				exit(EXIT_FAILURE);
			}
		}
		if (command[read - 1] == '\n')
			command[read - 1] = '\0';

		if (execute_command(command) != 0)
			fprintf(stderr, "Command execution failed.\n");
	}
	return (0);
}
