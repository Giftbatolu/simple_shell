#include "shell.h"

/**
 * _strcspn - function that find the length str present in str-sub
 * @str: The string to be scanned
 * @str_sub: The string containing char to matched
 *
 * Return: The length of of the matching character
 */
int _strcspn(char *str, char *str_sub)
{
	char *b;
	size_t  len;

	if (str == NULL || str_sub == NULL)
		return (0);
	len = 0;
	while (*str)
	{
		b = str_sub;
		while (*b)
		{
			if (*str == *b)
				return (len);
			b++;
		}
		str++;
		len++;
	}
	return (len);
}

/**
 * _strspn - function that find the len of sunstring.
 * @str: The string to be scanned
 * @str_sub: The string containing the char to match
 *
 * Return: The length of the resulting value.
 */
int _strspn(char *str, char *str_sub)
{
	char *b;
	size_t len;

	if (str == NULL || str_sub == NULL)
		return (0);
	len = 0;
	while (*str)
	{
		b = str_sub;
		while (*b)
		{
			if (*str == *b)
				break;
			b++;
		}
		if (*b == '\0')
			return (len);
		str++;
		len++;
	}
	return (len);
}

/**
 * _strlen - function that find the len.
 * @s: The string to the len of
 *
 * Return: Always 0.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _memset - fills a given string with n number of fill chars
 * @str: string to be filled with fill
 * @fill: the char to put into str
 * @n: the number of chars to fill
 */
void _memset(char *str, int fill, int n)
{
	int b;

	for (b = 0; b < n; b++)
		str[b] = fill;
}

/**
 * _memcpy - copies part or all of string src to string dest
 * @dest: destination string
 * @src: source string
 * @bytes: number of bytes to copy
 */
void _memcpy(char *dest, char *src, unsigned int bytes)
{
	unsigned int b;

	for (b = 0; b < bytes; b++)
		dest[b] = src[b];
}
