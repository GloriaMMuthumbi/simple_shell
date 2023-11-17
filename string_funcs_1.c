#include "main.h"
/**
 * str_chr - searches for occurence of character
 * @s: string to be searched
 * @c: character to check for
 * Return: returns pointer to first occurence.
 * otherwise NULL if no match found
 */
char *str_chr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}
