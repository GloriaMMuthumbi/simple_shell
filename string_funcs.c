#include "main.h"
/**
 * str_len - gets length of string
 * @s: string to be checked
 * Return: returns the length of string
 */
int str_len(char *s)
{
	int len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
