#include "main.h"
/**
 * sigint_handler = it handles SIGINT
 * @signum: integer for signal
 * Return: returns nothing
 */

void sigint_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\nExiting...\n", 13);
	exit(EXIT_SUCCESS);
}
