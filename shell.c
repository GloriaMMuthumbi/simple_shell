#include "main.h"
/**
 * main - entry point of the shell
 * Return: returns 0 always
 */
int main(void)
{
	char *command;

	while (1)
	{
		command = read_command();

		if (command != NULL)
		{
			execute_command(command);
			free(command);
		}
	}
	return (0);
}
