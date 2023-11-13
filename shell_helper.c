#include "shell.h"

/**
 * _strchr - function that find char in str
 * @str: The string to be searched
 * @c: The character to find
 *
 * Return: The character found.
 */
char *_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

/**
 * _strncmp - function that compare two strings
 * @s1: The first string
 * @s2: The second string
 * @len: The length of the character found
 *
 * Return: The len of the character found.
 */
int _strncmp(char *s1, char *s2, size_t len)
{
	size_t b;

	for (b = 0; b < len; b++)
	{
		if (s1[b] != s2[b])
			return (s1[b] - s2[b]);
		if (s1[b] == '\0')
			return (0);
	}
	return (0);
}

/**
 * _strcat - function that concatenate string.
 * @dest: the destination.
 * @src: The source
 *
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	size_t b, d;

	b = 0;
	while (dest[b] != '\0')
		b++;
	d = 0;
	while (src[d] != '\0')
	{
		dest[b] = src[d];
		b++;
		d++;
	}
	dest[b] = '\0';
	return (dest);
}

/**
 * _strcpy - function that copy strings
 * @dest: The destination
 * @src: The source
 *
 * Return: Always 0.
 */
char *_strcpy(char *dest, char *src)
{
	int b = 0;

	if (dest == NULL)
		return (NULL);
	while (src[b] != '\0')
	{
		dest[b] = src[b];
		b++;
	}
	dest[b] = '\0';
	return (dest);
}

/**
 * _getenv - function that find the path
 * @name: The name of the path
 *
 * Return: Always 0.
 */
char *_getenv(char *name)
{
	char *variable;
	int b;

	for (b = 0; environ[b] != NULL; b++)
	{
		if (_strncmp(name, environ[b], _strlen(name) == 0))
		{
			variable = _strchr(environ[b], '=');
			return (variable + 1);
		}
	}
	return (NULL);
}
