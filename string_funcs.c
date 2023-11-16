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

/**
 * str_tok - tokenizes a string
 * @str: string to be tokenized
 * @tok: token to be used as delimeter
 * Return: pointer to next token
 */
char *str_tok(char *str, const char *tok)
{
	char *startToken;
	static char *lastToken;

	if (str)
		startToken = str;
	else if (lastToken)
		startToken = lastToken;
	else
		return (NULL);

	startToken += delim_check(*startToken, tok);

	if (*startToken == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	lastToken = startToken + 1;
	while (*lastToken && !delim_check(*lastToken, tok))
		lastToken++;

	if (*lastToken == '\0')
		lastToken = NULL;
	else
	{
		*lastToken = '\0';
		lastToken++;
	}
	return (startToken);
}

/**
 * delim_check - checks for delimeters
 * @c: character to be checked
 * @str: string to check
 * Return: return 0 always
 */
unsigned int delim_check(char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

/**
 * str_dup - duplicates a string
 * @str: string to be duplicated
 * Return: returns pointer to duplicate
 */
char *str_dup(char *str)
{
	int len = str_len(str);
	char *dup = (char *)malloc((len + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);

	str_cpy(dup, str);
	return (dup);
}

/**
 * str_cpy - copies a string
 * @dest: the string to be copied to
 * @src: the string to be copied from
 * Return: returns pointer to the dest string
 */
char *str_cpy(char *dest, char *src)
{
	int i = 0;

	while ((dest[i] = src[i]) != '\0')
		i++;
	return (dest);
}
