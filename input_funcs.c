#include "main.h"
/**
 * display_prompt - displays prompt to user
 * Return: returns nothing
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$", str_len("#cisfun$"));
}
